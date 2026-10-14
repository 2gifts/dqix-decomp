#include <globaldefs.h>

struct Obj020bc180;
void CallFunc020c0204OnActiveNode(Obj020bc180*, int, int);
void SetEntryByte_020bbf34(int, int);

extern float data_020e8ec4[];

struct TweenScaleFields0209c2e0 {
    char pad0[0xc8];
    unsigned char fc8_bit0 : 1;
    unsigned char fc8_half : 1;
    unsigned char fc8_rest : 6;
    char pad_c9[3];
    unsigned char fcc;
    unsigned char fcd;
};

// USA: func_0209c2e0  (semantic: UpdateTweenScaleAndSetEntryBytes_0209c2e0)
extern "C" ARM void func_0209c2e0(TweenScaleFields0209c2e0* obj, int b, int arg2) {
    obj->fcd = (unsigned char)b;
    int fccVal = obj->fcc;
    float scale = ((float)fccVal - 1.0f) / 4.0f;
    int v = (int)((float)obj->fcd * scale);
    if (obj->fc8_half) {
        v = v / 2;
    }
    CallFunc020c0204OnActiveNode((Obj020bc180*)((char*)obj + 0xbc), v, arg2);
    CallFunc020c0204OnActiveNode((Obj020bc180*)((char*)obj + 0xc0), v, arg2);
    int result = (int)((float)obj->fcd * data_020e8ec4[obj->fcc - 1]);
    SetEntryByte_020bbf34(5, result);
    SetEntryByte_020bbf34(7, result);
    SetEntryByte_020bbf34(6, result);
}
