// JPN: func_ov017_02198cfc
#if defined(jpn)
enum { RegionOffset6c = 0x8c };
#else
enum { RegionOffset6c = 0x6c };
#endif

#include <globaldefs.h>
#include "GameState/GameState.h"

struct AreaNode_0219814c {
    char pad00[0x2c];
    unsigned char areaId;
    char pad2d[0x70 - 0x2d];
    struct AreaNode_0219814c* next;
};

struct Anchor_0219814c {
    unsigned int w[3];
};

struct EventArgs_0219814c {
    int field_0x0;
    int areaId;
    char pad08[0x30 - 0x08];
    int field_0x30;
};

extern "C" void* func_02012fe4(void);
extern "C" void* func_0205ec34(void);
void* GetPointerFromArray0x3c(unsigned char* obj, unsigned int index);
extern "C" int func_02094b9c(struct AreaNode_0219814c* node, struct Anchor_0219814c* anchor);
struct AreaNode_0219814c* GetFieldAt0x188(unsigned char* obj);
void SetFieldAt0x188(unsigned char* obj, int value);
extern "C" int _Z28LookupAndForEachNode020649b0PviS_(void* a, int mode, void* c);
extern "C" void func_0206f81c(void* p);

// USA: func_ov017_0219814c
extern "C" ARM void func_ov017_0219814c(void) {
    GameState* battle = GameState::GetInstance();
    void* ctx = func_02012fe4();
    void* events = func_0205ec34();
    GameObject* combatant = battle->GetUnknownGameObject();
    struct Anchor_0219814c anchor = *(struct Anchor_0219814c*)((char*)combatant + 0x44);
    struct EventArgs_0219814c args;
    struct AreaNode_0219814c* node;
    struct AreaNode_0219814c* current;

    node = (struct AreaNode_0219814c*)GetPointerFromArray0x3c((unsigned char*)ctx + RegionOffset6c, 3);
    while (node != 0) {
        if (func_02094b9c(node, &anchor)) {
            break;
        }
        node = node->next;
    }

    current = GetFieldAt0x188((unsigned char*)combatant);
    if (current != 0) {
        if (node == 0) {
            args.areaId = current->areaId;
            if (_Z28LookupAndForEachNode020649b0PviS_(events, 5, &args)) {
                func_0206f81c(&args);
            }
        } else if (node != current) {
            args.areaId = current->areaId;
            if (_Z28LookupAndForEachNode020649b0PviS_(events, 5, &args)) {
                func_0206f81c(&args);
            }
            args.field_0x30 = 0;
            args.areaId = node->areaId;
            if (_Z28LookupAndForEachNode020649b0PviS_(events, 2, &args)) {
                func_0206f81c(&args);
            }
        }
    } else if (node != 0) {
        args.areaId = node->areaId;
        if (_Z28LookupAndForEachNode020649b0PviS_(events, 2, &args)) {
            func_0206f81c(&args);
        }
    }
    SetFieldAt0x188((unsigned char*)combatant, (int)node);
}
