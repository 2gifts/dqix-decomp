#include <globaldefs.h>

struct MainCtxHolder0222f6f8 {
    unsigned char pad0_0222f6f8;
    unsigned char field1_0222f6f8;
    unsigned char pad2_0222f6f8[6];
    struct Ctx0222f6f8* ctx;
};

struct Ctx0222f6f8 {
    void* field0;
    void* pad4;
    void* field8;
    void* arrC[2];
    void* pad14;
    void* arr18[7];
    void* field34;
    void* pad38;
    void* field3c;
    unsigned char field40;
};

extern struct MainCtxHolder0222f6f8 data_ov031_02290ca0;
extern int data_ov031_0224bb64;
extern void* data_ov031_02290ca8;

extern "C" int func_ov031_0223c054(int);
ARM int TailCallForward_0223e2e0(int, void*);
extern "C" int func_ov031_0223da58(void* obj);
extern "C" void func_ov031_022238cc(void);
void* TailCallElemAtIndex30_0223c7c4(int idx);
extern "C" int func_ov031_02223440(void);
extern "C" void func_ov031_02234f08(void);
extern "C" void func_ov031_0223b710(void* a);
extern "C" void func_ov031_022234d8(int a0, void (*cb)(int, int, unsigned int));
extern "C" void func_ov031_0223cbbc(int channel, int mask);
extern "C" unsigned int func_ov031_0223cf70(void** a);
extern "C" void func_ov031_02235194(void);

extern "C" void LoadToMainObjStandardPalette(int, int, unsigned int);
extern "C" int func_ov031_0221b158(void* p);
char* GetOffset400_02235c70(void);
extern "C" void func_ov031_02236094(int a);
extern "C" void* VectorizedMemset(void* dst, int val, int n);
void SetField181c_0222750c(int, int);
void SetField1014_022274d0(int, int);
void SetField_022274c0_022274c0(int);
extern "C" void func_ov031_0222cbe0(void);
extern "C" void func_ov031_0222d720(void);
extern "C" void func_ov031_02233a00(void);
extern "C" void func_ov031_02230f00(void);
extern "C" void func_ov031_02232508(void);
extern "C" void func_ov031_02233248(void);

// USA: func_ov031_0222f6f8
extern "C" ARM void func_ov031_0222f6f8(void) {
    if (func_ov031_0223c054(1) != 0) return;
    if (func_ov031_0223c054(0) != 0) return;

    TailCallForward_0223e2e0(0, data_ov031_02290ca0.ctx->field0);
    TailCallForward_0223e2e0(1, data_ov031_02290ca0.ctx->field3c);

    int i = 0;
    do {
        void* p = data_ov031_02290ca0.ctx->arr18[i];
        func_ov031_0223da58(p);
        i++;
    } while (i < 7);
    if (data_ov031_02290ca0.ctx->field34 != 0) {
        func_ov031_0223da58(data_ov031_02290ca0.ctx->field34);
    }

    func_ov031_02235194();
    TailCallElemAtIndex30_0223c7c4(0);
    func_ov031_022238cc();

    if (data_ov031_02290ca0.ctx->field40 != 0xc) func_ov031_02223440();

    func_ov031_02234f08();
    func_ov031_0223b710(data_ov031_02290ca0.ctx->field8);

    int j = 0;
    do {
        void* p = data_ov031_02290ca0.ctx->arrC[j];
        func_ov031_0223b710(p);
        j++;
    } while (j < 2);

    func_ov031_022234d8((int)&data_ov031_0224bb64, LoadToMainObjStandardPalette);

    func_ov031_0223cbbc(1, 1);
    func_ov031_0223cbbc(0, 0x1d);

    *(volatile unsigned int*)0x4000010 = 0;
    *(volatile unsigned int*)0x4000018 = 0;
    *(volatile unsigned short*)0x400000c = (*(volatile unsigned short*)0x400000c & 0x43) | 0xe10;

    int flag = 0;
    switch (data_ov031_02290ca0.ctx->field40) {
    case 0:
    case 1:
        SetField181c_0222750c(data_ov031_02290ca0.ctx->field40, flag);
        SetField1014_022274d0(2, 0);
        SetField_022274c0_022274c0((int)func_ov031_0222cbe0);
        break;
    case 4: case 5: case 6: case 9: case 10: {
        unsigned int v = data_ov031_02290ca0.ctx->field40;
        int r4 = v - 4;
        if (v >= 9) r4 -= 2;
        SetField1014_022274d0(2, 0);
        SetField181c_0222750c(r4, 0);
        SetField_022274c0_022274c0((int)func_ov031_0222d720);
        break;
    }
    case 11: {
        unsigned char* base = (unsigned char*)GetOffset400_02235c70();
        int bits = func_ov031_0221b158(base + 0xf0);
        base[0xd0] = (unsigned char)bits;
        if (base[0xf5] != 0) {
            VectorizedMemset(base + 0xc0, 0, 4);
            VectorizedMemset(base + 0xc4, 0, 4);
            VectorizedMemset(base + 0xf0, 0, 4);
            base[0xd0] = 0;
        }
        if (base[0xf6] != 0) {
            VectorizedMemset(base + 0xc8, 0, 8);
        }
        SetField1014_022274d0(2, 0);
        SetField181c_0222750c(0, 0);
        SetField_022274c0_022274c0((int)func_ov031_02233a00);
        break;
    }
    case 12:
        SetField1014_022274d0(flag, flag);
        SetField_022274c0_022274c0((int)func_ov031_02230f00);
        break;
    case 13:
        if (data_ov031_02290ca0.field1_0222f6f8 == 0) {
            flag = 1;
            SetField1014_022274d0(2, flag);
            SetField_022274c0_022274c0((int)func_ov031_02232508);
        } else {
            func_ov031_02236094(((unsigned char*)GetOffset400_02235c70())[0xf4]);
            flag = 1;
            SetField1014_022274d0(0, flag);
            SetField_022274c0_022274c0((int)func_ov031_02233248);
        }
        break;
    }

    func_ov031_0223cf70((void**)&data_ov031_02290ca8);
}
