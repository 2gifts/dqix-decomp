#include <globaldefs.h>
#if defined(jpn)
enum { kEntryOffset = 0x5a7c };
#else
enum { kEntryOffset = 0x5cdc };
#endif

#include "GameState/GameState.h"

struct BitEntry0208ec04 {
    unsigned int low9 : 9;
    unsigned int mid8 : 8;
    unsigned int id8 : 8;
    unsigned int type4 : 4;
    unsigned int unused2 : 2;
    unsigned int flag : 1;
};

// USA: func_0208ec04  (semantic: RecalcLow9FieldFromType0208ec04)
extern "C" ARM void func_0208ec04(void) {
    char* base = (char*)GameState::GetInstance();
    struct BitEntry0208ec04* e = (struct BitEntry0208ec04*)(base + kEntryOffset);
    int i;
    for (i = 0; i < 0x64; i++, e++) {
        if (e->flag && e->id8 != 0) {
            e->id8 = 0;
            e->low9 = e->type4 * 3;
        }
    }
}
