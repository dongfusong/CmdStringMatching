#include "CmdMatcher.h"
#include "StringPath.h"
using namespace std;
void CmdMatcher::addCmd(const string& str) {
	StringPath cmdStr(str);
	_container.add(cmdStr);
}

void CmdMatcher::getRelatedStrings(const string& str,
		std::vector<std::string>& opts) {
	StringPath cmdStr(str);
	_container.getRelatedStrings(cmdStr, opts);
}
