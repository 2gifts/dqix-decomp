// JPN: func_ov017_021a5764
#if defined(jpn)
enum { RegionOffset710 = 0x500, RegionOffset724 = 0x4c4, RegionOffset6fc = 0x4ec };
#else
enum { RegionOffset710 = 0x710, RegionOffset724 = 0x724, RegionOffset6fc = 0x6fc };
#endif

#include <globaldefs.h>
#include "GameState/GameState.h"

void* GetGlobalPtr021075f4(void);
struct EntryList_203dce4;
struct Entry_203dce4* GetEntryUnlessFlag0x8000(struct EntryList_203dce4* list, int id);
int GetField0x8(int* obj);
int* GetGlobal02109418(void);
extern "C" void func_02095924(int* g, int val);
extern "C" void* func_0205ec34(void* arg);
int LookupAndForEachNode020649b0(void* a, int mode, void* c);
extern "C" void func_0206f81c(void* p);
struct S021b8d1c;
extern "C" void func_ov017_021b8d1c(void* obj);
struct TailList020469b4;
struct TailNode020469b4;
void AppendNodeToTail(struct TailList020469b4* list, struct TailNode020469b4* node);

extern int data_ov017_021d76d8;
extern int data_ov017_021d83a8;

struct LocalC021a4cf0 {
    int f0;
    char pad[0x14 - 0x4];
    int f14;
    char pad2[0x34 - 0x18];
};

// USA: func_ov017_021a4cf0
ARM void ProcessEntryFieldAndNotify_021a4cf0(char* self) {
    void* list = GetGlobalPtr021075f4();
    short id = *(short*)((char*)&data_ov017_021d76d8 + 0x2);
    struct Entry_203dce4* entry = GetEntryUnlessFlag0x8000((struct EntryList_203dce4*)list, id);
    if (entry == NULL) {
        return;
    }
    int* field = (int*)GetField0x8((int*)entry);
    if (field == NULL) {
        return;
    }
    void* obj710 = *(void**)(self + 0x3000 + RegionOffset710);
    if (*((unsigned char*)obj710 + 0x130) != 0) {
        return;
    }
    int* g = GetGlobal02109418();
    unsigned short v = *(unsigned short*)field;
    func_02095924(g, v & 0xff);
    GameState* bs = GameState::GetInstance();
    unsigned short v2 = *(unsigned short*)field;
    *(int*)((char*)bs + 0x5000 + RegionOffset724) = v2;
    void* r = func_0205ec34((char*)bs + 0x5000);
    struct LocalC021a4cf0 c;
    c.f0 = *(unsigned short*)field;
    c.f14 = *(unsigned short*)&data_ov017_021d83a8;
    if (LookupAndForEachNode020649b0(r, 0, &c)) {
        func_0206f81c(&c);
        return;
    }
    func_ov017_021b8d1c(*(void**)(self + 0x3000 + RegionOffset710));
    *(int*)((char*)(*(void**)(self + 0x3000 + RegionOffset710)) + 0x114) = (int)field;
    *(int*)((char*)(*(void**)(self + 0x3000 + RegionOffset710)) + 0x124) = *(unsigned short*)&data_ov017_021d83a8;
    AppendNodeToTail((struct TailList020469b4*)(*(void**)(self + 0x3000 + RegionOffset6fc)),
                      (struct TailNode020469b4*)(*(void**)(self + 0x3000 + RegionOffset710)));
}
