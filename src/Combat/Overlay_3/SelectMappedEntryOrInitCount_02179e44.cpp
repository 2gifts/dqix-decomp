#include <globaldefs.h>

#if defined(jpn)
enum { kOffset1010 = 0xf8c };
enum { kOffset1014 = 0xf90 };
enum { kOffset1016 = 0xf92 };
enum { kOffset101c = 0xf98 };
enum { kOffset1030 = 0xfac };
enum { kOffset1043 = 0xfbf };
enum { kOffset89c = 0x818 };
#else
enum { kOffset1010 = 0x1010 };
enum { kOffset1014 = 0x1014 };
enum { kOffset1016 = 0x1016 };
enum { kOffset101c = 0x101c };
enum { kOffset1030 = 0x1030 };
enum { kOffset1043 = 0x1043 };
enum { kOffset89c = 0x89c };
#endif

#include "GameState/GameState.h"

short FindMappedMemberId02080468(void* obj, int id);
struct S_a0b8c;
int CountNonZeroValues020a0b8c(struct S_a0b8c* p);

// JPN: func_ov003_02178c80
// USA: func_ov003_02179e44  (semantic: SelectMappedEntryOrInitCount_02179e44)
extern "C" ARM int func_ov003_02179e44(char* obj) {
    GameState* battle = GameState::GetInstance();
    void* ptr = GetPtrField0x2a04(battle);
    int state = *(int*)(obj + kOffset1030);
    void* field89c = *(void**)(obj + kOffset89c);
    int type;
    switch (state) {
        case 1: type = 0x11; break;
        case 2: type = 0x12; break;
        case 3: type = 0x13; break;
        case 4: type = 0x14; break;
    }

    *(char*)(obj + kOffset1043) = -1;
    short idx = FindMappedMemberId02080468(field89c, type);
    short v10 = *(short*)(obj + kOffset1010);
    int state2 = *(int*)(obj + kOffset1030);
    short diff = (short)(v10 - idx);
    if (state2 > diff) {
        int val = *(int*)(obj + kOffset101c + diff * 4);
        *(char*)(obj + kOffset1043) = (char)val;
        *(short*)(obj + kOffset1014) = 0;
        *(short*)(obj + kOffset1016) = 1;
        return 1;
    } else {
        int count = CountNonZeroValues020a0b8c((struct S_a0b8c*)ptr);
        int n = (count + 7) / 8;
        *(short*)(obj + kOffset1014) = 0;
        *(short*)(obj + kOffset1016) = n;
        short v16 = *(short*)(obj + kOffset1016);
        if (v16 == 0) {
            v16 = 1;
            *(short*)(obj + kOffset1016) = v16;
        }
        return v16;
    }
}
