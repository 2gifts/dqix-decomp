#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/AllocatorUnion.h"
#include "Memory/SafeAllocator.h"
#include "GameState/GameState.h"

int GetWord0x0(int* obj);

int DispatchByMode77c_021ddbb8(void* obj, int a, int b);
struct Obj021ddbf8;
int Check_021ddbf8(struct Obj021ddbf8* obj);
void OrGlobalFlag0x40(void);
int GetGlobal02109400(void);
extern "C" void _Z21BlankFunction02094b30v(int, int, int);
int AlwaysTrue02094b4c(void);

struct SubBgControlBackup02074b64;
void BackupSubBgControlRegisters(struct SubBgControlBackup02074b64* obj);
extern "C" void func_02074af4(void* p);

struct List0202fec8;
struct ActiveEntry02046900;
int CountActiveEntries(struct ActiveEntry02046900* entry);
struct Rec020467f0;
void* FindRecordByIndex(struct Rec020467f0* rec, int index, void** out, int* out44);
extern "C" void func_0205a528(void* a, void* ptr, int val, void* d);
extern "C" void func_020dfec0(void* dest, void* allocator, void* fileData, unsigned int size);

void ConfigureBgSub1AndClear_021dcc58(void* obj);
ARM void ResetIfNonNeg_021db2e4(volatile int* p);

void* AllocateAligned4(AllocatorUnion* alloc, unsigned int size);
extern AllocatorUnion data_02114e20;

#if defined(jpn)
struct DataStruct_021dd59c { unsigned int pad0[5]; void* field4; };
#else
struct DataStruct_021dd59c { unsigned int pad0; void* field4; };
#endif

extern struct DataStruct_021dd59c data_ov023_021ff9e0;

extern int data_ov023_021fdb40;
extern int data_ov023_021fdb52;
extern int data_ov023_021fdb60;
extern int data_ov023_021fdb72;
extern int data_ov023_021fdb80;
extern int data_ov023_021fdb99;

