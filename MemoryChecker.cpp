#include "MemoryChecker.h"
#include <stdio.h>
#include <malloc.h>
#include <string.h>

MemoryChecker::MemoryChecker() {
	m_pMem_list_header = NULL;
	m_iTotal = NULL;
}

MemoryChecker::~MemoryChecker() {}

void MemoryChecker::Append(mem_list_t* pMem) {
	pMem->pNext = m_pMem_list_header;
	m_pMem_list_header = pMem;
	m_iTotal += m_pMem_list_header->m_nsize;
}

void MemoryChecker::Remove(void* ptr) {
	mem_list_t* pCur = m_pMem_list_header;
	mem_list_t* pPrve = NULL;
	ß
}