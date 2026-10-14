#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

struct Entry0215e69c {
    short id;
    char pad2[0x14 - 0x2];
    short count;
};

struct Task0215e69c {
    char pad0[0x14];
    unsigned char active;
};

struct Ctx0215e69c {
    char pad0[0xae2];
    unsigned short flags;
    char padae4[0x12a0 - 0xae4];
    Task0215e69c task;

    Task0215e69c* GetTask() { return &task; }
};

struct Obj0215e69c {
    char pad0[0x4];
    void** buffer;
    char pad8[0x10 - 0x8];
    Ctx0215e69c* ctx;
    void* elements;
    char pad18[0x34 - 0x18];
    Entry0215e69c* entry;
    char pad38[0x3c - 0x38];
    char loader[0x74 - 0x3c];
    char table[0x14c - 0x74];
    char out[0x170 - 0x14c];
    char lookup[0x17c - 0x170];
    char list[0x1ec - 0x17c];
    short lookupId;
    char pad1ee[0x37e - 0x1ee];
    short message;
    char pad380[0x382 - 0x380];
    short chance;
    char pad384[0x387 - 0x384];
    unsigned char mergeCount;
    unsigned char cursorA;
    unsigned char cursorB;
    char pad38a[0x38f - 0x38a];
    unsigned char mode;
    unsigned char state;
    char pad391;
    unsigned char messageTimer;
    char pad393;
    unsigned short flags;
    unsigned char variant;
    unsigned char shown;
    char pad398[0x3b4 - 0x398];
    int busy;
    char pad3b8[0x428 - 0x3b8];
    int taskId;
    unsigned char field42c;
    unsigned char waitCount;
    unsigned char nextState;
    unsigned char field42f;

    int IsCritical() { return (flags & 0x40) != 0; }
};

extern "C" int func_ov006_02153f24(void* table, int id);
extern "C" void _Z13Func_0215a33cP11Obj0215a33c(Obj0215e69c* self, int critical);
extern "C" int func_ov006_0215a384(Obj0215e69c* self, int critical);
extern "C" void func_ov006_0215fe34(Obj0215e69c* self, void* list);
extern "C" int func_ov006_0215fecc(Obj0215e69c* self);
extern "C" void func_ov006_02159db0(Obj0215e69c* self);
extern "C" int func_ov006_02159e50(Obj0215e69c* self);
void* GetBTRandom(void);
extern "C" unsigned int _Z13NextRandomMaxP6Randomi(void* rng, int max);
extern "C" void _Z18SetElementFlag0x20P7Obj2081i(void* elements, int key);
extern "C" void _Z20ClearElementFlag0x20P7Obj2081i(void* elements, int key);
extern "C" int _Z26CheckFlagOrByte55_02158c70v(Obj0215e69c* self);
extern "C" void func_ov006_02153cbc(void* table, int a, int b, void* out);
extern "C" void func_ov006_0215759c(void* list, Entry0215e69c* entry, int count);
extern "C" void func_ov006_02158de0(Obj0215e69c* self);
unsigned int* GetDataPtr02114e04_020d6c00(void);
void OrBitsIntoField0(unsigned int* p, unsigned int bits);
extern "C" void _Z19ClearStruct020a9ea4P14Struct020a9ea4(void* p);
extern "C" void* func_0202ae18(void);
extern "C" int func_0202c540(void* p);
extern "C" int func_020aad1c(void* loader, void* name, int a, int b);
extern "C" void _Z18ClearFlags020466f4P16FlagWord020466f4j(unsigned int* p, unsigned int bits);
void** CallFunc020e52a0(void* lookup, int id);
extern "C" void* memset(void* dst, int c, unsigned int n);
extern "C" void func_020e4864(void* src, void* dst, int a, int b, int c, int d);
extern "C" void _Z26SetEntryFirstField02080f8cP17Container02080f8cii(void* elements, int key, void* value);
void Forward0207f7acObjPlus4Size0x40(void* elements, int key);
extern "C" void func_020813ec(void* elements, int key);
extern "C" void _Z30InitHandleAndDispatch_021571fcPc(Ctx0215e69c* ctx);
extern "C" void _Z27SetValueAndActivate0209c830P14Struct0209c830t(void* p, int value);
extern "C" void _Z29CallFunc0204c804OnMatchingKeyP7Obj2081i(void* elements, int key);
extern "C" void _Z25SetByte_0215728c_0215728cPv(Ctx0215e69c* ctx);
void SetEntryLowNibbleAndElement02080c68(void* elements, int key, int value);
extern "C" void _Z34ToggleElementFlagsAndByte_0215e5f8P20Flags394Obj_0215e5f8P7Obj2081iPh(Obj0215e69c* self, void* elements, int flag, unsigned char* out);

