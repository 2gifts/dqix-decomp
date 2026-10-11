#include <globaldefs.h>
#if defined(jpn)
enum { kRegion1324 = 0x11b4 };
enum { kRegion19b2 = 0x17e2 };
enum { kRegion99c = 0x86c };
#else
enum { kRegion1324 = 0x1324 };
enum { kRegion19b2 = 0x19b2 };
enum { kRegion99c = 0x99c };
#endif

#if defined(jpn)
extern "C" void func_02045d88(void*, int, int);
#endif

int GetGlobalField0x1c020421a0();
extern "C" void func_02046380(void);
struct Container020e0310;
int GetFieldByKey020e0434(struct Container020e0310* c, int key);
struct Obj02046574;
void SetIndexedName02046574(struct Obj02046574* obj, int index, char* str);
struct StoreStruct;
void StoreInArray0x8b0(struct StoreStruct* base, int index, int value);
extern "C" void func_0204500c(void*, int, int, int);

// JPN: func_ov003_0216d3b0
// USA: func_ov003_0216d8d4  (semantic: SetIndexedNameAndStoreValues_0216d8d4)
#if defined(jpn)
extern "C" ARM void func_ov003_0216d8d4(char* obj, int keyA) {
#else
extern "C" ARM void func_ov003_0216d8d4(char* obj, int keyA, int p3, int p4, int p5) {
#endif
    int g = GetGlobalField0x1c020421a0();
#if !defined(jpn)
    func_02046380();

    if (p3 >= 0) {
        struct Container020e0310* c = (struct Container020e0310*)(obj + kRegion1324);
        int name = GetFieldByKey020e0434(c, (short)p3);
        SetIndexedName02046574((struct Obj02046574*)g, 5, (char*)name);
    }
    if (p4 >= 0) {
        StoreInArray0x8b0((struct StoreStruct*)g, 1, p4);
    }
    if (p5 >= 0) {
        StoreInArray0x8b0((struct StoreStruct*)g, 0, p5);
    }

#endif
    struct Container020e0310* c2 = (struct Container020e0310*)(obj + kRegion1324);
    int name2 = GetFieldByKey020e0434(c2, (short)keyA);
#if defined(jpn)
    func_02045d88((void*)g, name2, 0);
#else
    func_0204500c((void*)g, name2, 0, 0xe3);
#endif

    *(unsigned char*)(g + kRegion19b2) = 1;
    *(int*)(g + kRegion99c) = 2;
}
