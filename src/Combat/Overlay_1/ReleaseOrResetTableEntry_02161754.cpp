#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" int func_ov017_021d60f4(void*);

struct Entry_203dce4 { int flags; };
struct EntryList_203dce4 { char pad[0xc]; struct Entry_203dce4* entries[0x20]; };
extern void* GetGlobalPtr021075f4(void);
extern struct Entry_203dce4* GetEntryUnlessFlag0x8000(struct EntryList_203dce4* list, int id);
int GetField0x8(int* obj);
void EmptyStub0203d004(void);
extern const char data_ov001_021657d4[];

struct Container02040404;
int FindEntryIndexByName02040404(struct Container02040404* container, const char* name);
struct Container0204039c;
void ReleaseOrDecrementSlot0204039c(struct Container0204039c* obj, int index);

extern "C" void _ZN8Object3D7DestroyEv(unsigned char* obj);
struct State02041244;
void ResetState0204128c(struct State02041244* obj);
void Reset02040504(int* obj);

struct SlotArray0203dd10;
void SetSlotIfIndexBelow32(SlotArray0203dd10* obj, unsigned int index, int value);

struct TableEntry_02161754 { int type; int field4; char pad8[8]; };
struct DataOv001_02161754 { char pad0[4]; struct TableEntry_02161754* table; };
extern DataOv001_02161754 data_ov001_02165880;

typedef void* (*EmptyStubFn_02161754)(void*);

// USA: func_ov001_02161754  (semantic: ReleaseOrResetTableEntry_02161754)
extern "C" ARM int func_ov001_02161754(void* self) {
    int id = func_ov017_021d60f4(self);
    if (id < 0) {
        return 0;
    }
    if (data_ov001_02165880.table[id].type != 6 && data_ov001_02165880.table[id].type != 2) {
        return 0;
    }

    void* ctxRaw = GetGlobalPtr021075f4();
    struct EntryList_203dce4* list = (struct EntryList_203dce4*)ctxRaw;
    struct Entry_203dce4* entry = GetEntryUnlessFlag0x8000(list, data_ov001_02165880.table[id].field4);
    if (entry == NULL) {
        return 0;
    }

    if (*(int*)((char*)entry + 0x14) != 0) {
        int field = GetField0x8((int*)entry);
        EmptyStubFn_02161754 stub = (EmptyStubFn_02161754)EmptyStub0203d004;
        struct Container02040404* c = (struct Container02040404*)stub(ctxRaw);
        char buf[0x10];
#if defined(jpn)
        sprintf(buf, data_ov001_021657d4, field + 16);
#else
        sprintf(buf, data_ov001_021657d4, field + 4);
#endif
        int idx = FindEntryIndexByName02040404(c, buf);
        ReleaseOrDecrementSlot0204039c((struct Container0204039c*)c, idx);
    } else {
        if (*(void**)((char*)entry + 0x18) != 0) {
            _ZN8Object3D7DestroyEv((unsigned char*)*(void**)((char*)entry + 0x18));
            ResetState0204128c((struct State02041244*)*(void**)((char*)entry + 0x18));
        }
    }

    Reset02040504((int*)entry);
    SetSlotIfIndexBelow32((SlotArray0203dd10*)list, data_ov001_02165880.table[id].field4, 0);
    return 1;
}
