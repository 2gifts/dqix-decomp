#include <globaldefs.h>
#if defined(jpn)
enum { kPointerOffset = 0x144 };
#else
enum { kPointerOffset = 0x150 };
#endif


void SetOrClearBitInArray(void* unused, unsigned char* array, int bit, int value);
extern "C" void* func_0205ec34(void);

struct Obj02052d7c {
    unsigned char pad[kPointerOffset];
    char* f150;
};

// USA: func_02052d7c  (semantic: SetIndexedShortField02052d7c)
extern "C" ARM void func_02052d7c(struct Obj02052d7c* obj, int index, short value) {
    char* ptr = obj->f150;
    if (ptr == 0) return;
    short old = *(short*)(ptr + index * 2 + 0x400 + 0x88);
    if (value == old) return;

    if (index != 7 && index != 8) {
        void* ctx = func_0205ec34();
        SetOrClearBitInArray(ctx, (unsigned char*)ctx + 0x8c, 0x113f, 1);
    }

    ptr = obj->f150;
    *(short*)(ptr + index * 2 + 0x400 + 0x88) = value;
    if (index != 9) return;

    ptr = obj->f150;
    if (ptr != 0) {
        ptr[0x56e] = 1;
    }
}
