#include <globaldefs.h>

struct UnkStruct0205c508;
struct Container020e0310;

extern "C" void _Z26ComputeProductSums0205c508P17UnkStruct0205c508PiS1_(struct UnkStruct0205c508* s, int* out1, int* out2);
extern "C" int _Z21GetFieldByKey020e0434P17Container020e0310i(struct Container020e0310* c, int key);
int IsField0x118Equal2(void* obj);
extern "C" int _Z22AppendFrameTag02041c08Pciiiii(char* dst, int a1, int a2, int a3, int a4, int a5);
int AppendCursorTag(char* dst, int cursor);
extern "C" int _Z20GetNthSetBit0218158cPvi(void* obj, int n);
int AppendNameTag(char* dst, int n, const char* name);
extern "C" int _Z20AppendString02042058PcPKc(char* dst, const char* src);

// USA: func_ov000_02177f74
extern "C" ARM void func_ov000_02177f74(void* base, char* dst) {
    int first;
    int last;
    _Z26ComputeProductSums0205c508P17UnkStruct0205c508PiS1_((struct UnkStruct0205c508*)((char*)base + 0x1dc), &first, &last);
    signed char start = first;
    signed char end = last;
    struct Container020e0310* c = (struct Container020e0310*)((char*)base + 0xb8);
    int sep = _Z21GetFieldByKey020e0434P17Container020e0310i(c, 0);
    signed char cursor = *(signed char*)((char*)base + 0x1d00 + 0x6e);
    int n = 0;

    if (IsField0x118Equal2(base)) {
        _Z22AppendFrameTag02041c08Pciiiii(dst, cursor - start, 8, 5, 5, 5);
    }
    AppendCursorTag(dst, cursor - start);

    for (signed char i = start; i < end; i++) {
        short bit = _Z20GetNthSetBit0218158cPvi(base, i);
        short key = bit + 7;
        int name = _Z21GetFieldByKey020e0434P17Container020e0310i(c, key);
        AppendNameTag(dst, n, (const char*)name);
        if (i != end - 1) {
            _Z20AppendString02042058PcPKc(dst, (const char*)sep);
        }
        n++;
    }
}
