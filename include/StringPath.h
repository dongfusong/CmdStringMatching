/*
 * StringPath.h
 *
 *  Created on: 2014Äê11ÔÂ15ÈÕ
 *      Author: Thoughtworks
 */

#ifndef STRING_PATH_H_
#define STRING_PATH_H_
#include <string>
struct StringPath {
	StringPath(const std::string& str);
	std::string getCurrentPart();
	void next();
	bool isDone()const;
private:
	bool isSymbol(char c) const;
	int findSymbol(const std::string& str, int beginPos)const;
private:
	const std::string& _str;
	size_t _currentPartPos;
	size_t _nextPartPos;
};
#endif /* COMMONDSTRING_H_ */
