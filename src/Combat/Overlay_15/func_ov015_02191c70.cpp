#include <globaldefs.h>

struct ResetStruct0218eef0 {};
struct Self0218f02c : ResetStruct0218eef0 {};
struct CombatNode { Self0218f02c* object; CombatNode* next; };
struct CommandNode {
    int value;
    unsigned short parameter;
    unsigned char mode;
    unsigned char pad7;
    CommandNode* next;
};
struct Entry8_0218bb14 { int value; CommandNode* commands; };
struct List8_0218bb14 { void* field0; Entry8_0218bb14* entries; void* field8; int count; };
struct CombatMenu {
    char pad0[0x2c];
    CombatNode* head;
    char pad30[0xc];
    List8_0218bb14 list;
    char pad4c[0x1a4-0x4c];
    int state;
};
struct CommandInfo {
    int value;
    int secondValue;
    unsigned short parameter;
    unsigned char fieldA;
    unsigned char fieldB;
};
struct AllocatorUnion;
extern AllocatorUnion data_02114e20;
extern unsigned short data_02114e30;
extern "C" Entry8_0218bb14* _Z18GetEntry8_0218bb14P14List8_0218bb14i(List8_0218bb14*, int);
int TestFlagMask(unsigned short*, int);
void* AllocateAligned4(AllocatorUnion*, unsigned int);
extern "C" void _Z19TailForward02012da4P14AllocatorUnionPv(AllocatorUnion*, void*);
extern "C" void _Z29InitCombatFieldStruct0218eef0P19ResetStruct0218eef0(ResetStruct0218eef0*);
extern "C" int _Z35SetFieldAndModeThenDispatch0218f02cP12Self0218f02cii(Self0218f02c*, int, int);
extern "C" void func_ov015_0218f0c4(Self0218f02c*);
extern "C" void func_ov015_0218f308(Self0218f02c*, int);
extern "C" int func_ov015_0218f27c(Self0218f02c*, CommandInfo*);

// USA: func_ov015_02191c70
extern "C" ARM void func_ov015_02191c70(CombatMenu* self, int index) {
    Entry8_0218bb14* entry = _Z18GetEntry8_0218bb14P14List8_0218bb14i(&self->list, index);
    if (!entry) return;
    if (TestFlagMask(&data_02114e30, 0x100)) {
        CombatNode* node = self->head;
        while (node) {
            func_ov015_0218f0c4(node->object);
            _Z19TailForward02012da4P14AllocatorUnionPv(&data_02114e20, node->object);
            CombatNode* old = node;
            node = node->next;
            _Z19TailForward02012da4P14AllocatorUnionPv(&data_02114e20, old);
        }
        self->head = 0;
    }
    CommandNode* command = entry->commands;
    int previousState;
    CombatNode* node;
    Self0218f02c* object = 0;
    for (; command; command = command->next) {
        previousState = self->state;
        if (command->mode == 8 || command->mode == 9 || command->mode == 10) {
            switch (command->mode) {
            case 8: self->state = 0x1e; break;
            case 9: self->state = 0x1f; break;
            case 10: self->state = 0x20; break;
            }
            if (object) func_ov015_0218f308(object, command->value);
            self->state = previousState;
        } else if (command->mode == 11) {
            if (object) func_ov015_0218f308(object, command->value);
        } else {
            node = (CombatNode*)AllocateAligned4(&data_02114e20, 8);
            if (!node) return;
            node->object = 0;
            node->next = 0;
            object = node->object = (Self0218f02c*)AllocateAligned4(&data_02114e20, 0x5c);
            if (!object) {
                _Z19TailForward02012da4P14AllocatorUnionPv(&data_02114e20, node);
                return;
            }
            _Z29InitCombatFieldStruct0218eef0P19ResetStruct0218eef0(object);
            if (!_Z35SetFieldAndModeThenDispatch0218f02cP12Self0218f02cii(object, (int)self, command->mode)) {
                _Z19TailForward02012da4P14AllocatorUnionPv(&data_02114e20, node->object);
                node->object = 0;
                _Z19TailForward02012da4P14AllocatorUnionPv(&data_02114e20, node);
                return;
            }
            CommandInfo info;
            info.value = 0;
            info.secondValue = 0;
            info.parameter = 0;
            info.fieldA = 0;
            info.fieldB = 0;
            info.value = command->value;
            info.secondValue = command->value;
            info.parameter = command->parameter;
            if (!func_ov015_0218f27c(object, &info)) {
                func_ov015_0218f0c4(node->object);
                _Z19TailForward02012da4P14AllocatorUnionPv(&data_02114e20, node->object);
                node->object = 0;
                _Z19TailForward02012da4P14AllocatorUnionPv(&data_02114e20, node);
                return;
            }
            CombatNode** tail = &self->head;
            while (*tail) tail = &(*tail)->next;
            *tail = node;
        }
    }
}
