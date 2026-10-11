#include <globaldefs.h>

#if defined(jpn)
enum { kElementsOffset = 0x8c };
#else
enum { kElementsOffset = 0x6c };
#endif


extern "C" void* func_02012fe4(void);
void* GetElementStride0x74(unsigned char* obj, int index);
void SetOrClearElemFlag0x4ByKeys(int mode, int key1, short key2);
void SetFlagBitAndNotifyOverlay17(int param0, int param1);

struct Elem020ae730 {
    unsigned char pad[0x28];
    unsigned int flags28;
};

// USA: func_020ae730
ARM void SetElemFlag8IfOverlayActive020ae730(int a) {
    if (*(unsigned short*)func_02012fe4() != 0x1edd) {
        return;
    }
    unsigned char* base = (unsigned char*)func_02012fe4();
    struct Elem020ae730* p = (struct Elem020ae730*)GetElementStride0x74(base + kElementsOffset, 3);
    struct Elem020ae730* q = (struct Elem020ae730*)GetElementStride0x74(base + kElementsOffset, 4);
    if (p == NULL || q == NULL) {
        return;
    }
    if (a != 0) {
        p->flags28 &= ~8;
        q->flags28 &= ~8;
    } else {
        p->flags28 |= 8;
        q->flags28 |= 8;
    }
    SetOrClearElemFlag0x4ByKeys(a, 0, 0x10);
    SetFlagBitAndNotifyOverlay17(6, a != 0);
}
