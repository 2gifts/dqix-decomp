// JPN: main:020cef60
struct DeferredNode { DeferredNode* next; void (*callback)(void*); void* argument; };
struct AddressRange { unsigned unknown, base, length, extra; };
extern DeferredNode* data_020f33b0;
int DisableIRQInterrupts();
void SetIRQInterruptState(int);
#pragma optimize_for_size off
extern "C" void func_020cd494(AddressRange* range) {
 for(;;) {
  DeferredNode* first=0;
  DeferredNode* last=0;
  unsigned base=range->base;
  unsigned end=base+(range->length+range->extra);
  int irq=DisableIRQInterrupts();
  DeferredNode* previous;
  DeferredNode* head;
  DeferredNode* current;
  head=data_020f33b0;
  current=head;
  previous=0;
  if(current) do {
   DeferredNode* next;
   void* argument=current->argument;
   next=current->next;
   unsigned callback=(unsigned)current->callback;
   if((!argument && callback>=base && callback<end) || ((unsigned)argument>=base && (unsigned)argument<end)) {
    if(last) last->next=current; else first=current;
    if(head==current) { data_020f33b0=next; head=next; }
    current->next=0;
    last=current;
    if(previous) previous->next=next;
   } else previous=current;
   current=next;
  } while(current);
  SetIRQInterruptState(irq);
  if(!first) return;
  do {
   DeferredNode* next=first->next;
   if(first->callback) first->callback(first->argument);
   first=next;
  } while(first);
 }
}

#pragma optimize_for_size reset
