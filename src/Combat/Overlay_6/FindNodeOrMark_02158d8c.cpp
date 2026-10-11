#if defined(jpn)
#define R(j,u) (j)
#define func_ov006_02154e58 func_ov006_021565b0
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

struct Node02158d8c {
    char pad[0x1c];
    struct Node02158d8c* next;
};

// USA: func_ov006_02158d8c
ARM struct Node02158d8c* FindNodeOrMark_02158d8c(void* objRaw, short life) {
    char* obj = (char*)objRaw;
    struct Node02158d8c* n = *(struct Node02158d8c**)(obj + R(0x28, 0x30));
    short i = 0;
    while (n != NULL && life != 0) {
        if (n->next == NULL) {
            obj = obj + 0x300;
            *(short*)(obj + 0x6a) = i + 0x29;
            break;
        }
        life--;
        i++;
        n = n->next;
    }
    return n;
}
