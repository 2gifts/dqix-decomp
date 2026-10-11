#include <globaldefs.h>
#if defined(jpn)
enum { kArraySize = 0xa0 };
#else
enum { kArraySize = 0xb4 };
#endif

#include "Filesystem/BackgroundLoader.h"
#if defined(jpn)
#include "Filesystem/FileIO.h"
extern char data_020f244c[];
#endif
void InitHandlerArrayAndRunScript020d3c84(struct HandlerSlotArray020d3c84*, struct StreamHeader*, int);
#include "std_library_functions.h"

extern "C" void* ExtractFileFromGP2(const char* gp2Path, const char* innerFilePath, unsigned int* outSize);

extern int data_020f22e0;
extern int data_020f22f4;

struct Obj020d3c28 {
    unsigned char pad[kArraySize];
    int fieldB4;
};

// USA: func_020d3c28
ARM void InitAndMaybeStartStream020d3c28(struct Obj020d3c28* obj) {
    int localVar;
    int result;
    memset(obj, 0, kArraySize);
    obj->fieldB4 = 0;
    BackgroundLoader::AddLockGlobal();
#if defined(jpn)
    result = (int)LoadFileIntoMemory(data_020f244c, data_0211e33c, (unsigned int*)&localVar);
#else
    result = (int)ExtractFileFromGP2((const char*)&data_020f22e0, (const char*)&data_020f22f4, (unsigned int*)&localVar);
#endif
    if (result != 0) {
        InitHandlerArrayAndRunScript020d3c84((struct HandlerSlotArray020d3c84*)(obj), (struct StreamHeader*)(result), (int)(localVar));
    }
    BackgroundLoader::RemoveLockGlobal();
}
