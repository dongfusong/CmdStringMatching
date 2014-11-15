#include "Node.h"
#include "StringPath.h"
#include <iostream>
#include <assert.h>
using namespace std;

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
	assert(!str.isDone());
	str.next();
	_childs.getRelatedStrings(str, opts);
}