static inline short* ChancePtr(Obj0215e69c* self) { return (short*)((char*)self + 0x382); }
static inline short* ChanceWords(Obj0215e69c* self) { return (short*)self; }

static inline int IsTaskActive(Task0215e69c* task) { return task != 0 && task->active != 0; }

extern int data_0211e33c;
extern int data_02109bf4;

// USA: func_ov006_0215e69c
extern "C" ARM void func_ov006_0215e69c(Obj0215e69c* self) {
    Ctx0215e69c* ctx = self->ctx;
    BackgroundLoader::GetInstance();

    if (self->state == 0) {
        self->busy = 0;
        if (_Z26CheckFlagOrByte55_02158c70v(self)) {
            _Z29CallFunc0204c804OnMatchingKeyP7Obj2081i(self->elements, 0);
            _Z29CallFunc0204c804OnMatchingKeyP7Obj2081i(self->elements, 1);
            SetEntryLowNibbleAndElement02080c68(self->elements, 9, 0);
            self->flags &= ~0x40;
            if (self->entry->count >= 0) {
                self->chance = func_ov006_02153f24(self->table, self->entry->count);
                self->message = 0xd;
                self->messageTimer = 0;
                self->flags |= 0x20;
                self->state++;
                if (_Z13NextRandomMaxP6Randomi(GetBTRandom(), 10000) / 100 < self->chance) {
                    self->flags |= 0x40;
                }
                _Z13Func_0215a33cP11Obj0215a33c(self, self->IsCritical());
            } else {
                ctx->flags &= ~0x40;
                self->waitCount = 0;
                self->nextState = 100;
                self->state = 0x96;
                _Z34ToggleElementFlagsAndByte_0215e5f8P20Flags394Obj_0215e5f8P7Obj2081iPh(self, self->elements, 0, &self->shown);
            }
        }
    } else if (self->state == 1) {
        if (_Z26CheckFlagOrByte55_02158c70v(self) && self->taskId == -1) {
            if (func_ov006_0215a384(self, self->IsCritical())) {
                func_ov006_0215fe34(self, self->list);
            }
        } else if (self->taskId != -1) {
            if (func_ov006_0215fecc(self)) {
                self->message = self->variant + 0xe;
                self->messageTimer = 0;
                self->state++;
            }
        }
    } else if (self->state == 2) {
        if (_Z26CheckFlagOrByte55_02158c70v(self)) {
            short id = 0x10;
            if (self->chance >= 3 && self->chance < 10) {
                id = 0x11;
            } else if (*ChancePtr(self) >= 10 && *ChancePtr(self) <= 99) {
                id = 0x12;
            } else if (ChanceWords(self)[0x382 / 2] == 100) {
                id = self->variant + 0x16;
            }
            self->message = id;
            self->messageTimer = 0;
            self->state++;
        }
    } else if (self->state == 3) {
        if (_Z26CheckFlagOrByte55_02158c70v(self)) {
            short id = 0x13;
            self->state++;
            if (self->chance == 100) {
                self->state = 6;
                id = 0x18;
            }
            self->message = id;
            self->messageTimer = 0;
        }
    } else if (self->state == 4) {
        if (_Z26CheckFlagOrByte55_02158c70v(self)) {
            self->message = 0x14;
            self->messageTimer = 0;
            self->state++;
        }
    } else if (self->state == 5) {
        if (_Z26CheckFlagOrByte55_02158c70v(self)) {
            self->message = 0x15;
            self->messageTimer = 0;
            self->state++;
        }
    } else if (self->state == 6) {
        func_ov006_02159db0(self);
        self->state++;
    } else if (self->state == 7) {
        int r = func_ov006_02159e50(self);
        if (r != -1) {
            if (r == 1) {
                unsigned char a;
                unsigned char b;
                if (self->IsCritical()) {
                    func_ov006_02153cbc(self->table, self->entry->count, self->entry->id, self->out);
                } else {
                    func_ov006_02153cbc(self->table, self->entry->id, -1, self->out);
                }
                func_ov006_0215759c(self->list, self->entry, self->mergeCount);
                a = self->cursorA;
                b = self->cursorB;
                func_ov006_02158de0(self);
                self->cursorA = a;
                self->cursorB = b;
                self->state++;
            }
        } else {
            self->message = 0x19;
            self->messageTimer = 0;
            self->flags = (self->flags | 0x20) & ~0x40;
            self->state = 0x5a;
        }
    } else if (self->state == 0x5a) {
        if (_Z26CheckFlagOrByte55_02158c70v(self)) {
            _Z20ClearElementFlag0x20P7Obj2081i(self->elements, 0);
            self->message = 1;
            self->messageTimer = 0;
            self->flags |= 0x20;
            self->state = 0x79;
        }
    } else if (self->state == 8) {
        if (BackgroundLoader::GetInstance()->GetNumQueuedTasks() <= 0) {
            self->state++;
        }
    } else if (self->state == 9) {
        self->message = 0x36;
        self->messageTimer = 0;
        _Z18SetElementFlag0x20P7Obj2081i(self->elements, 0);
        self->state++;
    } else if (self->state == 0xa) {
        self->flags |= 0x200;
        if (BackgroundLoader::GetInstance()->GetNumQueuedTasks() <= 0) {
            OrBitsIntoField0(GetDataPtr02114e04_020d6c00(), 0x80);
            _Z19ClearStruct020a9ea4P14Struct020a9ea4(self->loader);
            self->state++;
        }
    } else if (self->state == 0xb) {
        int size;
        BackgroundLoader::AddLockGlobal();
        BackgroundLoader::FreeAllocationsGlobal();
        size = 8;
        if (func_0202c540(func_0202ae18())) {
            size = 0x14;
        }
        if (func_020aad1c(self->loader, &data_0211e33c, size, 0) == 1) {
            _Z18ClearFlags020466f4P16FlagWord020466f4j(GetDataPtr02114e04_020d6c00(), 0x80);
            self->state++;
            self->flags &= ~0x200;
        }
        BackgroundLoader::RemoveLockGlobal();
    } else if (self->state == 0xc) {
        self->message = 0x37;
        self->messageTimer = 0;
        self->state++;
    } else if (self->state == 0xd) {
        if (_Z26CheckFlagOrByte55_02158c70v(self)) {
            self->message = 0x1a;
            self->messageTimer = 0;
            self->flags |= 0x20;
            self->state++;
        }
    } else if (self->state == 0xe) {
        self->field42c = 0;
        if (_Z26CheckFlagOrByte55_02158c70v(self)) {
            _Z34ToggleElementFlagsAndByte_0215e5f8P20Flags394Obj_0215e5f8P7Obj2081iPh(self, self->elements, 0, &self->shown);
            ctx->flags &= ~0x40;
            self->waitCount = 0;
            self->nextState = 0xf;
            self->state = 0x96;
        }
    } else if (self->state == 0xf) {
        ctx->flags |= 0x100;
        self->state++;
    } else if (self->state == 0x10) {
        ctx->flags |= 0x200;
        self->state++;
    } else if (self->state == 0x11) {
        void** res;
        int sound;
        self->busy = 1;
        res = CallFunc020e52a0(self->lookup, self->lookupId);
        if (res != 0) {
            memset(*self->buffer, 0, 0x80);
            func_020e4864(*res, *self->buffer, 1, 0, 0, 0);
            _Z26SetEntryFirstField02080f8cP17Container02080f8cii(self->elements, 0x7f, *self->buffer);
        }
        Forward0207f7acObjPlus4Size0x40(self->elements, 0x7f);
        func_020813ec(self->elements, 0x12);
        ctx->flags |= 0x400;
        self->field42f = 1;
        sound = 0x3e;
        if (self->IsCritical()) {
            sound = 0x3f;
            _Z30InitHandleAndDispatch_021571fcPc(self->ctx);
        }
        _Z27SetValueAndActivate0209c830P14Struct0209c830t(&data_02109bf4, sound);
        _Z18SetElementFlag0x20P7Obj2081i(self->elements, 0);
        self->message = 0xc;
        self->messageTimer = 0;
        self->state++;
    } else if (self->state == 0x12) {
        if (_Z26CheckFlagOrByte55_02158c70v(self)) {
            if (self->IsCritical()) {
                _Z25SetByte_0215728c_0215728cPv(ctx);
            }
            self->message = 0x38;
            self->messageTimer = 0;
            self->state++;
        }
    } else if (self->state == 0x13) {
        if (_Z26CheckFlagOrByte55_02158c70v(self)) {
            short id;
            _Z29CallFunc0204c804OnMatchingKeyP7Obj2081i(self->elements, 0x12);
            self->busy = 0;
            ctx->flags &= ~0x800;
            id = 0x1f;
            if (self->IsCritical()) {
                id = self->variant + 0x1b;
            }
            self->flags |= 0x20;
            self->message = id;
            self->messageTimer = 0;
            self->state++;
        }
    } else if (self->state == 0x14) {
        if (_Z26CheckFlagOrByte55_02158c70v(self)) {
            short id = 0x20;
            if (self->IsCritical()) {
                id = self->variant + 0x1d;
            }
            self->message = id;
            self->messageTimer = 0;
            self->state = 0x78;
        }
    } else if (self->state == 100) {
        ctx->flags |= 0x100;
        self->state++;
    } else if (self->state == 0x65) {
        ctx->flags |= 0x200;
        self->state++;
    } else if (self->state == 0x66) {
        void** res;
        unsigned char a;
        unsigned char b;
        func_ov006_02153cbc(self->table, self->entry->id, -1, self->out);
        func_ov006_0215759c(self->list, self->entry, self->mergeCount);
        a = self->cursorA;
        b = self->cursorB;
        func_ov006_02158de0(self);
        self->cursorA = a;
        self->cursorB = b;
        self->busy = 1;
        res = CallFunc020e52a0(self->lookup, self->lookupId);
        if (res != 0) {
            memset(*self->buffer, 0, 0x80);
            func_020e4864(*res, *self->buffer, 1, 0, 0, 0);
            _Z26SetEntryFirstField02080f8cP17Container02080f8cii(self->elements, 0x7f, *self->buffer);
        }
        Forward0207f7acObjPlus4Size0x40(self->elements, 0x7f);
        func_020813ec(self->elements, 0x12);
        ctx->flags |= 0x400;
        self->field42f = 1;
        _Z27SetValueAndActivate0209c830P14Struct0209c830t(&data_02109bf4, 0x3e);
        self->message = 0xc;
        self->messageTimer = 0;
        self->state++;
    } else if (self->state == 0x67) {
        if (_Z26CheckFlagOrByte55_02158c70v(self)) {
            self->message = 0x38;
            self->messageTimer = 0;
            self->state = 0x78;
        }
    } else if (self->state == 0x78) {
        if (self->field42f != 0) {
            self->field42c = 0;
        } else {
            Task0215e69c* task = ctx->GetTask();
            if (!(task != 0 && task->active != 0) && _Z26CheckFlagOrByte55_02158c70v(self)) {
                _Z29CallFunc0204c804OnMatchingKeyP7Obj2081i(self->elements, 0x12);
                self->busy = 0;
                ctx->flags &= ~0x800;
                self->message = 1;
                self->messageTimer = 0;
                self->flags |= 0x20;
                self->state++;
            }
        }
    } else if (self->state == 0x79) {
        if (_Z26CheckFlagOrByte55_02158c70v(self)) {
            _Z34ToggleElementFlagsAndByte_0215e5f8P20Flags394Obj_0215e5f8P7Obj2081iPh(self, self->elements, 1, &self->shown);
            _Z29CallFunc0204c804OnMatchingKeyP7Obj2081i(self->elements, 0);
            _Z29CallFunc0204c804OnMatchingKeyP7Obj2081i(self->elements, 1);
            self->mode = 0xa;
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
