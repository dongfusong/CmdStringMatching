#include "NodeContainer.h"
#include "Node.h"
#include "StringPath.h"
using namespace std;

void NodeContainer::add(StringPath& str) {
	if (str.isDone()){
		return;
	}
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
	//根据key寻找下个
	if (str.isDone()){
		return;
	}
	string content = str.getCurrentPart();
	NodeMap::iterator iter = _nodes.find(content);
	if (iter != _nodes.end()){
		return;
	}
	str.next();
	iter->second->getRelatedStrings(str, opts);
}
