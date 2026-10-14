#include <globaldefs.h>
#include "World/Object3D.h"

extern "C" int func_ov017_021d60f4(void*);
extern "C" void func_ov017_021d6134(void*, unsigned int);
struct BitFlags02037170;

struct TableStruct0215ccdc { void* unused0; char* base; };
extern TableStruct0215ccdc data_ov001_02165880;
struct Entry0215ccdc { int word0; char pad[8]; void* fieldC; };

// USA: func_ov001_0215ccdc
ARM int UpdateFlagFromNodeState_0215ccdc(void* self) {
    int idx = func_ov017_021d60f4(self);
    Entry0215ccdc* table = (Entry0215ccdc*)data_ov001_02165880.base;
    int word0 = table[idx].word0;
    if (word0 == 0 || word0 == 4 || word0 == 5 || word0 == 1 || word0 == 6) {
        void* fieldC = table[idx].fieldC;
        if (fieldC != NULL) {
            int b = ((Object3D*)((struct BitFlags02037170*)fieldC))->HasAnimationStopped();
            unsigned int val = (b == 0) ? 1 : 0;
            func_ov017_021d6134((char*)self + 0x8, val);
        }
    } else {
        func_ov017_021d6134((char*)self + 0x8, 1);
    }
    return 1;
}
