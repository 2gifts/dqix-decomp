#include <globaldefs.h>

struct B190Outer;
int GetBits12To15Clamped_0205af18(int unused, struct B190Outer* obj);
void* GetEntryPtr_021fa854(char* obj, unsigned int idx);
void ClearBit_021f6e34(void* obj, int idx, unsigned int bit);
void EmptyDestructor0205a494(void* obj);
int GetGlobalField0x1c020421a0();
extern "C" void func_ov023_021f6d9c(void* param2, void* field78);

// USA: func_ov023_021fa7d4  (semantic: ClearEntriesAndSetGlobalFlags_021fa7d4)
extern "C" ARM void func_ov023_021fa7d4(void* obj, void* param2) {
    func_ov023_021f6d9c(param2, (char*)obj + 0x78);
    for (unsigned int i = 0; i < *(unsigned short*)((char*)obj + 0x72); i++) {
        void* entry = GetEntryPtr_021fa854((char*)obj + 0x24, (unsigned short)i);
        if (entry != 0) {
            int bits = GetBits12To15Clamped_0205af18((int)((char*)obj + 0x24), (struct B190Outer*)entry);
            unsigned char byteVal = *(unsigned char*)((char*)obj + 0x74);
            ClearBit_021f6e34(param2, byteVal, bits);
        }
    }
    EmptyDestructor0205a494((char*)obj + 0x24);
    char* global = (char*)GetGlobalField0x1c020421a0();
    *(int*)(global + 0x2d8) = 0;
    *(unsigned char*)(global + 0x2e6) = 1;
}
