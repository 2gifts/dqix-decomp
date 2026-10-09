#include <globaldefs.h>
#include "Graphics/Model3D.h"

struct Holder021e509c {
    char pad0[0xc];
    char* slots;
};

struct Param021e509c {
    char pad0[8];
    unsigned char slotA;
    unsigned char slotB;
    char padA[2];
    const char* boneName;
};

struct Record021e509c {
    char pad0[8];
    Model3D* model;
    char padC[0xac - 0xc];
    int fieldAC;
    char padB0[2];
    short linkedId;
    short boneIndex;
};

extern "C" void* func_02057924(void);
Record021e509c* GetInlineRecordByBattleId(void* obj, int id);
extern "C" int* _Z28GetSlotPtr_021e8cf0_021e8cf0Pci(char* base, int idx);
extern Holder021e509c data_ov025_021ef988;

// USA: func_ov025_021e509c
extern "C" ARM int func_ov025_021e509c(Param021e509c* p) {
    void* obj = func_02057924();
    int* slotA = _Z28GetSlotPtr_021e8cf0_021e8cf0Pci(data_ov025_021ef988.slots, p->slotA);
    int* slotB = _Z28GetSlotPtr_021e8cf0_021e8cf0Pci(data_ov025_021ef988.slots, p->slotB);
    if (slotA == 0 || slotB == 0) {
        return 1;
    }
    int idB = *slotB;
    Record021e509c* recA = GetInlineRecordByBattleId(obj, *slotA);
    Record021e509c* recB = GetInlineRecordByBattleId(obj, idB);
    if (recA == 0 || recB == 0) {
        return 1;
    }
    if (recB->fieldAC != 0) {
        return 1;
    }
    recA->linkedId = idB;
    if (p->boneName != 0 && recB->model != 0) {
        recA->boneIndex = recB->model->GetBoneIndex(p->boneName);
    }
    return 1;
}
