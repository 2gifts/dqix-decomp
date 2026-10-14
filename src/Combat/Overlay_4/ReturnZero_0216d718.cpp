#include <globaldefs.h>
#if defined(jpn)
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
extern "C" void* memset(void*, int, unsigned int);
extern "C" void* memcpy(void*, const void*, unsigned int);
extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, int);
extern "C" int func_ov023_021f6f10(void*);
extern "C" void func_ov023_021fa598(void*);
extern "C" void* _Z26GetGlobalField0x1c020421a0v();
extern "C" void _Z22SetByte0x7f70_02012028Pvh(void*, unsigned char);
extern "C" void* func_ov011_021845f8(void*, int);
extern "C" int _Z23VariadicForward020c7170iiiz(char*, int, const char*, ...);
extern const char data_ov004_02170fac[];
struct MethodRecord0216dcc8 { char pad[0x20]; char* text; };
struct SavedNumber0216dcc8 { char pad[0x48]; unsigned long long number; };
static inline char* GetSection120(GameState* state) { return (char*)state + 0x120; }
static inline SavedNumber0216dcc8* GetSection6000(char* section) { return (SavedNumber0216dcc8*)(section + 0x6000); }
extern "C" ARM int func_ov004_0216d718(void* self)
{
    void* entry = func_ov023_021f6880(func_ov011_021849c8(self), 0x192);
    if (entry != 0 && func_ov023_021f6f10(entry) == 4)
        func_ov023_021fa598(entry);
    _Z26GetGlobalField0x1c020421a0v();
    GameState* state = GameState::GetInstance();
    _Z22SetByte0x7f70_02012028Pvh(state, 0);
    SafeAllocator* allocator = (SafeAllocator*)((char*)func_ov011_021845f8(self, 5) + 4);
    char* buffer = (char*)allocator->Allocate(0x400);
    memset(buffer, 0, 0x400);
    MethodRecord0216dcc8* record = (MethodRecord0216dcc8*)func_ov023_021f6880(func_ov011_021849c8(self), 0x4f);
    if (record == 0 || func_ov023_021f6f10(record) != 8)
        record = 0;
    if (record != 0) {
        char number[13];
        _Z23VariadicForward020c7170iiiz(number, 13, data_ov004_02170fac, GetSection6000(GetSection120(state))->number);
        char* in = number;
        char* out = buffer;
        for (int i = 0; i < 3; i++) {
            memcpy(out, in, 4);
            out += 4;
            in += 4;
            if (i != 2)
                *out++ = '-';
        }
        record->text = buffer;
    }
    return 0;
}
#else

// USA: func_ov004_0216d718  (semantic: ReturnZero_0216d718)
extern "C" ARM int func_ov004_0216d718(void) {
    return 0;
}

#endif
