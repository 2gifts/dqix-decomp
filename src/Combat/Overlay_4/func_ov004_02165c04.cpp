#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, int);
int ScaleStatsIfType12_021f6f10(void* self);
struct Struct0200fb08;
unsigned char NormalizeField5_0200fb08(struct Struct0200fb08* obj);
void* GetFieldPtrAt_021f79e4_021f79e4(void* obj);

struct Obj0204b988;
void DispatchIndexedEntry0204b988(struct Obj0204b988*, unsigned int, int, int, unsigned short);

struct Obj0204b8d0;
void DispatchEntry0204b8d0(struct Obj0204b8d0*, unsigned int, int, int, short, short, short, short, unsigned short);

struct List0204b0e8;
void FlushAndDispatchList0204b0e8(struct List0204b0e8*, void*);

struct Obj021fb25c;
void SetShorts_021fb25c(Obj021fb25c*, unsigned int, unsigned int, unsigned int, int);

// USA: func_ov004_02165c04  (semantic: DispatchByNormalizedKindWithExtra_02165c04)
extern "C" ARM int func_ov004_02165c04(void* a) {
    unsigned char v = NormalizeField5_0200fb08((struct Struct0200fb08*)GameState::GetInstance());
    unsigned short extra = 0x4a;
    unsigned int kind = 0;
    switch (v) {
    case 2: kind = 1; extra = 0x5a; break;
    case 4: kind = 2; extra = 0x80; break;
    case 3: kind = 3; break;
    case 5: kind = 4; extra = 0x78; break;
    }

    void* node = func_ov023_021f6880(func_ov011_021849c8(a), 3);
    if (!node) return 0;
    if (ScaleStatsIfType12_021f6f10(node) != 2) return 0;

    *(unsigned char*)((char*)node + 0xc) |= 1;
    void* list = GetFieldPtrAt_021f79e4_021f79e4(node);
    DispatchIndexedEntry0204b988((struct Obj0204b988*)list, 0, 0, 0, 0xffff);
    if (kind != 0) {
        DispatchEntry0204b8d0((struct Obj0204b8d0*)list, kind, 0, 0, 0x16, 2, 9, 3, 0xffff);
    }
    FlushAndDispatchList0204b0e8((struct List0204b0e8*)list, 0);

    void* node2 = func_ov023_021f6880(func_ov011_021849c8(a), 0x1f8);
    if (node2 && ScaleStatsIfType12_021f6f10(node2) == 1) {
        if (!node2) return 0;
        SetShorts_021fb25c((struct Obj021fb25c*)node2, 0, 0, extra, 0x11);
    }
    return 0;
}
