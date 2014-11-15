#include "StringPath.h"
#include "SymbolTable.h"
using namespace std;

StringPath::StringPath(const std::string& str) :
		_str(str),_currentPartPos(0),_nextPartPos(0) {
}

std::string StringPath::getCurrentPart() {
	if (isSymbol(_str[_currentPartPos])){
		_nextPartPos = _currentPartPos+1;
		return string(1, _str[_currentPartPos]);
	}
	_nextPartPos = findSymbol(_str, _currentPartPos);
	 return _str.substr(_currentPartPos, _nextPartPos - _currentPartPos);
}

void StringPath::next() {
	_currentPartPos = _nextPartPos;
}

bool StringPath::isDone() const{
	return _currentPartPos == _str.size();
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
