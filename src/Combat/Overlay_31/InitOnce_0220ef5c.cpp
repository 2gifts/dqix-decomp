#include <globaldefs.h>

struct FourWords;
struct Mutex;
void ZeroInitializeMutex(Mutex*);

struct GuardStruct_0220ef5c {
    unsigned char guard;
    char pad0[3];
    int field4;
    int field8;
    char pad1[0x24 - 0xc];
    int field24;
};

extern struct GuardStruct_0220ef5c data_ov031_0224e540;
extern struct FourWords data_ov031_0224e54c;

// USA: func_ov031_0220ef5c
ARM void InitOnce_0220ef5c(void) {
    if (data_ov031_0224e540.guard != 0) {
        return;
    }
    data_ov031_0224e540.guard = 1;
    data_ov031_0224e540.field24 = 0;
    data_ov031_0224e540.field8 = 0;
    data_ov031_0224e540.field4 = 0;
    ZeroInitializeMutex((Mutex*)&data_ov031_0224e54c);
}
