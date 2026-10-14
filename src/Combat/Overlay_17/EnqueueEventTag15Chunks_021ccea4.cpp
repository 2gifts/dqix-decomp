#include <globaldefs.h>

void* GetData02100044_0202ae24(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct LocalMsg021ccea4 {
    unsigned char tag;
    unsigned char pad0[3];
    unsigned char aField : 3;
    unsigned char loopField : 4;
    unsigned char pad4b : 1;
    unsigned char arr[15];
};

// USA: func_ov017_021ccea4  (semantic: EnqueueEventTag15Chunks_021ccea4)
extern "C" ARM void func_ov017_021ccea4(int a, unsigned char* b, int c) {
    void* p = GetData02100044_0202ae24();
    LocalMsg021ccea4 msg;
    msg.tag = 0xf;
    msg.aField = a;
    int pos = 0;
    int group = 0;
    while (pos < c) {
        int j;
        for (j = 0; j < 15; j++) {
            if (c <= pos + j) break;
            msg.arr[j] = b[group * 15 + j];
        }
        msg.loopField = j;
        func_0205e330(p, &msg, 0);
        pos += msg.loopField;
        group++;
    }
}
