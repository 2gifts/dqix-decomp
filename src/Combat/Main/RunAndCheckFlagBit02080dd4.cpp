#include <globaldefs.h>

extern "C" int func_02080e40(void* obj, int p1, int x, int y);

struct Entry0207f6ac;
struct List0207f6ac;
struct Entry0207f6ac* FindEntryByShortId0207f6ac(struct List0207f6ac* list, int id);

extern "C" void func_02080558(void* obj, int p1, int result, int flag, unsigned char extra);

// USA: func_02080dd4
ARM int RunAndCheckFlagBit02080dd4(void* obj, int p1, int unused2, int unused3, unsigned char* outFlag, unsigned char extra) {
    int result;
    struct Entry0207f6ac* entry;
    result = func_02080e40(obj, p1, unused2, unused3);
    if (result == -1) {
        return -1;
    }
    *outFlag = 0;
    entry = FindEntryByShortId0207f6ac((struct List0207f6ac*)((char*)obj + 4), result);
    if (*((unsigned char*)entry + 0x2a) & 4) {
        *outFlag = 1;
    }
    func_02080558(obj, p1, result, 1, extra);
    return result;
}
