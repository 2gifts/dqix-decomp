#include <globaldefs.h>
struct Slot {char p[0xc];short hp;char q[2];signed char states[8],index;char r[0xb];unsigned char flags;char s[0x27];int id;
#if defined(jpn)
char t[0x424];
#else
char t[0x3e4];
#endif
float phase;};
struct Stats {char p[0x3b];unsigned char low:3,active:1,mode:4;};
struct GameObject {char p[0x138];Stats* stats;};
class GameState {public:static GameState* GetInstance();GameObject* GetCombatantByIndex(int);};
struct World {
#if defined(jpn)
char p[0x3508];
#else
char p[0x3718];
#endif
void* battle;};
struct Combat {char p[0x17c];int id;};
int HasAnyFlags_021719f8_021719f8(int*);int GetWord0x0(int*);void* GetOffsetPtr02160f08(void*);void NotifyIfActive_02170078(char*);
struct Position {int x,y,z;};extern int data_ov000_02183ff0;extern Position data_ov000_02184288;
extern "C" {void* func_ov017_021b8468(void*);int func_ov000_0217ae90(void*);int func_ov000_0217b380(void*,int,int);int func_ov000_0217b518(void*,int,int);int func_ov000_0217b6d0(void*,int,int);int func_ov000_0217b8a4(void*,int,int);int func_ov000_0217bb2c(void*,int,int);int func_ov000_0217bdf4(void*,int,int);int func_ov000_0217bfbc(void*,int,int);int func_ov000_0217c094(void*);}
// USA: func_ov000_021700dc
// JPN: func_ov000_021700dc
extern "C" ARM int func_ov000_021700dc(Slot* self){
 if(self->id<0)return -1;if(!(self->flags&1))return -1;if(self->hp==0)return -1;
 if(HasAnyFlags_021719f8_021719f8((int*)self)){self->states[self->index]=100;return 100;}
 GameState* gs=GameState::GetInstance();World* world=(World*)GetWord0x0((int*)gs);if(!world)return -1;
 void* battle=world->battle;if(!battle)return -1;battle=func_ov017_021b8468(battle);if(!battle)return -1;Combat* combat=(Combat*)GetOffsetPtr02160f08(battle);if(!combat)return -1;
 GameObject* unit=gs->GetCombatantByIndex(combat->id);
 if(unit&&unit->stats->active){if(unit->stats->mode==1)self->phase+=0.2f;else self->phase+=0.05f;if(self->phase>=3.141592f)self->phase=0.0f;}
 NotifyIfActive_02170078((char*)self);
 switch(self->states[self->index]){
 case 13:return func_ov000_0217ae90(self);
 case 14:return func_ov000_0217b380(self,data_ov000_02183ff0,data_ov000_02184288.y);
 case 15:return func_ov000_0217b518(self,data_ov000_02183ff0,data_ov000_02184288.y);
 case 16:return func_ov000_0217b6d0(self,data_ov000_02183ff0,data_ov000_02184288.y);
 case 17:return func_ov000_0217b8a4(self,data_ov000_02183ff0,data_ov000_02184288.y);
 case 18:case 19:case 20:return func_ov000_0217bb2c(self,data_ov000_02183ff0,data_ov000_02184288.y);
 case 21:return func_ov000_0217bdf4(self,data_ov000_02183ff0,data_ov000_02184288.y);
 case 26:return func_ov000_0217bfbc(self,data_ov000_02183ff0,data_ov000_02184288.y);
 case 27:return func_ov000_0217bfbc(self,data_ov000_02183ff0,data_ov000_02184288.y);
 case 28:return func_ov000_0217bfbc(self,data_ov000_02183ff0,data_ov000_02184288.y);
 case 29:return func_ov000_0217bfbc(self,data_ov000_02183ff0,data_ov000_02184288.y);
 case 30:return func_ov000_0217bfbc(self,data_ov000_02183ff0,data_ov000_02184288.y);
 case 37:return func_ov000_0217bfbc(self,data_ov000_02183ff0,data_ov000_02184288.y);
 case 38:return func_ov000_0217bfbc(self,data_ov000_02183ff0,data_ov000_02184288.y);
 case 39:return func_ov000_0217bfbc(self,data_ov000_02183ff0,data_ov000_02184288.y);
 case 40:return func_ov000_0217bfbc(self,data_ov000_02183ff0,data_ov000_02184288.y);
 case 100:return func_ov000_0217c094(self);
 default:return -1;
 }
}
