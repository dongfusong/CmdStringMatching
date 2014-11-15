/*
 * SymbolTable.h
 *
 *  Created on: 2014Äê11ÔÂ15ÈÕ
 *      Author: Thoughtworks
 */

#ifndef SYMBOLTABLE_H_
#define SYMBOLTABLE_H_
#include <set>
struct SymbolTable {
	static SymbolTable getInstance(){
		static SymbolTable instance;
		return instance;
	}
	bool isSymbol(char c)const{
		return _symbols.end() != _symbols.find(c);
	}
private:
	SymbolTable(){
		_symbols.insert('/');
		_symbols.insert(':');
		_symbols.insert('-');
	}
	std::set<char> _symbols;
};

#endif /* SYMBOLTABLE_H_ */
