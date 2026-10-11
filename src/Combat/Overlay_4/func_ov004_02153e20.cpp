#if defined(jpn)
#define R(j,u) (j)
#define _Z24IssueBattleCommandSlot25ii func_020d84e0
#define data_ov001_02164ca4 data_ov001_02166270
#define data_ov028_021d9aa0 data_ov028_021da400
#define func_ov014_02188330 func_ov014_02189234
#define func_ov014_0218854c func_ov014_0218942c
#define func_ov014_021885bc func_ov014_0218948c
#define func_ov015_02191f04 func_ov015_02192a48
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

struct Grid021f9b30;

struct Entry02153e20 {
    int field_0x0;
    int value;
    int field_0x8;
    unsigned int flags;
};

struct ListNode02153e20 {
    ListNode02153e20* next;
    Entry02153e20* entry;
};

struct Board02153e20 {
    char pad[0x5c];
    short x;
    short y;
};

struct Slot02153e20 {
    char pad[0xc];
    unsigned char flags;
    char pad2[0x13];
    int value;
};

struct Cursor02153e20 {
    char pad[0x104];
    short x;
    short y;
};

class ListOwner02153e20 {
public:
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
    virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
    virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51();
    virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55();
    virtual void v56(); virtual void v57(); virtual void v58();
    virtual ListNode02153e20** GetList();
};

extern "C" void* func_ov011_021849c8(void* ctx);
extern "C" void* func_ov023_021f6880(void* list, int id);
extern "C" int func_ov023_021f6f10(void* obj);
extern "C" unsigned char* func_0205ec34(void);
extern "C" int _Z26SetCellIfInBounds_021f9b30P12Grid021f9b30sjj(struct Grid021f9b30* self, unsigned short val, unsigned int x, unsigned int y);
int TestBitInByteArray(int unused, unsigned char* arr, int index);
extern "C" void func_ov023_021f9d14(void* grid, void* ctx);
extern "C" void func_ov023_021f809c(void* obj, void* ctx);
extern "C" int _Z31CheckType16ThenTestBit_02153d8cPv(void* ctx);

// USA: func_ov004_02153e20
extern "C" ARM int func_ov004_02153e20(void* ctx) {
    void* list = func_ov011_021849c8(ctx);
    short x, y;
    Board02153e20* board = (Board02153e20*)func_ov023_021f6880(list, 0x2c);
    if (!board) return 0;
    if (func_ov023_021f6f10(board) != 7) return 0;
    x = board->x;
    y = board->y;
    ListOwner02153e20* owner = (ListOwner02153e20*)func_ov023_021f6880(list, 0x39);
    if (!owner) return 0;
    if (func_ov023_021f6f10(owner) != 0x12) return 0;
    ListNode02153e20** head = owner->GetList();
    if (!head) return 0;
    ListNode02153e20* node = *head;
    if (!node) return 0;
    unsigned char* flags = func_0205ec34();

    short start = x * 16;
    short i = 0;
    while (node) {
        if (i == start) break;
        i++;
        node = node->next;
    }

    for (short j = 0; j < 16; j++) {
        int id = j + 0x1a;
        Slot02153e20* slot = (Slot02153e20*)func_ov023_021f6880(list, id);
        if (slot && func_ov023_021f6f10(slot) == 8) {
            slot->value = 0;
            slot->flags &= ~8;
            if (!node) {
                _Z26SetCellIfInBounds_021f9b30P12Grid021f9b30sjj((Grid021f9b30*)board, 0, (unsigned short)(j >> 1), (unsigned short)(j & 1));
                slot->flags |= 8;
            } else {
                _Z26SetCellIfInBounds_021f9b30P12Grid021f9b30sjj((Grid021f9b30*)board, (unsigned short)id, (unsigned short)(j >> 1), (unsigned short)(j & 1));
                Entry02153e20* entry = node->entry;
                if (entry) {
                    int bits = (unsigned short)((entry->flags << 9) >> 21);
                    if (bits > 0) {
                        if (TestBitInByteArray((int)flags, flags + 0x8c, bits + 0x76 + 0xc00)) {
                            slot->value = entry->value;
                        }
                    }
                }
                node = node->next;
            }
        }
    }

    func_ov023_021f9d14(board, ctx);
    Cursor02153e20* cursor = (Cursor02153e20*)func_ov023_021f6880(list, 3);
    if (!cursor) return 0;
    if (func_ov023_021f6f10(cursor) != 6) return 0;
    cursor->x = x;
    cursor->y = y;
    func_ov023_021f809c(cursor, ctx);
    _Z31CheckType16ThenTestBit_02153d8cPv(ctx);
    return 0;
}
