#include <globaldefs.h>
#include "GameState/GameState.h"

struct S02053dc0;
struct TargetResult_021f8628 {
    short type;
    unsigned char id;
    unsigned char group;
};
struct TargetResult_021f8628* GetField0x19cOrNull(struct S02053dc0* p);

GameObject* GetCombatantWithFlag0x400ByID(int unused, int id);

struct S_10088_inner { char unk[0x14]; int flags; };
struct S_10088 { char unk[0x138]; struct S_10088_inner* inner; };
int IsFlag10088Set(struct S_10088* obj);

extern "C" float func_ov024_021db358(GameObject* obj);

struct Group_021f8628 {
    unsigned char b0;
    unsigned char lo : 4;
    unsigned char groupCount : 2;
    char pad2[4];
    unsigned char ids[8];
    unsigned char memberCount : 4;
    char padf[9];
};

// USA: func_ov024_021f8628
extern "C" ARM int func_ov024_021f8628(char** obj, void* p1, struct S02053dc0* p2, unsigned short* outB) {
    struct TargetResult_021f8628* result = GetField0x19cOrNull(p2);
    if (!result) return 0;

    int bestId = 0;
    float best = 1.1f;
    int bestGroup = 0;
    int found = 0;
    struct Group_021f8628* groups = (struct Group_021f8628*)(*obj + 0x81b0);
    for (int i = 0; i < groups->groupCount; i++) {
        for (int j = 0; j < groups[i].memberCount; j++) {
            GameObject* c = GetCombatantWithFlag0x400ByID((int)*obj, (short)(groups[i].ids[j] + 0xc0));
            if (c == 0) continue;
            if (IsFlag10088Set((struct S_10088*)c)) continue;
            if (func_ov024_021db358(c) < best) {
                best = func_ov024_021db358(c);
                bestGroup = i;
                bestId = groups[i].ids[j] + 0xc0;
                found = 1;
            }
        }
    }
    if (!found) return 0;

    result->type = 1;
    result->id = bestId;
    result->group = bestGroup;
    *outB = 1;
    return 1;
}
