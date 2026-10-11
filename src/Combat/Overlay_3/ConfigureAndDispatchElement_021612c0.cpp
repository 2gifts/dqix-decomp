#include <globaldefs.h>

#if defined(jpn)
enum { kRegionValue36_2A = 0x2a };
enum { kRegionValue308_1F0 = 0x1f0 };
enum { kRegionValue324_20C = 0x20c };
enum { kRegionValue390_278 = 0x278 };
enum { kRegionValue328_210 = 0x210 };
enum { kRegionValue470_298 = 0x298 };
enum { kRegionValue394_27C = 0x27c };
enum { kRegionValue488_2B0 = 0x2b0 };
enum { kRegionValue476_29E = 0x29e };
enum { kRegionValue49C_2C4 = 0x2c4 };
enum { kRegionValue48A_2B2 = 0x2b2 };
#else
enum { kRegionValue36_2A = 0x36 };
enum { kRegionValue308_1F0 = 0x308 };
enum { kRegionValue324_20C = 0x324 };
enum { kRegionValue390_278 = 0x390 };
enum { kRegionValue328_210 = 0x328 };
enum { kRegionValue470_298 = 0x470 };
enum { kRegionValue394_27C = 0x394 };
enum { kRegionValue488_2B0 = 0x488 };
enum { kRegionValue476_29E = 0x476 };
enum { kRegionValue49C_2C4 = 0x49c };
enum { kRegionValue48A_2B2 = 0x48a };
#endif


struct Obj2081 {
    char pad[kRegionValue36_2A];
    unsigned short field36;
};

struct Obj0208203c;
struct Obj020e280c;
struct Obj0205eaa0;

extern "C" int func_020813ec(void *obj, int id);
void ResetWithSub0208203c(struct Obj0208203c *obj);
void DispatchWithShortB4_0205eaa0(struct Obj0205eaa0* obj, int a, int b);
void SetElementFlag0x20(struct Obj2081* obj, int key);
void ResetAndReposition020e280c(struct Obj020e280c* self, void* b);

extern struct Obj0205eaa0 data_02108760;

struct Ctx021612c0 {
    char pad0[kRegionValue308_1F0];
    char sub308[kRegionValue324_20C - kRegionValue308_1F0];
    struct Obj2081* field324;
    char pad1[kRegionValue390_278 - kRegionValue328_210];
    struct Obj020e280c* field390;
    char pad2[kRegionValue470_298 - kRegionValue394_27C];
    int field470;
    short field474;
    char pad3[kRegionValue488_2B0 - kRegionValue476_29E];
    short field488;
    char pad4[kRegionValue49C_2C4 - kRegionValue48A_2B2];
    short field49c;
};

// USA: func_ov003_021612c0  (semantic: ConfigureAndDispatchElement_021612c0)
// JPN: func_ov003_021613ac
extern "C" ARM void func_ov003_021612c0(struct Ctx021612c0* self) {
    self->field488 = 9;
    self->field474 = self->field49c = 0x2c;
    self->field324->field36 = self->field49c;
    func_020813ec(self->field324, self->field488);
    ResetWithSub0208203c((struct Obj0208203c*)self->sub308);
    self->field470 = 0;
    DispatchWithShortB4_0205eaa0(&data_02108760, 5, 0);
    if (self->field390 == NULL) {
        return;
    }
    SetElementFlag0x20(self->field324, self->field488);
    ResetAndReposition020e280c(self->field390, (void*)-1);
}
