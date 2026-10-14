#include <globaldefs.h>
#include "Resource/Script.h"

struct Variant02030b0c { int tag; int u; };

struct GetRowByIndexRow;
GetRowByIndexRow* GetRowByIndex(GetRowByIndexRow* base, int i);

struct StoreWordToRowArrayRow;
void StoreWordToRowArray(StoreWordToRowArrayRow* base, int i, int j, unsigned int* src);

extern void* data_02109bac;

// USA: func_0209ae10  (semantic: PushCombatValueToActiveRow_0209ae10)
extern "C" ARM int func_0209ae10(struct Variant02030b0c* arg0) {
    char* p = (char*)data_02109bac;
    if (*(int*)(p + 0x8) == 0) return 1;

    char* q = *(char**)(p + 0x0);
    int i = *(int*)(q + 0x1c8);
    int j = *(int*)(q + 0x1d0);

    unsigned int v = (unsigned int)((Script::Parameter*)arg0)->ToInt();

    q = *(char**)((char*)data_02109bac + 0x0);
    StoreWordToRowArray((StoreWordToRowArrayRow*)q, i, j, &v);

    *(int*)(*(char**)(char*)data_02109bac + 0x1d0) = j + 1;

    q = *(char**)((char*)data_02109bac + 0x0);
    struct GetRowByIndexRow* row = GetRowByIndex((GetRowByIndexRow*)q, i);
    if (row != 0) {
        unsigned char* cnt = (unsigned char*)row + 3;
        *cnt = *cnt + 1;
    }
    return 1;
}
