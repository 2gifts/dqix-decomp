#include <globaldefs.h>

struct CombatEvent {
    short* entryList;
    char unknown4[0x3c - 4];
};
struct CombatEventContext {
    char unknown0[0x540];
    CombatEvent event;
};
struct CombatEventGlobals {
#if defined(jpn)
    char unknown0[4];
#else
    char unknown0[0xc];
#endif
    CombatEventContext* context;
};
extern CombatEventGlobals data_ov025_021ef988;
extern "C" void func_ov025_021e2f54(CombatEvent*, short*, char*);
extern "C" void func_ov025_021e3084(CombatEvent*);

// USA: func_ov025_021e3048
extern "C" ARM int func_ov025_021e3048(void*, short* entryList, void*, char* world) {
    CombatEventContext* context = data_ov025_021ef988.context;
    func_ov025_021e3084(&context->event);
    context->event.entryList = entryList;
    func_ov025_021e2f54(&context->event, entryList, world);
    return 1;
}
