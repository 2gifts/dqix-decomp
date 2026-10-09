#include <globaldefs.h>

struct Grid021f9b30 {
    char pad[0x20];
    short* cells;
    unsigned short width;
    unsigned short height;
    char pad28[0x34];
    short x;
    short y;
};

struct Entry0215534c {
    int field_0x0;
    int value;
    int field_0x8;
    unsigned int flags;
};

struct ListNode0215534c {
    ListNode0215534c* next;
    Entry0215534c* entry;
};

struct Slot0215534c {
    char pad[0xc];
    unsigned char flags;
    char padD[0x13];
    int value;
};

class VObj0215534c {
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
	virtual ListNode0215534c** GetList();
};

extern "C" void* func_ov011_021849c8(void* ctx);
extern "C" void* func_ov023_021f6880(void* list, int id);
extern "C" int func_ov023_021f6f10(void* obj);
extern "C" void* func_0205ec34(void);
extern "C" void func_ov023_021f9d14(Grid021f9b30* grid, void* ctx);
extern "C" int _Z26SetCellIfInBounds_021f9b30P12Grid021f9b30sjj(Grid021f9b30* self, unsigned short val, unsigned int x, unsigned int y);
extern "C" void _Z26SetByteAtOffset60_021f9da0Pvh(void* self, unsigned char val);
extern "C" void _Z21DispatchNode_021f6630iiss(int ctx, int kind, short x, short y);
extern "C" int _Z31CheckType16ThenTestBit_021552b8Pv(void* ctx);
extern int TestBitInByteArray(int unused, unsigned char* arr, int index);

// USA: func_ov004_0215534c
extern "C" ARM int func_ov004_0215534c(void* ctx) {
    void* list;
    short x;
    Grid021f9b30* grid;
    short y;
    VObj0215534c* obj;
    ListNode0215534c** head;
    ListNode0215534c* node;
    unsigned char* flags;
    short i;
    short j;
    int id;
    Slot0215534c* slot;

    list = func_ov011_021849c8(ctx);
    grid = (Grid021f9b30*)func_ov023_021f6880(list, 0x2c);
    if (!grid) return 0;
    if (func_ov023_021f6f10(grid) != 7) return 0;
    x = grid->x;
    y = grid->y;
    obj = (VObj0215534c*)func_ov023_021f6880(list, 0x39);
    if (!obj) return 0;
    if (func_ov023_021f6f10(obj) != 0x12) return 0;
    head = obj->GetList();
    if (!head) return 0;
    node = *head;
    if (!node) return 0;
    flags = (unsigned char*)func_0205ec34();

    short start = x * 16;
    i = 0;
    while (node) {
        if (i == start) break;
        i++;
        node = node->next;
    }

    for (j = 0; j < 16; j++) {
        id = j + 0x1a;
        slot = (Slot0215534c*)func_ov023_021f6880(list, id);
        if (slot && func_ov023_021f6f10(slot) == 8) {
            slot->value = 0;
            slot->flags &= ~8;
            if (!node) {
                _Z26SetCellIfInBounds_021f9b30P12Grid021f9b30sjj(grid, 0, (unsigned short)(j >> 1), (unsigned short)(j & 1));
                slot->flags |= 8;
            } else {
                _Z26SetCellIfInBounds_021f9b30P12Grid021f9b30sjj(grid, (unsigned short)id, (unsigned short)(j >> 1), (unsigned short)(j & 1));
                Entry0215534c* entry = node->entry;
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

    _Z26SetByteAtOffset60_021f9da0Pvh(grid, 1);
    func_ov023_021f9d14(grid, ctx);
    _Z21DispatchNode_021f6630iiss((int)ctx, 3, x, y);
    _Z31CheckType16ThenTestBit_021552b8Pv(ctx);
    return 0;
}
