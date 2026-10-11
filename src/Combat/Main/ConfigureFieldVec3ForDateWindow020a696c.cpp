#include <globaldefs.h>
#if defined(jpn)
enum { kCodeOffset = 0x27c6, kXTarget = 0x27cc, kYTarget = 0x27d0, kXSource = 0x64, kYSource = 0x68 };
#else
enum { kCodeOffset = 0x2786, kXTarget = 0x278c, kYTarget = 0x2790, kXSource = 0x44, kYSource = 0x48 };
#endif
#include "GameState/GameState.h"

extern "C" void* func_02012fe4(GameState* battleStruct);
void* GetField0x3f8Address(GameState* battleStruct);
extern "C" void _ZN8Vector3iaSERKS_(int* dst, int* src);
struct Vec3Target020a6aa4 { int x; int y; int z; };
void SetVec3At0x0020a6aa4(struct Vec3Target020a6aa4* obj, int x, int y, int z);

// USA: func_020a696c
ARM void ConfigureFieldVec3ForDateWindow(void* unused0, int value1, int value2) {
    GameState* battleStruct = GameState::GetInstance();
    void* base = func_02012fe4(battleStruct);
    void* fieldPtr = GetField0x3f8Address(battleStruct);

    if (value2 == 0x170c) {
        if ((value1 >= 0x4e20 && value1 <= 0x752f) || value1 == 0x76c) {
            unsigned char* p = (unsigned char*)fieldPtr;
            if (p[0x5] == 0 && p[0x62] == 0) {
                unsigned short u = *(unsigned short*)((char*)base + kCodeOffset);
                *(unsigned short*)fieldPtr = u;
                switch (u) {
                case 0:
                case 1:
                {
                    int localBuf[3];
                    int code = 0x170c;
                    *(unsigned short*)fieldPtr = code;
                    SetVec3At0x0020a6aa4((struct Vec3Target020a6aa4*)localBuf, -0x7000, code >> 3, 0x5e66);
                    _ZN8Vector3iaSERKS_((int*)((char*)fieldPtr + 0x10), localBuf);
                    p[0x7] = 1;
                    break;
                }
                default:
                    if (u != 0x76c) {
                        *(int*)((char*)fieldPtr + 0x10) = 0x100000;
                        *(int*)((char*)fieldPtr + 0x14) = 0;
                        *(int*)((char*)fieldPtr + 0x18) = 0x100000;
                        p[0x7] = 1;
                    }
                    break;
                }
            }
        }
    }

    if (value1 == 0x2710 && value2 >= 0x4e20 && value2 <= 0x752f) {
        *(int*)((char*)base + kXTarget) = *(int*)((char*)base + kXSource);
        *(int*)((char*)base + kYTarget) = *(int*)((char*)base + kYSource);
    }
}
