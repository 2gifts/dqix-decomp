// JPN: func_ov017_0219c8cc
#if defined(jpn)
enum { RegionOffset840 = 0x860 };
#else
enum { RegionOffset840 = 0x840 };
#endif

#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_0202ae18(void);
extern "C" void* func_0205ec34(void);
extern "C" void* func_02012fe4(void);
extern "C" int func_0202c508(void* obj);
struct Obj020ad4c4;
extern int CheckAndInvoke020ad4c4(struct Obj020ad4c4* obj);
extern "C" int func_02098080(void* p);
struct U16Field0x6_020375f8;
extern "C" extern unsigned short _ZNK8Object3D10GetField06Ev(struct U16Field0x6_020375f8* obj);
extern "C" int func_0206e558(void* obj);
extern "C" int func_ov017_0219c774(int a, int b, int c);

// USA: func_ov017_0219bddc  (semantic: EvaluateCombatantTransition_0219bddc)
extern "C" ARM int func_ov017_0219bddc(unsigned char* p0) {
    func_ov017_0218b5b0();
    GameState* bs = GameState::GetInstance();
    void* search = func_0202ae18();
    void* obj8 = func_0205ec34();
    void* obj4 = func_02012fe4();
    GameObject* c7 = bs->GetGameObjectByIndex(0);
    GameObject* c6 = bs->GetProtagonist();

    if (func_0202c508(search) != 0) {
        return 0;
    }
    if (c7 == NULL) {
        return 0;
    }
    if (c6 == NULL) {
        return 0;
    }

    int result = 0;
    if (CheckAndInvoke020ad4c4((struct Obj020ad4c4*)obj4) != 0) {
        result = 1;
        goto end;
    }
    if (func_02098080((char*)obj4 + RegionOffset840) != 0) {
        result = 1;
        p0[0] = (unsigned char)result;
        goto end;
    }

    unsigned short v1 = _ZNK8Object3D10GetField06Ev((struct U16Field0x6_020375f8*)c7);
    unsigned short v2 = _ZNK8Object3D10GetField06Ev((struct U16Field0x6_020375f8*)c6);
    if (v1 != v2) {
        return result;
    }

    if (func_0206e558(obj8) != 0) {
        result = 1;
    }
    if (func_ov017_0219c774(*(int*)((char*)obj4 + 8), 0, 0) != 0) {
        result = 1;
    }

end:
    return result;
}
