#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
enum { kRegionValue4A4_2CC = 0x2cc };
enum { kRegionValue400_200 = 0x200 };
enum { kRegionValue82_AA = 0xaa };
enum { kRegionValue4A3_2CB = 0x2cb };
enum { kRegionValue84_AC = 0xac };
enum { kRegionValue86_AE = 0xae };
enum { kRegionValue80_A8 = 0xa8 };
enum { kRegionValue464_28C = 0x28c };
#else
enum { kRegionValue4A4_2CC = 0x4a4 };
enum { kRegionValue400_200 = 0x400 };
enum { kRegionValue82_AA = 0x82 };
enum { kRegionValue4A3_2CB = 0x4a3 };
enum { kRegionValue84_AC = 0x84 };
enum { kRegionValue86_AE = 0x86 };
enum { kRegionValue80_A8 = 0x80 };
enum { kRegionValue464_28C = 0x464 };
#endif


int GetFieldAt0x150(unsigned char* obj);
void AddPositiveField150EntriesToMap_021b6bb8(int combatantId);
extern "C" int func_ov017_021b6d60(int a, void* buf);
extern "C" void func_02086778(void* map, void* buf, int c, int d);

// USA: func_ov003_02163e4c  (semantic: AdvanceTargetSearchStep_02163e4c)
// JPN: func_ov003_02163e64
extern "C" ARM void func_ov003_02163e4c(char* obj) {
    unsigned char step = obj[kRegionValue4A4_2CC];
    if (step == 0) {
        char buf[0x23c];
        GameState* bs = GameState::GetInstance();
        void* map = GetPtrField0x2a04(bs);
        short id = *(short*)(obj + kRegionValue400_200 + kRegionValue82_AA);
        GameObject* c = bs->GetPartyMemberByIndex(id);
        if (c == NULL) {
            obj[kRegionValue4A3_2CB] = 0x10;
            return;
        }
        unsigned char* field150 = (unsigned char*)GetFieldAt0x150((unsigned char*)c);
        if (field150 == NULL) {
            obj[kRegionValue4A3_2CB] = 0x10;
            return;
        }
        *(short*)(obj + kRegionValue400_200 + kRegionValue84_AC) = 0xd;
        short v54 = *(short*)(field150 + 0x400 + 0x54);
        if (v54 > 0) {
            *(short*)(obj + kRegionValue400_200 + kRegionValue86_AE) = 0xe;
        }
        AddPositiveField150EntriesToMap_021b6bb8(*(short*)(obj + kRegionValue400_200 + kRegionValue82_AA));
        func_ov017_021b6d60(*(short*)(obj + kRegionValue400_200 + kRegionValue82_AA), buf);
        func_02086778(map, buf, 0, 0);
        short sv = (buf[0] << 26) >> 26;
        *(short*)(obj + kRegionValue400_200 + kRegionValue80_A8) = sv;
        obj[kRegionValue4A4_2CC] = (unsigned char)obj[kRegionValue4A4_2CC] + 1;
        *(int*)(obj + kRegionValue464_28C) |= 8;
        return;
    }
    if (step != 1) return;
    *(short*)(obj + kRegionValue400_200 + kRegionValue84_AC) = 2;
    *(int*)(obj + kRegionValue464_28C) |= 8;
    obj[kRegionValue4A3_2CB] = 1;
    obj[kRegionValue4A4_2CC] = 0;
}
