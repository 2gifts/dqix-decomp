#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"
#include "Util/Random.h"
struct Container02070e60;
struct Element021e2298 { unsigned short key; unsigned char type2; unsigned char type3; int unused; void* field8; unsigned short fieldC; };
extern "C" Element021e2298* _Z33SearchWithLow15Comparator02070fd0P17Container02070e60i(Container02070e60*,int);
extern "C" short func_ov000_0215cda0(void*);
extern "C" void* func_ov000_0215e958(void*);
extern "C" void func_ov000_0215cd44(void*,void*,GameObject*,int,int,int,int);
struct Weights021e2298 { int values[3]; };
extern Weights021e2298 data_ov024_021fe6ec;
struct Party021e2298 { unsigned short key; char pad[0x14]; unsigned char used2; unsigned char used3; };
struct BattleFlags021e2298 {unsigned char low:4;unsigned char count:2;unsigned char high:2;};
struct Battle021e2298 {char pad[0x81b1];BattleFlags021e2298 flags;char pad2[2];Party021e2298 parties[4];char pad3[0x8e18-0x81b4-4*0x18];char* data;};
struct Message021e2298 {char pad[6];short value6;char pad8[0x12];unsigned short value1a;unsigned short value1c;};
struct Action021e2298 {char pad[0x1c];unsigned char unused:7;unsigned char flag:1;};
struct Obj021e2298 {char pad[4];Message021e2298* message;char pad8[4];Action021e2298* action;Battle021e2298* battle;int count;char pad18[0x6e - 0x18];unsigned char done;};
// USA: func_ov024_021e2298
extern "C" ARM void* func_ov024_021e2298(Obj021e2298* obj,int unused,int id){
    GameObject* c=GetCombatantByID((int)obj->battle,id);
    if(!c)return 0;
    Battle021e2298* battle=obj->battle;
    if(obj->done==0){
        char* data=battle->data+0x284;
        Weights021e2298 weights=data_ov024_021fe6ec;
        int roll=NextRandomMax((Random*)battle,100);
        int choice=0;
        for(;choice<3;choice++){
            if(weights.values[choice]>=roll)break;
            roll-=weights.values[choice];
        }
        unsigned char flags=0;
        int low=obj->battle->flags.low;
        for(int i=0;i<obj->battle->flags.count;i++){
            Party021e2298* party=&obj->battle->parties[i];
            Element021e2298* e=_Z33SearchWithLow15Comparator02070fd0P17Container02070e60i((Container02070e60*)(data+0x400),party->key);
            if(e){
                if(e->field8)flags|=1;
                if(e->fieldC)flags|=2;
                if(e->type2<7 && choice==1){flags|=4;party->used2=1;}
                if(e->type3<7 && choice==0){flags|=8;party->used3=1;}
            }
        }
        obj->done=1;
        obj->count++;
        obj->message->value1c=0x1f;
        if(flags&1){
            obj->message->value1c=0x263;
            if(flags&2){
                obj->message->value1c=0x1be;
                if(flags&4){
                    if(low>1)obj->message->value1c=0x1bf;else obj->message->value1c=0x224;
                }else if(flags&8){
                    if(low>1)obj->message->value1c=0x1c0;else obj->message->value1c=0x225;
                }
            }else if(flags&4){
                if(low>1)obj->message->value1c=0x266;else obj->message->value1c=0x268;
            }else if(flags&8){
                if(low>1)obj->message->value1c=0x267;else obj->message->value1c=0x269;
            }
        }else if(flags&4){
            if(low>1)obj->message->value1c=0x264;else obj->message->value1c=0x26a;
        }else if(flags&8){
            if(low>1)obj->message->value1c=0x265;else obj->message->value1c=0x26b;
        }
        obj->message->value1a=obj->message->value1c;
        obj->message->value6=func_ov000_0215cda0(obj->battle);
    }
    void* entry=func_ov000_0215e958(obj->battle);
    if(!entry)return 0;
    func_ov000_0215cd44(obj->battle,entry,c,0,0,0,obj->action->flag!=0);
    return entry;
}
