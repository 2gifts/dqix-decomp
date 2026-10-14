#include <globaldefs.h>

extern char data_02114e54;

struct Struct_0205d81c;
struct Elem_0205d81c;
Elem_0205d81c* FindElementByC40205d81c(Struct_0205d81c*, int);

struct ShortArrays0204c610;
void GetFourShortsAtIndex(struct ShortArrays0204c610* base, int index, short* out0, short* out1, short* out2, short* out3);

int IsWithinRect_02012734(unsigned char* obj, int x, int y, int width, int height);

// USA: func_ov013_021842a0  (semantic: GetElemRectHit021842a0)
extern "C" ARM int func_ov013_021842a0(void* obj, int index) {
    if (!*(unsigned char*)((char*)&data_02114e54 + 0x5c)) goto fail;

    {
    Elem_0205d81c* elem = FindElementByC40205d81c((Struct_0205d81c*)obj, 0);
    if (elem == 0) goto fail;

    short elemAc = *(short*)((char*)elem + 0xac);
    short elemAe = *(short*)((char*)elem + 0xae);

    short out0, out1, out2, out3;
    GetFourShortsAtIndex((struct ShortArrays0204c610*)elem, (short)index, &out0, &out1, &out2, &out3);

    return IsWithinRect_02012734((unsigned char*)&data_02114e54, out0 + (short)(elemAc << 3), out1 + (short)(elemAe << 3), out2, out3);
    }

fail:
    return 0;
}
