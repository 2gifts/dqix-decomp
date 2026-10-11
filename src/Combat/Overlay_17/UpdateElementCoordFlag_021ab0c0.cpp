// JPN: func_ov017_021ab920
#if defined(jpn)
enum { RegionOffset36 = 0x2a };
#else
enum { RegionOffset36 = 0x36 };
#endif

#include <globaldefs.h>

struct Ctx021ab0c0 {
    char pad0[0x18];
    void* p18;
    char pad1[0x44 - 0x1c];
    short* p44;
    char pad2[0x48 - 0x48];
    short s48;
    char pad3[0x4e - 0x4a];
    short s4e;
};

extern unsigned short data_02114e30;
extern unsigned char data_02114e54;

int TestFlag0SetAndFlag1Clear(unsigned short* obj, int mask);
void SelectCoordsByFlag0x24(unsigned char* obj, int* out1, int* out2);
int RunAndCheckFlagBit02080dd4(void* obj, int p1, int unused2, int unused3, unsigned char* outFlag, unsigned char extra);
extern "C" void func_020813ec(void* obj, int key);

// USA: func_ov017_021ab0c0
ARM int UpdateElementCoordFlag_021ab0c0(struct Ctx021ab0c0* ctx) {
    unsigned char flag = 0;
    if (TestFlag0SetAndFlag1Clear(&data_02114e30, 0x401)) {
        flag = 1;
    }
    if (*(unsigned char*)(&data_02114e54 + 0x55) != 0 && ctx->p44 != NULL) {
        void* obj = ctx->p18;
        int a, b;
        SelectCoordsByFlag0x24(&data_02114e54, &a, &b);
        ctx->s4e = *ctx->p44;
        int result = RunAndCheckFlagBit02080dd4(obj, ctx->s48, (short)a, (short)b, &flag, 1);
        if (result < 0) {
            return 0;
        }
        *ctx->p44 = (short)result;
        short cur = *ctx->p44;
        if (ctx->s4e != cur) {
            *(short*)((char*)obj + RegionOffset36) = cur;
            func_020813ec(obj, ctx->s48);
        }
    }
    return flag;
}
