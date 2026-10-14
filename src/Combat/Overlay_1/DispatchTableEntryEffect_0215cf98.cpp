#include <globaldefs.h>
#include "World/Object3D.h"

extern "C" int func_ov017_0218b5b0(void);
extern "C" int func_ov017_021d60f4(void*);
int CallHelperIfCheckPasses_0218fcf8(int a, int b, int c);
int CallHelperIfCheckPasses_0218f92c(int a, int b, int c);

struct GlobalTable_0215cf98 { int pad0; unsigned char* elems; };
extern GlobalTable_0215cf98 data_ov001_02165880;

struct TableEntry_0215cf98 { int type; char pad4[8]; void* field0xc; };

// USA: func_ov001_0215cf98  (semantic: DispatchTableEntryEffect_0215cf98)
extern "C" ARM int func_ov001_0215cf98(void* self, int mode) {
    int ctx = func_ov017_0218b5b0();
    int id = func_ov017_021d60f4(self);
    struct TableEntry_0215cf98* e = (struct TableEntry_0215cf98*)(data_ov001_02165880.elems + id * 0x10);

    if (e->type == 0 || e->type == 1 || e->type == 4 || e->type == 5 || e->type == 6) {
        void* p = e->field0xc;
        if (p) {
            short sval = *(short*)((char*)p + 4);
            int a = func_ov017_021d60f4((char*)self + 8);
            int b = func_ov017_021d60f4((char*)self + 0x10);
            int c = func_ov017_021d60f4((char*)self + 0x18);
            unsigned short packed = (unsigned short)(a | (b << 5) | (c << 10));
            int extra = 0;
            if (mode - 4 > 0) {
                extra = func_ov017_021d60f4((char*)self + 0x20);
            }
            ((Object3D*)((unsigned char*)p))->SetField9e((unsigned char)(extra & 0xff));

            int cond = (sval >= 0 && sval <= 3);
            if (cond) {
                CallHelperIfCheckPasses_0218fcf8(ctx, sval, packed);
            } else {
                CallHelperIfCheckPasses_0218f92c(ctx, sval, packed);
            }
        }
    }
    return 1;
}
