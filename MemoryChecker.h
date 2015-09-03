#ifndef _MEMORY_CHECKER_H_
#define _MEMORY_CHECKER_H_
#include "MemoryChecker.h"
#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct mem_list_s
{
	void* pMem;
	size_t m_nSize;
	char m_szFileName[256];
	int m_nLine;
	struct mem_list_s* pNext;
} mem_list_t;


class MemManager {

public:
	MemManager();
	~MemManager();
	static MemManager* GetInstance();
	void Append(mem_list_t* pMem);
	void Remove(void* ptr);
	void Dump();
private:
	mem_list_t* m_pMem_list_header;
	int m_iTotal;
};

//void* operator new(size_t size);
void* operator new(size_t size, const char* szFile, const int nline);
void operator delete(void* ptr, const char* szFile, const int nline);
//void operator delete(void *ptr);
//void* operator new[](size_t size);
void* operator new[](size_t size, const char* szFile, const int nline);
void operator delete[](void* ptr, const char* szFile, const int nline);
//void operator delete[](void* ptr);
#endif
