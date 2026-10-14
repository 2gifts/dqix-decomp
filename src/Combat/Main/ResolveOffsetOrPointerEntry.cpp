#include <globaldefs.h>

extern "C" void func_020d21f8(void);
extern "C" void func_020d220c(void);

struct OffsetTable020d2eec { char pad[0x3c]; int entries[1]; };

// USA: func_020d2eec
ARM void* ResolveOffsetOrPointerEntry_020d2eec(void* base, int index) {
    void* result;
    int val;
    func_020d21f8();
    val = ((struct OffsetTable020d2eec*)base)->entries[index];
    if (val != 0) {
        if ((unsigned int)val < 0x2000000) {
            result = (char*)base + val;
        } else {
            result = (void*)val;
        }
    } else {
        result = NULL;
    }
    func_020d220c();
    return result;
}
