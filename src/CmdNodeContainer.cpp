#include "CmdNodeContainer.h"
#include "CmdNode.h"
#include "StringPath.h"
#include <iostream>
#include <assert.h>
using namespace std;

#define NODE(iter) iter->second
#define CONST_FOR_EACH(container, iter) for(ConstIterator iter = container.begin(); iter != container.end(); ++iter)

void CmdNodeContainer::addNode(StringPath& path) {
	assert(!path.isDone());
	string content = path.getCurrentPart();
	path.next();
	Iterator iter = _nodes.find(content);
	if (iter != _nodes.end()){
		NODE(iter)->addChild(path);
		return;
	}
	_nodes[content] = new CmdNode(content, path);
}


void CmdNodeContainer::getNextPossibleStrings(StringPath& path,
		std::vector<std::string>& opts)const{
	if (path.isDone()){
		addChildsToOpts(opts);
		return;
	}
	string content = path.getCurrentPart();
	ConstIterator iter = _nodes.find(content);
	if (iter != _nodes.end()){
		NODE(iter)->getNextPossibleStrings(path, opts);
	}
}

void CmdNodeContainer::addChildsToOpts(std::vector<std::string>& opts)const{
	CONST_FOR_EACH(_nodes, iter){
		opts.push_back(NODE(iter)->getContent());
	}
}
