#include <globaldefs.h>

void* GetDataPtr02114e04_020d6c00(void);

struct FlagWord02046708;
int TestFlags02046708(struct FlagWord02046708* word, unsigned int mask);

extern "C" {
    void func_02021578(void* obj);
    void func_02021b84(void* obj);
    void func_020e081c(void* obj);
    void func_02021f88(void* obj);
    void func_020227dc(void* obj);
}

struct Obj020214f0 {
#if defined(jpn)
    char pad[0x915];
#else
    char pad[0x9c1];
#endif
    unsigned char field0x9c1;
    unsigned char pad2;
    unsigned char field0x9c3;
};

// USA: func_020214f0
ARM void HandleStateDispatch020214f0(struct Obj020214f0* obj) {
    if (obj->field0x9c3 == 0) {
        return;
    }
    if (TestFlags02046708((struct FlagWord02046708*)GetDataPtr02114e04_020d6c00(), 0x41)) {
        return;
    }

    switch (obj->field0x9c1) {
    case 0:
        func_02021578(obj);
        break;
    case 1:
        func_02021b84(obj);
        break;
    case 2:
        func_020e081c(obj);
        break;
    case 3:
        func_02021f88(obj);
        break;
    case 4:
        func_020227dc(obj);
        break;
    }
}
