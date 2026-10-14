#include <globaldefs.h>

struct Entry0222c1b8 {
    unsigned char pad_0[0x28];
    unsigned char kind;
    unsigned char field_0x29;
};
struct Manager0222c1b8 {
    Entry0222c1b8* entries;
    void* field_0x4;
    void* field_0x8;
    void* field_0xc;
    void* first[5];
    void* second[5];
    unsigned char pad_0x38[4];
    void* field_0x3c;
    unsigned char pad_0x40[0x12];
    unsigned char selected;
    unsigned char pad_0x53;
    unsigned char field_0x54;
};
struct Context0222c1b8 {
    unsigned char field_0;
    unsigned char pad_1[3];
    Manager0222c1b8* manager;
};
struct Block0222c1b8 {
    unsigned char pad_0[0xf4];
    unsigned char field_0xf4;
};
extern Context0222c1b8 data_ov031_02290c8c;
extern unsigned char data_ov031_02290c90;
extern "C" int func_ov031_0223c054(int);
int IsField19ZeroOrNull_02222e54();
void TailCallForward_0223e2e0(int, void*);
extern "C" void func_ov031_0223da58(void*);
extern "C" void func_ov031_0223c760(void*);
extern "C" void func_ov031_02235194();
extern "C" void func_ov031_022238cc();
extern "C" void func_ov031_02223440();
extern "C" void func_ov031_02234f08();
extern "C" void func_ov031_0223b710(void*);
extern "C" void func_ov031_0223cbbc(int, int);
extern "C" void func_ov031_022357b4();
void* GetOffset400_02235c70();
extern "C" void func_ov031_02236094(int);
void SetField1014_022274d0(int, int);
void SetField181c_0222750c(int, int);
void SetField_022274c0_022274c0(int);
void CopyBlockAndClearFlag_02235cac(void*);
extern "C" void func_ov031_02233248();
void ResetAndInit_02232024();
extern "C" void func_ov031_0222cbe0();
void Setup022340c0();
extern "C" void func_ov031_0223cf70(void*);
#define REG_SCROLL (*(volatile unsigned int*)0x04000010)
#define REG_SCROLL_SUB (*(volatile unsigned int*)0x04000018)

// USA: func_ov031_0222c1b8
extern "C" ARM void func_ov031_0222c1b8() {
    if (func_ov031_0223c054(1) != 0) return;
    if (func_ov031_0223c054(0) != 0) return;
    if (IsField19ZeroOrNull_02222e54() == 0) return;
    TailCallForward_0223e2e0(1, data_ov031_02290c8c.manager->field_0x3c);
    int i = 0;
    do {
        if (data_ov031_02290c8c.manager->first[i]) func_ov031_0223da58(data_ov031_02290c8c.manager->first[i]);
        if (data_ov031_02290c8c.manager->second[i]) func_ov031_0223da58(data_ov031_02290c8c.manager->second[i]);
    } while (++i < 5);
    func_ov031_0223c760(data_ov031_02290c8c.manager->field_0xc);
    func_ov031_02235194();
    func_ov031_022238cc();
    func_ov031_02223440();
    func_ov031_02234f08();
    func_ov031_0223b710(data_ov031_02290c8c.manager->field_0x4);
    func_ov031_0223b710(data_ov031_02290c8c.manager->field_0x8);
    func_ov031_0223cbbc(1, 1);
    func_ov031_0223cbbc(0, 0x1d);
    REG_SCROLL = 0;
    REG_SCROLL_SUB = 0;
    if (data_ov031_02290c8c.manager->field_0x54 == 0) {
        func_ov031_022357b4();
        func_ov031_02236094(((Block0222c1b8*)GetOffset400_02235c70())->field_0xf4);
        SetField1014_022274d0(2, 0);
        SetField_022274c0_022274c0((int)func_ov031_02233248);
    } else if (data_ov031_02290c8c.field_0 == 4) {
        func_ov031_022357b4();
        SetField1014_022274d0(0, 1);
        SetField_022274c0_022274c0((int)ResetAndInit_02232024);
    } else {
        CopyBlockAndClearFlag_02235cac(&data_ov031_02290c8c.manager->entries[data_ov031_02290c8c.manager->selected]);
        SetField1014_022274d0(0, 0);
        if (data_ov031_02290c8c.manager->entries[data_ov031_02290c8c.manager->selected].kind != 0) {
            SetField1014_022274d0(0, 1);
            SetField181c_0222750c(1, 1);
            SetField_022274c0_022274c0((int)func_ov031_0222cbe0);
        } else {
            SetField1014_022274d0(0, 1);
            SetField181c_0222750c(0, 1);
            SetField_022274c0_022274c0((int)Setup022340c0);
        }
    }
    func_ov031_0223cf70(&data_ov031_02290c90);
}
