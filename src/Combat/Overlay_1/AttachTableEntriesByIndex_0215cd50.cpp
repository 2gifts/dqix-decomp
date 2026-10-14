#include <globaldefs.h>
#include "World/Object3D.h"

extern "C" int func_ov017_021d60f4(void*);
extern "C" int func_ov017_021d612c(void*);

struct Node02037890;
struct Object3D;

struct TableStruct0215cd50 { void* unused0; char* base; };
extern TableStruct0215cd50 data_ov001_02165880;
struct Entry0215cd50 { int word0; char pad[8]; void* fieldC; };

// USA: func_ov001_0215cd50
ARM int AttachTableEntriesByIndex_0215cd50(void* self, int mode) {
    int idx1 = func_ov017_021d60f4(self);
    int idx2 = func_ov017_021d60f4((char*)self + 0x8);
    int extra = 0;
    if (mode >= 3) {
        extra = func_ov017_021d612c((char*)self + 0x10);
    }
    Entry0215cd50* table = (Entry0215cd50*)data_ov001_02165880.base;
    void* fieldC1 = NULL;
    void* fieldC2 = fieldC1;
    int w = table[idx1].word0;
    if (w == 0 || w == 4 || w == 5 || w == 1 || w == 6) {
        fieldC1 = table[idx1].fieldC;
    }
    w = table[idx2].word0;
    if (w == 0 || w == 4 || w == 5 || w == 1 || w == 6) {
        fieldC2 = table[idx2].fieldC;
    }
    if (fieldC1 == NULL || fieldC2 == NULL) return 0;
    ((Object3D*)((struct Node02037890*)fieldC1))->Attach((Object3D*)fieldC2, (char*)extra);
    return 1;
}
