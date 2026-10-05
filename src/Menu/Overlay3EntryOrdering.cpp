// External entry names follow the fork's symbols.txt at b399f53.
// Local argument views remain provisional; see contribution interface notes.
#include "globaldefs.h"

// These packed fields are compared by the original menu ordering routine;
// their gameplay names are not established.
struct Overlay3OrderedEntry {
    unsigned char unknown00[0xb];
    unsigned char rank : 7;
    unsigned char unknownB7 : 1;
    unsigned int unknownC0 : 4;
    unsigned int category : 4;
    unsigned int unknownC8 : 7;
    unsigned int order : 4;
    unsigned int suborder : 5;
    unsigned int unknownC24 : 8;
};
struct Overlay3EntryProvider {
    unsigned char unknown00[0x1b38];
    int count;
};
struct Overlay3EntryOrdering {
    unsigned char unknown00[0xf4];
    Overlay3OrderedEntry* entries[31];
    Overlay3EntryProvider* provider;
};
extern "C" int _Z21CountNibble0xcEquals9P18NibbleElem02098e70(Overlay3EntryProvider*);
extern "C" int _Z21CountNibble0xcEqualsAP18NibbleElem02098eac(Overlay3EntryProvider*);

extern "C" ARM void func_ov003_02170688(Overlay3EntryOrdering* state) {
    Overlay3EntryProvider* provider = state->provider;
    int count = provider->count;
    int first = _Z21CountNibble0xcEquals9P18NibbleElem02098e70(provider);
    int split = first + _Z21CountNibble0xcEqualsAP18NibbleElem02098eac(provider);
    int moved = 0;
    for (int i = 0; i < count; ++i) {
        Overlay3OrderedEntry* entry = state->entries[i];
        if (entry->category == 9 || entry->category == 10) {
            state->entries[i] = state->entries[moved];
            state->entries[moved] = entry;
            ++moved;
        }
    }
    for (int i = 0; i < split - 1; ++i) {
        for (int j = 0; j < split - 1 - i; ++j) {
            Overlay3OrderedEntry* a = state->entries[j];
            Overlay3OrderedEntry* b = state->entries[j + 1];
            if (a->rank < b->rank) {
                state->entries[j] = b;
                state->entries[j + 1] = a;
            } else if (a->rank > b->rank) {
                continue;
            } else {
                if (a->order < b->order) {
                    state->entries[j] = b;
                    state->entries[j + 1] = a;
                } else if (a->order > b->order) {
                    continue;
                } else if (a->suborder < b->suborder) {
                    state->entries[j] = b;
                    state->entries[j + 1] = a;
                }
            }
        }
    }
    int tailPass = 0;
    for (int i = split; i < count - 1; ++i, ++tailPass) {
        for (int j = split; j < count - 1 - tailPass; ++j) {
            Overlay3OrderedEntry* a = state->entries[j];
            Overlay3OrderedEntry* b = state->entries[j + 1];
            if (a->rank < b->rank) {
                state->entries[j] = b;
                state->entries[j + 1] = a;
            } else if (a->rank > b->rank) {
                continue;
            } else {
                if (a->order < b->order) {
                    state->entries[j] = b;
                    state->entries[j + 1] = a;
                } else if (a->order > b->order) {
                    continue;
                } else {
                    if (a->suborder < b->suborder) {
                        state->entries[j] = b;
                        state->entries[j + 1] = a;
                    } else if (a->suborder > b->suborder) {
                        continue;
                    } else if (a->category > b->category) {
                        state->entries[j] = b;
                        state->entries[j + 1] = a;
                    }
                }
            }
        }
    }
}
