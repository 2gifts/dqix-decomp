#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"

struct List6759c { char pad[0x1c]; unsigned char lo:4; unsigned char hi:4; char tail[3]; };
struct Obj6759c { int unused; void* list; char pad[0xd8]; };
struct Manager6759c {
#if defined(jpn)
    char pad[0x20];
#else
    char pad[0x2c];
#endif
    void* list; char gap[8]; unsigned char active; char gap2; unsigned char flag;
};
struct View6759c {
    int value; SafeAllocator* alloc; List6759c* lists; Obj6759c* objects; Manager6759c* manager;
#if defined(jpn)
    char pad[0x34-0x14];
#else
    char pad[0x64-0x14];
#endif
    int task; char pad2[8]; int selected; unsigned char ready; unsigned char stage; signed char pending;
};
struct Entry6759c { char pad[8]; unsigned int size; void* data; };
extern "C" {
void* __clear(void*, int);
void _Z17ResetList0204af64P12List0204af64(void*);
void _Z24SetWord0x18ClearByte0x1fPhi(void*, int);
void func_0204b5b4(void*, int);
void _Z30AllocateAndClearBuffer0204b12cP19AllocTarget0204b12cP13SafeAllocator(void*,SafeAllocator*);
void _Z24DispatchViaTable0204b5e8P11Obj0204b5e8ii(void*,int,int);
void _Z21AllocateArray0204af38P11Foo0204af38iP13SafeAllocator(void*,int,SafeAllocator*);
void DisableSubBGVRAMBanks();
void MapVRAMBanksToSubBG(int);
int _Z18CountActiveEntriesP19ActiveEntry02046900(void*);
void* _Z17FindRecordByIndexP11Rec020467f0iPPvPi(void*,int,void**,int*);
void func_0204b174(void*,void*,SafeAllocator*,int);
void func_0204bc74(void*,int,int,int,int,int,int);
void _Z28FlushAndDispatchList0204b0e8P12List0204b0e8Pv(void*,void*);
Entry6759c* _Z25GetEntryByIndexStride0x10P17EntryList0204af14j(void*,unsigned int);
void _Z25CleanInvalidateCacheRangePKvj(const void*,unsigned int);
void LoadToSubBG1ScreenData(void*,int,unsigned int);
void func_0204c684(void*);
void _Z22AllocateBuffer0204c7a8P11Obj0204c7a8P13SafeAllocatorij(void*,SafeAllocator*,int,unsigned int);
void func_0207f84c(void*);
#if defined(jpn)
void func_02080654(void*,SafeAllocator*,const char*);
#else
void _Z35SetFieldsFromFormattedValue0207f914P11Obj0207f914iii(void*,SafeAllocator*,const char*,const char*);
#endif
int func_0207f9f4(void*);
void LoadToSubBGStandardPalette(const void*,unsigned int,unsigned int);
void _Z15CleanCacheRangePKvj(const void*,unsigned int);
void _Z21InitNodeChain0207f7f0P15Manager0207f7f0P12Node0207f7f0i(void*,void*,int);
void _Z28CallFunc0204c804OverAllElemsP12Cont0207fe44(void*);
void func_ov003_02167a5c(void*,int,int);
}
extern char data_ov003_021800a4[];
extern char data_ov003_021800bb[];
extern char data_ov003_021800d5[];
extern unsigned short data_ov003_0217f4dc[];
#if defined(jpn)
extern char data_ov003_0217e87f[];
#endif

