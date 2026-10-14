#include <globaldefs.h>
#include "Combat/MapDisplay.h"
#include "Filesystem/BackgroundLoader.h"


struct List0202fec8;

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

struct Record0204acb0;
void ClearRecordFields(struct Record0204acb0* rec);
void CopyWordAndFlushCache0204ad88(void* a, void* b);
int GetTableEntry0204a5f8(int a, int b);
typedef void (*Callback0204adb4)(void*, int, int);
void CopyWordAndInvokeCallback0204adb4(unsigned char* dst, Callback0204adb4 callback, unsigned char* src);
void Forward0204acd0(struct Record0204acb0* rec);

struct List0204b0e8;
void FlushAndDispatchList0204b0e8(struct List0204b0e8* obj, void* buf);

struct List0204afb4;
void ResetRecordList0204afb4(struct List0204afb4* obj);


// USA: func_02020cb8
ARM void FinalizeRecordListDisplay02020cb8(void* self, MapDisplayTaskHandle handle) {
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    void* recListHead = 0;
    unsigned int val2Ignored = 0;
    void* dummyPtr;
    void* arrayC[3];
    int arrayB[3];
    List0204af64 s;
    unsigned char struct2[0x10];

    loader->GetLoadedFileByID(
#if defined(jpn)
        handle
#else
        *handle
#endif
, &recListHead, &val2Ignored);
    int count = CountActiveEntries((struct ActiveEntry02046900*)recListHead);
    for (int i = 0; i < count; i++) {
        arrayC[i] = FindRecordByIndex((struct Rec020467f0*)recListHead, i, &dummyPtr, &arrayB[i]);
    }

    ResetList0204af64((struct List0204af64*)&s);
    s.b1c_lo = 1;
    s.b1c_hi = 1;
    func_0204b5b4(&s, 3);
    SetWord0x18ClearByte0x1f((unsigned char*)&s, 0);
    DispatchViaTable0204b5e8((struct Obj0204b5e8*)&s, 0, 0);

    s.byteCount = 0x6000;
    s.h0e = 0xfffe;
    unsigned short* tbl = (unsigned short*)((char*)arrayC[2] + 0x10);
    for (int i = 0; i < 0x300; i++) {
        tbl[i] = tbl[i] + 0x300;
    }

    for (int i = 0; i < 2; i++) {
        DispatchByTag0204b2e0(&s, (char*)arrayC[i]);
        DispatchByTagLookup0204b3a0((struct SelfTag0204b3a0*)&s, (char*)arrayC[i]);
    }

    ClearRecordFields((struct Record0204acb0*)struct2);
    CopyWordAndFlushCache0204ad88(struct2, arrayC[2]);
    Callback0204adb4 fn = (Callback0204adb4)GetTableEntry0204a5f8(1, 1);
    CopyWordAndInvokeCallback0204adb4(struct2, fn, (unsigned char*)arrayC[2]);
    Forward0204acd0((struct Record0204acb0*)struct2);

    FlushAndDispatchList0204b0e8((struct List0204b0e8*)&s, 0);
    ResetRecordList0204afb4((struct List0204afb4*)&s);

    BackgroundLoader* finalLoader = BackgroundLoader::GetInstance();
    finalLoader->RemoveTask(
#if defined(jpn)
        handle
#else
        *handle
#endif
);
#if !defined(jpn)
    *handle = -1;
#endif
}
