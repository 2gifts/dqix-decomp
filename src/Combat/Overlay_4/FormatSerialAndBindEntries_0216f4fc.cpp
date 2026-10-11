#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"

#if defined(jpn)
enum { serialBase = 0x120, serialPage = 0x6000 };
#else
enum { serialBase = 0x2380, serialPage = 0x4000 };
#endif

extern "C" void func_ov004_0216ea38(void* ctx, int mode);
int GetGlobalField0x1c020421a0(void);
extern "C" void* func_ov011_021849c8(void* ctx);
extern "C" void* func_ov023_021f6880(void* list, int id);
extern "C" int func_ov023_021f6f10(void* node);
extern "C" void func_ov023_021f809c(void* node, void* ctx);
int VariadicForward020c7170(int a, int b, int c, ...);

extern int data_ov004_021707b0;
struct Struct02171048_0216f4fc { char pad[4]; char* ptr; };
extern Struct02171048_0216f4fc data_ov004_02171048;

// USA: func_ov004_0216f4fc  (semantic: FormatSerialAndBindEntries_0216f4fc)
extern "C" ARM int func_ov004_0216f4fc(void* ctx) {
    char buf[0x10];
    GameState* battle = GameState::GetInstance();
    char* dst;
    char* src;
    int k;
    void* code;
    void* entry;

    func_ov004_0216ea38(ctx, 4);
    GetGlobalField0x1c020421a0();

    code = func_ov023_021f6880(func_ov011_021849c8(ctx), 0x65);
    if (code == NULL || func_ov023_021f6f10(code) != 8) code = NULL;
    if (code != NULL) {
        char* p = (char*)battle + serialBase;
        p += serialPage;
        VariadicForward020c7170((int)buf, 0xd, (int)&data_ov004_021707b0, *(long long*)(p + 0x48));

        // Rewrite the formatted digits as three dash-separated groups of four.
        dst = data_ov004_02171048.ptr + 0xe;
        src = buf;
        for (k = 0; k < 3; k++) {
            memcpy(dst, src, 4);
            dst += 4;
            src += 4;
            if (k != 2) *dst++ = '-';
        }
        *(char**)((char*)code + 0x20) = data_ov004_02171048.ptr + 0xe;
    }

    entry = func_ov023_021f6880(func_ov011_021849c8(ctx), 0x14);
    if (entry == NULL || func_ov023_021f6f10(entry) != 6) entry = NULL;
    if (entry != NULL) func_ov023_021f809c(entry, ctx);
    return 0;
}
