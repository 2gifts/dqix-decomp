#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_0205ec34();
struct GameState;
void* GetPtrField0x2a04_02010828(GameState*);
extern "C" int func_0209645c(void* list, int value);
struct PackedNibbleArray0206e120;
int GetPackedNibbleField(PackedNibbleArray0206e120*, int);
void SetNibbleBit0206e218(unsigned char*, int);
void SetBitWithOffset0206eb64(unsigned char*, int, int);
struct Obj02086aec;
int SumCombatantKeyMatches02086aec(Obj02086aec*, int);
int DecrementKeyEverywhere02086d88(unsigned char*, int);

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
    void* gs = GameState::GetInstance();
    void* nibbles = func_0205ec34();
    void* obj = GetPtrField0x2a04_02010828((GameState*)gs);
    struct Node02095d30* cur;
    for (cur = list->head; cur != 0; cur = cur->next) {
        if (cur->id != value) {
            continue;
        }
        int ok = (GetPackedNibbleField((PackedNibbleArray0206e120*)nibbles, value) == 2);
        if (ok != 0) {
            if (!cur->bit10) {
                return 0;
            }
            SetNibbleBit0206e218((unsigned char*)nibbles, value);
            func_0209645c(list, value);
            if (mode != 0) {
                int i = 0;
                int x = 0;
                while (i < cur->count) {
                    SetBitWithOffset0206eb64((unsigned char*)nibbles, cur->list0[i], x);
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
                n = SumCombatantKeyMatches02086aec((Obj02086aec*)obj, v);
                for (k = 0; k < n; k++) {
                    DecrementKeyEverywhere02086d88((unsigned char*)obj, cur->list1[j]);
                }
            }
            break;
        }
    }
    if (cur == 0) { return 0; }
    return 1;
}
