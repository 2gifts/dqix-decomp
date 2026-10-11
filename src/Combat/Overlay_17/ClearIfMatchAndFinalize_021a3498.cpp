#include <globaldefs.h>

extern "C" int func_ov017_0218b5b0(void);
struct ClearList02046968;
void ClearListUntilFlagZero(struct ClearList02046968* list);
extern "C" void func_ov017_021a3544(void* self, void* ptr0);

struct Buf72_021a3498 {
    int words[18];
};
extern struct Buf72_021a3498 data_ov017_021d6a34;

struct Ctx021a3498 {
    void* field0;
};

// JPN: func_ov017_021a3f0c
// USA: func_ov017_021a3498
ARM void ClearIfMatchAndFinalize_021a3498(struct Ctx021a3498* self) {
#if defined(jpn)
 enum {regionalOffset0=0x134};
#else
 enum {regionalOffset0=0x354};
#endif
    void* ptr = self->field0;
    if (ptr != NULL && *((unsigned char*)ptr + 1) != 0) {
        int obj = func_ov017_0218b5b0();
        if (obj != 0) {
            struct Buf72_021a3498 local = data_ov017_021d6a34;
            int* p = local.words;
            while (*p != 0xffff) {
                signed char val = *(signed char*)self->field0;
                if (val == *p) {
                    *((unsigned char*)(long)obj + 0x4000 + regionalOffset0) = 0xc;
                    break;
                }
                p++;
            }
        }
    }
    ClearListUntilFlagZero((struct ClearList02046968*)self);
    func_ov017_021a3544(self, self->field0);
}
