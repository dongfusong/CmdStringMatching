/*
 * CmdNode.h
 *
 *  Created on: 2014Äê11ÔÂ15ÈÕ
 *      Author: Thoughtworks
 */

#ifndef NODE_H_
#define NODE_H_
#include "CmdNodeContainer.h"
struct CmdStringPath;
struct CmdNode {
	CmdNode(const std::string& content, StringPath& path);
	void addChild(StringPath& path);
	void getNextPossibleStrings(StringPath& path, std::vector<std::string>& opts)const;
	std::string getContent() const;
private:
	std::string _content;
	CmdNodeContainer _childs;
};
#endif /* NODE_H_ */
