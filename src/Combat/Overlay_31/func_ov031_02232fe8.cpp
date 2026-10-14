#include <globaldefs.h>

struct Elem8_0223baa0;
struct ElemArray_0223baa0;
struct Obj0223bcc8;
union MenuHandle02232fe8 {
    void* raw;
    ElemArray_0223baa0* entries;
    Obj0223bcc8* flags;
};
struct MenuOwner02232fe8 {
    int field_0;
    MenuHandle02232fe8 primary[3];
    MenuHandle02232fe8 secondary[3];
};
struct MenuState02232fe8 {
    unsigned char index;
    unsigned char padding_1[3];
    MenuOwner02232fe8* owner;
};
extern MenuState02232fe8 data_ov031_02290cc0;
struct MenuValue02232fe8 {
    unsigned short value;
    unsigned short field_2;
};
extern MenuValue02232fe8 data_ov031_02249082[];
extern MenuValue02232fe8 data_ov031_02249084[];
signed char GetField1b_02237e9c();
extern "C" void func_ov031_02236878(int);
extern "C" void func_ov031_02236484(int);
extern "C" Elem8_0223baa0* func_ov031_0223baa0(ElemArray_0223baa0*, int);
extern "C" int func_ov031_0223bdb0(int, int, int);
extern "C" void func_ov031_0223bbd8(void*, int, int, int);
void SetEntryHalfword4Bits_0223bcc8(Obj0223bcc8*, int, int);
extern "C" void func_ov031_0223ba20(void*);
extern "C" void func_ov031_02237e58();
void SetField_022274c0_022274c0(int);
extern "C" void func_ov031_02233154();

// USA: func_ov031_02232fe8
extern "C" ARM void func_ov031_02232fe8() {
    int index = data_ov031_02290cc0.index - 4;
    switch (GetField1b_02237e9c()) {
    case 1:
        func_ov031_02236878(14);
        func_ov031_02236484(index);
        func_ov031_0223bdb0(0, 86, (int)func_ov031_0223baa0(data_ov031_02290cc0.owner->primary[index].entries, 0));
        func_ov031_0223bbd8(data_ov031_02290cc0.owner->primary[index].raw, -1,
            data_ov031_02249082[index].value, data_ov031_02249084[index].value);
        SetEntryHalfword4Bits_0223bcc8(data_ov031_02290cc0.owner->primary[index].flags, -1, 3);
        func_ov031_0223ba20(data_ov031_02290cc0.owner->secondary[index].raw);
        data_ov031_02290cc0.owner->secondary[index].raw = 0;
        break;
    case 0:
        func_ov031_02236878(7);
        func_ov031_0223bdb0(0, 17, (int)func_ov031_0223baa0(data_ov031_02290cc0.owner->secondary[index].entries, 0));
        func_ov031_0223bbd8(data_ov031_02290cc0.owner->secondary[index].raw, -1,
            data_ov031_02249082[index + 3].value, data_ov031_02249084[index + 3].value);
        SetEntryHalfword4Bits_0223bcc8(data_ov031_02290cc0.owner->secondary[index].flags, -1, 3);
        break;
    default:
        return;
    }
    func_ov031_02237e58();
    SetField_022274c0_022274c0((int)func_ov031_02233154);
}
