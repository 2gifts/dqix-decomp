#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"
#include "Filesystem/FileIO.h"


struct Obj021dcb70;
unsigned char LookupByField8_021dcb70(struct Obj021dcb70* p);

struct List0202fec8;

struct List0204af64 {
    char pad0[0xc];
    unsigned char b0c;
    unsigned char pad0d;
    unsigned short h0e;
    int w10;
    int w14;
    int w18;
    unsigned char b1c_lo : 4;
    unsigned char b1c_hi : 4;
    unsigned char b1d;
    unsigned char b1e;
    unsigned char b1f;
};
void ResetList0204af64(struct List0204af64* obj);

extern "C" void func_0204b5b4(void*, int);
void SetWord0x18ClearByte0x1f(unsigned char* obj, int value);

struct Obj0204b5e8;
int DispatchViaTable0204b5e8(struct Obj0204b5e8* obj, int a, int b);

struct ActiveEntry02046900;
int CountActiveEntries(struct ActiveEntry02046900* entry);

struct Rec020467f0;
void* FindRecordByIndex(struct Rec020467f0* rec, int index, void** out, int* out44);

void DispatchByTag0204b2e0(void* obj, char* str);

struct SelfTag0204b3a0;
void DispatchByTagLookup0204b3a0(struct SelfTag0204b3a0* self, char* str);

extern "C" int func_ov023_021e20f0(void*, void*, void*, void*);

void ClearFields_021e20c0(void* p);

extern "C" void func_ov023_021dde00(void* obj);
extern "C" void func_ov023_021dbd10(void* obj, void* p);

extern "C" unsigned int GetSubBG0ScreenBase(void);
extern "C" unsigned int GetMainBG2ScreenBase(void);

extern const char* data_ov023_021fda78[];

