#include <globaldefs.h>

extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* func_0205ec34();
extern "C" void* _Z17GetPtrField0x2a04P9GameState(void* battle);
extern "C" int func_0209645c(void* list, int value);
extern "C" int _Z20GetPackedNibbleFieldP25PackedNibbleArray0206e120i(void* arr, int index);
extern "C" void _Z20SetNibbleBit0206e218Phi(void* arr, int index);
extern "C" void _Z24SetBitWithOffset0206eb64Phii(void* arr, int bit, int value);
extern "C" int _Z30SumCombatantKeyMatches02086aecP11Obj02086aeci(void* obj, int key);
extern "C" int _Z30DecrementKeyEverywhere02086d88Phi(void* obj, int key);

struct Node02095d30 {
    unsigned short id : 9;
    unsigned short pad9 : 1;
    unsigned short bit10 : 1;
    unsigned short count : 5;
    unsigned short list0[13];
    unsigned short count1;
    short list1[5];
    struct Node02095d30* next;
};

struct List02095d30 {
    unsigned char pad[0xa4];
    struct Node02095d30* head;
};

// USA: func_02095d30
extern "C" ARM int func_02095d30(struct List02095d30* list, int value, int mode) {
    if (list->head == 0) {
        return 0;
    }
    void* gs = _ZN9GameState11GetInstanceEv();
    void* nibbles = func_0205ec34();
    void* obj = _Z17GetPtrField0x2a04P9GameState(gs);
    struct Node02095d30* cur;
    for (cur = list->head; cur != 0; cur = cur->next) {
        if (cur->id != value) {
            continue;
        }
        int ok = (_Z20GetPackedNibbleFieldP25PackedNibbleArray0206e120i(nibbles, value) == 2);
        if (ok != 0) {
            if (!cur->bit10) {
                return 0;
            }
            _Z20SetNibbleBit0206e218Phi(nibbles, value);
            func_0209645c(list, value);
            if (mode != 0) {
                int i = 0;
                int x = 0;
                while (i < cur->count) {
                    _Z24SetBitWithOffset0206eb64Phii(nibbles, cur->list0[i], x);
                    i++;
                }
            }
            int j;
            int n;
            int k = 0;
            for (j = 0; j < cur->count1; j++) {
                short v = cur->list1[j];
                if (v <= 0) {
                    continue;
                }
                n = _Z30SumCombatantKeyMatches02086aecP11Obj02086aeci(obj, v);
                for (k = 0; k < n; k++) {
                    _Z30DecrementKeyEverywhere02086d88Phi(obj, cur->list1[j]);
                }
            }
            break;
        }
    }
    if (cur == 0) { return 0; }
    return 1;
}