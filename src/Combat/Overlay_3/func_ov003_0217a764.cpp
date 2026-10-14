#include <globaldefs.h>

#if defined(jpn)
enum { kRegionSelfShift = 0x84, kRegionElementCursor = 0x2a };
#else
enum { kRegionSelfShift = 0, kRegionElementCursor = 0x36 };
#endif

struct Obj2081;
struct Cont0207fdf0;
struct Obj0205eaa0;
struct Obj0208203c;
struct Container020dedd0;
struct Obj021dcae0;
struct Element020de650;

struct ElemKind0217a764 {
    char pad[8];
    unsigned int unk_ : 12;
    unsigned int kind_ : 2;
};

extern "C" void* _Z17GetPtrField0x2a04P9GameState(void* battleStruct);
extern "C" void* _ZN9GameState11GetInstanceEv();
void ComputeMappedOffset_0217a220(unsigned char* obj);

short FindMappedMemberId02080468(void* obj, int id);
void SetEntryLowNibbleAndElement02080c68(void* obj, int id, int value);
void DispatchWithShortB4_0205eaa0(struct Obj0205eaa0* obj, int a, int b);
void ResetWithSub0208203c(struct Obj0208203c* obj);
struct Element020de650* FindElementByKey020dedd0(struct Container020dedd0* c, int key);
void CallFunc0204c804OnNonMatchingKey(struct Cont0207fdf0* obj, int key);
ARM int RefillAndResetEntry_02175d78(char* obj);

extern "C" void func_ov003_02177820(char* self);
extern "C" void func_ov003_02177938(void* self);
extern "C" void func_ov003_021748c4(unsigned char* self);
extern "C" int func_ov003_021765b4(void* self);
extern "C" int func_ov003_021766e8(void* self);
extern "C" int func_ov003_021764f4(unsigned char* self);
extern "C" void func_ov003_02176468(unsigned char* self);
extern "C" int func_ov003_02175df4(void* self);
extern "C" int func_ov003_02179da8(void* obj, int flag);
extern "C" void func_ov023_021dcae0(struct Obj021dcae0* obj, int val);

extern struct Obj0205eaa0 data_02108760;

