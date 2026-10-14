#include <globaldefs.h>
#if defined(jpn)
enum { kRegion998 = 0x868 };
enum { kRegione4 = 0xe0 };
enum { kRegion4e8 = 0x4e4 };
enum { kRegion4ec = 0x4e8 };
enum { kRegion4e9 = 0x4e5 };
enum { kRegion4ed = 0x4e9 };
enum { kRegion5a4 = 0x5a0 };
enum { kRegion960 = 0x800 };
#else
enum { kRegion998 = 0x998 };
enum { kRegione4 = 0xe4 };
enum { kRegion4e8 = 0x4e8 };
enum { kRegion4ec = 0x4ec };
enum { kRegion4e9 = 0x4e9 };
enum { kRegion4ed = 0x4ed };
enum { kRegion5a4 = 0x5a4 };
enum { kRegion960 = 0x960 };
#endif
#include "std_library_functions.h"
#include "GameState/GameState.h"

struct MessageWork02168b50 {
    char pad0[kRegion998];
    int field_0x998;
    int field_0x99c;
    int state;
};

struct DataEntry02108d18 {
    char pad0[0x10];
    char title[0x20];
};

struct BattleData02168b50 {
    char pad0[0xf68];
    int field_0xf68;
};

struct Container020e0310;
struct Obj02046574;
struct StoreStruct;
struct Struct_0205d81c;

struct BattleMenu02168b50 {
    char pad0[0x64];
    char messages[0x7c - 0x64];
    char* text;
    char pad80[kRegione4 - 0x80];
    char menu[kRegion4e8 - kRegione4];
    unsigned char step;
    char pad4e9[kRegion4ec - kRegion4e9];
    unsigned char mode;
    char pad4ed[kRegion5a4 - kRegion4ed];
    unsigned char busy;
};

struct MessageWork02168b50* GetGlobalField0x1c020421a0();
struct DataEntry02108d18* GetData02108d18();
int AppendFormatted02041fe8(char* buf, int a);
int GetFieldByKey020e0434(struct Container020e0310* c, int key);
int AppendString02042058(char* dst, const char* src);
extern "C" void func_02046380(void* obj);
void SetIndexedName02046574(struct Obj02046574* obj, int index, char* str);
void StoreInArray0x8b0(struct StoreStruct* base, int index, int value);
void SetByteInRange(unsigned char* base, int index, unsigned char value);

#if defined(jpn)
extern "C" void func_0204500c(void*, char*, int);
#endif
#if !defined(jpn)
extern "C" void func_0204500c(void* obj, char* buffer, int a, int b);
#endif
extern "C" void func_ov003_0216982c(struct BattleMenu02168b50* self);
extern "C" void func_ov003_0216997c(struct BattleMenu02168b50* self);
void SetElementFieldC2(struct Struct_0205d81c* s, int key, int value);

// USA: func_ov003_02168b50
extern "C" ARM void func_ov003_02168b50(struct BattleMenu02168b50* self) {
    struct MessageWork02168b50* work = GetGlobalField0x1c020421a0();
    struct Container020e0310* messages = (struct Container020e0310*)self->messages;
    if (self->step == 0) {
        memset(self->text, 0, kRegion960);
        struct DataEntry02108d18* data = GetData02108d18();
        if (data->title[0] != 0) {
            AppendFormatted02041fe8(self->text, (int)data->title);
        }
        AppendString02042058(self->text, (const char*)GetFieldByKey020e0434(messages, 0x3e8));
        GameState* game = GameState::GetInstance();
        struct BattleData02168b50* battle = (struct BattleData02168b50*)GetPtrField0x2a04(game);
        func_02046380(work);
        SetIndexedName02046574((struct Obj02046574*)work, 0, (char*)game->GetProtagonist()->baseStats_);
        if (battle->field_0xf68 != 0) {
            StoreInArray0x8b0((struct StoreStruct*)work, 0, battle->field_0xf68);
            SetByteInRange((unsigned char*)work, 0, 0);
            AppendString02042058(self->text, (const char*)GetFieldByKey020e0434(messages, 0x3ea));
        } else {
            AppendString02042058(self->text, (const char*)GetFieldByKey020e0434(messages, 0x3e9));
        }
        work->field_0x998 = 1;
#if defined(jpn)
        func_0204500c(work, self->text, 0);
#else
        func_0204500c(work, self->text, 0, 0xe3);
#endif
        work->field_0x99c = 2;
        self->step++;
    } else if (self->step == 1 && self->busy == 0 && work->state == 3) {
        func_ov003_0216982c(self);
        func_ov003_0216997c(self);
        SetElementFieldC2((struct Struct_0205d81c*)self->menu, 0, 0);
        self->mode = 2;
        self->step = 0;
    }
}
