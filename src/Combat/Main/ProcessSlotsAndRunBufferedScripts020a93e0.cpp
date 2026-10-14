#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Memory/AllocatorUnion.h"

struct ResetFieldsStruct {
    int f0;
    short f4;
    short f6;
    short f8;
    char pad0a[2];
    int fc;
    short f10;
    char pad12[2];
    int f14;
    short f18;
};
void ResetStructFields_02089db4(struct ResetFieldsStruct* s);
void ForwardResetStructFields02089ddc(struct ResetFieldsStruct* s);
void SetupHeaderAndRunBufferedScript02089de8(void* param0, void* param1, const char* param2);

struct Entry02089fb0 {
    signed char id;
    unsigned char pad[0x3f];
};
struct EntryArray02089fb0 {
    struct Entry02089fb0* base;
    short count;
};
struct Entry02089fb0* FindEntryBySignedId02089fb0(struct EntryArray02089fb0* arr, int id);

extern "C" int func_020426bc(char* str, unsigned char* out, int id);

void* AllocateAligned4_02012d88(AllocatorUnion* alloc, unsigned int size);
void TailForward02012da4(AllocatorUnion* alloc, void* data);
extern AllocatorUnion data_02114e20;

struct FlagByte020a93e0 {
    unsigned char pad[0x13f];
    unsigned char flags : 3;
};

// USA: func_020a93e0  (semantic: ProcessSlotsAndRunBufferedScripts020a93e0)
extern "C" ARM void func_020a93e0(char* param0) {
    char* elem2;
    int end;
    int i;
    for (i = 0; i < 13; i++) {
        char* elem = param0 + i * 0x23c;
        if (((struct FlagByte020a93e0*)elem)->flags != 0) {
            struct ResetFieldsStruct fields;
            SafeAllocator localAlloc;
            localAlloc.ResetAllocatorPointer();
            localAlloc.ResetAllocatorPointer();
            void* mem = AllocateAligned4_02012d88(&data_02114e20, 0x800);
            localAlloc.CreateTypeA(mem, 0x800);
            ResetStructFields_02089db4(&fields);
            SetupHeaderAndRunBufferedScript02089de8(&fields, &localAlloc, 0);
            end = *(unsigned char*)(param0 + 0x1d11) + *(unsigned char*)(param0 + 0x1d0c);
            for (; i < end; i++) {
                elem2 = param0 + i * 0x23c;
                int flags2 = ((struct FlagByte020a93e0*)elem2)->flags;
                if (flags2 != 0) {
                    struct Entry02089fb0* e = FindEntryBySignedId02089fb0(
                        (struct EntryArray02089fb0*)&fields, (short)(flags2 + 7));
                    char* str = *(char**)((char*)e + 4);
                    func_020426bc(str, (unsigned char*)(elem2 + 0x140), 1);
                }
            }
            SignedAllocatorHeader* sig = localAlloc.GetSignedAllocator();
            ForwardResetStructFields02089ddc(&fields);
            localAlloc.Destroy();
            TailForward02012da4(&data_02114e20, sig);
            return;
        }
    }
}
