#if defined(jpn)
enum { RegionalOffset = 0x43c };
#else
enum { RegionalOffset = 0x41c };
#endif

#include <globaldefs.h>
#include "Graphics/LightingManager.h"
#include "GameState/GameState.h"

struct Manager_1f2a4;
struct Element_1f2a4;
struct Element_1f2a4* GetElementByIndexStride0x20(struct Manager_1f2a4* manager, int index);

struct Struct02013380;
void SetFlag0x40AndToggle0x4(struct Struct02013380* obj, int unused, int clear4);


struct Entry02019568 {
    unsigned short field0;
    unsigned short field2;
};

// USA: func_02019568
// JPN: func_02019568
ARM void ProcessBattlerEffects02019568(void* a, int b) {
    GameState::GetInstance();
    void* d = LightingManager::GetInstance();
    int shiftAmt = *(int*)((char*)d + 0x98);

    void* node = *(void**)((char*)a + RegionalOffset);
    while (node != NULL) {
        int rawId = *(int*)node;
        int id = 0;
        if (rawId >= 0) {
            id = rawId & 0xff;
        }
        for (int j = 0; j < *(int*)((char*)node + 0x14); j++) {
            struct Element_1f2a4* e2 = GetElementByIndexStride0x20((struct Manager_1f2a4*)((char*)node + 4), j);
            struct Entry02019568* entry = (struct Entry02019568*)((char*)(*(void**)((char*)node + 0x44)) + j * 0x70);

            if (entry->field2 & 4) {
                entry->field2 &= ~0x20;
            } else {
                entry->field2 |= 0x20;
            }

            if (*(unsigned short*)((char*)e2 + 6) & 0x10) {
                SetFlag0x40AndToggle0x4((struct Struct02013380*)entry, id, 1);
            }

            if (!(*(unsigned short*)((char*)e2 + 6) & (1 << shiftAmt))) {
                SetFlag0x40AndToggle0x4((struct Struct02013380*)entry, id, 0);
            }

            if (b != 0) {
                if (*(unsigned short*)((char*)e2 + 6) & 0x20) {
                    SetFlag0x40AndToggle0x4((struct Struct02013380*)entry, id, 0);
                }
            } else {
                if (*(unsigned short*)((char*)e2 + 6) & 0x40) {
                    SetFlag0x40AndToggle0x4((struct Struct02013380*)entry, id, 0);
                }
            }

            entry->field2 &= ~0x40;
        }
        node = *(void**)((char*)node + 0x54);
    }
}
