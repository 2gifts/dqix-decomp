#include <globaldefs.h>

#if defined(jpn)
#define data_ov023_021fd922 data_ov023_021fcbd2
#endif


#if defined(jpn)
#define func_ov023_021f9da8 func_ov023_021f9234
#define GetEntryByteIfFlag0x84 func_0204887c
#endif


#if defined(jpn)
#define func_ov023_021f8e1c func_ov023_021f82a8
#endif
#include "GameState/GameState.h"

struct Vec3_021f8e1c {
    int x;
    int y;
    int z;
};

static inline const Vec3_021f8e1c* AddrOf_021f8e1c(const Vec3_021f8e1c& v) { return &v; }

class Node021f8e1c {
public:
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual Vec3_021f8e1c GetPos();
    virtual void v09(); virtual void v10(); virtual void v11(); virtual void v12();
    virtual void v13(); virtual void v14(); virtual void v15();
    virtual int GetSoundA();
    virtual void v17();
    virtual int GetSoundB();
    virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22();
    virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26();
    virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30();
    virtual void v31();
    virtual int GetSoundC();
    virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36();
    virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40();
    virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44();
    virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48();
    virtual void v49(); virtual void v50(); virtual void v51(); virtual void v52();
    virtual void v53(); virtual void v54(); virtual void v55(); virtual void v56();
    virtual void v57(); virtual void v58(); virtual void v59(); virtual void v60();

#if !defined(jpn)
    virtual void v61();
#endif
    virtual int IsDisabled();

    char pad4[0x2c];
    short offX;
    short offY;
};

struct Cursor021f8e1c {
    char pad0[6];
    unsigned short id;
    char pad8[4];
    unsigned char flags;
    char padd[0x13];
    unsigned short* table;
    unsigned short rows;
    unsigned short cols;
    unsigned short row;
    unsigned short col;
    Vec3_021f8e1c offset;
    int dirty;
    unsigned short snd3c;
    unsigned short snd3e;
    unsigned short snd40;
    unsigned short snd42;
    unsigned short snd44;
    unsigned short snd46;
    unsigned short snd48;
    unsigned short snd4a;
    unsigned short snd4c;
    unsigned short snd4e;
    unsigned short snd50;
    unsigned short snd52;
    unsigned short snd54;
    unsigned short snd56;
    unsigned short snd58;
    unsigned short snd5a;
    short page;
    short pageCount;
    unsigned char wrap;
    unsigned char confirmSe;
    unsigned char noCancel;
};

struct Obj_02184a00;
struct Obj_02184bd8;
struct Obj_02184bcc;
struct Obj021f6f08;
struct Owner02047a5c;
struct Owner02047a3c;
struct Obj0205eaa0;

extern "C" unsigned short _Z25GetShortField1b0_02184a00P12Obj_02184a00(struct Obj_02184a00* obj);
extern "C" int _Z22GetSignedField020c39c8PVt(volatile unsigned short* p);
int TestFlag0SetAndFlag1Clear(unsigned short* obj, int mask);
int TestFlagMask(unsigned short* obj, int mask);
void SelectCoordsByFlag0x24(unsigned char* obj, int* out1, int* out2);
extern "C" void* _Z20AddOffset20_021f7318Pv(void* p);
#if defined(jpn)
extern "C"
#endif
unsigned char GetEntryByteIfFlag0x84(struct Owner02047a5c* owner, int index);
int GetElementByte1IfEnabled(struct Owner02047a3c* obj, int index);
extern "C" unsigned short _Z28GetShortAt_021f8c50_021f8c50Ph(unsigned char* obj);
extern "C" unsigned short _Z28GetShortAt_021f8c60_021f8c60Ph(unsigned char* obj);
extern "C" unsigned int _Z18GetShort6_021f6f08P11Obj021f6f08(struct Obj021f6f08* obj);
extern "C" int _Z20GetField1c8_02184bd8P12Obj_02184bd8(struct Obj_02184bd8* obj);
extern "C" void _Z25SetField1c8False_02184bccP12Obj_02184bcc(struct Obj_02184bcc* obj);
extern "C" void _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(struct Obj0205eaa0* obj, int a, int b);
extern "C" void* _Z29GetLinkedNodeIfKind6_021f9cb8PvS_S_(void* unused, void* other, void* node);

