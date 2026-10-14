#include <globaldefs.h>

#if defined(jpn)
enum { kRegionValue1F8_1F4 = 0x1f4 };
enum { kRegionValue204_200 = 0x200 };
#else
enum { kRegionValue1F8_1F4 = 0x1f8 };
enum { kRegionValue204_200 = 0x204 };
#endif

struct Obj0207fcb8;
unsigned int ClearAllBuffers0207fcb8(Obj0207fcb8*);
struct Outer020e28dc;
unsigned int GetInnerFlagBit0020e28dc(Outer020e28dc*);
struct Struct020e2794;
unsigned int UpdateEntryIfActive020e2794(Struct020e2794*, void*);
struct Cont0207fd44;
unsigned int CallFunc0204b04cOverList0x2c(Cont0207fd44*);
unsigned int InitBuffersIfFlag431_021eb4b8(void*);
struct Obj0207fd00;
unsigned int CallFunc0204c8f0OverEntries0207fd00(Obj0207fd00*);
extern "C" unsigned int func_0207fe80(unsigned int, unsigned int, unsigned int, unsigned int);
extern "C" unsigned int func_ov003_0215501c(unsigned int);

// USA: func_ov003_02154eec  (semantic: Trans_02154eec)
extern "C" ARM void func_ov003_02154eec(unsigned int self) {
    if (*(unsigned char*)((char*)self + kRegionValue1F8_1F4) == 0) { return; }
    if (*(unsigned int*)((char*)self + kRegionValue204_200) != 0) {
        InitBuffersIfFlag431_021eb4b8((void*)(*(unsigned int*)((char*)self + kRegionValue204_200)));
    } else {
        unsigned int obj = *(unsigned int*)((char*)self + 0x18);
        if (obj != 0) {
            ClearAllBuffers0207fcb8((Obj0207fcb8*)obj);
            CallFunc0204c8f0OverEntries0207fd00((Obj0207fd00*)obj);
            func_0207fe80(obj, 2, 1, 1);
            CallFunc0204b04cOverList0x2c((Cont0207fd44*)obj);
        }
    }
    if (*(unsigned int*)((char*)self + 0x1c) != 0 && GetInnerFlagBit0020e28dc((Outer020e28dc*)(*(unsigned int*)((char*)self + 0x1c))) != 0) {
        UpdateEntryIfActive020e2794((Struct020e2794*)(*(unsigned int*)((char*)self + 0x1c)), (void*)(self + 0x2c));
        return;
    }
    func_ov003_0215501c(self);
}
