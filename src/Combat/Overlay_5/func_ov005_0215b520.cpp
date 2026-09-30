#include <globaldefs.h>

typedef union Matrix4x3 {
    int m[4][3];
    int a[12];
} Matrix4x3;
Matrix4x3 RotationMatrixY(int angle);
void IssueCommand0x19(int cmd);

struct Obj0204b8d0;
extern "C" void _Z21DispatchEntry0204b8d0P11Obj0204b8d0jiisssst(struct Obj0204b8d0*, unsigned int, int, int, short, short, short, short, unsigned short);
struct Obj0204b010;
extern "C" void _Z19ClearBuffer0204b010P11Obj0204b010Pv(struct Obj0204b010* obj, void* p);
extern "C" void func_0204b04c(void* p, int flag);
extern "C" void func_02047554(void* obj, int val, int param1);
extern "C" void func_ov005_0215792c(void* obj, int mode);
extern "C" void func_ov005_021579ec(void* obj, unsigned char a, unsigned char b);
extern "C" void func_ov005_02154d34(void* obj, int a, int b);
extern "C" void func_ov005_02154d7c(void* obj, int a, int b);
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" char* func_ov017_0218b5b0();
extern "C" char* _Z19GetField1c_021a193cPi(void* p);
extern "C" void* _Z25GetCombatantWithFlag0x100P9GameStatei(void* gs, int id);
extern "C" short* _Z19GetField150Ptr0x488P22Field150Holder02052e14(void* holder);

extern const unsigned char data_ov005_0215cbec[];
extern const unsigned char data_ov005_0215cbdc[];

#define G3_MTX_PUSH  (*(volatile int*)0x04000444)
#define G3_MTX_POP   (*(volatile int*)0x04000448)
#define G3_MTX_SCALE (*(volatile int*)0x0400046c)
#define G3_MTX_TRANS (*(volatile int*)0x04000470)

struct Entry0215b520 {
    char data[0x88];
};

struct Sub0215b520 {
    char pad[0x1000];
    Entry0215b520 entries[1];
};

struct Scene0215b520 {
    char pad0[0xea4];
    char list;          // 0xea4
    char pad1[0x1a34 - 0xea5];
    char motion;        // 0x1a34
    char pad2[0x1a70 - 0x1a35];
    Entry0215b520 entries[(0x3db8 - 0x1a70) / 0x88];
    char pad3[0x3db8 - 0x1a70 - ((0x3db8 - 0x1a70) / 0x88) * 0x88];
    unsigned char mode;     // 0x3db8
    char pad4;
    unsigned char state;    // 0x3dba
    unsigned char modeB;    // 0x3dbb
    unsigned char cursor;   // 0x3dbc
    char pad5[0x3dcc - 0x3dbd];
    unsigned int flags;     // 0x3dcc
    char pad6[0x3de2 - 0x3dd0];
    short level;            // 0x3de2
    int step;               // 0x3de4
    int accum;              // 0x3de8
    int phase;              // 0x3dec
};

