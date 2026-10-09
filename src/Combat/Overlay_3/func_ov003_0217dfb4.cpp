#include <globaldefs.h>

struct Struct_0205c570;
struct Struct_0205d81c;
struct StructA0205d5d0;
struct Container020e0310;

struct ListWindow0217dfb4 {
    char pad0[0x68];
    int page;
};

struct ListMenu0217dfb4 {
    char pad0[0x14];
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
extern "C" int _Z26TryApplyElemFields0205d5d0P15StructA0205d5d0iiih(struct StructA0205d5d0* a, int b, int c, int d, unsigned char e);

extern const char data_ov003_02180c7f[];

// USA: func_ov003_0217dfb4
extern "C" ARM void func_ov003_0217dfb4(struct ListMenu0217dfb4* menu) {
    char buf[0x400];
    func_02012fe4();
    _Z26GetGlobalField0x1c020421a0v();
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
        unsigned char* elem = _Z23FindElementByC40205d81cP15Struct_0205d81ci((struct Struct_0205d81c*)menu->window, 0);
        if (elem != NULL) {
            SetField0xd8State(elem, 1);
            SetByte0xd9AndFlag0x2(elem, page);
            SetByte0xdaAndFlag0x2(elem, menu->field32);
        }
    }
    _Z26TryApplyElemFields0205d5d0P15StructA0205d5d0iiih((struct StructA0205d5d0*)menu->window, 0, (int)buf, 1, 0);
}
