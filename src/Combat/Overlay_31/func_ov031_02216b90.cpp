// JPN: func_ov031_02217370
#include <globaldefs.h>
#include "std_library_functions.h"

struct SysBlock_02216b90 {
    char pad0[0x1004];
    int status;
    char pad1[0x1c4];
    char sub11cc[0x34];
    char sub1200[0xc];
    int f120c;
    int f1210;
    char pad2[0x100];
    void* ctx;
};

struct SysGlobals_02216b90 {
    char pad0[8];
    SysBlock_02216b90* sys;
};

struct Config_02216b90 {
    const char* name;
    char pad0[8];
    int f0c;
    int f10;
    int f14;
};

struct ProcHolder_02216b90 {
    char pad0[4];
    void* proc;
};

extern "C" int _Z18GetContextPriorityP16ProcessorContext(void* proc);
extern "C" int func_ov031_02217c00(void* ctx, Config_02216b90* config);
extern "C" void func_ov031_0221ae00(void* arg);
extern "C" int func_ov031_022173f4(void* ctx, void* a, void* b);
extern "C" int func_ov031_02217d1c(void* ctx);
extern "C" void func_ov031_02217db4(void* ctx, int priority);

extern Config_02216b90 data_ov031_02249b54;
extern Config_02216b90 data_ov031_02249b54;
extern const char data_ov031_02249bb8[];
extern SysGlobals_02216b90 data_ov031_0224e5e8;
extern int data_ov031_0224e5f4;
extern ProcHolder_02216b90 data_02111304;

// USA: func_ov031_02216b90
extern "C" ARM int func_ov031_02216b90(int mode) {
    if (strcmp(data_ov031_02249b54.name, data_ov031_02249bb8) != 0) {
        data_ov031_02249b54.f14 = 1;
    }
    data_ov031_02249b54.f0c = data_ov031_0224e5e8.sys->f120c;
    data_ov031_02249b54.f10 = data_ov031_0224e5e8.sys->f1210;
#if defined(jpn)
    if (func_ov031_02217c00(data_ov031_0224e5e8.sys->ctx, ((__typeof__(&data_ov031_02249b54))0x0224A754)) != 0) {
#else
    if (func_ov031_02217c00(data_ov031_0224e5e8.sys->ctx, ((__typeof__(&data_ov031_02249b54))0x02249B54)) != 0) {
#endif
        return 4;
    }
    if (mode == 1) {
        func_ov031_0221ae00(&data_ov031_0224e5f4);
    }
    data_ov031_0224e5e8.sys->status = func_ov031_022173f4(data_ov031_0224e5e8.sys->ctx,
                                                          data_ov031_0224e5e8.sys->sub1200,
                                                          data_ov031_0224e5e8.sys->sub11cc);
    if (data_ov031_0224e5e8.sys->status != 0) {
        return 4;
    }
    if (func_ov031_02217d1c(data_ov031_0224e5e8.sys->ctx) != 0) {
        return 4;
    }
    func_ov031_02217db4(data_ov031_0224e5e8.sys->ctx,
                        _Z18GetContextPriorityP16ProcessorContext(data_02111304.proc) - 1);
    return 0;
}
