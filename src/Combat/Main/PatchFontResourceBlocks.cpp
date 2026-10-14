#include <globaldefs.h>

// USA: func_020b291c
ARM void PatchFontResourceBlocks_020b291c(void* base) {
    char* entry = (char*)base + *(unsigned short*)((char*)base + 0xc);
    unsigned short count = *(unsigned short*)((char*)base + 0xe);
    int i = 0;

    if ((int)count <= 0)
        return;

    do {
        unsigned int magic = *(unsigned int*)entry;
        switch (magic) {
        case 0x46494e46: {
            int* p10 = (int*)(entry + 0x10);
            *p10 = *p10 + (int)base;
            int* p14 = (int*)(entry + 0x14);
            if (*p14 != 0)
                *p14 = *p14 + (int)base;
            int* p18 = (int*)(entry + 0x18);
            if (*p18 != 0)
                *p18 = *p18 + (int)base;
            break;
        }
        case 0x43574448: {
            int* p = (int*)(entry + 0xc);
            if (*p != 0)
                *p = *p + (int)base;
            break;
        }
        case 0x434d4150: {
            int* p = (int*)(entry + 0x10);
            if (*p != 0)
                *p = *p + (int)base;
            break;
        }
        case 0x43474c50:
            break;
        }

        i = i + 1;
        entry = entry + *(int*)(entry + 4);
        count = *(unsigned short*)((char*)base + 0xe);
    } while (i < count);
}