extern "C" void __clear(void* buf, int n);
extern "C" void* func_ov011_021849c8(void* obj);
extern "C" void func_ov011_021848a0(void* obj, int val);
extern "C" void func_ov011_02184a40(void* obj, int val);
extern "C" int func_ov023_021f9bc8(void* obj);
extern "C" Node021f8e1c* func_ov023_021f6880(void* base, int key);
extern "C" int func_ov023_021f6f10(void* obj);
extern "C" void func_ov023_021f88b8(void* obj, void* other, int id);
extern "C" Vec3_021f8e1c func_ov023_021f8b78(void* src, void* other);
extern "C" void func_ov023_021f98e0(void* obj, void* other);
extern "C" int func_ov023_021f9da8(void* obj, void* other, int x, int y);

extern unsigned short data_02114e30;
extern unsigned char data_02114e54[];
extern struct Obj0205eaa0 data_02108760;
extern unsigned int data_ov023_021fff24;
extern const unsigned short data_ov023_021fd922[];

static inline int GetMasterBrightnessMain_021f8e1c() { return _Z22GetSignedField020c39c8PVt((volatile unsigned short*)0x400006c); }
static inline int GetMasterBrightnessSub_021f8e1c() { return _Z22GetSignedField020c39c8PVt((volatile unsigned short*)0x400106c); }

