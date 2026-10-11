#include <globaldefs.h>
#if defined(jpn)
enum { kRegion89c = 0x818 };
enum { kRegion103c = 0xfb8 };
#else
enum { kRegion89c = 0x89c };
enum { kRegion103c = 0x103c };
#endif


struct Obj2081;
void ClearElementFlag0x20(struct Obj2081* obj, int key);
void SetEntryLowNibbleAndElement02080c68(void* obj, int id, int value);
struct Container02080fa8;
void SetEntryFirstField02080fa8(struct Container02080fa8* obj, int id, int value);
int SetEntryFlagById02080b2c(void* obj, int id);
extern "C" void func_020813ec(void* obj, int key);

// JPN: func_ov003_021761f0
// USA: func_ov003_02177208  (semantic: ResetAndConfigureElement_02177208)
extern "C" ARM void func_ov003_02177208(char* obj) {
    struct Obj2081* elemObj = *(struct Obj2081**)(obj + kRegion89c);
    ClearElementFlag0x20(elemObj, 9);
    SetEntryLowNibbleAndElement02080c68(elemObj, 9, 0);
    SetEntryFirstField02080fa8((struct Container02080fa8*)elemObj, 0x57, *(unsigned char*)(obj + kRegion103c));
    SetEntryFlagById02080b2c(elemObj, 0x58);
    SetEntryFlagById02080b2c(elemObj, 0x59);
    func_020813ec(elemObj, 9);
}
