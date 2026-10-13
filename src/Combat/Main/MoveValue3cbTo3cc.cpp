#include <globaldefs.h>

struct CopyPayload {
#if defined(jpn)
    char data[11];
#else
    char data[48];
#endif
};
struct CopyableRecord {
    CopyPayload payload;
#if defined(jpn)
    unsigned char byte11;
#endif
    short f30;
    signed char f32;
    unsigned char f33;
};

struct NamedRequestQueue {
    CopyableRecord active[8];
    CopyableRecord saved[8];
#if defined(jpn)
    char unknown100[0x13b - 0x100];
#else
    char unknown340[0x3cb - 0x340];
#endif
    signed char activeCount;
    signed char savedCount;
    unsigned char flags;
};

#if defined(jpn)
#define func_02093ad8 func_02094400
#define MoveValue3cbTo3cc func_02094380
extern "C" ARM void func_02094380(char*);
#endif
extern "C" void func_02093ad8(void*, CopyableRecord* source, CopyableRecord* destination, int count);


ARM void MoveValue3cbTo3cc(char* storage) {
    NamedRequestQueue* queue = reinterpret_cast<NamedRequestQueue*>(storage);
    func_02093ad8(queue, queue->active, queue->saved, queue->activeCount);
    queue->savedCount = queue->activeCount;
    queue->activeCount = 0;
    queue->flags &= ~4;
}
