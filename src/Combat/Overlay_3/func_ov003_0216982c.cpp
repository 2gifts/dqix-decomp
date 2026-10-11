#include <globaldefs.h>
#if defined(jpn)
enum { kRegion960 = 0x800 };
enum { kRows = 4 };
enum { kRegione4 = 0xe0 };
enum { kRegion84 = 0x80 };
enum { kRegion86 = 0x82 };
enum { kRegion88 = 0x84 };
enum { kRegion8a = 0x86 };
enum { kRegion8c = 0x88 };
enum { kRegion8e = 0x8a };
enum { kRegion90 = 0x8c };
enum { kRegion92 = 0x8e };
enum { kRegion195 = 0x191 };
enum { kRegion199 = 0x195 };
#else
enum { kRegion960 = 0x960 };
enum { kRows = 2 };
enum { kRegione4 = 0xe4 };
enum { kRegion84 = 0x84 };
enum { kRegion86 = 0x86 };
enum { kRegion88 = 0x88 };
enum { kRegion8a = 0x8a };
enum { kRegion8c = 0x8c };
enum { kRegion8e = 0x8e };
enum { kRegion90 = 0x90 };
enum { kRegion92 = 0x92 };
enum { kRegion195 = 0x195 };
enum { kRegion199 = 0x199 };
#endif

#if defined(jpn)
extern "C" void func_02042428(void*, int);
extern "C" void func_0205d304(void*, void*, int, int, int, int, int);
struct Container020e0310;
int GetFieldByKey020e0434(Container020e0310*, int);
#endif
#include "std_library_functions.h"
#include "GameState/GameState.h"

struct Struct0205de24;
void FindAndLinkMatchingEntry0205de24(struct Struct0205de24* obj, unsigned char keyLow, unsigned char keyHigh);

int GetGlobalField0x1c020421a0();
extern "C" void func_02046380(void* obj);
int CallFunc020e0434With02153694(int value);
int AppendString02042058(char* dst, const char* src);

struct StoreStruct;
void StoreInArray0x8b0(struct StoreStruct* base, int index, int value);
void SetByteInRange(unsigned char* base, int index, unsigned char value);
void SetByteAtIndex(unsigned char* base, int index, unsigned char value);

#if !defined(jpn)
extern "C" void func_0205d304(void* a, void* b, int c, int d, int e, int f, int g, int h);
#endif

// JPN: func_ov003_02169654
// USA: func_ov003_0216982c
extern "C" ARM void func_ov003_0216982c(unsigned char* self) {
    GameState* battle = GameState::GetInstance();
    int field = GetGlobalField0x1c020421a0();
    void* ptr = GetPtrField0x2a04(battle);

    FindAndLinkMatchingEntry0205de24((struct Struct0205de24*)(self + kRegione4), 0, 2);

    *(short*)(self + 0x100 + kRegion84) = 0xb;
    *(short*)(self + 0x100 + kRegion86) = 2;
    *(short*)(self + 0x100 + kRegion88) = 0x14;
    *(short*)(self + 0x100 + kRegion8a) = 0;
    *(short*)(self + 0x100 + kRegion8c) = 0x10;
    *(short*)(self + 0x100 + kRegion8e) = kRows;
    *(short*)(self + 0x100 + kRegion90) = 0xa;
    *(short*)(self + 0x100 + kRegion92) = 0xe;
    self[kRegion195] = 0;
    self[kRegion199] = 1;

    memset(*(void**)(self + 0x7c), 0, kRegion960);

#if defined(jpn)
    func_02042428(*(void**)(self + 0x7c), 8);
    int msg = GetFieldByKey020e0434((Container020e0310*)(self + 0x64), 0x65);
    AppendString02042058((char*)*(void**)(self + 0x7c), (const char*)msg);
#else
    int msg = CallFunc020e0434With02153694(0x3f1);
    AppendString02042058((char*)*(void**)(self + 0x7c), (const char*)msg);
#endif

    func_02046380((void*)field);

    int value = *(int*)((char*)ptr + 0xf6c);
    StoreInArray0x8b0((struct StoreStruct*)field, 0, value);
    SetByteInRange((unsigned char*)field, 0, 7);
    SetByteAtIndex((unsigned char*)field, 0, 1);

#if defined(jpn)
    func_0205d304(self + kRegione4, *(void**)(self + 0x7c), 0, 0, 0, 1, 0);
#else
    func_0205d304(self + kRegione4, *(void**)(self + 0x7c), 0, 0, 0, 1, 0, 0);
#endif
}
