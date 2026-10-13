#include <globaldefs.h>
#include "Resource/MessageSystem.h"

struct Container020e0310;
int GetGlobalField0x1c020421a0();
int GetFieldByKey020e0434(Container020e0310* container, int key);

// KEEP-NAME
// USA: func_ov013_02185774
ARM void SetupBattleMessage02185774(void* obj) {
    unsigned char* menu = (unsigned char*)obj;
    MessageSystem* messages = (MessageSystem*)GetGlobalField0x1c020421a0();
#if defined(jpn)
    unsigned char mode = menu[0x5c8];
    if (mode == 4) {
        func_0204500c(messages, (const char*)GetFieldByKey020e0434((Container020e0310*)(menu + 0x5ac), 1000), 0);
    } else if (mode == 3) {
        func_0204500c(messages, (const char*)GetFieldByKey020e0434((Container020e0310*)(menu + 0x5ac), 1001), 0);
    } else if (mode == 2) {
        func_0204500c(messages, (const char*)GetFieldByKey020e0434((Container020e0310*)(menu + 0x5ac), 1002), 0);
    }
    messages->b19b2 = 0;
    *(int*)((char*)messages + 0x868) = 1;
#else
    unsigned char mode = menu[0x63c];
    if (mode == 4) {
        func_0204500c(messages, (const char*)GetFieldByKey020e0434((Container020e0310*)(menu + 0x620), 1000), 0, (void*)0xe3);
    } else if (mode == 3) {
        func_0204500c(messages, (const char*)GetFieldByKey020e0434((Container020e0310*)(menu + 0x620), 1001), 0, (void*)0xe3);
    } else if (mode == 2) {
        func_0204500c(messages, (const char*)GetFieldByKey020e0434((Container020e0310*)(menu + 0x620), 1002), 0, (void*)0xe3);
    }
    messages->b19b2 = 0;
    *(int*)((char*)messages + 0x998) = 1;
#endif
}
