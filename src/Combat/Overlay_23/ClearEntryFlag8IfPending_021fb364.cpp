#include <globaldefs.h>

extern "C" void* func_ov023_021f6880(void** list, int value);
extern "C" void* func_ov023_021fad18(void* obj);
void ClearBitRange_021f6c3c(void*, unsigned int, unsigned int, unsigned int);

struct Elem0205a3d0;
struct Container0205a3d0;
struct Elem0205a3d0* FindEntryByHalfword0205a3d0(struct Container0205a3d0* c, int key);

// USA: func_ov023_021fb364  (semantic: ClearEntryFlag8IfPending_021fb364)
extern "C" ARM void func_ov023_021fb364(void* obj, void** listHead) {
    void* node = func_ov023_021f6880(listHead, *(unsigned short*)((char*)obj + 0x20));
    if (node == 0) return;
    void* p = func_ov023_021fad18(node);
    ClearBitRange_021f6c3c((void*)listHead, *(unsigned char*)((char*)p + 0x50), *(unsigned short*)((char*)obj + 0x24), 1);
    struct Container0205a3d0* c = *(struct Container0205a3d0**)((char*)p + 0x3c);
    if (c == 0) return;
    struct Elem0205a3d0* e = FindEntryByHalfword0205a3d0(c, *(unsigned short*)((char*)obj + 0x22));
    if (e != 0) {
        *(unsigned char*)((char*)e + 0x15) &= ~8;
    }
}
