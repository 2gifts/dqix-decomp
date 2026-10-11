#include <globaldefs.h>
#if defined(jpn)
enum { kNameOffset = 0x989 };
enum { kFilenameOffset = 4 };
#else
enum { kNameOffset = 0xa35 };
enum { kFilenameOffset = 8 };
#endif

#include "Filesystem/BackgroundLoader.h"
#include "std_library_functions.h"

extern "C" void* func_02012fe4(void);
extern int data_020ef460;
extern char data_020ef587;
extern char data_020ef58f;

// USA: func_02020b98
ARM int FormatAndCopyNames02020b98(void* r6) {
    char buf[0x20];
    int val5 = (int)BackgroundLoader::GetInstance();
    char* ptr4 = (char*)func_02012fe4();
    sprintf(buf, &data_020ef587, (void*)(ptr4 + 0x26));
    int result = ((BackgroundLoader*)(val5))->QueueLoadFileInGP2((const char*)(*(int*)((char*)&data_020ef460 + kFilenameOffset)), (const char*)((int)buf), (SafeAllocator*)(0));
    strcpy((char*)r6 + kNameOffset, ptr4 + 0x26);
    strcpy((char*)r6 + 0x548, &data_020ef58f);
    return result;
}
