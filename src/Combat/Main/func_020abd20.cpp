#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "System/Matrix.h"

extern char data_0211e33c[];

extern "C" void* func_02012fe4();
extern "C" int func_020aaf84(void* buf, int a, int b, int c);
extern "C" void* func_0205ec34();
extern "C" void func_020a9a50(void* ctx, char* dst, int flag);
extern "C" void _Z32CopyBlobIntoBattleStruct020a9ba4Pv(void* blob);
void LoadBattleRegion0x5cdc(unsigned char* p);
extern "C" void func_020a9b2c(void* p);
void ClearAllTreasureMapUnknownBits(void* p);
void* GetField0x74deForValidIndex(char* p, unsigned int index);

struct StateBits5ccc_11544;
void SetFlag0x5cccBit0(struct StateBits5ccc_11544* p);

// USA: func_020abd20
extern "C" ARM int func_020abd20() {
    GameState* gs = GameState::GetInstance();
    func_ov017_0218b5b0();
    unsigned char* zone = (unsigned char*)func_02012fe4();
    ((unsigned char*)gs)[0x5cc8] = 0;
    char buf[8];
    if (func_020aaf84(buf, 0, 0, 1) == 0) {
        SetFlag0x5cccBit0((struct StateBits5ccc_11544*)gs);
        return 0;
    }
    {
        BackgroundLoader::AddLockGlobal();
        BackgroundLoader::FreeAllocationsGlobal();
        unsigned char* base = (unsigned char*)&data_0211e33c[0] + 0x28000;
        func_020a9a50(base + 0x2cac, (char*)func_0205ec34(), 1);
        memcpy(((unsigned char*)GameState::GetInstance()) + 0x5e6c, base + 0x6c3c, 0x110);
        _Z32CopyBlobIntoBattleStruct020a9ba4Pv(base + 0x5a04);
        LoadBattleRegion0x5cdc(base + 0x33c0);
        func_020a9b2c(base + 0x3ec4);
        unsigned char* sub = base + 4;
        unsigned char* s = sub;
        s += 0x2c00;
        *(unsigned short*)((zone + 0x2700) + 0x86) = *(unsigned short*)(s + 0x5c);
        *(unsigned short*)((zone + 0x2700) + 0x84) = *(short*)(s + 0x5e);
        ((Vector3i*)(zone + 0x2774))->operator=(*((const Vector3i*)((sub + 0xc60) + 0x2000)));
        unsigned char* z2000 = zone;
        z2000 += 0x2000;
        unsigned char* q = sub;
        q += 0x2000;
        *(unsigned int*)(z2000 + 0x780) = *(unsigned int*)(q + 0xc6c);
        *(unsigned char*)(z2000 + 0x788) = *(unsigned char*)(q + 0xc74);
        *(unsigned int*)(z2000 + 0x794) = *(unsigned int*)(q + 0xc70);
        *(unsigned short*)((zone + 0x2700) + 0xb4) = *(unsigned char*)(q + 0xc75);
        *(unsigned short*)((zone + 0x2700) + 0xb6) = *(unsigned char*)(q + 0xc76);
        unsigned char* z1840 = zone + 0x1840;
        *(unsigned int*)(z1840 + 0xb48) = *(unsigned int*)(q + 0xc80);
        *(unsigned int*)(z1840 + 0xb4c) = *(unsigned int*)(q + 0xc84);
        ClearAllTreasureMapUnknownBits(gs);
        memcpy(GetField0x74deForValidIndex((char*)gs, 0), base + 0x2c54, 8);
        BackgroundLoader::RemoveLockGlobal();
        return 1;
    }
}
