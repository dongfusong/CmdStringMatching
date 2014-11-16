/*
 * PartitionSymbolDef.h
 *
 *  Created on: 2014年11月16日
 *      Author: Thoughtworks
 */

#ifndef PARTITIONSYMBOLDEF_H_
#define PARTITIONSYMBOLDEF_H_
#include "SymbolTable.h"

DEF_SYMBOL_TABLE(Partition)
	DEF_SYMBOL('-')
	DEF_SYMBOL('/')
	DEF_SYMBOL(':')
END()

//使用方式: SYMBOL_TABLE(Partition).isSymbol(c)

#endif /* PARTITIONSYMBOLDEF_H_ */
