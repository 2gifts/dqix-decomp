#include <globaldefs.h>
#include <World/LootableContainer.h>
#include <Filesystem/BackgroundLoader.h>
#include <Filesystem/FileIO.h>
#include <World/Zone3D.h>

struct S02013cb0;
struct ZoneNode {
    unsigned int id : 16;
    unsigned int field_0x2 : 16;
    unsigned int kind : 4;
    unsigned int flags : 28;
    unsigned char field_0x8[0x64];
    ZoneNode* next;
};
struct ZoneManager {
    unsigned int field_0x0;
    ZoneNode* nodes;
    unsigned int field_0x8;
    short* ids;
};
struct ListNode;
extern "C" void* func_0205ec34();
extern "C" int* func_0202ae18();
extern "C" void* func_0208e0a8();
int IsMatchingName0208e824(void*, char*);
void InitStruct020133fc(char*);
int TestBitInByteArray(int, unsigned char*, int);
int CheckField0NonZero(int*);
ListNode* FindNodeById(void*, int, int);
void ZeroInit020de848(void*);
extern "C" int func_020de9a4(void*, SafeAllocator*, void*, unsigned int, short*, unsigned short);
extern "C" void func_02013b70(Zone3D*, SafeAllocator*);
void SetElementFlagsFromMask02013cb0(S02013cb0*, unsigned int);
void UpdateFlaggedType2Entries02018c74(unsigned char*, unsigned int);
extern const char* data_020f2a38;
extern const char* data_020f2a30;

#if defined(jpn)
extern "C" int func_020e0484(void*, SafeAllocator*, const char*, short*, unsigned short, bool);
#endif

// USA: func_0201647c
// JPN: func_02016248
extern "C" ARM void func_0201647c(S02013cb0* self) {
    Zone3D* zone = reinterpret_cast<Zone3D*>(self);
    SafeAllocator* allocator = zone->pAllocator_68_;
    LootableContainerManager* containers = LootableContainerManager::GetMainInstance();
    unsigned char* save = static_cast<unsigned char*>(func_0205ec34());
    int* flags = func_0202ae18();
    ZoneManager* zoneItems = static_cast<ZoneManager*>(func_0208e0a8());
    LootableContainerManager::Container* container = containers->pContainerList_;
    bool includeZone = false;
    if (IsMatchingName0208e824(zoneItems, zone->pUnknownStruct_8_->mapShortName_)) includeZone = true;
    int containerCount = 0;
    for (; container; container = container->pNext) {
        if (container->containerType == 0 || container->containerType == 4) containerCount++;
    }
    zone->unknown_47c_ = static_cast<ZoneChestRenderRecord*>(allocator->Allocate(containerCount * sizeof(ZoneChestRenderRecord)));
    if (!zone->unknown_47c_) return;
    container = containers->pContainerList_;
    zone->numChests_ = 0;
    for (; container; container = container->pNext) {
        if (container->containerType == 0 || container->containerType == 4) {
            ZoneChestRenderRecord* entry = &zone->unknown_47c_[zone->numChests_];
            InitStruct020133fc(reinterpret_cast<char*>(entry));
            entry->position = container->position;
            entry->angleY = container->unk_6;
            *reinterpret_cast<short*>(reinterpret_cast<char*>(entry) + 0x10) = 0;
            *reinterpret_cast<short*>(reinterpret_cast<char*>(entry) + 0x1a) = zone->numChests_;
            *reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(entry) + 0x1c) = container->uniqueID;
            entry->secondPass = 0;
            if (container->containerType == 4) entry->secondPass = 1;
            if ((container->containerType == 0 &&
                 TestBitInByteArray(reinterpret_cast<int>(save), save + 0x8c, container->uniqueID + 0x212)) ||
                (container->containerType == 4 &&
                 TestBitInByteArray(reinterpret_cast<int>(save), save + 0x8c, container->uniqueID + 0x79e))) {
                entry->active = 8;
                entry->angleX = 0x4000;
                container->lootType = 0;
            } else {
                entry->active = 1;
                entry->angleX = 0x647a;
            }
            if (CheckField0NonZero(flags) && container->containerType == 4)
                *(reinterpret_cast<unsigned char*>(entry) + 0x18) = 1;
            zone->numChests_++;
        } else if (container->containerType == 3) {
            ListNode* node = FindNodeById(zone->substruct_6c_, 5, static_cast<unsigned short>(container->unk_6));
            if (node) *reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(node) + 0x30) = container->uniqueID;
        }
    }
    short ids[100];
    int count = 0;
    for (container = containers->pContainerList_; container; container = container->pNext) {
        if (container->lootType == 2) {
            unsigned int id = container->itemIDOrRank;
            bool unique = true;
            for (int i = 0; i < count; i++) {
                if (id == ids[i]) {
                    unique = false;
                    break;
                }
            }
            if (unique) ids[count++] = id;
        }
    }
    if (includeZone && zoneItems->nodes) {
        ZoneNode* node = zoneItems->nodes;
        if (node->kind == 9) {
            short* source = zoneItems->ids;
            if (source) {
                for (int i = 0; i < 16; count++, source++, i++) ids[count] = *source;
            }
        } else {
            while (node) {
                ids[count++] = node->id;
                node = node->next;
            }
        }
    }
    ZeroInit020de848(zone->unknown_struct_2754_);
    if (count > 0) {
#if defined(jpn)
        func_020e0484(zone->unknown_struct_2754_, allocator, data_020f2a38, ids,
            static_cast<unsigned short>(count), true);
#else
        BackgroundLoader::AddLockGlobal();
        unsigned int size = 0;
        void* file = ExtractFileFromGP2(data_020f2a38, data_020f2a30, &size);
        if (file) func_020de9a4(zone->unknown_struct_2754_, allocator, file, size, ids, static_cast<unsigned short>(count));
        BackgroundLoader::RemoveLockGlobal();
#endif
    }
    func_02013b70(zone, zone->pAllocator_68_);
    if (zone->pendingLootableMask_) {
        SetElementFlagsFromMask02013cb0(self, zone->pendingLootableMask_);
        zone->pendingLootableMask_ = 0;
    }
    if (zone->pendingType2Mask_) {
        UpdateFlaggedType2Entries02018c74(reinterpret_cast<unsigned char*>(zone), zone->pendingType2Mask_);
        zone->pendingType2Mask_ = 0;
    }
}
