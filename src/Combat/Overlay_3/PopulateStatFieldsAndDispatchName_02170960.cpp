#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

int GetGlobalField0x1c020421a0();
extern "C" void func_02046380(void);
extern "C" void* __clear(void* dst, int count);
extern "C" void func_02042764(unsigned char* src, char* dst, int n);

struct Dest_020e4b34 { int f0; int f4; unsigned int f8; };
extern "C" void func_020e4b34(Dest_020e4b34* dst, void* a1, int a2, unsigned int a3,
    unsigned char b0, unsigned char b1, unsigned char b2, unsigned char b3,
    unsigned char b4, unsigned char b5, unsigned char b6, unsigned char b7);

int CallFunc020e0434With02153694_020e51cc(int value);

struct Container020e0310;
int GetFieldByKey020e0434(struct Container020e0310* c, int key);

extern "C" void func_0204500c(void*, int, int, int);

struct Arg2_02170960 {
    char pad0[0xc];
    unsigned int nibble : 4;
    unsigned int rest : 28;
    char pad1[0x1e];
    unsigned char bit0 : 1;
};

struct Obj02170960 { char pad[0xd8]; struct Container020e0310* c; };

// USA: func_ov003_02170960  (semantic: PopulateStatFieldsAndDispatchName_02170960)
extern "C" ARM void func_ov003_02170960(struct Obj02170960* obj, int key, struct Arg2_02170960* p3) {
    int g = GetGlobalField0x1c020421a0();
    func_02046380();

    Dest_020e4b34 structA;
    Dest_020e4b34 structB;
    char buf[0x30];
    __clear(buf, 0x30);

    if (p3 != 0) {
        func_02042764((unsigned char*)p3, buf, 1);

        func_020e4b34(&structA, buf, 0, 0, 0, 0, 0, p3->bit0, 0, 1, 0, 1);
        *(void**)(g + 0x10) = &structA;

        int fmt = CallFunc020e0434With02153694_020e51cc(p3->nibble);

        func_020e4b34(&structB, (void*)fmt, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        *(void**)(g + 0x28) = &structB;
    }

    int fieldVal = GetFieldByKey020e0434(obj->c, (short)key);
    func_0204500c((void*)g, fieldVal, 0, 0xe3);

    *(unsigned char*)(g + 0x1000 + 0x9b2) = 1;
    *(int*)(g + 0x99c) = 2;
}
