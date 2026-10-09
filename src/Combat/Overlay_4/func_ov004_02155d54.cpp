#include <globaldefs.h>

struct Vec3_02155d54 { int x, y, z; };

class Node02155d54 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6();
    virtual void SetVal0x1c(const Vec3_02155d54& v);
    virtual Vec3_02155d54 GetVal0x20();
};

struct StatusState_02155d54 {
    unsigned char pad[0xe];
    unsigned short value;
};
extern StatusState_02155d54* data_ov004_021707c4;

extern "C" void* func_ov011_021849c8(void* a);
extern "C" Node02155d54* func_ov023_021f6880(void* obj, int key);
extern "C" void _Z26SetByteAtOffset60_021f9da0Pvh(void* obj, unsigned char v);
extern "C" int func_ov004_0215513c(void* obj, short* pB, short* pC, short* pD);
extern "C" int func_ov004_02155090(void);
extern "C" int func_ov004_02155104(void);
extern "C" int _Z26GetField38IfKind8_021f6378Pvi(void* a, int key);
extern "C" void* _Z21Lookup4Entry_021f63acPvii(void* a, int b, int c);
extern "C" void func_ov023_021f645c(void* a, int b, unsigned short c, int d);
extern "C" void func_ov023_021f64a8(void* a, int b, unsigned short c, int d);
extern "C" int _Z29DispatchNodeIfState6_021f6680Pvi(void* obj, int id);

// USA: func_ov004_02155d54
extern "C" ARM int func_ov004_02155d54(void* self) {
    _Z26SetByteAtOffset60_021f9da0Pvh(func_ov023_021f6880(func_ov011_021849c8(self), 5), 1);

    short b, c, d;
    func_ov004_0215513c(self, &b, &c, &d);

    unsigned short value;
    unsigned short mode = 0xd;
    if (b == 0) {
        value = (short)data_ov004_021707c4->value;
    } else if (c == 8) {
        value = func_ov004_02155090();
        mode = 0xe;
    } else {
        value = func_ov004_02155104();
        mode = 0xf;
    }

    Node02155d54* node = func_ov023_021f6880(func_ov011_021849c8(self), 0x14);
    if (node) {
        char* entry = (char*)_Z21Lookup4Entry_021f63acPvii(self, 4, _Z26GetField38IfKind8_021f6378Pvi(self, 0x19));
        if (entry == 0 || *entry == 0) {
            Node02155d54* src = func_ov023_021f6880(func_ov011_021849c8(self), 0x19);
            if (src) {
                const Vec3_02155d54& v = src->GetVal0x20();
                node->SetVal0x1c(v);
            }
        }
    }

    func_ov023_021f645c(self, 7, mode, 0xf);
    func_ov023_021f64a8(self, 0x14, value, 0xf);
    _Z29DispatchNodeIfState6_021f6680Pvi(self, 0x10);
    return 0;
}
