/*
 * NodeContainer.h
 *
 *  Created on: 2014Äê11ÔÂ15ÈÕ
 *      Author: Thoughtworks
 */

#ifndef NODECONTAINER_H_
#define NODECONTAINER_H_
#include <map>
#include <string>
#include <vector>
class StringPath;
class Node;
class NodeContainer {
public:
	typedef std::map<std::string, Node*> NodeMap;
	void add(StringPath& str);
	void getRelatedStrings(StringPath& str, std::vector<std::string>& opts);
private:
	NodeMap _nodes;
};
#endif /* NODECONTAINER_H_ */
