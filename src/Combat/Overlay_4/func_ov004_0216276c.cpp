#include <globaldefs.h>
#include "GameState/GameState.h"
#include "System/Matrix.h"

class SlotNode0216276c {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6();
    virtual void SetPosition(const Vector3i&);
    virtual Vector3i GetPosition();
    virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12();
    virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16();
    virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20();
    virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
    virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28();
    virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32();
    virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36();
    virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40();
    virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44();
    virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48();
    virtual void v49(); virtual void v50(); virtual void v51(); virtual void v52();
    virtual void v53(); virtual void SetState(int); virtual void v55();
    virtual void SetValue(int);
    char padding4[8];
    unsigned char flags;
    char paddingd[0x2b];
    short value;
};
struct Equipment0216276c {
    char padding[0x16c];
    unsigned short items[13];
    unsigned char levels[13];
};
struct Selection0216276c { char padding[7]; unsigned char state; char padding8[0x14]; int combatant; };
extern Selection0216276c data_ov004_021707e8;
extern int data_ov004_0216fe5c[];
extern unsigned char data_ov004_02170845[];
Equipment0216276c* GetFieldAt0x150(unsigned char*);
extern "C" void* func_ov011_021849c8(void*);
extern "C" void func_ov004_0215e574(void*, int, int, int, int);
extern "C" SlotNode0216276c* func_ov023_021f6880(void*, int);
int GetFlagBitFromField150_0215eb20(void*, int);
int CheckAfterTwoCalls_0215e460();
void SetField38IfState8_0215e49c(void*, int, short);
typedef void (*SetSlotValue0216276c)(void*, int, int);
extern "C" int func_ov004_0215e4e8(void*, short);
extern "C" SlotNode0216276c* func_ov004_0215e47c(void*, int);

// USA: func_ov004_0216276c
extern "C" ARM int func_ov004_0216276c(void* self) {
    data_ov004_021707e8.state = 0x68;
    GameObject* combatant = GetCombatantWithFlag0x100(GameState::GetInstance(), data_ov004_021707e8.combatant);
    if (!combatant) return 0;
    Equipment0216276c* equipment = GetFieldAt0x150(reinterpret_cast<unsigned char*>(combatant));
    if (!equipment) return 0;
    void* list = func_ov011_021849c8(self);
    func_ov004_0215e574(self, 12, 255, 0, 0);
    unsigned char index = 0;
    while (index < 12) {
        SlotNode0216276c* node = func_ov023_021f6880(list, index + 0x51);
        if (!node) { ++index; continue; }
        node->flags |= 8;
        node = func_ov023_021f6880(list, index + 13);
        if (!node) { ++index; continue; }
        node->flags |= 8;
        node = func_ov023_021f6880(list, index + 25);
        if (!node) { ++index; continue; }
        node->flags |= 8;
        node = func_ov023_021f6880(list, index + 38);
        if (!node) { ++index; continue; }
        node->flags |= 8;
        ++index;
    }
    unsigned char row = 0;
    int* slots = data_ov004_0216fe5c;
    for (int index = 0; index < 12; ++index) {
        int tableIndex = index + 1;
        if (!GetFlagBitFromField150_0215eb20(combatant, slots[tableIndex]) || !data_ov004_02170845[tableIndex]) continue;
        SlotNode0216276c* node = func_ov023_021f6880(list, row + 13);
        if (!node) continue;
        node->flags &= ~8;
        node = func_ov023_021f6880(list, row + 25);
        if (!node) continue;
        node->flags &= ~8;
        if (CheckAfterTwoCalls_0215e460())
            reinterpret_cast<SetSlotValue0216276c>(SetField38IfState8_0215e49c)(self, row + 13, 4);
        else
            reinterpret_cast<SetSlotValue0216276c>(SetField38IfState8_0215e49c)(self, row + 13, slots[tableIndex] + 4);
        SetField38IfState8_0215e49c(self, row + 25, 0x1f1);
        node = func_ov023_021f6880(list, row + 0x51);
        if (!node) continue;
        int slot = slots[index + 1];
        node->SetValue(equipment->items[slot]);
        node->flags &= ~8;
        unsigned char level = equipment->levels[slot];
        if (level != 0) {
            node = func_ov023_021f6880(list, row + 38);
            if (!node) continue;
            node->flags &= ~8;
            int sourceKey = 13;
            sourceKey += row;
            int width = func_ov004_0215e4e8(self, static_cast<short>(sourceKey));
            node = func_ov004_0215e47c(self, sourceKey);
            if (node) {
                Vector3i position;
                const Vector3i& source = node->GetPosition();
                position = source;
                position.x += (width + 2) << 12;
                node = func_ov004_0215e47c(self, row + 38);
                if (node) {
                    node->SetPosition(position);
                    node->value = level + 0x1d3;
                    if (level == 10) node->SetState(13);
                    else node->SetState(5);
                }
            }
        }
        ++row;
    }
    return 0;
}