// USA: func_ov003_0217a764
extern "C" ARM void func_ov003_0217a764(unsigned char* self) {
    void* battle = _ZN9GameState11GetInstanceEv();
    _Z17GetPtrField0x2a04P9GameState(battle);
    struct Obj2081* elemObj = *(struct Obj2081**)(self + (0x89c - kRegionSelfShift));
    int state = *(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift));

    if (state == 0) {
        int id = 0x11;
        switch (*(int*)(self + (0x1000 + 0x30 - kRegionSelfShift))) {
        case 2: id = 0x12; break;
        case 3: id = 0x13; break;
        case 4: id = 0x14; break;
        }
        func_ov003_02177820((char*)self);
        func_ov003_02177938(self);
        *(short*)((char*)elemObj + kRegionElementCursor) = *(short*)(self + (0x1000 + 0x10 - kRegionSelfShift));
        SetEntryLowNibbleAndElement02080c68(elemObj, id, 1);
        *(short*)(self + (0xf00 + 0xfc - kRegionSelfShift)) = *(short*)(self + (0xf00 + 0xfe - kRegionSelfShift));
        *(short*)(self + (0xf00 + 0xfe - kRegionSelfShift)) = 0x15;
        if (*(short*)(self + (0x1000 + 0xe - kRegionSelfShift)) < 0) {
            *(short*)(self + (0x1000 + 0xe - kRegionSelfShift)) = FindMappedMemberId02080468(elemObj, *(short*)(self + (0xf00 + 0xfe - kRegionSelfShift)));
        }
        *(short*)((char*)elemObj + kRegionElementCursor) = *(short*)(self + (0x1000 + 0xe - kRegionSelfShift));
        ResetWithSub0208203c((struct Obj0208203c*)(self + (0x88c - kRegionSelfShift)));
        *(void**)(self + (0xff8 - kRegionSelfShift)) = 0;
        *(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift)) = 1;
        ComputeMappedOffset_0217a220(self);
        func_ov003_021748c4(self);
        return;
    }

    if (state == 1) {
        *(void**)(self + (0xff8 - kRegionSelfShift)) = self + (0x1000 + 0xe - kRegionSelfShift);
        ComputeMappedOffset_0217a220(self);
        func_ov023_021dcae0((struct Obj021dcae0*)(self + 0x3c), *(short*)(self + (0x1000 + 0x3a - kRegionSelfShift)));
        if (func_ov003_021765b4(self) != 0) {
            DispatchWithShortB4_0205eaa0(&data_02108760, 1, 0);
            ResetWithSub0208203c((struct Obj0208203c*)(self + (0x88c - kRegionSelfShift)));
            *(void**)(self + (0xff8 - kRegionSelfShift)) = 0;
            void* elem = (void*)FindElementByKey020dedd0((struct Container020dedd0*)(self + (0x874 - kRegionSelfShift)), *(short*)(self + (0x1000 + 0x3a - kRegionSelfShift)));
            *(void**)(self + 8) = elem;
            if (elem == 0) return;
            int tier = func_ov003_02179da8(elem, 0);
            if (tier == 2) {
                CallFunc0204c804OnNonMatchingKey((struct Cont0207fdf0*)elemObj, 0);
                *(short*)(self + (0x1000 + 0x36 - kRegionSelfShift)) = 0x1c;
                *(unsigned char*)(self + (0x1000 + 0x3e - kRegionSelfShift)) = 1;
                *(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift)) = 0;
                *(unsigned short*)(self + (0x1000 + 0x46 - kRegionSelfShift)) |= 0x2000;
                return;
            }
            CallFunc0204c804OnNonMatchingKey((struct Cont0207fdf0*)elemObj, 0);
            int kind = ((struct ElemKind0217a764*)*(void**)(self + 8))->kind_;
            short next36 = -1;
            unsigned char next3f = 0;
            switch (kind) {
            case 0:
                *(unsigned short*)(self + (0x1000 + 0x46 - kRegionSelfShift)) |= 0x20;
                next36 = 0x12;
                break;
            case 1:
                next36 = 0xd;
                next3f = 4;
                break;
            case 2:
                next36 = 0x11;
                next3f = 2;
                break;
            }
            *(short*)(self + (0x1000 + 0x36 - kRegionSelfShift)) = next36;
            *(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift)) = next3f;
            *(unsigned short*)(self + (0x1000 + 0x46 - kRegionSelfShift)) |= 0x2000;
            if (((struct ElemKind0217a764*)*(void**)(self + 8))->kind_ == 0) {
                *(unsigned short*)(self + (0x1000 + 0x46 - kRegionSelfShift)) &= ~0x2000;
            }
            return;
        }
        if (func_ov003_021766e8(self) == 0) return;
        ResetWithSub0208203c((struct Obj0208203c*)(self + (0x88c - kRegionSelfShift)));
        *(void**)(self + (0xff8 - kRegionSelfShift)) = 0;
        *(unsigned char*)(self + (0x1000 + 0x3e - kRegionSelfShift)) = 4;
        *(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift)) = 1;
        *(unsigned short*)(self + (0x1000 + 0x46 - kRegionSelfShift)) |= 0x2000;
        return;
    }

    if (state == 2) {
        func_ov003_02176468(self);
        *(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift)) = 3;
        return;
    }

    if (state == 3) {
        int res = func_ov003_021764f4(self);
        if (res != -1) {
            if (res != 1) return;
            *(short*)(self + (0x1000 + 0x36 - kRegionSelfShift)) = 0x10;
            *(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift)) = 4;
        } else {
            *(short*)(self + (0x1000 + 0x36 - kRegionSelfShift)) = 0x30;
            *(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift)) = 0;
            *(unsigned short*)(self + (0x1000 + 0x46 - kRegionSelfShift)) |= 0x20;
        }
        return;
    }

    if (state == 4) {
        func_ov003_02176468(self);
        *(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift)) = 5;
        return;
    }

    if (state == 5) {
        int res = func_ov003_021764f4(self);
        if (res != -1) {
            if (res != 1) return;
            RefillAndResetEntry_02175d78((char*)self);
            func_ov003_02175df4(self);
            *(short*)(self + (0x1000 + 0x36 - kRegionSelfShift)) = 0xe;
            *(unsigned char*)(self + (0x1000 + 0x3e - kRegionSelfShift)) = 4;
            *(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift)) = 1;
            *(unsigned short*)(self + (0x1000 + 0x46 - kRegionSelfShift)) |= 0x20;
        } else {
            *(short*)(self + (0x1000 + 0x36 - kRegionSelfShift)) = 0x30;
            *(unsigned char*)(self + (0x1000 + 0x3e - kRegionSelfShift)) = 5;
            *(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift)) = 0;
            *(unsigned short*)(self + (0x1000 + 0x46 - kRegionSelfShift)) |= 0x20;
        }
        return;
    }
}
