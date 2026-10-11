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

struct QueueEntryInit_f740 { int a; int b; int c; int d; };
extern "C" void func_ov001_0215acb4(QueueEntryInit_f740* p);

struct DataOv001_f740 { char pad0[4]; QueueEntryInit_f740* table; };
extern DataOv001_f740 data_ov001_02165880;

typedef void* (*EmptyStubFn_f740)(void*);

// USA: func_ov001_0215f740  (semantic: ProcessEntryAndClearQueueSlots_0215f740)
extern "C" ARM int func_ov001_0215f740(void* self) {
    int id = func_ov017_021d60f4(self);
    if (id >= 0x20) {
        return 0;
    }
    struct EntryList_203dce4* list = (struct EntryList_203dce4*)GetGlobalPtr021075f4();
    struct Entry_203dce4* entry = GetEntryUnlessFlag0x8000(list, id);
    if (entry == NULL) {
        return 0;
    }
    if (*(int*)((char*)entry + 0x14) != 0) {
        int field = GetField0x8((int*)entry);
        EmptyStubFn_f740 stub = (EmptyStubFn_f740)EmptyStub0203d004;
        struct Container02040404* c = (struct Container02040404*)stub(list);
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
    SetSlotIfIndexBelow32((SlotArray0203dd10*)list, id, 0);

    if (data_ov001_02165880.table != NULL) {
        for (int i = 0; i < 0x20; i++) {
            if (data_ov001_02165880.table[i].a == 2 || data_ov001_02165880.table[i].a == 6) {
                if (data_ov001_02165880.table[i].b == id) {
                    func_ov001_0215acb4(&data_ov001_02165880.table[i]);
                }
            }
        }
    }
    return 1;
}
