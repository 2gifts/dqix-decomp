#include <globaldefs.h>
#include <World/LootableContainer.h>
#include <Filesystem/BackgroundLoader.h>
#include <Filesystem/FileIO.h>

struct LootEntry {
    Vector3i position;
    short objectID;
    short scale;
    short counter;
    short field_0x12;
    unsigned char field_0x14;
    unsigned char field_0x15;
    unsigned char state;
    unsigned char blueChest;
    unsigned char special;
    unsigned char field_0x19;
    short index;
    unsigned short uniqueID;
    unsigned short field_0x1e;
    void* field_0x20;
};
struct S02013cb0 {
    unsigned char field_0x0[8];
    char* name;
    unsigned char field_0xc[0x5c];
    SafeAllocator* allocator;
    unsigned char nodes[0x40a];
    unsigned char field_0x476;
    unsigned char count;
    unsigned int field_0x478;
    LootEntry* entries;
    unsigned char field_0x480[0x22d4];
    unsigned char loader[0x84];
    unsigned short pendingType2;
    unsigned short pendingElements;
};
struct SaveState {
    unsigned char field_0x0[0x8c];
    unsigned char bits[1];
};
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
struct WorldNode {
    unsigned char field_0x0[0x30];
    unsigned short containerID;
};
extern "C" SaveState* func_0205ec34();
extern "C" int* func_0202ae18();
extern "C" ZoneManager* func_0208e0a8();
extern "C" int _Z22IsMatchingName0208e824PvPc(void*, char*);
extern "C" void _Z18InitStruct020133fcPc(char*);
int TestBitInByteArray(int, unsigned char*, int);
int CheckField0NonZero(int*);
WorldNode* FindNodeById(void*, int, int);
extern "C" void _Z16ZeroInit020de848Pv(void*);
extern "C" void func_020de9a4(void*, SafeAllocator*, void*, unsigned int, short*, unsigned short);
extern "C" void func_02013b70(S02013cb0*, SafeAllocator*);
extern "C" void _Z31SetElementFlagsFromMask02013cb0P9S02013cb0j(S02013cb0*, unsigned int);
extern "C" void _Z33UpdateFlaggedType2Entries02018c74Phj(unsigned char*, unsigned int);
extern const char* data_020f2a38;
extern const char* data_020f2a30;

struct ZoneCopyState {
    short* source;
    int index;
};

// USA: func_0201647c
extern "C" ARM void func_0201647c(S02013cb0* self) {
    SafeAllocator* allocator = self->allocator;
    LootableContainerManager* containers = LootableContainerManager::GetMainInstance();
    SaveState* save = func_0205ec34();
    int* flags = func_0202ae18();
    ZoneManager* zone = func_0208e0a8();
    LootableContainerManager::Container* container = containers->pContainerList_;
    bool includeZone = false;
    if (_Z22IsMatchingName0208e824PvPc(zone, self->name + 5)) includeZone = true;
    int containerCount = 0;
    for (; container; container = container->pNext) {
        if (container->containerType == 0 || container->containerType == 4) containerCount++;
    }
    self->entries = static_cast<LootEntry*>(allocator->Allocate(containerCount * sizeof(LootEntry)));
    if (!self->entries) return;
    container = containers->pContainerList_;
    self->count = 0;
    for (; container; container = container->pNext) {
        if (container->containerType == 0 || container->containerType == 4) {
            LootEntry* entry = &self->entries[self->count];
            _Z18InitStruct020133fcPc(reinterpret_cast<char*>(entry));
            entry->position = container->position;
            entry->objectID = container->unk_6;
            entry->counter = 0;
            entry->index = self->count;
            entry->uniqueID = container->uniqueID;
            entry->blueChest = 0;
            if (container->containerType == 4) entry->blueChest = 1;
            if ((container->containerType == 0 &&
                 TestBitInByteArray(reinterpret_cast<int>(save), save->bits, container->uniqueID + 0x212)) ||
                (container->containerType == 4 &&
                 TestBitInByteArray(reinterpret_cast<int>(save), save->bits, container->uniqueID + 0x79e))) {
                entry->state = 8;
                entry->scale = 0x4000;
                container->lootType = 0;
            } else {
                entry->state = 1;
                entry->scale = 0x647a;
            }
            if (CheckField0NonZero(flags) && container->containerType == 4) entry->special = 1;
            self->count++;
        } else if (container->containerType == 3) {
            WorldNode* node = FindNodeById(self->nodes, 5, static_cast<unsigned short>(container->unk_6));
            if (node) node->containerID = container->uniqueID;
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
    if (includeZone && zone->nodes) {
        ZoneNode* node = zone->nodes;
        if (node->kind == 9) {
            ZoneCopyState copy;
            copy.source = zone->ids;
            if (copy.source) {
                for (copy.index = 0; copy.index < 16; copy.index++) ids[count++] = *copy.source++;
            }
        } else {
            while (node) {
                ids[count++] = node->id;
                node = node->next;
            }
        }
    }
    _Z16ZeroInit020de848Pv(self->loader);
    if (count > 0) {
        BackgroundLoader::AddLockGlobal();
        unsigned int size = 0;
        void* file = ExtractFileFromGP2(data_020f2a38, data_020f2a30, &size);
        if (file) func_020de9a4(self->loader, allocator, file, size, ids, static_cast<unsigned short>(count));
        BackgroundLoader::RemoveLockGlobal();
    }
    func_02013b70(self, self->allocator);
    if (self->pendingElements) {
        _Z31SetElementFlagsFromMask02013cb0P9S02013cb0j(self, self->pendingElements);
        self->pendingElements = 0;
    }
    if (self->pendingType2) {
        _Z33UpdateFlaggedType2Entries02018c74Phj(reinterpret_cast<unsigned char*>(self), self->pendingType2);
        self->pendingType2 = 0;
    }
}
