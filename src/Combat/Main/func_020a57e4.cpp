#include <globaldefs.h>
#include "Grotto/Main/TreasureMapDataStructs.h"
#include "Filesystem/FileIO.h"
#include "Filesystem/BackgroundLoader.h"
#include "System/Memory.h"
#include "std_library_functions.h"

extern const char data_020f1ae4[];
extern const char data_020f1af8[];

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag.
// USA: func_020a57e4
void DetailedTreasureMapData::LoadLegacyBossStats(bool compute, const unsigned char* providedArchive)
{
    if (mapType_ != TreasureMapType_Legacy)
        return;

    if (!compute)
    {
        legacy_.stats_.dropListIndex = 0;
        legacy_.stats_.newDropListAtNextLevel = false;
        return;
    }

    BackgroundLoader::AddLockGlobal();

    unsigned int archiveSize = 0;
    const void* archive = data_0211e33c;
    if (providedArchive != NULL)
        archive = providedArchive;
    else if (LoadFileIntoMemory(data_020f1ae4, (void*)archive, &archiveSize) == NULL)
    {
        BackgroundLoader::RemoveLockGlobal();
        return;
    }

    char fileName[256] __attribute__((aligned(4)));
    sprintf(fileName, data_020f1af8, legacy_.bossMonsterID_);

    const void* file;
    unsigned int fileSize;
    if (!GetFileInNarc(archive, fileName, &file, &fileSize, 0))
    {
        BackgroundLoader::RemoveLockGlobal();
        return;
    }
    BackgroundLoader::RemoveLockGlobal();

    int recordSize = 0x18;
    int offset = recordSize * (legacy_.level_ - 1);
    LegacyBossStats& stats = legacy_.stats_;
    VectorizedInvertedMemcpy((const unsigned char*)file + offset, &stats.maxHP, 4);
    offset += 4;
    VectorizedInvertedMemcpy((const unsigned char*)file + offset, &stats.maxMP, 4);
    offset += 4;
    VectorizedInvertedMemcpy((const unsigned char*)file + offset, &stats.agility, 2);
    offset += 2;
    VectorizedInvertedMemcpy((const unsigned char*)file + offset, &stats.attack, 2);
    offset += 2;
    VectorizedInvertedMemcpy((const unsigned char*)file + offset, &stats.defense, 2);
    offset += 2;
    VectorizedInvertedMemcpy((const unsigned char*)file + offset, &stats.alternateVersion, 1);
    offset += 1;
    VectorizedInvertedMemcpy((const unsigned char*)file + offset, &stats.rewardExp, 4);
    offset += 4;
    VectorizedInvertedMemcpy((const unsigned char*)file + offset, &stats.rewardGold, 4);
    offset += 4;
    VectorizedInvertedMemcpy((const unsigned char*)file + offset, &stats.dropListIndex, 1);
    offset += 1;

    stats.newDropListAtNextLevel = false;
    if (legacy_.level_ < 99)
    {
        LegacyBossStats next;
        offset = recordSize * legacy_.level_;
        VectorizedInvertedMemcpy((const unsigned char*)file + offset, &next.maxHP, 4);
        offset += 4;
        VectorizedInvertedMemcpy((const unsigned char*)file + offset, &next.maxMP, 4);
        offset += 4;
        VectorizedInvertedMemcpy((const unsigned char*)file + offset, &next.agility, 2);
        offset += 2;
        VectorizedInvertedMemcpy((const unsigned char*)file + offset, &next.attack, 2);
        offset += 2;
        VectorizedInvertedMemcpy((const unsigned char*)file + offset, &next.defense, 2);
        offset += 2;
        VectorizedInvertedMemcpy((const unsigned char*)file + offset, &next.alternateVersion, 1);
        offset += 1;
        VectorizedInvertedMemcpy((const unsigned char*)file + offset, &next.rewardExp, 4);
        offset += 4;
        VectorizedInvertedMemcpy((const unsigned char*)file + offset, &next.rewardGold, 4);
        offset += 4;
        VectorizedInvertedMemcpy((const unsigned char*)file + offset, &next.dropListIndex, 1);
        offset += 1;
        if (stats.dropListIndex < next.dropListIndex)
            stats.newDropListAtNextLevel = true;
    }

    offset = recordSize * 99;
    VectorizedInvertedMemcpy((const unsigned char*)file + offset, &stats.numLevelUpMoves, 1);
    offset += 1;
    for (int i = 0; i < stats.numLevelUpMoves; i++)
    {
        LegacyBossStats::LevelUpMove* move = &stats.levelUpMoves[i];
        VectorizedInvertedMemcpy((const unsigned char*)file + offset, &move->moveID, 2);
        offset += 2;
        VectorizedInvertedMemcpy((const unsigned char*)file + offset, &move->level, 1);
        offset += 1;
        VectorizedInvertedMemcpy((const unsigned char*)file + offset, &move->announceLearn, 1);
        offset += 1;
    }
}
