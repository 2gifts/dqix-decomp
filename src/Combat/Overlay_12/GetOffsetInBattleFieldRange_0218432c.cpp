#include <globaldefs.h>

#if defined(jpn)
#define func_ov012_0218432c func_ov012_021853a0
#endif
#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif

#include "GameState/GameState.h"

#if defined(jpn)
#define data_ov012_0218afaa data_ov012_0218bd16
#define data_ov012_0218afac data_ov012_0218bd18
#endif
struct FieldValueB0218432c {
    unsigned int unk0 : 9;
    signed int value : 10;
    unsigned int unk1 : 13;
};

struct Entry0218432c { short value; short unused; };

extern struct Entry0218432c data_ov012_0218afaa[];
extern struct Entry0218432c data_ov012_0218afac[];

// USA: func_ov012_0218432c  (semantic: GetOffsetInBattleFieldRange_0218432c)
extern "C" ARM int func_ov012_0218432c(int index) {
    char* base = (char*)GameState::GetInstance() + R(0x543c, 0x569c);
    int fieldvalue = ((struct FieldValueB0218432c*)(base + 4))->value;
    short a1 = data_ov012_0218afaa[index].value;
    if (a1 <= fieldvalue) {
        short a2 = data_ov012_0218afac[index].value;
        if (fieldvalue < a2) return fieldvalue - a1;
    }
    return 0;
}
