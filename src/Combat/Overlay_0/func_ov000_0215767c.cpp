#include <globaldefs.h>
#include "std_library_functions.h"
struct Stats {char p[0x22];unsigned short lo:12,mode:2,hi:2;char q[0x12];short skill;char r[3];unsigned char flags;};
struct GameObject {char p[0x138];Stats* stats;
#if defined(jpn)
char q[8];
#else
char q[20];
#endif
unsigned char* actor;};
class GameState {public:static GameState* GetInstance();GameObject* GetCombatantByIndex(int);};
struct ActionEntry {char p[0x1c];short sentinel,pad;unsigned short id;char q[0xe];int tail;};
struct TargetNode {char p[0xe];short id;char q[7];unsigned char active;char r[0xc];};
struct ActionNode {unsigned short action;char p[7];unsigned char targetCount;char q;unsigned char flag:1,other:7;char r[4];ActionEntry* entry;char s[0x14];};
struct Battle {char p[0x8e00];unsigned char tableCount;char q[0x17];char* field8e18;char r[0x58];TargetNode* targets;char s[8];unsigned char entryCount,targetCount;char t[0x14];unsigned char mode;};
struct SkillData {char p[0x18];unsigned int low:5,type:7,high:20;char q[0x14];short linked;};
struct Ids {short v[8];};struct Party {short v[4];};struct Big {char buf[0x678];};
char* GetData02108e10();GameObject* GetCombatantWithFlag0x100(GameState*,int);GameObject* GetCombatantWithFlag0x400(GameState*,int);
int IsSpecialStateValue_02159c58(void*,int);int HasFlaggedSlotBit21Set0208555c(unsigned char*);struct Random;int NextRandomMax(Random*,int);
struct TargetObj02088418;int IsValidTargetCombatant(TargetObj02088418*,int,int);int IsFlag0x14Bit0x800000Set(GameObject*);void ResetTargetFlags02088474(void*,int,int);
int GetCombatantField0x148Bits3To4(int,int);void ClearInt0208a910(int*);struct Container02070e60;void* SearchWithLow15Comparator02070fd0(Container02070e60*,int);
struct Obj0204887c;void ReplaceEntryAndFormat0204887c(Obj0204887c*,char*);SkillData* SearchBothTables02079e2c(char*,int);
void ResetStruct02157cdc(void*);void* GetTableEntry0x8e00Bound0x48(void*);void ClearFlags0x3bAnd0x3cAndByte0x3a(unsigned char*);
int IsFlag0x14Bit0x80000Set(GameObject*);int IsFlag0x14Bit0x20Set(GameObject*);
struct Obj021600cc;struct Node021600cc;void AppendNode021600cc(Obj021600cc*,Node021600cc*);
struct Obj02160068;struct Node02160068;void AppendNode02160068(Obj02160068*,Node02160068*);
extern "C" {
extern const Ids data_ov000_02182c54,data_ov000_02182c64;extern const Party data_ov000_02182a74;
int func_ov000_0215e9fc(void*,short*,int,int);int func_ov000_02159cb4(void*,int);int func_ov000_02155f9c(void*,int,int);
void func_ov024_021f73b8(Big*);void func_ov024_021f8f20(Big*,void*,int,ActionNode*);
int func_ov000_0215704c(void*,int);int func_0208a91c(int*,void*,int,int*,short*);
int func_ov000_0215833c(void*,int,ActionNode*);int func_ov000_0215f67c(void*,int);
}
inline int IsParty(int id){return (id>=0&&id<=3)?1:0;}
// USA: func_ov000_0215767c
// JPN: func_ov000_0215767c
extern "C" ARM void func_ov000_0215767c(Battle* self,ActionNode* src,ActionNode* dst){
 GameState* gs=GameState::GetInstance();char* data=GetData02108e10();int id=(short)src->entry->id;GameObject* unit=GameState::GetInstance()->GetCombatantByIndex(id);if(!unit)return;
 Ids ids(data_ov000_02182c54);signed char count=0;bool special=false;bool multiple=false;self->mode=0;
 if(IsParty(id)){
  if(IsSpecialStateValue_02159c58(self,src->action)){
   ids.v[count++]=id;Party party(data_ov000_02182a74);int total=func_ov000_0215e9fc(self,party.v,4,1);
   if(total!=4)src->action=func_ov000_02159cb4(self,id);
   else {multiple=true;for(int i=0;i<total;i++){int next=party.v[i];if(ids.v[0]!=next)ids.v[count++]=next;}}
  }else{
   ids.v[count++]=id;GameObject* member=GetCombatantWithFlag0x100(gs,id);int handled=0;
   if(member&&HasFlaggedSlotBit21Set0208555c(member->actor)&&!func_ov000_02155f9c(self,id,0)&&!NextRandomMax((Random*)self,4)&&IsValidTargetCombatant((TargetObj02088418*)member->stats,9,0)){
    self->mode=IsFlag0x14Bit0x800000Set(member);ResetTargetFlags02088474(member->stats,9,0);handled=1;
   }
   if(!handled&&src->action!=0x1f6){Big big;func_ov024_021f73b8(&big);func_ov024_021f8f20(&big,self,id,src);}
  }
 }else{
  ids.v[count++]=id;GameObject* enemy=GetCombatantWithFlag0x400(GameState::GetInstance(),id);int kind=GetCombatantField0x148Bits3To4((int)self,id);int skip=1;
  if(func_ov000_0215704c(self,id))special=true;
  else if(src->action==0x1f7&&!func_ov000_02155f9c(self,id,1))skip=0;
  else if(kind==2)skip=0;
  if(!skip){
   Ids targets(data_ov000_02182c64);int num=0;int work;ClearInt0208a910(&work);
   src->action=func_0208a91c(&work,self,(unsigned short)id,&num,targets.v);SkillData* skill=SearchBothTables02079e2c(data,(short)src->action);
   if(skill){while(skill->type==0x22){void* entry=SearchWithLow15Comparator02070fd0((Container02070e60*)(self->field8e18+0x684),skill->linked);if(entry){ReplaceEntryAndFormat0204887c((Obj0204887c*)enemy,(char*)entry);enemy->stats->skill=skill->linked;}
    memset(targets.v,-1,16);num=0;src->action=func_0208a91c(&work,self,(unsigned short)id,&num,targets.v);skill=SearchBothTables02079e2c(data,(short)src->action);if(!skill)break;
   }}
   src->targetCount=0;for(int i=0;i<num;i++){TargetNode* target=&self->targets[self->targetCount];ResetStruct02157cdc(target);target->id=targets.v[i];target->active=1;AppendNode021600cc((Obj021600cc*)src,(Node021600cc*)target);self->targetCount++;}
  }
 }
 for(signed char i=0;i<count;i++){
  ActionEntry* entry=(ActionEntry*)GetTableEntry0x8e00Bound0x48(self);if(!entry)break;memset(entry,0,0x30);entry->sentinel=-1;entry->tail=0;int current=ids.v[i];int handled=0;entry->id=current;
  if(!multiple)handled=func_ov000_0215833c(self,current,src);
  GameObject* other=GameState::GetInstance()->GetCombatantByIndex(current);if(other)ClearFlags0x3bAnd0x3cAndByte0x3a((unsigned char*)other->stats);
  if(!handled){
   if(func_ov000_02155f9c(self,current,0)){src->action=0x1f7;src->targetCount=0;if(IsFlag0x14Bit0x80000Set(unit))unit->stats->flags|=2;}
   else if(special){src->action=0x1f7;src->targetCount=0;if((unsigned char)unit->stats->mode==1){self->mode=IsFlag0x14Bit0x800000Set(unit);ResetTargetFlags02088474(unit->stats,10,0);unit->stats->flags|=2;}}
   else if(IsFlag0x14Bit0x20Set(unit)){src->action=func_ov000_0215f67c(self,current);src->targetCount=0;}
  }
  AppendNode02160068((Obj02160068*)dst,(Node02160068*)entry);self->tableCount++;
 }
 dst->action=src->action;dst->flag=src->flag;
}
