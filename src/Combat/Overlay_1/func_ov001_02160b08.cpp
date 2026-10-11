#include <globaldefs.h>

extern "C" int func_ov017_021d60f4(void*);
extern "C" void* func_02012fe4(void);

extern "C" void func_0201874c(void* list, void* obj);
void* GetPointerFromArray0x3c(unsigned char* obj, unsigned int index);

struct Node02160b08 {
    char pad0[0x2c];
    unsigned char idA;   // +0x2c
    unsigned char idB;   // +0x2d
    unsigned short low4 : 4;
    unsigned short upper12 : 12; // +0x2e
    char pad30[0x70 - 0x30];
    Node02160b08* next; // +0x70
};

// USA: func_ov001_02160b08
extern "C" ARM int func_ov001_02160b08(void* self, int mode) {
#if defined(jpn)
    enum { substructureOffset = 0x8c };
#else
    enum { substructureOffset = 0x6c };
#endif
    int a = func_ov017_021d60f4(self);
    int b = func_ov017_021d60f4((char*)self + 0x8);
    if (mode > 2) {
        func_ov017_021d60f4((char*)self + 0x10);
    }
    void* list = func_02012fe4();
    Node02160b08* node = (Node02160b08*)GetPointerFromArray0x3c((unsigned char*)list + substructureOffset, 2);
    while (node != NULL) {
        if ((node->upper12 & 1) && node->idA == a && node->idB == b) {
            node->upper12 &= ~0x200;
            func_0201874c(list, node);
        }
        node = node->next;
    }
    return 1;
}
