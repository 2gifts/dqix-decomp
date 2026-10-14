#include <globaldefs.h>

extern "C" int func_ov017_021d60f4(void* p);

extern void* GetGlobalPtr021075f4_0203cf4c(void);

struct EntryList_203dce4;
struct Entry_203dce4;
extern struct Entry_203dce4* GetEntryUnlessFlag0x8000_0203dce4(struct EntryList_203dce4* list, int id);

struct GlobalTable_0215d0f4 { int pad0; unsigned char* elems; };
extern struct GlobalTable_0215d0f4 data_ov001_02165880;

// USA: func_ov001_0215d0f4
ARM int SetEntryOffset10Zero_0215d0f4(void* ctx) {
    int idx = func_ov017_021d60f4(ctx);
    unsigned char* elem = data_ov001_02165880.elems + idx * 0x10;
    int id = *(int*)(elem + 0x4);
    struct Entry_203dce4* entry = GetEntryUnlessFlag0x8000_0203dce4(
        (struct EntryList_203dce4*)GetGlobalPtr021075f4_0203cf4c(), id);
    if (entry == NULL) return 0;
    *(int*)((char*)entry + 0x10) = 0;
    return 1;
}
