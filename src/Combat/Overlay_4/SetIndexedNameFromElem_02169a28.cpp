#include <globaldefs.h>

int GetGlobalField0x1c020421a0(void);
extern "C" void* func_ov023_021f6524(void* ctx, int value);
struct TableA68;
extern "C" TableA68* func_ov004_02168b08(void* a, int key);
extern "C" int func_ov023_021f9bc8(char* obj);
extern "C" void __clear(void* buf, int len);
extern "C" void func_02046380(void* global);
extern "C" void func_02042764(const char* name, char* dest, int flag);
struct Obj02046574;
void SetIndexedName02046574(struct Obj02046574* obj, int index, char* str);
extern "C" void func_ov011_021848a0(void* obj, int val);

struct Grid02169a28 { char pad[0x5c]; short field5c; };
struct Elem02169a28 { char pad[6]; char field6; };
struct Data02169a28 { char pad[0x190]; char* field190; };
extern Data02169a28* data_ov004_02171030;

// USA: func_ov004_02169a28  (semantic: SetIndexedNameFromElem_02169a28)
extern "C" ARM int func_ov004_02169a28(void* self) {
    char* field190 = data_ov004_02171030->field190;
    if (!field190) return 0;

    void* g = (void*)GetGlobalField0x1c020421a0();
    Grid02169a28* grid = (Grid02169a28*)func_ov023_021f6524(self, 0x64);
    func_ov004_02168b08(self, 3);
    short field5c = grid->field5c;
    int areaIdx = func_ov023_021f9bc8((char*)grid);

    char buf[0x30];
    __clear(buf, 0x30);
    func_02046380(g);

    struct Elem02169a28* elem = (struct Elem02169a28*)(field190 + 4 + (areaIdx + field5c * 8) * 0x2c);
    func_02042764(&elem->field6, buf, 1);
    SetIndexedName02046574((struct Obj02046574*)g, 0, buf);
    func_ov011_021848a0(self, 0x51);
    return 0;
}
