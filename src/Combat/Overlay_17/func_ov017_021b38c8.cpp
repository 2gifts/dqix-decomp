#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "std_library_functions.h"

struct Field150Holder02052e2c;
struct ResourceSlot021b38c8 { char storage[0x70]; };
struct ResourceSlots021b38c8 { ResourceSlot021b38c8 party[0x15]; ResourceSlot021b38c8 fallback; };
struct Entry02083554 { char pad_0[0x18]; short id; char pad_1a[6]; };
struct Container02083554 { char pad_0[0x194]; Entry02083554 entries[11]; };
struct BattleAssets021b38c8 {
    unsigned short field_0, slot; SafeAllocator allocators[11];
    char pad_e0[0x52c - 0xe0]; SafeAllocator animationAllocator, extraAllocator;
};
struct Combatant021b38c8 {
    char pad_0[0x154]; BattleAssets021b38c8* assets;
    BattleAssets021b38c8* GetAssets() { return assets; }
};
struct Scale021b38c8 { char pad_0[8]; short field_8; char pad_a[0x18-0xa]; short width, height; };
struct Reload021b38c8 {
    char pad_0[8]; short combatant; char pad_a;
    unsigned char flags;
    char pad_c[4]; int tasks[11]; int animationTask; int field_40; int extraTask;
};
Container02083554* GetFieldAt0x150_02053c6c(unsigned char*);
Scale021b38c8* GetField150Ptr0x488_02052e2c(Field150Holder02052e2c*);
void InitSlotEntries020543ec(char*, char*);
extern "C" void func_02072afc(int, int*, short*);
Entry02083554* FindEntryByShortField02083554(Container02083554*, int);
extern "C" int func_02072e94(char*, int, int, Entry02083554*, Entry02083554*);
void FormatAndAppendCombatMessage02072d58(int, char*, char*);
extern const char* data_ov017_021d7a38[2];
extern char data_ov017_021d7ace[], data_ov017_021d7ad6[];
static inline int ScaleProduct(int first, int second) { return (int)(((long long)first * second + 0x800) >> 12); }

