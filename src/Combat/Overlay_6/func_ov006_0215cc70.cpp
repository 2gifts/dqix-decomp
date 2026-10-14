#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"

struct Entry0215cc70 {
    short id;
    char pad2[0x14 - 0x2];
    short count;
};

struct Ctx0215cc70 {
    char pad0[0xae2];
    unsigned short flags;
};

struct Obj0215cc70 {
    char pad0[0x4];
    void** buffer;
    char pad8[0x10 - 0x8];
    Ctx0215cc70* ctx;
    void* elements;
    char pad18[0x34 - 0x18];
    Entry0215cc70* entry;
    char pad38[0x3c - 0x38];
    char loader[0x74 - 0x3c];
    char table[0x14c - 0x74];
    char out[0x170 - 0x14c];
    char lookup[0x17c - 0x170];
    char list[0x1ec - 0x17c];
    short lookupId;
    char pad1ee[0x364 - 0x1ee];
    short selected;
    char pad366[0x378 - 0x366];
    short ids[3];
    short message;
    char pad380[0x382 - 0x380];
    short chance;
    char pad384[0x387 - 0x384];
    unsigned char mergeCount;
    char pad388[0x38c - 0x388];
    unsigned char mergeBuf[3];
    unsigned char mode;
    unsigned char state;
    char pad391;
    unsigned char messageTimer;
    char pad393;
    unsigned short flags;
    unsigned char variant;
    char pad397[0x3b4 - 0x397];
    int busy;
    char pad3b8[0x428 - 0x3b8];
    int taskId;
    unsigned char field42c;
    unsigned char waitCount;
    unsigned char nextState;
    unsigned char field42f;
    char pad430[0x432 - 0x430];
    unsigned char field432;

    int IsCritical() { return (flags & 0x40) != 0; }
};

Entry0215cc70* MergeIntoBuffers_0215fd60(void*, short*, unsigned char*, int);
extern "C" int func_ov006_02153f24(void* table, int id);
struct Obj02159094;
void ExpireStatusSlot02159094(Obj02159094*);
extern "C" void _Z13Func_0215a33cP11Obj0215a33c(Obj0215cc70* self, int critical);
extern "C" int func_ov006_0215a384(Obj0215cc70* self, int critical);
extern "C" void func_ov006_0215fe34(Obj0215cc70* self, void* list);
extern "C" int func_ov006_0215fecc(Obj0215cc70* self);
int GetField0x3acValue_020100a8(GameState* gs);
extern "C" int func_020dd4c4(signed char a, void* list);
extern "C" void func_ov006_02159db0(Obj0215cc70* self);
extern "C" int func_ov006_02159e50(Obj0215cc70* self);
int CheckAnyFlag_021570b4(char*);
void* GetBTRandom(void);
struct Random;
unsigned int NextRandomMax(Random*, int);
struct Obj2081;
void SetElementFlag0x20_02080c04(Obj2081*, int);
void ClearElementFlag0x20_02080c20(Obj2081*, int);
extern "C" int _Z26CheckFlagOrByte55_02158c70v(Obj0215cc70* self);
extern "C" void func_ov006_02153cbc(void* table, int a, int b, void* out);
extern "C" void func_ov006_0215759c(void* list, Entry0215cc70* entry, int count);
extern "C" void func_ov006_02158de0(Obj0215cc70* self);
unsigned int* GetDataPtr02114e04_020d6c00(void);
void OrBitsIntoField0_020466e4(unsigned int* p, unsigned int bits);
struct Struct020a9ea4;
void ClearStruct020a9ea4(Struct020a9ea4*);
extern "C" void* func_0202ae18(void);
extern "C" int func_0202c540(void* p);
extern "C" int func_020aad1c(void* loader, void* name, int a, int b);
struct FlagWord020466f4;
void ClearFlags020466f4(FlagWord020466f4*, unsigned int);
void** CallFunc020e52a0_020e5294(void* lookup, int id);
extern "C" void* memset(void* dst, int c, unsigned int n);
extern "C" void func_020e4864(void* src, void* dst, int a, int b, int c, int d);
struct Container02080f8c;
void SetEntryFirstField02080f8c(Container02080f8c*, int, int);
void Forward0207f7acObjPlus4Size0x40_020805f4(void* elements, int key);
extern "C" void func_020813ec(void* elements, int key);
void InitHandleAndDispatch_021571fc(char*);
struct Struct0209c830;
void SetValueAndActivate0209c830(Struct0209c830*, int);
void CallFunc0204c804OnMatchingKey_0207fdcc(Obj2081*, int);
void SetByte_0215728c_0215728c(void*);

static inline short* ChancePtr(Obj0215cc70* self) { return (short*)((char*)self + 0x382); }
static inline short* ChanceWords(Obj0215cc70* self) { return (short*)self; }
static inline Entry0215cc70* GetEntry(Obj0215cc70* self) { return *(Entry0215cc70**)((char*)self + 0x34); }

