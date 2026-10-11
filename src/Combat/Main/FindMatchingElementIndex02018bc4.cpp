#include <globaldefs.h>

#if defined(jpn)
enum { elementArrayOffset = 0x8c, elementCountOffset = 0xb4 };
#else
enum { elementArrayOffset = 0x6c, elementCountOffset = 0x94 };
#endif

void* GetElementStride0x74(unsigned char* obj, int index);

// USA: func_02018bc4
ARM int FindMatchingElementIndex02018bc4(unsigned char* obj, void* target) {
    char* node = (char*)GetElementStride0x74(obj + elementArrayOffset, 0);
    int count = *(int*)(obj + elementCountOffset);
    int matches = 0;
    int i;
    for (i = 0; i < count; i++) {
        if (*(int*)(node + 0x4) == 2) {
            if ((void*)node == target) {
                return matches;
            }
            matches++;
        }
        node += 0x74;
    }
    return -1;
}
