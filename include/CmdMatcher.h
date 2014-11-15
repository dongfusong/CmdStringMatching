/*
 * CmdMatcher.h
 *
 *  Created on: 2014Äê11ÔÂ15ÈÕ
 *      Author: Thoughtworks
 */
#ifndef CMDMATCHER_H_
#define CMDMATCHER_H_
#include <string>
#include <vector>
#include "CmdNodeContainer.h"
struct CmdMatcher {
	void configCmd(const std::string& str);
	void getNextPossibleStrings(const std::string& str, std::vector<std::string>& opts);
private:
	CmdNodeContainer _container;
};
#endif /* CMDMATCHER_H_ */
