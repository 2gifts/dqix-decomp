#include <globaldefs.h>
struct Stats {char p[0x10];unsigned int p10:10,first:10,second:10,q10:2;unsigned int flags;};
struct GameObject {char p[0x138];Stats* stats;
#if defined(jpn)
char q[8];
#else
char q[20];
#endif
unsigned char* actor;
};
class GameState {public:static GameState* GetInstance();GameObject* GetCombatantByIndex(int);};
GameObject* GetCombatantWithFlag0x100(GameState*,int);
int IsFlag0x18Bit0x800Set(GameObject*);int IsFlag0x18Bit0x40Set(GameObject*);int IsFlag0x14Bit0x40Set(GameObject*);
void ClearFlag0x100000(unsigned char*);void ClearFlag0x200000(unsigned char*);
int TestBit10At0x2f4(unsigned char*);int TestBit11At0x2f4(unsigned char*);
struct Random {char p[0x8e95];unsigned char failure;};int NextRandomMax(Random*,int);float NextRandomFloatBetween(Random*,float,float);
struct Output {char p[0x1c];unsigned char flags;};
struct Work {char p[0xa];unsigned char flags;};
struct Action {unsigned int zero;unsigned int id:12,minimum:10,maximum:10;unsigned int low8:8,side:2,rest8:22;unsigned int c;unsigned int flags;unsigned int base:7,lower:7,upper:7,rest14:11;unsigned int low18:16,mode:2,rest18:9,element:5;};
extern "C" {int func_ov000_02156068(void*,int,int,int);float func_ov000_02156b38(void*,int,int);}
#define IsParty(n) ((n)>=0&&(n)<=3?1:0)
struct Tail {char p[0xe95];unsigned char failure;};
inline void SetFailure(Random* self,int value){((Tail*)((char*)self+0x8000))->failure=value;}
// USA: func_ov000_02156648
// JPN: func_ov000_02156648
extern "C" ARM int func_ov000_02156648(Random* self,int attacker,int target,Output* out,Action* action,Work* work,unsigned char force){
 GameState* gs=GameState::GetInstance();GameObject* unit=GameState::GetInstance()->GetCombatantByIndex(target);
 self->failure=0;
 if(action->id!=0x150){
  if(unit&&IsFlag0x18Bit0x800Set(unit)&&action->side==1){out->flags|=0x40;return 0;}
  if(unit&&IsFlag0x18Bit0x40Set(unit)&&action->side==1){out->flags|=0x20;return 0;}
 }
 if((action->flags&0x40)&&unit){
  if(unit->stats->flags&0x100000){work->flags|=8;out->flags|=8;ClearFlag0x100000((unsigned char*)unit->stats);return 0;}
  if(unit->stats->flags&0x200000){work->flags|=0x10;out->flags|=0x10;ClearFlag0x200000((unsigned char*)unit->stats);return 0;}
 }
 if(force)return 1;
 if(func_ov000_02156068(self,target,0,1)&&!(action->flags&0x1000000))return 0;
 float chance=100.0f;int roll=NextRandomMax(self,100);
 if(IsParty(attacker)){
  GameObject* actor=GetCombatantWithFlag0x100(gs,attacker);if(!actor)return 0;
  if((action->flags&0x40000)&&TestBit10At0x2f4(actor->actor))return 1;
  if((action->flags&0x10000)&&TestBit11At0x2f4(actor->actor)){if(NextRandomMax(self,4)==0)return 0;}
 }
 if(action->mode==1){
  if(IsParty(attacker)){
   GameObject* actor=GetCombatantWithFlag0x100(gs,attacker);if(!actor)return 0;
   unsigned int first=(unsigned short)actor->stats->first;unsigned int second=(unsigned short)actor->stats->second;
   unsigned int selected=0;int useStat=0;
   if(action->flags&0x4000){selected=first;useStat=1;}else if(action->flags&0x8000){selected=second;useStat=1;}
   if(useStat){
    if(selected<=action->minimum)chance=(float)action->lower;
    else if(selected>=action->maximum)chance=(float)action->upper;
    else {unsigned int lower=action->lower;float position=(float)(selected-action->minimum);float delta=(float)(action->upper-lower);float width=(float)(action->maximum-action->minimum);chance=(float)(lower+(int)(position*(delta/width)));}
   }else{float lower=(float)action->lower;float upper=(float)action->upper;chance=(float)(int)NextRandomFloatBetween(self,lower,upper);}
  }else chance=(float)action->base;
  float resistance=func_ov000_02156b38(self,target,action->element);
  if(resistance>0.0f){if(work->flags&1)return 1;if(resistance<1.0f)SetFailure(self,1);if(chance<100.0f)SetFailure(self,1);}
  chance=0.5f+chance*resistance;
 }
 if(action->flags&8){GameObject* actor=GameState::GetInstance()->GetCombatantByIndex(attacker);if(IsFlag0x14Bit0x40Set(actor)){if(NextRandomMax(self,8)<5)return 0;}}
 return roll<(int)chance;
}
