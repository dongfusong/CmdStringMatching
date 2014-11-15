#include "NodeContainer.h"
#include "Node.h"
#include "StringPath.h"
#include <iostream>
#include <assert.h>
using namespace std;


void NodeContainer::add(StringPath& str) {
	assert(!str.isDone());
	string content = str.getCurrentPart();
	str.next();
	NodeMap::iterator iter = _nodes.find(content);
	if (iter != _nodes.end()){
		iter->second->add(str);
	}else{
		_nodes[content] = new Node(content, str);
	}
}

void NodeContainer::getRelatedStrings(StringPath& str,
		std::vector<std::string>& opts) {
	if (str.isDone()){
		for (NodeMap::iterator iter = _nodes.begin(); iter != _nodes.end(); ++iter){
			opts.push_back(iter->second->getContent());
		}
		return;
	}
	string content = str.getCurrentPart();
	NodeMap::iterator iter = _nodes.find(content);
	if (iter != _nodes.end()){
		iter->second->getRelatedStrings(str, opts);
	}
}
