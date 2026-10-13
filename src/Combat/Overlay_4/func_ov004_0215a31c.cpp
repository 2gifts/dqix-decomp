#include <globaldefs.h>
#include "GameState/GameState.h"

class Node0215a31c {
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
    virtual void v52(); virtual void v53();
    virtual void SetIcon(int v);
    virtual void v55();
    virtual void SetValue(int v);
    char pad04[8];
    unsigned char flags;
    char pad0d[0x13];
    void* data;
};

struct Grid021f9b30 {
    char pad[0x5c];
    short page;
    short pageCount;
};

struct Element0215a31c {
    char pad[4];
    void* data;
};

struct Container020dedd0;
struct TableA68;
struct S_a0b8c;

extern "C" int func_ov004_02157128(void* obj);
extern "C" Container020dedd0* func_ov004_02156fd4(void* obj, int key);
extern "C" TableA68* _Z34DispatchAdjustmentIfType4_02157018Pvi(void* obj, int key);
extern "C" Grid021f9b30* func_ov004_02156ed0(void* obj, int key);
extern "C" Node0215a31c* func_ov004_02156f04(void* obj, int key);
extern "C" Node0215a31c* func_ov004_02156f38(void* obj, int key);
void* FindEntryByKey(TableA68* table, int key);
extern "C" int _Z26CountNonZeroValues020a0b8cP7S_a0b8c(S_a0b8c* p);
extern "C" void _Z26ClearNodeMaskById_021f6600Pvii(void* obj, int id, int mask);
unsigned char* GetFieldAt0x150(unsigned char* obj);
extern "C" int func_020dcc98(int combatantId);
extern "C" void func_ov023_021f65d4(void* obj, int id, int mask);
extern "C" Element0215a31c* _Z24FindElementByKey020dedd0P17Container020dedd0i(Container020dedd0* c, int key);
extern "C" int _Z26SetCellIfInBounds_021f9b30P12Grid021f9b30sjj(Grid021f9b30* self, unsigned short val, unsigned int x, unsigned int y);
extern "C" void func_ov023_021f9ba8(Grid021f9b30* grid, int v);
extern "C" void* func_ov004_02156f6c(void* obj, int kind);
extern "C" void func_ov023_021f809c(void* node, void* obj);
extern "C" void* _Z24CheckThenNotify_02157088Pvi(void* object, int key);
extern "C" void func_ov023_021dcae0(void* obj, int v);

// USA: func_ov004_0215a31c
extern "C" ARM int func_ov004_0215a31c(void* obj) {
    int flag = func_ov004_02157128(obj);
    Container020dedd0* items = func_ov004_02156fd4(obj, 5);
    TableA68* table = _Z34DispatchAdjustmentIfType4_02157018Pvi(obj, 3);
    short* keys;
    Grid021f9b30* grid = func_ov004_02156ed0(obj, 0x63);
    int i;
    int slot;

    if (flag == -1) {
        unsigned char* list = (unsigned char*)GetPtrField0x2a04(GameState::GetInstance());
        if (!list) return 0;
        keys = (short*)(list + 0xc);
        signed char* counts = (signed char*)(list + 0x13c);
        Node0215a31c* node = func_ov004_02156f04(obj, 0x454);
        if (node) {
            node->data = FindEntryByKey(table, 0xb);
        }
        short page = grid->page;
        short pageCount = grid->pageCount;
        if (!(page > 0 && pageCount > 0)) {
            page = 0;
            pageCount = (_Z26CountNonZeroValues020a0b8cP7S_a0b8c((S_a0b8c*)list) - 1) / 8 + 1;
            if (pageCount < 1) pageCount = 1;
            grid->page = 0;
            grid->pageCount = pageCount;
        }
        keys += page * 8;
        node = func_ov004_02156f04(obj, 0x458);
        if (node) node->flags &= ~8;
        func_ov004_02156f38(obj, 0x456)->SetValue(page + 1);
        func_ov004_02156f38(obj, 0x457)->SetValue(pageCount);
        _Z26ClearNodeMaskById_021f6600Pvii(obj, 0x456, 8);
        _Z26ClearNodeMaskById_021f6600Pvii(obj, 0x457, 8);
        _Z26ClearNodeMaskById_021f6600Pvii(obj, 0x469, 8);
        _Z26ClearNodeMaskById_021f6600Pvii(obj, 0x46a, 8);
        for (i = 0; i < 8; i++) {
            _Z26ClearNodeMaskById_021f6600Pvii(obj, i + 0x459, 8);
            _Z26ClearNodeMaskById_021f6600Pvii(obj, i + 0x461, 8);
            func_ov004_02156f38(obj, i + 0x461)->SetValue(counts[i]);
        }
    } else {
        GameObject* combatant = GetCombatantWithFlag0x100(GameState::GetInstance(), flag);
        if (!combatant) return 0;
        keys = (short*)(GetFieldAt0x150((unsigned char*)combatant) + 0x454);
        Node0215a31c* node = func_ov004_02156f04(obj, 0x454);
        if (node) {
            node->data = combatant->baseStats_;
            node->SetIcon(func_020dcc98(flag));
        }
        node = func_ov004_02156f04(obj, 0x458);
        if (node) node->flags |= 8;
        func_ov023_021f65d4(obj, 0x456, 8);
        func_ov023_021f65d4(obj, 0x457, 8);
        func_ov023_021f65d4(obj, 0x469, 8);
        func_ov023_021f65d4(obj, 0x46a, 8);
        for (slot = 0; slot < 8; slot++) {
            func_ov023_021f65d4(obj, slot + 0x459, 8);
            func_ov023_021f65d4(obj, slot + 0x461, 8);
        }
    }

    for (slot = 0; slot < 8; slot++) {
        Element0215a31c* elem = _Z24FindElementByKey020dedd0P17Container020dedd0i(items, keys[slot]);
        Node0215a31c* node = func_ov004_02156f04(obj, slot + 0x44c);
        if (!elem) {
            node->flags |= 8;
            func_ov023_021f65d4(obj, slot + 0x459, 8);
            func_ov023_021f65d4(obj, slot + 0x461, 8);
            _Z26SetCellIfInBounds_021f9b30P12Grid021f9b30sjj(grid, 0, (unsigned short)slot, 0);
        } else {
            void* data = elem->data ? elem->data : 0;
            if (node) {
                node->flags &= ~8;
                node->data = data;
                _Z26SetCellIfInBounds_021f9b30P12Grid021f9b30sjj(grid, (unsigned short)(slot + 0x44c), (unsigned short)slot, 0);
            }
        }
    }
    func_ov023_021f9ba8(grid, 0);
    void* list = func_ov004_02156f6c(obj, 0x17);
    if (list) func_ov023_021f809c(list, obj);
    void* notified = _Z24CheckThenNotify_02157088Pvi(obj, 7);
    if (notified) func_ov023_021dcae0(notified, -1);
    return 0;
}
