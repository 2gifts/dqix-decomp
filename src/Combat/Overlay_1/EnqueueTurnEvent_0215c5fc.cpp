#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" int func_ov017_021d60f4(void*);
extern "C" void* func_ov001_0215ab20(int);
extern "C" int fix32_Atan2(int x, int z);
int fix32ReduceAngle0To2Pi(int angle);
int fix32abs(int x);

struct Payload12_0215a480 {
    unsigned int w0;
    unsigned int w1;
    unsigned int w2;
};
void EnqueueEventType8_0215a480(void* ctx, struct Payload12_0215a480 payload, unsigned int a, unsigned int b);

// USA: func_ov001_0215c5fc  (semantic: EnqueueTurnEvent_0215c5fc)
extern "C" ARM int func_ov001_0215c5fc(void* obj, int mode) {
    int x1 = func_ov017_021d60f4(obj);
    void* ctxA = func_ov001_0215ab20(x1);
    if (ctxA == NULL) return 0;
    int x2 = func_ov017_021d60f4((char*)obj + 0x8);
    void* ctxB = func_ov001_0215ab20(x2);
    if (ctxB == NULL) return 0;

    int deltaY = *(int*)((char*)ctxB + 0x74) - *(int*)((char*)ctxA + 0x74);
    int deltaX = *(int*)((char*)ctxB + 0x7c) - *(int*)((char*)ctxA + 0x7c);
    struct Payload12_0215a480 payload;
    memcpy(&payload, (char*)ctxA + 0x80, sizeof(payload));
    payload.w1 = fix32ReduceAngle0To2Pi(fix32_Atan2(deltaY, deltaX));

    unsigned int a = func_ov017_021d60f4((char*)obj + 0x10);
    unsigned int b;
    if (mode >= 4) {
        b = func_ov017_021d60f4((char*)obj + 0x18);
    } else {
        short diff = (short)(*(int*)((char*)ctxA + 0x84)) - (short)payload.w1;
        if (fix32abs(diff) > 0x3244) {
            b = (diff < 0) ? 1 : 0;
        } else {
            if (diff < 0) {
                b = 0;
            } else {
                b = 1;
            }
        }
    }

    EnqueueEventType8_0215a480(ctxA, payload, a, b);
    return 1;
}
