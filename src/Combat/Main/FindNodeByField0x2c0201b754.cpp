#include <globaldefs.h>

#if defined(jpn)
enum { ContainerOffset = 0x8c };
#else
enum { ContainerOffset = 0x6c };
#endif
void* GetPointerFromArray0x3c(unsigned char*, unsigned int);

struct Node0201b754 {
    unsigned char pad0[0x2c];
    unsigned short f2c;
    unsigned char pad2e[0x42];
    struct Node0201b754* f70;
};

// USA: func_0201b754
ARM struct Node0201b754* FindNodeByField0x2c0201b754(void* obj, int key) {
    struct Node0201b754* node = (struct Node0201b754*)GetPointerFromArray0x3c((unsigned char*)((char*)obj + ContainerOffset), (unsigned int)(0xa));
    while (node != 0) {
        if (node->f2c == key) return node;
        node = node->f70;
    }
    return 0;
}
