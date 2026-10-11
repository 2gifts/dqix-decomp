#include <globaldefs.h>
#include "std_library_functions.h"
union Detail { struct { short first,second; }; struct { unsigned short rawFirst,rawSecond; }; };
struct GameObject { char p[0x138]; Detail* detail; int First() const { return detail->first; } int Second() const { return detail->second; } };
class GameState { public: static GameState* GetInstance(); GameObject* GetCombatantByIndex(int); };
struct List02160094 { void* first; void* last; unsigned char count; };
struct Node { void* chains[6]; char p0[4]; short sentinel,field1e; unsigned short id,field22,field24; unsigned char counts[6],pad2c,trigger; char p1[2]; int tail; };
struct Work { unsigned short kind; char p[9]; unsigned char flags; };
struct State { char p0[0xe]; unsigned short id; char p1[7]; unsigned char flag; };
struct Out { char p[0x20]; int tail; };
Node* GetNodeAtIndex02160094(List02160094*,int);
void* GetWorkArrayEntry0215e9d8(void*);
void InitStruct02160030(void*);
void* GetTableEntry0x8e00Bound0x48(void*);
void* GetTableEntry0x8e01Bound0x88(void*);
void ResetStruct02157cdc(void*);
void AppendToChainAndIncCount0215ffc4(void*,void*,int);
void AddEntryAndIncrementCount0215a88c(void*,void*,int);
struct Obj02160068; struct Node02160068; struct Obj021600cc; struct Node021600cc;
void AppendNode02160068(Obj02160068*,Node02160068*);
void AppendNode021600cc(Obj021600cc*,Node021600cc*);
extern "C" { Out* func_ov000_0215e958(void*); void _Z22PopulateEntry_0215ccbciP17OutStruct0215ccbcP10GameObjectsssiih(void*,Out*,GameObject*,short,short,short,int,int,unsigned char); }
inline int IsParty(unsigned short n) { int result=0; if(n<=3) result=1; return result; }
// USA: func_ov000_0215bbbc
// JPN: func_ov000_0215bbbc
extern "C" ARM void func_ov000_0215bbbc(unsigned char* self,List02160094* list) {
    for(int i=0;i<list->count;i++) {
        Node* node=GetNodeAtIndex02160094(list,i);
        if(!node) continue;
        Work* work; Node* copy; State* state; Out* out;
        int id=(short)node->id;
        GameState* gs=GameState::GetInstance();
        GameObject* unit=gs->GetCombatantByIndex(id);
        if(!unit) continue;
        int sum=0;
        for(int j=0;j<6;j++) if(j!=1) sum+=node->counts[j];
        if(sum<=0) continue;
#define ALLOCATE() \
        work=(Work*)GetWorkArrayEntry0215e9d8(self); \
        if(!work) continue; InitStruct02160030(work); \
        copy=(Node*)GetTableEntry0x8e00Bound0x48(self); \
        if(!copy) continue; memset(copy,0,0x30); copy->sentinel=-1; copy->tail=0; \
        state=(State*)GetTableEntry0x8e01Bound0x88(self); \
        if(!state) continue; ResetStruct02157cdc(state); \
        out=func_ov000_0215e958(self); \
        if(!out) continue; memset(out,0,0x20); out->tail=0;
        ALLOCATE()
        work->kind=0x3ae;
        memcpy(copy,node,0x34);
        for(int j=0;j<6;j++) if(j!=1) { node->chains[j]=0; node->counts[j]=0; }
        node->sentinel=-1; node->field1e=0; node->trigger=0;
        copy->chains[1]=0; copy->counts[1]=0;
        { int second=unit->Second(); int first=unit->First();
        _Z22PopulateEntry_0215ccbciP17OutStruct0215ccbcP10GameObjectsssiih(self,out,unit,0,first,second,0,0,0); }
        state->id=node->id; state->flag=1;
        AppendToChainAndIncCount0215ffc4(state,out,0);
        work->flags|=4;
        AppendNode02160068((Obj02160068*)work,(Node02160068*)copy);
        AppendNode021600cc((Obj021600cc*)work,(Node021600cc*)state);
        (*(int*)(self+0x8e24))++; self[0x8e00]++; self[0x8e01]++; self[0x8e02]++;
        if(copy->trigger==1) {
            ALLOCATE()
             int party=0; if(node->id<=3) party=1; if(party) work->kind=0x39c; else work->kind=0x39d;
            copy->id=node->id;
            copy->field22=unit->detail->rawFirst; copy->field24=unit->detail->rawSecond;
            work->flags|=4;
            { int second=unit->Second(); int first=unit->First();
        _Z22PopulateEntry_0215ccbciP17OutStruct0215ccbcP10GameObjectsssiih(self,out,unit,0,first,second,0,0,0); }
            AddEntryAndIncrementCount0215a88c(self,out,0x35);
            state->id=node->id; state->flag=1;
            AppendToChainAndIncCount0215ffc4(state,out,0);
            self[0x8e02]++;
            AppendNode02160068((Obj02160068*)work,(Node02160068*)copy);
            AppendNode021600cc((Obj021600cc*)work,(Node021600cc*)state);
            (*(int*)(self+0x8e24))++; self[0x8e00]++; self[0x8e01]++; self[0x8e02]++;
            copy->trigger=0;
        }
#undef ALLOCATE
    }
}
