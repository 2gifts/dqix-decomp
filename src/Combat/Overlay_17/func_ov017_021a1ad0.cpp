#include <globaldefs.h>
#include "GameState/GameState.h"

struct Entry_02028bd0 {
    unsigned short id;
    unsigned short slotGroup : 2;
    unsigned short active : 1;
    unsigned short flags : 13;
};
struct Element0x318_02028bac;
struct Obj02076b58;
struct FieldMonster021a1ad0 {
    Object3D object;
    char pad_ac[0x130 - 0xac];
    int phase;
    char pad_134[0x17d - 0x134];
    unsigned char flags;
};
struct MonsterBounds021a1ad0 {
    Vector3fix maximum;
    Vector3fix minimum;
};
union CollisionVector021a1ad0 {
    Vector3fix vector;
    unsigned int words[3];
};
struct CollisionFrame021a1ad0 {
    Vector3fix origin;
    CollisionVector021a1ad0 position;
    MonsterBounds021a1ad0 bounds;
    CollisionVector021a1ad0 temporary;

    CollisionFrame021a1ad0(const Vector3fix& position) : origin(position) {}
};
Entry_02028bd0* GetEntryTableBase();
Entry_02028bd0* GetElementStride0x318(Element0x318_02028bac*, int);
Entry_02028bd0* FindInlineEntryById(Entry_02028bd0*, int);
void TickActorAndDispatchPhase02076b58(Obj02076b58*);
int IsValueInRange0201b5d8(int);
int CheckField0NonZero(int*);
void EnqueueEventTag134_021c9544(int, int, int, int);
extern "C" int* func_0202ae18();
extern "C" unsigned short* func_02012fe4();
extern "C" int func_0202c508(int*);
extern "C" void func_02034104(Vector3fix*, GameObject*);
extern "C" int func_02031118(Vector3fix*, MonsterBounds021a1ad0*);
extern "C" void func_02076a8c(FieldMonster021a1ad0*);

// USA: func_ov017_021a1ad0
extern "C" ARM void func_ov017_021a1ad0() {
    GameState* state = GameState::GetInstance();
    Entry_02028bd0* table = GetEntryTableBase();
    int* manager = func_0202ae18();
    unsigned short* currentArea = func_02012fe4();
    if (func_0202c508(manager)) {
        int base;
        int group;
        Entry_02028bd0* entry;
        for (group = 0; group < 4; group++) {
            entry = GetElementStride0x318((Element0x318_02028bac*)table, group);
            if (!entry->active) continue;
            base = group * 12 + 0x70;
            int tag = -1;
            for (int slot = 0; slot < 12; slot++) {
                FieldMonster021a1ad0* monster = (FieldMonster021a1ad0*)state->GetMaybeFieldMonsterByIndex(slot + base);
                if (!monster || !monster->object.IsVisible()) continue;
                TickActorAndDispatchPhase02076b58((Obj02076b58*)monster);
                int removable = 1;
                if ((monster->flags & 2) || (monster->flags & 4) || IsValueInRange0201b5d8(*currentArea)) removable = 0;
                if (monster->flags & 8) removable = 0;
                if (!removable) continue;
                int clear;
                {
                    GameObject* fieldMonster;
                    GameState* collisionState = GameState::GetInstance();
                    fieldMonster = collisionState->GetMaybeFieldMonsterByIndex(slot + base);
                    if (!fieldMonster) clear = 0;
                    else {
                        CollisionFrame021a1ad0 frame(fieldMonster->obj3D_.position_);
                        for (int i = 0; i < 4; i++) {
                            GameObject* wanderingMonster = collisionState->GetMaybeWanderingMonsterByIndex(i);
                            if (!wanderingMonster) continue;
                            int area = wanderingMonster->obj3D_.GetField06();
                            if (area != fieldMonster->obj3D_.GetField06()) continue;
                            func_02034104(&frame.temporary.vector, wanderingMonster);
                            frame.position = frame.temporary;
                            frame.bounds.maximum = frame.position.vector;
                            frame.bounds.maximum.x += 0x19000;
                            frame.bounds.maximum.y += 0x19000;
                            frame.bounds.maximum.z += 0x19000;
                            frame.bounds.minimum = frame.position.vector;
                            frame.bounds.minimum.x -= 0x19000;
                            frame.bounds.minimum.y -= 0x19000;
                            frame.bounds.minimum.z -= 0x19000;
                            if (func_02031118(&frame.origin, &frame.bounds)) {
                                clear = 0;
                                goto collisionComplete;
                            }
                        }
                        clear = 1;
                    }
                }
collisionComplete:
                if (clear && monster->phase != 8 && monster->phase != 9) {
                    func_02076a8c(monster);
                    monster->object.MakeHidden();
                    if (CheckField0NonZero(manager) && entry) {
                        EnqueueEventTag134_021c9544(entry->id, slot, monster->object.unknown_2_, tag);
                    }
                }
            }
        }
    } else {
        Entry_02028bd0* entry = FindInlineEntryById(table, *currentArea);
        if (!entry) return;
        for (int slot = 0; slot < 12; slot++) {
            FieldMonster021a1ad0* monster = (FieldMonster021a1ad0*)state->GetMaybeFieldMonsterByIndex(entry->slotGroup * 12 + 0x70 + slot);
            if (monster && monster->object.IsVisible()) TickActorAndDispatchPhase02076b58((Obj02076b58*)monster);
        }
    }
}
