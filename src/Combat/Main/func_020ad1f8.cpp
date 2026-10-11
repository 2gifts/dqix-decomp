#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void func_0202ae18();
extern "C" void func_0201bd04(void* obj, int a, int b);
extern "C" void func_0201bd3c(void* obj, int a, int b);
int GetField5cb0Value(char* obj);
struct Fields020407b4;
void SetFields0x44(struct Fields020407b4* obj, int a, int b, int c);

struct Vec3I020ad1f8 {
    int x;
    int y;
    int z;
};

struct Sub020ad1f8 {
    char pad[0xb4];
    unsigned short state;
};

struct Obj020ad1f8 {
    unsigned short field0;
    char pad[0x2700 - 2];
    struct Sub020ad1f8 sub;
};

// USA: func_020ad1f8
extern "C" ARM void func_020ad1f8(struct Obj020ad1f8* obj) {
    GameState* battle = GameState::GetInstance();
    func_ov017_0218b5b0();
    func_0202ae18();
    battle->GetPartyMemberByIndex(0);
    GameObject* unk = battle->GetUnknownGameObject();
    struct Vec3I020ad1f8 pos = *(struct Vec3I020ad1f8*)((char*)unk + 0x44);

    if (obj->field0 == 0x1198) {
        if (obj->sub.state == 1) {
            func_0201bd04(obj, 7, 0);
            func_0201bd04(obj, 8, 0);
            func_0201bd04(obj, 6, 0);
            func_0201bd3c(obj, 5, 0);
            return;
        }
        func_0201bd3c(obj, 7, 0);
        func_0201bd3c(obj, 8, 0);
        func_0201bd3c(obj, 6, 0);
        func_0201bd04(obj, 5, 0);
        if (pos.x < -0xc400 && pos.z < -0xf4cc) {
            SetFields0x44((struct Fields020407b4*)unk, -0xc4cc, 0x42b8, -0xe385);
        }
        return;
    } else if (obj->field0 == 0x10cd) {
        if (obj->sub.state == 3) {
            func_0201bd04(obj, 2, 0);
            func_0201bd04(obj, 1, 0);
            func_0201bd3c(obj, 0xa, 0);
            return;
        }
        func_0201bd3c(obj, 2, 0);
        func_0201bd3c(obj, 1, 0);
        func_0201bd04(obj, 0xa, 0);
        if (pos.x > -0xa66 && pos.x < 0x999 && pos.z > 0x2999) {
            SetFields0x44((struct Fields020407b4*)unk, 0, -0x5ccc, 0x2000);
        }
        return;
    } else if (obj->field0 == 0x1130) {
        int v = GetField5cb0Value((char*)battle);
        if (obj->sub.state == 5 || v >= 0x13) {
            func_0201bd04(obj, 0x17, 0);
            func_0201bd04(obj, 1, 0);
            func_0201bd3c(obj, 0x19, 0);
            return;
        }
        func_0201bd3c(obj, 0x17, 0);
        func_0201bd3c(obj, 1, 0);
        func_0201bd04(obj, 0x19, 0);
        if (pos.x > -0x2800 && pos.x < -0x1333 && pos.z > 0x2800) {
            SetFields0x44((struct Fields020407b4*)unk, -0x1e66, -0x5ccc, 0x1ccc);
        }
    }
}
