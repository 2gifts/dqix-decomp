#include <globaldefs.h>
#if defined(jpn)
enum { kTextSize=0x800 };
extern "C" void func_02042428(char*, int);
extern "C" void func_02042158(char*, int);
extern char data_ov003_0217e68e[];
extern char data_ov003_0217e696[];
#else
enum { kTextSize=0x960 };
#endif
#include "std_library_functions.h"
#include "GameState/GameState.h"

struct TouchState02114e54 {
    char pad0[0x24];
    unsigned short pressed;
    char pad26[0x5f - 0x26];
    unsigned char active;
};

struct CursorList0215c0ec {
    int count;
    char pad4[0x30 - 0x4];
    int selected;
};

struct BattleData0215c0ec {
    char pad0[0xf6c];
    int field_0xf6c;
};

struct BattleMenu0215c0ec {
    char pad0[0x7c];
    char* text;
    char pad80[0xf4 - 0x80];
    char menu[0x1a4 - 0xf4];
    unsigned char mode;
    char pad1a5[0x582 - 0x1a5];
    unsigned char state;
    unsigned char refresh;
};

struct StructA0205d5d0;
struct StoreStruct;

extern struct TouchState02114e54 data_02114e54;

#if defined(jpn)
extern "C" int _Z26TryApplyElemFields0205d5d0P15StructA0205d5d0iiih(struct StructA0205d5d0*, int, int, int);
#else
int TryApplyElemFields0205d5d0(struct StructA0205d5d0* a, int b, int c, int d, unsigned char e);
#endif
extern "C" void func_ov003_0215b6f0(struct BattleMenu0215c0ec* self, char* dst, int flag);
extern "C" void func_ov003_0215b964(struct BattleMenu0215c0ec* self, char* dst, int flag);
extern "C" void func_ov003_0215be70(struct BattleMenu0215c0ec* self, char* dst, int flag);
int GetGlobalField0x1c020421a0();
extern "C" void func_02046380(void* obj);
int CallFunc020e0434With02153694(int value);
int AppendString02042058(char* dst, const char* src);
void StoreInArray0x8b0(struct StoreStruct* base, int index, int value);
void SetByteInRange(unsigned char* base, int index, unsigned char value);
void SetByteAtIndex(unsigned char* base, int index, unsigned char value);

// JPN: func_ov003_0215d3f4
// USA: func_ov003_0215c0ec
extern "C" ARM void func_ov003_0215c0ec(struct BattleMenu0215c0ec* self) {
    if (self->state != 0) {
        int flag = 0;
        if (self->state == 2 && data_02114e54.active != 0 && data_02114e54.pressed != 0) {
            struct CursorList0215c0ec* list = (struct CursorList0215c0ec*)((char*)self->menu + 4);
            if (!flag && list->selected < 0) {
                return;
            }
            flag = 1;
        }
        memset(self->text, 0, kTextSize);
        unsigned char mode = self->mode;
        switch (mode) {
        case 1:
            func_ov003_0215b6f0(self, self->text, flag);
            break;
        case 2:
            func_ov003_0215b964(self, self->text, flag);
            break;
        case 3:
            func_ov003_0215be70(self, self->text, flag);
            break;
        }
#if defined(jpn)
        _Z26TryApplyElemFields0205d5d0P15StructA0205d5d0iiih((struct StructA0205d5d0*)self->menu, mode, (int)self->text, 1);
#else
        TryApplyElemFields0205d5d0((struct StructA0205d5d0*)self->menu, mode, (int)self->text, 1, 0);
#endif
    }
    if (self->refresh != 0) {
        GameState* game = GameState::GetInstance();
        int messages = GetGlobalField0x1c020421a0();
        memset(self->text, 0, kTextSize);
#if defined(jpn)
        func_02042428(self->text, 8);
        AppendString02042058(self->text, data_ov003_0217e68e);
        func_02042158(self->text, 2);
        AppendString02042058(self->text, data_ov003_0217e696);
#else
        AppendString02042058(self->text, (const char*)CallFunc020e0434With02153694(0x3f1));
#endif
        func_02046380((void*)messages);
        StoreInArray0x8b0((struct StoreStruct*)messages, 0,
                          ((struct BattleData0215c0ec*)GetPtrField0x2a04(game))->field_0xf6c);
        SetByteInRange((unsigned char*)messages, 0, 7);
        SetByteAtIndex((unsigned char*)messages, 0, 1);
#if defined(jpn)
        _Z26TryApplyElemFields0205d5d0P15StructA0205d5d0iiih((struct StructA0205d5d0*)self->menu, 0, (int)self->text, 1);
#else
        TryApplyElemFields0205d5d0((struct StructA0205d5d0*)self->menu, 0, (int)self->text, 1, 0);
#endif
        self->refresh = 0;
    }
}
