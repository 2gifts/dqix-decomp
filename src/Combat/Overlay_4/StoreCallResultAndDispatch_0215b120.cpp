#include <globaldefs.h>
#if defined(jpn)
#define func_ov004_0215b120 func_ov004_0215c128
extern "C" void func_020e207c(void*, char*, int);
struct Obj02046574;
void SetIndexedName02046574(Obj02046574*, int, char*);
#endif


int GetGlobalField0x1c020421a0(void);
extern "C" void func_02046380(void* global);
struct Container020dedd0;
extern "C" struct Container020dedd0* func_ov004_02156fd4(void* obj, int key);
struct Element020de650;
struct Element020de650* FindElementByKey020dedd0(struct Container020dedd0* c, int key);
void* CallFunc020e52a0(void* arr, int key);
struct StoreStruct;
void StoreInArray0x8b0(struct StoreStruct* base, int index, int value);

struct Struct021707d8_0215b120 { char pad[8]; char* ptr; };
extern Struct021707d8_0215b120 data_ov004_021707d8;

// USA: func_ov004_0215b120  (semantic: StoreCallResultAndDispatch_0215b120)
extern "C" ARM int func_ov004_0215b120(void* self) {
    void* g = (void*)GetGlobalField0x1c020421a0();
    func_02046380(g);

    struct Container020dedd0* c = func_ov004_02156fd4(self, 5);
    struct Element020de650* elem = FindElementByKey020dedd0(c, *(short*)(data_ov004_021707d8.ptr + 0x6c));

    char* ptr2 = data_ov004_021707d8.ptr;
    unsigned char flag = *(unsigned char*)(ptr2 + 0x6e);
    void* obj8c = ptr2 + 0x8c;

    if (flag == 1) {
#if defined(jpn)
        char name[80];
        func_020e207c(obj8c, name, *(short*)((char*)elem + 0x18));
        SetIndexedName02046574((Obj02046574*)g, 1, name);
#else
        void* r = CallFunc020e52a0(obj8c, *(short*)((char*)elem + 0x18));
        *(void**)((char*)g + 0x18) = r;
#endif
        StoreInArray0x8b0((struct StoreStruct*)g, 0, *(int*)(data_ov004_021707d8.ptr + 0x78));
    } else {
#if defined(jpn)
        char name[80];
        func_020e207c(obj8c, name, *(short*)((char*)elem + 0x18));
        SetIndexedName02046574((Obj02046574*)g, 1, name);
#else
        void* r = CallFunc020e52a0(obj8c, *(short*)((char*)elem + 0x18));
        *(void**)((char*)g + 0x18) = r;
#endif
        StoreInArray0x8b0((struct StoreStruct*)g, 0, *(int*)(data_ov004_021707d8.ptr + 0x78));
        StoreInArray0x8b0((struct StoreStruct*)g, 1, *(unsigned char*)(data_ov004_021707d8.ptr + 0x6e));
    }
    return 0;
}