// USA: func_ov023_021f8e1c
extern "C" ARM void func_ov023_021f8e1c(Cursor021f8e1c* self, void* other) {
    if (self->id != _Z25GetShortField1b0_02184a00P12Obj_02184a00((struct Obj_02184a00*)other)) {
        return;
    }
    if (self->flags & 0x10) {
        return;
    }
    func_ov023_021f9bc8(self);

    int row;
    int scroll;
    int cell;
    int locked = 0;
    if (GetMasterBrightnessMain_021f8e1c() != 0 && GetMasterBrightnessSub_021f8e1c() != 0) {
        locked = 1;
    }

    void* nodes = func_ov011_021849c8(other);
    int done = 0;
    row = self->row;
    int col = self->col;

    unsigned short pressSe[5];
    __clear(pressSe, sizeof(pressSe));
    pressSe[1] = self->snd3e;
    pressSe[2] = self->snd3c;
    unsigned short releaseSe[5];
    releaseSe[0] = self->snd4a;
    releaseSe[1] = self->snd50;
    releaseSe[2] = self->snd52;
    releaseSe[3] = self->snd58;
    releaseSe[4] = self->snd5a;

    if (!locked) {
        for (int i = 0; i < 5; i++) {
            if (TestFlag0SetAndFlag1Clear(&data_02114e30, data_ov023_021fd922[i])) {
                int played = 0;
                if (pressSe[i] != 0) {
                    func_ov011_021848a0(other, pressSe[i]);
                    played = 1;
                }
                if (releaseSe[i] != 0) {
                    func_ov011_02184a40(other, releaseSe[i]);
                    played = 1;
                }
                if (played) {
                    return;
                }
            }
        }
    }

    int cancel = 0;
    if (self->noCancel != 0) {
        if (TestFlag0SetAndFlag1Clear(&data_02114e30, 0x400)) {
            cancel = 1;
        }
    }
    if (TestFlag0SetAndFlag1Clear(&data_02114e30, 1) || cancel) {
        done = 1;
    }
    int up = TestFlag0SetAndFlag1Clear(&data_02114e30, 0x40);
    int down = TestFlag0SetAndFlag1Clear(&data_02114e30, 0x80);
    int left = TestFlag0SetAndFlag1Clear(&data_02114e30, 0x20);
    int right = TestFlag0SetAndFlag1Clear(&data_02114e30, 0x10);

    if (done == 0) {
        unsigned int dt = GameState::GetInstance()->GetEffectiveDeltaTime();
        if (TestFlagMask(&data_02114e30, 0x40)) {
            if (data_ov023_021fff24 < dt) {
                up = 1;
            } else {
                data_ov023_021fff24 -= dt;
            }
        } else if (TestFlagMask(&data_02114e30, 0x80)) {
            if (data_ov023_021fff24 < dt) {
                down = 1;
            } else {
                data_ov023_021fff24 -= dt;
            }
        } else if (TestFlagMask(&data_02114e30, 0x20)) {
            if (data_ov023_021fff24 < dt) {
                left = 1;
            } else {
                data_ov023_021fff24 -= dt;
            }
        } else if (TestFlagMask(&data_02114e30, 0x10)) {
            if (data_ov023_021fff24 < dt) {
                right = 1;
            } else {
                data_ov023_021fff24 -= dt;
            }
        } else {
            data_ov023_021fff24 = 500;
        }
    }

    int moved = 0;
    if (up) {
        row--;
        if (self->snd4c != 0) {
            func_ov011_02184a40(other, self->snd4c);
            return;
        }
    } else if (down) {
        row++;
        if (self->snd4e != 0) {
            func_ov011_02184a40(other, self->snd4e);
            return;
        }
    } else if (left) {
        col--;
        if (self->snd56 != 0) {
            func_ov011_02184a40(other, self->snd56);
            return;
        }
    } else if (right) {
        col++;
        if (self->snd54 != 0) {
            func_ov011_02184a40(other, self->snd54);
            return;
        }
    }

    scroll = 0;
    if (self->wrap != 0) {
        int top;
        for (top = 0; top < self->rows; top++) {
            if (self->table[top * self->cols + self->col] != 0) {
                break;
            }
        }
        int bottom;
        for (bottom = self->rows - 1; bottom >= 0; bottom--) {
            if (self->table[bottom * self->cols + self->col] != 0) {
                break;
            }
        }
        int leftmost;
        for (leftmost = 0; leftmost < self->cols; leftmost++) {
            if (self->table[self->row * self->cols + leftmost] != 0) {
                break;
            }
        }
        int rightmost;
        for (rightmost = self->cols - 1; rightmost >= 0; rightmost--) {
            if (self->table[self->row * self->cols + rightmost] != 0) {
                break;
            }
        }
        if (row < top) {
            row = bottom;
        } else if (bottom < row) {
            row = top;
        } else if (col < leftmost) {
            col = leftmost;
            scroll = -1;
            if (self->pageCount == 1) {
                col = rightmost;
            }
        } else if (rightmost < col) {
            col = rightmost;
            scroll = 1;
            if (self->pageCount == 1) {
                col = leftmost;
            }
        }
    } else {
        if (row < 0) {
            row = 0;
        } else if (self->rows <= row) {
            row = self->rows - 1;
        } else if (col < 0) {
            col = 0;
            scroll = -1;
        } else if (self->cols <= col) {
            col = self->cols - 1;
            scroll = 1;
        }
    }

    int idx = row * self->cols + col;
    if (self->pageCount == 1) {
        scroll = 0;
    }
    if (self->table[idx] == 0) {
        row = self->row;
        col = self->col;
    }
    if (row != self->row || col != self->col) {
        moved = 1;
        Node021f8e1c* node = func_ov023_021f6880(nodes, self->table[func_ov023_021f9bc8(self)]);
        void* linked = _Z29GetLinkedNodeIfKind6_021f9cb8PvS_S_(self, other, node);
        if (linked != 0) {
            func_ov023_021f88b8(linked, other, 0x8000);
        }
    }

    if (moved == 0 && data_02114e54[0x55] != 0) {
        int touchX;
        int touchY;
        SelectCoordsByFlag0x24(data_02114e54, &touchX, &touchY);
        scroll = func_ov023_021f9da8(self, other, touchX, touchY);
        if (scroll == 0) {
            int x;
            int y;
            int w;
            int h;
            int total = self->cols * self->rows;
            for (cell = 0; cell < total; cell++) {
                x = y = w = h = 0;
                if (self->table[cell] == 0) {
                    continue;
                }
                Node021f8e1c* node = func_ov023_021f6880(nodes, self->table[cell]);
                if (node == 0) {
                    continue;
                }
                Vec3_021f8e1c pos = node->GetPos();
                if (func_ov023_021f6f10(node) == 0) {
                    x = (int)(pos.x / 4096.0f);
                    y = (int)(pos.y / 4096.0f);
                    void* elem = _Z20AddOffset20_021f7318Pv(node);
                    w = GetEntryByteIfFlag0x84((struct Owner02047a5c*)elem, 0);
                    h = GetElementByte1IfEnabled((struct Owner02047a3c*)elem, 0);
                } else if (func_ov023_021f6f10(node) == 8) {
                    const Vec3_021f8e1c* v = AddrOf_021f8e1c(func_ov023_021f8b78(node, other));
                    pos.x = v->x;
                    pos.y = v->y;
                    pos.z = v->z;
                    x = (int)(pos.x / 4096.0f) + node->offX;
                    y = (int)(pos.y / 4096.0f) + node->offY;
                    w = _Z28GetShortAt_021f8c50_021f8c50Ph((unsigned char*)node);
                    h = _Z28GetShortAt_021f8c60_021f8c60Ph((unsigned char*)node);
                }
                if (x < touchX && touchX <= x + w && y < touchY && touchY <= y + h) {
                    col = cell % self->cols;
                    row = cell / self->cols;
                    node = func_ov023_021f6880(nodes, self->table[row * self->cols + col]);
                    if (node != 0 && func_ov023_021f6f10(node) == 8 && node->IsDisabled() == 0) {
                        void* linked = _Z29GetLinkedNodeIfKind6_021f9cb8PvS_S_(self, other, node);
                        if (linked != 0) {
                            func_ov023_021f88b8(linked, other, (unsigned short)_Z18GetShort6_021f6f08P11Obj021f6f08((struct Obj021f6f08*)node));
                        }
                    } else if (row == self->row && col == self->col) {
                        done = 1;
                    }
                    break;
                }
            }
        }
    }

    if (row != self->row || col != self->col) {
        self->row = row;
        self->col = col;
        self->dirty = 1;
    }
    if (_Z20GetField1c8_02184bd8P12Obj_02184bd8((struct Obj_02184bd8*)other)) {
        self->dirty = 1;
        _Z25SetField1c8False_02184bccP12Obj_02184bcc((struct Obj_02184bcc*)other);
    }
    if (self->dirty) {
        func_ov023_021f98e0(self, other);
    }

    if (scroll != 0) {
        self->page += scroll;
        if (self->pageCount <= self->page) {
            self->page = 0;
        } else if (self->page < 0) {
            self->page = self->pageCount - 1;
        }
        if (self->snd48 != 0) {
            func_ov011_02184a40(other, self->snd48);
        }
        return;
    }

    if (up || down || left || right) {
        return;
    }

    if (done != 0) {
        if (locked) {
            return;
        }
        col = self->col;
        row = self->row;
        Node021f8e1c* node = func_ov023_021f6880(nodes, self->table[row * self->cols + col]);
        int played = 0;
        if (node != 0) {
            int se = node->GetSoundA();
            if (se > 0) {
                func_ov011_021848a0(other, se);
                played = 1;
            }
            se = node->GetSoundB();
            if (se > 0) {
                func_ov011_02184a40(other, se);
                played = 1;
            }
        }
        if (self->snd42 != 0) {
            func_ov011_021848a0(other, self->snd42);
        }
        if (self->snd40 != 0) {
            func_ov011_02184a40(other, self->snd40);
        }
        if (played && self->confirmSe != 0) {
            _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(&data_02108760, 1, 0);
        }
    }

    if (TestFlag0SetAndFlag1Clear(&data_02114e30, 2)) {
        if (locked) {
            return;
        }
        if (self->snd44 != 0) {
            func_ov011_021848a0(other, self->snd44);
        }
        if (self->snd46 != 0) {
            func_ov011_02184a40(other, self->snd46);
        }
    }

    if (TestFlag0SetAndFlag1Clear(&data_02114e30, 0x400)) {
        if (self->noCancel == 0 && !locked) {
            col = self->col;
            row = self->row;
            Node021f8e1c* node = func_ov023_021f6880(nodes, self->table[row * self->cols + col]);
            int played = 0;
            if (node != 0) {
                int se = node->GetSoundC();
                if (se > 0) {
                    func_ov011_02184a40(other, se);
                    played = 1;
                }
            }
            if (played && self->confirmSe != 0) {
                _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(&data_02108760, 1, 0);
            }
        }
    }
}
