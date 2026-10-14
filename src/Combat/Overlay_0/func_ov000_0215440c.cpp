#include <globaldefs.h>
#include "Resource/ActionDataTables.h"
#include "std_library_functions.h"
struct Stats { char p[0x2e]; short id; };
struct GameObject { char p[0x138]; Stats* stats; char q[0x17c - 0x13c]; unsigned char group; char r[2]; unsigned char linked; unsigned char solo; };
class GameState {public: static GameState* GetInstance();GameObject* GetCombatantByIndex(int);};
struct S_10088;int IsFlag10088Set_02010088(S_10088*);
int IsFlag0x18Bit0x2000Set_ov000_02153c0c(GameObject*);
GameObject* GetCombatantWithFlag0x400_0200fea4(GameState*,int);
int ClassifyField0x81fe_ov000_0215fc60(char*);
struct Skill {char p[8];unsigned int low8:8,side:2,rest8:22;char q[8];unsigned int low14:28,mode:4;unsigned int low18:5,type:7,rest18:20;unsigned int low1c:14,repeats:5,rest1c:13;};
Skill* SearchBothTables02079e2c(char*,int);int GetCombatantField0x148Bits3To4_ov000_02159d94(int,int);
struct Random;int PickTableValueWithRandomFill_0215fbe0(Random*,int);int NextRandomMax(Random*,int);
struct Entry { char p[0x20]; short id; };
struct Action { short id; char p[7]; unsigned char count; char q[6]; Entry* entry; };
struct List02160094;struct Node02160094 { char p[0x20]; unsigned short id; };Node02160094* GetNodeAtIndex02160094(List02160094*,int);
struct List021600f8;struct Node021600f8 { char p[0xe]; short id; };Node021600f8* GetNodeAtIndex021600f8(List021600f8*,int);
struct Group { unsigned char pad0; unsigned char flags:4,count:2,pad1:2; char pad2[4]; unsigned char ids[8]; unsigned char memberCount:4,weight:4; char padf[0x18-0xf]; };
struct Ids { short v[8]; };
extern "C" {extern const Ids data_ov000_02182c84;extern const Ids data_ov000_02182b64;extern const Ids data_ov000_02182ae4;
int func_ov000_02153e78(Random*,short*,int,int,int);int func_ov000_0215eb1c(Random*,short*,int,int);int func_ov000_0215e9fc(Random*,short*,int,int);int func_ov000_02154a04(Random*,int,int,short*);}
inline int GetId(Entry* e){return e->id;}
inline int GetId(Stats* s){return s->id;}
inline int GetId(Node021600f8* n){return n->id;}
inline int GetId(Ids* ids,int i){return ids->v[i];}
inline GameObject* GetEnemy(int id){return GetCombatantWithFlag0x400_0200fea4(GameState::GetInstance(),id);}
inline GameObject* GetUnit(int id){return GameState::GetInstance()->GetCombatantByIndex(id);}
// USA: func_ov000_0215440c
extern "C" ARM int func_ov000_0215440c(Random* self,Action* action,short* output){
 ActionDataTables* tables = GetData02108e10_020797dc();
 if(ClassifyField0x81fe_ov000_0215fc60((char*)self)){
  Node02160094* slotNode=GetNodeAtIndex02160094((List02160094*)action,0);
  if(slotNode){int party=(slotNode->id>=0xc0&&slotNode->id<=0xc7)?1:0;if(party){output[0]=0;return 1;}}
 }
 Skill* skill=SearchBothTables02079e2c((char*)tables,action->id);if(!skill)return 0;
 int count=0;
 GameObject* unit=GetEnemy(GetId(action->entry));if(!unit)return count;
 int done=0;
 if(GetCombatantField0x148Bits3To4_ov000_02159d94((int)self,GetId(action->entry))!=2){
  if(unit->linked){
   if((skill->mode==2||skill->mode==5)&&skill->side==1){
    GameObject* partner=GetUnit(GetId(unit->stats));
    if(partner&&!IsFlag10088Set_02010088((S_10088*)partner)&&!IsFlag0x18Bit0x2000Set_ov000_02153c0c(partner)){output[0]=GetId(unit->stats);count++;done=1;}
   }
  }else if(unit->solo)done=1;
 }
 if(!done){
  if(skill->mode==4||skill->mode==3){
   Ids ids=data_ov000_02182c84;short* p=ids.v;int group=unit->group;short n=0;
   if(skill->side==2){
    if(action->count){
     Node021600f8* node=GetNodeAtIndex021600f8((List021600f8*)action,0);
     if(node){GameObject* target=GetEnemy(GetId(node));if(target)group=target->group;}
    }
    if(skill->mode==4)n=func_ov000_02153e78(self,ids.v,8,group,0);
    else if(skill->mode==3)n=func_ov000_0215eb1c(self,ids.v,8,0);
   }else if(skill->side==1){
    n=func_ov000_0215e9fc(self,p,8,0);
   }
   if(skill->type==0x21){
    Group* groups=(Group*)((char*)self+0x81b0);int weight=0;int alive=0;
    for(int i=0;i<groups->count;i++){weight+=groups[i].weight;Ids buf=data_ov000_02182b64;alive+=func_ov000_02153e78(self,buf.v,8,i,0);}
    if(weight>=5){memcpy(output,&ids,sizeof(ids));return n;}
    if(alive>5)alive=5;
    count=0;int spare=alive-weight;
    for(int i=0;i<groups->count;i++){
     for(int j=0;j<groups[i].memberCount;j++){
      int id=groups[i].ids[j]+0xc0;
      GameObject* c=GameState::GetInstance()->GetCombatantByIndex((short)id);
      if(!c)continue;
      if(IsFlag0x18Bit0x2000Set_ov000_02153c0c(c))continue;
      if(IsFlag10088Set_02010088((S_10088*)c)){if(spare>0){output[count]=id;count++;spare--;}}
      else{output[count]=id;count++;}
      if(count>=5)break;
     }
    }
   }else{
    for(long i=0;i<n;i++){
     short cid=p[i];
     GameState* gs=GameState::GetInstance();
     GameObject* c=gs->GetCombatantByIndex(cid);
     if(skill->type==0x12||skill->type==0x21||(!IsFlag10088Set_02010088((S_10088*)c)&&!IsFlag0x18Bit0x2000Set_ov000_02153c0c(c))){output[count]=p[i];count++;}
    }
   }
  }else{
   for(int i=0;i<action->count;i++){
    Node021600f8* node=GetNodeAtIndex021600f8((List021600f8*)action,i);
    GameObject* c=GetUnit(GetId(node));
    if(!c)continue;
    if(skill->type==0x12||skill->type==0x21||(!IsFlag10088Set_02010088((S_10088*)c)&&!IsFlag0x18Bit0x2000Set_ov000_02153c0c(c))){output[count]=GetId(node);count++;}
   }
  }
 }
 if(count>0){
  Ids selected=data_ov000_02182ae4;short* ptr=selected.v;
  int repeat=PickTableValueWithRandomFill_0215fbe0(self,(signed char)skill->repeats);
  if(repeat>0){for(int i=0;i<repeat;i++){ptr[i]=output[NextRandomMax(self,count)];}memset(output,0,count*2);memcpy(output,selected.v,repeat*2);count=repeat;}
  return count;
 }
 return func_ov000_02154a04(self,(unsigned short)GetId(action->entry),(unsigned short)action->id,output);
}
