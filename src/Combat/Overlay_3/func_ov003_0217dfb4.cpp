#include <globaldefs.h>
#if defined(jpn)
enum { kMenuPrefix=0x10 };
extern "C" void func_02046380(void*);
struct StoreStruct;
void StoreInArray0x8b0(StoreStruct*,int,int);
void SetByteInRange(unsigned char*,int,unsigned char);
void SetByteAtIndex(unsigned char*,int,unsigned char);
extern "C" void func_02042428(char*, int);
#else
enum { kMenuPrefix=0x14 };
#endif

struct Struct_0205c570;
struct Struct_0205d81c;
struct StructA0205d5d0;
struct Container020e0310;

struct ListWindow0217dfb4 {
    char pad0[0x68];
    int page;
};

struct ListMenu0217dfb4 {
    char pad0[kMenuPrefix];
    int mode;
    unsigned char items[0x30 - 0x18];
    unsigned char itemCount;
    char pad31;
    unsigned char field32;
    char pad33[0x90 - 0x33];
    struct ListWindow0217dfb4* window;
    char pad94[0xcc - 0x94];
    char names[4];
};

extern "C" void* func_02012fe4(void);
extern "C" int _Z26GetGlobalField0x1c020421a0v();
extern "C" void __clear(void* buf, int n);
extern "C" int _Z26GetActiveScaledSum0205d794P15Struct_0205c570(struct Struct_0205c570* s);
extern "C" int _Z22AppendFrameTag02041c08Pciiiii(char* dst, int a1, int a2, int a3, int a4, int a5);
extern "C" int _Z21GetFieldByKey020e0434P17Container020e0310i(struct Container020e0310* c, int key);
int AppendNameTag(char* dst, int n, const char* name);
extern "C" int _Z20AppendString02042058PcPKc(char* dst, const char* src);
extern "C" unsigned char* _Z23FindElementByC40205d81cP15Struct_0205d81ci(struct Struct_0205d81c* s, int key);
void SetField0xd8State(unsigned char* elem, int state);
void SetByte0xd9AndFlag0x2(unsigned char* elem, unsigned char value);
void SetByte0xdaAndFlag0x2(unsigned char* elem, int value);
#if defined(jpn)
extern "C" int _Z26TryApplyElemFields0205d5d0P15StructA0205d5d0iiih(struct StructA0205d5d0*,int,int,int);
#else
extern "C" int _Z26TryApplyElemFields0205d5d0P15StructA0205d5d0iiih(struct StructA0205d5d0* a, int b, int c, int d, unsigned char e);
#endif

extern const char data_ov003_02180c7f[];

// JPN: func_ov003_0217cc68
// USA: func_ov003_0217dfb4
extern "C" ARM void func_ov003_0217dfb4(struct ListMenu0217dfb4* menu) {
    char buf[0x400];
    func_02012fe4();
#if defined(jpn)
    int global = _Z26GetGlobalField0x1c020421a0v();
#else
    _Z26GetGlobalField0x1c020421a0v();
#endif
    __clear(buf, 0x400);
    int end;
    int i;
    int page = menu->window->page;
    end = (page + 1) * 6;
    if (end > menu->itemCount) {
        end = menu->itemCount;
    }
    if (menu->mode == 2) {
        _Z22AppendFrameTag02041c08Pciiiii(buf, _Z26GetActiveScaledSum0205d794P15Struct_0205c570((struct Struct_0205c570*)menu->window) % 6, 8, 5, 5, 5);
    }
    for (i = page * 6; i < end; i++) {
        const char* name = (const char*)_Z21GetFieldByKey020e0434P17Container020e0310i((struct Container020e0310*)menu->names, (short)(menu->items[i] + 100));
        AppendNameTag(buf, i % 6, name);
        if (i != end - 1) {
            _Z20AppendString02042058PcPKc(buf, data_ov003_02180c7f);
        }
    }
    if (menu->field32 > 1) {
#if defined(jpn)
        func_02046380((void*)global);
        StoreInArray0x8b0((StoreStruct*)global, 0, page + 1);
        StoreInArray0x8b0((StoreStruct*)global, 1, menu->field32);
        SetByteInRange((unsigned char*)global, 0, 2);
        SetByteInRange((unsigned char*)global, 1, 2);
        SetByteAtIndex((unsigned char*)global, 0, 1);
        SetByteAtIndex((unsigned char*)global, 1, 0);
        func_02042428(buf, 8);
        _Z20AppendString02042058PcPKc(buf, (const char*)_Z21GetFieldByKey020e0434P17Container020e0310i((Container020e0310*)menu->names, 0xc8));
#else
        unsigned char* elem = _Z23FindElementByC40205d81cP15Struct_0205d81ci((struct Struct_0205d81c*)menu->window, 0);
        if (elem != NULL) {
            SetField0xd8State(elem, 1);
            SetByte0xd9AndFlag0x2(elem, page);
            SetByte0xdaAndFlag0x2(elem, menu->field32);
        }
#endif
    }
#if defined(jpn)
    _Z26TryApplyElemFields0205d5d0P15StructA0205d5d0iiih((struct StructA0205d5d0*)menu->window, 0, (int)buf, 1);
#else
    _Z26TryApplyElemFields0205d5d0P15StructA0205d5d0iiih((struct StructA0205d5d0*)menu->window, 0, (int)buf, 1, 0);
#endif
}
