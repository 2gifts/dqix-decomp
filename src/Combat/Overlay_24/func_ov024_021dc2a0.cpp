#include <globaldefs.h>
#include "GameState/GameState.h"
GameObject* GetCombatantWithFlag0x400ByID(int,int);
extern "C" void* _Z19GetActiveCombatWorkv();
extern "C" int _Z23FindRecordByKey0215fb54isP11Out0215fb54(int,short,void*);
extern "C" void* _Z26FindNodeByShortKey02162d88Pvs(void*,int);
extern "C" int func_ov000_02161380(void*,int,int,int);
struct Entry021dc2a0 {char pad[0xe];short fieldE;short field10;short field12;short field14;char pad16;unsigned char field17;char pad18[8];int field20;};
extern "C" Entry021dc2a0* _Z28GetTableEntry0x8e01Bound0x88Pv(void*);
extern "C" void _Z19ResetStruct0215fef0P14Struct0215fef0(Entry021dc2a0*);
extern "C" Entry021dc2a0* func_ov000_0215e958(void*);
extern "C" void _Z17ZeroWorkBlock0x20Pv(void*);
extern "C" void _Z32AppendToChainAndIncCount0215ffc4PvS_i(void*,void*,int);
extern "C" void _Z18AppendNode021600ccP11Obj021600ccP12Node021600cc(void*,void*);
void AddEntryAndIncrementCount0215a88c(void*,void*,int);
extern "C" void func_ov000_0215cd44(void*,void*,GameObject*,int,int,int,int);
struct Pair021dc2a0 {int values[2];};
extern Pair021dc2a0 data_ov024_021fe6d0;
struct Code021dc2a0 {unsigned int value:12;unsigned int rest:20;};
struct Field18_021dc2a0 {unsigned int low:5;unsigned int mode:7;unsigned int high:20;};
struct Triple021dc2a0 {unsigned int a:10;unsigned int b:10;unsigned int c:10;unsigned int high:2;};
struct Params021dc2a0 {char pad[4];Code021dc2a0 code;char pad8[0x10];Field18_021dc2a0 field18;char pad1c[8];Triple021dc2a0 field24;};
struct Message021dc2a0 {unsigned short code;};
struct Obj021dc2a0 {char pad[4];Message021dc2a0* message;char pad8[8];void* context;int count;};
struct ActorStats021dc2a0 {char pad[0x188];unsigned short hp;unsigned short mp;};
// USA: func_ov024_021dc2a0
extern "C" ARM void* func_ov024_021dc2a0(Obj021dc2a0* obj,short id,int unused,Params021dc2a0* params,int unused2,int unused3,unsigned char enabled){
    GameObject* c=GetCombatantWithFlag0x400ByID((int)obj->context,id);
    if(!c)return 0;
    void* work=_Z19GetActiveCombatWorkv();
    int total=1;
    Pair021dc2a0 ids=data_ov024_021fe6d0;
    ids.values[0]=*(short*)((char*)c+2);
    if(params->field18.mode==12){
        total=_Z23FindRecordByKey0215fb54isP11Out0215fb54((int)obj->context,params->code.value,&ids);
        for(int i=0;i<total;i++){
            if(!_Z26FindNodeByShortKey02162d88Pvs(work,ids.values[i])){total=0;break;}
        }
    }
    int slot=-1;
    if(params->code.value==0xf2)slot=*(signed char*)((char*)c+0x17c);
    int successes=0;
    if(enabled){
        for(int i=0;i<total;i++){
            for(int j=0;j<1;j++){
                int nextID=func_ov000_02161380(work,ids.values[i],slot,1);
                if(nextID>=0xc0){
                    Entry021dc2a0* node=_Z28GetTableEntry0x8e01Bound0x88Pv(obj->context);
                    if(node){
                        _Z19ResetStruct0215fef0P14Struct0215fef0(node);
                        node->field20=0;
                        node->fieldE=nextID;
                        node->field17=1;
                        GameObject* actor=GetCombatantWithFlag0x400ByID((int)obj->context,nextID);
                        if(actor){
                            Entry021dc2a0* entry=func_ov000_0215e958(obj->context);
                            if(entry){
                                _Z17ZeroWorkBlock0x20Pv(entry);
                                entry->field20=0;
                                entry->fieldE=((ActorStats021dc2a0*)actor)->hp;
                                entry->field10=((ActorStats021dc2a0*)actor)->mp;
                                entry->field12=((ActorStats021dc2a0*)actor)->hp;
                                entry->field14=((ActorStats021dc2a0*)actor)->mp;
                                _Z32AppendToChainAndIncCount0215ffc4PvS_i(node,entry,0);
                                ((unsigned char*)obj->context)[0x8e02]++;
                                _Z18AppendNode021600ccP11Obj021600ccP12Node021600cc(obj->message,node);
                                successes++;
                                ((unsigned char*)obj->context)[0x8e01]++;
                                obj->count++;
                            }
                        }
                    }
                }
            }
        }
    }
    if(successes<=0){
        Entry021dc2a0* entry=func_ov000_0215e958(obj->context);
        if(!entry)return 0;
        obj->message->code=0x1f5;
        unsigned short selection=params->field24.c;
        AddEntryAndIncrementCount0215a88c(obj->context,entry,selection);
        GameObject* actor=GetCombatantWithFlag0x400ByID((int)obj->context,id);
        if(!actor)return 0;
        func_ov000_0215cd44(obj->context,entry,actor,0,0,0,0);
        return entry;
    }
    return 0;
}
