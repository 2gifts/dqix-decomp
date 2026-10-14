#include <globaldefs.h>
void LoadEightEntriesFromTable_0202f310(char*, void*, void*);

// USA: func_020440b8
ARM void CallFunc0202f310AtField0x19e0_020440b8(char* base, void* arg, void* data) {
#if defined(jpn)
    LoadEightEntriesFromTable_0202f310((char*)(base + 0x1804), (void*)(arg), data);
#else
    LoadEightEntriesFromTable_0202f310((char*)(base + 0x19e0), (void*)(arg), data);
#endif
}
