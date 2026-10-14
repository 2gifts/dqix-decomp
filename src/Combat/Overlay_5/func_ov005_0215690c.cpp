#include <globaldefs.h>
#include "GameState/Field3b0.h"
#include <GameState/GameState.h>
#include <Graphics/Vector.h>

struct Obj0205eaa0;
struct Vec3copy0202ec84;
struct Field150Holder02052df8;

struct Body {
    char unk_0[0x50];
    Vector3fix rotation_;
};

struct MemberScreen {
#if defined(jpn)
    char unk_0[0x4f8];
#else
    char unk_0[0x4fc];
#endif
    int member_;
#if defined(jpn)
    char unk_500[0x56c - 0x4fc];
#else
    char unk_500[0x634 - 0x500];
#endif
    unsigned short flags_;
};

struct EquipmentSlot {
    short item_;
    signed char count_;
    unsigned char equipped_;
    void* vramState_;
    void* model_;
    int x_;
    int y_;
    int offset_;
    short loadedItem_;
};

struct EquipmentMenu {
#if defined(jpn)
    char unk_0[0x196c];
#else
    char unk_0[0x19f4];
#endif
    char cursor_[0x2d90 - 0x19f4];
    EquipmentSlot slots_[24];
    char slotModels_[0x3d78 - 0x3030];
    short dragged_;
    char unk_3d7a[0x3d98 - 0x3d7a];
    short itemCounts_[8];
    unsigned char unk_3da8;
    unsigned char equippedStep_;
    unsigned char pageStep_;
    char unk_3dab[0x3db8 - 0x3dab];
    unsigned char state_;
    unsigned char lastState_;
    unsigned char step_;
    signed char slot_;
    unsigned char kind_;
    signed char page_;
    unsigned char unk_3dbe;
    signed char lastPage_;
    signed char unk_3dc0;
    char unk_3dc1[0x3dcc - 0x3dc1];
    unsigned int flags_;
    char unk_3dd0[0x3dfc - 0x3dd0];
    unsigned char pages_[8];
};

#if defined(jpn)
#define data_ov005_0215cc84 data_ov005_0215e064
#define data_ov005_0215cc14 data_ov005_0215dff4
#define data_ov005_0215cd58 data_ov005_0215e138
#define data_ov005_0215cd50 data_ov005_0215e130
#endif

extern const Vector3fix data_ov005_0215cc84[8];
extern const signed char data_ov005_0215cc14[8];
extern unsigned char data_ov005_0215cd58[8];
extern unsigned char data_ov005_0215cd50[8];
extern int data_02108760;

MemberScreen* GetField1c_021a193c(int* p);
extern "C" int func_ov005_02157ae8(EquipmentMenu* self, int member);
struct Obj021e4e20;
Body* RunIfPtr_021e4e20(Obj021e4e20*);
extern "C" int func_ov005_02155670(EquipmentMenu* self, int x, int y);
int ComputeTwoFromVec3_0202ec84(void* obj, Vec3copy0202ec84* src, int* out1, int* out2);
GameObject* GetCombatantWithFlag0x100(GameState* gs, int id);
extern "C" double func_0200b454(double x);
short GetHalfwordEntryFromField150(Field150Holder02052df8* obj, int index);
extern "C" int func_ov005_02158560(EquipmentMenu* self, unsigned char kind, int silent);
extern "C" void func_ov005_0215792c(EquipmentMenu* self, unsigned char state);
extern "C" void func_ov005_021579ec(EquipmentMenu* self, unsigned int state, unsigned char slot);
extern "C" void func_ov005_021555c0(EquipmentMenu* self);
void* GetPtrField0x2a04(GameState* gs);
short* GetPointerFromArray0xbd0(unsigned char* obj, unsigned int index);
extern "C" void func_0205bb04(void* cursor, int index);
void DispatchWithShortB4_0205eaa0(Obj0205eaa0* obj, int a, int b);

