#include <globaldefs.h>

extern "C" void func_0202ae18(void);
extern "C" int func_0202c508(void);
void EnqueueEventTag90_021ca2a0(int a, int b);
void* GetData02108ea8(void);
struct Entry0207d9bc;
struct Entry0207d9bc* FindEntryByHalfword(struct Entry0207d9bc* arr, unsigned short key);
extern "C" void func_0207d7f4(void* arr, unsigned short key, int val, int flag, int a2, unsigned short b2, unsigned char c2);
extern "C" int func_ov017_0218b5b0(void);
extern "C" void* func_ov017_021b8478(void* obj);
extern "C" void func_ov017_021b88d0(void* node, int a, unsigned short key);

// JPN: func_ov017_021c5f3c
// USA: func_ov017_021c5a8c  (semantic: NotifyEntryAndMaybeUpdateNode_021c5a8c)
extern "C" ARM void func_ov017_021c5a8c(int a, int key) {
#if defined(jpn)
 enum {regionalOffset0=0x508};
#else
 enum {regionalOffset0=0x718};
#endif
    func_0202ae18();
    if (func_0202c508()) {
        EnqueueEventTag90_021ca2a0(a, (unsigned short)key);

        void* arr = GetData02108ea8();
        struct Entry0207d9bc* entry = FindEntryByHalfword((struct Entry0207d9bc*)arr, key);
        if (entry != NULL) {
            char* e = (char*)entry;
            func_0207d7f4(arr, key, a, 1, e[4], *(unsigned short*)(e + 2), *(unsigned char*)(e + 5));
        }

        void* base = (char*)func_ov017_0218b5b0() + 0x3000;
        void* node = *(void**)((char*)base + regionalOffset0);
        void* ret = func_ov017_021b8478(node);
        unsigned short val = *(unsigned short*)((char*)ret + 8);
        if (val == key) {
            func_ov017_021b88d0(node, a, key);
        }
    }
}
