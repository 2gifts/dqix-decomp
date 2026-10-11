#include <globaldefs.h>
#if defined(jpn)
enum { kModel=0x20c, kFlags=0x28c, kFirst=0x2e5, kSelection=0x2a, kWidth=20 };
#else
enum { kModel=0x324, kFlags=0x464, kFirst=0x4bd, kSelection=0x36, kWidth=21 };
#endif
struct MenuModel02166fc4 { char pad[kSelection]; short selected; short GetSelected() const { return selected; } };
struct MenuBackground02166fc4 { char pad[0x40]; char buffer[1]; };
struct Menu02166fc4 {
 char pad[kModel]; MenuModel02166fc4* model; MenuBackground02166fc4* background;
 char padFlags[kFlags-kModel-8]; unsigned int flags;
 char padFirst[kFirst-kFlags-4]; unsigned char first;
};
extern "C" void _Z19ClearBuffer0204b010P11Obj0204b010Pv(void*,void*);
extern "C" void func_0204bc74(void*,int,int,int,int,int,int);
extern "C" void _Z21DispatchEntry0204b8d0P11Obj0204b8d0jiisssst(void*,unsigned int,int,int,short,short,short,short,unsigned short);
extern "C" void func_0204b04c(void*,int);
// JPN: func_ov003_02166ea4
// USA: func_ov003_02166fc4
extern "C" ARM void func_ov003_02166fc4(Menu02166fc4* self) {
 MenuBackground02166fc4* bg=self->background;
 if((self->flags&0x80000) || (self->flags&0x100000) || (self->flags&0x200000) || (self->flags&0x800000)) {
  _Z19ClearBuffer0204b010P11Obj0204b010Pv(bg->buffer,0);
  if(self->flags&0x80000) {
   func_0204bc74(bg->buffer,0,0,0,32,25,0);
   self->flags|=0x40000;self->flags&=~0x80000;
  }
  if(self->flags&0x100000) {
   _Z21DispatchEntry0204b8d0P11Obj0204b8d0jiisssst(bg->buffer,0,0,0,0,0,32,12,0xffff);
   self->flags|=0x40000;self->flags&=~0x100000;
  }
  if(self->flags&0x200000) {
   _Z21DispatchEntry0204b8d0P11Obj0204b8d0jiisssst(bg->buffer,1,0,0,11,0,kWidth,2,0xffff);
   self->flags|=0x40000;self->flags&=~0x200000;
  }
  if(self->flags&0x400000) {
   short selected=self->model->GetSelected();
   short delta=selected-self->first;
   short y=(delta%4)*2+2;
   _Z21DispatchEntry0204b8d0P11Obj0204b8d0jiisssst(bg->buffer,2,0,0,2,y,28,2,0xffff);
   self->flags|=0x40000;self->flags&=~0x400000;
  }
  if(self->flags&0x800000) {
   _Z21DispatchEntry0204b8d0P11Obj0204b8d0jiisssst(bg->buffer,3,0,0,3,10,1,2,0xffff);
   _Z21DispatchEntry0204b8d0P11Obj0204b8d0jiisssst(bg->buffer,4,0,0,28,10,1,2,0xffff);
   self->flags|=0x40000;self->flags&=~0x800000;
  }
  if(self->flags&0x40000) func_0204b04c(bg->buffer,0);
 }
}
