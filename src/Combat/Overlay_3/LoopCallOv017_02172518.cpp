#include <globaldefs.h>

#if defined(jpn)
#define LoopCallOv017_02172518 func_ov003_021714f0
#endif

extern "C" void func_ov017_021d0ef8(int peerId, unsigned char* payload, int size, int offset, int* sentBytes);

struct Obj_02172518 {
    char pad0[0x199];
    unsigned char peerId;
#if defined(jpn)
    char unknown19a[0x19c - 0x19a];
    unsigned char profilePayload[0xe0];
#else
    char unknown19a[0x1c0 - 0x19a];
    unsigned char profilePayload[0xe0];
    char unknown2a0[0x380 - 0x2a0];
    unsigned char alternateProfilePayload[0xe0];
#endif
};

// USA: func_ov003_02172518
#if defined(jpn)
extern "C"
ARM void LoopCallOv017_02172518(struct Obj_02172518* obj) {
#else
ARM void LoopCallOv017_02172518(struct Obj_02172518* obj, int flag) {
#endif
    unsigned int sentBytes = 0;
#if defined(jpn)
    unsigned char* payload = obj->profilePayload;
#else
    unsigned char* payload = flag != 0 ? obj->profilePayload : obj->alternateProfilePayload;
#endif
    int chunkBytes;

    while (sentBytes < sizeof(obj->profilePayload)) {
        func_ov017_021d0ef8(obj->peerId, payload, sizeof(obj->profilePayload), sentBytes, &chunkBytes);
        sentBytes += chunkBytes;
    }
}
