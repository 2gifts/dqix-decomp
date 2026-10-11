#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"

#if defined(jpn)
enum { kResourceSize=0x7c, kStride=8 };
#else
enum { kResourceSize=0x80, kStride=16 };
#endif
struct List68654 { char pad[0x1c]; unsigned char lo:4; unsigned char hi:4; char tail[3]; };
struct Obj68654 { int unused; void* list; char pad[0xd8]; };
struct Cont68654 { char pad[0x98]; void* list; char gap[0x16]; unsigned char count; char tail[9]; };
struct Scene68654 {
    SafeAllocator alloc[4]; char pad[0x14]; char resource[kResourceSize];
    Cont68654 entries; List68654 lists[2]; Obj68654 objects[3]; char records[0x3c];
    void* fieldA; void* fieldB; char gap[8]; short stride; char gap2[2]; unsigned char flag;
    char gap3[3]; void* dataA; void* dataB; char gap4[4]; int task; void* buffer;
    unsigned char stage; char gap5[3]; unsigned char state; char gap6[0xb7];
    unsigned char active; unsigned char finished;
};
extern "C" {
void func_020dfec0(void*,SafeAllocator*,void*,unsigned int);
void _Z24SetWord0x18ClearByte0x1fPhi(void*,int);
void func_0204b5b4(void*,int);
void _Z30AllocateAndClearBuffer0204b12cP19AllocTarget0204b12cP13SafeAllocator(void*,SafeAllocator*);
void _Z24DispatchViaTable0204b5e8P11Obj0204b5e8ii(void*,int,int);
void ColorEffect_ConfigureAlphaBlend(unsigned int*,unsigned char,unsigned char,unsigned char,int);
int _Z18CountActiveEntriesP19ActiveEntry02046900(void*);
void* _Z17FindRecordByIndexP11Rec020467f0iPPvPi(void*,int,void**,int*);
void func_0204b174(void*,void*,SafeAllocator*,int);
void func_0204bc74(void*,int,int,int,int,int,int);
void _Z28FlushAndDispatchList0204b0e8P12List0204b0e8Pv(void*,void*);
void _Z22AllocateBuffer0204c7a8P11Obj0204c7a8P13SafeAllocatorij(void*,SafeAllocator*,void*,unsigned int);
void _Z29LinkArrayPrevPointers0205cf78P15Struct_0205cf78P13Elem_0205cf78h(void*,void*,unsigned char);
void func_0205a528(void*,void*,int,SafeAllocator*);
}
extern char data_ov003_021800e0[];
extern char data_ov003_021800fb[];
struct Pair68654 { unsigned char v[2]; };
struct Table68654 {
#if defined(jpn)
    Pair68654 mode; Pair68654 hi;
#else
    Pair68654 hi; Pair68654 mode;
#endif
};
extern const Table68654 data_ov003_0217f528;
extern char data_ov003_0218010d[];
extern char data_ov003_02180120[];
#if defined(jpn)
extern char data_ov003_0217e8a0[];
#endif

