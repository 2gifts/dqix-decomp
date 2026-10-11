#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "World/LootableContainer.h"

struct ActorEntry {
    unsigned short id;
    char unk2[0x22];
    Vector3fix position;
};

struct ActorListManager {
    unsigned short id;
};

struct LootBag_021b5aec {
    SafeAllocator allocator;
    char unk14[0x18];
    void* inventory;
    int unk30;
    int unk34;
};

struct ContainerEvent_021b5aec {
    unsigned char unk0;
    unsigned char done;
    char unk2[0xe];
    unsigned short actorIndex;
    unsigned short itemID;
    char unk14[0x8];
    void* leader;
    char unk20[0x4];
    LootableContainerManager::Container* container;
    char unk28[0x4];
    Vector3fix position;
    char unk38[0x4];
    int unk3c;
};

extern "C" ActorListManager* func_02012fe4(void);
extern "C" unsigned char* func_0205ec34(void);
ActorEntry* GetActorEntryByIndex(ActorListManager* manager, int index);
void SetByteField0x253(void* obj);
extern "C" void func_ov017_021b5a30(ContainerEvent_021b5aec* obj);
int TestBitInByteArray(int unused, unsigned char* arr, int index);
extern "C" void* _Z22ZeroInitReturn020de824Pv(void* obj);
extern "C" void _Z18InitStruct0207cbe8Pc(char* obj);
extern "C" void func_0207d538(LootBag_021b5aec* bag, int lootType, int itemID, int arg, int flag);
extern "C" void func_ov017_021b6174(int id, int index, int bit);
extern "C" void _Z27EnqueueEventTag165_021cfde0ttt(unsigned short a, unsigned short b, unsigned short c);
extern "C" unsigned int* func_ov017_0218b5b0(void);
void SetBitsInField4(unsigned int* obj, unsigned int mask);

// JPN: func_ov017_021b60a0
// USA: func_ov017_021b5aec
extern "C" ARM int func_ov017_021b5aec(ContainerEvent_021b5aec* obj) {
#if defined(jpn)
 enum { regionalOffset = 0x2794 };
#else
 enum { regionalOffset = 0x2754 };
#endif
    ActorListManager* actors = func_02012fe4();
    unsigned char* flags = func_0205ec34();
    LootableContainerManager* containers = LootableContainerManager::GetMainInstance();
    ActorEntry* actor = GetActorEntryByIndex(actors, obj->actorIndex);
    if (containers == 0 || flags == 0 || actor == 0) {
        SetByteField0x253(obj->leader);
        func_ov017_021b5a30(obj);
        obj->done = 1;
        return 6;
    }

    obj->position.x = actor->position.x;
    obj->position.y = actor->position.y;
    obj->position.z = actor->position.z;
    int alreadyOpened = 1;
    int hasLoot = 0;
    unsigned short listPos = 0;
    unsigned short containerID = 0;
    LootableContainerManager::Container* container = containers->GetContainerByID(actor->id, &listPos);
    if (container != 0) {
        containerID = container->uniqueID;
        alreadyOpened = TestBitInByteArray((int)flags, flags + 0x8c, containerID + 0x79e);
        if (!alreadyOpened) {
            obj->container = container;
            if (container->lootType) {
                hasLoot = 1;
                LootBag_021b5aec bag;
                bag.allocator.ResetAllocatorPointer();
                _Z22ZeroInitReturn020de824Pv(bag.unk14);
                _Z18InitStruct0207cbe8Pc((char*)&bag);
                _Z18InitStruct0207cbe8Pc((char*)&bag);
                bag.inventory = (char*)actors + regionalOffset;
                func_0207d538(&bag, container->lootType, container->itemIDOrRank, obj->unk3c, 1);
                obj->itemID = container->itemIDOrRank;
            }
        }
    }
    func_ov017_021b6174(actors->id, obj->actorIndex, containerID);
    _Z27EnqueueEventTag165_021cfde0ttt(actors->id, obj->actorIndex, containerID);
    if (!alreadyOpened && hasLoot) {
        SetBitsInField4(func_ov017_0218b5b0(), 0x40);
        return 1;
    }
    SetByteField0x253(obj->leader);
    func_ov017_021b5a30(obj);
    obj->done = 1;
    return 6;
}
