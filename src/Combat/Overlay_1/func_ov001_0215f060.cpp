#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "World/Object3D.h"
#include "std_library_functions.h"

extern "C" void* func_ov017_021d612c(void* obj);
extern "C" int func_ov017_021d60f4(void* a);
extern "C" int _Z28AbsPlus159IfNegative0215ad2ci(int x);

extern SafeAllocator* data_ov001_021658b8[8];
extern const char data_ov001_02165745[];
extern const char data_ov001_02165791[];
extern const char data_ov001_02165798[];
extern const char data_ov001_0216579f[];
extern const char data_ov001_021657a6[];

// USA: func_ov001_0215f060
extern "C" ARM int func_ov001_0215f060(char* obj, int count) {
    void* rawArg = obj;
    obj += 0x8;
    void* name = func_ov017_021d612c(rawArg);
    GameState* state = GameState::GetInstance();
    SafeAllocator* alloc = data_ov001_021658b8[0];

    char buf[0x20];
    sprintf(buf, data_ov001_02165745, name);

    int slot = -1;
    if (strstr(buf, data_ov001_02165791) != NULL) {
        slot = 0;
    } else if (strstr(buf, data_ov001_02165798) != NULL) {
        slot = 1;
    } else if (strstr(buf, data_ov001_0216579f) != NULL) {
        slot = 2;
    } else if (strstr(buf, data_ov001_021657a6) != NULL) {
        slot = 3;
    }
    if (slot < 0) return 0;

    void* data;
    unsigned int length;
    BackgroundLoader::GetInstance()->GetLoadedFileByName(buf, &data, &length);

    for (int i = 1; i < count; i++) {
        int id = func_ov017_021d60f4(obj);
        obj += 0x8;
        GameObject* object = state->GetGameObjectByIndex(_Z28AbsPlus159IfNegative0215ad2ci(id));
        if (object != NULL) {
            if (data != NULL) {
                object->obj3D_.LoadType0AnimationFromFileInMemory(slot, alloc, data, length);
            } else {
                object->obj3D_.LoadType0AnimationFromFile(slot, buf, alloc);
            }
        }
    }
    return 1;
}
