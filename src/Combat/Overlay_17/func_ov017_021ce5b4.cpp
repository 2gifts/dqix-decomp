#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct CombatantEvent021ce5b4 {
    char padding[4];
    unsigned short combatantId;
    signed char field6;
    signed char field7;
    signed char field8;
    signed char field9;
    signed char fieldA;
    signed char fieldB;
};

struct CombatantEventFields021ce5b4 {
    char padding[0x809];
    signed char field809;
    signed char field80A;
    char padding80B;
    signed char field80C;
    signed char field80D;
    signed char field80E;
    char padding80F;
    signed char field810;
};

struct CombatantEventRegion021ce5b4 {
#if defined(jpn)
    char padding[0x1c];
#else
    char padding[0x34];
#endif
    CombatantEventFields021ce5b4 fields;
};

struct CombatantData021ce5b4 {
#if defined(jpn)
    char padding[0x80];
#else
    char padding[0x100];
#endif
    CombatantEventRegion021ce5b4 eventRegion;
};

CombatantData021ce5b4* GetFieldAt0x150(unsigned char* obj);

static inline CombatantEventRegion021ce5b4* GetEventRegion(CombatantData021ce5b4* data) {
    return &data->eventRegion;
}

static inline CombatantEventFields021ce5b4* GetEventFields(CombatantEventRegion021ce5b4* region) {
    return &region->fields;
}

// JPN: func_ov017_021cea5c
// USA: func_ov017_021ce5b4
extern "C" ARM void* func_ov017_021ce5b4(int unused, CombatantEvent021ce5b4* event, GameState* gameState) {
    GameObject* combatant = GetCombatantWithFlag0x100(gameState, event->combatantId);
    if (combatant == NULL) return combatant;

    CombatantData021ce5b4* data = GetFieldAt0x150((unsigned char*)combatant);
    if (data == NULL) return data;

    CombatantEventFields021ce5b4* fields = GetEventFields(GetEventRegion(data));
    fields->field809 = event->field6;
    fields->field80A = event->field7;
    fields->field80C = event->field8;
    fields->field80D = event->field9;
    fields->field80E = event->fieldA;
    fields->field810 = event->fieldB;
    return fields;
}
