/*
 * NodeContainer.h
 *
 *  Created on: 2014��11��15��
 *      Author: Thoughtworks
 */

#ifndef CMD_NODECONTAINER_H_
#define CMD_NODECONTAINER_H_
#include <map>
#include <string>
#include <vector>
struct StringPath;
struct CmdNode;
struct CmdNodeContainer {
	void addNode(StringPath& str);
	void getNextPossibleStrings(StringPath& str, std::vector<std::string>& opts)const;
private:
	typedef std::map<std::string, CmdNode*> NodeMap;
	typedef NodeMap::iterator Iterator;
	typedef NodeMap::const_iterator ConstIterator;
	NodeMap _nodes;
};
#endif /* NODECONTAINER_H_ */
