#include <globaldefs.h>
struct Detail { unsigned short first,current,maxFirst,maxCurrent; char p[0x41];unsigned char chance; };
struct Extra { char p[0x10];unsigned int a:19,enabled:1,b:12; };
struct GameObject { char p[0x138];Detail* detail;char q[0xc];Extra* extra; unsigned int Current()const{return detail->current;} unsigned int Maximum()const{return detail->maxCurrent;} };
class GameState {public:static GameState* GetInstance();GameObject* GetCombatantByIndex(int);};
GameObject* GetCombatantWithFlag0x100(GameState*,int);GameObject* GetCombatantWithFlag0x400(GameState*,int);
struct Actor02085c80 {char p[0x29c];unsigned int a:4,mode:5,b:23;char q[0xc];short enabled;};
unsigned char* GetFieldAt0x150(unsigned char*);
float AccumulateSlotBits20To29AsTenths(char*);int AccumulateSlotBits02085c80(Actor02085c80*);
struct Random;int NextRandomMax(Random*,int);float NextRandomFloatBetween(Random*,float,float);
#define IsParty(n) ((n)>=0&&(n)<=3?1:0)
// USA: func_ov000_021573a8
// JPN: func_ov000_021573a8
extern "C" ARM int func_ov000_021573a8(Random* self,int id,int other,int amount){
 if(amount<=0)return 0;
 GameState* gs=GameState::GetInstance();
 GameObject* target=GameState::GetInstance()->GetCombatantByIndex(other);
 if(!target)return 0;
 float result;
 if(IsParty(id)) {
  GameObject* unit=GetCombatantWithFlag0x100(gs,id);if(!unit)return 0;
  Actor02085c80* actor=(Actor02085c80*)GetFieldAt0x150((unsigned char*)unit);if(!actor)return 0;
  if(actor->enabled<=0)return 0;if(actor->mode!=3)return 0;
  {unsigned int maximum=unit->Maximum();unsigned int current=unit->Current();if(current>=maximum)return 0;}
  float chance=(float)(int)target->detail->chance;if(chance<=0)return 0;
  chance/=100.0f;
  float bonus=AccumulateSlotBits20To29AsTenths((char*)actor);
  float bits=(float)AccumulateSlotBits02085c80(actor);
  float scale=(bonus+bits)/100.0f;
  float bound=(float)amount*scale;
  int random=NextRandomMax(self,2);
  float vary=NextRandomFloatBetween(self,0,bound);
  result=1.0f+(float)random;
  result+=chance*vary;
  if(bonus+bits<result)result=bonus+bits;
  unsigned int current=target->detail->current;if((float)current<result)result=(float)current;
 }else {
  GameObject* unit=GetCombatantWithFlag0x400(GameState::GetInstance(),id);if(!unit)return 0;
  if(!unit->extra)return 0;if(!unit->extra->enabled)return 0;
  if(unit->detail->current<0xff&&unit->detail->current>=unit->detail->maxCurrent)return 0;
  int random=NextRandomMax(self,2);
  result=0.1f*(float)amount;
  result+=1.0f+(float)random;
  unsigned int current=target->detail->current;if((float)current<result)result=(float)current;
 }
 return (int)result;
}