extern int data_0211e33c;
extern int data_02109bf4;

// USA: func_ov006_0215cc70
extern "C" ARM void func_ov006_0215cc70(Obj0215cc70* self) {
    Ctx0215cc70* ctx = self->ctx;
    BackgroundLoader::GetInstance();

    if (self->state == 0) {
        Entry0215cc70* entry;
        self->busy = 0;
        self->mergeCount = 0;
        entry = MergeIntoBuffers_0215fd60(self, self->ids, self->mergeBuf, (int)&self->mergeCount);
        self->entry = entry;
        if (entry != 0) {
            self->chance = func_ov006_02153f24(self->table, entry->id);
            self->state++;
        } else {
            ExpireStatusSlot02159094((Obj02159094*)self);
            ExpireStatusSlot02159094((Obj02159094*)self);
            ExpireStatusSlot02159094((Obj02159094*)self);
            self->state = 0x78;
            self->flags |= 0x20;
            self->message = 0xb;
            self->messageTimer = 0;
        }
    } else if (self->state == 1) {
        _Z13Func_0215a33cP11Obj0215a33c(self, 0);
        self->state++;
    } else if (self->state == 2) {
        if (self->taskId == -1) {
            if (func_ov006_0215a384(self, 0)) {
                func_ov006_0215fe34(self, self->list);
            }
        } else if (func_ov006_0215fecc(self)) {
            int r = func_020dd4c4(GetField0x3acValue_020100a8(GameState::GetInstance()), self->list);
            self->state = 5;
            if (r & 0x10) {
                self->flags |= 0x20;
                self->message = self->variant + 4;
                self->messageTimer = 0;
                self->state++;
            }
        }
    } else if (self->state == 3) {
        func_ov006_02159db0(self);
        self->state++;
    } else if (self->state == 4) {
        int r = func_ov006_02159e50(self);
        if (r != -1) {
            if (r == 1) {
                self->state++;
            }
        } else {
            ExpireStatusSlot02159094((Obj02159094*)self);
            ExpireStatusSlot02159094((Obj02159094*)self);
            ExpireStatusSlot02159094((Obj02159094*)self);
            self->state = 0x78;
        }
    } else if (self->state == 5) {
        if (CheckAnyFlag_021570b4((char*)ctx) == 0) {
            self->flags &= ~0x40;
            bool hasCount = false;
            if (self->entry != 0 && self->entry->count > 0) {
                hasCount = true;
            }
            if (hasCount) {
                self->chance = func_ov006_02153f24(self->table, GetEntry(self)->count);
                self->message = 0xd;
                self->messageTimer = 0;
                self->flags |= 0x20;
                self->state++;
                if (NextRandomMax((Random*)GetBTRandom(), 10000) / 100 < self->chance) {
                    self->flags |= 0x40;
                }
                _Z13Func_0215a33cP11Obj0215a33c(self, self->IsCritical());
            } else {
                SetElementFlag0x20_02080c04((Obj2081*)self->elements, 0x10);
                SetElementFlag0x20_02080c04((Obj2081*)self->elements, 0x11);
                SetElementFlag0x20_02080c04((Obj2081*)self->elements, 1);
                SetElementFlag0x20_02080c04((Obj2081*)self->elements, 0);
                self->ctx->flags |= 0x10;
                self->field432 = 1;
                self->waitCount = 0;
                self->nextState = 100;
                self->state = 0x96;
            }
        }
    } else if (self->state == 6) {
        if (_Z26CheckFlagOrByte55_02158c70v(self) && self->taskId == -1) {
            if (func_ov006_0215a384(self, self->IsCritical())) {
                func_ov006_0215fe34(self, self->list);
            }
        } else if (self->taskId != -1) {
            if (func_ov006_0215fecc(self)) {
                self->flags |= 0x20;
                self->message = self->variant + 0xe;
                self->messageTimer = 0;
                self->state++;
            }
        }
    } else if (self->state == 7) {
        if (_Z26CheckFlagOrByte55_02158c70v(self)) {
            short id = 0x10;
            if (self->chance >= 3 && self->chance < 10) {
                id = 0x11;
            } else if (*ChancePtr(self) >= 10 && *ChancePtr(self) <= 99) {
                id = 0x12;
            } else if (ChanceWords(self)[0x382 / 2] == 100) {
                id = self->variant + 0x16;
            }
            self->flags |= 0x20;
            self->message = id;
            self->messageTimer = 0;
            self->state++;
        }
    } else if (self->state == 8) {
        if (CheckAnyFlag_021570b4((char*)ctx) == 0) {
            if (_Z26CheckFlagOrByte55_02158c70v(self)) {
                short id = 0x13;
                self->state++;
                if (self->chance == 100) {
                    self->state = 0xb;
                    id = 0x18;
                }
                self->flags |= 0x20;
                self->message = id;
                self->messageTimer = 0;
            }
        }
    } else if (self->state == 9) {
        if (_Z26CheckFlagOrByte55_02158c70v(self)) {
            self->flags |= 0x20;
            self->message = 0x14;
            self->messageTimer = 0;
            self->state++;
        }
    } else if (self->state == 10) {
        if (_Z26CheckFlagOrByte55_02158c70v(self)) {
            self->flags |= 0x20;
            self->message = 0x15;
            self->messageTimer = 0;
            self->state++;
        }
    } else if (self->state == 0xb) {
        func_ov006_02159db0(self);
        self->state++;
    } else if (self->state == 0xc) {
        int r = func_ov006_02159e50(self);
        if (r != -1) {
            if (r == 1) {
                if (self->IsCritical()) {
                    func_ov006_02153cbc(self->table, self->entry->count, self->entry->id, self->out);
                } else {
                    func_ov006_02153cbc(self->table, self->entry->id, -1, self->out);
                }
                func_ov006_0215759c(self->list, self->entry, self->mergeCount);
                func_ov006_02158de0(self);
                self->selected = -1;
                self->state++;
            }
        } else {
            ExpireStatusSlot02159094((Obj02159094*)self);
            ExpireStatusSlot02159094((Obj02159094*)self);
            ExpireStatusSlot02159094((Obj02159094*)self);
            self->flags = (self->flags | 0x20) & ~0x40;
            ClearElementFlag0x20_02080c20((Obj2081*)self->elements, 0);
            self->message = 0x19;
            self->messageTimer = 0;
            self->flags |= 0x20;
            self->state = 0x5a;
        }
    } else if (self->state == 0x5a) {
        if (_Z26CheckFlagOrByte55_02158c70v(self)) {
            ClearElementFlag0x20_02080c20((Obj2081*)self->elements, 0);
            self->message = 0x24;
            self->messageTimer = 0;
            self->flags |= 0x20;
            self->flags |= 0x100;
            self->mode = 5;
            self->state = 0;
        }
    } else if (self->state == 0xd) {
        self->message = 0x36;
        self->messageTimer = 0;
        SetElementFlag0x20_02080c04((Obj2081*)self->elements, 0);
        self->state++;
    } else if (self->state == 0xe) {
        self->flags |= 0x200;
        if (BackgroundLoader::GetInstance()->GetNumQueuedTasks() <= 0) {
            OrBitsIntoField0_020466e4(GetDataPtr02114e04_020d6c00(), 0x80);
            ClearStruct020a9ea4((Struct020a9ea4*)self->loader);
            self->state++;
        }
    } else if (self->state == 0xf) {
        int size;
        BackgroundLoader::AddLockGlobal();
        BackgroundLoader::FreeAllocationsGlobal();
        size = 8;
        if (func_0202c540(func_0202ae18())) {
            size = 0x14;
        }
        if (func_020aad1c(self->loader, &data_0211e33c, size, 0) == 1) {
            ClearFlags020466f4((FlagWord020466f4*)GetDataPtr02114e04_020d6c00(), 0x80);
            self->state++;
            self->flags &= ~0x200;
        }
        BackgroundLoader::RemoveLockGlobal();
    } else if (self->state == 0x10) {
        self->message = 0x37;
        self->messageTimer = 0;
        self->state++;
    } else if (self->state == 0x11) {
        if (_Z26CheckFlagOrByte55_02158c70v(self)) {
            self->message = 0x1a;
            self->messageTimer = 0;
            self->flags |= 0x20;
            ClearElementFlag0x20_02080c20((Obj2081*)self->elements, 0);
            self->state++;
        }
    } else if (self->state == 0x12) {
        self->field42c = 0;
        if (_Z26CheckFlagOrByte55_02158c70v(self)) {
            SetElementFlag0x20_02080c04((Obj2081*)self->elements, 0x10);
            SetElementFlag0x20_02080c04((Obj2081*)self->elements, 0x11);
            SetElementFlag0x20_02080c04((Obj2081*)self->elements, 1);
            SetElementFlag0x20_02080c04((Obj2081*)self->elements, 0);
            self->ctx->flags |= 0x10;
            self->field432 = 1;
            self->waitCount = 0;
            self->nextState = 0x13;
            self->state = 0x96;
        }
    } else if (self->state == 0x13) {
        ctx->flags |= 0x100;
        self->state++;
    } else if (self->state == 0x14) {
        ctx->flags |= 0x200;
        self->state++;
    } else if (self->state == 0x15) {
        void** res;
        int sound;
        self->busy = 1;
        res = CallFunc020e52a0_020e5294(self->lookup, self->lookupId);
        if (res != 0) {
            memset(*self->buffer, 0, 0x80);
            func_020e4864(*res, *self->buffer, 1, 0, 0, 0);
            SetEntryFirstField02080f8c((Container02080f8c*)self->elements, 0x7f, (int)(*self->buffer));
        }
        Forward0207f7acObjPlus4Size0x40_020805f4(self->elements, 0x7f);
        func_020813ec(self->elements, 0x12);
        ctx->flags |= 0x400;
        self->field42f = 1;
        sound = 0x3e;
        if (self->IsCritical()) {
            sound = 0x3f;
            InitHandleAndDispatch_021571fc((char*)self->ctx);
        }
        SetValueAndActivate0209c830((Struct0209c830*)&data_02109bf4, sound);
        self->message = 0xc;
        self->messageTimer = 0;
        self->state++;
    } else if (self->state == 0x16) {
        if (_Z26CheckFlagOrByte55_02158c70v(self)) {
            self->message = 0x38;
            self->messageTimer = 0;
            self->state++;
        }
    } else if (self->state == 0x17) {
        if (_Z26CheckFlagOrByte55_02158c70v(self)) {
            short id;
            CallFunc0204c804OnMatchingKey_0207fdcc((Obj2081*)self->elements, 0x12);
            self->busy = 0;
            ctx->flags &= ~0x800;
            id = 0x1f;
            if (self->IsCritical()) {
                SetByte_0215728c_0215728c(self->ctx);
                id = self->variant + 0x1b;
            }
            self->flags |= 0x20;
            self->message = id;
            self->messageTimer = 0;
            self->state++;
        }
    } else if (self->state == 0x18) {
        if (_Z26CheckFlagOrByte55_02158c70v(self)) {
            short id = 0x20;
            if (self->IsCritical()) {
                id = self->variant + 0x1d;
            }
            self->flags |= 0x20;
            self->message = id;
            self->messageTimer = 0;
            self->state = 0x78;
            self->flags &= ~0x40;
        }
    } else if (self->state == 100) {
        ctx->flags |= 0x100;
        self->state++;
    } else if (self->state == 0x65) {
        ctx->flags |= 0x200;
        self->state++;
    } else if (self->state == 0x66) {
        if (self->entry != 0) {
            void** res;
            self->busy = 1;
            res = CallFunc020e52a0_020e5294(self->lookup, self->lookupId);
            if (res != 0) {
                memset(*self->buffer, 0, 0x80);
                func_020e4864(*res, *self->buffer, 1, 0, 0, 0);
                SetEntryFirstField02080f8c((Container02080f8c*)self->elements, 0x7f, (int)(*self->buffer));
            }
            Forward0207f7acObjPlus4Size0x40_020805f4(self->elements, 0x7f);
            func_020813ec(self->elements, 0x12);
            func_ov006_02153cbc(self->table, self->entry->id, -1, self->out);
            func_ov006_0215759c(self->list, self->entry, self->mergeCount);
            func_ov006_02158de0(self);
            self->selected = -1;
            self->field42f = 1;
            SetValueAndActivate0209c830((Struct0209c830*)&data_02109bf4, 0x3e);
            ctx->flags |= 0x400;
            SetElementFlag0x20_02080c04((Obj2081*)self->elements, 0);
            self->message = 0xc;
            self->messageTimer = 0;
            self->state++;
        } else {
            ExpireStatusSlot02159094((Obj02159094*)self);
            ExpireStatusSlot02159094((Obj02159094*)self);
            ExpireStatusSlot02159094((Obj02159094*)self);
            self->flags |= 0x20;
            self->message = 0xb;
            self->messageTimer = 0;
            self->state = 0x78;
        }
    } else if (self->state == 0x67) {
        if (_Z26CheckFlagOrByte55_02158c70v(self)) {
            self->message = 0x38;
            self->messageTimer = 0;
            self->state = 0x78;
        }
    } else if (self->state == 0x78) {
        if (self->field42f != 0) {
            self->field42c = 0;
        } else if (_Z26CheckFlagOrByte55_02158c70v(self)) {
            CallFunc0204c804OnMatchingKey_0207fdcc((Obj2081*)self->elements, 0x12);
            ctx->flags &= ~0x800;
            ClearElementFlag0x20_02080c20((Obj2081*)self->elements, 0);
            self->flags |= 0x20;
            self->message = 0x24;
            self->messageTimer = 0;
            self->flags |= 0x100;
            self->mode = 5;
            self->state = 0;
        }
    } else if (self->state == 0x96) {
        unsigned short* flags = &ctx->flags;
        ctx->flags |= 0x2000;
        self->waitCount++;
        if (self->waitCount >= 10) {
            self->waitCount = 0;
            *flags &= ~0x2000;
            *flags |= 0x80;
            self->state = self->nextState;
        }
    }
}