// USA: func_ov017_021b38c8
extern "C" ARM int func_ov017_021b38c8(Reload021b38c8* self) {
    SafeAllocator* allocators;
    Entry02083554* entries;
    GameState* game = GameState::GetInstance();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    GameObject* combatant = GetCombatantWithFlag0x100_0200ff1c(game, self->combatant);
    if (!combatant) return 0;
    BattleAssets021b38c8* assets = ((Combatant021b38c8*)combatant)->GetAssets();
    if (!assets) return 0;
    Container02083554* data = GetFieldAt0x150_02053c6c((unsigned char*)combatant);
    if (!data) return 0;
    Scale021b38c8* scale = GetField150Ptr0x488_02052e2c((Field150Holder02052e2c*)combatant);
    if (!scale) return 0;
    if (!combatant->obj3D_.pModel_) {
        GameResources* resources = func_ov017_0218b5b0();
        int partyMember = 0;
        if (self->combatant >= 0 && self->combatant <= 3) partyMember = 1;
        char* slot;
        if (!partyMember) {
            ResourceSlots021b38c8* table = (ResourceSlots021b38c8*)resources->unknown_2cc;
            slot = table->fallback.storage;
        } else {
            ResourceSlots021b38c8* table = (ResourceSlots021b38c8*)resources->unknown_2cc;
            slot = table->party[assets->slot + 1].storage;
        }
        InitSlotEntries020543ec((char*)assets, slot);
    }
    int objectIds[11];
    short recordIds[12];
    func_02072afc(self->combatant, objectIds, recordIds);
    GameObject* object = game->GetGameObjectByIndex(objectIds[7]);
    if (object && recordIds[7] != object->obj3D_.unknown_2_) {
        GameObject* first = game->GetGameObjectByIndex(objectIds[3]);
        GameObject* second = game->GetGameObjectByIndex(objectIds[4]);
        if (first) first->obj3D_.unknown_2_ = -1;
        if (second) second->obj3D_.unknown_2_ = -1;
    }
    object = game->GetGameObjectByIndex(objectIds[1]);
    if (object && recordIds[1] != object->obj3D_.unknown_2_) {
        object = game->GetGameObjectByIndex(objectIds[0]);
        if (object) object->obj3D_.unknown_2_ = -1;
    }
    if (recordIds[0] != combatant->obj3D_.unknown_2_ && scale->field_8 < 0) {
        object = game->GetGameObjectByIndex(objectIds[5]);
        if (object) object->obj3D_.unknown_2_ = -1;
    }
    int reloadAnimation = self->flags & 2;
    object = game->GetGameObjectByIndex(objectIds[8]);
    if (object && recordIds[8] != object->obj3D_.unknown_2_) reloadAnimation = 1;
    int addFence;
    int force = self->flags & 1;
    self->flags &= ~1;
    int changed = 0;
    addFence = 1;
    FindEntryByShortField02083554(data, recordIds[7]);
    entries = data->entries;
    allocators = assets->allocators;
    for (int i = 0; i < 11; i++) {
        GameObject* object = game->GetGameObjectByIndex(objectIds[i]);
        if (!object) continue;
        if (!force) {
            int recordId = recordIds[i];
            int currentId = object->obj3D_.unknown_2_;
            if (recordId == currentId) continue;
        }
        object->obj3D_.unknown_2_ = recordIds[i];
        if (recordIds[i] < 0) continue;
        Entry02083554* entry = FindEntryByShortField02083554(data, recordIds[i]);
        if (!entry) continue;
        char path[0x80];
        if (!func_02072e94(path, self->combatant, i, entry, entries)) {
            object->obj3D_.Initialize();
            object->obj3D_.unknown_2_ = recordIds[i];
            continue;
        }
        object->obj3D_.Destroy();
        allocators[i].Reset();
        if (addFence) { loader->AddFence(); addFence = 0; }
        self->tasks[i] = loader->QueueLoadFileInGP2(data_ov017_021d7a38[0], path, &allocators[i]);
        if ((unsigned int)i <= 1) {
            int height = scale->height;
            short horizontal = 0.065f * (float)ScaleProduct(height, scale->width);
            short vertical = 0.065f * (float)height;
            object->obj3D_.SetScale(horizontal, vertical, horizontal);
            reloadAnimation = 1;
        } else if (i == 2 || i == 3 || (unsigned int)(i - 7) <= 2) {
            int horizontal = fix32_Divide(0x1000, ScaleProduct(scale->height, scale->width));
            int vertical = fix32_Divide(0x1000, scale->height);
            int depth = horizontal;
            if (i == 2 || i == 3 || i == 7) {
                int adjusted = scale->height - ((scale->height - 0x1000) >> 1);
                horizontal = ScaleProduct(horizontal, adjusted);
                vertical = ScaleProduct(vertical, adjusted);
                depth = ScaleProduct(depth, adjusted);
            }
            object->obj3D_.SetScale(horizontal, vertical, depth);
        }
        if (i == 8 || i == 1) reloadAnimation = 1;
        changed = 1;
    }
    if (reloadAnimation) {
        char animation[0x28];
        char extra[0x28];
        char path[0x50];
        FormatAndAppendCombatMessage02072d58(self->combatant, animation, extra);
        if (self->flags & 4) {
            animation[0] = 'm';
            sprintf(path, data_ov017_021d7ace, animation);
            self->flags &= ~4;
        } else sprintf(path, data_ov017_021d7ad6, animation);
        combatant->obj3D_.RemoveAllAnimationPackages();
        assets->animationAllocator.Reset();
        assets->extraAllocator.Reset();
        self->animationTask = loader->QueueLoadFileInGP2(data_ov017_021d7a38[1], path, &assets->animationAllocator);
        sprintf(path, data_ov017_021d7ad6, extra);
        self->extraTask = loader->QueueLoadFileInGP2(data_ov017_021d7a38[1], path, 0);
        changed = 1;
    }
    return changed;
}
