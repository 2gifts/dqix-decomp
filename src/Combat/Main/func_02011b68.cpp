#include <globaldefs.h>
#include "System/Memory.h"
#include "std_library_functions.h"

struct SixBytes {
    unsigned char b[6];
};
struct CacheFlags {
    unsigned char active : 1;
    unsigned char flags : 7;
};
struct State0200fad4 {
    SixBytes key;
    CacheFlags state;
    unsigned char pad_07;
    float elapsed;
};
struct PartyKey {
    SixBytes key;
    signed char id;
    char pad_07[3];
};
struct TimedKey {
    SixBytes key;
    char pad_06[0xb];
    unsigned char timer;
    unsigned short count : 14;
    unsigned short active : 1;
    unsigned short flag : 1;
    char pad_14[0x18];
};
struct KeyManager {
    char pad_00[0x3ac];
    int protagonist;
    char pad_3b0[0x14];
    unsigned int deltaTicks;
    char pad_3c8[0xc];
    float timeScale;
    char pad_3d8[0x5345];
    unsigned char selected[4];
    signed char selectedCount;
    char pad_5722[0x1ade];
    TimedKey timed[16];
    PartyKey previous[3];
    char pad_74de[0xaae];
    State0200fad4 cache[3];
};
int CompareSixBytes(unsigned char*, SixBytes);
extern "C" void _Z26ClearFlagsAndValue0200fad4P13State0200fad4(State0200fad4*);

// USA: func_02011b68
extern "C" ARM void func_02011b68(KeyManager* self) {
    unsigned char selected[4] = {0};
    memcpy(selected, self->selected, (unsigned char)self->selectedCount);
    int selectedCount = self->selectedCount;
    signed char pendingCount = 0;
    SixBytes pending[4];
    memset(pending, 0, sizeof(pending));
    PartyKey* previous = self->previous;
    for (int i = 0; i < 3; i++) self->cache[i].state.active = 0;
    for (int i = 0; i < 3; i++, previous++) {
        int insert = 0;
        SixBytes key;
        VectorizedMemset(&key, insert, sizeof(key));
        for (int j = 0; j < selectedCount; j++) {
            if (previous->id == selected[j]) {
                key = previous->key;
                if (previous->id >= 0 && previous->id != self->protagonist) {
                    insert = 1;
                    for (int k = 0; k < 3; k++) {
                        if (CompareSixBytes(self->cache[k].key.b, key)) {
                            self->cache[k].state.active = 1;
                            insert = 0;
                            break;
                        }
                    }
                }
            }
        }
        if (insert) {
            pending[pendingCount] = key;
            pendingCount++;
        }
    }
    for (int i = 0; i < pendingCount; i++) {
        int empty;
        for (int k = 0; k < 6; k++) {
            if (pending[i].b[k] != 0) {
                empty = 0;
                goto checkedKey;
            }
        }
        empty = 1;
checkedKey:
        if (!empty) {
            for (int j = 0; j < 3; j++) {
                if (!self->cache[j].state.active) {
                    State0200fad4* slot = &self->cache[j];
                    _Z26ClearFlagsAndValue0200fad4P13State0200fad4(slot);
                    self->cache[j].state.active = 1;
                    slot->key = pending[i];
                    break;
                }
            }
        }
    }
    float elapsed = (float)self->deltaTicks * self->timeScale;
    for (int i = 0; i < 3; i++) {
        if (self->cache[i].state.active) {
            self->cache[i].elapsed += elapsed;
            if (self->cache[i].elapsed >= 60.0f) {
                TimedKey* entry = self->timed;
                for (int j = 0; j < 16; j++, entry++) {
                    if (entry->active && CompareSixBytes(entry->key.b, self->cache[i].key)) {
                        if (++entry->timer >= 60) {
                            if (entry->count >= 9999) entry->timer = 59;
                            else {
                                entry->count++;
                                entry->timer = 0;
                            }
                        }
                        break;
                    }
                }
                self->cache[i].elapsed -= 60.0f;
            }
        }
    }
    for (int i = 0; i < 3; i++) {
        if (!self->cache[i].state.active) _Z26ClearFlagsAndValue0200fad4P13State0200fad4(&self->cache[i]);
    }
}
