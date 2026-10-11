#include <globaldefs.h>
struct GameObject { char p[0x17c]; unsigned char group; };
class GameState {public: static GameState* GetInstance();GameObject* GetCombatantByIndex(int);};
struct S_10088;int IsFlag10088Set(S_10088*);
int IsFlag0x18Bit0x2000Set(GameObject*);
GameObject* GetCombatantWithFlag0x400(GameState*,int);
char* GetData02108e10();
struct Random;int NextRandomMax(Random*,int);
struct Action { int p[2]; unsigned int p8:8,side:2,q8:22;int q[2];unsigned int p14:28,type:4;int p18;unsigned int p1c:14,target:5,q1c:13; };
struct Ids { short values[8]; };
extern "C" { extern const Ids data_ov000_02182b34;int func_ov000_0215e9fc(Random*,short*,int,int);int func_ov000_02153e78(Random*,short*,int,int,int);int func_ov000_0215eb1c(Random*,short*,int,int); }
#define IsParty(n) ((n)>=0 && (n)<=3 ? 1 : 0)
// USA: func_ov000_02154c68
// JPN: func_ov000_02154c68
extern "C" ARM int func_ov000_02154c68(Random* self,int id,Action* action){
 if(!action)return -1;
 GameState* gs=GameState::GetInstance();GetData02108e10();
 GameObject* unit=GameState::GetInstance()->GetCombatantByIndex(id);
 if(unit&&!IsFlag10088Set((S_10088*)unit)&&!IsFlag0x18Bit0x2000Set(unit))return id;
 switch(action->target){case 3:case 4:case 5:case 7:case 8:case 11:break;default:return id;}
 int side=action->side;int type=action->type;int group=0;
 if(!IsParty(id)){unit=GetCombatantWithFlag0x400(gs,id);if(!unit)return id;group=unit->group;}
 Ids ids(data_ov000_02182b34);int count;
 if(side==1){
  if(type==4){if(IsParty(id))count=func_ov000_0215e9fc(self,ids.values,8,1);else count=func_ov000_02153e78(self,ids.values,8,group,1);}
  else if(type==3){if(IsParty(id))count=func_ov000_0215e9fc(self,ids.values,8,1);else count=func_ov000_0215eb1c(self,ids.values,8,1);}
  else return id;
 }else if(side==2){
  if(type==4){if(IsParty(id))count=func_ov000_0215e9fc(self,ids.values,8,1);else count=func_ov000_02153e78(self,ids.values,8,group,1);}
  else if(type==3){if(IsParty(id))count=func_ov000_0215e9fc(self,ids.values,8,1);else count=func_ov000_0215eb1c(self,ids.values,8,1);}
  else return id;
 }else return id;
 if(count>0)id=ids.values[NextRandomMax(self,count)];return id;
}
