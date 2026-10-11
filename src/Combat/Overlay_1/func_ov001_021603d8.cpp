#include <globaldefs.h>
#include "Graphics/LightingManager.h"


extern "C" void* func_02012fe4(void);
extern "C" int func_ov017_021d60f4(void* a);
extern "C" void func_ov001_021601f8(void* a, void* b);
extern "C" void _ZN15LightingManager25RecomputeAdvancedLightingEv(void* d);
extern "C" void func_02016874(void* big);

struct Node_021603d8 { char pad0[0x44]; int field44; char pad1[0x54 - 0x48]; struct Node_021603d8* next; };
struct Big_021603d8 {
#if defined(jpn)
    char pad0[0x430];
#else
    char pad0[0x410];
#endif
    int field410;
#if defined(jpn)
    char pad1[0x43c - 0x434];
#else
    char pad1[0x41c - 0x414];
#endif
    struct Node_021603d8* field41c;
#if defined(jpn)
    char pad2[0x852 - 0x440];
#else
    char pad2[0x832 - 0x420];
#endif
    unsigned char field832;
    unsigned char field833;
    unsigned char field834;
};
struct DataStruct_021603d8 { char pad0[0x90]; int field90; int field94; int field98; };

struct TableRow_021603d8 {
    int field0;
    unsigned char pad0[0x10 - 0x4];
    int field10;
    int field14;
    unsigned char pad1[0x2c - 0x18];
    int field2c;
    int field30;
};
extern TableRow_021603d8 data_ov001_02165880;

struct Cache_021603d8 {
    unsigned char pad0[0x10];
    int field10;
    int field14;
    int field18;
    int field1c;
};
extern Cache_021603d8 data_ov001_02164d14;

extern int data_ov001_02164d24[];

// USA: func_ov001_021603d8
// JPN: func_ov001_021619ec
extern "C" ARM int func_ov001_021603d8(void* obj) {
    Big_021603d8* big = (Big_021603d8*)func_02012fe4();
    DataStruct_021603d8* d = (DataStruct_021603d8*)LightingManager::GetInstance();
    int idx = func_ov017_021d60f4(obj);
    d->field98 = idx;
    if (!(data_ov001_02165880.field14 & 1)) {
        data_ov001_02164d14.field10 = data_ov001_02165880.field0;
        data_ov001_02164d14.field14 = data_ov001_02165880.field10;
        data_ov001_02164d14.field18 = data_ov001_02165880.field30;
        data_ov001_02164d14.field1c = data_ov001_02165880.field2c;
        data_ov001_02165880.field14 |= 1;
    }
    d->field94 = data_ov001_02164d24[idx];

    if (big->field410 == 1) {
        if (big->field834 != 0) {
            return 1;
        }
        Node_021603d8* node = big->field41c;
        while (node != NULL) {
            if (node->field44 != 0) {
                func_ov001_021601f8((void*)node->field44, (char*)node + 4);
            }
            node = node->next;
        }
        big->field834 = 1;
    } else {
        int local[4];
        local[0] = data_ov001_02165880.field0;
        local[1] = data_ov001_02165880.field10;
        local[2] = data_ov001_02165880.field30;
        local[3] = data_ov001_02165880.field2c;
        d->field94 = local[idx];
        d->field90 = 0;
        _ZN15LightingManager25RecomputeAdvancedLightingEv(d);
    }

    big->field832 = 1;
    big->field833 = 1;
    func_02016874(big);
    return 1;
}
