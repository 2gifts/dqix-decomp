#include <globaldefs.h>

#if defined(jpn)
#define CheckAnyFlag_021570b4 func_ov006_021586bc
enum { kIngredientEntries = 0x714 };
#else
enum { kIngredientEntries = 0x894 };
#endif



struct Entry021570b4 {
    char pad[0x7a];
    unsigned char flagByte;
    char pad2[0x7c - 0x7b];
};

// USA: func_ov006_021570b4
#if defined(jpn)
extern "C"
#endif
ARM int CheckAnyFlag_021570b4(char* obj) {
    struct Entry021570b4* e = (struct Entry021570b4*)(obj + kIngredientEntries);
    int found = 0;
    unsigned char i;
    for (i = 0; i < 4; i++) {
        if (found | e->flagByte) {
            found = 1;
        } else {
            found = 0;
        }
        e = (struct Entry021570b4*)((char*)e + 0x7c);
    }
    return found;
}
