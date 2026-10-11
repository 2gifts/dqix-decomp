#include <globaldefs.h>
struct SlotObj020bc454; struct Node020bc5bc; struct Obj020bc4f8; struct Outer020bc16c; struct Obj020bc1ac; struct Foo;
void* AcquireOrEvictSlotAndLink020bc454(SlotObj020bc454*,int,int);
int PopSlotFirstAndLink020bc5bc(int,Node020bc5bc*);
extern "C" int func_020bded0(int,int,int,int,int*);
void CallFunc020bc79c_020bc4ec(void*);
void HandleCommandType2Event020bc4f8(Obj020bc4f8*,int,int,int);
void SetInnerByte0x40(Outer020bc16c*,unsigned char);
void CallFunc020d1e88OnNodeField3c(Obj020bc1ac*,int);
extern "C" void _Z15SetActionParamsP3Fooss(Foo*,int,int);
struct LoadOptions { int value; short pad; unsigned char mode,kind; };
#pragma optimize_for_size off
// USA: 020be924; JPN: 020c03f0
extern "C" ARM int func_020be924(void* object,int slot,int key,int count,LoadOptions* options,char* data,int a,int b) {
 void* node=AcquireOrEvictSlotAndLink020bc454((SlotObj020bc454*)object,slot,count);
 if(!node) return 0;
 int item=PopSlotFirstAndLink020bc5bc(slot,(Node020bc5bc*)node);
 int result;
 if(func_020bded0(key,6,item,0,&result)) { CallFunc020bc79c_020bc4ec(node); return 0; }
 HandleCommandType2Event020bc4f8((Obj020bc4f8*)node,(int)(data+*(int*)(data+0x18)),options->value,result);
 SetInnerByte0x40((Outer020bc16c*)object,options->mode);
 CallFunc020d1e88OnNodeField3c((Obj020bc1ac*)object,options->kind);
 _Z15SetActionParamsP3Fooss((Foo*)object,a,b);
 return 1;
}

#pragma optimize_for_size reset
