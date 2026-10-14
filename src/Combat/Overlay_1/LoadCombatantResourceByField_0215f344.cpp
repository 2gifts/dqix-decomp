#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

extern "C" void* func_ov017_021d612c(void* obj);
struct TaggedValue_021d60f4 { int type; union { int i; float f; } value; };
extern "C" int func_ov017_021d60f4(TaggedValue_021d60f4* a);
int AbsPlus159IfNegative0215ad2c(int x);

struct SearchObj0202ff34;

struct Obj020363b4;

extern const char data_ov001_02165745[];
struct Global021658b8 { int field0; char pad[0x8c - 0x4]; unsigned char field8c; };
extern Global021658b8 data_ov001_021658b8;

// USA: func_ov001_0215f344  (semantic: LoadCombatantResourceByField_0215f344)
extern "C" ARM int func_ov001_0215f344(void* obj) {
    char buf[0x20];
    int out1;
    int out2;

    void* field4 = func_ov017_021d612c(obj);
    GameState* battle = GameState::GetInstance();
    if (battle == 0) return 0;
    sprintf(buf, data_ov001_02165745, field4);
    int idx = AbsPlus159IfNegative0215ad2c(func_ov017_021d60f4((TaggedValue_021d60f4*)((char*)obj + 8)));
    GameObject* combatant = battle->GetGameObjectByIndex(idx);
    if (combatant == 0) return 0;
    SafeAllocator* alloc = (SafeAllocator*)data_ov001_021658b8.field0;
    ((BackgroundLoader*)((SearchObj0202ff34*)(int)BackgroundLoader::GetInstance()))->GetLoadedFileByName((const char*)(buf), (void**)(&out1), (unsigned int*)(&out2));
    if (out1 != 0) {
        ((Object3D*)((struct Obj020363b4*)combatant))->LoadType0AnimationPackageFromBCFGScript(alloc, (void*)out1, out2);
    } else {
        ((Object3D*)((struct Obj020363b4*)combatant))->LoadType0AnimationPackageFromBCFGScript((char const*)((int)buf), alloc);
    }
    return 1;
}
