#include <globaldefs.h>

extern "C" void* func_ov000_02170cf8(char* obj, int val);
extern "C" int func_ov000_02171210(void* a, void* b);
extern "C" void* __clear(void* dst, int count);
extern "C" void func_020e4864(int a, void* b, int c, int d, int e, int f);
void CopyTextAndUppercaseIfFlagged0206819c(const char* src, char* dst, int flag);

struct Obj0203c108;
void SwapGlobalEntry0203c108(struct Obj0203c108* obj, char* fmt);

// USA: func_ov000_021718a4  (semantic: RecordEntryAndLogMessage_021718a4)
extern "C" ARM void func_ov000_021718a4(void* self) {
    unsigned char* base = (unsigned char*)self + 8;
    unsigned short val = *(unsigned short*)(base + 0x1e);
    void* entry = func_ov000_02170cf8((char*)self, val);
    if (entry == 0) return;

    signed char counter = *(signed char*)(base + 0x10);
    counter = counter + 1;
    *(signed char*)(base + 0x10) = counter;

    int result = func_ov000_02171210(entry, self);

    signed char counter2 = *(signed char*)(base + 0x10);
    unsigned char* slot = base + counter2;
    slot[8] = (unsigned char)result;

#if defined(jpn)
    SwapGlobalEntry0203c108((struct Obj0203c108*)((char*)self + 0x50), *(char**)entry);
#else
    char buf1[0x80];
    __clear(buf1, 0x80);
    char buf2[0x80];
    __clear(buf2, 0x80);

    func_020e4864(*(int*)entry, buf1, 1, 0, 0, 0);

    CopyTextAndUppercaseIfFlagged0206819c(buf1, buf2, 0);
    SwapGlobalEntry0203c108((struct Obj0203c108*)((char*)self + 0x50), buf2);
#endif
}
