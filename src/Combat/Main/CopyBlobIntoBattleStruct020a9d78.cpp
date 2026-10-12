#include <globaldefs.h>

#if defined(jpn)
#define CopyBlobIntoBattleStruct020a9d78 func_020ab9c8
#define SetField0x27d8 func_0201b9f4
#define SetField0x27da func_0201ba00
enum { RegionOffset = 0x7c38 };
#else
enum { RegionOffset = 0x7e78 };
#endif
#include "GameState/GameState.h"

void* GetField0x3f8Address(GameState* battleStruct);
extern "C" void _ZN8Vector3iaSERKS_(int* dst, int* src);
extern "C" void* func_02012fe4();
struct S_bc7c;
#if defined(jpn)
extern "C" void func_0201b9f4(struct S_bc7c* obj, unsigned short val);
#endif
void SetField0x27d8(struct S_bc7c* obj, unsigned short val);
struct S_bc88;
#if defined(jpn)
extern "C" void func_0201ba00(struct S_bc88* obj, unsigned short val);
#endif
void SetField0x27da(struct S_bc88* obj, unsigned short val);

struct Data02109bf4 {
    unsigned char pad[0xc8];
    unsigned char b0 : 1;
    unsigned char b1 : 1;
    unsigned char b2 : 1;
    unsigned char b3 : 1;
};
extern struct Data02109bf4 data_02109bf4;

#if defined(jpn)
extern "C" ARM int func_020ab9c8(void* srcRaw);
#endif

// USA: func_020a9d78
ARM int CopyBlobIntoBattleStruct020a9d78(void* srcRaw) {
    char* src = (char*)srcRaw;
    GameState* battleStruct = GameState::GetInstance();
    char* dst = (char*)GetField0x3f8Address(battleStruct);

    *(unsigned short*)(dst + 0x0) = *(unsigned short*)(src + 0x0);
    _ZN8Vector3iaSERKS_((int*)(dst + 0x10), (int*)(src + 0x4));

    *(short*)(dst + 0x1c) = *(short*)(src + 0x2);
    *(unsigned char*)(dst + 0x7) = 1;

    void* g = func_02012fe4();
    SetField0x27d8((struct S_bc7c*)g, *(unsigned short*)(src + 0x12));
    SetField0x27da((struct S_bc88*)g, *(unsigned short*)(src + 0x10));

    data_02109bf4.b3 = (*(unsigned char*)(src + 0x14) != 0);

    char* region = (char*)battleStruct + RegionOffset;
    *(short*)(region + 0x0) = *(short*)(src + 0x16);
    *(short*)(region + 0x2) = *(short*)(src + 0x18);
    *(short*)(region + 0x4) = *(short*)(src + 0x1a);
    *(signed char*)(region + 0x6) = *(signed char*)(src + 0x15);
    return 1;
}
