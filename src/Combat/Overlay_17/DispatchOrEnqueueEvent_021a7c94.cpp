// JPN: func_ov017_021a8624
#if defined(jpn)
enum { RegionOffset998 = 0x868, RegionOffset6fc = 0x4ec, RegionOffsetb9c = 0x97c };
#else
enum { RegionOffset998 = 0x998, RegionOffset6fc = 0x6fc, RegionOffsetb9c = 0xb9c };
#endif

#include <globaldefs.h>
#include "GameState/GameState.h"

struct TailNode020469b4 { char unk0[2]; unsigned char inList; char unk3; TailNode020469b4* next; };
struct TailList020469b4 { TailNode020469b4* head; TailNode020469b4* tail; };
struct Obj021a7d78 { char pad[0x30]; short f30; short pad30; int f34; };

int GetGlobalField0x1c020421a0(void);
int CheckSubstructByte0x7cPositive(signed char* obj);
int IsField0Null(void** obj);
int GetField0x3acValue(GameState* battleStruct);
void AppendNodeToTail(struct TailList020469b4* list, struct TailNode020469b4* node);
void EnqueueEventTag170_021d0198(int a, int b, int c, int d);
void InitObj_021a7d78(struct Obj021a7d78* p);
extern "C" int func_020dc920(int, int, int, int);

// USA: func_ov017_021a7c94  (semantic: DispatchOrEnqueueEvent_021a7c94)
extern "C" ARM void func_ov017_021a7c94(unsigned char* obj, int id, int arg2) {
    GameState* bs = GameState::GetInstance();
    int g = GetGlobalField0x1c020421a0();
    GameObject* combatant = bs->GetUnknownGameObject();
    int ok = 1;
    if (*(int*)(g + RegionOffset998) != 0) ok = 0;
    if (CheckSubstructByte0x7cPositive((signed char*)combatant) != 0) ok = 0;
    if (IsField0Null((void**)*(struct TailList020469b4**)(obj + 0x3000 + RegionOffset6fc)) == 0) ok = 0;
    if (func_020dc920(id & 0xff, 1, 1, 0) == 0) ok = 0;
    int val = GetField0x3acValue(bs);
    if (ok) {
        InitObj_021a7d78(*(struct Obj021a7d78**)(obj + 0x3000 + RegionOffsetb9c));
        (*(struct Obj021a7d78**)(obj + 0x3000 + RegionOffsetb9c))->f34 = id;
        (*(struct Obj021a7d78**)(obj + 0x3000 + RegionOffsetb9c))->f30 = (short)arg2;
        AppendNodeToTail(*(struct TailList020469b4**)(obj + 0x3000 + RegionOffset6fc), (struct TailNode020469b4*)*(struct Obj021a7d78**)(obj + 0x3000 + RegionOffsetb9c));
        EnqueueEventTag170_021d0198(4, id, val, arg2);
    } else {
        EnqueueEventTag170_021d0198(5, id, val, arg2);
    }
}
