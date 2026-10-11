#include <globaldefs.h>
#include "Graphics/LightingManager.h"
#include "GameState/GameState.h"

extern "C" void* func_02012fe4(void);
extern "C" void func_ov001_021601f8(void* a, void* b);

struct TableRow02160504 {
    int field0;
    char pad4[0xc - 4];
    int flag;
    int field10;
    char pad14[0x2c - 0x10 - 4];
    int field2c;
    int field30;
};
extern TableRow02160504 data_ov001_02165880;

struct Cache02160504 { char pad[0x20]; int f20, f24, f28, f2c; };
extern Cache02160504 data_ov001_02164d14;

extern int data_ov001_02164d34[];

struct Node02160504 { char pad0[0x44]; int field44; char pad1[0x54 - 0x48]; Node02160504* next; };
struct Big02160504 {
    
#if defined(jpn)
    char pad0[0x430];
#else
    char pad0[0x410];
#endif

    int field410;
    char pad1[0x41c - 0x414];
    Node02160504* field41c;
    char pad2[0x834 - 0x420];
    unsigned char field834;
};
struct DataStruct02160504 { char pad0[0x94]; int field94; int field98; };

// USA: func_ov001_02160504
extern "C" ARM int func_ov001_02160504(void) {
    GameState* battle = GameState::GetInstance();
    Big02160504* big = (Big02160504*)func_02012fe4();
    DataStruct02160504* d = (DataStruct02160504*)LightingManager::GetInstance();
    if (big->field834 != 0) return 1;
    int idx = battle->GetTimeOfDay();
    d->field98 = idx;
    if (!(data_ov001_02165880.flag & 1)) {
        data_ov001_02164d14.f20 = data_ov001_02165880.field0;
        data_ov001_02164d14.f24 = data_ov001_02165880.field10;
        data_ov001_02164d14.f28 = data_ov001_02165880.field30;
        data_ov001_02164d14.f2c = data_ov001_02165880.field2c;
        data_ov001_02165880.flag |= 1;
    }
    d->field94 = data_ov001_02164d34[idx];
    if (big->field410 == 1) {
        Node02160504* node = big->field41c;
        while (node != NULL) {
            if (node->field44 != 0) {
                func_ov001_021601f8((void*)node->field44, (char*)node + 4);
            }
            node = node->next;
        }
        big->field834 = 1;
    }
    return 1;
}
