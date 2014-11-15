#include "CmdNodeContainer.h"
#include "CmdNode.h"
#include "StringPath.h"
#include <iostream>
#include <assert.h>
using namespace std;

#define NODE(iter) iter->second
#define CONST_FOR_EACH(container, iter) for(ConstIterator iter = container.begin(); iter != container.end(); ++iter)

void CmdNodeContainer::addNode(StringPath& str) {
	assert(!str.isDone());
	string content = str.getCurrentPart();
	str.next();
	Iterator iter = _nodes.find(content);
	if (iter != _nodes.end()){
		NODE(iter)->addChild(str);
		return;
	}
	_nodes[content] = new CmdNode(content, str);
}

void CmdNodeContainer::getNextPossibleStrings(StringPath& str,
		std::vector<std::string>& opts)const{
	if (str.isDone()){
		CONST_FOR_EACH(_nodes, iter){
			opts.push_back(NODE(iter)->getContent());
		}
		return;
	}
	string content = str.getCurrentPart();
	ConstIterator iter = _nodes.find(content);
	if (iter != _nodes.end()){
		NODE(iter)->getNextPossibleStrings(str, opts);
	}
}
