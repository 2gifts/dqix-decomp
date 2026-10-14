#include <globaldefs.h>

extern "C" void* func_0205ec34(void);
int TestBitInByteArray_0206dfb0(int unused, unsigned char* arr, int index);

struct Entry020a8458 { unsigned char byte0; unsigned char byte1; char pad[0x2c - 2]; };
struct Obj020a8458 {
    struct Entry020a8458* arr;
    char pad4[2];
    unsigned short count;
};

// USA: func_020a8458  (semantic: PickBestEntry020a8458)
extern "C" ARM struct Entry020a8458* func_020a8458(struct Obj020a8458* obj) {
    void* ctx = func_0205ec34();
    unsigned char bestVal = 0xff;
    int bestIdx = 0;
    for (int i = 0; i < obj->count; i++) {
        struct Entry020a8458* e = (struct Entry020a8458*)((char*)obj->arr + i * 0x2c);
        if (e->byte1 == 0xff) {
            if (e->byte0 < bestVal) {
                if (TestBitInByteArray_0206dfb0((int)ctx, (unsigned char*)ctx + 0x8c, e->byte0 + 0x200)) {
                    bestVal = e->byte0;
                    bestIdx = i & 0xff;
                }
            }
        }
    }
    return (bestVal != 0xff) ? (struct Entry020a8458*)((char*)obj->arr + bestIdx * 0x2c) : 0;
}
