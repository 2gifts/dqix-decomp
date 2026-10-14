#include <globaldefs.h>

extern "C" void sprintf(void* buf, void* table, int index);
extern "C" void func_0204719c(void* obj);
extern "C" void func_02047b40(void* elem, int offset, void* param2);

extern int GetFileFromNARCInMemory(const char* filename);

extern int data_020ef7c4;

struct PathBuf0202f310 { char path[0x28]; };

// USA: func_0202f310
ARM void LoadEightEntriesFromTable_0202f310(char* obj, void* param2, void* data) {
    struct PathBuf0202f310 buf;
    char* p;
    int i;
    p = obj;
    for (i = 0; i < 8; i++) {
        int offset;
        sprintf(&buf, &data_020ef7c4, i);
        offset = GetFileFromNARCInMemory((const char*)&buf);
        func_0204719c(p);
        func_02047b40(p, offset, param2);
        p += 0x88;
    }
}
