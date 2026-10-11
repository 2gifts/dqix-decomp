#include <globaldefs.h>
#if defined(jpn)
enum { kCache=0x18c, kVocation=0x144, kVocationValue=0x8b8, kModelSelection=0x2a, kGlobalFlag=0x17de };
#else
enum { kCache=0x190, kVocation=0x150, kVocationValue=0x950, kModelSelection=0x36, kGlobalFlag=0x19ae };
#endif
struct Status { unsigned int flags; unsigned short hp; unsigned short mp; };
struct Profile { char pad[0x30]; unsigned short hp; unsigned short mp; };
struct Vocation { char pad[kVocationValue]; unsigned int value; };
struct Member { char pad[0x130]; Status* status; Profile* profile; char pad138[kVocation-0x138]; Vocation* vocation;
 unsigned int HP() const { return status->hp; }
 unsigned int MaxHP() const { return profile->hp; }
 unsigned int MP() const { return status->mp; }
 unsigned int MaxMP() const { return profile->mp; }
 unsigned int Voc() const { return vocation->value; }
 unsigned int Flags() const { return status->flags; }
};
struct Cache { unsigned int flags; unsigned short hp, maxHP; unsigned short mp,maxMP; unsigned char table, vocation; char pad[2]; };
struct Model { char pad[kModelSelection]; short selected; };
struct Scene {
 void* vtable; void* controller; short* selection; char padc[0x18-0xc]; Model* model; void* inner;
 char pad20[0x80-0x20]; char selector[0xc]; unsigned short field8c; unsigned char field8e;
 char pad8f[kCache-0x8f]; Cache cache[4]; int task; int field1d0; int changed; unsigned int scale;
 char pad1dc[6]; short element; short previous; short field1e6; short pending, field1ea;
 char pad1ec[8]; unsigned char state, flag; char pad1f6[2]; unsigned int flags; int field1fc; int skip;
 char pad204[0x334-0x204]; unsigned char blocked, reset, started;
};
struct Party { char pad[0xf78]; unsigned char ids[4]; unsigned char count; };
struct Dispatch { unsigned int fn, locator; };
struct Table { Dispatch entries[8]; };
extern short data_ov003_0217f2a8[3];
extern Table data_ov003_0217f340;
extern Dispatch data_020e6d5c;
extern "C" int func_ov017_021959b4();
extern "C" char* _Z26GetGlobalField0x1c020421a0v();
extern "C" void _Z24ReinitController02043204Pc(char*);
extern "C" int _Z24GetInnerFlagBit0020e28dcP13Outer020e28dc(void*);
extern "C" void _Z27ResetSelectionState020e25e8P11Obj020e25e8(void*);
extern "C" void func_ov003_021537d4(void*,unsigned int);
extern "C" void func_ov003_021552b8(Scene*);
extern "C" void _Z35CallFunc0204c87cOverEntries0207fc6cP11Obj0207fc6ci(Model*,unsigned int);
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" Party* _Z17GetPtrField0x2a04P9GameState(void*);
extern "C" Member* _ZN9GameState21GetPartyMemberByIndexEi(void*,int);
extern "C" unsigned int _Z13GetTableValuePv(Member*);
extern "C" int _Z20HasElementByByte0xc4P7Obj2081i(Model*,int);
extern "C" void func_ov003_02158334(Scene*);
extern "C" void func_02081f20(void*,unsigned int);
extern "C" int func_020800fc(Model*,short*,int,unsigned short,unsigned char,int);
extern "C" void _Z24ClearSublistEntriesFlag4Pvi(Model*,int);
extern "C" void func_020813ec(Model*,int);
extern "C" void _Z27UpdateEntryStateAndPositionP11Ctx020e263ci(void*,unsigned int);
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();
extern "C" void _ZN16BackgroundLoader10RemoveTaskEi(void*,int);
// JPN: func_ov003_021561dc
// USA: func_ov003_02154af4
extern "C" ARM int func_ov003_02154af4(Scene* self,unsigned int scale) {
 self->scale=scale;
 if (!self->started && func_ov017_021959b4()) { self->started=1; self->reset=1; }
 if (self->reset && !self->blocked) {
  if(self->selection) *self->selection=-1;
  self->selection=0;
  _Z24ReinitController02043204Pc(_Z26GetGlobalField0x1c020421a0v());
  self->field1ea=-1; self->pending=self->field1ea;
  if(self->inner && _Z24GetInnerFlagBit0020e28dcP13Outer020e28dc(self->inner)) _Z27ResetSelectionState020e25e8P11Obj020e25e8(self->inner);
  self->state=6; self->flag=0; self->reset=0;
 }
 if(!self->skip) func_ov003_021537d4(self->controller,scale);
 if(self->pending>=0) { func_ov003_021552b8(self); return 0; }
 if(self->state) _Z26GetGlobalField0x1c020421a0v()[kGlobalFlag]=0;
 Model* model=self->model;
 if(model) {
  if(!self->skip) _Z35CallFunc0204c87cOverEntries0207fc6cP11Obj0207fc6ci(model,scale);
  int i; Cache* c; Member* member; bool changed; int id; Party* party; void* gs;
  changed=false;
  gs=_ZN9GameState11GetInstanceEv();
  party=_Z17GetPtrField0x2a04P9GameState(gs);
  int count=party->count;
  for(i=0;i<count;i++) {
   id=party->ids[i];
   member=_ZN9GameState21GetPartyMemberByIndexEi(gs,id);
   if(member) {
    c=&self->cache[id];
    unsigned int hp=member->HP();
    unsigned int maxhp,mp,maxmp,voc,flags;
    if(!(c->hp==hp && ((maxhp=member->MaxHP()), c->maxHP==maxhp) && ((mp=member->MP()), c->mp==mp) && ((maxmp=member->MaxMP()), c->maxMP==maxmp) && ((voc=member->Voc()), c->vocation==voc) && c->table==_Z13GetTableValuePv(member) && ((flags=member->Flags()), c->flags==flags))) {
     c->hp=member->status->hp; c->maxHP=member->profile->hp; c->mp=member->status->mp; c->maxMP=member->profile->mp;
     c->vocation=member->vocation->value; c->table=_Z13GetTableValuePv(member); changed=true; c->flags=member->status->flags;
    }
   }
  }
  if(changed) for(int i=0;i<3;i++) if(_Z20HasElementByByte0xc4P7Obj2081i(model,data_ov003_0217f2a8[i])) { func_ov003_02158334(self);break; }
 }
 if(self->selection) {
  func_02081f20(self->selector,scale);
  self->previous=*self->selection;
  self->changed=func_020800fc(model,self->selection,self->previous,self->field8c,self->field8e,(self->flags&4)!=0);
  model->selected=*self->selection;
  if(self->changed) _Z24ClearSublistEntriesFlag4Pvi(model,self->element);
  if(self->previous!=*self->selection) func_020813ec(model,self->element);
 }
 if(self->inner && _Z24GetInnerFlagBit0020e28dcP13Outer020e28dc(self->inner)) _Z27UpdateEntryStateAndPositionP11Ctx020e263ci(self->inner,self->scale);
 Table buf; buf=data_ov003_0217f340;
 unsigned int locator=data_020e6d5c.locator;
 unsigned int fn=data_020e6d5c.fn;
 buf.entries[7].locator=locator; buf.entries[7].fn=fn;
 if(!buf.entries[self->state].fn) {
  _ZN16BackgroundLoader10RemoveTaskEi(_ZN16BackgroundLoader11GetInstanceEv(),self->task);self->task=-1;return 1;
 }
 Dispatch* d=&buf.entries[self->state];
 void* base=(char*)self+((int)d->locator>>1);
 void* callback;
 if(d->locator&1) callback=*(void**)((char*)*(void**)base+d->fn);else callback=(void*)d->fn;
 ((void(*)(void*))callback)(base);
 return 0;
}
