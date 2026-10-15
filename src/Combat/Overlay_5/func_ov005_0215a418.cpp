#if defined(jpn)
#define func_ov005_0215a418 func_ov005_0215b96c
#endif

#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Graphics/Vector.h>

#if defined(jpn)
#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif

void IssueCommand0x19_020c51a4(int cmd);

char* GetField1c_021a193c(int*);
struct Field150Holder02052e14;
short* GetField150Ptr0x488(Field150Holder02052e14*);
extern "C" void func_02047554(void* obj, int val, int param1);

extern const unsigned char data_ov005_0215cc1c[];

#define G3_MTX_PUSH  (*(volatile int*)0x04000444)
#define G3_MTX_POP   (*(volatile int*)0x04000448)
#define G3_MTX_SCALE (*(volatile int*)0x0400046c)
#define G3_MTX_TRANS (*(volatile int*)0x04000470)

struct Entry0215a418 { char data[0x88]; };

struct Sub0215a418 {
    char pad[0x1000];
    Entry0215a418 entries[1];
};

struct Scene0215a418 {
    char pad0[LOW_REGION(0x19e8, 0x1a70)];
    Entry0215a418 entries[(LOW_REGION(0x3d30, 0x3db8) - LOW_REGION(0x19e8, 0x1a70)) / 0x88];
    char pad1[LOW_REGION(0x3d30, 0x3db8) - LOW_REGION(0x19e8, 0x1a70) - ((LOW_REGION(0x3d30, 0x3db8) - LOW_REGION(0x19e8, 0x1a70)) / 0x88) * 0x88];
    unsigned char mode;
    char pad2[3];
    unsigned char cursor;
};

// USA: func_ov005_0215a418
extern "C" ARM void func_ov005_0215a418(Scene0215a418* self) {
    GameState* gs = GameState::GetInstance();
    GameResources* res = func_ov017_0218b5b0();
    char* holder = GetField1c_021a193c((int*)res->unknown_ptr_array_36fc[3]);
    short* tbl = GetField150Ptr0x488((Field150Holder02052e14*)(GetCombatantWithFlag0x100_0200ff1c(gs,*(int*)(holder + LOW_REGION(0x4f8, 0x4fc)))));
    if (self->mode != 0) return;

    for (int i = 0; i < 8; i++) {
        int sel = 0;
        if (i == self->cursor) sel = 1;
        int k = sel * 11;
        int y = (i * 0x18) << 12;
        G3_MTX_PUSH = 0;
        G3_MTX_TRANS = 0x7f000;
        int off = (k + 4) * 0x88;
        Entry0215a418* ents = ((Sub0215a418*)((char*)self + LOW_REGION(0x9e8, 0xa70)))->entries;
        G3_MTX_TRANS = y;
        G3_MTX_TRANS = -0x200000;
        func_02047554((Entry0215a418*)((char*)ents + off), 0, 1);
        G3_MTX_POP = 1;
        G3_MTX_PUSH = 0;
        G3_MTX_TRANS = 0x100000;
        G3_MTX_TRANS = y;
        G3_MTX_TRANS = -0x200000;
        Matrix4x3 mtxCopy = RotationMatrixY(0x3244);
        IssueCommand0x19_020c51a4((int)&mtxCopy);
        func_02047554((Entry0215a418*)((char*)ents + off), 0, 1);
        G3_MTX_POP = 1;
        G3_MTX_PUSH = 0;
        G3_MTX_TRANS = 0x70000;
        G3_MTX_TRANS = y;
        G3_MTX_TRANS = -0x200000;
        G3_MTX_SCALE = 0x14000;
        G3_MTX_SCALE = 0x1000;
        G3_MTX_SCALE = 0x1000;
        func_02047554(&self->entries[k + 5], 0, 1);
        G3_MTX_POP = 1;
        Entry0215a418* e = &self->entries[k + 7 + i];
        if (tbl[data_ov005_0215cc1c[i]] > 0) {
            e = &self->entries[k + 6];
        }
        G3_MTX_PUSH = 0;
        G3_MTX_TRANS = 0x85000;
        G3_MTX_TRANS = y;
        G3_MTX_TRANS = -0x1ff000;
        func_02047554(e, 0, 1);
        G3_MTX_POP = 1;
    }
}
