/*
 * CmdNode.h
 *
 *  Created on: 2014Äê11ÔÂ15ÈÕ
 *      Author: Thoughtworks
 */

#ifndef NODE_H_
#define NODE_H_
#include "CmdNodeContainer.h"
struct StringPath;
struct CmdNode {
	CmdNode(const std::string& content, StringPath& restStr);
	void addChild(StringPath& str);
	void getNextPossibleStrings(StringPath& str, std::vector<std::string>& opts)const;
	std::string getContent() const;
private:
	std::string _content;
	CmdNodeContainer _childs;
};
#endif /* NODE_H_ */
