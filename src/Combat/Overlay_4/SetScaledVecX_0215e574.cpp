#include <globaldefs.h>
#include <System/Matrix.h>

class Node0215e574 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6();
    virtual void SetVal0x1c(const Vector3i& v);
    virtual Vector3i GetVal0x20();
};

extern "C" int func_ov004_0215e4e8(void* a, int key);
extern "C" Node0215e574* func_ov004_0215e47c(void* a, int key);

// USA: func_ov004_0215e574  (semantic: SetScaledVecX_0215e574)
extern "C" ARM void func_ov004_0215e574(void* a, int b, int c, int d) {
    int r5 = func_ov004_0215e4e8(a, (short)b);
    Node0215e574* node = func_ov004_0215e47c(a, b);
    if (!node) return;
    Vector3i v2;
    const Vector3i& v = node->GetVal0x20();
    v2 = v;
    v2.x = (d + ((c - r5) >> 1)) << 12;
    node->SetVal0x1c(v2);
}
