#include <globaldefs.h>

void* GetData02100044_0202ae24(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct LocalEvt021cd0d8 {
    unsigned char tag;
    unsigned char pad1[3];
    unsigned char threeBit : 3;
    unsigned char count : 3;
    unsigned char pad4 : 2;
    unsigned char pad5;
    short vals[7];
};

// USA: func_ov017_021cd0d8  (semantic: SendShortArrayInChunks_021cd0d8)
extern "C" ARM void func_ov017_021cd0d8(int a0, unsigned short* a1, int a2) {
    void* p = GetData02100044_0202ae24();
    int consumed;
    int j;

    struct LocalEvt021cd0d8 evt;
    evt.tag = 0x10;
    evt.threeBit = (unsigned char)a0;

    consumed = 0;
    j = 0;
    while (consumed < a2) {
        int i = 0;
        for (; i < 7; i++) {
            if (a2 <= consumed + i) {
                break;
            }
            evt.vals[i] = a1[j * 7 + i];
        }
        evt.count = i;
        func_0205e330(p, &evt, 0);
        consumed += evt.count;
        j++;
    }
}
