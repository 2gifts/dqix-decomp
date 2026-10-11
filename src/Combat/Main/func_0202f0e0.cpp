// JPN: main:0202ec50
#include "GameState/GameState.h"
struct AngleTrig0202e9a4 { unsigned char pad0[0x58]; int angle; unsigned char pad5c[0x194]; int target; unsigned remaining; };
void SetAngleAndTrigTable0202e9a4(AngleTrig0202e9a4*,int);
extern "C" {
#if defined(jpn)
extern unsigned data_02104040;
#define InterpolationCounter data_02104040
#else
extern unsigned data_02104300;
#define InterpolationCounter data_02104300
#endif
void func_0202f0e0(AngleTrig0202e9a4* self) {
 if(!self->remaining) return;
 unsigned elapsed=GameState::GetInstance()->GetEffectiveDeltaTime();
 int angle=self->angle;
 int result;
 if(elapsed>=self->remaining) { self->remaining=0; result=self->target; }
 else {
  float start=(float)angle;
  float difference=(float)(self->target-angle);
  float fraction=(float)elapsed/(float)self->remaining;
  result=(int)(start+difference*fraction);
  self->remaining-=elapsed;
  ++InterpolationCounter;
 }
 SetAngleAndTrigTable0202e9a4(self,result);
}
}
