#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Graphics/LightingManager.h"

extern "C" void* func_02012fe4(void);
extern "C" void* func_0202ae18(void);
extern "C" void* func_0205ec34(void);
void* GetFieldIfFlag4(char* obj);

struct PointerField32c_ffc0
{
    char padding0[0x32c];
    void* field_0x32c;
};
void* GetPointerAt0x32c(struct PointerField32c_ffc0* obj);

void* GetField0x3f8Address(GameState*);

extern "C" void func_020da77c(void* target, int type, void* msg);

void SetField0x21c(void* obj, short value);

void SetBitsInField4(unsigned int* obj, unsigned int mask);
void ClearBitsInField4(unsigned int* obj, unsigned int mask);

void StoreVec3AtField0x50(unsigned char* obj, int a, int b, int c);

extern "C" int func_0202c508(void* obj);
extern "C" int func_0202c540(void* obj);

extern "C" void func_ov017_021d1a18(int a, short b, short c, unsigned char d);

struct Obj02033874;
extern "C" void _Z24SetVecYFromValue02033874P11Obj02033874i(struct Obj02033874* obj, int arg);

extern "C" void* func_0201b678(void* savedEvent, void* ptr);
struct TerrainCtx02018fbc;
extern "C" int func_02018fbc(TerrainCtx02018fbc*, Vector3fix*);
extern "C" void func_ov017_0219c598(int* srcVec3, short* srcAngle, int forceFlag);

extern "C" void* _Z27FindNodeByField0x2c0201b754Pvi(void* obj, int key);
void ClearCombatantSlot(GameState*, int);

struct Obj0201b600;
struct Elem0201b600;
struct Struct02013380;
struct Elem0201b600* FindElemByKeys(struct Obj0201b600*, int, short);
void SetFlag0x40AndToggle0x4(struct Struct02013380* obj, int unused, int clear4);
extern "C" void _Z25ApplyElementFlags0201b8c8P11Obj0201b600iii(struct Obj0201b600* obj, int a1, int a2, int a3);

extern "C" void func_020da244(void* sb);

void SetVec3At0x0020a6aa4(Vector3i* obj, int x, int y, int z);

struct EventDispatcher020a6aac;
extern EventDispatcher020a6aac data_ov017_021d82fc;
extern Vector3i data_020e909c;

struct EventController020a6aac
{
    unsigned char pad0[0x1f8];
    unsigned char transitionActive;
    unsigned char pad1f9[7];
    unsigned int transitionScale;
    int transitionRange;
};
struct ActorView020a6aac
{
    Object3D object;
    unsigned char padac[0x144 - 0xac];
    Vector3i secondaryPosition;
    unsigned char pad150[4];
    unsigned char scripted;
};
struct SavedEvent020a6aac
{
    unsigned char pad0[0x2774];
    Vector3i position;
    int height;
    short nodeId;
    unsigned short eventId;
    unsigned char active;
};
struct MovementView020a6aac
{
    unsigned char pad0[5];
    unsigned char busy;
    unsigned char pad6[0x20 - 6];
    int eventId;
};
struct EventNode020a6aac
{
    unsigned char pad0[8];
    Vector3i position;
    unsigned char pad14[0x20 - 0x14];
    short angle;
    unsigned char pad22[0x2c - 0x22];
    unsigned short id;
    short height;
    Vector3i spawnPosition;
    unsigned char pad3c[4];
    Vector3i savedPosition;
};
struct EventDispatcher020a6aac
{
    unsigned char pad0[0xe];
    unsigned char status;
};

struct LocalMsg020a6aac
{
    int id;
    unsigned char flag;
};

static inline const Vector3i* SavedPosition020a6aac(SavedEvent020a6aac* event)
{ SDK_NULL_ASSERT(event); return &event->position; }

