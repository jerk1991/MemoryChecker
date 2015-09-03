#include <stdio.h>
#include <iostream>
#include "MemoryChecker.h"

int int main(int argc, char const *argv[])
{
	int *plen = new int;
	*plen = 0;
	delete plen;
	char* pstr = new char[35];
	strcpy(pstr,"hello memory leek");
	m_memTracer.Dump();
	return 0;
}