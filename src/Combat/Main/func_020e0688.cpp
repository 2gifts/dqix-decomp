#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

struct Obj020e0688 {
    unsigned char pad0[0x55c];
    unsigned char flag_55c;
#if defined(jpn)
    unsigned char pad1[0x6bc - 0x55d];
#else
    unsigned char pad1[0x768 - 0x55d];
#endif
    unsigned char flag_768;
    unsigned char pad2[0x9c5 - 0x769];
    unsigned char flag_9c5;
    unsigned char pad3[0xa0c - 0x9c6];
    int handle_a0c;
};

struct FlagWord02046708;
int TestFlags02046708(struct FlagWord02046708* word, unsigned int mask);
void* GetDataPtr02114e04_020d6c00(void);
void ReleaseHandle02022b90(void* owner, int* handle);
void DelayThenSyncBit0(void);

struct ActiveEntry02046900;
int CountActiveEntries(struct ActiveEntry02046900* entry);

struct Rec020467f0;
void* FindRecordByIndex(struct Rec020467f0* rec, int index, void** out, int* out44);

struct List0204af64;
void ResetList0204af64(struct List0204af64* obj);

void SetWord0x18ClearByte0x1f(unsigned char* obj, int value);

extern "C" void func_0204b5b4(void*, int);

struct Obj0204b5e8;
int DispatchViaTable0204b5e8(struct Obj0204b5e8* obj, int a, int b);

void DispatchByTag0204b2e0(void* obj, char* str);

struct SelfTag0204b3a0;
void DispatchByTagLookup0204b3a0(struct SelfTag0204b3a0* self, char* str);

struct List0204b0e8;
void FlushAndDispatchList0204b0e8(struct List0204b0e8* obj, void* buf);

struct List0204afb4;
void ResetRecordList0204afb4(struct List0204afb4* obj);

struct LocalList020e0688 {
    unsigned char pad0[0x1c];
    unsigned char lo : 4;
    unsigned char hi : 4;
    unsigned char pad1d[3];
};

// USA: func_020e0688
extern "C" ARM void func_020e0688(struct Obj020e0688* self) {
    if (self->flag_9c5 == 0) {
        return;
    }

    if (TestFlags02046708((struct FlagWord02046708*)GetDataPtr02114e04_020d6c00(), 0x41)) {
        return;
    }

    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    int status = loader->GetTaskStatus(self->handle_a0c);
    if (status == 0) {
        return;
    }

    if (status == -1) {
        *(volatile unsigned int*)0x04001000 = (*(volatile unsigned int*)0x04001000 & ~0x1f00) | 0x200;
        self->flag_768 = 0;
    } else {
        int recListHead = 0;
        int val2Ignored = 0;
        void* dummyPtr;
        void* arrayC[3];
        int arrayB[3];
        LocalList020e0688 s;

        loader->GetLoadedFileByID(self->handle_a0c, (void**)(&recListHead), (unsigned int*)(&val2Ignored));
        int count = CountActiveEntries((struct ActiveEntry02046900*)recListHead);
        for (int i = 0; i < count; i++) {
            arrayC[i] = FindRecordByIndex((struct Rec020467f0*)recListHead, i, &dummyPtr, &arrayB[i]);
        }

        DelayThenSyncBit0();
        ResetList0204af64((struct List0204af64*)&s);
        s.lo = 1;
        s.hi = 0;
        func_0204b5b4(&s, 2);
        SetWord0x18ClearByte0x1f((unsigned char*)&s, 0);
        DispatchViaTable0204b5e8((struct Obj0204b5e8*)&s, 0, 0);

        for (int i = 0; i < count; i++) {
            DispatchByTag0204b2e0(&s, (char*)arrayC[i]);
            DispatchByTagLookup0204b3a0((struct SelfTag0204b3a0*)&s, (char*)arrayC[i]);
        }

        FlushAndDispatchList0204b0e8((struct List0204b0e8*)&s, 0);
        ResetRecordList0204afb4((struct List0204afb4*)&s);
    }

    ReleaseHandle02022b90(self, &self->handle_a0c);
    self->flag_55c = 1;
    self->flag_9c5 = 0;
}
