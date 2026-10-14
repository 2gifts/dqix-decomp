#include <globaldefs.h>
#include "GameState/GameState.h"

void* GetPtrField0x2a04(GameState* battleStruct);
int HasFlag101_021571d8(int a);
int DispatchNodeIfType7_02156e2c(void* a, int key);
void* GetPointerFromArray0xbd0(unsigned char* obj, unsigned int index);
void* GetPointerAt0xbf0(void* base, unsigned int index);
void ClearNodeMaskById_021f6600(void* obj, int id, int mask);
extern "C" int func_ov004_02157128(void* obj);
extern "C" void* func_ov004_02156fd4(void* obj, int key);
extern "C" void* func_ov004_02156f38(void* obj, int key);
extern "C" void* func_ov004_02156f6c(void* obj, int key);
extern "C" void func_ov023_021f65d4(void* obj, int key, int mask);
extern "C" void func_ov023_021f809c(void* node, void* obj);
extern "C" void func_ov023_021dcae0(void* node, int val);
void* CheckThenNotify_02157088(void* object, int key);

struct Grid021f9b30 {
    char pad0[0x20];
    short* cells;
    unsigned short width;
    unsigned short height;
    char pad1[0x34];
    short field5c;
    short field5e;
};
extern "C" Grid021f9b30* func_ov004_02156ed0(void* obj, int key);
extern "C" int _Z26SetCellIfInBounds_021f9b30P12Grid021f9b30sjj(Grid021f9b30* self, unsigned short val, unsigned short x, unsigned short y);

struct Element020de650 {
    char pad[4];
    int field4;
};
struct Container020dedd0;
Element020de650* FindElementByKey020dedd0(Container020dedd0* c, int key);

struct Slot02156f04 {
    char pad[0xc];
    unsigned char flags;
    char pad2[0x13];
    int field20;
};
extern "C" Slot02156f04* func_ov004_02156f04(void* obj, int key);

struct Struct021707d8_0215a738 { char pad[8]; unsigned char* ptr; };
extern Struct021707d8_0215a738 data_ov004_021707d8;

class VObj0215a738 {
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
    virtual void Notify(int n);
};

// USA: func_ov004_0215a738
extern "C" ARM int func_ov004_0215a738(void* obj) {
    short base;
    short saved;
    GameState* bs = GameState::GetInstance();
    unsigned char* p = (unsigned char*)GetPtrField0x2a04(bs);
    if (!p) return 0;
    Grid021f9b30* grid = func_ov004_02156ed0(obj, 0x63);
    base = grid->field5c;
    saved = grid->field5e;
    short* keys;
    signed char* bytes;
    if (HasFlag101_021571d8((int)obj)) {
        int idx = DispatchNodeIfType7_02156e2c(obj, 0x65);
        if (idx < 0) return 0;
        keys = (short*)GetPointerFromArray0xbd0(p + 0x1d4, *(data_ov004_021707d8.ptr + idx + 0x7c));
        bytes = (signed char*)GetPointerAt0xbf0(p + 0x1d4, *(data_ov004_021707d8.ptr + idx + 0x7c));
    } else {
        if (func_ov004_02157128(obj) >= 0) return 0;
        keys = (short*)(p + 0xc);
        bytes = (signed char*)(p + 0x13c);
    }
    Container020dedd0* node = (Container020dedd0*)func_ov004_02156fd4(obj, 5);
    for (int i = 0; i < 8; i++) {
        int k = i + base * 8;
        Element020de650* elem = FindElementByKey020dedd0(node, keys[k]);
        Slot02156f04* slot = func_ov004_02156f04(obj, i + 0x44c);
        if (elem == 0) {
            slot->flags |= 8;
            _Z26SetCellIfInBounds_021f9b30P12Grid021f9b30sjj(grid, 0, i, 0);
            func_ov023_021f65d4(obj, i + 0x459, 8);
            func_ov023_021f65d4(obj, i + 0x461, 8);
        } else {
            int v = elem->field4 ? elem->field4 : 0;
            if (slot) {
                slot->flags &= ~8;
                slot->field20 = v;
                _Z26SetCellIfInBounds_021f9b30P12Grid021f9b30sjj(grid, i + 0x44c, i, 0);
                ClearNodeMaskById_021f6600(obj, i + 0x459, 8);
                ClearNodeMaskById_021f6600(obj, i + 0x461, 8);
                ((VObj0215a738*)func_ov004_02156f38(obj, i + 0x461))->Notify(bytes[k]);
            }
        }
    }
    ((VObj0215a738*)func_ov004_02156f38(obj, 0x456))->Notify(base + 1);
    ((VObj0215a738*)func_ov004_02156f38(obj, 0x457))->Notify(saved);
    ClearNodeMaskById_021f6600(obj, 0x456, 8);
    ClearNodeMaskById_021f6600(obj, 0x457, 8);
    ClearNodeMaskById_021f6600(obj, 0x469, 8);
    ClearNodeMaskById_021f6600(obj, 0x46a, 8);
    void* n = func_ov004_02156f6c(obj, 0x17);
    if (n) func_ov023_021f809c(n, obj);
    void* r = (void*)CheckThenNotify_02157088(obj, 7);
    int idx2 = DispatchNodeIfType7_02156e2c(obj, 0x63);
    if (r) func_ov023_021dcae0(r, keys[idx2 + base * 8]);
    return 0;
}