// USA: func_020a6aac
extern "C" ARM void func_020a6aac(unsigned int* obj, int eventCode, int previousCode)
{
    GameState* state = GameState::GetInstance();
    SavedEvent020a6aac* savedEvent = (SavedEvent020a6aac*)func_02012fe4();
    LightingManager::GetInstance();
    void* events = func_0202ae18();
    func_0205ec34();
    EventController020a6aac* controller = (EventController020a6aac*)GetFieldIfFlag4((char*)state);
    ActorView020a6aac* actor = (ActorView020a6aac*)GetPointerAt0x32c((struct PointerField32c_ffc0*)state);
    GameObject* unknown = state->GetUnknownGameObject();
    MovementView020a6aac* movement = (MovementView020a6aac*)GetField0x3f8Address(state);

    if ((unsigned int)(eventCode - 0x170c) <= 3) {
        controller->transitionActive = 1;
        controller->transitionScale = 0x3f800000;
        controller->transitionRange = 0x1000;
    } else {
        controller->transitionActive = 0;
    }

    if (eventCode == 0x2710) {
        MovementView020a6aac* movementState = (MovementView020a6aac*)GetField0x3f8Address(state);
        int flagMatch = 0;
        if (movementState->eventId == 0x25f1)
        {
            flagMatch = 1;
        }
        struct LocalMsg020a6aac local;
        local.id = -1;
        local.flag = 0;
        if (flagMatch) {
            local.id = 0xa0;
            func_020da77c(&data_ov017_021d82fc, 2, &local);
        } else {
            local.id = 0xc9;
            func_020da77c(&data_ov017_021d82fc, 1, &local);
        }
        SetField0x21c(controller, 0xc9);
        actor->object.DisableFlag(0x100);
        actor->object.MakeVisible();
        actor->scripted = 1;
        actor->object.SetScale(0xa0, 0xa0, 0xa0);
        SetBitsInField4(obj, 0x10004);
        actor->object.position_ = *SavedPosition020a6aac(savedEvent);
        actor->secondaryPosition = *SavedPosition020a6aac(savedEvent);
        int savedHeight = savedEvent->height;
        StoreVec3AtField0x50((unsigned char*)actor, 0, savedHeight, 0);
        if (func_0202c508(events) != 0 && flagMatch == 0) {
            savedEvent->active = 1;
            func_ov017_021d1a18(1, -1, 1, 0);
        }
        if (func_0202c540(events) != 0) {
            actor->object.position_.x = 0x19000;
            actor->object.position_.y = 0x199;
            actor->object.position_.z = 0x38ccc;
            _Z24SetVecYFromValue02033874P11Obj02033874i((struct Obj02033874*)actor, 0);
        }
    } else if (eventCode == 0x2774) {
        actor->scripted = 0;
        actor->object.MakeVisible();
    } else if (eventCode >= 0x4e20 && eventCode <= 0x752f) {
        if (actor == 0)
        {
            return;
        }
        {
            actor->scripted = 0;
            actor->object.SetScale(0x180, 0x180, 0x180);
            if (previousCode == 0x2710) {
                EventNode020a6aac* node1 = (EventNode020a6aac*)func_0201b678(savedEvent, &savedEvent->position);
                if (node1 != 0) {
                    Vector3i spawnPosition = node1->spawnPosition;
                    spawnPosition.y = func_02018fbc((TerrainCtx02018fbc*)savedEvent, &spawnPosition);
                    if (movement->busy == 0) {
                        unknown->obj3D_.position_ = spawnPosition;
                        StoreVec3AtField0x50((unsigned char*)unknown, 0, node1->height, 0);
                        func_ov017_0219c598(&spawnPosition.x, &node1->height, 0);
                    }
                    savedEvent->nodeId = node1->id;
                    savedEvent->eventId = (unsigned short)eventCode;
                }
                SetField0x21c(controller, unknown->obj3D_.unknown_4_);
                ClearBitsInField4(obj, 0x10004);
                savedEvent->active = 0;
                short savedEventId = (short)savedEvent->eventId;
                short savedNodeId = savedEvent->nodeId;
                func_ov017_021d1a18(savedEventId, savedNodeId, 0, 0);
            } else if (previousCode == 0x170c) {
                short savedNodeId = savedEvent->nodeId;
                EventNode020a6aac* node2 = (EventNode020a6aac*)_Z27FindNodeByField0x2c0201b754Pvi(savedEvent, savedNodeId);
                if (node2 != 0) {
                    Vector3i spawnPosition = node2->spawnPosition;
                    spawnPosition.y = func_02018fbc((TerrainCtx02018fbc*)savedEvent, &spawnPosition);
                    if (movement->busy == 0) {
                        unknown->obj3D_.position_ = spawnPosition;
                        func_ov017_0219c598(&spawnPosition.x, &node2->height, 0);
                    }
                }
                SetField0x21c(controller, unknown->obj3D_.unknown_4_);
                ClearBitsInField4(obj, 0x10004);
            }
            unsigned short savedEventId = savedEvent->eventId;
            if (eventCode == savedEventId) {
                short savedNodeId = savedEvent->nodeId;
                EventNode020a6aac* node3 = (EventNode020a6aac*)_Z27FindNodeByField0x2c0201b754Pvi(savedEvent, savedNodeId);
                if (node3 != 0) {
                    actor->object.EnableFlag(0x100);
                    actor->object.position_ = node3->position;
                    actor->secondaryPosition = node3->position;
                    _Z24SetVecYFromValue02033874P11Obj02033874i((struct Obj02033874*)actor, node3->angle);
                    Vector3i savedPosition = node3->savedPosition;
                    savedEvent->position = savedPosition;
                }
                actor->object.MakeVisible();
            } else {
                actor->object.MakeHidden();
            }
        }
    } else if (eventCode == 0x170c) {
        if (previousCode == 0x2710) {
            GameObject* currentObject = state->GetUnknownGameObject();
            SetField0x21c(controller, currentObject->obj3D_.unknown_4_);
            ClearBitsInField4(obj, 0x10004);
            ClearCombatantSlot(state, 0xc9);
            if (func_0202c540(events) != 0) {
                if (savedEvent->active == 0) {
                    _Z25ApplyElementFlags0201b8c8P11Obj0201b600iii((struct Obj0201b600*)savedEvent, 0, 1, 0);
                } else {
                    _Z25ApplyElementFlags0201b8c8P11Obj0201b600iii((struct Obj0201b600*)savedEvent, 1, 0, 1);
                }
            } else {
                _Z25ApplyElementFlags0201b8c8P11Obj0201b600iii((struct Obj0201b600*)savedEvent, 1, 0, 1);
                savedEvent->active = 1;
                func_ov017_021d1a18(1, -1, 1, 0);
            }
        } else {
            if (savedEvent->active != 0) {
                _Z25ApplyElementFlags0201b8c8P11Obj0201b600iii((struct Obj0201b600*)savedEvent, 1, 0, 1);
                func_ov017_021d1a18(1, -1, 1, 0);
            } else {
                _Z25ApplyElementFlags0201b8c8P11Obj0201b600iii((struct Obj0201b600*)savedEvent, 0, 1, 0);
                short savedEventId = (short)savedEvent->eventId;
                short savedNodeId = savedEvent->nodeId;
                func_ov017_021d1a18(savedEventId, savedNodeId, 0, 0);
            }
        }
    } else if (eventCode == 0x76c) {
        SavedEvent020a6aac* savedState = (SavedEvent020a6aac*)func_02012fe4();
        if (previousCode == 0x2710) {
            GameObject* currentObject = state->GetUnknownGameObject();
            Vector3i homePosition = data_020e909c;
            short angle570 = 0x570;
            currentObject->obj3D_.position_ = homePosition;
            _Z24SetVecYFromValue02033874P11Obj02033874i((struct Obj02033874*)currentObject, angle570);
            func_ov017_0219c598(&homePosition.x, &angle570, 0);
            savedState->active = 0;
            func_ov017_021d1a18((short)eventCode, -1, 0, 0);
            savedState->nodeId = 0;
            savedState->eventId = (unsigned short)eventCode;
            short objectId = state->GetUnknownGameObject()->obj3D_.unknown_4_;
            SetField0x21c(controller, objectId);
            ClearBitsInField4(obj, 0x10004);
            struct Elem0201b600* firstSlot = FindElemByKeys((struct Obj0201b600*)savedState, 0, 4);
            if (firstSlot != 0)
            {
                SetFlag0x40AndToggle0x4((struct Struct02013380*)firstSlot, 0, 1);
            }
            struct Elem0201b600* secondSlot = FindElemByKeys((struct Obj0201b600*)savedState, 0, 0x28);
            if (secondSlot != 0)
            {
                SetFlag0x40AndToggle0x4((struct Struct02013380*)secondSlot, 0, 1);
            }
        } else {
            unsigned short savedEventId = savedState->eventId;
            if (savedEventId == 0x76c) {
                struct Elem0201b600* firstSlot = FindElemByKeys((struct Obj0201b600*)savedState, 0, 4);
                if (firstSlot != 0)
                {
                    SetFlag0x40AndToggle0x4((struct Struct02013380*)firstSlot, 0, 1);
                }
                struct Elem0201b600* secondSlot = FindElemByKeys((struct Obj0201b600*)savedState, 0, 0x28);
                if (secondSlot != 0)
                {
                    SetFlag0x40AndToggle0x4((struct Struct02013380*)secondSlot, 0, 1);
                }
            } else {
                struct Elem0201b600* firstSlot = FindElemByKeys((struct Obj0201b600*)savedState, 0, 4);
                if (firstSlot != 0)
                {
                    SetFlag0x40AndToggle0x4((struct Struct02013380*)firstSlot, 0, 0);
                }
                struct Elem0201b600* secondSlot = FindElemByKeys((struct Obj0201b600*)savedState, 0, 0x28);
                if (secondSlot != 0)
                {
                    SetFlag0x40AndToggle0x4((struct Struct02013380*)secondSlot, 0, 0);
                }
            }
        }
        ClearCombatantSlot(state, 0xc9);
    } else {
        if (previousCode == 0x2710) {
            ClearBitsInField4(obj, 0x10004);
            ClearCombatantSlot(state, 0xc9);
            short actorId = state->GetUnknownGameObject()->obj3D_.unknown_4_;
            SetField0x21c(controller, actorId);
            short savedEventId = (short)savedEvent->eventId;
            short savedNodeId = savedEvent->nodeId;
            unsigned char flag2788 = savedEvent->active;
            func_ov017_021d1a18(savedEventId, savedNodeId, flag2788, 1);
            unsigned char statusByte = data_ov017_021d82fc.status;
            if (!(statusByte != 1 && statusByte != 2)) {
                func_020da244(&data_ov017_021d82fc);
            }
        }
    }

    Vector3i fallbackPosition = savedEvent->position;
    if (fallbackPosition.x == 0 && fallbackPosition.z == 0) {
        SetVec3At0x0020a6aa4(&fallbackPosition, 0x19000, 0x199, 0x38ccc);
        savedEvent->position = fallbackPosition;
    }
}
