#include <globaldefs.h>

#if defined(jpn)
#define func_ov013_021864f0 func_ov013_02187820
#endif

int GetGlobalField0x1c020421a0();
int TestFlag0SetAndFlag1Clear(unsigned short* obj, int mask);
int CheckByteSetAndByteClear(unsigned char* obj);
void InvalidateBattlerField0x18(unsigned char* obj);
void ReinitController02043204(char* obj);

extern "C" void func_ov013_02186c64(void* obj, int a, int b);
extern "C" void func_ov013_02185cc0(void* obj);

extern unsigned short data_02114e30;
extern char data_02114e54;

// USA: func_ov013_021864f0  (semantic: RefreshTagAndReinit021864f0)
extern "C" ARM void func_ov013_021864f0(void* obj) {
    unsigned char* o = (unsigned char*)obj;
    o[0x6bc] &= ~1;
    if (o[0x63f] != 0) o[0x639] = 1;

    int g = GetGlobalField0x1c020421a0();
    unsigned char* gp = (unsigned char*)g;
    gp[0x1000 + 0x9be] = 1;

    if (!TestFlag0SetAndFlag1Clear(&data_02114e30, 0x613) && !CheckByteSetAndByteClear((unsigned char*)&data_02114e54)) {
        return;
    }

    o[0x63c] = 1;
    InvalidateBattlerField0x18((unsigned char*)&data_02114e30);
    ReinitController02043204((char*)gp);
    o[0x639] = 0;
    func_ov013_02186c64(obj, 0, 0);
    func_ov013_02185cc0(obj);
}
