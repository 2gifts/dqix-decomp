#include <globaldefs.h>
#include "std_library_functions.h"
#include "World/Object3D.h"

struct BinarySearch020971a8Node;
struct BinarySearch020971a8Container;
struct BinarySearch020971a8Node* BinarySearchByField4_02097224(struct BinarySearch020971a8Container* c, int key);

extern const char data_ov014_021895c8[];
extern const char data_ov014_021895ce[];

// USA: func_ov014_02184e3c
ARM void ProcessEntry02184e3c(unsigned char* obj) {
    unsigned char* a = *(unsigned char**)(obj + 0x40);
    if (a == NULL || *(int*)(a + 0xc) == 0 || *(unsigned char**)(obj + 0x48) == NULL) {
        return;
    }
    unsigned char* c = *(unsigned char**)(obj + 0x48);
    unsigned char* r4 = (unsigned char*)BinarySearchByField4_02097224((BinarySearch020971a8Container*)(obj + 0xc), *(short*)(c + 0xc));
    if (r4 == NULL) return;

    a = *(unsigned char**)(obj + 0x40);
    char* s = *(char**)(a + 0x14);
    if (s != NULL && strcmp(data_ov014_021895c8, s) != 0 && strcmp(data_ov014_021895ce, s) != 0) {
        return;
    }

    int cnt = *(int*)(obj + 0x74) + 1;
    *(int*)(obj + 0x74) = cnt;
    if ((int)*(unsigned char*)(r4 + 0xc) <= cnt) {
        *(int*)(obj + 0x74) = 0;
        if (*(unsigned char*)(r4 + 0xc) > 1) {
            *(int*)(obj + 0x74) = 1;
        }
    }

    unsigned char** arr = *(unsigned char***)(r4 + 0x2c);
    unsigned char* e = arr[*(int*)(obj + 0x74)];
    if (e == NULL || *(signed char*)e == 0) return;

    a = *(unsigned char**)(obj + 0x40);
    ((Object3D*)a)->MaybeSetRegularAnimation((char const*)e, 0);
}
