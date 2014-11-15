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
	StringPath(const std::string& str):_content(str){

	}

	std::string getCurrentPart(){
		return "";
	}
	void next(){

	}
	bool isDone(){
		return true;
	}
private:
	std::string _content;
};





#endif /* COMMONDSTRING_H_ */
