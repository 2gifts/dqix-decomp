#include <globaldefs.h>
#if defined(jpn)
extern "C" void func_020474a8(void*, int, int, char*);
#endif
#include "GameState/GameState.h"

void* GetGlobalField0x1c020421a0();
extern "C" void func_02046380(void* global);
struct StoreStruct;
void StoreInArray0x8b0_020465c0(struct StoreStruct* base, int index, int value);
void SetByteInRange_020465f0(unsigned char* base, int index, unsigned char value);
struct Obj02046574;
void SetIndexedName02046574(struct Obj02046574* obj, int index, char* name);
struct Container020e0310;
int GetFieldByKey020e0434(struct Container020e0310* container, int key);
extern "C" void func_02046608(void* global, int mode, int fmt, char* dst, int size, int a5, int a6);
int AppendString02042058(char* dst, const char* src);

struct PartyData0216abd8 {
    char pad0[0xf68];
    int amount;
};

struct TextBuf0216abd8 {
    char pad0[0x600];
    char text[0x100];
};

struct Obj0216abd8 {
    char pad0[0x64];
    char messages[0x18];
    struct TextBuf0216abd8* buf;
};

// USA: func_ov003_0216abd8
extern "C" ARM void func_ov003_0216abd8(struct Obj0216abd8* self, char* out) {
#if defined(jpn)
    const volatile struct Obj0216abd8* self_v = self;
#else
    struct Obj0216abd8* self_v = self;
#endif
    if (out == NULL) {
        return;
    }
    GameState* gameState = GameState::GetInstance();
    void* global = GetGlobalField0x1c020421a0();
    struct PartyData0216abd8* party = (struct PartyData0216abd8*)GetPtrField0x2a04_02010828(gameState);
    struct TextBuf0216abd8* buf = self_v->buf;
    func_02046380(global);
    if (party->amount != 0) {
        StoreInArray0x8b0_020465c0((struct StoreStruct*)global, 0, party->amount);
        SetByteInRange_020465f0((unsigned char*)global, 0, 0);
        int fmt = GetFieldByKey020e0434((struct Container020e0310*)self_v->messages, 0x443);
#if defined(jpn)
        func_020474a8(global, 0xc, fmt, buf->text);
#else
#if defined(jpn)
        func_020474a8(global, 0xc, fmt, buf->text);
#else
        func_02046608(global, 0xc, fmt, buf->text, 0xe3, 0, 1);
#endif
#endif
        AppendString02042058(out, buf->text);
    } else {
        char* name = (char*)gameState->GetProtagonist()->baseStats_;
        SetIndexedName02046574((struct Obj02046574*)global, 0, name);
        int fmt = GetFieldByKey020e0434((struct Container020e0310*)self_v->messages, 0x442);
#if defined(jpn)
        func_020474a8(global, 0xc, fmt, buf->text);
#else
#if defined(jpn)
        func_020474a8(global, 0xc, fmt, buf->text);
#else
        func_02046608(global, 0xc, fmt, buf->text, 0xe3, 0, 1);
#endif
#endif
        AppendString02042058(out, buf->text);
    }
}
