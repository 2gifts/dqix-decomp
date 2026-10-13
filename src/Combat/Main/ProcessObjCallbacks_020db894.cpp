#include <globaldefs.h>

void PushInterruptDisableState();

struct Obj020db964;
void RefreshSlots0x5cFromCallbacks(Obj020db964* obj);

struct Actor020db844;
void RunFlaggedCallback020db844(Actor020db844* a, int b, int c, int d);

void ConfigureAndDispatchHandle020db304(int obj, int b);

struct FlagWord020466f4;
FlagWord020466f4* GetDataPtr02114e04_020d6c00();
void ClearFlags020466f4(FlagWord020466f4* word, unsigned int mask);

struct Struct020db0c4;
void InitStruct020db0c4(Struct020db0c4* p);

void InitFlag0x28FromOverlay(void* obj);

extern "C" void func_020d8694();

typedef void (*FnVoidInt)(int);
typedef int (*FnIntVoid)(void);
extern FnVoidInt data_020f28dc[];
extern FnIntVoid data_020f28fc[];
extern FnVoidInt data_020f28f4[];

struct Obj020db894 {
    char pad00[0x3c];
    unsigned char b3c;
    char pad3d[0x51 - 0x3d];
    unsigned char b51;
    unsigned char pad52;
    unsigned char b53;
    char pad54[0x5c - 0x54];
    int field5c;
    int field60;
    unsigned char b64;
    char pad65[0x6a - 0x65];
    short sh6a;
};

// USA: func_020db894  (semantic: ProcessObjCallbacks_020db894)
extern "C" ARM void func_020db894(Obj020db894* obj) {
    if (!obj->b51) {
        return;
    }
    PushInterruptDisableState();
    RefreshSlots0x5cFromCallbacks((Obj020db964*)obj);
    if (obj->b53) {
        RunFlaggedCallback020db844((Actor020db844*)obj, obj->b3c, obj->sh6a, 0);
        data_020f28dc[6](obj->field5c);
        data_020f28dc[7](obj->field60);
    } else if (!obj->b64) {
        int result = data_020f28fc[obj->b3c]();
        result &= ~0x10;
        data_020f28f4[obj->b3c](result);
    }
    ConfigureAndDispatchHandle020db304((int)obj, obj->b3c);
    ClearFlags020466f4(GetDataPtr02114e04_020d6c00(), 0x8000);
    InitStruct020db0c4((Struct020db0c4*)obj);
    InitFlag0x28FromOverlay(obj);
    func_020d8694();
}
