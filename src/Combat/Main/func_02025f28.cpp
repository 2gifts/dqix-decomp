#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_0205ec34(void);
void* GetData02105254_0203b628(void);
extern "C" void* func_02012fe4(void);

struct Bcb8Params;
void ForwardParamsToB8bc_0203bcb8(struct Bcb8Params* s, int arg1, int arg2);

struct Obj_0201bb78 { unsigned short field0; };
int LookupBitFromValueRange0201bb78(struct Obj_0201bb78* obj, unsigned int val);

void _Z24SetElementFields0202756cPviiihhthii(void* obj, int p1, int p2, int idx,
        unsigned char p5, unsigned char p6, unsigned short p7, unsigned char p8, int p9, int p10);

int TestBitInByteArray_0206dfb0(int unused, unsigned char* arr, int index);
void ClampPositionToBounds0202630c(void* obj, int* pos, int margin);

extern "C" int _u32_div_f(int a, int b);
extern "C" int _s32_div_f(int a, int b);
extern "C" int abs(int x);
extern "C" void ColorEffect_ConfigureAlphaBlend(unsigned int* out, unsigned char a, unsigned char b, int c, int d);

extern int data_020fdc4c;

struct Elem0xa9c {
    unsigned short h0;
    unsigned char b2;
    char pad3;
    int w4;
    int w8;
};

struct Vec3i { int x, y, z; };

struct G8Obj {
    char pad[0xc];
    unsigned char lowNibble : 4;
    unsigned char highNibble : 4;
};

// USA: func_02025f28
extern "C" ARM void func_02025f28(unsigned char* obj) {
    GameState* battle = GameState::GetInstance();
    unsigned char* ctx = (unsigned char*)func_0205ec34();
    GetData02105254_0203b628();
    void* g = func_02012fe4();
    unsigned short g0 = *(unsigned short*)g;
    void* g8 = *(void**)((char*)g + 8);
    GameObject* c1 = battle->GetUnknownGameObject();
    battle->GetProtagonist();
    struct Vec3i pos0 = *(struct Vec3i*)((char*)c1 + 0x44);

    if (*(unsigned char*)(obj + 0x55c) != 0) {
        *(unsigned char*)(obj + 0x55c) = 0;
        ForwardParamsToB8bc_0203bcb8((struct Bcb8Params*)(*(char**)(obj + 0x20) + 8), 0, 0);
    }

    int p6a = 1;
    for (int i = 0; i < *(unsigned char*)(obj + 0xa99); i++) {
        struct Elem0xa9c* arr = *(struct Elem0xa9c**)(obj + 0xa9c);
        int result = LookupBitFromValueRange0201bb78((struct Obj_0201bb78*)g, (unsigned short)(arr[i].h0 * 100));
        if (result == 0) continue;
        struct Elem0xa9c* e = *(struct Elem0xa9c**)(obj + 0xa9c) + i;
        if (e->b2 == 1) {
            _Z24SetElementFields0202756cPviiihhthii(obj, e->w4 + 0x7d000, e->w8 + 0x5d000, 0x18,
                (i + 0x55) & 0xff, p6a, 0xff, 0xff, 0x1000, 0x1000);
        } else if (e->b2 == 2) {
            _Z24SetElementFields0202756cPviiihhthii(obj, e->w4 + 0x7d000, e->w8 + 0x5d000, 0x17,
                (i + 0x55) & 0xff, 0, 0xff, 0xff, 0x1000, 0x1000);
        }
    }

    int flag2 = (g0 != 10000) && (TestBitInByteArray_0206dfb0((int)ctx, ctx + 0x8c, 0x2b) != 0);
    int posVec[3];
    int ok = 1;
    if (g0 == 10000 || g0 == 10100) {
        posVec[0] = pos0.x + 0x80000;
        posVec[2] = pos0.z + 0x60000;
    } else if (((struct G8Obj*)g8)->lowNibble == 0) {
        posVec[0] = fix32_Divide((fix32_t)(pos0.x + *(int*)((char*)g + 0x44)), (fix32_t)(0x6000)) + 0x80000;
        posVec[2] = fix32_Divide((fix32_t)(pos0.z + *(int*)((char*)g + 0x48)), (fix32_t)(0x6000)) + 0x60000;
    } else {
        int g44 = *(int*)((char*)g + 0x44);
        if (g44 == 0 || *(int*)((char*)g + 0x48) == 0) {
            if (g44 == 0) ok = 0;
        } else {
            posVec[0] = g44 + 0x80000;
            posVec[2] = *(int*)((char*)g + 0x48) + 0x60000;
        }
    }

    if (flag2) {
        struct Vec3i v = *(struct Vec3i*)((char*)g + 0x2774);
        v.x += 0x80000;
        v.z += 0x60000;
        ClampPositionToBounds0202630c(obj, (int*)&v, 0x7000);
        v.x -= 0x4000;
        v.z -= 0x4000;
        _Z24SetElementFields0202756cPviiihhthii(obj, v.x, v.z, 0x19, 0x54, 0, 0xff, 0xff, 0x1000, 0x1000);
    }

    int fieldVal = battle->GetEffectiveDeltaTime();
    unsigned int sum = *(unsigned int*)((char*)&data_020fdc4c + 0xc) + (unsigned int)fieldVal;
    unsigned int rem = sum % 0x560u;
    int q = ((int)rem - 0x2b0) / 0x2b;
    *(unsigned int*)((char*)&data_020fdc4c + 0xc) = rem;
    int absQ = abs(q);
    int q2 = (absQ * 0x4b) / 100;
    int c = q2 + 5;
    if (c > 0x10) c = 0x10;
    int d = 0x10 - c;
    ColorEffect_ConfigureAlphaBlend((unsigned int*)0x04001050, 0, 3, c, d);

    ClampPositionToBounds0202630c(obj, posVec, 0x5000);
    posVec[0] -= 0x4000;
    posVec[2] -= 0x4000;

    if (ok) {
        short f4 = *(short*)((char*)c1 + 4);
        unsigned char p5 = (unsigned char)(f4 + 0x44);
        unsigned short p7 = (unsigned short)(f4 + 4);
        _Z24SetElementFields0202756cPviiihhthii(obj, posVec[0], posVec[2], 5, p5, 0, p7, 0xff, 0x1000, 0x1000);
    }
}
