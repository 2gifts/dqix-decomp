#include <globaldefs.h>

#if defined(jpn)
enum { kOffsetcda = 0xa7a };
#else
enum { kOffsetcda = 0xcda };
#endif

#include "GameState/GameState.h"

struct Variant02030b0c;
extern "C" int _ZNK6Script9Parameter5ToIntEv(Variant02030b0c*);

struct Entry02108ff4 {
    unsigned short a;
    unsigned char b;
    unsigned char c;
};
extern Entry02108ff4 data_02108ff4[];

// USA: func_0208e2c0  (semantic: StoreVariantTriple0208e2c0)
extern "C" ARM int func_0208e2c0(char* v) {
    unsigned char* battleField = (unsigned char*)GameState::GetInstance();
    Entry02108ff4* table = data_02108ff4;
    int idRaw = _ZNK6Script9Parameter5ToIntEv((Variant02030b0c*)v);
    v += 8;
    unsigned char id = (unsigned char)idRaw;
    battleField = battleField + 0x5000;
    for (int i = 0; i < 8; i++) {
        unsigned short aVal = (unsigned short)_ZNK6Script9Parameter5ToIntEv((Variant02030b0c*)v);
        unsigned char bVal = (unsigned char)_ZNK6Script9Parameter5ToIntEv((Variant02030b0c*)(v + 8));
        char* arg3 = v + 0x10;
        v += 0x18;
        unsigned char cVal = (unsigned char)_ZNK6Script9Parameter5ToIntEv((Variant02030b0c*)arg3);
        if (i == battleField[kOffsetcda]) {
            table[id].a = aVal;
            table[id].b = bVal;
            table[id].c = cVal;
            return 1;
        }
    }
    return 0;
}
