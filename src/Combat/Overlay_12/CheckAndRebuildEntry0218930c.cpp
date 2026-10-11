#include <globaldefs.h>

#if defined(jpn)
#define func_ov012_0218930c func_ov012_02189be8
#endif

struct Struct0205d888;
void* GetLastEntry0205d888(struct Struct0205d888* p);
struct Entry_0205d6a0;
void ResetEntryList0205d6a0(struct Entry_0205d6a0* a, int flag);
extern "C" void func_ov023_021e6e60(void* self);
extern "C" void func_ov012_02185bf0(void* self, int a1, int a2);

struct Pair0218af88 { unsigned char a; unsigned char b; };
extern struct Pair0218af88 data_ov012_0218af88[];

// USA: func_ov012_0218930c  (semantic: CheckAndRebuildEntry0218930c)
extern "C" ARM void func_ov012_0218930c(char* self, int flag) {
    void* last = GetLastEntry0205d888((struct Struct0205d888*)(self + 0xac));
    if (last != 0 && flag == 0) {
        int i;
        for (i = 0; i < 5; i++) {
            unsigned char tableVal = data_ov012_0218af88[i].a;
            unsigned char entryVal = *((unsigned char*)last + 0xc4);
            if (tableVal == entryVal) {
                ResetEntryList0205d6a0((struct Entry_0205d6a0*)(self + 0xac), 0);
                break;
            }
        }
    }
    ResetEntryList0205d6a0((struct Entry_0205d6a0*)(self + 0xac), 0);
    last = GetLastEntry0205d888((struct Struct0205d888*)(self + 0xac));
    if (last == 0) return;
    self[0x1371] = *((unsigned char*)last + 0xc4);
    func_ov023_021e6e60(self);
    func_ov012_02185bf0(self, *(unsigned char*)(self + 0x1371), 0);
}
