#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"
struct Obj021dd028;
struct Params021dd028;
extern "C" int _Z23IsFlagBit24Set_021dd260P16FlagObj_021dd260(GameObject*);
extern "C" int _Z30CheckCombatantInTable_021ea78cP16Wrapper_021ea78ciP13Obj3_021ea78c(Obj021dd028*,int,Params021dd028*);
extern "C" void func_ov000_02159eac(void*,void*,int);
extern "C" void func_ov000_0215a004(void*,int,int,int,void*,Params021dd028*,int,int);
void ClearFlag0x400000AndBytes(unsigned char*);
unsigned short SelectByIndexRange0to3_021da644(int,int,int);
extern "C" void* func_ov000_0215e958(void*);
extern "C" void func_ov024_021e8bf0(Obj021dd028*,void*,unsigned short*);
void AddEntryAndIncrementCount0215a88c(void*,void*,int);
extern "C" void func_ov000_0215cd44(void*,void*,GameObject*,int,unsigned long long,unsigned char);
struct Flags021dd028 {char pad[0x1c]; unsigned char unused:7; unsigned char flag:1;};
struct Obj021dd028 {char pad[0xc];Flags021dd028* action;void* context;int count;char pad18[0x75-0x18];unsigned char field75;};
struct Triple021dd028 {unsigned int a:10;unsigned int b:10;unsigned int c:10;unsigned int rest:2;};
struct Field021dd028 {unsigned int low:19;unsigned int value:5;unsigned int high:8;};
struct Params021dd028 {char pad[0x1c];Field021dd028 field1c;int field20;Triple021dd028 field24;Triple021dd028 field28;};
static inline unsigned short GetHP(GameObject* c){ SDK_NULL_ASSERT(c); return c->currentStats_->primaryStats.currHP; }
// USA: func_ov024_021dd028
extern "C" ARM void* func_ov024_021dd028(Obj021dd028* obj,int sourceID,int id,Params021dd028* params,int unused,int unused2,unsigned char enabled){
    GameObject* c=GetCombatantByID((int)obj->context,id);
    if(!c)return 0;
    int allowed=1;
    if(_Z23IsFlagBit24Set_021dd260P16FlagObj_021dd260(c)){
        if(params->field1c.value==7)allowed=0;
    }
    union {struct {int low;int high;};unsigned long long value;} effects;
    effects.low=0;
    effects.high=0;
    unsigned short selection=0;
    if(enabled && allowed){
        if(_Z30CheckCombatantInTable_021ea78cP16Wrapper_021ea78ciP13Obj3_021ea78c(obj,id,params)){
            func_ov000_02159eac(obj->context,&effects,0x29);
            func_ov000_0215a004(obj->context,sourceID,id,GetHP(c)-1,&effects,params,obj->action->flag!=0,0);
            func_ov000_02159eac(obj->context,&effects,0xfe);
            ClearFlag0x400000AndBytes((unsigned char*)c->currentStats_);
            selection=0xc8;
        }else{
            func_ov000_0215a004(obj->context,sourceID,id,0xffff,&effects,params,obj->action->flag!=0,8);
            effects.low=0;
            effects.high=0;
            func_ov000_02159eac(obj->context,&effects,0xd);
            selection=SelectByIndexRange0to3_021da644(id,params->field28.a,params->field28.b);
        }
        obj->count++;
    }else{
        selection=SelectByIndexRange0to3_021da644(id,params->field24.b,params->field24.c);
        obj->field75=0;
    }
    void* entry=func_ov000_0215e958(obj->context);
    if(!entry)return 0;
    func_ov024_021e8bf0(obj,obj->action,&selection);
    AddEntryAndIncrementCount0215a88c(obj->context,entry,selection);
    func_ov000_0215cd44(obj->context,entry,c,0,effects.value,obj->action->flag!=0);
    return entry;
}
