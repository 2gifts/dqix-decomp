#include <globaldefs.h>

extern "C" int func_020d5fd0(int, int, int);
ARM void SetField54IfTagNot9Or10(int v);

typedef void (*Callback_0223a2b0)(int, void*);
struct DataOv02290d18_0223a2b0 { Callback_0223a2b0 unk0; unsigned char* inner; };
extern struct DataOv02290d18_0223a2b0 data_ov031_02290d18;
extern int data_ov031_0224c498;
extern int data_ov031_0224c4c8;

// USA: func_ov031_0223a2b0
extern "C" ARM int func_ov031_0223a2b0(int arg) {
    unsigned char* inner = data_ov031_02290d18.inner;
    int tag = func_020d5fd0((int)(inner + 0x13e0), arg, (int)(inner + 0x1c00));

    if (tag == 7) {
        Callback_0223a2b0 cb = data_ov031_02290d18.unk0;
        if (cb != NULL) {
            cb(0x8000000, &data_ov031_0224c498);
        }
        return 0;
    }
    if (tag == 5) {
        Callback_0223a2b0 cb = data_ov031_02290d18.unk0;
        if (cb != NULL) {
            cb(0x8000000, &data_ov031_0224c4c8);
        }
        SetField54IfTagNot9Or10(tag);
        return 0;
    }
    if (tag == 0) {
        return 1;
    }
    SetField54IfTagNot9Or10(tag);
    return 0;
}
