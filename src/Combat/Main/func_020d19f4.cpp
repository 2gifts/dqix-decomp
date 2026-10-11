// JPN: main:020d34c0
union TaskRequest { struct { int (*work)(TaskRequest*); void (*done)(TaskRequest*); int result; unsigned fields[6]; } view; unsigned words[9]; };
struct TaskOwner { unsigned char pad[0xc0]; TaskRequest* request; };
struct BlockedContextList;
void BlockCurrentContext(BlockedContextList*);
void ContextExecutionReturnProc();
int DisableIRQInterrupts();
void SetIRQInterruptState(int);
extern "C" void VectorizedMemset(void*, int, unsigned);
#if defined(jpn)
extern unsigned char data_02112328[];
#define taskState data_02112328
#else
extern unsigned char data_02112328[];
#define taskState data_02112328
#endif
 #pragma optimize_for_size off
#pragma opt_common_subs off
extern "C" void func_020d19f4(TaskOwner* owner) {
 for(;;) {
  TaskRequest local;
  VectorizedMemset(&local,0,sizeof(local));
  int irq=DisableIRQInterrupts();
  if(!owner->request) do { BlockCurrentContext(0); } while(!owner->request);
  local=*owner->request;
  SetIRQInterruptState(irq);
  if(local.view.work) local.view.result=local.view.work(&local);
  irq=DisableIRQInterrupts();
  taskState[0x26]=0;
  if(local.view.done) local.view.done(&local);
  if(!*(unsigned*)taskState) break;
  owner->request=0;
  SetIRQInterruptState(irq);
 }
 ContextExecutionReturnProc();
}

#pragma optimize_for_size reset
#pragma opt_common_subs reset
