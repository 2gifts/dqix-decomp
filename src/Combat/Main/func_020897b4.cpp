#include <globaldefs.h>

#include "Combat/Main/BattleList.h"
#include "Combat/ResourceScriptEntry.h"
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

#if defined(jpn)
enum { SelectedVocationOffset = 0x8b8 };
#else
enum { SelectedVocationOffset = 0x950 };
#endif

struct StreamHeader;
struct Ctx0209a8b4 { void* field0; };

extern char data_020f1019[];
extern char data_020f102e[];
extern unsigned char data_0211e33c[0x30000];

int GetFieldAt0x150(unsigned char* obj);
void* Clear0x54Bytes0208247c(void* obj);
int InitAndRunScript0208274c(void* spellTable, StreamHeader* script, int size, int arg3);
extern "C" void func_02083cbc(void* dst, void* src, void* tail);
extern "C" void func_02083e28(void* model, int arg);
void SetBitsFromIndexList02083b8c(unsigned char* obj, unsigned char* learnedSpells, unsigned int count);
void ClearField00209a804(int* field);
void SetupAndRunBufferedScript0209a8b4(Ctx0209a8b4* spellTable, SafeAllocator* spellAllocator, StreamHeader* buffer, int length);
extern "C" int func_0209aa54(void* holder, unsigned char* path, unsigned char* out, int threshold);
void EnqueueEventTag176_021ce614(unsigned char combatantId, unsigned char level, unsigned char vocation);

struct VocationRecord {
    unsigned char unknown0[0x138];
    unsigned int experience[13];
    unsigned short levels[13];
    unsigned char unknown186[0x564 - 0x186];
    unsigned short unknown564;
    unsigned char unknown566[SelectedVocationOffset - 0x566];
    int currentVocation;
    unsigned short unlockedVocations;
};

struct RestorationState {
    unsigned int flags;
    unsigned short hp;
    unsigned short mp;
};

struct CombatantRestorationView {
    unsigned char unknown0[0x130];
    RestorationState* restoration;
};

// USA: func_020897b4
extern "C" ARM void func_020897b4(unsigned char combatantId, unsigned char level, int vocation, unsigned char notifyLevelChange,
                                 unsigned char restoreHpMp, void* levelScript, unsigned int levelScriptSize, void* spellScript, unsigned int spellScriptSize) {
    char path[0x50];
    ResourceScriptEntry entry;
    char heap[0x600];
    SafeAllocator spellAllocator;
    unsigned char learnedSpells[0x14];
    unsigned int size;
    Ctx0209a8b4 spellTable;

    GameObject* combatant = GetCombatantWithFlag0x100(GameState::GetInstance(), combatantId);
    if (combatant == 0) {
        return;
    }
    BackgroundLoader::AddLockGlobal();

    if (levelScript == 0) {
        sprintf(path, data_020f1019, vocation);
        if (LoadFileIntoMemory(path, &data_0211e33c, &size) == 0) {
            BackgroundLoader::RemoveLockGlobal();
            return;
        }
        levelScript = &data_0211e33c;
        levelScriptSize = size;
    }

    Clear0x54Bytes0208247c(&entry);
    InitAndRunScript0208274c(&entry, (StreamHeader*)levelScript, levelScriptSize, level);

    ResourceScriptEntry* const levelData = &entry;
    VocationRecord* record = reinterpret_cast<VocationRecord*>(GetFieldAt0x150((unsigned char*)combatant));
    record->unlockedVocations |= 1 << vocation;
    record->currentVocation = vocation;
    record->levels[vocation] = level;
    record->experience[vocation] = levelData->initial.value0;
    record->unknown564 = levelData->initial.value4High;
    func_02083cbc(record, levelData, entry.variants);

    if (restoreHpMp != 0) {
        func_02083e28(record, 0);
        CombatantRestorationView* actor = reinterpret_cast<CombatantRestorationView*>(combatant);
        actor->restoration->hp = combatant->baseStats_->primaryStats.maxHP;
        actor->restoration->mp = combatant->baseStats_->primaryStats.maxMP;
    }

    if (spellScript == 0) {
        if (LoadFileIntoMemory(data_020f102e, &data_0211e33c, &size) != 0) {
            spellScript = &data_0211e33c;
            spellScriptSize = size;
        }
    }

    if (spellScript != 0) {
        spellAllocator.ResetAllocatorPointer();
        spellAllocator.CreateTypeA(heap, 0x600);
        ClearField00209a804((int*)&spellTable);
        SetupAndRunBufferedScript0209a8b4(&spellTable, &spellAllocator, (StreamHeader*)spellScript, spellScriptSize);
        unsigned int count = func_0209aa54(&spellTable, (unsigned char*)combatant, learnedSpells, 0);
        SetBitsFromIndexList02083b8c(reinterpret_cast<unsigned char*>(record), learnedSpells, count);
        spellAllocator.Destroy();
    }

    if (notifyLevelChange != 0) {
        EnqueueEventTag176_021ce614(combatantId, level, restoreHpMp);
    }

    BackgroundLoader::RemoveLockGlobal();
}
