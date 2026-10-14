#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"
void* GetPtrField0x2a04(GameState*);
struct ArrayContainsByteStruct;
int ArrayContainsByte(ArrayContainsByteStruct*, int);
void IncrementByteCounterCapped0x63_0215a8d4(unsigned char*, int);
int CheckField0x14FiveFlagsClear020881c4(unsigned char*);
int CheckField0x14FiveFlagsClear0208810c(unsigned char*);
extern "C" void _Z26SetFlag0x800000AndByte0x24Pvh(void*,int);
int SetFlag0x800000AndCall02088208(void*, int);
void ResetAndSetFlag0x1000000(void*);
int GetCodeForCategory_021e8c48(void*, int);
unsigned short SelectByIndexRange0to3_021da644(int,int,int);
extern "C" void* func_ov000_0215e958(void*);
void AddEntryAndIncrementCount0215a88c(void*,void*,int);
void AppendToChainAndIncCount0215ffc4(void*,void*,int);
extern "C" void func_ov000_02159eac(void*,unsigned long long*,int);
extern "C" void func_ov000_0215cd44(void*,void*,GameObject*,short,unsigned long long,unsigned char);
extern "C" void func_ov000_0215af54(void*,int,int);
struct Action021dc93c {char pad[0x1c];unsigned char unused:7;unsigned char flag:1;};
struct Obj021dc93c {char pad[0xc];Action021dc93c* action;void* context;char pad14[0x71-0x14];unsigned char done;char pad72[2];unsigned char changed;};
struct Code021dc93c {unsigned int code:12;unsigned int rest:20;};
struct Triple021dc93c {unsigned int a:10;unsigned int b:10;unsigned int c:10;unsigned int rest:2;};
struct Params021dc93c {char pad[4];Code021dc93c field4;char pad8[0x1c];Triple021dc93c field24;char pad28[8];short count;};
struct Stats021dc93c {char pad[0x24];unsigned char stage;};
static inline void* GetCtx(Obj021dc93c* o){ SDK_NULL_ASSERT(o); return o->context; }
static inline int IsPartyIndex(int id){ return id>=0 && id<=3; }
// USA: func_ov024_021dc93c
extern "C" ARM void* func_ov024_021dc93c(Obj021dc93c* obj,short sourceID,int id,Params021dc93c* params,int amount,int unused,unsigned char enabled){
 GameObject* target=GetCombatantByID((int)obj->context,id);
 if(!target)return 0;
 int done=0;
 int ok=0;
 int message;
 unsigned long long effects=0;
 unsigned short code=params->field4.code;
 if(enabled){
  if(code==0x151 || code==0x152){
   if(code==0x151){
    if(CheckField0x14FiveFlagsClear020881c4((unsigned char*)target->currentStats_))ok=1;
   }else if(code==0x152){
    if(CheckField0x14FiveFlagsClear0208810c((unsigned char*)target->currentStats_))ok=1;
   }
   int stage;
   int count=params->count;
   stage=((Stats021dc93c*)target->currentStats_)->stage;
   if(stage>=count)ok=0;
   if(ok){
    void* entry=func_ov000_0215e958(obj->context);
    if(!entry)return 0;
    func_ov000_0215cd44(obj->context,entry,target,stage,effects,obj->action->flag!=0);
    AppendToChainAndIncCount0215ffc4(obj->action,entry,0);
    ++*((unsigned char*)obj->context+0x8e02);
    AddEntryAndIncrementCount0215a88c(obj->context,entry,0x152);
    if(stage<count){
     message=0;
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
     if(count>=4){
      entry=func_ov000_0215e958(obj->context);
      if(!entry)return 0;
      ResetAndSetFlag0x1000000(target->currentStats_);
      AddEntryAndIncrementCount0215a88c(obj->context,entry,0x34);
      func_ov000_02159eac(obj->context,&effects,7);
      func_ov000_0215cd44(obj->context,entry,target,stage,effects,obj->action->flag!=0);
      AppendToChainAndIncCount0215ffc4(obj->action,entry,0);
      ++*((unsigned char*)obj->context+0x8e02);
      obj->changed=1;
      AddEntryAndIncrementCount0215a88c(obj->context,entry,message);
      func_ov000_0215af54(obj->context,id,0);
     }else{
      _Z26SetFlag0x800000AndByte0x24Pvh(target->currentStats_,count);
     }
    }
   }
  }else if(CheckField0x14FiveFlagsClear020881c4((unsigned char*)target->currentStats_)){
   int count=params->count;
   int total=((Stats021dc93c*)target->currentStats_)->stage+count;
   if(total>4)count-=total-4;
   for(;count>0;count--){
    int result=SetFlag0x800000AndCall02088208(target->currentStats_, (int)GetCtx(obj));
    effects=0;
    message=GetCodeForCategory_021e8c48(obj, (signed char)result);
    void* entry=func_ov000_0215e958(obj->context);
    if(!entry)return 0;
    if(result>0){
     func_ov000_02159eac(obj->context,&effects,0x23);
     if(result==4){
      func_ov000_02159eac(obj->context,&effects,7);
      func_ov000_0215af54(obj->context,id,0);
      void* list=GetPtrField0x2a04(GameState::GetInstance());
      if(ArrayContainsByte((ArrayContainsByteStruct*)list, sourceID) && code==0xa8)
       IncrementByteCounterCapped0x63_0215a8d4((unsigned char*)obj->context, 3);
     }
    }else{
     effects=0;
     result=0;
    }
    func_ov000_0215cd44(obj->context,entry,target,result,effects,obj->action->flag!=0);
    AppendToChainAndIncCount0215ffc4(obj->action,entry,0);
    ++*((unsigned char*)obj->context+0x8e02);
    obj->changed=1;
    AddEntryAndIncrementCount0215a88c(obj->context,entry,message);
   }
   done=1;
  }else{
   void* entry=func_ov000_0215e958(obj->context);
   if(!entry)return 0;
   func_ov000_0215cd44(obj->context,entry,target,0,0,obj->action->flag!=0);
   AppendToChainAndIncCount0215ffc4(obj->action,entry,0);
   ++*((unsigned char*)obj->context+0x8e02);
   obj->changed=1;
   AddEntryAndIncrementCount0215a88c(obj->context,entry,SelectByIndexRange0to3_021da644(id,params->field24.b,params->field24.c));
  }
 }
 if(IsPartyIndex(id) && done)obj->done=1;
 return 0;
}
