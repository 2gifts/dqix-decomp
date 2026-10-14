#include <globaldefs.h>
#if defined(jpn)
#define IS_JPN 1
#else
#define IS_JPN 0
#endif
#if defined(jpn)
#define func_02094654 func_02094f3c
#define func_020947f0 func_020950d8
#endif

extern "C" int func_ov017_0218b5b0(void);
extern "C" void* func_0202ae18(void);
extern "C" void func_02094654(void* obj);
extern "C" void func_020947f0(void* obj);

int IsChannelValueZero0203b5e0(void* obj, int sel);
int CheckField0NonZero_0202b7d8(int* obj);

struct ListHead02046b60;
int ListContainsId(struct ListHead02046b60* list, int id);

void* GetDataPtr02114e04_020d6c00(void);

struct FlagWord02046708;
int TestFlags02046708(struct FlagWord02046708* word, unsigned int mask);

struct FlagBits02093f68 {
    char pad[(IS_JPN ? 0x139 : 0x3c9)];
    bool flag1 : 1;
};

// USA: func_02093f68
ARM void UpdateChannelStateIfEligible02093f68(char* obj) {
    int base1 = func_ov017_0218b5b0();
    int chVal = *(int*)(base1 + (IS_JPN ? 0x34ec : 0x36fc));

    if (IsChannelValueZero0203b5e0((void*)base1, 1)) return;
    if (((unsigned char*)obj)[(IS_JPN ? 0x13d : 0x3cd)] & 2) return;

    int base2 = func_ov017_0218b5b0();

    if (CheckField0NonZero_0202b7d8((int*)func_0202ae18())
        || *(int*)(base2 + (IS_JPN ? 0x41e4 : 0x4494))
        || ListContainsId((struct ListHead02046b60*)chVal, 0x26)) {
        func_02094654(obj);
    }

    if (TestFlags02046708((struct FlagWord02046708*)GetDataPtr02114e04_020d6c00(), 0x8020)) return;
    if (!((struct FlagBits02093f68*)obj)->flag1) return;
    if (obj[(IS_JPN ? 0x13b : 0x3cb)] <= 0) return;

    unsigned char v = obj[(IS_JPN ? 0x13d : 0x3cd)];
    if (v & 1) return;
    if (!(v & 4)) return;

    func_020947f0(obj);
}
