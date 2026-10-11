#include <globaldefs.h>
#include "std_library_functions.h"

struct GameObject { char p[0x138]; short* details; int GetFirst() const { return details[0]; } int GetSecond() const { return details[1]; } };
class GameState { public: static GameState* GetInstance(); GameObject* GetCombatantByIndex(int); };
struct List02160094 { void* first; void* last; unsigned char count; };
struct Node0215bf5c {
    void* field0; void* field4; void* chain8; void* fieldC; void* chain10;
    char p0[8]; short sentinel; char p1[2]; unsigned short id; unsigned short field22,field24,field26;
    unsigned char count28,flag29,count2a; char p2[5]; int field30;
};
struct Flags0215bf5c { unsigned long long flags; };
struct Work0215bf5c { unsigned short kind; char p[9]; unsigned char flags; };
struct State0215bf5c { char p0[0xe]; unsigned short id; char p1[7]; unsigned char flag; };
struct Out0215bf5c { char p0[0x20]; int field20; };
Node0215bf5c* GetNodeAtIndex02160094(List02160094*,int);
Flags0215bf5c* GetNodeAtIndex0215feb4(char*,int,int);
void* GetWorkArrayEntry0215e9d8(void*);
void InitStruct02160030(void*);
void* GetTableEntry0x8e00Bound0x48(void*);
void* GetTableEntry0x8e01Bound0x88(void*);
void ResetStruct02157cdc(void*);
void AppendToChainAndIncCount0215fe84(void*,void*,int);
void AppendToChainAndIncCount0215ffc4(void*,void*,int);
struct Obj02160068; struct Node02160068;
void AppendNode02160068(Obj02160068*,Node02160068*);
struct Obj021600cc; struct Node021600cc;
void AppendNode021600cc(Obj021600cc*,Node021600cc*);
extern "C" {
GameObject* _ZN9GameState19GetCombatantByIndexEi(GameState*,int);
int func_ov000_0215fd90(Flags0215bf5c*,int);
Out0215bf5c* func_ov000_0215e958(void*);
void _Z22PopulateEntry_0215ccbciP17OutStruct0215ccbcP10GameObjectsssiih(void*,Out0215bf5c*,GameObject*,short,short,short,int,int,unsigned char);
}

struct Root0215bf5c { char p[0x8e00]; unsigned char count0,count1,count2; char q[0x21]; int workCount; };

static inline GameObject* ResolveUnit0215bf5c(int id) { return GameState::GetInstance()->GetCombatantByIndex(id); }
static inline int GetCount0215bf5c(Node0215bf5c* node) { int count=node->count28;return count; }

// USA: func_ov000_0215bf5c
// JPN: func_ov000_0215bf5c
extern "C" ARM void func_ov000_0215bf5c(Root0215bf5c* self,List02160094* list) {
    for (int i=0;i<list->count;i++) {
        Node0215bf5c* node=GetNodeAtIndex02160094(list,i);
        if (!node) continue;
        Flags0215bf5c* flags;
        bool special;bool moveExtra;
        Work0215bf5c* work;
        State0215bf5c* state;
        Out0215bf5c* out;
        int id=(short)node->id;
        GameState* gs=GameState::GetInstance();
        GameObject* unit=gs->GetCombatantByIndex(id);
        if (!unit) continue;
        int count=GetCount0215bf5c(node);
        flags=GetNodeAtIndex0215feb4((char*)node,i,2);
        special=false; moveExtra=0;
        if (flags && (func_ov000_0215fd90(flags,0x22) || func_ov000_0215fd90(flags,0x25))) special=true;
        if (!special && !node->flag29) { moveExtra=1;count+=node->count2a; }
        if (count<=0) continue;
        work=(Work0215bf5c*)GetWorkArrayEntry0215e9d8(self);
        if (!work) continue;
        InitStruct02160030(work);
        Node0215bf5c* copy=(Node0215bf5c*)GetTableEntry0x8e00Bound0x48(self);
        if (!copy) continue;
        memset(copy,0,0x30);copy->sentinel=-1;copy->field30=0;
        state=(State0215bf5c*)GetTableEntry0x8e01Bound0x88(self);
        if (!state) continue;
        ResetStruct02157cdc(state);
        out=func_ov000_0215e958(self);
        if (!out) continue;
        memset(out,0,0x20);out->field20=0;
        work->kind=0x3ae;
        int moved=0;
        if (flags && ((flags->flags&2ULL) || (flags->flags&4ULL) || (flags->flags&0x10ULL) || (flags->flags&0x2000ULL))) {
            AppendToChainAndIncCount0215fe84(copy,flags,2);
            node->chain8=0;node->count28=0;moved=1;
        }
        if (!moved && !moveExtra) continue;
        if (moveExtra) {
            copy->chain10=node->chain10;copy->count2a=node->count2a;
            node->chain10=0;node->count2a=0;
        }
        copy->id=node->id;copy->field24=node->field24;
        int second=unit->GetSecond();
        int first=unit->GetFirst();
        _Z22PopulateEntry_0215ccbciP17OutStruct0215ccbcP10GameObjectsssiih(self,out,unit,0,first,second,0,0,0);
        state->id=node->id;state->flag=1;
        AppendToChainAndIncCount0215ffc4(state,out,0);
        work->flags|=4;
        AppendNode02160068((Obj02160068*)work,(Node02160068*)copy);
        AppendNode021600cc((Obj021600cc*)work,(Node021600cc*)state);
        self->workCount++;self->count0++;self->count1++;self->count2++;
    }
}
