#include <globaldefs.h>

struct Variant02030b0c {
    int tag;
    union { int i; float f; } u;
};
struct Struct02030b7c;
extern "C" int _ZNK6Script9Parameter5ToIntEv(struct Variant02030b0c* p);
extern "C" void* _ZNK6Script9Parameter8ToStringEv(struct Struct02030b7c* s);
void UpdateStringField02023b0c(char* a, char* b);
extern "C" void func_020277f4(void* obj, int a, void* b, void* allocator);

struct Global020fdc4c_f528 {
    int pad0;

#if !defined(jpn)
    int pad4;
#endif
    void* field8;
    int padc;
    void* field10;
};
extern struct Global020fdc4c_f528 data_020fdc4c;

// USA: func_0201f528
ARM int SetDecodedStringEntry0201f528(struct Variant02030b0c* arg0) {
    int a = _ZNK6Script9Parameter5ToIntEv(arg0);
    void* b = _ZNK6Script9Parameter8ToStringEv((struct Struct02030b7c*)((char*)arg0 + 0x8));
    if (b == 0) return 0;
    UpdateStringField02023b0c((char*)data_020fdc4c.field10, (char*)b);
    func_020277f4(data_020fdc4c.field10, a, b, data_020fdc4c.field8);
    return 1;
}
