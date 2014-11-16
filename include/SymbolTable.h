/*
 * SymbolTable.h
 *
 *  Created on: 2014Äê11ÔÂ15ÈÕ
 *      Author: Thoughtworks
 */

#ifndef SYMBOLTABLE_H_
#define SYMBOLTABLE_H_
#include <set>

#define SYMBOL_TABLE(name) name##SymbolTable::getInstance()

#define DEF_SYMBOL_TABLE(name) struct name##SymbolTable : SymbolTable\
{\
	static name##SymbolTable getInstance(){\
		static name##SymbolTable instance;\
		static bool init = false;\
		if (!init){ instance.addSymbols(); init = true;}\
		return instance;\
	}\
private: name##SymbolTable(){}\
void addSymbols(){

#define DEF_SYMBOL(c) insertSymbol(c);

#define END()\
}\
};

struct SymbolTable {
	SymbolTable(){
	}
	bool isSymbol(char c)const{
		return _symbols.end() != _symbols.find(c);
	}
	virtual ~SymbolTable(){

	}
	virtual void addSymbols() = 0;
protected:
	void insertSymbol(char c){
		_symbols.insert(c);
	}
	std::set<char> _symbols;
};







#endif /* SYMBOLTABLE_H_ */
