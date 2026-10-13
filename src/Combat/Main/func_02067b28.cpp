#include <globaldefs.h>
#include <std_library_functions.h>

struct Entry0204254c {
    int value;
    char pad_04;
    signed char length : 6;
    signed char flags : 2;
    char pad_06[2];
};
struct Container02045c00;
struct TextContext02067b28 {
    char pad_00[0x4c];
    unsigned short* output;
    char* input;
    void* field_54;
    void* field_58;
    char pad_5c[0x10];
    unsigned int outputCursor;
    unsigned int outputLimit;
    char pad_74[8];
    unsigned int inputCursor;
    char pad_80[0x8b4];
    short wrapX, wrapY;
    char pad_938[0x7c];
    unsigned int entryCursor;
    char pad_9b8[0xe00];
    unsigned char usage[0x80];
    char pad_1838[0x4a];
    unsigned short ring[64];
    char pad_1902[0x40];
    unsigned short ringIndex;
    short positionX;
    short available;
    char pad_1948[0x7a];
    unsigned char wrapped;
    unsigned char wrapPending;
    unsigned char canWrap;
    char pad_19c5[0x17];
    unsigned char table;
};
int IsHighByteFF02044494(void*, void*);
int Dispatch02044420(void*, void*);
Entry0204254c* FindEntryByKey0204254c(int, int);
int FindEntryIndexByKey020424e4(int, int);
int FindMatchingEntryIndex(Container02045c00*, int);
extern "C" int func_020459b8(TextContext02067b28*, unsigned char, Entry0204254c*, unsigned char);
extern "C" int func_02001aec(const void*, const void*, int);
extern char data_020f08dc[3];

// USA: func_02067b28
extern "C" ARM void func_02067b28(TextContext02067b28* state) {
    if (!state->field_54 || !state->field_58) return;
    if (state->outputLimit <= state->outputCursor) return;
    while (state->outputCursor < state->outputLimit) {
        char* source = state->input + state->inputCursor;
        unsigned short* destination = state->output + state->outputCursor;
        unsigned short token;
        memcpy(&token, source, 2);
        if (IsHighByteFF02044494(state, &token)) {
            *destination = token;
            state->inputCursor += 2;
            ++state->outputCursor;
            int length = Dispatch02044420(state, &token);
            memcpy(destination + 1, source + 2, length * 2);
            state->inputCursor += length * 2;
            state->outputCursor += length;
            continue;
        }
        if (!state->wrapped) {
            state->canWrap = 1;
            if (state->available <= 0) state->canWrap = 0;
            if (!func_02001aec(source, data_020f08dc, 2)) {
                if (state->ringIndex == 0) state->canWrap = 0;
                else {
                    state->wrapX = state->positionX + 18 + (short)(8 - (state->positionX & 7));
                    state->wrapY = 22;
                    state->wrapped = 1;
                }
                state->wrapPending = 1;
            }
        }
        Entry0204254c* entry = FindEntryByKey0204254c((int)source, state->table);
        int tableIndex = FindEntryIndexByKey020424e4((int)source, state->table);
        if (entry && tableIndex >= 0) {
            int index = FindMatchingEntryIndex((Container02045c00*)state, (int)entry);
            state->inputCursor += entry->length;
            if (index < 0) {
                unsigned short inserted = func_020459b8(state, (unsigned char)tableIndex, entry, state->table);
                if (!state->wrapped) state->ring[state->ringIndex] = inserted;
                *destination = inserted;
                ++state->outputCursor;
                state->entryCursor = (state->entryCursor + 1) & 0x7f;
                break;
            }
            unsigned short selected = index;
            if (!state->wrapped) {
                state->ring[state->ringIndex] = selected;
                ++state->ringIndex;
                state->ringIndex &= 0x3f;
            }
            *destination = selected;
            if (state->usage[selected] < 255) ++state->usage[selected];
        } else {
            signed char character = *source;
            if (!state->wrapped && character == 32) {
                state->ring[state->ringIndex] = 0xff19;
                ++state->ringIndex;
                state->ringIndex &= 0x3f;
            }
            *destination = 0xff19;
            ++state->inputCursor;
        }
        ++state->outputCursor;
    }
    if (!state->wrapped) {
        ++state->ringIndex;
        state->ringIndex &= 0x3f;
    }
}
