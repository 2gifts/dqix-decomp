#include <globaldefs.h>

#if defined(jpn)
enum { kGlobalHolderInnerOffset = 0x4 };
#else
enum { kGlobalHolderInnerOffset = 0xc };
#endif


#if defined(jpn)
#define data_ov025_021ef7ef data_ov025_021efacf
#endif


#if defined(jpn)
#define FormatAndDispatch_021e40e4 func_ov025_021e45d4
#endif
#include "Filesystem/BackgroundLoader.h"
#include "std_library_functions.h"

struct Ctx021e40e4 { char pad[kGlobalHolderInnerOffset]; void* target; };
extern struct Ctx021e40e4 data_ov025_021ef988;
extern char data_ov025_021ef7ef;

void* GetArrayEntry_021e8a54_021e8a54(char* obj);
extern "C" int func_ov025_021e25a4(char* buf);
extern "C" void func_ov025_021eb05c(void* ctx, int val);

// USA: func_ov025_021e40e4
#if defined(jpn)
extern "C"
#endif
ARM int FormatAndDispatch_021e40e4(unsigned char* obj) {
    char buf[0x50];
    (int)BackgroundLoader::GetInstance();
    GetArrayEntry_021e8a54_021e8a54((char*)data_ov025_021ef988.target);
    int v = *(int*)(obj + 8);
    sprintf(buf, &data_ov025_021ef7ef, v);
    int r = func_ov025_021e25a4(buf);
    func_ov025_021eb05c(data_ov025_021ef988.target, r);
    return 1;
}
