#include <globaldefs.h>

extern "C" void func_020287b4(void* obj);

struct Big02028894 {
    char pad[0x10];
    void* p1ref;   // 0x10
#if !defined(jpn)
    void* p2ref;   // 0x14
#endif
    char pad2[0x318 - 0x18];
};

// USA: func_02028894
ARM void InitEntries02028894(struct Big02028894* obj, char* p1, char* p2) {
    int i;
    func_020287b4(obj);
    for (i = 0; i < 4; i++) {
        obj[i].p1ref = p1 + i * 0x14;
#if !defined(jpn)
        obj[i].p2ref = p2 + i * 0x14;
#endif
    }
}
