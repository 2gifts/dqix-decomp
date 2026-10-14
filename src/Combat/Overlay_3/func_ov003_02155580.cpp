#include <globaldefs.h>

#if defined(jpn)
enum { kRegionValue30_24 = 0x24 };
enum { kRegionValue1E6_1E2 = 0x1e2 };
#else
enum { kRegionValue30_24 = 0x30 };
enum { kRegionValue1E6_1E2 = 0x1e6 };
#endif

struct Elem2081;

struct Obj2081 {
    char pad0[kRegionValue30_24];
    struct Elem2081* elems;
    short field34;
    short selected;
};

struct Obj0208203c;
struct Obj0205eaa0;
struct Clamp020e29a8;
struct Obj020e280c;

extern "C" void func_020813ec(struct Obj2081* obj, int key);
void ResetWithSub0208203c(struct Obj0208203c* obj);
void DispatchWithShortB4_0205eaa0(struct Obj0205eaa0* obj, int a, int b);
void SetElementFlag0x20(struct Obj2081* obj, int key);
void ClampFieldTo2At0x16(struct Clamp020e29a8* p, int v);
void ResetAndReposition020e280c(struct Obj020e280c* self, void* b);

extern struct Obj0205eaa0 data_02108760;

struct Ctx02155580 {
    char pad0[0x8];
    void* field8;
    char pad1[0x18 - 0xc];
    struct Obj2081* menu;
    void* cursor;
    char pad2[0x80 - 0x20];
    char field80[kRegionValue1E6_1E2 - 0x80];
    short key1e6;
    short field1e8;
    short field1ea;
};

// USA: func_ov003_02155580
extern "C" ARM void func_ov003_02155580(struct Ctx02155580* self, int arg) {
    self->key1e6 = 1;
    self->field1e8 = self->field1ea = 6;
    self->menu->selected = self->field1ea;
    func_020813ec(self->menu, self->key1e6);
    ResetWithSub0208203c((struct Obj0208203c*)self->field80);
    self->field8 = 0;
    DispatchWithShortB4_0205eaa0(&data_02108760, 5, 0);
    if (self->cursor != 0) {
        SetElementFlag0x20(self->menu, self->key1e6);
        ClampFieldTo2At0x16((struct Clamp020e29a8*)self->cursor, (signed char)arg);
        ResetAndReposition020e280c((struct Obj020e280c*)self->cursor, (void*)-1);
    }
}
