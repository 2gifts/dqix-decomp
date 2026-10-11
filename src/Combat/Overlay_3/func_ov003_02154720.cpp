#include <globaldefs.h>
#if defined(jpn)
enum { kClearSize=0x48 };
#else
enum { kClearSize=0x4c };
#endif
struct Cache02154720 { unsigned int flags; unsigned short hp,maxHP,mp,maxMP; unsigned char table,vocation,pad[2]; };
struct Party02154720 { char pad[0xf78]; unsigned char ids[4],count; };
struct Scene02154720 {
 void* p0;void* p4;void* p8;void* pc;void* p10;void* p14;void* p18;void* p1c;void* p20;void* p24;void* p28;
 char init2c[0x54];char selector[0xc];char sub[4];char clear90[0x54];char resetE4[0x18];char resetFc[0x18];char clear114[kClearSize];
 char controller[0x10];unsigned char flag170,flag171;char pad172[2];unsigned int display;
 char zero178[0x18];Cache02154720 cache[4];int task,field1d4,changed;unsigned int scale;
 short field1e0,field1e2,field1e4,element,previous,field1ea,pending,field1ee,field1f0;
 unsigned char ids[4],count,current,state,flag1f9,flag1fa,multiplayer;unsigned int flags;int field200,skip;
 char pad208[0x330-0x208];int field330,field334;unsigned char blocked,reset,started;
};
extern "C" void func_02074af4(void*);
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" Party02154720* _Z17GetPtrField0x2a04P9GameState(void*);
extern "C" void _Z18InitStruct0205a444Pc(void*);
extern "C" void _Z19InitWithSub02081ee4P11Obj02081ee4P11Sub02081ee4(void*,void*);
extern "C" void _Z22Clear0x54Bytes0208247cPv(void*);
extern "C" void _Z19ResetStruct020dfc40P14Struct020dfc40(void*);
extern "C" void _Z20ClearFields_021e20c0Pv(void*);
extern "C" void _Z16ZeroInit020de848Pv(void*);
extern "C" unsigned int _Z18GetField0x3acValueP9GameState(void*);
extern "C" void* memset(void*,int,unsigned int);
extern "C" unsigned int _Z19CopyOutRegion0x571dPcPv(void*,void*);
extern "C" void _Z20ResetFields_0215873cPv(void*);
// JPN: func_ov003_02155e08
// USA: func_ov003_02154720
extern "C" ARM void func_ov003_02154720(void* memory,unsigned char flagIn) {
 unsigned char flag=flagIn;
 Scene02154720* self=(Scene02154720*)memory;
 Party02154720* party;
 unsigned char count;
 int k;
 void* gs;
 int init;
 self->flag170=0;self->flag171=0;func_02074af4(self->controller);
 self->display=(*(volatile unsigned int*)0x04000000&0x1f00)>>8;
 *(volatile unsigned int*)0x04000000=(*(volatile unsigned int*)0x04000000&~0x1f00)|0x100;
 gs=_ZN9GameState11GetInstanceEv();
 party=_Z17GetPtrField0x2a04P9GameState(gs);
 self->p0=0;self->p4=0;self->pc=0;self->p8=0;self->p10=0;self->p14=0;self->p18=0;self->p20=0;self->p24=0;self->p28=0;
 _Z18InitStruct0205a444Pc(self->init2c);
 _Z19InitWithSub02081ee4P11Obj02081ee4P11Sub02081ee4(self->selector,self->sub);
 _Z22Clear0x54Bytes0208247cPv(self->clear90);
 _Z19ResetStruct020dfc40P14Struct020dfc40(self->resetE4);
 _Z19ResetStruct020dfc40P14Struct020dfc40(self->resetFc);
 _Z20ClearFields_021e20c0Pv(self->clear114);
 _Z16ZeroInit020de848Pv(self->zero178);
 self->task=-1;self->field1d4=0;self->changed=0;self->scale=0;
 self->field1e0=-1;self->field1e2=-1;self->field1e4=-1;self->element=-1;self->previous=-1;self->field1ea=-1;self->field1ee=-1;self->pending=self->field1ee;self->field1f0=-1;
 self->current=_Z18GetField0x3acValueP9GameState(gs);
 self->state=0;self->flag1f9=0;self->flag1fa=0;self->multiplayer=0;self->flags=0;self->field200=0;self->skip=0;
 self->field330=0;self->field334=0;self->blocked=0;self->reset=0;self->started=0;
 for(init=0;init<4;init++) { self->ids[init]=0;memset(&self->cache[init],0,4); }
 self->count=_Z19CopyOutRegion0x571dPcPv(gs,self->ids);
 Party02154720* currentParty=_Z17GetPtrField0x2a04P9GameState(gs);
 count=self->count;
 for(int i=0;i<count;i++) {
  int id;
  bool found=false;
  id=(signed char)self->ids[i];
  for(int j=0;j<currentParty->count;j++) if(id==currentParty->ids[j]) found=true;
  if(!found) { self->ids[i]=0xff;self->count--; }
 }
 for(k=0;k<count-1;k++) {
  if(self->ids[k]==0xff) for(int j=k+1;j<count;j++) if(self->ids[j]!=0xff) {self->ids[k]=self->ids[j];self->ids[j]=0xff;break;}
 }
 _Z20ResetFields_0215873cPv(self);
 if(flag) self->flags|=1;
 self->multiplayer=party->count!=1;
}
