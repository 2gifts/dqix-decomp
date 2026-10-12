#if defined(jpn)
#define func_ov014_021885bc func_ov014_0218948c
#endif

#include <globaldefs.h>

#if defined(jpn)
#define ClearSublistEntriesFlag2 func_02081184
#define _Z29AddSublistEntryFlag2_020806b0Pvi func_020811d8
#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif

void ClearSublistEntriesFlag1(void* obj, int id);
#if defined(jpn)
extern "C" void ClearSublistEntriesFlag2(void* obj, int id);
#else
void ClearSublistEntriesFlag2(void* obj, int id);
#endif
struct Container02080f8c;
extern "C" void _Z26SetEntryFirstField02080f8cP17Container02080f8cii(struct Container02080f8c* obj, int id, int value);
struct Container02080fa8;
extern "C" void _Z26SetEntryFirstField02080fa8P17Container02080fa8ii(struct Container02080fa8* obj, int id, int value);
extern "C" void _Z29AddSublistEntryFlag2_020806b0Pvi(void* obj, int id);
extern "C" void _Z24SetEntryFlagById02080b2cPvi(void* obj, int id);
extern "C" void _Z30SetOrClearEntryFlag0x102081130Pvii(void* obj, int id, int flag);
extern "C" int func_020813ec(void* obj, int id);
struct Container020e0310;
extern "C" int _Z21GetFieldByKey020e0434P17Container020e0310i(struct Container020e0310* c, int key);
struct ListHeadStruct021874f8;
extern "C" short _Z29CountLinkedListNodes_021874f8P22ListHeadStruct021874f8(struct ListHeadStruct021874f8* obj);
struct S02187520;
extern "C" short _Z23FindIndexDiv16_02187520P9S02187520(struct S02187520* s);

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
            int v = _Z21GetFieldByKey020e0434P17Container020e0310i((struct Container020e0310*)((char*)self + 0xe0), 0x15);
            _Z26SetEntryFirstField02080f8cP17Container02080f8cii((struct Container02080f8c*)list, id, v);
            if (node->flagBit1) {
                _Z26SetEntryFirstField02080f8cP17Container02080f8cii((struct Container02080f8c*)*(void**)((char*)self + 0xc0), id, node->field8);
            }
            node = node->next;
        } else {
            _Z29AddSublistEntryFlag2_020806b0Pvi(list, id);
            _Z24SetEntryFlagById02080b2cPvi(list, id);
        }
    }

    short listCount = _Z29CountLinkedListNodes_021874f8P22ListHeadStruct021874f8((struct ListHeadStruct021874f8*)self);
    short idx = (short)(_Z23FindIndexDiv16_02187520P9S02187520((struct S02187520*)self) + 1);
    _Z26SetEntryFirstField02080fa8P17Container02080fa8ii((struct Container02080fa8*)list, 0x2b, idx);
    short page = (short)((listCount + 0xf) / 0x10);
    _Z26SetEntryFirstField02080fa8P17Container02080fa8ii((struct Container02080fa8*)list, 0x2d, page);
    int overflow = (listCount > 0x10) ? 1 : 0;
    _Z30SetOrClearEntryFlag0x102081130Pvii(list, 5, overflow);
    func_020813ec(list, 5);
}
