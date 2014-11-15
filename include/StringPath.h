/*
 * CommondString.h
 *
 *  Created on: 2014Äê11ÔÂ15ÈÕ
 *      Author: Thoughtworks
 */

#ifndef COMMONDSTRING_H_
#define COMMONDSTRING_H_
#include <string>

class StringPath {
public:
	StringPath(const std::string& str);
	std::string getCurrentPart();
	void next();
	bool isDone()const;
private:
	bool isSymbol(char c) const;
	int findSymbol(const std::string& str, int beginPos);
private:
	std::string _content;
	size_t _currentPartPos;
	size_t _nextPartPos;
};
#endif /* COMMONDSTRING_H_ */
