#include <globaldefs.h>

extern "C" void* _Z25TailCallAllocate_0218f4f0j(unsigned int len);
extern "C" int _Z23InitDiffFields_0218f508PvS_(void* obj, void* src);
extern "C" void* _Z25TailCallAllocate_0218e7a4j(unsigned int len);
extern "C" void* _Z19ZeroFields_0218e7bcPv(void* obj);
extern "C" int _Z27CallStubAndForward_0218e528iii(int a, int b, int c);
extern "C" void func_ov016_0218e7ec(void* a);
extern "C" void func_ov016_0218e7b0(void* data);

extern int data_ov016_0219d07c;
extern int data_ov016_0219d0a0;

struct Node_0218e558 {
    virtual void Dummy0();
    virtual int Run();
    int f4;
    int f8;
};

// USA: func_ov016_0218e558  (semantic: CreateDiffNode_0218e558)
extern "C" ARM int func_ov016_0218e558(void* obj, int param) {
    Node_0218e558* n = (Node_0218e558*)_Z25TailCallAllocate_0218f4f0j(0x14);
    if (n != 0) {
        *(void**)n = &data_ov016_0219d07c;
        n->f4 = 0;
        n->f8 = 0;
        *(void**)n = &data_ov016_0219d0a0;
    }

    if (n == 0) {
        return 0;
    }

    int result = _Z23InitDiffFields_0218f508PvS_(n, obj);
    if (result == 0) {
        if (n != 0) {
            n->Run();
        }
        return 0;
    }

    void* buf = _Z25TailCallAllocate_0218e7a4j(
#if defined(jpn)
        0xd4
#else
        0xd8
#endif
    );
    if (buf != 0) {
        buf = _Z19ZeroFields_0218e7bcPv(buf);
    }
    result = _Z27CallStubAndForward_0218e528iii((int)buf, (int)n, param);
    switch (result) {
    case 0:
        if (buf != 0) {
            func_ov016_0218e7ec(buf);
            func_ov016_0218e7b0(buf);
        }
        return 0;
    }
    return (int)buf;
}
