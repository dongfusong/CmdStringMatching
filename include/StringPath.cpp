#include "StringPath.h"
#include "SymbolTable.h"
using namespace std;


StringPath::StringPath(const std::string& str) :
		_content(str),_currentPartPos(0),_nextPartPos(0) {
}

std::string StringPath::getCurrentPart() {
	if (isSymbol(_content[_currentPartPos])){
		_nextPartPos = _currentPartPos+1;
		return string(1, _content[_currentPartPos]);
	}
	int endPos = findSymbol(_content, _currentPartPos);
	_nextPartPos = endPos;
	 return _content.substr(_currentPartPos, endPos - _currentPartPos);
}

void StringPath::next() {
	_currentPartPos = _nextPartPos;
}

bool StringPath::isDone() const{
	return _currentPartPos == _content.size();
}

bool StringPath::isSymbol(char c) const {
	return SymbolTable::getInstance().isSymbol(c);
}

int StringPath::findSymbol(const std::string& str, int beginPos) {
	int i = beginPos;
	for (; i < str.size(); i++) {
		if (isSymbol(str[i])) {
			break;
		}
	}
	return i;
}
