// JPN: func_ov025_021dce88
#if defined(jpn)
enum { RegionOffset2a8 = 0x224, RegionOffset4104 = 0x40c0, RegionOffset40b8 = 0x4074, RegionOffset448 = 0x488 };
#else
enum { RegionOffset2a8 = 0x2a8, RegionOffset4104 = 0x4104, RegionOffset40b8 = 0x40b8, RegionOffset448 = 0x448 };
#endif

#include <globaldefs.h>

void* GetSlotPtr02160f20(void* obj);
extern "C" void func_ov025_021e9778(void* obj);
int CheckField4ThenCheck021ed2f4_021e9528(char* obj);
extern "C" int func_ov025_021dc940(void* obj);
extern "C" void func_ov025_021e9558(void* obj);
ARM void IncrementCounterAndReset_021def30(unsigned char* obj);

struct ListNode02160094_dc590 {
    char pad0[0x20];
    unsigned short id;
};

struct FlagsByte0xb_dc590 {
    unsigned char bit0 : 1;
    unsigned char bit1 : 1;
    unsigned char bit2 : 1;
    unsigned char bit3 : 1;
    unsigned char bit4 : 1;
    unsigned char bit5 : 1;
    unsigned char bit6 : 1;
    unsigned char bit7 : 1;
};

struct Slot021dc590 {
    char pad0[0xb];
    struct FlagsByte0xb_dc590 flags;
    char pad1[4];
    struct ListNode02160094_dc590* node;
};

// USA: func_ov025_021dc590  (semantic: UpdateSlotEntryAndFlag_021dc590)
extern "C" ARM void func_ov025_021dc590(void* obj) {
    struct Slot021dc590* slot = (struct Slot021dc590*)GetSlotPtr02160f20(obj);
    func_ov025_021e9778((char*)obj + RegionOffset2a8);
    if (!CheckField4ThenCheck021ed2f4_021e9528((char*)obj + RegionOffset2a8)) {
        return;
    }
    if (!func_ov025_021dc940(obj)) {
        return;
    }
    func_ov025_021e9558((char*)obj + RegionOffset2a8);

    struct ListNode02160094_dc590* node = slot->node;
    if (node != NULL) {
        int id = node->id;
        int flag1 = (id >= 0 && id <= 3) ? 1 : 0;
        if (flag1) {
            void* result;
            int flag2 = (id >= 0 && id <= 3) ? 1 : 0;
            if (flag2) {
                for (int i = 0; i < 4; i++) {
                    int cur = *(int*)((char*)obj + i * RegionOffset448 + RegionOffset4104);
                    if (id == cur) {
                        result = (char*)obj + RegionOffset40b8 + i * RegionOffset448;
                        goto found;
                    }
                }
            }
            result = 0;
            found:
            if (result != 0) {
                if (slot->flags.bit2 == 0) {
                    signed char off = *(signed char*)((char*)result + 0x18);
                    *((unsigned char*)result + off + 0x10) = 0x66;
                }
            }
        }
    }
    IncrementCounterAndReset_021def30((unsigned char*)obj);
}
