#include <globaldefs.h>

struct Obj2081;

struct Ctx021ab1a4 {
    char pad[0x18];
    struct Obj2081* obj18;
};

extern unsigned short data_02114e30;
extern unsigned char data_02114e54;

int TestFlag0SetAndFlag1Clear_02012444(unsigned short* obj, int mask);
void SelectCoordsByFlag0x24_02012a84(unsigned char* obj, int* out1, int* out2);
int IsPointInsideElement02080d54(struct Obj2081* obj, int key, int px, int py);

// USA: func_ov017_021ab1a4
ARM int CheckCoordsInsideElement_021ab1a4(struct Ctx021ab1a4* ctx) {
    int flag = 0;
    if (TestFlag0SetAndFlag1Clear_02012444(&data_02114e30, 0x2)) {
        flag = 1;
    }
    if (*(unsigned char*)(&data_02114e54 + 0x55) != 0) {
        int a, b;
        SelectCoordsByFlag0x24_02012a84(&data_02114e54, &a, &b);
        if (!IsPointInsideElement02080d54(ctx->obj18, 0, (short)a, (short)b)) {
            if (!IsPointInsideElement02080d54(ctx->obj18, 1, (short)a, (short)b)) {
                flag = 1;
            }
        }
    }
    return flag;
}
