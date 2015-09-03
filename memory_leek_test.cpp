#include <stdio.h>
#include <iostream>
#include "MemoryChecker.h"
#define new DEBUG_NEW
#define DEBUG_NEW new(__FILE__,__LINE__)

int main(int argc, char const *argv[])
{
	int *plen = new int;
	*plen = 0;
	delete plen;
	char* pstr = new char[35];
	strcpy(pstr,"hello memory leek");
	MemManager::GetInstance()->Dump();
	return 0;
}
