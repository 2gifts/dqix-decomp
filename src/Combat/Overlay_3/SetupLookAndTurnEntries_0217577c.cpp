#include <globaldefs.h>

#if defined(jpn)
enum { kOffset104b = 0xfc7 };
enum { kOffset104c = 0xfc8 };
enum { kOffset89c = 0x818 };
#else
enum { kOffset104b = 0x104b };
enum { kOffset104c = 0x104c };
enum { kOffset89c = 0x89c };
#endif


struct Obj2081;
struct Elem2081;
struct Elem2081* FindElementByByte0xc4(struct Obj2081* obj, int key);
int IsField0x9cEqual3(unsigned char* obj);
void GetLookAndTurnOffsets020809c4(void* obj, int id, int id2, short* out1, short* out2);
void InitEntryAtIndex_0217585c(void* obj, int a, int b, int idx, unsigned char c);

struct Ctx0217577c {
    char pad[kOffset89c];
    struct Obj2081* field89c;
};

// JPN: func_ov003_021747cc
// USA: func_ov003_0217577c  (semantic: SetupLookAndTurnEntries_0217577c)
extern "C" ARM void func_ov003_0217577c(void* objRaw) {
    Ctx0217577c* obj = (Ctx0217577c*)objRaw;
    struct Obj2081* target = obj->field89c;
    struct Elem2081* e = FindElementByByte0xc4(target, 9);
    if (e == 0) return;
    if (!IsField0x9cEqual3((unsigned char*)e)) return;

    short out1, out2;
    int flag1 = 0;
    if (*(unsigned char*)((char*)objRaw + kOffset104b) != 0) flag1 = 1;
    GetLookAndTurnOffsets020809c4(target, 9, 0x58, &out1, &out2);
    InitEntryAtIndex_0217585c(objRaw, out1 + flag1, out2 + flag1, 0x1d, 0x1e);

    int flag2 = 0;
    if (*(unsigned char*)((char*)objRaw + kOffset104c) != 0) flag2 = 1;
    GetLookAndTurnOffsets020809c4(target, 9, 0x59, &out1, &out2);
    InitEntryAtIndex_0217585c(objRaw, out1 + flag2, out2 + flag2, 0x1e, 0x1f);
}
