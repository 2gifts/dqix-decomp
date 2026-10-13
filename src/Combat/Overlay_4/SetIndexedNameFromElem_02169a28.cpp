#include <globaldefs.h>

#if defined(jpn)
#define func_ov023_021f6524 func_ov004_02168f08
#define func_ov004_02168b08 func_ov004_02169040
#endif

int GetGlobalField0x1c020421a0(void);
extern "C" void* func_ov023_021f6524(void* ctx, int value);
struct TableA68;
extern "C" TableA68* func_ov004_02168b08(void* a, int key);
extern "C" int func_ov023_021f9bc8(char* obj);
extern "C" void __clear(void* buf, int len);
extern "C" void func_02046380(void* global);
extern "C" void func_02042764(unsigned char* name, char* dest, int flag);
struct Obj02046574;
void SetIndexedName02046574(struct Obj02046574* obj, int index, char* str);
extern "C" void func_ov011_021848a0(void* obj, int val);

extern void* data_ov004_02171030;

// USA: func_ov004_02169a28  (semantic: SetIndexedNameFromElem_02169a28)
// KEEP-NAME
extern "C" ARM int func_ov004_02169a28(void* self) {
#if defined(jpn)
    char* records = *(char**)((char*)data_ov004_02171030 + 0x10);
#else
    char* records = *(char**)((char*)data_ov004_02171030 + 0x190);
#endif
    if (!records) return 0;

    void* g = (void*)GetGlobalField0x1c020421a0();
    char* grid = (char*)func_ov023_021f6524(self, 0x64);
    func_ov004_02168b08(self, 3);
    short page = *(short*)(grid + 0x5c);
    int areaIdx = func_ov023_021f9bc8(grid);

#if !defined(jpn)
    char buf[0x30];
    __clear(buf, 0x30);
#endif
    func_02046380(g);

    char (*entries)[0x2c] = (char (*)[0x2c])(records + 4);
    char* name = entries[areaIdx + page * 8] + 6;
#if defined(jpn)
    SetIndexedName02046574((struct Obj02046574*)g, 0, name);
#else
    func_02042764((unsigned char*)name, buf, 1);
    SetIndexedName02046574((struct Obj02046574*)g, 0, buf);
#endif
    func_ov011_021848a0(self, 0x51);
    return 0;
}
