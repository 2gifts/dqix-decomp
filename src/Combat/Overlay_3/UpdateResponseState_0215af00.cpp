#include <globaldefs.h>

#if defined(jpn)
enum { kRegionValue998_868 = 0x868 };
#else
enum { kRegionValue998_868 = 0x998 };
#endif

void* GetGlobalField0x1c020421a0(void);
struct Entry_0205d6a0;
void ResetEntryList0205d6a0(Entry_0205d6a0*, int);
struct Container020e0310;
void* GetFieldByKey020e0434(Container020e0310*, int);
extern "C" void func_ov003_02159250(void*, void*);
extern "C" void func_ov017_021d243c(int);
extern "C" int func_ov017_0218b5b0(void);
extern "C" void func_ov017_02191108(int, int, int, int, int);

// USA: func_ov003_0215af00
ARM void UpdateResponseState_0215af00(void* self) {
    unsigned char* s = (unsigned char*)self;
    unsigned char* g = (unsigned char*)GetGlobalField0x1c020421a0();
    unsigned char state = *(unsigned char*)(s + 0x580);

    if (state == 0) {
        ResetEntryList0205d6a0((Entry_0205d6a0*)(s + 0xf4), 1);
        void* val = GetFieldByKey020e0434((Container020e0310*)(s + 0x64), 0x442);
        func_ov003_02159250(self, val);
        *(unsigned char*)(s + 0x580) = *(unsigned char*)(s + 0x580) + 1;
    }

    if (!(state == 1 && *(int*)(g + kRegionValue998_868) == 0)) return;

    func_ov017_021d243c(0);
    int r = func_ov017_0218b5b0();
    func_ov017_02191108(r, 1, 1, 1, 1);

    *(unsigned char*)(s + 0x588) = 0xb;
    *(unsigned char*)(s + 0x580) = 0;
}
