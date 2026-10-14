#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"
struct FlagObj_021dd260;
int IsFlagBit24Set_021dd260(FlagObj_021dd260*);
int CheckField0x14FiveFlagsClear020881c4(unsigned char*);
void SetFlag0x800000AndByte0x24(void*,unsigned char);
void ResetAndSetFlag0x1000000(void*);
extern "C" void* func_ov000_0215e958(void*);
void AddEntryAndIncrementCount0215a88c(void*,void*,int);
void AppendToChainAndIncCount0215ffc4(void*,void*,int);
extern "C" void func_ov000_02159eac(void*,unsigned long long*,int);
extern "C" void func_ov000_0215cd44(void*,void*,GameObject*,short,unsigned long long,unsigned char);
extern "C" void func_ov000_0215af54(void*,int,int);
struct Action021e191c {char pad[0x1c];unsigned char unused:7;unsigned char flag:1;unsigned char other;};
struct Obj021e191c {char pad[0xc];Action021e191c* action;void* context;char pad14[0x58];unsigned char mode;char pad6d[7];unsigned char changed;};
struct Code021e191c {unsigned int code:12;unsigned int rest:20;};
struct Params021e191c {char pad[4];Code021e191c field4;};
struct Stats021e191c {char pad[0x24];unsigned char stage;};
// USA: func_ov024_021e191c
extern "C" ARM void* func_ov024_021e191c(Obj021e191c* obj,int unused,int id,Params021e191c* params){
 GameObject* target=GetCombatantByID((int)obj->context,id);
 if(!target)return 0;
 unsigned long long effects=0;
 if(IsFlagBit24Set_021dd260((FlagObj_021dd260*)target) || !CheckField0x14FiveFlagsClear020881c4((unsigned char*)target->currentStats_)){
  void* entry=func_ov000_0215e958(obj->context);
  if(!entry)return 0;
  AddEntryAndIncrementCount0215a88c(obj->context,entry,0x1f);
  func_ov000_0215cd44(obj->context,entry,target,0,0,obj->action->flag!=0);
  AppendToChainAndIncCount0215ffc4(obj->action,entry,0);
  ++*((unsigned char*)obj->context+0x8e02);
  obj->changed=1;
 }else{
  int stage=((Stats021e191c*)target->currentStats_)->stage;
  int original=stage;
  void* entry=func_ov000_0215e958(obj->context);
  if(!entry)return 0;
  func_ov000_0215cd44(obj->context,entry,target,stage,effects,obj->action->flag!=0);
  AppendToChainAndIncCount0215ffc4(obj->action,entry,0);
  ++*((unsigned char*)obj->context+0x8e02);
  AddEntryAndIncrementCount0215a88c(obj->context,entry,0x1bc);
  if(params->field4.code==0x20b){
   if(obj->mode || stage>=3)stage=3;
   else stage=2;
  }
  if(stage<3){
  int message=0;
  while(stage<3){
   ++stage;
   switch(stage){case 1:message=0x31;break;case 2:message=0x32;break;case 3:message=0x33;break;}
   effects=0;
   func_ov000_02159eac(obj->context,&effects,0x23);
   void* step=func_ov000_0215e958(obj->context);
   if(!step)return 0;
   func_ov000_0215cd44(obj->context,step,target,stage,effects,obj->action->flag!=0);
   AppendToChainAndIncCount0215ffc4(obj->action,step,0);
   ++*((unsigned char*)obj->context+0x8e02);
   obj->changed=1;
   AddEntryAndIncrementCount0215a88c(obj->context,step,message);
  }
  SetFlag0x800000AndByte0x24(target->currentStats_,3);
  }
  if(obj->mode || original>=3){
   void* last=func_ov000_0215e958(obj->context);
   if(!last)return 0;
   ResetAndSetFlag0x1000000(target->currentStats_);
   AddEntryAndIncrementCount0215a88c(obj->context,last,0x34);
   func_ov000_02159eac(obj->context,&effects,7);
   func_ov000_0215cd44(obj->context,last,target,4,effects,obj->action->flag!=0);
   AppendToChainAndIncCount0215ffc4(obj->action,last,0);
   ++*((unsigned char*)obj->context+0x8e02);
   obj->changed=1;
   if(params->field4.code==0x20b)obj->action->other|=2;
   else func_ov000_0215af54(obj->context,id,0);
  }
 }
 return 0;
}