// JPN: func_ov023_021e047c
// USA: func_ov023_021dfecc  (semantic: ResetAndDispatchListEntries_021dfecc)
extern "C" ARM int func_ov023_021dfecc(void* objRaw) {
#if defined(jpn)
 enum {regionalOffset0=0x6b0, regionalOffset1=0x600, regionalOffset2=0xf8, regionalOffset3=0x6f4, regionalOffset4=0x6d8, regionalOffset5=0xf7, regionalOffset6=0x6dc, regionalOffset7=0x6e4, regionalOffset8=0x6f5, regionalOffset9=0xf0, regionalOffset10=0x6b4};
#else
 enum {regionalOffset0=0x734, regionalOffset1=0x700, regionalOffset2=0x7c, regionalOffset3=0x778, regionalOffset4=0x75c, regionalOffset5=0x7b, regionalOffset6=0x760, regionalOffset7=0x768, regionalOffset8=0x779, regionalOffset9=0x74, regionalOffset10=0x738};
#endif
    unsigned char* obj = (unsigned char*)objRaw;
    struct List0204af64 listObj;
    int listVal1;
    void* recPtr;
    int listVal2;
    int sizeOut;
    void* dummyOut;
    int result;

    int listPtr = (int)BackgroundLoader::GetInstance();
    int handle = *(int*)(obj + regionalOffset0);
    if (((BackgroundLoader*)(listPtr))->GetTaskStatus((int)(handle)) != 0) {
        unsigned char lookupResult = LookupByField8_021dcb70((struct Obj021dcb70*)*(void**)(obj + 0x50));
        ((BackgroundLoader*)((struct List0202fec8*)listPtr))->GetLoadedFileByID((int)(*(int*)(obj + regionalOffset0)), (void**)(&listVal1), (unsigned int*)(&listVal2));

#if defined(jpn)
        if (listVal1 != 0) {
#else
        if (listVal1 != 0 && listVal2 != 0) {
#endif

            ResetList0204af64(&listObj);

            signed char f7c = *(signed char*)(obj + regionalOffset1 + regionalOffset2);
            if (f7c == 1) {
                listObj.b1c_lo = f7c;
                listObj.b1c_hi = 1;
            } else {
                listObj.b1c_lo = f7c;
                listObj.b1c_hi = 3;
            }

            func_0204b5b4(&listObj, 3);
            SetWord0x18ClearByte0x1f((unsigned char*)&listObj, 0);
            DispatchViaTable0204b5e8((struct Obj0204b5e8*)&listObj, 0, 0);

            if (*(signed char*)(obj + regionalOffset1 + regionalOffset2) == 1) {
                volatile unsigned int* reg = (volatile unsigned int*)0x4001000;
                unsigned int bits = 0x12;
                if (lookupResult != 0) bits |= 1;
                *reg = (*reg & ~0x1f00) | (bits << 8);
            }

            if (lookupResult == 0 && *(unsigned char*)(obj + regionalOffset3) != 0) {
                int count = CountActiveEntries((struct ActiveEntry02046900*)listVal1);
                for (unsigned char i = 0; i < count; i++) {
                    recPtr = FindRecordByIndex((struct Rec020467f0*)listVal1, i, &dummyOut, &sizeOut);
                    if (recPtr) {
                        DispatchByTag0204b2e0(&listObj, (char*)recPtr);
                        DispatchByTagLookup0204b3a0((struct SelfTag0204b3a0*)&listObj, (char*)recPtr);
                        func_ov023_021e20f0(obj + 0xcc, obj, recPtr, (void*)sizeOut);
                    }
                }
            } else {
                ClearFields_021e20c0(obj + 0xcc);
                ((SafeAllocator*)obj)->Reset();
                for (unsigned char i = 0; i < 4; i++) {
                    if (FindFilesInNarcBySubstring((const void*)listVal1, data_ov023_021fda78[i],
                            (const void**)&recPtr, (unsigned int*)&sizeOut, 1) != 0) {
                        if (i != 3) {
                            DispatchByTag0204b2e0(&listObj, (char*)recPtr);
                            DispatchByTagLookup0204b3a0((struct SelfTag0204b3a0*)&listObj, (char*)recPtr);
                        } else {
                            func_ov023_021e20f0(obj + 0xcc, obj, recPtr, (void*)sizeOut);
                        }
                    }
                }
            }

            *(int*)(obj + regionalOffset4) = 0x3800;
            if (*(signed char*)(obj + regionalOffset1 + regionalOffset5) == 1) {
                *(int*)(obj + regionalOffset4) = 0x2800;
            }
            *(int*)(obj + regionalOffset6) = 0;
            *(int*)(obj + regionalOffset7) = 0;

            if (*(signed char*)(obj + regionalOffset1 + regionalOffset2) == 1) {
                memset((void*)GetSubBG0ScreenBase(), 0, 0x800);
                if (*(void**)(obj + 0x50) != 0) {
                    func_ov023_021dde00(obj);
                    volatile unsigned int* reg = (volatile unsigned int*)0x4001000;
                    *reg = (*reg & ~0x1f00) | 0x1300;
                }
            } else {
                memset((void*)GetMainBG2ScreenBase(), 0, 0x800);
                if (*(void**)(obj + 0x50) != 0) {
                    func_ov023_021dde00(obj);
                }
            }
            func_ov023_021dbd10(obj + 0xcc, *(void**)(obj + 0x50));
        }

        *(unsigned char*)(obj + regionalOffset8) = lookupResult;
        ((BackgroundLoader*)(listPtr))->RemoveTask((int)(*(int*)(obj + regionalOffset0)));
        *(int*)(obj + regionalOffset0) = -1;
        *(void**)(obj + 0x4c) = *(void**)(obj + 0x50);
        *(void**)(obj + 0x50) = 0;

        unsigned short flags74 = *(unsigned short*)(obj + regionalOffset1 + regionalOffset9);
        if (flags74 & 0x40) {
            if (!(flags74 & 4)) {
                flags74 |= 0x20;
                *(unsigned short*)(obj + regionalOffset1 + regionalOffset9) = flags74;
            }
        }

        for (int i = 0; i < 7; i++) {
            *(int*)(obj + regionalOffset10 + i * 4) = -1;
        }

        flags74 = *(unsigned short*)(obj + regionalOffset1 + regionalOffset9);
        flags74 |= 0x4;
        flags74 |= 0x2000;
        *(unsigned short*)(obj + regionalOffset1 + regionalOffset9) = flags74;

        result = (*(void**)(obj + 0x4c) == 0) ? -1 : 2;
    } else {
        result = 1;
    }
    return result;
}
