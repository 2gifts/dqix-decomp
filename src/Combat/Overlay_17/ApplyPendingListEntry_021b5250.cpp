#include <globaldefs.h>

#if defined(jpn)
enum { kHalfwordArrayOffset = 0x40, kPendingEntryOffset = 0x2f4 };
#else
enum { kHalfwordArrayOffset = 0x44, kPendingEntryOffset = 0x2f8 };
#endif


#if defined(jpn)
#define data_ov017_021d7bc3 data_ov017_021d82dd
#endif


#if defined(jpn)
#define func_ov017_021b5250 func_ov017_021b5814
#endif
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"

struct List0202fe68;
struct List0202fec8;
extern "C" void __clear(void* buf, int size);
struct HalfwordArray {
    unsigned short arr[12];
    unsigned short count;
};
ARM unsigned short CopyHalfwordArrayByCount(struct HalfwordArray* src, struct HalfwordArray* dst);
void* Clear12Bytes0206efc4(void* obj);
#if defined(jpn)
extern "C" void func_0206f230(void* a, int b, int c, int d, void* e, int f);
#else
extern "C" void func_0206f230(void* a, int b, int c, int d, void* e, int f, int g, int h);
#endif

extern char data_ov017_021d7bc3;

struct Obj021b5250 {
    char pad0[8];
    void* sub;
    int key;
    unsigned char field10;
    char pad1[3];
    int field14;
};

// USA: func_ov017_021b5250  (semantic: ApplyPendingListEntry_021b5250)
extern "C" ARM void func_ov017_021b5250(struct Obj021b5250* obj) {
    GameState::GetInstance();
    int list = (int)BackgroundLoader::GetInstance();
    if (!((BackgroundLoader*)(list))->GetTaskStatus((int)(obj->key))) {
        return;
    }

    if (((BackgroundLoader*)((struct List0202fe68*)list))->GetDetailedTaskStatus((int)(obj->key)) == 2) {
        int out2, out1;
        ((BackgroundLoader*)((struct List0202fec8*)list))->GetLoadedFileByID((int)(obj->key), (void**)(&out1), (unsigned int*)(&out2));
        if (out1 != 0) {
            char* sub = (char*)obj->sub;
            unsigned short buf[12];
            __clear(buf, 0x18);
            short signedCount = (short)CopyHalfwordArrayByCount((struct HalfwordArray*)(sub + kHalfwordArrayOffset), (struct HalfwordArray*)buf);
            char* pending = (char*)obj->sub + kPendingEntryOffset;
            Clear12Bytes0206efc4(pending);
            char* sub2 = (char*)obj->sub;
            func_0206f230(pending, *(int*)(sub2 + 0x10), out1, out2, buf, signedCount
#if !defined(jpn)
                , *(int*)(sub2 + 0x14), obj->field14
#endif
            );
        }
    }

    ((BackgroundLoader*)(list))->RemoveTask((int)(obj->key));
    obj->key = -1;
    obj->key = ((BackgroundLoader*)(list))->QueueLoadFile((const char*)((int)&data_ov017_021d7bc3), (SafeAllocator*)(0));
    obj->field10 = 7;
}
