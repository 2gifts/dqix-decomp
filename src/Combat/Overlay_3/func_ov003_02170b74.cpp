#include <globaldefs.h>
#if defined(jpn)
enum { kRegion460 = 0x35c };
#else
enum { kRegion460 = 0x460 };
#endif

struct Obj020827c4;

extern "C" void* memset(void* dst, int value, unsigned int length);
extern "C" void VectorizedMemset(void* dst, int val, unsigned int len);
extern "C" void _Z26InitFlagsAndTimers020827c4P11Obj020827c4(struct Obj020827c4* obj);

struct Entry02170b74 {
    char name[0xb];
    unsigned char field0b_lo : 7;
    unsigned char field0b_hi : 1;
    unsigned int field0c_a : 4;
    unsigned int field0c_b : 4;
    unsigned int field0c_pad : 7;
    unsigned int field0c_c : 4;
    unsigned int field0c_d : 5;
    unsigned int field0c_e : 6;
    unsigned int field0c_f : 1;
    unsigned int field0c_g : 1;
    unsigned int field10_a : 2;
    unsigned int field10_b : 30;
    unsigned char field14[6];
    unsigned short timers[0xf];
    unsigned char field38[0x18];
    unsigned char field50[0x1c];
    unsigned int field6c_a : 12;
    unsigned int field6c_b : 4;
    unsigned int field6c_c : 5;
    unsigned int field6c_d : 4;
    unsigned int field6c_e : 1;
    unsigned int field6c_f : 1;
    unsigned int field6c_g : 1;
    unsigned int field6c_h : 1;
    unsigned int field6c_i : 1;
    unsigned int field6c_j : 1;
    unsigned int field6c_k : 1;
    unsigned int field70_a : 9;
    unsigned int field70_b : 10;
    unsigned int field70_c : 11;
    unsigned int field70_d : 1;
    unsigned int field70_e : 1;
    unsigned char field74;
    char pad75[0xe8 - 0x75];
};

struct Obj02170b74 {
    unsigned char state;
    char pad1[3];
    unsigned int timer;
    unsigned char field8[0x190];
    unsigned char field198;
    char pad199[kRegion460 - 0x199];
    Entry02170b74 entries[3];
    unsigned char field718;
    char pad719[3];
    int field71c;
    int field720;
    int field724;
    int field728;
    int field72c;
    char pad730;
    signed char retries;
    signed char attempts;
    unsigned char field733;
    unsigned char field734;
    char pad735[3];
    int field738;
};

// JPN: func_ov003_02170230
// USA: func_ov003_02170b74
extern "C" ARM void func_ov003_02170b74(struct Obj02170b74* self) {
    self->state = 0;
    self->timer = 0;
    memset(self->field8, 0, 0x190);
    self->field198 = 0;
    self->field71c = 0;
    self->field720 = 0;
    self->field724 = 0;
    self->field728 = 0;
    self->field718 = 0;
    self->field72c = 0;
    self->retries = 2;
    self->attempts = 3;
    self->field733 = 0;
    self->field734 = 0;
    self->field738 = 0;

    for (int i = 0; i < 3; i++) {
        Entry02170b74* entry = &self->entries[i];
        memset(self->entries[i].name, 0, 0xb);
        entry->field0c_a = 0;
        entry->field0c_b = 0;
        entry->field0b_lo = 0;
        entry->field0c_c = 0;
        entry->field0c_d = 0;
        entry->field0c_e = 0;
        entry->field0c_f = 0;
        entry->field10_a = 0;
        entry->field0c_g = 0;
        entry->field0b_hi = 0;
        entry->field10_b = 0;
        VectorizedMemset(entry->field14, 0, 6);
        entry->field6c_a = 2000;
        entry->field6c_b = 1;
        entry->field6c_c = 1;
        entry->field6c_h = 0;
        entry->field6c_d = 0;
        entry->field6c_g = 0;
        entry->field6c_e = 0;
        entry->field6c_f = 0;
        entry->field6c_i = 0;
        entry->field6c_j = 1;
        entry->field6c_k = 0;
        entry->field70_a = 0x1ff;
        entry->field70_d = 0;
        entry->field70_b = 300;
        entry->field70_c = 706;
        self->entries[i].field74 = 0;
        _Z26InitFlagsAndTimers020827c4P11Obj020827c4((struct Obj020827c4*)entry->timers);
        VectorizedMemset(entry->field38, 0, 0x18);
        VectorizedMemset(entry->field50, 0, 0x1c);
    }
}
