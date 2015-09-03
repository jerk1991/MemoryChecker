#include "MemoryChecker.h"
#include <stdio.h>
#include <malloc.h>
#include <string.h>

MemManager::MemManager() {
	m_pMem_list_header = NULL;
	m_iTotal = NULL;
}

MemManager::~MemManager() {}

void MemManager::Append(mem_list_t* pMem) {
	pMem->pNext = m_pMem_list_header;
	m_pMem_list_header = pMem;
	m_iTotal += m_pMem_list_header->m_nSize;
}

void MemManager::Remove(void* ptr) {
	mem_list_t* pCur = m_pMem_list_header;
	mem_list_t* pPrve = NULL;
	while(pCur) {
		if(pCur->pMem == ptr) {
			if(pPrve) {
				pPrve->pNext = pCur->pNext;
			}
			else {
				m_pMem_list_header = pCur->pNext;
			}
			m_iTotal -= pCur->m_nSize;
			free(pCur);
			break;
		}
		pPrve = pCur;
		pCur = pCur->pNext;
	}
}

void MemManager::Dump() {
	mem_list_t* pp = m_pMem_list_header;
	while(pp) {
		printf("File is %s\n",pp->m_szFileName);
		printf("Size is %d\n",pp->m_nSize);
		printf("Line is %d\n",pp->m_nLine);
		pp = pp->pNext;
	}
}

void PutEntry(void *ptr, int size, const char* szFile, int nLine) {
	mem_list_t* p = (mem_list_t*)(malloc(sizeof(mem_list_t)));
	if(p) {
		strcpy(p->m_szFileName,szFile);
		p->pMem = ptr;
		p->m_nSize = size;
		MemManager::GetInstance()->Append(p);
	}
}

void RemoveEntry(void *ptr) {
	MemManager::GetInstance()->Remove(ptr);
}

void operator new(size_t size, const char* szFile, int nLine) {
	void * ptr = malloc(size);
	PutEntry(ptr,size,szFile,nLine);
	return ptr;
}

void operator delete(void *ptr) {
	RemoveEntry(ptr);
	//free(ptr);
}

void *operator new[](size_t size,const char* szFile,int nLine) {
	void * ptr = malloc(size);
	PutEntry(ptr,size,szFile,nLine);
	return ptr;
}

void operator delete[](void *ptr,const char* szFile,int nLine) {
	RemoveEntry(ptr);
	//free(ptr);
}

void operator delete(void *ptr,const char* szFile,int nLine) {
	RemoveEntry(ptr);
}

#define new new(__FILE__, __LINE__)

MemManager m_memTracer;

MemManager* MemManager::GetInstance() {
	return &m_memTracer;
}



