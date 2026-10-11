#include <globaldefs.h>
#if defined(jpn)
#define IS_JPN 1
#else
#define IS_JPN 0
#endif
#if defined(jpn)
#define func_02052bfc func_02053fd8
#endif


extern "C" int _Z8fix32absi(int x);
#if defined(jpn)
extern "C" void func_020554e4(void* obj);
#define ConsumeCountdown0205416c func_020554e4
#else
void ConsumeCountdown0205416c(void* obj);
#endif

extern "C" {
    void _ZN8Object3D14AdvanceEffectsEv(void* obj);
    void func_02053634(void* obj);
    void func_020489e8(void* obj);
    void func_02052bfc(void* obj);
}

struct Obj02052ae8 {
    char pad0[IS_JPN ? 0x170 : 0x17c];
    signed char field17c;
    char pad1[0x1b4 - 0x17d];
    int field1b4;
    int field1b8;
    int field1bc;
};

// USA: func_02052ae8
ARM void StepValueTowardTarget02052ae8(struct Obj02052ae8* obj) {
    int cond = obj->field17c > 0;
    if (cond) {
        _ZN8Object3D14AdvanceEffectsEv(obj);
        func_02053634(obj);
    } else {
        func_020489e8(obj);
        func_02052bfc(obj);
    }

    if (obj->field1b4 > 0 || obj->field1b8 > 0) {
        int step = _Z8fix32absi((int)((float)(obj->field1b4 - obj->field1b8) * 0.1f));
        if (step == 0) {
            obj->field1b8 = obj->field1b4;
        }
        if (step < obj->field1bc) {
            obj->field1bc = step;
        } else if (obj->field1bc < step) {
            obj->field1bc += 0x14;
            if (step < obj->field1bc) {
                obj->field1bc = step;
            }
            if (obj->field1bc > 0x199) {
                obj->field1bc = 0x199;
            }
            step = obj->field1bc;
        }

        if (obj->field1b4 < obj->field1b8) {
            obj->field1b8 = obj->field1b8 - step;
            if (obj->field1b8 < obj->field1b4) {
                obj->field1b8 = obj->field1b4;
            }
        } else if (obj->field1b8 < obj->field1b4) {
            obj->field1b8 = obj->field1b8 + step;
            if (obj->field1b4 < obj->field1b8) {
                obj->field1b8 = obj->field1b4;
            }
        }
    }

    ConsumeCountdown0205416c(obj);
}
