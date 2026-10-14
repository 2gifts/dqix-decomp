#include <globaldefs.h>
int ComputeLevelAndByte020d2ac4(int);

extern int data_0210fcf4[];

struct Obj020bcbe0 {
    char pad0[0x3c];
    void* basePtr;
    char pad1[0x8];
    int count;
    unsigned char types[1];
};

int EnqueueEvent0x14_020d1ff0(int a, int b, int c);

// USA: func_020bcbe0
ARM void PostEventsForTypes020bcbe0(struct Obj020bcbe0* obj, void* base) {
    int type;
    int i = 0;
    obj->basePtr = base;
    if (obj->count <= 0) return;
    do {
        type = obj->types[i];
        char* entry = (char*)data_0210fcf4 + (type << 3);
        void* addr = (char*)obj->basePtr + *(int*)(entry + 4);
        int result = ComputeLevelAndByte020d2ac4((int)(addr));
        EnqueueEvent0x14_020d1ff0(1 << type, result & 0xff, result >> 8);
        i++;
    } while (i < obj->count);
}
