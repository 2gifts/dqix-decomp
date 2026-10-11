#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

struct PackedPair_021de274 {
    unsigned int a : 10;
    unsigned int b : 10;
    unsigned int c : 10;
    unsigned int hi : 2;
};

struct Range_021de274 {
    char pad[0x20];
    struct PackedPair_021de274 f20;
    struct PackedPair_021de274 f24;
};

struct Flag_021de274 { unsigned char pad : 7; unsigned char flag : 1; };

struct Nested021de274 {char pad[0x20]; short id;};
struct Source021de274 {char pad[0x10];Nested021de274* info;};
struct Obj_021de274 {char pad[4];Source021de274* source;void* chain;void* action;void* world;char pad14[0x61];unsigned char flag;};

struct OutStruct0215ccbc;

extern "C" unsigned short _Z31SelectByIndexRange0to3_021da644iii(int idx, int a, int b);
extern "C" struct OutStruct0215ccbc* func_ov000_0215e958(void* world);
extern "C" void _Z33AddEntryAndIncrementCount0215a88cPvS_i(void* world, void* entry, int msg);
extern "C" short _Z20ApplyMPDelta0215a1d4PviiPs(void* world, int id, int delta, short* outApplied);
extern "C" void func_ov000_02159eac(void* world, unsigned long long* bits, int bit);
extern "C" short _Z17ConsumeMP0215a124Pvii(void* world, int id, int amount);
extern "C" void _Z22PopulateEntry_0215ccbciP17OutStruct0215ccbcP10GameObjectsssiih(void* world, struct OutStruct0215ccbc* out, GameObject* combatant,
                            short valC, short valA, short valB, unsigned long long words, unsigned char byteE);

static inline int GetCurrentHP(GameObject* c) {
    int hp = c->currentStats_->primaryStats.currHP;
    return hp;
}

static inline unsigned short GetMaxMP(GameObject* c) {
    unsigned short maxMP = c->currentStats_->primaryStats.maxMP;
    return maxMP;
}

extern "C" void _Z32AppendToChainAndIncCount0215fe84PvS_i(void*,void*,int);
extern "C" void func_ov024_021e8bf0(Obj_021de274*,void*,unsigned short*);
static inline int IsParty(int id){return id>=0 && id<=3;}
// USA: func_ov024_021de274
extern "C" ARM OutStruct0215ccbc* func_ov024_021de274(Obj_021de274* obj,short sourceID,int id,Range_021de274* params,int amount,int unused,unsigned char enabled){
 GameObject* source;
 GameObject* target;
 int active;
 int original=amount;
 source=GetCombatantByID((int)obj->world,obj->source->info->id);
 if(!source)return 0;
 target=GetCombatantByID((int)obj->world,id);
 if(!target)return 0;
 active=enabled;
 int current=target->currentStats_->primaryStats.currMP;
 if(current<amount)amount=current;
 unsigned long long effects=0;
 unsigned long long sourceEffects=0;
 unsigned short selection=0;
 if(active && amount>0){
  selection=_Z31SelectByIndexRange0to3_021da644iii(id,params->f20.c,params->f24.a);
  func_ov000_02159eac(obj->world,&effects,1);
  func_ov000_02159eac(obj->world,&effects,0x2a);
 }else{
#if defined(jpn)
  if(original<=0)selection=0x1b;
  else selection=0x1f;
#else
  if(original>0)selection=0x1f;
  else selection=_Z31SelectByIndexRange0to3_021da644iii(id,0x26d,0x1b);
#endif
  amount=0;
  obj->flag=0;
 }
 short mp=target->currentStats_->primaryStats.currMP;
 int consume=1;
 if(!IsParty(id) && target->currentStats_->primaryStats.currMP>=0xff)consume=0;
 if(consume)mp=_Z17ConsumeMP0215a124Pvii(obj->world,id,amount);
 if((unsigned short)obj->source->info->id!=id){
  short applied=0;
  short sourceMP=_Z20ApplyMPDelta0215a1d4PviiPs(obj->world,sourceID,amount,&applied);
  if(active && amount>0){
   func_ov000_02159eac(obj->world,&sourceEffects,0x22);
   OutStruct0215ccbc* entry=func_ov000_0215e958(obj->world);
   if(!entry)return 0;
   _Z33AddEntryAndIncrementCount0215a88cPvS_i(obj->world,entry,0x26c);
   _Z22PopulateEntry_0215ccbciP17OutStruct0215ccbcP10GameObjectsssiih(obj->world,entry,source,-amount,source->currentStats_->primaryStats.currHP,sourceMP,sourceEffects,0);
   _Z32AppendToChainAndIncCount0215fe84PvS_i(obj->chain,entry,0);
   ++*((unsigned char*)obj->world+0x8e02);
  }
 }
 OutStruct0215ccbc* entry=func_ov000_0215e958(obj->world);
 if(!entry)return 0;
 func_ov024_021e8bf0(obj,obj->action,&selection);
 _Z33AddEntryAndIncrementCount0215a88cPvS_i(obj->world,entry,selection);
 Flag_021de274* flag=(Flag_021de274*)((char*)obj->action+0x1c);
 _Z22PopulateEntry_0215ccbciP17OutStruct0215ccbcP10GameObjectsssiih(obj->world,entry,target,amount,GetCurrentHP(target),mp,effects,flag->flag!=0);
 return entry;
}
