#include <globaldefs.h>

extern "C" int func_ov017_021d60f4(void* p);

extern void* GetGlobalPtr021075f4_0203cf4c(void);

struct EntryList_203dce4;
struct Entry_203dce4;
extern struct Entry_203dce4* GetEntryUnlessFlag0x8000_0203dce4(struct EntryList_203dce4* list, int id);

struct GlobalTable_0215d08c { int pad0; unsigned char* elems; };
extern struct GlobalTable_0215d08c data_ov001_02165880;

// USA: func_ov001_0215d08c
ARM int SetEntryField10FromTable_0215d08c(void* self) {
    int idx1 = func_ov017_021d60f4(self);
    int idx2 = func_ov017_021d60f4((char*)self + 0x8);
    void* global = GetGlobalPtr021075f4_0203cf4c();
    int id = *(int*)(data_ov001_02165880.elems + idx1 * 0x10 + 0x4);
    struct Entry_203dce4* entry = GetEntryUnlessFlag0x8000_0203dce4((struct EntryList_203dce4*)global, id);
    if (entry == NULL) return 0;
    int val = *(int*)(data_ov001_02165880.elems + idx2 * 0x10 + 0xc);
    if (val == 0) return 0;
    *(int*)((char*)entry + 0x10) = val;
    return 1;
}
