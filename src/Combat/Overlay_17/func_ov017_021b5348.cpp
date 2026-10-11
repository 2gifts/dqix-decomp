// JPN: func_ov017_021b58fc
#if defined(jpn)
enum { RegionOffset44 = 0x40, RegionOffset304 = 0x300, RegionOffset308 = 0x304 };
#else
enum { RegionOffset44 = 0x44, RegionOffset304 = 0x304, RegionOffset308 = 0x308 };
#endif

#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"

extern "C" void* func_0202ae18(void);
struct List0202fe68;
struct List0202fec8;
extern "C" void __clear(void* buf, int size);
struct HalfwordArray {
    unsigned short arr[12];
    unsigned short count;
};
ARM unsigned short CopyHalfwordArrayByCount(struct HalfwordArray* src, struct HalfwordArray* dst);
struct ZeroWordAndByte0206ee60Struct;
void ZeroWordAndByte0206ee60(struct ZeroWordAndByte0206ee60Struct* obj);
struct StreamHeader;
void RegisterCallbackWithArgsAndRunScript(void* a, void* b, struct StreamHeader* c, int d, void* e, short f);
extern "C" void func_ov017_021b5648(void* obj);

extern char data_ov017_021d7bdc;

struct Obj021b5348 {
    char pad0[8];
    void* sub;
    int key;
    unsigned char field10;
};

struct Sub021b5348 {
    char pad0[RegionOffset308];
    unsigned char field308;
};

// USA: func_ov017_021b5348  (semantic: ApplyPendingListEntryAndRunScript_021b5348)
extern "C" ARM void func_ov017_021b5348(struct Obj021b5348* obj) {
    void* subEarly;
    GameState::GetInstance();
    int list = (int)BackgroundLoader::GetInstance();
    func_0202ae18();
    if (!((BackgroundLoader*)(list))->GetTaskStatus((int)(obj->key))) {
        return;
    }

    subEarly = obj->sub;
    if (((BackgroundLoader*)((struct List0202fe68*)list))->GetDetailedTaskStatus((int)(obj->key)) == 2) {
        int out2, out1;
        ((BackgroundLoader*)((struct List0202fec8*)list))->GetLoadedFileByID((int)(obj->key), (void**)(&out1), (unsigned int*)(&out2));
        if (out1 != 0) {
            char* sub = (char*)obj->sub;
            unsigned short buf[12];
            __clear(buf, 0x18);
            short signedCount = (short)CopyHalfwordArrayByCount((struct HalfwordArray*)(sub + RegionOffset44), (struct HalfwordArray*)buf);
            ZeroWordAndByte0206ee60((struct ZeroWordAndByte0206ee60Struct*)((char*)subEarly + RegionOffset304));
            void* ptrB = *(void**)((char*)obj->sub + 0x10);
            RegisterCallbackWithArgsAndRunScript((char*)subEarly + RegionOffset304, ptrB, (struct StreamHeader*)out1, (short)out2, buf, signedCount);
        }
    }

    ((BackgroundLoader*)(list))->RemoveTask((int)(obj->key));
    obj->key = -1;
    int zero = 0;
    if (((struct Sub021b5348*)subEarly)->field308 > zero) {
        obj->key = ((BackgroundLoader*)(list))->QueueLoadFile((const char*)((int)&data_ov017_021d7bdc), (SafeAllocator*)(0));
        obj->field10 = 8;
    } else {
        func_ov017_021b5648(obj);
    }
}