// USA: func_ov005_0215b520
extern "C" ARM void func_ov005_0215b520(Scene0215b520* self) {
    unsigned char state = self->state;
    if (state == 0 && self->phase == 0) {
        func_ov005_0215792c(self, 1);
        self->flags |= 0x100;
        void* gs = _ZN9GameState11GetInstanceEv();
        char* res = func_ov017_0218b5b0();
        char* holder = _Z19GetField1c_021a193cPi(*(void**)(res + 0x3708));
        short* tbl = _Z19GetField150Ptr0x488P22Field150Holder02052e14(
            _Z25GetCombatantWithFlag0x100P9GameStatei(gs, *(int*)(holder + 0x4fc)));
        self->accum += self->step;
        if (self->accum >= 3) {
            self->accum -= 3;
            self->level += 0x29;
            if (self->level >= 0x7b) {
                self->level = 0x7b;
                self->phase = 1;
            }
        }
        if (self->mode == 1) {
            for (int i = 0; i < 8; i++) {
                int sel = 0;
                if (i == self->cursor) sel = 1;
                int k = sel * 11;
                int y = (i * 0x18) << 12;
                G3_MTX_PUSH = 0;
                G3_MTX_TRANS = (self->level + 0x7f) << 12;
                int off = (k + 4) * 0x88;
                Entry0215b520* ents = ((Sub0215b520*)((char*)self + 0xa70))->entries;
                G3_MTX_TRANS = y;
                G3_MTX_TRANS = -0x200000;
                func_02047554((Entry0215b520*)((char*)ents + off), 0, 1);
                G3_MTX_POP = 1;
                G3_MTX_PUSH = 0;
                G3_MTX_TRANS = (self->level + 0x100) << 12;
                G3_MTX_TRANS = y;
                G3_MTX_TRANS = -0x200000;
                Matrix4x3 rot;
                rot = RotationMatrixY(0x3244);
                IssueCommand0x19((int)&rot);
                func_02047554((Entry0215b520*)((char*)ents + off), 0, 1);
                G3_MTX_POP = 1;
                G3_MTX_PUSH = 0;
                G3_MTX_TRANS = (self->level + 0x70) << 12;
                G3_MTX_TRANS = y;
                G3_MTX_TRANS = -0x200000;
                G3_MTX_SCALE = 0x14000;
                G3_MTX_SCALE = 0x1000;
                G3_MTX_SCALE = 0x1000;
                func_02047554(&self->entries[k + 5], 0, 1);
                G3_MTX_POP = 1;
                Entry0215b520* e = &self->entries[k + 7 + i];
                if (tbl[data_ov005_0215cbec[i]] > 0) {
                    e = &self->entries[k + 6];
                }
                G3_MTX_PUSH = 0;
                G3_MTX_TRANS = (self->level + 0x85) << 12;
                G3_MTX_TRANS = y;
                G3_MTX_TRANS = -0x1ff000;
                func_02047554(e, 0, 1);
                G3_MTX_POP = 1;
            }
        }
        if (self->phase == 1) {
            self->state++;
            self->level = 0;
            self->accum = 0;
            self->phase = 0;
        }
    } else if (state == 1 && self->phase == 0) {
        self->flags |= 0x100;
        self->accum += self->step;
        if (self->accum >= 3) {
            self->accum -= 3;
            self->level += 6;
            if (self->level >= 0x10) {
                self->level = 0x10;
                self->phase = 1;
            }
        }
        _Z19ClearBuffer0204b010P11Obj0204b010Pv((struct Obj0204b010*)&self->list, 0);
        _Z21DispatchEntry0204b8d0P11Obj0204b8d0jiisssst((struct Obj0204b8d0*)&self->list, 0, 0, 0, 0x20 - self->level, 0, 0x10, 0x16, 0xffff);
        unsigned char cursor = self->cursor;
        short y = cursor * 2 + 0xf;
        _Z21DispatchEntry0204b8d0P11Obj0204b8d0jiisssst((struct Obj0204b8d0*)&self->list, (unsigned char)(cursor + 1), 0, 0, y + 0x10 - self->level, 0, 4, 3, 0xffff);
        func_0204b04c(&self->list, 0);
        if (self->phase == 1) {
            self->state++;
            self->level = 0;
            self->accum = 0;
        }
    } else if (state == 2 && self->phase == 1) {
        func_ov005_0215792c(self, 3);
        self->flags |= 0x100;
        func_ov005_021579ec(self, self->mode, self->modeB);
        func_ov005_02154d34(&self->motion, 0x85000, 0x17000);
        func_ov005_02154d7c(&self->motion, 0x76000, 0x16000);
        self->flags |= 0x800;
    } else if (state == 0 && self->phase == 1) {
        self->flags |= 0x800;
        func_ov005_0215792c(self, 1);
        self->flags |= 0x100;
        self->accum += self->step;
        if (self->accum >= 3) {
            self->accum -= 3;
            self->level += 6;
            if (self->level >= 0x10) {
                self->level = 0x10;
                self->phase = 2;
            }
        }
        _Z19ClearBuffer0204b010P11Obj0204b010Pv((struct Obj0204b010*)&self->list, 0);
        _Z21DispatchEntry0204b8d0P11Obj0204b8d0jiisssst((struct Obj0204b8d0*)&self->list, 0, 0, 0, self->level + 0x10, 0, 0x10, 0x16, 0xffff);
        unsigned char cursor = self->cursor;
        short y = cursor * 2 + 0xf;
        _Z21DispatchEntry0204b8d0P11Obj0204b8d0jiisssst((struct Obj0204b8d0*)&self->list, (unsigned char)(cursor + 1), 0, 0, y + self->level, 0, 4, 3, 0xffff);
        func_0204b04c(&self->list, 0);
        if (self->phase == 2) {
            self->state++;
            self->level = 0;
            self->accum = 0;
        }
    } else if (state == 1 && self->phase == 2) {
        void* gs = _ZN9GameState11GetInstanceEv();
        char* res = func_ov017_0218b5b0();
        char* holder = _Z19GetField1c_021a193cPi(*(void**)(res + 0x3708));
        short* tbl = _Z19GetField150Ptr0x488P22Field150Holder02052e14(
            _Z25GetCombatantWithFlag0x100P9GameStatei(gs, *(int*)(holder + 0x4fc)));
        self->accum += self->step;
        if (self->accum >= 3) {
            self->accum -= 3;
            self->level += 0x29;
            if (self->level >= 0x7b) {
                self->level = 0x7b;
                self->phase = 1;
            }
        }
        if (self->mode == 1) {
            for (int i = 0; i < 8; i++) {
                int sel = 0;
                if (i == self->cursor) sel = 1;
                int k = sel * 11;
                int y = (i * 0x18) << 12;
                G3_MTX_PUSH = 0;
                G3_MTX_TRANS = (0xfa - self->level) << 12;
                int off = (k + 4) * 0x88;
                Entry0215b520* ents = ((Sub0215b520*)((char*)self + 0xa70))->entries;
                G3_MTX_TRANS = y;
                G3_MTX_TRANS = -0x200000;
                func_02047554((Entry0215b520*)((char*)ents + off), 0, 1);
                G3_MTX_POP = 1;
                G3_MTX_PUSH = 0;
                G3_MTX_TRANS = (0x17b - self->level) << 12;
                G3_MTX_TRANS = y;
                G3_MTX_TRANS = -0x200000;
                Matrix4x3 rot;
                rot = RotationMatrixY(0x3244);
                IssueCommand0x19((int)&rot);
                func_02047554((Entry0215b520*)((char*)ents + off), 0, 1);
                G3_MTX_POP = 1;
                G3_MTX_PUSH = 0;
                G3_MTX_TRANS = (0xeb - self->level) << 12;
                G3_MTX_TRANS = y;
                G3_MTX_TRANS = -0x200000;
                G3_MTX_SCALE = 0x14000;
                G3_MTX_SCALE = 0x1000;
                G3_MTX_SCALE = 0x1000;
                func_02047554(&self->entries[k + 5], 0, 1);
                G3_MTX_POP = 1;
                Entry0215b520* e = &self->entries[k + 7 + i];
                if (tbl[data_ov005_0215cbdc[i]] > 0) {
                    e = &self->entries[k + 6];
                }
                G3_MTX_PUSH = 0;
                G3_MTX_TRANS = (0x100 - self->level) << 12;
                G3_MTX_TRANS = y;
                G3_MTX_TRANS = -0x1ff000;
                func_02047554(e, 0, 1);
                G3_MTX_POP = 1;
            }
        }
        if (self->phase == 1) {
            self->state = 0;
            self->level = 0;
            self->accum = 0;
            self->phase = 0;
            func_ov005_0215792c(self, 0);
            self->flags |= 0x100;
        }
    }
}
