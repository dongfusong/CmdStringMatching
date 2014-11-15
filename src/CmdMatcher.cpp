#include "CmdMatcher.h"
#include "StringPath.h"
using namespace std;

void CmdMatcher::configCmd(const string& str) {
	StringPath cmdStr(str);
	cmdStr.parse();
	_container.addNode(cmdStr);
}

void CmdMatcher::getNextPossibleStrings(const string& str,
		std::vector<std::string>& opts) {
	StringPath cmdStr(str);
	cmdStr.parse();
	_container.getNextPossibleStrings(cmdStr, opts);
}
