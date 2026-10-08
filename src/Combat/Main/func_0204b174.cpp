#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

extern "C" void __clear(void* buf, int len);
extern "C" int func_02001aec(void* a, void* b, int n);

struct Rec0204a848;
struct Rec0204acdc;
struct Obj0204aa64;

typedef void (*Cb0204b174)(const void*, int, unsigned int);

extern "C" int _Z22DeserializeAndDispatchP11Rec0204a848PFvPKvijEPh(Rec0204a848* dst, Cb0204b174 cb, unsigned char* src, void* extra);
int DeserializeAndAllocate(Rec0204acdc* dst, void* unused, unsigned char* src, SafeAllocator* alloc);
extern "C" int func_0204aa64(Obj0204aa64* obj, Cb0204b174 cb, unsigned char* src, void* src2);

extern char data_020f0238;
extern char data_020f023d;
extern char data_020f0242;
extern int data_020f01f8[][4];
extern Cb0204b174 data_020f01b0[];
extern int data_020f0218[][4];

struct Self0204b174 {
    unsigned char pad0[0x10];
    Rec0204acdc* f10;
    unsigned char pad14[8];
    unsigned char lo : 4;
    unsigned char hi : 4;
    unsigned char index;
    unsigned char limit;
};

// USA: func_0204b174
extern "C" ARM int func_0204b174(struct Self0204b174* self, char* str, Cb0204b174 cb) {
    char buf[5];

    if (str == 0) {
        return 1;
    }

    __clear(buf, 5);
    memcpy(buf, str, 5);

    if (func_02001aec(buf, &data_020f0238, 4) == 0) {
        Cb0204b174 fn = (Cb0204b174)data_020f01f8[self->lo][self->hi];
        return _Z22DeserializeAndDispatchP11Rec0204a848PFvPKvijEPh((Rec0204a848*)self, fn, (unsigned char*)str, (void*)cb);
    }

    if (func_02001aec(buf, &data_020f023d, 4) == 0) {
        Cb0204b174 fn = data_020f01b0[self->lo];
        return func_0204aa64((Obj0204aa64*)((char*)self + 0xc), fn, (unsigned char*)str, (void*)cb);
    }

    if (func_02001aec(buf, &data_020f0242, 4) == 0) {
        if (self->f10 != 0) {
            if (self->limit <= self->index) {
                return 1;
            }
            int r = DeserializeAndAllocate((Rec0204acdc*)((char*)self->f10 + self->index * 0x10),
                                           (void*)(Cb0204b174)data_020f0218[self->lo][self->hi],
                                           (unsigned char*)str, (SafeAllocator*)cb);
            if (r != 0) {
                return 1;
            }
            self->index = self->index + 1;
            return 0;
        }
    }

    return 1;
}