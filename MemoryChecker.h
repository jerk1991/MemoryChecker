#ifndef _MEMORY_CHECKER_H_
#define _MEMORY_CHECKER_H_

typedef struct mem_list_s
{
	void* pMem;
	ssize_t m_nsize;
	char m_szFilename[256];
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

void* operator new(size_t size, const char* szFile, int nline);
void operator delete(void* ptr, const char* szFile, int nline);
void operator delete(void *ptr);
void* operator new[](size_t size, const char* szFile, int nline);
void operator delete[](void* ptr, const char* szFile, int nline);
void operator delete[](void* ptr);ß
#endif
