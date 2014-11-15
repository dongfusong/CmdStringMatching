#include "Node.h"
#include "StringPath.h"

Node::Node(const std::string& content, StringPath& str):_content(content){
	add(str);
}

void Node::add(StringPath& str) {
	if (str.isDone()){
		return;
	}
	_childs.add(str);
}

void Node::getRelatedStrings(StringPath& str,
		std::vector<std::string>& opts) {
	if (str.isDone()){
		opts.push_back(_content);
	}
	_childs.getRelatedStrings(str, opts);
}
