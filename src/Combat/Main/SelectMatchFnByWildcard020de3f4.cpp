#include <globaldefs.h>

struct NibbleStruct;
int IsField8NibbleInRange_020de34c(struct NibbleStruct* s, int lo, int hi);

struct Field8Bits4To8;
int IsField8Bits4To8Equal_020de334(struct Field8Bits4To8* obj, int a1, int a2, int value);

struct Field8Bits0To3;
int IsField8Bits0To3Equal_020de31c(struct Field8Bits0To3* obj, int value);

struct BitPair020de36c;
int MatchBits0To3And4To8At0x8(struct BitPair020de36c* obj, int a, int unused, int b);

// USA: func_020de3f4
#pragma optimize_for_size off
ARM void SelectMatchFnByWildcard020de3f4(int a, int b, int c, int d, char* outA, char* outB, char* outC, void** outFunc) {
    *outA = (char)c;
    *outB = (char)-1;
    *outC = (char)d;
    *outFunc = 0;

    if (a != 0) {
        switch (b) {
            case 0:
                *outA = 0;
                *outB = 7;
                break;
            case 1:
                *outA = 0;
                break;
            case 2:
                *outA = 1;
                *outB = 6;
                break;
            case 3:
                *outA = 7;
                break;
        }
    } else {
        switch (b) {
            case 0:
                *outA = 8;
                *outB = 9;
                break;
            case 1:
                *outA = 8;
                break;
            case 2:
                *outA = 9;
                break;
        }
    }

    if (*outA == -1) {
        if (*outC == -1) {
            *outFunc = 0;
        } else {
            *outFunc = (void*)&IsField8Bits4To8Equal_020de334;
        }
    } else {
        if (*outC == -1) {
            if (*outB == -1) {
                *outFunc = (void*)&IsField8Bits0To3Equal_020de31c;
            } else {
                *outFunc = (void*)&IsField8NibbleInRange_020de34c;
            }
        } else {
            *outFunc = (void*)&MatchBits0To3And4To8At0x8;
        }
    }
}
