#include "CmdNode.h"
#include "StringPath.h"
#include <iostream>
#include <assert.h>
using namespace std;

CmdNode::CmdNode(const std::string& content, StringPath& str):_content(content){
	addChild(str);
}

void CmdNode::addChild(StringPath& str) {
	if (str.isDone()){
		return;
	}
	_childs.addNode(str);
}

void CmdNode::getNextPossibleStrings(StringPath& str,
		std::vector<std::string>& opts) const{
	assert(!str.isDone());
	assert(_content == str.getCurrentPart());
	str.next();
	_childs.getNextPossibleStrings(str, opts);
}

std::string CmdNode::getContent() const {
	return _content;
}
