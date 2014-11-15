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
#include "NodeContainer.h"
class CmdMatcher {
public:
	void addCmd(const std::string& str);
	void getRelatedStrings(const std::string& str, std::vector<std::string>& opts);
private:
	NodeContainer _container;
};
#endif /* CMDMATCHER_H_ */
