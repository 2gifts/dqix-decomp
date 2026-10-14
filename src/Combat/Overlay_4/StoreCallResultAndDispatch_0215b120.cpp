#include <globaldefs.h>
#if defined(jpn)
struct Container020e0310;
extern "C" char* func_020e207c(Container020e0310*, char*, int);
struct Obj02046574;
void SetIndexedName02046574(Obj02046574*, int, char*);
#endif

int GetGlobalField0x1c020421a0(void);
extern "C" void func_02046380(void* global);
struct Container020dedd0;
extern "C" struct Container020dedd0* func_ov004_02156fd4(void* obj, int key);
struct Element020de650 {
    unsigned char unknown0[0x18];
    short key;
    unsigned char unknown1a[6];
};
struct Element020de650* FindElementByKey020dedd0(struct Container020dedd0* c, int key);
void* CallFunc020e52a0_020e5294(void* arr, int key);
struct StoreStruct;
void StoreInArray0x8b0_020465c0(struct StoreStruct* base, int index, int value);

#if defined(jpn)
struct Element020e0310 { int key; int value; };
struct Container020e0310 {
    unsigned int count : 12;
    unsigned int rest : 20;
    Element020e0310* base;
};
typedef Container020e0310 NameTable0215b120;
#else
struct NameEntry0215b120 {
    void* first;
    void* second;
    unsigned int unknown8;
    unsigned short key;
    unsigned short unknownE;
};
struct NameTable0215b120 {
    unsigned int count : 12;
    unsigned int rest : 20;
    NameEntry0215b120* entries;
};
#endif
struct ItemSelection0215b120 {
    unsigned char unknown0[0x6c];
    short itemId;
    unsigned char quantity;
    unsigned char maximumQuantity;
    unsigned char unknown70[8];
    int value;
    unsigned char unknown7c[0x10];
    NameTable0215b120 names;
};
struct Struct021707d8_0215b120 { char pad[8]; ItemSelection0215b120* ptr; };
extern Struct021707d8_0215b120 data_ov004_021707d8;

// USA: func_ov004_0215b120  (semantic: StoreCallResultAndDispatch_0215b120)
extern "C" ARM int func_ov004_0215b120(void* self) {
    void* g = (void*)GetGlobalField0x1c020421a0();
    func_02046380(g);

    struct Container020dedd0* c = func_ov004_02156fd4(self, 5);
    struct Element020de650* elem = FindElementByKey020dedd0(c, data_ov004_021707d8.ptr->itemId);

    ItemSelection0215b120* selection = data_ov004_021707d8.ptr;
    unsigned char quantity = selection->quantity;
    NameTable0215b120* names = &selection->names;

    if (quantity == 1) {
#if defined(jpn)
        char name[80];
        func_020e207c(names, name, elem->key);
        SetIndexedName02046574((Obj02046574*)g, 1, name);
#else
        void* r = CallFunc020e52a0_020e5294(names, elem->key);
        *(void**)((char*)g + 0x18) = r;
#endif
        StoreInArray0x8b0_020465c0((struct StoreStruct*)g, 0, data_ov004_021707d8.ptr->value);
    } else {
#if defined(jpn)
        char name[80];
        func_020e207c(names, name, elem->key);
        SetIndexedName02046574((Obj02046574*)g, 1, name);
#else
        void* r = CallFunc020e52a0_020e5294(names, elem->key);
        *(void**)((char*)g + 0x18) = r;
#endif
        StoreInArray0x8b0_020465c0((struct StoreStruct*)g, 0, data_ov004_021707d8.ptr->value);
        StoreInArray0x8b0_020465c0((struct StoreStruct*)g, 1, data_ov004_021707d8.ptr->quantity);
    }
    return 0;
}
