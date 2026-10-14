#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"

struct Struct02030b7c;
extern "C" void func_ov000_02169b78(void* node);
extern int data_ov000_02184264;

struct Event0216ad0c {
    int tag;
    int unused;
    char* str;
};

// USA: func_ov000_0216ad0c
ARM int BuildStringEventWithTag_0216ad0c(struct Struct02030b7c* arg) {
    Event0216ad0c* node = (Event0216ad0c*)(*(SafeAllocator**)((char*)&data_ov000_02184264 + 0x8))->Allocate(0xc);
    node->tag = 0;
    node->unused = 0;
    node->tag = 0x22;
    char* str = (char*)(void*)((Script::Parameter*)arg)->ToString();
    char* buf = (char*)(*(SafeAllocator**)((char*)&data_ov000_02184264 + 0x8))->Allocate(strlen(str) + 1);
    node->str = buf;
    strcpy(buf, str);
    func_ov000_02169b78(node);
    return 1;
}
