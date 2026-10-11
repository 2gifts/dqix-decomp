#include <globaldefs.h>
#if defined(jpn)
enum { kRegionalFieldOffset = 0x43c };
#else
enum { kRegionalFieldOffset = 0x41c };
#endif

#include "Graphics/LightingManager.h"
#include "GameState/GameState.h"

struct Manager_1f2a4;
struct Element_1f2a4;
struct Element_1f2a4* GetElementByIndexStride0x20(struct Manager_1f2a4* manager, int index);
struct Struct02013380;
void SetFlag0x40AndToggle0x4(struct Struct02013380* obj, int unused, int clear4);

struct Entry02019678 {
    unsigned short field0;
    unsigned short field2;
};

// USA: func_02019678  (semantic: ProcessNodeFlags02019678)
extern "C" ARM void func_02019678(void* a) {
    GameState::GetInstance();
    LightingManager::GetInstance();
    void* node = *(void**)((char*)a + kRegionalFieldOffset);
    while (node != 0) {
        for (int j = 0; j < *(int*)((char*)node + 0x14); j++) {
            GetElementByIndexStride0x20((struct Manager_1f2a4*)((char*)node + 4), j);
            struct Entry02019678* entry = (struct Entry02019678*)((char*)(*(void**)((char*)node + 0x44)) + j * 0x70);
            if (entry->field2 & 0x40) continue;
            int rawId = *(int*)node;
            int id = 0;
            if (rawId >= 0) id = rawId & 0xff;
            SetFlag0x40AndToggle0x4((struct Struct02013380*)entry, id, entry->field2 & 0x20);
        }
        node = *(void**)((char*)node + 0x54);
    }
}
