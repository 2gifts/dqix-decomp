#if defined(jpn)
#define R(j,u) (j)
#define func_0202920c func_02028dc4
#define func_02029988 func_02029540
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

extern "C" int func_ov015_02190c98(void* obj);
void ClearBuffer02029060();
void SetField402028d58(int value);
extern "C" void func_02029988(void* p, int flag);
extern "C" void func_0202920c(int a, int b, int c, int d, int e);
void FlushBuffer02029088();
void ProcessRingJobs020bbcb4();
extern "C" void func_ov015_02190acc(void* obj);

struct Obj02190428 {
    char pad0[0x328];
    unsigned short field328;
    char pad1[0x330 - 0x328 - 2];
    unsigned char field330;
    char pad2[0x334 - 0x330 - 1];
    unsigned char field334;
    char pad3[0x348 - 0x334 - 1];
    int field348;
    float field34c;
    unsigned char field350;
    char pad4[0x354 - 0x350 - 1];
    int field354;
};

// USA: func_ov015_02190428  (semantic: RunCombatantUpdateAndFlush_02190428)
extern "C" ARM void func_ov015_02190428(struct Obj02190428* obj) {
    if (!func_ov015_02190c98(obj)) return;
    ClearBuffer02029060();
    if (obj->field330 != 2) obj->field350 = 0;
    SetField402028d58(obj->field354);
    func_02029988((char*)obj + 0x2c4, 1);
    obj->field334 = 0;
    SetField402028d58(0);
    func_0202920c(0xf, 0x81, 0x17, 6, 0x9e);
    func_0202920c(1, 0x82, 0x18, 4, 0x9c);
    int v = (int)(24.0f + obj->field34c * (float)(int)obj->field328);
    func_0202920c(0xf, 0x82, v, 4, obj->field348);
    func_ov015_02190acc(obj);
    FlushBuffer02029088();
    ProcessRingJobs020bbcb4();
}
