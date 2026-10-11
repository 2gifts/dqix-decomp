#include "GameState/GameState.h"
#include <globaldefs.h>

struct ArrayContainsByteStruct;

void *GetPtrField0x2a04(GameState *gameState);
extern "C" int *func_0202ae18();
int ArrayContainsByte(ArrayContainsByteStruct *arr, int value);
extern "C" int _Z36HasPositiveField256Short178_02154b94Pvi(void *self, int id);
extern "C" int _Z34HasPositiveField304Short4_02154a34Pvi(void *self, int id);
extern "C" void *_Z26LookupElementByKey02079ee0Pvi(void *table, int key);
int CheckField0NonZero(int *p);
extern "C" void func_ov002_02153e90(char *entry);
extern "C" int func_ov002_02154a6c(char *self, int id, int arg);
extern "C" int func_ov002_021538e4(char *self, char *q, void *elem, int arg);
extern "C" int func_ov002_021548c4(char *self, int id, int value, unsigned char *entry);
extern "C" int func_ov002_021549c8(char *self, int id, int value, unsigned char *entry);
extern "C" void func_ov017_021c9e00(int id, int a, int b, int c);

// USA: func_ov002_02154020
extern "C" ARM int func_ov002_02154020(char *self, char *p, char *q) {
    if (p == 0) return 0;
    if (q == 0) return 0;
    ArrayContainsByteStruct *arr = (ArrayContainsByteStruct *) GetPtrField0x2a04(GameState::GetInstance());
    int *x                       = func_0202ae18();
    int result                   = 0;
    char *first                  = p + 8;
    char *second                 = p + 0x20;
    for (int i = 0; i < 4; i++) {
        func_ov002_02153e90(first + i * 6);
        func_ov002_02153e90(second + i * 6);
    }
    for (int j = 0; j < *(unsigned char *) (p + 3); j++) {
        unsigned char *e = (unsigned char *) (first + j * 6);
        unsigned char *f = (unsigned char *) (second + j * 6);
        int id           = *(signed char *) (p + 4 + j);
        if (!ArrayContainsByte(arr, id)) {
            e[4] = 1;
            f[4] = 1;
        }
        if (!func_ov002_02154a6c(self, id, *(signed char *) (p + 2))) {
            e[0] = 1;
            continue;
        }
        if (_Z36HasPositiveField256Short178_02154b94Pvi(self, id)) {
            e[0] = 2;
            continue;
        }
        if (!_Z34HasPositiveField304Short4_02154a34Pvi(self, id)) continue;
        void *elem = _Z26LookupElementByKey02079ee0Pvi(*(void **) self, (*(unsigned int *) (q + 8) << 10) >> 24);
        if (elem == 0) continue;
        int v = func_ov002_021538e4(self, q, elem, *(signed char *) (p + 2));
        if (e[4]) {
            *(short *) (e + 2) = v;
            e[0]               = 3;
        } else {
            *(short *) (e + 2) = func_ov002_021548c4(self, id, v, e);
        }
        if (f[4]) {
            *(short *) (f + 2) = 1;
            f[0]               = 3;
        } else {
            *(short *) (f + 2) = func_ov002_021549c8(self, id, 2, f);
        }
        if (e[0] == 0 && f[0] == 0) continue;
        if (CheckField0NonZero(x) && ArrayContainsByte(arr, id)) {
            func_ov017_021c9e00(id, 0, 0, 1);
        }
        result = 1;
    }
    return result;
}
