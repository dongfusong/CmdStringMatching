#include "CmdNode.h"
#include "StringPath.h"
#include <iostream>
#include <assert.h>
using namespace std;

CmdNode::CmdNode(const std::string& content, StringPath& path):_content(content){
	addChild(path);
}

void CmdNode::addChild(StringPath& path) {
	if (path.isDone()){
		return;
	}
	_childs.addNode(path);
}

void CmdNode::getNextPossibleStrings(StringPath& path,
		std::vector<std::string>& opts) const{
	assert(!path.isDone());
	assert(_content == path.getCurrentPart());
	path.next();
	_childs.getNextPossibleStrings(path, opts);
}

std::string CmdNode::getContent() const {
	return _content;
}
