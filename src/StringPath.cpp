#include "StringPath.h"
#include "SymbolTable.h"
#include <iostream>
#include <assert.h>
using namespace std;

StringPath::StringPath(const std::string& str):_currentIndex(0),_str(str){

}

int StringPath::parse() {
	int beginPos = 0, endPos = 0;
	while (beginPos < _str.size()) {
		if (isSymbol (_str[beginPos])) {
			_parts.push_back(string(1, _str[beginPos]));
			beginPos++;
		} else {
			endPos = findSymbol(_str, beginPos);
			_parts.push_back(_str.substr(beginPos, endPos - beginPos));
			beginPos = endPos;
		}
	}
	return SUCCESS;
}

std::string StringPath::getCurrentPart()const{
	assert(not isDone());
	return _parts[_currentIndex];
}

void StringPath::first() {
	_currentIndex = 0;
}

void StringPath::next() {
	_currentIndex++;
}

bool StringPath::isDone() const{
	return _currentIndex == _parts.size();
}

bool StringPath::isSymbol(char c) const {
	return SymbolTable::getInstance().isSymbol(c);
}

int StringPath::findSymbol(const std::string& str, int beginPos)const{
	int i = beginPos;
	for (; i < str.size(); i++) {
		if (isSymbol(str[i])) {
			break;
		}
	}
	return i;
}
