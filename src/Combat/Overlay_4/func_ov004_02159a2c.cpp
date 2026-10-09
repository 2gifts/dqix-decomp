#include <globaldefs.h>
#include "GameState/GameState.h"

struct Battle021707d8 { char pad[0x32]; short members[4]; short memberCount; };
struct Data021707d8 { char pad[8]; Battle021707d8* battle; char unk[8]; };
extern Data021707d8 data_ov004_021707d8;

struct MemberIds { int ids[4]; };
extern MemberIds data_ov004_0216fb50;

extern "C" int _Z28DispatchNodeIfType7_02156e2cPvi(void* a, int key);
extern "C" void* _Z20GetEntryFor_021570a4Pvi(void* obj, int index);

struct Container020dedd0;
struct Element020de650 { char pad[8]; unsigned int field8 : 4; };
extern "C" struct Container020dedd0* func_ov004_02156fd4(void* obj, int key);
extern "C" struct Element020de650* _Z24FindElementByKey020dedd0P17Container020dedd0i(struct Container020dedd0* c, int key);
extern "C" int func_020dd4c4(int id, void* node);
extern "C" int func_ov004_02159bcc(void* obj);
extern "C" void func_ov011_021848a0(void* obj, int val);

// USA: func_ov004_02159a2c
extern "C" ARM int func_ov004_02159a2c(void* obj) {
    int i;
    GameState::GetInstance();
    int key = _Z28DispatchNodeIfType7_02156e2cPvi(obj, 0x5b);
    if (key < 0) return 0;
    void* entry = _Z20GetEntryFor_021570a4Pvi(obj, key & 0xff);
    if (!entry) return 0;
    struct Container020dedd0* node = func_ov004_02156fd4(obj, 5);
    if (!node) return 0;
    struct Element020de650* elem = _Z24FindElementByKey020dedd0P17Container020dedd0i(node, *(short*)entry);
    if (!elem) return 0;

    int ok = elem->field8 <= 7;
    if (ok) {
        MemberIds members = data_ov004_0216fb50;
        Battle021707d8* battle = data_ov004_021707d8.battle;
        int count = battle->memberCount;
        for (i = 0; i < count; i++) {
            members.ids[i] = battle->members[i];
        }
        int j;
        for (j = 0; j < count; j++) {
            if (!func_020dd4c4((signed char)members.ids[j], elem)) break;
        }
        if (j == count) {
            func_ov004_02159bcc(obj);
        } else {
            func_ov011_021848a0(obj, 0x38b);
        }
    } else {
        func_ov011_021848a0(obj, 0x2384);
    }
    return 0;
}
