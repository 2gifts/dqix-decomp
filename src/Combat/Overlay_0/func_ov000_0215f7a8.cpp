#include <globaldefs.h>
struct BaseStats {char p[0x34];unsigned short first,second;int First(){int v=first;return v;}int Second(){int v=second;return v;}};
struct Actor {unsigned int zero;unsigned int value:10,rest:22;};
struct GameObject {char p[0x134];BaseStats* base;void* stats;
#if defined(jpn)
char q[8];
#else
char q[20];
#endif
Actor* actor;};
class GameState {public:static GameState* GetInstance();GameObject* GetCombatantByIndex(int);};
GameObject* GetCombatantWithFlag0x100(GameState*,int);
struct Random;Random* GetBTRandom();int NextRandomMax(Random*,int);
struct Info {char p[0xc];int state;};
struct Battle {char p[0x8e18];Info* info;int attempts;int mode;char q[0x25];unsigned char flag;};
struct Ids {short v[8];};
extern "C" {extern const Ids data_ov000_02182b94;extern const int data_ov000_02182c04[];int func_ov000_0215ed34(void*,short*,int);int func_ov000_0215eb1c(void*,short*,int,int);int func_ov000_0215e9fc(void*,short*,int,int);int func_ov000_02155f9c(void*,int,int);}
inline GameObject* GetUnit(int id){GameState* gs=GameState::GetInstance();return gs->GetCombatantByIndex(id);}
inline int StatTotal(BaseStats* s){int second=s->Second();int first=s->First();return first+second;}
// USA: func_ov000_0215f7a8
// JPN: func_ov000_0215f7a8
extern "C" ARM int func_ov000_0215f7a8(Battle* self,short* selected,int count){
 Random* random=GetBTRandom();if(self->info->state>=0)return 0;
 short states[3];int size=func_ov000_0215ed34(self,states,3);short* statePtr=states;for(int i=0;i<size;i++,statePtr++)if((unsigned int)(*statePtr-0x26)<=2)return 0;
 if(self->mode==0&&self->flag==1)return 1;
 int partyTotal=0;int enemyTotal=0;Ids ids(data_ov000_02182b94);short* ptr=ids.v;short n=func_ov000_0215eb1c(self,ptr,8,1);short i=0;
 for(;i<n;i++,ptr++){if(!func_ov000_02155f9c(self,*ptr,0))break;}
 if(i==n)return 1;
 ptr=ids.v;for(i=0;i<n;i++,ptr++){GameObject* unit=GetUnit(*ptr);if(unit)enemyTotal+=StatTotal(unit->base);}
 enemyTotal/=n;
 ptr=ids.v;n=func_ov000_0215e9fc(self,ptr,8,1);
 for(i=0;i<n;i++,ptr++){GameObject* unit=GetUnit(*ptr);if(unit)partyTotal+=StatTotal(unit->base);}
 partyTotal/=n;if(enemyTotal*3<=partyTotal)return 1;
 GameState* gs=GameState::GetInstance();const int* thresholds=data_ov000_02182c04;thresholds++;int chance=0;
 for(int j=0;j<count;j++,selected++){GameObject* unit=GetCombatantWithFlag0x100(gs,*selected);if(unit){int value=10+(int)(0.05f*(float)(unsigned short)unit->actor->value);if(chance<value)chance=value;}}
 if(chance<(thresholds-1)[self->attempts])chance=(thresholds-1)[self->attempts];
 self->attempts++;return NextRandomMax(random,100)<chance;
}
