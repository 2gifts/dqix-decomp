#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"
struct Obj021da670;
struct Params021da670;
extern "C" void* func_ov000_0215e958(void*);
extern "C" void func_ov000_02159eac(void*,void*,int);
extern "C" void func_ov000_0215cd44(void*,void*,GameObject*,int,unsigned long long,int);
extern "C" void func_ov000_021554f4(void*,int,int,Params021da670*,int,int);
extern "C" void _Z15InitObj02088f68P11Obj02088f68(void*);
extern "C" void _Z24ResetTargetFlags02088474Pvii(void*,int,int);
extern "C" int _Z28IsFlagBit8388608Set_021da998P16FlagObj_021da998(GameObject*);
extern "C" void _Z24ResetStateFields0208826cPh(void*);
extern "C" void _Z20ResetStateFields0x18Ph(void*);
extern "C" int _Z22IsFlagBit8Set_021da9b0P16FlagObj_021da9b0(GameObject*);
extern "C" int _Z23CheckFlag0x14Bit0x10SetPh(void*);
extern "C" int _Z23IsFlagBit19Set_021da9c8P16FlagObj_021da9c8(GameObject*);
extern "C" unsigned short func_ov024_021e9018(Obj021da670*,int,int,int);
extern "C" void func_ov024_021e8cfc(Obj021da670*,GameObject*,int,int);
void AddEntryAndIncrementCount0215a88c(void*,void*,int);
struct Obj021da670 {char pad[0x10];void* context;};
struct Code021da670 {unsigned int value:12;unsigned int rest:20;};
struct Params021da670 {char pad[4];Code021da670 code;};
struct Bits021da670 {unsigned short low:2;unsigned short kind:4;unsigned short middle:6;unsigned short state:2;unsigned short upper:2;};
struct Stats021da670 {char pad[0x22];Bits021da670 flags;};
static inline unsigned char GetState(Stats021da670* stats){unsigned char value=stats->flags.state;return value;}
// JPN: func_ov024_021daf30
// USA: func_ov024_021da670
extern "C" ARM void* func_ov024_021da670(Obj021da670* obj,int sourceID,int id,Params021da670* params){
    GameObject* c=GetCombatantByID((int)obj->context,id);
    if(!c)return 0;
    unsigned short code=params->code.value;
    int message=0;
    union {struct{int low;int high;};unsigned long long value;} effects;
    effects.low=0;effects.high=0;
    if(id!=sourceID){
        void* entry=func_ov000_0215e958(obj->context);
        if(!entry)return 0;
        if(code==0x150)func_ov000_02159eac(obj->context,&effects,4);
        func_ov000_0215cd44(obj->context,entry,c,0,effects.value,0);
        return entry;
    }
    if(code==0xe1 || code==0x395){
        GameObject* source=GetCombatantByID((int)obj->context,sourceID);
        if(source){
            func_ov000_021554f4(obj->context,sourceID,sourceID,params,0,2);
            source->currentStats_->primaryStats.currHP=0;
            _Z15InitObj02088f68P11Obj02088f68(source->currentStats_);
        }
    }else if(code==0x384){
        func_ov000_02159eac(obj->context,&effects,0x1a);
    }else if(code==0x385){
        func_ov000_02159eac(obj->context,&effects,0x10);
    }else if(code==0x3aa){
        func_ov000_02159eac(obj->context,&effects,0x19);
    }else if(GetState((Stats021da670*)c->currentStats_)){
        func_ov000_02159eac(obj->context,&effects,0xb);
        switch(GetState((Stats021da670*)c->currentStats_)){
        case 1:
            message=0x93;
            _Z24ResetTargetFlags02088474Pvii(c->currentStats_,10,0);
            break;
        case 2:
            ((unsigned char*)obj->context)[0x8e96]=_Z28IsFlagBit8388608Set_021da998P16FlagObj_021da998(c);
            message=0x94;
            _Z24ResetStateFields0208826cPh(c->currentStats_);
            func_ov000_02159eac(obj->context,&effects,0x18);
            break;
        case 3:
            message=0x95;
            _Z20ResetStateFields0x18Ph(c->currentStats_);
            func_ov000_02159eac(obj->context,&effects,0x17);
            break;
        }
        ((Stats021da670*)c->currentStats_)->flags.state=0;
    }else if(_Z22IsFlagBit8Set_021da9b0P16FlagObj_021da9b0(c)){
        message=0x70;
    }else if(_Z23CheckFlag0x14Bit0x10SetPh(c->currentStats_)){
        message=0x44;
    }else if(_Z23IsFlagBit19Set_021da9c8P16FlagObj_021da9c8(c)){
        message=func_ov024_021e9018(obj,id,((Stats021da670*)c->currentStats_)->flags.kind,1);
        func_ov000_02159eac(obj->context,&effects,0x27);
    }
    if(((unsigned char*)obj->context)[0x8e96])func_ov024_021e8cfc(obj,c,0,0);
    void* entry=func_ov000_0215e958(obj->context);
    if(!entry)return 0;
    if(message)AddEntryAndIncrementCount0215a88c(obj->context,entry,message);
    func_ov000_0215cd44(obj->context,entry,c,0,effects.value,0);
    return entry;
}
