#include "CmdStringMatcher.h"
#include "StringPath.h"
using namespace std;

void CmdStringMatcher::configCmd(const string& str) {
	StringPath cmdStr(str);
	cmdStr.parse();
	_container.addNode(cmdStr);
}

void CmdStringMatcher::getNextPossibleStrings(const string& str,
		std::vector<std::string>& opts) {
	StringPath cmdStr(str);
	cmdStr.parse();
	_container.getNextPossibleStrings(cmdStr, opts);
}
