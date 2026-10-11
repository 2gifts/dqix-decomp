#include <globaldefs.h>
#include "World/Zone3D.h"
#include "World/LootableContainer.h"
#include "Graphics/LightingManager.h"

void ResetHeaderAndSubStructs(char* base);
extern "C" void func_02013d24(Zone3D* zone);

// USA: func_02013b70
extern "C" ARM void func_02013b70(Zone3D* zone, SafeAllocator* allocator)
{
    LootableContainerManager* manager = LootableContainerManager::GetMainInstance();
    const unsigned short light = LightingManager::GetInstance()->maybePotBarrelDiffuseColor_;
    LootableContainerManager::Container* c = manager->pContainerList_;
    unsigned int count = 0;

    for (; c != NULL; c = c->pNext)
    {
        if (c->containerType == 1 || c->containerType == 2)
            count++;
    }

    zone->unknown_478_ = static_cast<ZoneLootableRecord*>(
        allocator->Allocate(count * sizeof(ZoneLootableRecord)));
    if (zone->unknown_478_ == NULL)
        return;

    for (c = manager->pContainerList_; c != NULL; c = c->pNext)
    {
        if (c->containerType != 1 && c->containerType != 2)
            continue;

        unsigned char* storage = reinterpret_cast<unsigned char*>(zone->unknown_478_);
        ZoneLootableRecord* record = static_cast<ZoneLootableRecord*>(
            static_cast<void*>(storage + (unsigned char)zone->unknown_476_ * sizeof(ZoneLootableRecord)));

        ResetHeaderAndSubStructs(reinterpret_cast<char*>(record));
        func_0204719c(&record->blocks[0]);
        record->blocks[0].field80 = light;
        func_0204719c(&record->blocks[1]);
        record->blocks[1].field80 = light;

        for (int i = 0; i < 4; ++i)
        {
            func_0204719c(&(record->blocks + 2)[i]);
            ((Foo02048004*)((unsigned char*)record + 0x118))[i].field80 = light;
        }

        Vector3fix* pos = reinterpret_cast<Vector3fix*>(&record->blocks[0].words1c[0]);
        *pos = c->position;

        record->blocks[0].words1c[6] = 0x80;
        record->blocks[0].words1c[7] = 0x80;
        record->blocks[0].words1c[8] = 0x80;
        record->id = c->uniqueID;
        record->field2 = 0;
        zone->unknown_476_ = (char)((unsigned char)zone->unknown_476_ + 1);
    }

    func_02013d24(zone);
}
