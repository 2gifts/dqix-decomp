#include <globaldefs.h>
#include "GameState/GameState.h"

int GetField0x3b0Value(GameState* battleStruct);
extern "C" int func_ov000_0215e9fc(int a, short* buf, int max, int start);
extern "C" int func_ov000_0215ec1c(int a, short* buf, int max, int start);
extern "C" void* _Z18GetSlotPtr02160f20Pv(void* obj);
int CheckSubstructFlag0x10(unsigned char* obj);
extern "C" void func_ov025_021dc220(void* obj);

struct ListNode021dc168 {
    char pad0[0x20];
    unsigned short id;
    char pad22[0xe];
    struct ListNode021dc168* next;
};

struct List021dc168 {
    char pad0[0x10];
    struct ListNode021dc168* head;
};

struct Obj021dc168 {
    char pad0[0x29c];
    int field29c;
    char pad2a0[0xeac - 0x2a0];
    int field_eac;
};

// USA: func_ov025_021dc168
extern "C" ARM void func_ov025_021dc168(struct Obj021dc168* obj) {
    GameState* bs = GameState::GetInstance();
    int field29c = obj->field29c;
    GetField0x3b0Value(bs);
    func_ov017_0218b5b0();

    short buf[12];
    int n = 0;
    n = n + func_ov000_0215e9fc(field29c, buf, 12, n);
    n = n + func_ov000_0215ec1c(field29c, buf + n, 12 - n, 0);

    if (obj->field_eac == 2) {
        struct List021dc168* list = (struct List021dc168*)_Z18GetSlotPtr02160f20Pv(obj);
        struct ListNode021dc168* node = list->head;
        int ready = 1;
        while (node != NULL) {
            GameObject* combatant = bs->GetCombatantByIndex(node->id);
            if (combatant != NULL && CheckSubstructFlag0x10((unsigned char*)combatant)) {
                ready = 0;
                break;
            }
            node = node->next;
        }
        if (ready) {
            func_ov025_021dc220(obj);
        }
    }
}
