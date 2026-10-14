#include <globaldefs.h>
#include "GameState/GameState.h"

struct Field2a04_02158b78 { char pad[0xf6c]; int f0xf6c; };
extern "C" void* func_ov004_02156f38(void* self, int kind);
extern "C" void* func_ov004_02156f6c(void* self, int kind);
extern "C" void func_ov023_021f809c(void* a, void* self);

class VObj02158b78 {
public:
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
    virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
    virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51();
    virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55();
    virtual void MethodE0(int a);
};

// USA: func_ov004_02158b78
ARM int Dispatch02158b78(void* self) {
    VObj02158b78* node = (VObj02158b78*)func_ov004_02156f38(self, 0xc9);
    if (node) {
        struct Field2a04_02158b78* fld = (struct Field2a04_02158b78*)GetPtrField0x2a04_02010828(GameState::GetInstance());
        node->MethodE0(fld->f0xf6c);
        void* x = func_ov004_02156f6c(self, 0x16);
        if (x) func_ov023_021f809c(x, self);
    }
    return 0;
}
