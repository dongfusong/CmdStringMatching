/*
 * PartitionSymbolDef.h
 *
 *  Created on: 2014��11��16��
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

//ʹ�÷�ʽ: SYMBOL_TABLE(Partition).isSymbol(c)

#endif /* PARTITIONSYMBOLDEF_H_ */
