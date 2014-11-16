/*
 * StringPath.h
 *
 *  Created on: 2014Äê11ÔÂ15ÈÕ
 *      Author: Thoughtworks
 */

#ifndef STRINGPATH_H_
#define STRINGPATH_H_
#include <string>
#define ABSTRACT(...) virtual __VA_ARGS__ = 0;

template<typename T>
struct Path{
	ABSTRACT(virtual void first());
	ABSTRACT(void next())
	ABSTRACT(bool isDone()const);
	ABSTRACT(T getCurrentPart()const);
	virtual ~Path(){}
};

struct StringPath : Path<std::string>{};
#endif /* STRINGPATH_H_ */
