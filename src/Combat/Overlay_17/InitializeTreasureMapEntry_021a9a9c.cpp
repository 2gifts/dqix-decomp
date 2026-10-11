#include <globaldefs.h>
#include "Grotto/Main/TreasureMapMetadata.h"
#include "Grotto/Main/TreasureMapDataStructs.h"
#include "System/Memory.h"
#include "System/Timing.h"
#include "std_library_functions.h"

extern "C" void func_020a3720();
extern "C" void func_020a395c();
extern char data_ov017_021d781c;
#if defined(jpn)
extern const char data_ov017_021d7c80[];
extern const char data_ov017_021d7c8c[];
extern const char data_ov017_021d7c8d[];
#endif

// JPN: func_ov017_021aa270
// USA: func_ov017_021a9a9c  (semantic: InitializeTreasureMapEntry_021a9a9c)
extern "C" ARM void func_ov017_021a9a9c(void* obj, unsigned char type, unsigned int quality, int seed, unsigned char locationOverride) {
#if defined(jpn)
 enum {regionalOffset0=0x30d, regionalOffset1=0x30e, regionalOffset2=0x310};
#else
 enum {regionalOffset0=0x26d, regionalOffset1=0x26e, regionalOffset2=0x270};
#endif
    unsigned char* base = (unsigned char*)obj;
    TreasureMapMetadata* metadata = (TreasureMapMetadata*)(base + 0xa);
    DetailedTreasureMapData* detailed = (DetailedTreasureMapData*)(base + 0x28);

    base[regionalOffset0] = type;
    VectorizedMemset(metadata, 0, 0x1c);
    detailed->Clear();
    srand(GetMain16BitTimerCounter());

    if (base[regionalOffset0] == 1) {
        metadata->InitialiseAsNonLegacyMap(quality, seed);
        base[regionalOffset1] = metadata->QualityOrLegacyBossID;
        *(unsigned short*)(base + regionalOffset2) = metadata->SeedOrMinTurns;
    } else if (base[regionalOffset0] == 2) {
        metadata->InitialiseAsLegacyBossMap(quality, (unsigned char)seed);
        base[regionalOffset1] = metadata->QualityOrLegacyBossID;
        *(unsigned short*)(base + regionalOffset2) = metadata->LegacyBossLevel;
    } else {
        metadata->InitialiseAsNonLegacyMap(quality, seed);
        base[regionalOffset1] = metadata->QualityOrLegacyBossID;
        *(unsigned short*)(base + regionalOffset2) = metadata->SeedOrMinTurns;
    }

    if (locationOverride != 0) {
        metadata->Location = locationOverride;
    }

    func_020a3720();
    ExportDetailedTreasureMapData(metadata, detailed, false, NULL);
    func_020a395c();

#if defined(jpn)
    if (base[regionalOffset0] == 1) {
        strcpy((char*)(base + 0x20c), (char*)(base + 0xaf));
        strcpy((char*)(base + 0x22c), (char*)(base + 0xcf));
        strcpy((char*)(base + 0x24c), data_ov017_021d7c80);
        strcpy((char*)(base + 0x26c), (char*)(base + 0x10f));
    } else if (base[regionalOffset0] == 2) {
        strcpy((char*)(base + 0x20c), (char*)(base + 0x104));
        strcpy((char*)(base + 0x22c), (char*)(base + 0x124));
        strcpy((char*)(base + 0x24c), data_ov017_021d7c8c);
        strcpy((char*)(base + 0x26c), (char*)(base + 0x144));
    }
    sprintf((char*)(base + 0x28c), data_ov017_021d7c8d, (char*)(base + 0x20c), (char*)(base + 0x22c), (char*)(base + 0x24c), (char*)(base + 0x26c));

#else
    if (base[regionalOffset0] == 1) {
        strcpy((char*)(base + 0x1ec), (char*)(base + 0xd7));
    } else if (base[regionalOffset0] == 2) {
        strcpy((char*)(base + 0x1ec), (char*)(base + 0x16c));
    }

    sprintf((char*)(base + 0x22c), &data_ov017_021d781c, (char*)(base + 0x1ec));

#endif
}