// USA: func_ov005_0215690c
extern "C" ARM void func_ov005_0215690c(EquipmentMenu* self, int x, int y) {
    GameState* gameState;
    Body* body;
    gameState = GameState::GetInstance();
    unsigned char page;
    MemberScreen* screen = GetField1c_021a193c((int*)func_ov017_0218b5b0()->unknown_ptr_array_36fc[3]);
    unsigned int member = screen->member_;
    if (!func_ov005_02157ae8(self, member))
        return;
    body = RunIfPtr_021e4e20((Obj021e4e20*)screen);
    func_ov005_02155670(self, x, y);
    short item = -1;
    unsigned char kind = 0xff;
    if (x > 0 && x < 0x80) {
        int screenX[8];
        void* camera;
        int dx;
        int screenY[8];
        camera = GetField0x3b0Value(gameState);
        int count;
        Matrix4x3 matrix;
        Vector3fix positions[8];
        matrix = RotationMatrixY(body->rotation_.y);
        for (int i = 0; i < 8; i++) {
            Mat4x3_ApplyToVector(&data_ov005_0215cc84[i], &matrix, &positions[i]);
            ComputeTwoFromVec3_0202ec84(camera, (Vec3copy0202ec84*)&positions[i], &screenX[i], &screenY[i]);
        }
        GameObject* partyMember = GetCombatantWithFlag0x100(gameState, member);
        count = 0;
        float radii[8];
        int touched[8];
        for (int i = 0; i < 8; i++) {
            radii[i] = 20.0f;
            int dy = y - screenY[i];
            int dx = x - screenX[i];
            if ((float)func_0200b454(dx * dx + dy * dy) < radii[i])
                touched[count++] = i;
        }
        if (count > 0) {
            int equippedCount = 0;
            int found = 0;
            int equipped[8];
            for (int i = 0; i < count; i++) {
                int part = touched[i];
                if (GetHalfwordEntryFromField150((Field150Holder02052df8*)partyMember, data_ov005_0215cc14[part]) > 0) {
                    equipped[equippedCount] = part;
                    found = 1;
                    equippedCount++;
                }
            }
            if (found) {
                int best = equipped[0];
                int bestZ = positions[best].z;
                for (int i = 1; i < equippedCount; i++) {
                    int part = equipped[i];
                    if (bestZ < positions[part].z) {
                        best = part;
                        bestZ = positions[part].z;
                    }
                }
                kind = data_ov005_0215cd58[best];
                item = GetHalfwordEntryFromField150((Field150Holder02052df8*)partyMember, data_ov005_0215cc14[best]);
            } else {
                int best = touched[0];
                int bestZ = positions[best].z;
                for (int i = 1; i < count; i++) {
                    int part = touched[i];
                    if (bestZ < positions[part].z) {
                        best = part;
                        bestZ = positions[part].z;
                    }
                }
                kind = data_ov005_0215cd58[best];
                if (self->kind_ != kind) {
                    func_ov005_02158560(self, kind, 1);
                    self->slot_ = 8;
                    func_ov005_0215792c(self, 4);
                    func_ov005_021579ec(self, self->state_, self->slot_);
                    self->flags_ |= 0x100;
                    func_ov005_021555c0(self);
                    return;
                }
            }
        }
    } else if (x > 0x84 && x < 0x9d && y > 0x16 && y < 0x2d) {
        kind = self->kind_;
        item = self->slots_[kind].item_;
    }
    if (item <= 0)
        return;
    int changed = 0;
    if (self->kind_ != kind) {
        changed = 1;
        func_ov005_02158560(self, kind, 1);
        self->flags_ |= 0x100;
    }
    short* items = GetPointerFromArray0xbd0((unsigned char*)GetPtrField0x2a04(gameState) + 0x1d4, data_ov005_0215cd50[self->kind_]);
    int empty = -1;
    int index = -1;
    for (short i = 0; i < self->itemCounts_[self->kind_]; i++) {
        short other = items[i];
        if (item == other) {
            index = i;
            break;
        }
        if (empty < 0 && other == -1)
            empty = i;
    }
    if (index < 0)
        index = empty;
    page = index / 16;
    if (self->page_ != page) {
        self->lastPage_ = self->page_;
        self->page_ = page;
        changed = 1;
        self->pages_[self->kind_] = self->page_;
    }
    if (changed) {
        func_ov005_021555c0(self);
        self->flags_ |= 0x40;
        self->pageStep_ = 0;
    }
    func_ov005_0215792c(self, 3);
    self->dragged_ = self->kind_;
    self->slot_ = self->dragged_;
    func_0205bb04(self->cursor_, self->dragged_);
    self->unk_3dc0 = 1;
    self->flags_ |= 0x80;
    DispatchWithShortB4_0205eaa0((Obj0205eaa0*)&data_02108760, 2, 0);
    screen->flags_ &= ~1;
    screen->flags_ &= ~0x80;
    self->flags_ &= ~4;
    self->flags_ &= ~8;
}
