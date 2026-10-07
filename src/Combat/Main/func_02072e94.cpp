#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"
#include "Combat/Main/BattleList.h"

int GetFieldAt0x150(unsigned char* obj);
struct Field150Holder02052e2c;
extern "C" short* _Z28GetField150Ptr0x488_02052e2cP22Field150Holder02052e2c(Field150Holder02052e2c* obj);
struct StructDE234_020de234 {
    int a, b, c, d;
    unsigned int field10Low : 10;
    unsigned int field10Mid : 10;
    unsigned int field10High : 8;
    unsigned int field10Unused : 4;
    short e, f, g, h, i;
};
extern "C" unsigned short _Z31GetPreferredPackedField020de234P20StructDE234_020de234i(StructDE234_020de234* p, int preferMid);
struct EffectTable02072e94 {
    short values[10];
    unsigned char preferred : 1;
    unsigned char otherFlags : 7;
    unsigned char adjustment : 4;
    unsigned char otherAdjustment : 4;
};
struct Suffix02072e94 { char text[8]; };
struct Letters02072e94 { char text[10]; };
extern Suffix02072e94 data_020e8834;
extern Letters02072e94 data_020e883c;
extern char data_020f0d04[];
extern char data_020f0d0a[];

// USA: func_02072e94
extern "C" ARM int func_02072e94(char* out, int combatantId, int kind,
                                StructDE234_020de234* entry, void* optional) {
    GameObject* combatant = GetCombatantWithFlag0x100(GameState::GetInstance(), combatantId);
    unsigned char* fields = (unsigned char*)GetFieldAt0x150((unsigned char*)combatant);
    EffectTable02072e94* table = (EffectTable02072e94*)_Z28GetField150Ptr0x488_02052e2cP22Field150Holder02052e2c((Field150Holder02052e2c*)combatant);
    int preferred = table->preferred;
    int value = _Z31GetPreferredPackedField020de234P20StructDE234_020de234i(entry, table->preferred);
    StructDE234_020de234* alternate = NULL;
    StructDE234_020de234* primary = NULL;
    if (optional != NULL) {
        primary = (StructDE234_020de234*)optional;
        alternate = (StructDE234_020de234*)((char*)optional + 0xe0);
    }
    Suffix02072e94 suffix = data_020e8834;
    char letter[2] = {};
    char extra[2] = {};
    if (kind == 4) {
        strcpy(suffix.text, data_020f0d04);
        letter[0] = 'a';
        letter[1] = 0;
        value += table->adjustment;
    }
    int alternateValue = -1;
    if (alternate != NULL && alternate->g > -1) {
        alternateValue = _Z31GetPreferredPackedField020de234P20StructDE234_020de234i(alternate, preferred);
    }
    if (kind == 3) {
        letter[0] = 'a';
        letter[1] = 0;
        if (alternateValue >= 0) {
            unsigned int category = alternateValue / 100;
            if (category < 10) {
                Letters02072e94 letters = data_020e883c;
                char c = letters.text[category];
                if (c == 0) return 0;
                letter[0] = c;
                if (category == 3 && preferred == 0 && table->values[3] == 9001) {
                    letter[0] = 'f';
                }
            } else {
                return 0;
            }
        }
    }
    if (kind == 5 && primary != NULL) {
        if (table->values[4] == 8010 || table->values[4] < 0) {
            value = _Z31GetPreferredPackedField020de234P20StructDE234_020de234i(primary, preferred);
        }
        strcpy(suffix.text, data_020f0d04);
    }
    if (kind == 6) strcpy(suffix.text, data_020f0d04);
    if (entry->g == 1000) value += fields[0x56a];
    sprintf(out, data_020f0d0a, (char)entry->field10High, value, letter, extra, suffix.text);
    return 1;
}
