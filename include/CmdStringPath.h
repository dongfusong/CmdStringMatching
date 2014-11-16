/*
 * StringPath.h
 *
 *  Created on: 2014Äê11ÔÂ15ÈÕ
 *      Author: Thoughtworks
 */

#ifndef STRING_PATH_H_
#define STRING_PATH_H_
#include <string>
#include <vector>
#include "StringPath.h"
#define SUCCESS 0
#define FAILE 1

struct CmdStringPath : StringPath{
	CmdStringPath(const std::string& str);
	int parse();
	virtual void first();
	virtual void next();
	virtual bool isDone()const;
	virtual std::string getCurrentPart()const;
private:
	bool isSymbol(char c) const;
	int findSymbol(const std::string& str, int beginPos)const;
private:
	std::vector<std::string> _parts;
	size_t _currentIndex;
	std::string _str;
};


#endif /* COMMONDSTRING_H_ */
