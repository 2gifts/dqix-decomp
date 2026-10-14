#include <globaldefs.h>

void* TailCallAllocate_0218f4f0(unsigned int len);
int InitDiffFields_0218f508(void* obj, void* src);
void* TailCallAllocate_0218e7a4(unsigned int len);
void* ZeroFields_0218e7bc(void* obj);
int CallStubAndForward_0218e528(int a, int b, int c);
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
    Node_0218e558* n = (Node_0218e558*)TailCallAllocate_0218f4f0(0x14);
    if (n != 0) {
        *(void**)n = &data_ov016_0219d07c;
        n->f4 = 0;
        n->f8 = 0;
        *(void**)n = &data_ov016_0219d0a0;
    }

    if (n == 0) {
        return 0;
    }

    int result = InitDiffFields_0218f508(n, obj);
    if (result == 0) {
        if (n != 0) {
            n->Run();
        }
        return 0;
    }

    void* buf = TailCallAllocate_0218e7a4(
#if defined(jpn)
        0xd4
#else
        0xd8
#endif
    );
    if (buf != 0) {
        buf = ZeroFields_0218e7bc(buf);
    }
    result = CallStubAndForward_0218e528((int)buf, (int)n, param);
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
