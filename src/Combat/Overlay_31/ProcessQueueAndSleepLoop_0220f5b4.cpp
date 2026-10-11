#include <globaldefs.h>
#include "System/ProcessorContext.h"

extern void* data_ov031_0224e580;

void PopQueueEntryAndClear_0220f68c(void);
extern "C" void func_ov031_0220f6e0(void);
int HandleState2AndRelease_02210250(void);

extern "C" void func_ov031_0220f728(void);
extern "C" void func_ov031_0220f814(void);
extern "C" void func_ov031_0220f8a8(void);
extern "C" void func_ov031_0220faac(void);
extern "C" void func_ov031_0220fa1c(void);
extern "C" void func_ov031_0220fb28(void);
extern "C" void func_ov031_0220fbd4(void);
extern "C" void func_ov031_0220fc80(void);
extern "C" void func_ov031_0220fcfc(void);

// USA: func_ov031_0220f5b4  (semantic: ProcessQueueAndSleepLoop_0220f5b4)
extern "C" ARM void func_ov031_0220f5b4(void) {
    if (data_ov031_0224e580 == NULL) return;
    for (;;) {
        PopQueueEntryAndClear_0220f68c();
        void* entry = *(void**)((char*)data_ov031_0224e580 + 0x24);
        if (entry == NULL) {
            func_ov031_0220f6e0();
            break;
        }
        int state = *(int*)entry;
        switch (state) {
        case 1: func_ov031_0220f728(); break;
        case 2: func_ov031_0220f814(); break;
        case 3: func_ov031_0220f8a8(); break;
        case 4: func_ov031_0220faac(); break;
        case 5: func_ov031_0220fa1c(); break;
        case 6: func_ov031_0220fb28(); break;
        case 7: func_ov031_0220fbd4(); break;
        case 8: func_ov031_0220fc80(); break;
        case 9: func_ov031_0220fcfc(); break;
        }
        func_ov031_0220f6e0();
    }
    while (HandleState2AndRelease_02210250() == 0) {
        SleepCurrentContext(100);
    }
}
