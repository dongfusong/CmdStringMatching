/*
 * Node.h
 *
 *  Created on: 2014Äê11ÔÂ15ÈÕ
 *      Author: Thoughtworks
 */

#ifndef NODE_H_
#define NODE_H_
#include "NodeContainer.h"
class StringPath;
class Node {
public:
	Node(const std::string& content, StringPath& restStr);
	void add(StringPath& str);
	void getRelatedStrings(StringPath& str, std::vector<std::string>& opts);
	std::string getContent() const;
private:
	std::string _content;
	NodeContainer _childs;
};
#endif /* NODE_H_ */
