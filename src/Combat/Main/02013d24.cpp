#include <globaldefs.h>
#include "World/Zone3D.h"
#include "World/LootableContainer.h"
#include "Resource/GameResources.h"

#if defined(usa)
typedef char Zone3DSizeMustBe2824[(sizeof(Zone3D) == 0x2824) ? 1 : -1];
typedef char GameResourcesSizeMustBe44c8[(sizeof(GameResources) == 0x44c8) ? 1 : -1];
#endif

// USA: func_02013d24
extern "C" ARM void func_02013d24(Zone3D* zone)
{
    LootableContainerManager* manager = LootableContainerManager::GetMainInstance();
    for (int i = 0; i < (unsigned char)zone->unknown_476_; ++i)
    {
        unsigned char* storage = reinterpret_cast<unsigned char*>(zone->unknown_478_);
        ZoneLootableRecord* entry = static_cast<ZoneLootableRecord*>(
            static_cast<void*>(storage + i * sizeof(ZoneLootableRecord)));
        LootableContainerManager::Container* container =
            manager->GetContainerByID(entry->id, NULL);
        if (container == NULL)
            continue;

        int type = container->containerType;
        if (type == 1)
        {
            CopyFieldsWithFlags02048004(zone->lootableTemplates_[0], &entry->blocks[0]);
            CopyFieldsWithFlags02048004(zone->lootableTemplates_[1], &entry->blocks[1]);
            Foo02048004* fields = &entry->blocks[2];
            for (int j = 0; j < 4; ++j)
                CopyFieldsWithFlags02048004(zone->lootableTemplates_[2], fields + j);
        }
        else if (type == 2)
        {
            CopyFieldsWithFlags02048004(zone->lootableTemplates_[3], &entry->blocks[0]);
            CopyFieldsWithFlags02048004(zone->lootableTemplates_[4], &entry->blocks[1]);
            Foo02048004* fields = &entry->blocks[2];
            for (int j = 0; j < 4; ++j)
                CopyFieldsWithFlags02048004(zone->lootableTemplates_[5], fields + j);
        }
    }
}
