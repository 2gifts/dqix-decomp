#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"
struct Obj021de9dc;
struct Params021de9dc;
extern "C" int _Z30CheckCombatantInTable_021ea78cP16Wrapper_021ea78ciP13Obj3_021ea78c(Obj021de9dc*,int,Params021de9dc*);
extern "C" short func_ov000_0215a004(void*,int,int,int,void*,Params021de9dc*,int,int);
extern "C" void func_ov000_02159eac(void*,void*,int);
extern "C" int func_ov000_02159f18(void*,unsigned long long,int);
void ClearFlag0x400000AndBytes(unsigned char*);
unsigned short SelectByIndexRange0to3_021da644(int,int,int);
extern "C" void* func_ov000_0215e958(void*);
extern "C" void func_ov024_021e8bf0(Obj021de9dc*,void*,unsigned short*);
void AddEntryAndIncrementCount0215a88c(void*,void*,int);
extern "C" void _Z22PopulateEntry_0215ccbciP17OutStruct0215ccbcP10GameObjectsssiih(void*,void*,GameObject*,short,short,short,unsigned long long,unsigned char);
struct Flags021de9dc {char pad[0x1c];unsigned char unused:7;unsigned char flag:1;};
struct Obj021de9dc {char pad[0xc];Flags021de9dc* action;void* context;};
struct Triple021de9dc {unsigned int a:10;unsigned int b:10;unsigned int c:10;unsigned int rest:2;};
struct Params021de9dc {char pad[0x20];Triple021de9dc field20;Triple021de9dc field24;Triple021de9dc field28;};
static inline unsigned short GetHP(GameObject* c){unsigned short hp=c->currentStats_->primaryStats.currHP;return hp;}
// JPN: func_ov024_021df274
// USA: func_ov024_021de9dc
extern "C" ARM void* func_ov024_021de9dc(Obj021de9dc* obj,int sourceID,int id,Params021de9dc* params,int amount,int unused,unsigned char enabled){
    GameObject* c=GetCombatantByID((int)obj->context,id);
    if(!c)return 0;
    short hp;
    int handled=0;
    unsigned short selection=0;
    union {struct{int low;int high;};unsigned long long value;} effects;
    effects.low=0;effects.high=0;
    hp=c->currentStats_->primaryStats.currHP;
    if(enabled && amount>0){
        if(((unsigned char*)obj->context)[0x8e94] && _Z30CheckCombatantInTable_021ea78cP16Wrapper_021ea78ciP13Obj3_021ea78c(obj,id,params)){
            amount=0;
            hp=func_ov000_0215a004(obj->context,sourceID,id,GetHP(c)-1,&effects,params,obj->action->flag!=0,0x20);
            func_ov000_02159eac(obj->context,&effects,0x29);
            ClearFlag0x400000AndBytes((unsigned char*)c->currentStats_);
            selection=0xc8;
            handled=1;
        }
        if(!handled){
            hp=func_ov000_0215a004(obj->context,sourceID,id,amount,&effects,params,obj->action->flag!=0,0x20);
            if(func_ov000_02159f18(obj->context,effects.value,2)){
                amount=0;
                selection=SelectByIndexRange0to3_021da644(id,params->field28.a,params->field28.b);
            }else{
                selection=SelectByIndexRange0to3_021da644(id,params->field20.c,params->field24.a);
            }
        }
    }else{
        selection=SelectByIndexRange0to3_021da644(id,params->field24.b,params->field24.c);
    }
    void* entry=func_ov000_0215e958(obj->context);
    if(!entry)return 0;
    func_ov024_021e8bf0(obj,obj->action,&selection);
    AddEntryAndIncrementCount0215a88c(obj->context,entry,selection);
    unsigned short mp=c->currentStats_->primaryStats.currMP;
    unsigned char flag;
    if(obj->action->flag)flag=1;else flag=0;
    _Z22PopulateEntry_0215ccbciP17OutStruct0215ccbcP10GameObjectsssiih(obj->context,entry,c,amount,hp,mp,effects.value,flag);
    return entry;
}
