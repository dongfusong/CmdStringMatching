#include "CmdStringMatcher.h"
#include "CmdStringPath.h"
using namespace std;

void CmdStringMatcher::configCmd(const string& str) {
	CmdStringPath cmdStr(str);
	cmdStr.parse();
	_container.addNode(cmdStr);
}

void CmdStringMatcher::getNextPossibleStrings(const string& str,
		std::vector<std::string>& opts) {
	CmdStringPath cmdStr(str);
	cmdStr.parse();
	_container.getNextPossibleStrings(cmdStr, opts);
}
