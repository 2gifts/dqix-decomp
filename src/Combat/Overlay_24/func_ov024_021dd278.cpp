#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"
extern "C" int _Z14IsFlag10088SetP7S_10088(void*);
extern "C" void _Z29ResetFields14And18KeepFlag0x4Pht(unsigned char*,int);
extern "C" void func_ov000_02159eac(void*,void*,int);
GameObject* GetCombatantWithFlag0x100(GameState*,int);
unsigned short SelectByIndexRange0to3_021da644(int,int,int);
extern "C" void* func_ov000_0215e958(void*);
void AddEntryAndIncrementCount0215a88c(void*,void*,int);
extern "C" void func_ov000_0215cd44(void*,void*,GameObject*,int,unsigned long long,unsigned char);
struct Action021dd278 {char pad[0x1c];unsigned char unused:7;unsigned char flag:1;};
struct Obj021dd278 {char pad[0xc];Action021dd278* action;void* context;int count;};
struct Code021dd278 {unsigned int code:12;unsigned int lower:10;unsigned int upper:10;};
struct Triple021dd278 {unsigned int a:10;unsigned int b:10;unsigned int c:10;unsigned int rest:2;};
struct Params021dd278 {char pad[4];Code021dd278 field4;char pad8[0x18];Triple021dd278 field20;Triple021dd278 field24;};
struct Value021dd278 {unsigned int low:20;unsigned int value:10;unsigned int high:2;};
struct State021dd278 {char pad[0x10];Value021dd278 field10;char pad14[0x26];unsigned char field3a;unsigned char changed:1;unsigned char rest:7;};
static inline int IsParty(int id){return id>=0 && id<=3;}
// USA: func_ov024_021dd278
extern "C" ARM void* func_ov024_021dd278(Obj021dd278* obj,int sourceID,int id,Params021dd278* params,int unused,int unused2,unsigned char enabled){
    GameObject* source=GetCombatantByID((int)obj->context,sourceID);
    if(!source)return 0;
    GameObject* target=GetCombatantByID((int)obj->context,id);
    if(!target)return 0;
    int active=0;
    if(_Z14IsFlag10088SetP7S_10088(target))active=1;
    unsigned short code=params->field4.code;
    union {struct{int low;int high;};unsigned long long value;} effects;
    effects.low=0;effects.high=0;
    unsigned short selection;
    if(enabled && active){
        float factor=1.0f;
        switch(code){
        case 0x27:factor=0.5f;break;
        case 0x26:
        case 0x54:
            if(IsParty(sourceID)){
                unsigned short value=((State021dd278*)source->currentStats_)->field10.value;
                if(value<=params->field4.lower)factor=0.25f;
                else if(value>=params->field4.upper)factor=0.5f;
                else factor=(25.0f+(float)(int)((25.0f/(params->field4.upper-params->field4.lower))*(value-params->field4.lower)))/100.0f;
            }else factor=0.5f;
            break;
        }
        short hp=(int)(factor*(float)(unsigned int)target->currentStats_->primaryStats.maxHP);
        _Z29ResetFields14And18KeepFlag0x4Pht((unsigned char*)target->currentStats_,hp);
        func_ov000_02159eac(obj->context,&effects,3);
        ((State021dd278*)target->currentStats_)->changed=1;
        if(IsParty(id)){
            GameObject* member=GetCombatantWithFlag0x100(GameState::GetInstance(),id);
            if(member)((State021dd278*)member->currentStats_)->field3a=1;
        }
        selection=SelectByIndexRange0to3_021da644(id,params->field20.c,params->field24.a);
        obj->count++;
    }else{
        if(active)selection=0x21;
        else selection=SelectByIndexRange0to3_021da644(id,params->field24.b,params->field24.c);
    }
    void* entry=func_ov000_0215e958(obj->context);
    if(!entry)return 0;
    AddEntryAndIncrementCount0215a88c(obj->context,entry,selection);
    func_ov000_0215cd44(obj->context,entry,target,0,effects.value,obj->action->flag!=0);
    return entry;
}