// JPN: func_ov003_0216747c
// USA: func_ov003_0216759c
extern "C" ARM int func_ov003_0216759c(View6759c* self) {
    if (self->ready != 0) return 1;
    int result = 1;
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    if (self->stage == 0) {
        *(volatile unsigned int*)0x4001010 = 0;
        *(volatile unsigned int*)0x4001014 = 0;
        SafeAllocator* alloc = self->alloc;
        alloc->Reset();
        self->lists = (List6759c*)alloc->Allocate(0x40);
        int words[2];
        __clear(words, sizeof(words));
        List6759c* list;
        for (int i=0; i<2; i++) {
            list = self->lists+i;
            _Z17ResetList0204af64P12List0204af64(list);
            _Z24SetWord0x18ClearByte0x1fPhi(list, words[i]);
            list->lo=1;
            list->hi=i;
            func_0204b5b4(list,i);
            _Z30AllocateAndClearBuffer0204b12cP19AllocTarget0204b12cP13SafeAllocator(list,alloc);
            _Z24DispatchViaTable0204b5e8P11Obj0204b5e8ii(list,0,0);
        }
        _Z21AllocateArray0204af38P11Foo0204af38iP13SafeAllocator(self->lists+1,1,alloc);
        DisableSubBGVRAMBanks();
        MapVRAMBanksToSubBG(0x80);
        *(volatile unsigned short*)0x4001008 = (*(volatile unsigned short*)0x4001008 & 0x43) | 0xe00;
        *(volatile unsigned short*)0x400100a = (*(volatile unsigned short*)0x400100a & 0x43) | 0xf00;
        *(volatile unsigned short*)0x4001050 = 0;
        loader->MaybeFreeAllocations();
        self->task = loader->QueueLoadFile(data_ov003_021800a4,0);
        self->stage++;
        result=0;
    } else if (self->stage == 1) {
        if (loader->GetTaskStatus(self->task) != 0) {
            void* out; void* data; unsigned int size; int value;
            loader->GetLoadedFileByID(self->task,&data,&size);
            int count = _Z18CountActiveEntriesP19ActiveEntry02046900(data);
            SafeAllocator* alloc=self->alloc;
            List6759c* list=self->lists;
            for (int i=0;i<count;i++) {
                void* record=_Z17FindRecordByIndexP11Rec020467f0iPPvPi(data,i,&out,&value);
                if (record) {
                    func_0204b174(list,record,alloc,value);
                    list=self->lists+1;
                }
            }
            loader->RemoveTask(self->task);
            self->task=-1;
            list=self->lists;
            func_0204bc74(list,0,0,0,0x20,0x19,0);
            _Z28FlushAndDispatchList0204b0e8P12List0204b0e8Pv(list,0);
            Entry6759c* entry=_Z25GetEntryByIndexStride0x10P17EntryList0204af14j(self->lists+1,0);
            if (entry) {
                void* data; unsigned int size=entry->size; data=entry->data;
                _Z25CleanInvalidateCacheRangePKvj(data,size);
                LoadToSubBG1ScreenData(data,0,size);
            }
            alloc=self->alloc;
            alloc[1].Reset();
            self->objects=(Obj6759c*)alloc[1].Allocate(0x380);
            for (result=0;result<4;result++) {
                Obj6759c* obj=self->objects+result;
                func_0204c684(obj);
                _Z22AllocateBuffer0204c7a8P11Obj0204c7a8P13SafeAllocatorij(obj,alloc+1,self->value,0x600);
                obj->list=self->lists;
            }
            self->stage++;
        }
        result=0;
    } else if (self->stage == 2) {
        SafeAllocator* alloc=self->alloc;
        alloc[2].Reset();
#if defined(jpn)
        self->manager=(Manager6759c*)alloc[2].Allocate(0x34);
#else
        self->manager=(Manager6759c*)alloc[2].Allocate(0x40);
#endif
        func_0207f84c(self->manager);
#if defined(jpn)
        func_02080654(self->manager,alloc+2,data_ov003_0217e87f);
#else
        _Z35SetFieldsFromFormattedValue0207f914P11Obj0207f914iii(self->manager,alloc+2,data_ov003_021800bb,data_ov003_021800d5);
#endif
        self->stage++;
        result=0;
    } else if (self->stage == 3) {
        int status=func_0207f9f4(self->manager);
        if (status==0) self->stage++;
        if (status<0) self->ready=2;
        result=0;
    } else if (self->stage == 4) {
        *(volatile unsigned short*)0x4001008 &= ~3;
        *(volatile unsigned short*)0x400100a = (*(volatile unsigned short*)0x400100a & ~3) | 1;
        *(volatile unsigned short*)0x400100c = (*(volatile unsigned short*)0x400100c & ~3) | 2;
        *(volatile unsigned short*)0x400100e = (*(volatile unsigned short*)0x400100e & ~3) | 3;
        *(volatile unsigned int*)0x4001000 = (*(volatile unsigned int*)0x4001000 & ~0x1f00) | 0x1300;
        _Z25CleanInvalidateCacheRangePKvj(data_ov003_0217f4dc,2);
        LoadToSubBGStandardPalette(data_ov003_0217f4dc,2,2);
        _Z15CleanCacheRangePKvj(data_ov003_0217f4dc,2);
        _Z25CleanInvalidateCacheRangePKvj(data_ov003_0217f4dc,2);
        LoadToSubBGStandardPalette(data_ov003_0217f4dc,0x22,2);
        _Z15CleanCacheRangePKvj(data_ov003_0217f4dc,2);
        _Z21InitNodeChain0207f7f0P15Manager0207f7f0P12Node0207f7f0i(self->manager,self->objects,4);
        Manager6759c* manager=self->manager;
        manager->list=self->lists;
        manager->active=1;
        self->manager->flag=0;
        self->ready=1;
        self->stage=0;
        if (self->selected != 0 && self->pending>=0) {
            _Z28CallFunc0204c804OverAllElemsP12Cont0207fe44(self->manager);
            signed char index=self->pending;
            self->pending=-1;
            func_ov003_02167a5c(self,self->selected,index);
        }
    }
    return result;
}
