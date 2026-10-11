#include <globaldefs.h>
#include "Graphics/LightingManager.h"

extern "C" void* func_02012fe4(void);
extern "C" int func_ov017_021d60f4(void* a);
extern "C" void func_ov001_021601f8(void* a, void* b);

struct Node_02160338 { char pad0[0x44]; int field44; char pad1[0x54 - 0x48]; struct Node_02160338* next; };
struct Big_02160338 { 
#if defined(jpn)
    char pad0[0x430];
#else
    char pad0[0x410];
#endif
 int field410; char pad1[0x41c - 0x414]; struct Node_02160338* field41c; char pad2[0x834 - 0x420]; unsigned char field834; };
struct DataStruct_02160338 { char pad[0x90]; int field90; };

// USA: func_ov001_02160338  (semantic: SetOrInitFieldTable_02160338)
extern "C" ARM int func_ov001_02160338(void* obj) {
    Big_02160338* big = (Big_02160338*)func_02012fe4();
    DataStruct_02160338* d = (DataStruct_02160338*)LightingManager::GetInstance();
    if (big->field834 != 0) {
        return 1;
    }
    d->field90 = func_ov017_021d60f4(obj);
    if (big->field410 == 1) {
        Node_02160338* node = big->field41c;
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
