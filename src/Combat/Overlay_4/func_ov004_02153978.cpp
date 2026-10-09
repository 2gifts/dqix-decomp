#include <globaldefs.h>

struct Obj021f6f08;
extern "C" void* _Z16DoThing_021f6590Pv(void*);
extern "C" unsigned int _Z18GetShort6_021f6f08P11Obj021f6f08(Obj021f6f08*);
typedef void* (*DoThingFn_02153978)(void*, int);

// USA: func_ov004_02153978
extern "C" ARM void func_ov004_02153978(void* obj, short* pA, short* pB, short* pC) {
    *pC = -1;
    short v = *pC;
    *pB = v;
    *pA = v;
    void* node = ((DoThingFn_02153978)_Z16DoThing_021f6590Pv)(obj, 5);
    if (!node) return;
    switch (_Z18GetShort6_021f6f08P11Obj021f6f08((Obj021f6f08*)node)) {
        case 0x1a:
            *pA = 0;
            return;
        case 0x1b:
            *pB = 0;
            node = ((DoThingFn_02153978)_Z16DoThing_021f6590Pv)(obj, 0x2a);
            if (!node) return;
            switch (_Z18GetShort6_021f6f08P11Obj021f6f08((Obj021f6f08*)node)) {
                case 0x1a: *pC = 0; return;
                case 0x20: *pC = 1; return;
                case 0x1b: *pC = 2; return;
                case 0x21: *pC = 3; return;
                case 0x1c: *pC = 4; return;
                case 0x22: *pC = 5; return;
                case 0x1d: *pC = 6; return;
                case 0x23: *pC = 7; return;
                case 0x1e: *pC = 8; return;
                case 0x24: *pC = 9; return;
                case 0x1f: *pC = 10; return;
                case 0x25: *pC = 11; return;
            }
            break;
        case 0x1c:
            node = ((DoThingFn_02153978)_Z16DoThing_021f6590Pv)(obj, 0x2b);
            if (!node) return;
            switch (_Z18GetShort6_021f6f08P11Obj021f6f08((Obj021f6f08*)node)) {
                case 0x1a: *pB = 1; return;
                case 0x1b: *pB = 2; return;
                case 0x1c: *pB = 3; return;
                case 0x1d: *pB = 4; return;
                case 0x1e: *pB = 5; return;
                case 0x1f: *pB = 6; return;
            }
            break;
        case 0x1d:
            *pA = 3;
            *pB = 7;
            return;
    }
}
