#include <globaldefs.h>

#if defined(jpn)
#define func_ov013_021878b0 func_ov013_021888c0
#define func_ov013_02187a58 func_ov013_02188a24
#define data_ov013_02187eaf data_ov013_02188e11
#define LOW_REGION(j,u) (j)
#else
#define LOW_REGION(j,u) (u)
#endif
#include "Filesystem/BackgroundLoader.h"



struct List0202fec8;
struct ActiveEntry02046900;
int CountActiveEntries(struct ActiveEntry02046900* entry);
struct Rec020467f0;
void* FindRecordByIndex(struct Rec020467f0* rec, int index, void** out, int* out44);

extern "C" void func_0204c684(void* obj);
extern "C" void func_ov013_02187a58(void* obj, void* buf);
extern "C" void func_0204b174(void* list, void* payload, int a3, int a4);

struct EntryList0204af14;
void* GetEntryByIndexStride0x10(struct EntryList0204af14* list, unsigned int index);
struct Tilemap0204ae44;
void FillTilemapPalette0204ae44(struct Tilemap0204ae44* obj, int palette);
struct Obj0204b988;
#if defined(jpn)
#define DispatchIndexedEntry0204b988 func_0204c7a8
extern "C" void DispatchIndexedEntry0204b988(struct Obj0204b988* obj, unsigned int index, int a3, int a4, unsigned short a5);
#else
void DispatchIndexedEntry0204b988(struct Obj0204b988* obj, unsigned int index, int a3, int a4, unsigned short a5);
#endif
struct List0204b0e8;
void FlushAndDispatchList0204b0e8(struct List0204b0e8* obj, void* buf);

extern int data_ov013_02187eaf;

struct LocalBuf021878b0 {
    char pad0[0x8];
    void* field8;
    char pad10[0xa8 - 0xc];
    unsigned short halfA8;
    unsigned short halfAA;
    char padAC[0xb4 - 0xac];
    unsigned short halfB4;
    unsigned short halfB6;
    char padB8[0xe0 - 0xb8];
};

// USA: func_ov013_021878b0  (semantic: HandleQueuedListEntry021878b0)
extern "C" ARM void func_ov013_021878b0(void* obj) {
    unsigned char* o = (unsigned char*)obj;
    int g = (int)BackgroundLoader::GetInstance();
    unsigned char flag = o[LOW_REGION(0x52,0x66)];

    if (flag == 0) {
#if !defined(jpn)
        for (int i = 0; i < 10; i++) {
            (*(short**)(o + 0x50))[i] = -1;
            (*(short**)(o + 0x54))[i] = -1;
            (*(unsigned char**)(o + 0x58))[i] = 2;
        }
        *(signed char*)(o + 0x6a) = -1;
#endif
        ((BackgroundLoader*)((void*)g))->MaybeFreeAllocations();
        *(int*)(o + LOW_REGION(0x48,0x5c)) = ((BackgroundLoader*)(g))->QueueLoadFile((const char*)((int)&data_ov013_02187eaf), (SafeAllocator*)(0));
        o[LOW_REGION(0x52,0x66)]++;
    } else if (flag == 1) {
        if (((BackgroundLoader*)((void*)g))->GetTaskStatus((int)(*(int*)(o + LOW_REGION(0x48,0x5c)))) != 0) {
            void* recOut;
            int out1, out2;
            int field44;
            ((BackgroundLoader*)((struct List0202fec8*)g))->GetLoadedFileByID((int)(*(int*)(o + LOW_REGION(0x48,0x5c))), (void**)(&out1), (unsigned int*)(&out2));
            CountActiveEntries((struct ActiveEntry02046900*)out1);
            void* end = FindRecordByIndex((struct Rec020467f0*)out1, 0, &recOut, &field44);
            if (end != 0) {
                LocalBuf021878b0 buf;
                func_0204c684(&buf);
                buf.field8 = (char*)end + 0x10;
                buf.halfB4 = 0xa;
                buf.halfB6 = 0xb;
                buf.halfA8 = 0x20;
                buf.halfAA = 0x18;
                func_ov013_02187a58(obj, &buf);
                func_0204b174(o + 0x28, end, 0, field44);
            }
            ((BackgroundLoader*)(g))->RemoveTask((int)(*(int*)(o + LOW_REGION(0x48,0x5c))));
            *(int*)(o + LOW_REGION(0x48,0x5c)) = -1;
            void* e = GetEntryByIndexStride0x10((struct EntryList0204af14*)(o + 0x28), 0);
            if (e != 0) {
                FillTilemapPalette0204ae44((struct Tilemap0204ae44*)e, *(signed char*)(o + LOW_REGION(0x53,0x67)));
            }
            DispatchIndexedEntry0204b988((struct Obj0204b988*)(o + 0x28), 0, 0, 0, 0xffff);
            FlushAndDispatchList0204b0e8((struct List0204b0e8*)(o + 0x28), 0);
            o[LOW_REGION(0x52,0x66)] = 0;
            o[LOW_REGION(0x55,0x69)] &= ~1;
        }
    }
}
