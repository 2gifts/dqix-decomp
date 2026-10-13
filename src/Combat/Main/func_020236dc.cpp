#include <globaldefs.h>
#include "Combat/ActionDisplay.h"
#include "GameState/GameState.h"
#include "World/Zone3D.h"

struct MemberFields020236dc {
    Object3D object;
    unsigned char paddingAc[0x130 - 0xac];
    unsigned int* stateFlags;
    unsigned char padding134[0x18c - 0x134];
    unsigned int flags;
    unsigned char padding190[0x1b2 - 0x190];
    unsigned short field1b2;
};
union Member020236dc {
    GameObject game;
    MemberFields020236dc fields;
};
struct ZoneFields020236dc {
    unsigned char padding[0x2784];
    short key;
    unsigned short id;
};
struct EntryNode020236dc {
    unsigned short field00;
    unsigned char count;
    unsigned char padding03;
    unsigned short* ids;
    unsigned char padding08[8];
    EntryNode020236dc* next;
};
struct Container02021394;
struct EntryOwner020236dc {
    unsigned char padding[0x754];
    EntryNode020236dc* list;
};
struct SaveFlags020236dc {
    unsigned char padding[0x8c];
    unsigned char flags[1];
};
struct FlagWord02046708;
struct S3f58;
extern "C" GameResources* func_ov017_0218b5b0();
extern "C" void* func_02012fe4();
extern "C" void* func_0202ae18();
extern "C" void* func_0205ec34();
extern "C" void* _Z27GetDataPtr02114e04_020d6c00v();
GameObject* GetCombatantWithFlag0x1000(GameState*, int);
extern "C" int _Z17TestFlags02046708P16FlagWord02046708j(FlagWord02046708*, unsigned int);
void GetFields1a8And1ac(S3f58*, int*, int*);
unsigned char GetField0x1b0(void*);
int GetField0x3acValue(GameState*);
int GetSignedByte0x1c9(void*);
int TestBitInByteArray(int, unsigned char*, int);
extern "C" int _Z26FindEntryByKeyPair02021394P17Container02021394iiPsS1_(Container02021394*, int, int, short*, short*);
extern unsigned short data_020e704c[];

struct ActionOutputState020236dc {
    CombatActionPosition* entries;
    int count;
};

// USA: func_020236dc
extern "C" ARM int func_020236dc(CombatActionPosition* entries, unsigned char* groups, Vector3i* position) {
    GameState* game = GameState::GetInstance();
    GameResources* resources = func_ov017_0218b5b0();
    GameObject* protagonist = game->GetProtagonist();
    Zone3D* zone = (Zone3D*)func_02012fe4();
    func_0202ae18();
    SaveFlags020236dc* saved = (SaveFlags020236dc*)func_0205ec34();
    FlagWord02046708* flags = (FlagWord02046708*)_Z27GetDataPtr02114e04_020d6c00v();
    Container02021394* container = (Container02021394*)resources->unknown_ptr_36d0;
    ActionOutputState020236dc output;
    output.entries = entries;
    output.count = 0;
    for (int i = 0; i < 4; ++i) {
        Member020236dc* member = (Member020236dc*)GetCombatantWithFlag0x100(game, i);
        if (!member || !(member->fields.flags & 8)) continue;
        if (GetCombatantWithFlag0x1000(game, i)) {
            unsigned char index = 0;
            unsigned short zoneId = zone->unknown_4_;
            int excluded = 0;
            for (; data_020e704c[index]; ++index) {
                if (zoneId == data_020e704c[index]) {
                    excluded = 1;
                    break;
                }
            }
            if (excluded) continue;
        }
        CombatActionPosition* entry = &output.entries[output.count];
        entry->combatantId = i;
        ++output.count;
        entry->flag11 = member->fields.field1b2 && !_Z17TestFlags02046708P16FlagWord02046708j(flags, 0x80000) ? 1 : 0;
        entry->flag12 = protagonist ? protagonist->obj3D_.GetField06() == member->game.obj3D_.GetField06() : 0;
        if (member->fields.flags & 0x10) {
            GetFields1a8And1ac((S3f58*)member, &entry->position.x, &entry->position.z);
            entry->group = GetField0x1b0(member);
            entry->variant = groups[entry->group];
            ++groups[entry->group];
            if (i == GetField0x3acValue(game)) {
                position->x = entry->position.x;
                position->z = entry->position.z;
            }
        } else {
            Vector3i memberPosition = member->game.obj3D_.position_;
            entry->position.x = memberPosition.x;
            entry->position.y = memberPosition.y;
            entry->position.z = memberPosition.z;
            entry->variant = -1;
        }
        entry->elementId = 5;
        entry->palette = member->game.obj3D_.unknown_4_ + 4;
        GameObject* party = game->GetPartyMemberByIndex(i);
        GameObject* active = GetCombatantWithFlag0x1000(game, i);
        if (party && (member->game.obj3D_.unknown_4_ == 0 || active)) entry->type = GetSignedByte0x1c9(party) + 0x58;
        else entry->type = member->game.obj3D_.unknown_4_ + 0x5b;
        if (party) entry->flag13 = GetSignedByte0x1c9(party);
        if (*member->fields.stateFlags & 1) {
            entry->elementId = 6;
            entry->palette = 6;
        }
    }
    int found = 0;
    EntryOwner020236dc* owner = (EntryOwner020236dc*)func_ov017_0218b5b0()->unknown_ptr_36d0;
    ZoneFields020236dc* zoneFields = (ZoneFields020236dc*)zone;
    if (owner) {
        for (EntryNode020236dc* node = owner->list; node; node = node->next) {
            for (int i = 0; i < node->count; ++i) {
                int id = node->ids[i];
                int zoneId = zoneFields->id;
                if (id == zoneId) {
                    found = 1;
                    break;
                }
            }
        }
    }
    if (found && TestBitInByteArray((int)saved, saved->flags, 0x2b)) {
        short x = 0;
        short z = 0;
        if (_Z26FindEntryByKeyPair02021394P17Container02021394iiPsS1_(container, zoneFields->id, (unsigned char)zoneFields->key, &x, &z)) {
            CombatActionPosition* entry = &output.entries[output.count];
            ++output.count;
            VectorizedMemset(entry, 0, sizeof(*entry));
            entry->variant = -1;
            entry->combatantId = 0xff;
            entry->position.x = x << 12;
            entry->position.z = z << 12;
            entry->elementId = 0x1b;
            entry->palette = 7;
            entry->type = 0x74;
        }
    }
    return output.count;
}
