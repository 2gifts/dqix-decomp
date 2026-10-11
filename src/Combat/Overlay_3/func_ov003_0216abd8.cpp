#include <globaldefs.h>
#if defined(jpn)
extern "C" void func_020474a8(void*, int, int, char*);
#endif
#include "GameState/GameState.h"

extern "C" void* _Z26GetGlobalField0x1c020421a0v();
extern "C" void func_02046380(void* global);
struct StoreStruct;
void StoreInArray0x8b0(struct StoreStruct* base, int index, int value);
void SetByteInRange(unsigned char* base, int index, unsigned char value);
struct Obj02046574;
extern "C" void _Z22SetIndexedName02046574P11Obj02046574iPc(struct Obj02046574* obj, int index, char* name);
struct Container020e0310;
extern "C" int _Z21GetFieldByKey020e0434P17Container020e0310i(struct Container020e0310* container, int key);
extern "C" void func_02046608(void* global, int mode, int fmt, char* dst, int size, int a5, int a6);
extern "C" int _Z20AppendString02042058PcPKc(char* dst, const char* src);

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

// JPN: func_ov003_0216a7ac
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
    void* global = _Z26GetGlobalField0x1c020421a0v();
    struct PartyData0216abd8* party = (struct PartyData0216abd8*)GetPtrField0x2a04(gameState);
    struct TextBuf0216abd8* buf = self_v->buf;
    func_02046380(global);
    if (party->amount != 0) {
        StoreInArray0x8b0((struct StoreStruct*)global, 0, party->amount);
        SetByteInRange((unsigned char*)global, 0, 0);
        int fmt = _Z21GetFieldByKey020e0434P17Container020e0310i((struct Container020e0310*)self_v->messages, 0x443);
#if defined(jpn)
        func_020474a8(global, 0xc, fmt, buf->text);
#else
#if defined(jpn)
        func_020474a8(global, 0xc, fmt, buf->text);
#else
        func_02046608(global, 0xc, fmt, buf->text, 0xe3, 0, 1);
#endif
#endif
        _Z20AppendString02042058PcPKc(out, buf->text);
    } else {
        char* name = (char*)gameState->GetProtagonist()->baseStats_;
        _Z22SetIndexedName02046574P11Obj02046574iPc((struct Obj02046574*)global, 0, name);
        int fmt = _Z21GetFieldByKey020e0434P17Container020e0310i((struct Container020e0310*)self_v->messages, 0x442);
#if defined(jpn)
        func_020474a8(global, 0xc, fmt, buf->text);
#else
#if defined(jpn)
        func_020474a8(global, 0xc, fmt, buf->text);
#else
        func_02046608(global, 0xc, fmt, buf->text, 0xe3, 0, 1);
#endif
#endif
        _Z20AppendString02042058PcPKc(out, buf->text);
    }
}
