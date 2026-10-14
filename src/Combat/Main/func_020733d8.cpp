#include <globaldefs.h>
#include "GameState/GameState.h"
#include "System/Matrix.h"
#include "Graphics/Vector.h"

extern "C" void* func_0205ec34(void);
int TestBitInByteArray(int unused, unsigned char* arr, int index);
extern "C" int _Z40FindCombatantWithNegativeField2_021a20c0iii(int unused, int mult, int limit);
extern "C" void* __clear(void* dst, int count);
extern "C" void* func_0202ae18(void);
extern "C" void VectorizedInvertedMemcpy(const void* src, void* dst, unsigned int length);
int CheckField0NonZero(int* obj);

struct SearchStruct;
int TestBitBySignedByteIndex(struct SearchStruct* obj, int value);
int GetSignedByte0x1ca(void* obj);

// Writes the object's position to *out.
extern "C" void func_02034104(void* out, GameObject* obj);

struct ListEntry_02028430 { unsigned char id; unsigned char unk[0xF]; };
struct List_02028430 { unsigned char unk0[2]; unsigned char count; unsigned char unk3; struct ListEntry_02028430* entries; };
struct ListEntry_02028430* GetListEntryChecked(struct List_02028430* list, int index);

struct ListEntry_020283c0 { unsigned char id; unsigned char unk[0xF]; };
struct List_020283c0 { unsigned char unk0[2]; unsigned char count; unsigned char unk3; struct ListEntry_020283c0* entries; };
struct ListEntry_020283c0* FindListEntryById(struct List_020283c0* list, int id);

struct SearchCtx_02028460 { unsigned char pad0[2]; unsigned char count; unsigned char pad1[1]; void* nodes; };
extern "C" int func_02028460(struct SearchCtx_02028460* ctx, Vector3i* pos);

struct Bounds02031118 { Vector3i min; Vector3i max; };
extern "C" int func_02031118(Vector3i* p, struct Bounds02031118* b);
extern "C" int func_02031468(Vector3i* a, Vector3i* b, Vector3i* p, Vector3i* out);

extern "C" void _Z20SetVec3At0x002073d50P18Vec3Target02073d50iii(struct Vec3Target02073d50* obj, int x, int y, int z);
extern "C" int _Z29CheckAnySlotMatchesId02073d58iPvi(int a, void* b, int c);
extern "C" int func_02073dfc(unsigned char* self, Vector3i* pos);
extern "C" void* _Z31FindMatchingEntryByMask02073ec4iPv(int mask, void* list);
extern "C" int _Z27SelectWeightedEntry02073fdcPv(void* p);
extern "C" int func_ov017_021a2128(void* a, int b, int c, int d, Vector3i* e, int f, int g, int h);

extern "C" int rand(void);

struct Words4020733d8 { int v[4]; };
extern struct Words4020733d8 data_020e88a8;

// Position triple stored as an array, so it is copied as one block (unlike Vector3i).
struct Pos020733d8 { int v[3]; };

struct ModeField020733d8 {
    unsigned short mode : 2;
    unsigned short rest : 14;
};

struct FlagC2Field020733d8 {
    unsigned char pad : 6;
    unsigned char bit6 : 1;
    unsigned char pad2 : 1;
};

struct LevelField020733d8 {
    unsigned int lowBits : 21;
    unsigned int level : 4;
    unsigned int highBits : 7;
};

struct ZoneNode020733d8 {
    unsigned char id;
    unsigned char mask;
    unsigned char count;
    unsigned char flags;
    short x;
    short y;
    short z;
    unsigned char pad[2];
    struct ZoneNode020733d8** children;
};

static inline int NodeCount020733d8(unsigned char* self) {
    return ((struct List_020283c0*)(self + 0x18))->count;
}

#define SELF_MODE(self) (((struct ModeField020733d8*)((self) + 2))->mode)
#define SET_VEC3(v, x, y, z) _Z20SetVec3At0x002073d50P18Vec3Target02073d50iii((struct Vec3Target02073d50*)(v), x, y, z)

