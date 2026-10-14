#if defined(jpn)
#define func_ov014_021885bc func_ov014_0218948c
#endif

#include <globaldefs.h>

#if defined(jpn)
#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif

void ClearSublistEntriesFlag1(void* obj, int id);
void ClearSublistEntriesFlag2(void* obj, int id);
struct Container02080f8c;
void SetEntryFirstField02080f8c(struct Container02080f8c* obj, int id, int value);
struct Container02080fa8;
void SetEntryFirstField02080fa8(struct Container02080fa8* obj, int id, int value);
void AddSublistEntryFlag2_020806b0(void* obj, int id);
void SetEntryFlagById02080b2c(void* obj, int id);
void SetOrClearEntryFlag0x102081130(void* obj, int id, int flag);
extern "C" int func_020813ec(void* obj, int id);
struct Container020e0310;
int GetFieldByKey020e0434(struct Container020e0310* c, int key);
struct ListHeadStruct021874f8;
short CountLinkedListNodes_021874f8(struct ListHeadStruct021874f8* obj);
struct S02187520;
short FindIndexDiv16_02187520(struct S02187520* s);

struct SubEntry021885bc {
    struct SubEntry021885bc* next;
    char pad4[4];
    int field8;
    char pad12[0x13 - 0xc];
    unsigned char pad13 : 1;
    unsigned char flagBit1 : 1;
};

// USA: func_ov014_021885bc  (semantic: PopulateSublistEntriesAndPaging_021885bc)
extern "C" ARM void func_ov014_021885bc(void* self) {
    void* list = *(void**)((char*)self + 0xc0);
    short val = *(short*)((char*)self + 0x176);
    *(short*)((char*)list + LOW_REGION(0x2a, 0x36)) = val;
    ClearSublistEntriesFlag1(list, 5);
    ClearSublistEntriesFlag2(list, 5);

    struct SubEntry021885bc* node = *(struct SubEntry021885bc**)((char*)self + 0xbc);
    short id = 0x1b;
    short count = 0;
    for (; count < 0x10; id++, count++) {
        if (node != NULL) {
            int v = GetFieldByKey020e0434((struct Container020e0310*)((char*)self + 0xe0), 0x15);
            SetEntryFirstField02080f8c((struct Container02080f8c*)list, id, v);
            if (node->flagBit1) {
                SetEntryFirstField02080f8c((struct Container02080f8c*)*(void**)((char*)self + 0xc0), id, node->field8);
            }
            node = node->next;
        } else {
            AddSublistEntryFlag2_020806b0(list, id);
            SetEntryFlagById02080b2c(list, id);
        }
    }

    short listCount = CountLinkedListNodes_021874f8((struct ListHeadStruct021874f8*)self);
    short idx = (short)(FindIndexDiv16_02187520((struct S02187520*)self) + 1);
    SetEntryFirstField02080fa8((struct Container02080fa8*)list, 0x2b, idx);
    short page = (short)((listCount + 0xf) / 0x10);
    SetEntryFirstField02080fa8((struct Container02080fa8*)list, 0x2d, page);
    int overflow = (listCount > 0x10) ? 1 : 0;
    SetOrClearEntryFlag0x102081130(list, 5, overflow);
    func_020813ec(list, 5);
}
