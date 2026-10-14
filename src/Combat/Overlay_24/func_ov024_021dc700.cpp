#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"
void* GetPtrField0x2a04(GameState*);
struct ArrayContainsByteStruct;
int ArrayContainsByte(ArrayContainsByteStruct*, int);
void IncrementByteCounterCapped0x63_0215a8d4(unsigned char*, int);
short ApplyHPDelta0215a16c(void*,int,int,short*);
extern "C" void* func_ov000_0215e958(void*);
extern "C" void func_ov000_0215a004(void*,int,int,int,void*,void*,int,int);
extern "C" void func_ov000_02159eac(void*,void*,int);
void AddEntryAndIncrementCount0215a88c(void*,void*,int);
unsigned short SelectByIndexRange0to3_021da644(int,int,int);
extern "C" void _Z22PopulateEntry_0215ccbciP17OutStruct0215ccbcP10GameObjectsssiih(void*,void*,GameObject*,short,short,short,unsigned long long,unsigned char);
struct Flags021dc700 {char pad[0x1c];unsigned char unused:7;unsigned char flag:1;};
struct Obj021dc700 {char pad[0xc];Flags021dc700* action;void* context;char pad14[0x6d-0x14];unsigned char field6d;};
struct Triple021dc700 {unsigned int a:10;unsigned int b:10;unsigned int c:10;unsigned int rest:2;};
struct Code021dc700 {unsigned int value:12;unsigned int rest:20;};
struct Params021dc700 {char pad[4];Code021dc700 code;char pad8[0x18];Triple021dc700 field20;Triple021dc700 field24;};
static inline unsigned short GetMaxHP(GameObject* c){ return c->currentStats_->primaryStats.maxHP; }
// USA: func_ov024_021dc700
extern "C" ARM void* func_ov024_021dc700(Obj021dc700* obj,int sourceID,int id,Params021dc700* params,int amount,int unused,unsigned char enabled){
    GameObject* source=GetCombatantByID((int)obj->context,sourceID);
    if(!source)return 0;
    GameObject* target=GetCombatantByID((int)obj->context,id);
    if(!target)return 0;
    unsigned short maxHP=GetMaxHP(target);
    if(target->currentStats_->primaryStats.currHP>=maxHP)amount=0;
    unsigned short sourceHP=source->currentStats_->primaryStats.currHP;
    if(sourceHP<=1)amount=0;
    if(id==sourceID)amount=0;
    if(amount>sourceHP)amount=sourceHP-1;
    unsigned short selection;
    if(enabled && amount>0){
        selection=SelectByIndexRange0to3_021da644(id,params->field20.c,params->field24.a);
        void* list=GetPtrField0x2a04(GameState::GetInstance());
        if(ArrayContainsByte((ArrayContainsByteStruct*)list, sourceID) && target->currentStats_->primaryStats.currHP==1 && params->code.value==0xb7)
            IncrementByteCounterCapped0x63_0215a8d4((unsigned char*)obj->context, 2);
    }else{
        amount=0;
        selection=SelectByIndexRange0to3_021da644(id,params->field24.b,params->field24.c);
        obj->field6d=0;
    }
    void* entry=func_ov000_0215e958(obj->context);
    if(!entry)return 0;
    AddEntryAndIncrementCount0215a88c(obj->context,entry,selection);
    union {struct{int low;int high;};unsigned long long value;} effects;
    effects.low=0;effects.high=0;
    func_ov000_0215a004(obj->context,sourceID,sourceID,amount,&effects,params,obj->action->flag!=0,0);
    effects.low=0;effects.high=0;
    short applied=0;
    short hp=ApplyHPDelta0215a16c(obj->context,id,amount,&applied);
    func_ov000_02159eac(obj->context,&effects,0x25);
    unsigned short mp=target->currentStats_->primaryStats.currMP;
    unsigned char flag;
    if(obj->action->flag)flag=1;else flag=0;
    _Z22PopulateEntry_0215ccbciP17OutStruct0215ccbcP10GameObjectsssiih(obj->context,entry,target,-applied,hp,mp,effects.value,flag);
    return entry;
}
