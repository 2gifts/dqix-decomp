#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "std_library_functions.h"
#include "GameState/GameState.h"

#if defined(jpn)
struct Ctx021e8344 { char pad[4]; void* target; };
#else
struct Ctx021e8344 { char pad[0xc]; void* target; };
#endif
extern struct Ctx021e8344 data_ov025_021ef988;
extern char data_ov025_021ef87f;

void* GetArrayEntry_021e8a54_021e8a54(char* obj);
extern "C" int func_ov025_021e25a4(char* buf);
extern "C" void func_ov025_021eb05c(void* ctx, int val);

struct Param021e8344 { char pad[0x10]; void* field0x10; };
struct Inner021e8344 { char pad[0x49c]; unsigned char flag : 1; };

// JPN: func_ov025_021e87e4
// USA: func_ov025_021e8344  (semantic: FormatGenderTagAndDispatch_021e8344)
extern "C" ARM int func_ov025_021e8344(void* unused0, struct Param021e8344* ctx) {
#if defined(jpn)
 enum {regionalOffset0=0x144};
#else
 enum {regionalOffset0=0x150};
#endif
    char buf[0x50];
    (int)BackgroundLoader::GetInstance();
    GetArrayEntry_021e8a54_021e8a54((char*)data_ov025_021ef988.target);
    GameState* bs = GameState::GetInstance();
    int id = *(unsigned short*)((char*)ctx->field0x10 + 0x20);
    GameObject* c = GetCombatantWithFlag0x100(bs, id);
    struct Inner021e8344* c2 = *(struct Inner021e8344**)((char*)c + regionalOffset0);
    char ch = 'm';
    if (c2->flag == 1) {
        ch = 'w';
    }
    sprintf(buf, &data_ov025_021ef87f, ch);
    int r = func_ov025_021e25a4(buf);
    func_ov025_021eb05c(data_ov025_021ef988.target, r);
    return 1;
}
