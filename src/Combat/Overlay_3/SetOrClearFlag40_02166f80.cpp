#include <globaldefs.h>
#if defined(jpn)
enum { kRegion324 = 0x20c };
#else
enum { kRegion324 = 0x324 };
#endif

struct Obj2081;

struct Elem2081 {
    char unk[0xc5];
    unsigned char flags;
};

struct Elem2081* FindElementByByte0xc4(struct Obj2081* obj, int key);
extern "C" void func_020813ec(void* obj, int key);

// JPN: func_ov003_02166e60
// USA: func_ov003_02166f80
ARM void SetOrClearFlag40_02166f80(void* self, int key, int set) {
    struct Obj2081* obj = *(struct Obj2081**)((char*)self + kRegion324);
    struct Elem2081* elem = FindElementByByte0xc4(obj, key);
    if (elem == NULL) {
        return;
    }
    if (set) {
        elem->flags |= 0x40;
    } else {
        elem->flags &= ~0x40;
    }
    func_020813ec(*(void**)((char*)self + kRegion324), key);
}
