#include "CmdStringPath.h"
#include "PartitionSymbolDef.h"
#include <iostream>
#include <assert.h>
using namespace std;

CmdStringPath::CmdStringPath(const std::string& str):_currentIndex(0),_str(str){

}

int CmdStringPath::parse() {
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

std::string CmdStringPath::getCurrentPart()const{
	assert(not isDone());
	return _parts[_currentIndex];
}

void CmdStringPath::first() {
	_currentIndex = 0;
}

void CmdStringPath::next() {
	_currentIndex++;
}

bool CmdStringPath::isDone() const{
	return _currentIndex == _parts.size();
}

bool CmdStringPath::isSymbol(char c) const {
	return SYMBOL_TABLE(Partition).isSymbol(c);
}

int CmdStringPath::findSymbol(const std::string& str, int beginPos)const{
	int i = beginPos;
	for (; i < str.size(); i++) {
		if (isSymbol(str[i])) {
			break;
		}
	}
	return i;
}
