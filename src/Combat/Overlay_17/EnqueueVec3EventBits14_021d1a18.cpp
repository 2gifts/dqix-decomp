// JPN: func_ov017_021d1e9c
#if defined(jpn)
enum { RegionOffset2774 = 0x27b4, RegionOffset2780 = 0x27c0 };
#else
enum { RegionOffset2774 = 0x2774, RegionOffset2780 = 0x2780 };
#endif

#include <globaldefs.h>
#include "GameState/GameState.h"

struct SearchStruct0202c1a4 {
    char pad[0x1038];
    signed char arr[16];
};

extern "C" int* func_0202ae18(void);
int CheckField0NonZero(int* obj);
signed char GetSearchStructCurrentArrEntry(struct SearchStruct0202c1a4* obj);
void* GetField0x3f8Address(GameState* battleStruct);
extern "C" void* func_02012fe4(void* unused);
void* GetData02100044(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Vec3i021d1a18 { int x, y, z; };

struct Bits021d1a18 {
    short low14 : 14;
    short hi2 : 2;
};

struct SubEvt021d1a18 {
    short flag;
    struct Bits021d1a18 bits;
    short vx;
    short vy;
    short vz;
    unsigned short w;
    unsigned char d;
};

struct LocalEvt021d1a18 {
    unsigned char tag;
    unsigned char pad0[3];
    SubEvt021d1a18 sub;
};

// USA: func_ov017_021d1a18  (semantic: EnqueueVec3EventBits14_021d1a18)
extern "C" ARM void func_ov017_021d1a18(int a, short b, short c, unsigned char d) {
    if (!CheckField0NonZero(func_0202ae18())) return;
    if (GetSearchStructCurrentArrEntry((struct SearchStruct0202c1a4*)func_0202ae18()) != 0) return;

    ((int)func_ov017_0218b5b0());
    GameState* bs = GameState::GetInstance();
    void* base = func_02012fe4(GetField0x3f8Address(bs));
    void* p = GetData02100044();

    struct LocalEvt021d1a18 buf;
    buf.tag = 0xb2;
    buf.sub.flag = (a == 0) ? 1 : a;
    buf.sub.bits.low14 = b;
    buf.sub.bits.hi2 = c;

    struct Vec3i021d1a18 vec = *(struct Vec3i021d1a18*)((char*)base + RegionOffset2774);
    buf.sub.vx = (short)(vec.x >> 7);
    buf.sub.vy = (short)(vec.y >> 7);
    buf.sub.vz = (short)(vec.z >> 7);

    buf.sub.w = *(int*)((char*)base + RegionOffset2780);
    buf.sub.d = d;
    func_0205e330(p, &buf, 0);
}
