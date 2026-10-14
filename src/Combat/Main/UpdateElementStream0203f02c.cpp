#include <globaldefs.h>
#include "Graphics/itcm/VRAMStaging.h"

extern "C" int func_0204027c(void* list, int a, int b, int c, int d);
extern "C" int func_020bb588(int a, int b, int c);

void RestorePairTables0207df90(char* obj);
void BackupPairTables0207dfac(char* obj);

struct List02040468;
struct Element0203f02c {
    char pad0[0x1c];
    int field0x1c;
    void* field0x20;
    int field0x24;
    char pad1[0xc];
    int field0x34;
};
struct Element0203f02c* GetValidElement02040468(struct List02040468* list, int index);

int CancelVRAMStagingOperation(int value);
int StageMemoryToVRAM(VRAMSubregion subregion, const void* data, unsigned int offset,
    unsigned int length, bool highPriority, bool allocateStagingSpace);

struct Obj0203f02c {
    struct List02040468* list;
    char pad1[0x24];
    short field0x28;
    char pad2[0x22];
    int field0x4c;
    char pad3[0xa];
    short field0x5a;
};

// USA: func_0203f02c
ARM void UpdateElementStream0203f02c(struct Obj0203f02c* obj, int param1, int param2, char* param3, int param5, int param6) {
    RestorePairTables0207df90(param3);

    int result;
    if (param5) {
        result = func_0204027c(obj->list, param1, param2, param5, param6);
    } else {
        result = func_0204027c(obj->list, param1, param2, 0, 0);
    }
    obj->field0x28 = result;

    struct Element0203f02c* element = GetValidElement02040468(obj->list, obj->field0x28);
    if (element != NULL) {
        int v = func_020bb588(element->field0x34, 0, 0);
        obj->field0x4c = ((unsigned int)v << 16) >> 13;
        CancelVRAMStagingOperation(obj->field0x5a);
        obj->field0x5a = StageMemoryToVRAM(VRAMSubregion_TexturePalette, element->field0x20, element->field0x24, element->field0x1c << 1, false, false);
    }

    BackupPairTables0207dfac(param3);
}
