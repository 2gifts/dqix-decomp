#include <globaldefs.h>

struct UnkStruct0205c508;
extern "C" void _Z26ComputeProductSums0205c508P17UnkStruct0205c508PiS1_(struct UnkStruct0205c508* s, int* out1, int* out2);

int IsField0x118Equal2(void* obj);
extern "C" int _Z22AppendFrameTag02041c08Pciiiii(char* dst, int a1, int a2, int a3, int a4, int a5);
int AppendCursorTag(char* dst, int cursor);
extern "C" int _Z27GetBoundedField156_02171674Pvi(void* obj, int index);
int AppendNameTag(char* dst, int n, const char* name);
struct Container020e0310;
extern "C" int _Z21GetFieldByKey020e0434P17Container020e0310i(struct Container020e0310* c, int key);
extern "C" int _Z20AppendString02042058PcPKc(char* dst, const char* src);

struct Entry02178f28 {
    char pad[0x20];
    signed char cursor;
};

// USA: func_ov000_02178f28
extern "C" ARM void func_ov000_02178f28(char* obj, struct Entry02178f28* entry, char* dst) {
    if (entry != NULL && dst != NULL) {
        int a, b;
        _Z26ComputeProductSums0205c508P17UnkStruct0205c508PiS1_((struct UnkStruct0205c508*)(obj + 0x1dc), &a, &b);
        signed char first = a;
        signed char last = b;
        signed char cursor = entry->cursor;
        if (IsField0x118Equal2(obj)) {
            _Z22AppendFrameTag02041c08Pciiiii(dst, cursor - first, 8, 5, 5, 5);
        }
        AppendCursorTag(dst, cursor - first);
        for (signed char i = first; i < last; i++) {
            const char** name = (const char**)_Z27GetBoundedField156_02171674Pvi(entry, i);
            if (name == NULL) continue;
            AppendNameTag(dst, i - first, *name);
            if (i == last - 1) continue;
            _Z20AppendString02042058PcPKc(dst, (const char*)_Z21GetFieldByKey020e0434P17Container020e0310i((struct Container020e0310*)(obj + 0xb8), 0));
        }
    }
}
