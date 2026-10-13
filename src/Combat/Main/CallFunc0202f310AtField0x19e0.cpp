#include <globaldefs.h>
void LoadEightEntriesFromTable(char*, void*);


// USA: func_020440b8
ARM void CallFunc0202f310AtField0x19e0(char* base, void* arg, void*) {
#if defined(jpn)
    LoadEightEntriesFromTable((char*)(base + 0x1804), (void*)(arg));
#else
    LoadEightEntriesFromTable((char*)(base + 0x19e0), (void*)(arg));
#endif
}