#if defined(jpn)
extern char data_ov023_021fce2d[];
extern char data_ov023_021fce42[];
#endif
// JPN: func_ov023_021ddd7c
// USA: func_ov023_021dd59c  (semantic: UpdateCombatOverlayState_021dd59c)
extern "C" ARM void func_ov023_021dd59c(void* objRaw) {
#if defined(jpn)
 enum {regionalOffset0=0x6f3, regionalOffset1=0x6f0, regionalOffset2=0x6f7, regionalOffset3=0x6f8, regionalOffset4=0x178, regionalOffset5=0x168, regionalOffset6=0x17c, regionalOffset7=0x174, regionalOffset8=0x6b0, regionalOffset9=0x128, regionalOffset10=0x6f9, regionalOffset11=0x6ac, regionalOffset12=0x6f2, regionalOffset13=0x6b4, regionalOffset14=0x6d0, backgroundBackupOffset=0x114};
#else
 enum {regionalOffset0=0x777, regionalOffset1=0x774, regionalOffset2=0x77b, regionalOffset3=0x77c, regionalOffset4=0x17c, regionalOffset5=0x16c, regionalOffset6=0x180, regionalOffset7=0x178, regionalOffset8=0x734, regionalOffset9=0x12c, regionalOffset10=0x77d, regionalOffset11=0x730, regionalOffset12=0x776, regionalOffset13=0x738, regionalOffset14=0x754, backgroundBackupOffset=0x118};
#endif
    char* obj = (char*)objRaw;
    int dataResult = (int)BackgroundLoader::GetInstance();
    GetWord0x0((int*)GameState::GetInstance());

    if (*(unsigned char*)(obj + regionalOffset0) == 0) {
        if (data_ov023_021ff9e0.field4 == 0) {
            data_ov023_021ff9e0.field4 = AllocateAligned4(&data_02114e20, 0x1800);
        }
        if (!(*(unsigned short*)(obj + regionalOffset1) & 0x40)) {
            *(unsigned char*)(obj + regionalOffset0) = 2;
            return;
        }
        if (*(signed char*)(obj + regionalOffset2) != 1) {
            DispatchByMode77c_021ddbb8(obj, ~0xf, 8);
        }
        *(unsigned char*)(obj + regionalOffset0) = *(unsigned char*)(obj + regionalOffset0) + 1;
    }

    if (*(unsigned char*)(obj + regionalOffset0) == 1) {
        if (Check_021ddbf8((struct Obj021ddbf8*)obj) == 0) {
            if (*(signed char*)(obj + regionalOffset2) != 1) {
                OrGlobalFlag0x40();
            }
            *(unsigned char*)(obj + regionalOffset0) = *(unsigned char*)(obj + regionalOffset0) + 1;
        }
    }

    if (*(unsigned char*)(obj + regionalOffset0) == 2) {
        if (*(unsigned short*)(obj + regionalOffset1) & 0x10) {
            *(unsigned char*)(obj + regionalOffset0) = 4;
            return;
        }
        int g = GetGlobal02109400();
        _Z21BlankFunction02094b30v(g, 0x1fa, 0);
        *(unsigned char*)(obj + regionalOffset0) = *(unsigned char*)(obj + regionalOffset0) + 1;
    } else if (*(unsigned char*)(obj + regionalOffset0) == 3) {
        GetGlobal02109400();
        if (AlwaysTrue02094b4c() != 0) {
            *(unsigned char*)(obj + regionalOffset0) = *(unsigned char*)(obj + regionalOffset0) + 1;
        }
    }

    if (*(unsigned char*)(obj + regionalOffset0) == 4) {
        if (*(signed char*)(obj + regionalOffset3) == 1) {
            BackupSubBgControlRegisters((struct SubBgControlBackup02074b64*)(obj + backgroundBackupOffset));
        } else {
            func_02074af4(obj + backgroundBackupOffset);
        }
        *(char*)(obj + regionalOffset4) = *(signed char*)(obj + regionalOffset3);
        *(void**)(obj + regionalOffset5) = obj + regionalOffset6;
        *(short*)(obj + regionalOffset7) = 30;
#if defined(jpn)
        *(int*)(obj + regionalOffset8) = ((BackgroundLoader*)(dataResult))->QueueLoadFile(data_ov023_021fce2d, (SafeAllocator*)0);
#else
        *(int*)(obj + regionalOffset8) = ((BackgroundLoader*)(dataResult))->QueueLoadFileInGP2((const char*)((int)&data_ov023_021fdb60), (const char*)((int)&data_ov023_021fdb72), (SafeAllocator*)(0));
#endif

        *(unsigned char*)(obj + regionalOffset0) = *(unsigned char*)(obj + regionalOffset0) + 1;
    } else if (*(unsigned char*)(obj + regionalOffset0) == 5) {
        if (((BackgroundLoader*)(dataResult))->GetTaskStatus((int)(*(int*)(obj + regionalOffset8))) != 0) {
            ((SafeAllocator*)(*(void**)(obj + 0x44)))->Reset();
            void* dummyOut;
            int out1, out2;
            int fieldOut;
            ((BackgroundLoader*)((struct List0202fec8*)dataResult))->GetLoadedFileByID((int)(*(int*)(obj + regionalOffset8)), (void**)(&out1), (unsigned int*)(&out2));
#if defined(jpn)
            {
#else
            if (out1 != 0 && out2 != 0) {
#endif

                int count = CountActiveEntries((struct ActiveEntry02046900*)out1);
                for (int i = 0; i < count; i++) {
                    void* result = FindRecordByIndex((struct Rec020467f0*)out1, i, &dummyOut, &fieldOut);
                    func_0205a528(obj + regionalOffset9, result, fieldOut, *(void**)(obj + 0x44));
                }
            }
            *(signed char*)(obj + regionalOffset10) = 1;
            ((BackgroundLoader*)(dataResult))->RemoveTask((int)(*(int*)(obj + regionalOffset8)));
            *(int*)(obj + regionalOffset8) = -1;
            *(unsigned char*)(obj + regionalOffset0) = *(unsigned char*)(obj + regionalOffset0) + 1;
        }
    }

    if (*(unsigned char*)(obj + regionalOffset0) == 6) {
#if defined(jpn)
        *(int*)(obj + regionalOffset8) = ((BackgroundLoader*)(dataResult))->QueueLoadFile(data_ov023_021fce42, (SafeAllocator*)0);
#else
        *(int*)(obj + regionalOffset8) = ((BackgroundLoader*)(dataResult))->QueueLoadFileInGP2((const char*)((int)&data_ov023_021fdb80), (const char*)((int)&data_ov023_021fdb99), (SafeAllocator*)(0));
#endif

        *(unsigned char*)(obj + regionalOffset0) = *(unsigned char*)(obj + regionalOffset0) + 1;
    } else if (*(unsigned char*)(obj + regionalOffset0) == 7) {
        if (((BackgroundLoader*)(dataResult))->GetTaskStatus((int)(*(int*)(obj + regionalOffset8))) != 0) {
            int out1b, out2b;
            ((BackgroundLoader*)((struct List0202fec8*)dataResult))->GetLoadedFileByID((int)(*(int*)(obj + regionalOffset8)), (void**)(&out1b), (unsigned int*)(&out2b));
            ((SafeAllocator*)(obj + 0x14))->Reset();
#if defined(jpn)
            {
#else
            if (out1b != 0 && out2b != 0) {
#endif

                func_020dfec0(obj + 0x54, obj + 0x14, (void*)out1b, (unsigned int)out2b);
            }
            ((BackgroundLoader*)(dataResult))->RemoveTask((int)(*(int*)(obj + regionalOffset8)));
            *(int*)(obj + regionalOffset8) = -1;
            *(unsigned char*)(obj + regionalOffset0) = *(unsigned char*)(obj + regionalOffset0) + 1;
        }
    }

    if (*(unsigned char*)(obj + regionalOffset0) == 8) {
        unsigned int val;
        if (*(signed char*)(obj + regionalOffset3) == 1) {
            val = *(volatile unsigned int*)0x4001000;
        } else {
            val = *(volatile unsigned int*)0x4000000;
        }
        *(int*)(obj + regionalOffset11) = (val & 0x1f00) >> 8;
        if (*(signed char*)(obj + regionalOffset2) != 1) {
            ConfigureBgSub1AndClear_021dcc58(obj);
        }
        *(unsigned char*)(obj + regionalOffset12) = 1;
        *(unsigned char*)(obj + regionalOffset0) = 0;
        ResetIfNonNeg_021db2e4((volatile int*)(obj + regionalOffset8));
        for (int i = 0; i < 7; i++) {
            ResetIfNonNeg_021db2e4((volatile int*)(obj + regionalOffset13 + i * 4));
        }
        *(int*)(obj + regionalOffset14) = 0;
        *(unsigned short*)(obj + regionalOffset1) |= 1;
    }
}
