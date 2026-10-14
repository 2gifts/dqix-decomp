#include <globaldefs.h>

#if defined(jpn)
enum { BattleTableOffset = 0x73b0 };
#else
enum { BattleTableOffset = 0x75f0 };
#endif
#include "std_library_functions.h"
#include "GameState/GameState.h"
#include "GameState/BattleRecordSnapshot.h"

struct Entry020abe84 {
    unsigned int fieldA : 10;
    unsigned int rest : 22;
};

struct GameProgressRecords {
    unsigned char unknown0[BattleTableOffset];
    Entry020abe84 entries[308];
};

static inline unsigned int FieldA(const Entry020abe84* e) { return e->fieldA; }

int LoadBattleBlock020ac4c0(void*);
void AddClamped9BitField_020a0460(BattleRecordSnapshot*, unsigned int);
int CopyInBattleField0x7540_020ac494(void*);

// USA: func_020abe84
extern "C" ARM int func_020abe84(void* unused, short* indices, Entry020abe84* values, int count) {
    BattleRecordSnapshot block;
    Entry020abe84* table = reinterpret_cast<GameProgressRecords*>(GameState::GetInstance())->entries;
    int added = 0;
    int i;
    for (i = 0; i < count; i++) {
        short idx = (short)(indices[i] - 1);
        Entry020abe84* src = &values[i];
        if (idx < 0) continue;
        if (idx >= 0x134) continue;
        if (FieldA(&table[idx]) == 0 && src->fieldA != 0) {
            added++;
        }
        memcpy(&table[idx], src, sizeof(*src));
    }
    LoadBattleBlock020ac4c0(&block);
    AddClamped9BitField_020a0460(&block, added);
    CopyInBattleField0x7540_020ac494(&block);
    return 1;
}
