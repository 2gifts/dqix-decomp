#include <globaldefs.h>
#if defined(jpn)
enum { kRegion104b = 0xfc7 };
enum { kRegion103e = 0xfba };
enum { kRegion89c = 0x818 };
enum { kRegion104c = 0xfc8 };
#else
enum { kRegion104b = 0x104b };
enum { kRegion103e = 0x103e };
enum { kRegion89c = 0x89c };
enum { kRegion104c = 0x104c };
#endif


struct Obj0207fcb8;
void ClearAllBuffers0207fcb8(struct Obj0207fcb8* obj);
struct Obj0207fd00;
void CallFunc0204c8f0OverEntries0207fd00(struct Obj0207fd00* obj);
extern "C" void func_0207fe80(void* obj, int a, int b, int c);
struct Cont0207fd44;
void CallFunc0204b04cOverList0x2c(struct Cont0207fd44* obj);
extern "C" void func_ov003_02175fd4(void* obj);
struct Wrapper02176098;
void UpdateFlagEntry_02176098(struct Wrapper02176098* p);
extern "C" void func_ov003_0217545c(void* obj);
extern "C" void func_ov003_02175504(void* obj);
extern "C" void func_ov003_0217577c(void* obj);

// JPN: func_ov003_0217393c
// USA: func_ov003_0217480c  (semantic: ProcessCombatantIfActive_0217480c)
extern "C" ARM void func_ov003_0217480c(void* p) {
    char* obj = (char*)p;
    if (*(unsigned char*)(obj + kRegion103e) != 0) {
        void* sub = *(void**)(obj + kRegion89c);
        ClearAllBuffers0207fcb8((struct Obj0207fcb8*)sub);
        CallFunc0204c8f0OverEntries0207fd00((struct Obj0207fd00*)sub);
        func_0207fe80(sub, 1, 2, 1);
        CallFunc0204b04cOverList0x2c((struct Cont0207fd44*)sub);
        func_ov003_02175fd4(obj);
        UpdateFlagEntry_02176098((struct Wrapper02176098*)obj);
        func_ov003_0217545c(obj);
        func_ov003_02175504(obj);
        func_ov003_0217577c(obj);
        *(unsigned char*)(obj + kRegion104c) = 0;
        *(unsigned char*)(obj + kRegion104b) = 0;
    }
}