// JPN: func_ov003_021684dc
// USA: func_ov003_02168654
extern "C" ARM void func_ov003_02168654(Scene68654* self) {
    if (self->stage==0) {
#if defined(jpn)
        self->task=BackgroundLoader::GetInstance()->QueueLoadFile(data_ov003_0217e8a0,0);
#else
        self->task=BackgroundLoader::GetInstance()->QueueLoadFileInGP2(data_ov003_021800e0,data_ov003_021800fb,0);
#endif
        self->stage++;
    } else if (self->stage==1) {
        if (BackgroundLoader::GetInstance()->GetTaskStatus(self->task)!=0) {
            void* data; unsigned int size;
            BackgroundLoader::GetInstance()->GetLoadedFileByID(self->task,&data,&size);
            self->alloc[0].Reset();
            func_020dfec0(self->resource,self->alloc,data,size);
            BackgroundLoader::GetInstance()->RemoveTask(self->task);
            self->task=-1;
            Pair68654 hi=data_ov003_0217f528.hi;
            Pair68654 mode=data_ov003_0217f528.mode;
            List68654* list;
            for (int i=0;i<2;i++) {
                list=self->lists+i;
                _Z24SetWord0x18ClearByte0x1fPhi(list,0);
                int h=hi.v[i]; int m=mode.v[i];
                list->lo=0;
                list->hi=h;
                func_0204b5b4(list,m);
                _Z30AllocateAndClearBuffer0204b12cP19AllocTarget0204b12cP13SafeAllocator(list,self->alloc+1);
                _Z24DispatchViaTable0204b5e8P11Obj0204b5e8ii(list,0,0);
            }
            *(volatile unsigned short*)0x400000a=(*(volatile unsigned short*)0x400000a&0x43)|0x1d00;
            *(volatile unsigned short*)0x400000c=(*(volatile unsigned short*)0x400000c&0x43)|0x1e00;
            ColorEffect_ConfigureAlphaBlend((unsigned int*)0x4000050,2,1,10,6);
            self->task=BackgroundLoader::GetInstance()->QueueLoadFile(data_ov003_0218010d,0);
            self->stage++;
        }
    } else if (self->stage==2) {
        BackgroundLoader* loader=BackgroundLoader::GetInstance();
        if (loader->GetTaskStatus(self->task)!=0) {
            void* out; void* data; unsigned int size; void* records[2]; int values[2];
            loader->GetLoadedFileByID(self->task,&data,&size);
            int count=_Z18CountActiveEntriesP19ActiveEntry02046900(data);
            for (int i=0;i<count;i++) records[i]=_Z17FindRecordByIndexP11Rec020467f0iPPvPi(data,i,&out,values+i);
            for (int i=0;i<count;i++) {
                if (records[i]) {
                    func_0204b174(self->lists+1,records[i],self->alloc+1,values[i]);
                    func_0204b174(self->objects,records[i],self->alloc+1,values[i]);
                }
            }
            loader->RemoveTask(self->task);
            self->task=-1;
            List68654* list;
            for (int i=0;i<2;i++) {
                list=self->lists+i;
                func_0204bc74(list,0,0,0,0x20,0x19,0);
                _Z28FlushAndDispatchList0204b0e8P12List0204b0e8Pv(list,0);
            }
            self->alloc[2].Reset();
            self->buffer=self->alloc[2].Allocate(0x4000);
            Obj68654* obj;
            for (int i=0;i<3;i++) {
                obj=self->objects+i;
                _Z22AllocateBuffer0204c7a8P11Obj0204c7a8P13SafeAllocatorij(obj,self->alloc+1,self->buffer,0x400);
                obj->list=self->lists+1;
            }
            self->entries.list=self->lists;
            self->entries.count=2;
            _Z29LinkArrayPrevPointers0205cf78P15Struct_0205cf78P13Elem_0205cf78h(&self->entries,self->objects,3);
            self->stage++;
        }
    } else if (self->stage==3) {
        self->flag=0;
        self->fieldB=self->dataA;
        self->stride=kStride;
        self->fieldA=self->dataB;
        self->task=BackgroundLoader::GetInstance()->QueueLoadFile(data_ov003_02180120,0);
        self->stage++;
    } else if (self->stage==4) {
        BackgroundLoader* loader=BackgroundLoader::GetInstance();
        if (loader->GetTaskStatus(self->task)!=0) {
            void* out; void* data; unsigned int size; int value;
            loader->GetLoadedFileByID(self->task,&data,&size);
            int count=_Z18CountActiveEntriesP19ActiveEntry02046900(data);
            self->alloc[3].Reset();
            for (int i=0;i<count;i++) {
                void* record=_Z17FindRecordByIndexP11Rec020467f0iPPvPi(data,i,&out,&value);
                func_0205a528(self->records,record,value,self->alloc+3);
            }
            loader->RemoveTask(self->task);
            self->task=-1;
            self->stage++;
        }
    } else if (self->stage==5) {
        *(volatile unsigned short*)0x4000008=(*(volatile unsigned short*)0x4000008&~3)|2;
        *(volatile unsigned short*)0x400000a=(*(volatile unsigned short*)0x400000a&~3)|1;
        *(volatile unsigned short*)0x400000c&=~3;
        *(volatile unsigned short*)0x400000e=(*(volatile unsigned short*)0x400000e&~3)|3;
        *(volatile unsigned int*)0x4000000=(*(volatile unsigned int*)0x4000000&~0x1f00)|0x1700;
        self->state=1;
        self->stage=0;
        self->active=1;
        self->finished=0;
    }
}
