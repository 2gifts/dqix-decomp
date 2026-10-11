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
struct List021600f8 { unsigned short kind; char p[7]; unsigned char count; };
struct Entry { char p[0xe]; short id; char q[0xd]; unsigned char flag0:1, extra:1, rest:6; };
Entry* GetNodeAtIndex021600f8(List021600f8*,int);
// USA: func_ov000_0215b278
// JPN: func_ov000_0215b278
extern "C" ARM void func_ov000_0215b278(unsigned char* self,List021600f8* list) {
 if(list->kind!=0x20b) return;
 for(int i=0;i<list->count;i++) {
  Entry* entry=GetNodeAtIndex021600f8(list,i);
  if(!entry) continue;
  int id=entry->id;
  GameState* gs=GameState::GetInstance();
  GameObject* unit=gs->GetCombatantByIndex(id);
  if(!unit) continue;
  Work* work=(Work*)GetWorkArrayEntry0215e9d8(self);
  if(!work) continue; InitStruct02160030(work);
  Node* copy=(Node*)GetTableEntry0x8e00Bound0x48(self);
  if(!copy) continue; memset(copy,0,0x30);copy->sentinel=-1;copy->tail=0;
  State* state=(State*)GetTableEntry0x8e01Bound0x88(self);
  if(!state) continue;ResetStruct02157cdc(state);
  work->kind=0x3b1;
  copy->id=entry->id;copy->field22=unit->detail->rawFirst;copy->field24=unit->detail->rawSecond;
  memcpy(state,entry,0x24);
  AppendNode02160068((Obj02160068*)work,(Node02160068*)copy);
  AppendNode021600cc((Obj021600cc*)work,(Node021600cc*)state);
  work->flags|=4;
  (*(int*)(self+0x8e24))++; self[0x8e00]++;self[0x8e01]++;
  if(entry->extra) {
   Work* work2=(Work*)GetWorkArrayEntry0215e9d8(self);
   if(!work2) continue;InitStruct02160030(work2);
   copy=(Node*)GetTableEntry0x8e00Bound0x48(self);
   if(!copy) continue;memset(copy,0,0x30);copy->sentinel=-1;copy->tail=0;
   State* state2=(State*)GetTableEntry0x8e01Bound0x88(self);
   if(!state2) continue;ResetStruct02157cdc(state2);
   Out* out=func_ov000_0215e958(self);
   if(!out)continue;memset(out,0,0x20);out->tail=0;
   work2->kind=0x39c;
   copy->id=entry->id;copy->field22=unit->detail->rawFirst;copy->field24=unit->detail->rawSecond;
   work2->flags|=4;
   {int second=unit->Second();int first=unit->First();
   _Z22PopulateEntry_0215ccbciP17OutStruct0215ccbcP10GameObjectsssiih(self,out,unit,0,first,second,0,0,0);}
   AddEntryAndIncrementCount0215a88c(self,out,0x35);
   state2->id=entry->id;state2->flag=1;
   AppendToChainAndIncCount0215ffc4(state2,out,0);
   self[0x8e02]++;
   AppendNode02160068((Obj02160068*)work2,(Node02160068*)copy);
   AppendNode021600cc((Obj021600cc*)work2,(Node021600cc*)state2);
   (*(int*)(self+0x8e24))++; self[0x8e00]++;self[0x8e01]++;self[0x8e02]++;
  }
 }
}
