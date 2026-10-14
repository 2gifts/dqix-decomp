#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Graphics/Model3D.h"
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

extern "C" void* func_ov017_021d612c(void* obj);
extern "C" int func_ov017_021d60f4(void* a);
int AbsPlus159IfNegative0215ad2c(int x);

struct SearchObj0202ff34;

extern const char data_ov001_02165745[];
extern SafeAllocator* data_ov001_021658b8[8];

// USA: func_ov001_0215ef54  (semantic: AllocateAndFlagCombatantResources_0215ef54)
extern "C" ARM int func_ov001_0215ef54(char* obj, int count) {
    void* rawArg = obj;
    obj += 0x8;
    void* field4 = func_ov017_021d612c(rawArg);
    GameState* battle = GameState::GetInstance();
    if (battle == 0) return 0;

    char buf[0x20];
    sprintf(buf, data_ov001_02165745, field4);

    SafeAllocator* alloc = data_ov001_021658b8[0];
    void* newBuf = alloc->Allocate(0xac);
    if (newBuf == 0) return 0;
    ((Model3D*)((unsigned char*)newBuf))->Clear();

    int out1;
    int out2;
    ((BackgroundLoader*)((SearchObj0202ff34*)(int)BackgroundLoader::GetInstance()))->GetLoadedFileByName((const char*)(buf), (void**)(&out1), (unsigned int*)(&out2));
    if (out1 != 0) {
        ((Model3D*)newBuf)->CopyAndProcessRawFile(&alloc->allocUnion, (void*)out1, out2, Model3D::TextureStagingMode_Normal);
    } else {
        ((Model3D*)newBuf)->LoadFromFile(buf, &alloc->allocUnion, Model3D::TextureStagingMode_Normal);
    }

    for (int i = 1; i < count; i++) {
        int t = func_ov017_021d60f4(obj);
        obj += 0x8;
        int idx = AbsPlus159IfNegative0215ad2c(t);
        GameObject* combatant = battle->GetGameObjectByIndex(idx);
        if (combatant != 0 && *(void**)((char*)combatant + 0x8) != 0) {
            ((Model3D*)(*(void**)((char*)combatant + 0x8)))->ApplyTexturesFromModel((Model3D*)newBuf);
        }
    }
    return 1;
}
