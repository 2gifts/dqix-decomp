#include <globaldefs.h>
#include "GameState/GameState.h"

struct ZoneNode02198e30 {
    unsigned short id;
    short param;
    char area[0x10 - 4];
    unsigned int flags;
    char pos[0x2c - 0x14];
    struct ZoneNode02198e30* next;
};

struct ZoneMgr02198e30 {
    char pad0[0x491];
    signed char activeId;
    char pad1[0x494 - 0x492];
    struct ZoneNode02198e30* head;
};

struct LookupBuf02198e30 {
    char pad0[4];
    int id;
    char pad1[0x30 - 8];
    int field30;
};

extern "C" struct ZoneMgr02198e30* func_0205ec34(void);
extern "C" int func_020321e0(Vector3fix* pos, void* nodePos, int param, void* area, unsigned int flags);
extern "C" int _Z28LookupAndForEachNode020649b0PviS_(void* a, int mode, void* c);
extern "C" void func_0206f81c(void* p);

// USA: func_ov017_02198e30
extern "C" ARM void func_ov017_02198e30(unsigned char* self) {
    GameState* gs = GameState::GetInstance();
    struct ZoneMgr02198e30* mgr = func_0205ec34();
    struct ZoneNode02198e30* node = mgr->head;
    GameObject* obj = gs->GetUnknownGameObject();

    for (; node != 0; node = node->next) {
        if (func_020321e0(&obj->obj3D_.position_, node->pos, node->param, node->area, node->flags)) {
            break;
        }
    }

    signed char cur = mgr->activeId;

    if (node == 0) {
        if (cur > -1) {
            struct LookupBuf02198e30 c1;
            c1.id = cur;
            if (_Z28LookupAndForEachNode020649b0PviS_(mgr, 5, &c1)) {
                func_0206f81c(&c1);
            }
            mgr->activeId = -1;
        }
        return;
    }

    if (node->id == cur) return;

    struct LookupBuf02198e30 c2;
    if (cur > -1) {
        c2.id = cur;
        if (_Z28LookupAndForEachNode020649b0PviS_(mgr, 5, &c2)) {
            func_0206f81c(&c2);
        }
        c2.id = -1;
        c2.field30 = 0;
    }

    self[0x4446] = node->id;
    c2.id = node->id;
    if (_Z28LookupAndForEachNode020649b0PviS_(mgr, 2, &c2)) {
        func_0206f81c(&c2);
    }

    unsigned short id = node->id;
    func_0205ec34()->activeId = id;
}
