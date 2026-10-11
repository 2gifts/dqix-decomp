#include <globaldefs.h>

struct Obj0205d2bc;
extern "C" void func_0204b088(void*, int);
void InitEntries0205d2bc(struct Obj0205d2bc*);

#if defined(jpn)
enum { fieldFlagsOffset = 0x1faa };
#else
enum { fieldFlagsOffset = 0x1d72 };
#endif

// USA: func_ov000_021742c8
ARM void ApplyFieldGroups021742c8(void* obj) {
    unsigned short flags = *(unsigned short*)((char*)obj + fieldFlagsOffset);
    if (!(flags & 0x40)) return;
    if (flags & 0x80) {
        func_0204b088((char*)obj + 0x8c4, 0);
        return;
    }
    func_0204b088((char*)obj + 0x8a4, 0);
    func_0204b088((char*)obj + 0x8c4, 0);
    InitEntries0205d2bc((struct Obj0205d2bc*)((char*)obj + 0x188));
}