// USA: func_020733d8
extern "C" ARM void func_020733d8(unsigned char* self, int unused) {
    if (self == 0 || self[0xc] == 0) {
        return;
    }

    void* dataBase = func_0205ec34();
    if (TestBitInByteArray((int)dataBase, (unsigned char*)dataBase + 0x8c, 0x79a) != 0 &&
        *(unsigned short*)self >= 0x190 && *(unsigned short*)self <= 0x199) {
        return;
    }

    GameState* gameState = GameState::GetInstance();
    GameResources* globalB = func_ov017_0218b5b0();
    unsigned short savedId = *(unsigned short*)self;
    int timer = *(int*)(self + 8) + gameState->GetTrueDeltaTime();
    *(int*)(self + 8) = timer;
    if (timer < 0x3e8) {
        return;
    }

    if (_Z40FindCombatantWithNegativeField2_021a20c0iii((int)globalB, SELF_MODE(self), 0xc) < 0) {
        return;
    }

    Vector3i targetPos;
    void* matchEntry = 0;
    __clear(&targetPos, sizeof(targetPos));

    struct Words4020733d8 weights = data_020e88a8;
    int resultCount;
    int bestIdx = -1;
    int status = -1;
    resultCount = 0;
    int retry;
    struct ZoneNode020733d8* dest;
    int level;
    int wait;
    int chosen;
    GameObject* combatant;
    int angle;
    struct Pos020733d8 slotPos;
    Vector3i slotDir;
    struct Pos020733d8 slotPosTmp;

    for (retry = 0; retry < 4; retry++) {
        matchEntry = 0;

        // Pick the spawn slot with the fewest visible objects around it.
        // (The locals of these blocks are declared newest-first.)
        do {
            struct Pos020733d8 baseTmp;
            int d;
            int best;
            int minCount;
            int count;
            int c;
            int outCount;
            int fewCounts[4];
            int ids[4];
            GameObject* obj;
            int m;
            struct Bounds02031118 box;
            struct Pos020733d8 base;
            GameObject* monster;
            int k;
            int counts[4];
            int idx;
            int found;
            int slot;
            GameObject* member;
            int j;
            GameObject* unknown;
            int candIds[4];
            int candCount;
            int localWeights[4];
            int* counter;
            GameState* gs;

            gs = GameState::GetInstance();
            counter = (int*)func_0202ae18();
            VectorizedInvertedMemcpy(weights.v, localWeights, 0x10);

            candCount = 0;
            if (CheckField0NonZero(counter) == 0) {
                unknown = gs->GetUnknownGameObject();
                if (unknown != 0 && localWeights[0] == -1) {
                    candIds[0] = *(short*)((char*)unknown + 4);
                    candCount = 1;
                }
            } else {
                for (j = 0; j < 4; j++) {
                    if (!TestBitBySignedByteIndex((struct SearchStruct*)counter, j)) {
                        continue;
                    }
                    member = gs->GetPartyMemberByIndex(j);
                    if (member == 0) {
                        continue;
                    }
                    if (*(unsigned short*)self != member->obj3D_.GetField06()) {
                        continue;
                    }

                    if (GetSignedByte0x1ca(member) < 0) {
                        slot = j;
                    } else {
                        slot = GetSignedByte0x1ca(member);
                    }

                    found = 0;
                    for (idx = 0; idx < 4; idx++) {
                        if (slot == localWeights[idx]) {
                            found = 1;
                            break;
                        }
                    }
                    if (found) {
                        continue;
                    }
                    if (slot != -1) {
                        candIds[candCount++] = slot;
                    }
                }
            }

            if (candCount == 0) {
                bestIdx = -1;
                break;
            }

            for (k = 0; k < candCount; k++) {
                counts[k] = 0;
                monster = gs->GetMaybeWanderingMonsterByIndex(candIds[k]);
                func_02034104(&baseTmp, monster);
                base = baseTmp;

                box.min.x = base.v[0] + 0xf000;
                box.min.y = base.v[1] + 0x1800;
                box.min.z = base.v[2] + 0xf000;
                SET_VEC3(&box.max, base.v[0] - 0xf000, base.v[1] - 0x800, base.v[2] - 0xf000);

                for (m = 0; m < 0xc; m++) {
                    obj = gs->GetGameObjectByIndex(m + (SELF_MODE(self) * 0xc + 0x70));
                    if (obj == 0) {
                        continue;
                    }
                    if (!obj->obj3D_.IsVisible()) {
                        continue;
                    }
                    if (func_02031118(&obj->obj3D_.position_, &box)) {
                        counts[k]++;
                    }
                }
            }

            outCount = 0;
            for (c = 0; c < candCount; c++) {
                count = counts[c];
                if (count < 3) {
                    ids[outCount] = candIds[c];
                    fewCounts[outCount] = count;
                    outCount++;
                }
            }

            if (outCount == 0) {
                bestIdx = -1;
                break;
            }

            minCount = 0xc;
            best = -1;
            for (d = 0; d < outCount; d++) {
                if (fewCounts[d] < minCount) {
                    best = ids[d];
                    minCount = fewCounts[d];
                }
            }
            bestIdx = best;
        } while (0);

        if (bestIdx < 0) {
            return;
        }
        weights.v[resultCount++] = bestIdx;

        // Pick the next zone node for the slot's combatant and aim at it.
        do {
            struct Pos020733d8 selfTmp;
            Vector3i zoneTmp;
            int len;
            Vector3i diff;
            int reach;
            int closestDist;
            Vector3i closest;
            Vector3i entryPos;
            struct ZoneNode020733d8* entry;
            int dot;
            Vector3i dir;
            Vector3i nodePos;
            int bestDot;
            int q;
            struct ZoneNode020733d8* node;
            int i;
            int notFound;
            unsigned char zoneId;
            Vector3i zonePos;
            int p;
            struct ZoneNode020733d8* stored[16];
            int pick;
            int matchCount;
            Vector3i facing;
            struct Pos020733d8 selfPos;
            int closestIdx;
            struct ZoneNode020733d8* zone;
            GameObject* slotObj;

            slotObj = GetCombatantWithFlag0x100(GameState::GetInstance(), bestIdx);
            if (slotObj == 0) {
                status = -1;
                break;
            }
            if (!((struct FlagC2Field020733d8*)((char*)slotObj + 0xc2))->bit6) {
                status = -1;
                break;
            }

            zone = (struct ZoneNode020733d8*)GetListEntryChecked(
                (struct List_02028430*)(self + 0x18), *(unsigned short*)((char*)slotObj + 0xb8));
            if (zone == 0) {
                func_02034104(&zoneTmp, slotObj);
                closestIdx = func_02028460((struct SearchCtx_02028460*)(self + 0x18), &zoneTmp);
                if (closestIdx < 0) {
                    status = -1;
                    break;
                }
                zone = (struct ZoneNode020733d8*)GetListEntryChecked((struct List_02028430*)(self + 0x18), closestIdx);
                if (zone == 0) {
                    status = -1;
                    break;
                }
                *(unsigned short*)((char*)slotObj + 0xb8) = closestIdx;
            }
            if (zone == 0 || zone->count == 0) {
                status = -1;
                break;
            }

            func_02034104(&selfTmp, slotObj);
            selfPos = selfTmp;
            __clear(&facing, sizeof(facing));
            facing.x = fix32sin(*(int*)((char*)slotObj + 0x54));
            facing.z = fix32cos(*(int*)((char*)slotObj + 0x54));

            pick = -1;
            matchCount = 0;
            for (p = 0; p < zone->count; p++) {
                if (_Z29CheckAnySlotMatchesId02073d58iPvi(zone->children[p]->id, self, pick) != 0) {
                    continue;
                }
                stored[matchCount++] = zone->children[p];
            }

            zonePos.x = zone->x << 12;
            zonePos.y = zone->y << 12;
            zonePos.z = zone->z << 12;
            if (Vector3fix_Distance(&zonePos, (Vector3fix*)&selfPos) > 0x5000) {
                zoneId = zone->id;
                notFound = 1;
                for (i = 0; i < matchCount; i++) {
                    if (zoneId == stored[i]->id) {
                        notFound = 0;
                        break;
                    }
                }
                if (notFound) {
                    if (_Z29CheckAnySlotMatchesId02073d58iPvi(zoneId, self, -1) == 0) {
                        stored[matchCount++] = zone;
                    }
                }
            }

            bestDot = 0;
            for (q = 0; q < matchCount; q++) {
                node = stored[q];
                SET_VEC3(&nodePos, node->x << 12, node->y << 12, node->z << 12);
                Vector3fix_Subtract(&nodePos, (Vector3fix*)&selfPos, &dir);
                facing.y = 0;
                Vector3fix_Normalize(&dir, &dir);
                dot = Vector3fix_InnerProduct(&facing, &dir);
                if (dot <= 0) {
                    continue;
                }
                if (bestDot < dot) {
                    bestDot = dot;
                    pick = node->id;
                }
            }

            if (pick < 0) {
                if (matchCount == 0) {
                    status = -1;
                    break;
                }
                pick = stored[rand() % matchCount]->id;
            }

            entry = (struct ZoneNode020733d8*)FindListEntryById((struct List_020283c0*)(self + 0x18), pick);
            if (entry == 0) {
                status = -1;
                break;
            }

            entryPos.x = entry->x << 12;
            entryPos.y = entry->y << 12;
            entryPos.z = entry->z << 12;
            targetPos = entryPos;

            if (zone != entry && Vector3fix_Distance(&entryPos, (Vector3fix*)&selfPos) > 0xa000) {
                closestDist = func_02031468(&entryPos, &zonePos, (Vector3fix*)&selfPos, &closest);
                if (closestDist > 0) {
                    if (closestDist < 0xa000) {
                        reach = FIX32_MULTIPLY(fix32_Sqrt(0x1000 - fix32_Divide(FIX32_MULTIPLY(closestDist, closestDist), 0x64000)), 0xa000);
                        if (reach > 0x5000) {
                            Vector3fix_Subtract(&entryPos, &closest, &diff);
                            len = Vector3fix_Length(&diff);
                            Vector3fix_Normalize(&diff, &diff);
                            if (len < reach) {
                                Vector3fixMultiplyScalar(&diff, len, &diff);
                            } else {
                                Vector3fixMultiplyScalar(&diff, reach, &diff);
                            }
                            Vector3fix_Add(&closest, &diff, &targetPos);
                        }
                    } else {
                        status = -1;
                        break;
                    }
                }
            }

            if (func_02073dfc(self, &targetPos) != 0 && NodeCount020733d8(self) > 4) {
                status = -1;
                break;
            }
            status = pick;
        } while (0);

        if (status < 0) {
            continue;
        }
        if (func_02073dfc(self, &targetPos) != 0) {
            continue;
        }

        // Skip the destination if a visible object of this group already stands near it.
        int crowded;
        {
            GameObject* obj;
            int i;
            struct Bounds02031118 area;
            GameState* gs;

            gs = GameState::GetInstance();
            SET_VEC3(&area.min, targetPos.x + 0x3000, targetPos.y + 0x5000, targetPos.z + 0x3000);
            SET_VEC3(&area.max, targetPos.x - 0x3000, targetPos.y - 0x5000, targetPos.z - 0x3000);
            for (i = 0; i < 0xc; i++) {
                obj = gs->GetGameObjectByIndex(i + (SELF_MODE(self) * 0xc + 0x70));
                if (obj == 0) {
                    continue;
                }
                if (!obj->obj3D_.IsVisible()) {
                    continue;
                }
                if (func_02031118(&obj->obj3D_.position_, &area)) {
                    crowded = 1;
                    goto crowdChecked;
                }
            }
            crowded = 0;
        }
    crowdChecked:
        if (crowded) {
            continue;
        }

        dest = (struct ZoneNode020733d8*)FindListEntryById((struct List_020283c0*)(self + 0x18), status);
        if (dest == 0) {
            continue;
        }
        if (dest != 0 && (dest->flags & 2)) {
            continue;
        }
        matchEntry = _Z31FindMatchingEntryByMask02073ec4iPv(dest->mask, self + 0x60);
        if (matchEntry == 0) {
            continue;
        }

        level = ((struct LevelField020733d8*)((char*)matchEntry + 4))->level;
        wait = 6 - level;
        wait = wait + 1;
        if (*(int*)(self + 8) >= wait * 0x3e8) {
            break;
        }
    }

    if (matchEntry == 0) {
        return;
    }
    chosen = _Z27SelectWeightedEntry02073fdcPv(matchEntry);
    if (chosen == -1) {
        return;
    }

    combatant = GetCombatantWithFlag0x100(gameState, bestIdx);
    angle = 0;
    if (combatant != 0) {
        func_02034104(&slotPosTmp, combatant);
        slotPos = slotPosTmp;
        Vector3fix_Subtract((Vector3fix*)&slotPos, &targetPos, &slotDir);
        Vector3fix_Normalize(&slotDir, &slotDir);
        angle = fix32_Atan2(slotDir.x, slotDir.z);
    }

    if (func_ov017_021a2128(globalB, savedId, chosen, *(unsigned short*)matchEntry, &targetPos, angle,
                            (unsigned short)status, 0) != 0) {
        *(int*)(self + 8) = 0;
    }
}
