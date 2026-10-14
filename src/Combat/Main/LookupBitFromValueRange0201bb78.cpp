#include <globaldefs.h>

extern "C" unsigned char* func_0205ec34(void* obj, int val);
int ConvertIndex_02012f68(int x);
int TestBitInByteArray_0206dfb0(int unused, unsigned char* arr, int index);
int LookupKeyValue_02012f24(int key);
extern "C" int _s32_div_f(int a, int b);

struct Obj_0201bb78 { unsigned short field0; };

// USA: func_0201bb78
ARM int LookupBitFromValueRange0201bb78(struct Obj_0201bb78* obj, unsigned int val) {
    unsigned char* ctx = func_0205ec34(obj, val);
    int result = 0;
    if (val >= 20000 && val <= 0x752f) {
        int t = ConvertIndex_02012f68(val);
        if (t >= 0) {
            result = TestBitInByteArray_0206dfb0((int)ctx, ctx + 0x8c, t + 0x5a + 0xa00);
        }
    } else if (val >= 100 && val <= 0x270f) {
        int q = _s32_div_f(val, 100);
        if (q < 100) {
            result = TestBitInByteArray_0206dfb0((int)ctx, ctx + 0x8c, q + 0x96 + 0xa00);
        }
    } else if (val == 10000) {
        result = TestBitInByteArray_0206dfb0((int)ctx, ctx + 0x8c, 0x2b);
    } else {
        int t = LookupKeyValue_02012f24(obj->field0);
        if (t >= 0) {
            result = TestBitInByteArray_0206dfb0((int)ctx, ctx + 0x8c, t + 0x5a + 0xa00);
        }
    }
    return result;
}
