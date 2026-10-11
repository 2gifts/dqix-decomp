#include <globaldefs.h>
extern "C" void* VectorizedMemset(void*,int,unsigned);
void CopyFrom027ffcf4(void*);
int DisableIRQInterrupts();
void SetIRQInterruptState(int);
int GetBattleStateCode();
void* GetBattleContext();
int GetBattleContextField0x150();
int GetBattleContextField0x14cLow16();
struct CallbackEvent { unsigned short command,status,code,slot; unsigned a,b; unsigned short c,d; char mac[6]; unsigned short marker; int value; unsigned short field20,field22; char tail[0x20]; };
#pragma optimize_for_size off
// USA: 020d4770; JPN: 020d61cc
extern "C" ARM int func_020d4770(int slot,void (*callback)(CallbackEvent*),int value) {
 CallbackEvent event;
 if(callback) {
  VectorizedMemset(&event,0,sizeof(event));
  event.command=0x82; event.status=0; event.code=0x19; event.slot=slot;
  event.a=0; event.b=0; event.c=0; event.marker=0xffff; event.value=value; event.d=0;
  CopyFrom027ffcf4(event.mac);
 }
 int irq=DisableIRQInterrupts();
 int result=GetBattleStateCode();
 if(result) { SetIRQInterruptState(irq); return result; }
 char* context=(char*)GetBattleContext();
 *(void (**)(CallbackEvent*))(context+0xcc+slot*4)=callback;
 *(int*)(context+0x10c+slot*4)=value;
 if(callback) { event.field22=GetBattleContextField0x14cLow16(); event.field20=GetBattleContextField0x150(); callback(&event); }
 SetIRQInterruptState(irq); return 0;
}

#pragma optimize_for_size reset
