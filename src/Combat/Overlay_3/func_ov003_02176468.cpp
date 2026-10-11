#include <globaldefs.h>
#if defined(jpn)
enum { kRegion1000 = 0xf7c };
enum { kRegionffe = 0xf7a };
enum { kRegionff8 = 0xf74 };
enum { kRegion88c = 0x808 };
enum { kRegion1002 = 0xf7e };
enum { kRegion89c = 0x818 };
enum { kRegion36 = 0x2a };
#else
enum { kRegion1000 = 0x1000 };
enum { kRegionffe = 0xffe };
enum { kRegionff8 = 0xff8 };
enum { kRegion88c = 0x88c };
enum { kRegion1002 = 0x1002 };
enum { kRegion89c = 0x89c };
enum { kRegion36 = 0x36 };
#endif


struct Obj2081;
void SetElementFlag0x20(struct Obj2081* obj, int key);
extern "C" void func_020813ec(void* obj, int key);

struct Obj0208203c;
void ResetWithSub0208203c(struct Obj0208203c* obj);

struct Obj0205eaa0;
void DispatchWithShortB4_0205eaa0(struct Obj0205eaa0* obj, int a, int b);
extern struct Obj0205eaa0 data_02108760;

struct Obj020e280c;
void ResetAndReposition020e280c(struct Obj020e280c* self, void* b);

// JPN: func_ov003_021754bc
// USA: func_ov003_02176468  (semantic: ResetElementFieldsAndDispatch_02176468)
extern "C" ARM void func_ov003_02176468(unsigned char* self) {
    *(short*)(self + kRegionffe) = 1;
    *(short*)(self + kRegion1000) = *(short*)(self + kRegion1002) = 2;
    *(short*)((char*)(*(struct Obj2081**)(self + kRegion89c)) + kRegion36) = *(short*)(self + kRegion1002);
    func_020813ec(*(struct Obj2081**)(self + kRegion89c), *(short*)(self + kRegionffe));
    ResetWithSub0208203c((struct Obj0208203c*)(self + kRegion88c));
    *(void**)(self + kRegionff8) = 0;
    DispatchWithShortB4_0205eaa0(&data_02108760, 5, 0);
    if (*(void**)self == 0) {
        return;
    }
    SetElementFlag0x20(*(struct Obj2081**)(self + kRegion89c), *(short*)(self + kRegionffe));
    ResetAndReposition020e280c((struct Obj020e280c*)(*(void**)self), (void*)-1);
}
