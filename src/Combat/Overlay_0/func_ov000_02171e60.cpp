#if defined(jpn)
#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif
#include <globaldefs.h>
#include "Resource/ActionDataTables.h"
#include "GameState/GameState.h"

struct Container020e0310;
char* GetFieldByKey020e0434(struct Container020e0310* c, int key);

struct Obj0203c108 {
    char pad[0x14];
    short idx;
    short pad16;
};
void SwapGlobalEntry0203c108(struct Obj0203c108* obj, char* fmt);

void* SearchBothTables02079e2c(char* table, int key);
extern "C" int func_ov000_02171210(void* rec, void* self);

struct BattleInfo2a04 {
    char pad[0xf7c];
    unsigned char mode;
};

extern "C" void __clear(void* buf, int n);
extern "C" void func_020e4864(const char* src, char* dst, int a, int b, int c, int d);
void CopyTextAndUppercaseIfFlagged0206819c(const char* src, char* dst, int flag);
struct MessageSystem;
struct MessageSystem* GetGlobalField0x1c020421a0();
extern "C" void func_02046608(struct MessageSystem* messages, int a, const char* format, char* output, int size, int b, int c);

struct ActionEntry {
    int field_0x0;
    const char* name;
    char pad8[0xe];
    short recordId;
    short count;
};

struct CommandMenu {
    char pad0[4];
    struct Container020e0310* texts;
    char pad8[8];
    signed char stack[8];
    signed char stackTop;
    char pad19[4];
    signed char result;
    char pad1e[3];
    signed char field_0x21;
    signed char curIndex;
    char pad23[0xb];
    signed char field_0x2e;
    char pad2f[0x1d];
    int field_0x4c;
    struct Obj0203c108 message;
    char pad68[LOW_REGION(0x3c8, 0x388)];
    struct ActionEntry* entries[16];
};

// USA: func_ov000_02171e60
extern "C" ARM void func_ov000_02171e60(struct CommandMenu* self) {
    struct ActionEntry* entry = self->entries[self->curIndex];
    if (entry->count <= 0) {
        self->stackTop++;
        self->stack[self->stackTop] = 0xe;
        self->result = 0;
        SwapGlobalEntry0203c108(&self->message, GetFieldByKey020e0434(self->texts, 5));
        return;
    }
    void* rec = SearchBothTables02079e2c((char*)GetData02108e10(), entry->recordId);
    if (rec == NULL) {
        self->stackTop++;
        self->stack[self->stackTop] = 0xe;
        self->result = 0;
        SwapGlobalEntry0203c108(&self->message, GetFieldByKey020e0434(self->texts, 5));
        return;
    }
    self->stackTop++;
    self->stack[self->stackTop] = func_ov000_02171210(rec, self);
    if (self->stack[self->stackTop] == 0x13) {
        self->field_0x21 = 0;
        self->field_0x2e = self->field_0x4c;
        if (((struct BattleInfo2a04*)GetPtrField0x2a04(GameState::GetInstance()))->mode == 1) {
            self->stack[self->stackTop] = 100;
        }
    }
#if defined(jpn)
    SwapGlobalEntry0203c108(&self->message, (char*)entry->name);
#else
    char text[0x80];
    __clear(text, 0x80);
    char format[0x80];
    __clear(format, 0x80);
    func_020e4864(entry->name, text, 1, 0, 0, 0);
    CopyTextAndUppercaseIfFlagged0206819c(text, format, 0);
    func_02046608(GetGlobalField0x1c020421a0(), 10, format, text, 0x100, 0, 0);
    SwapGlobalEntry0203c108(&self->message, text);
#endif
}
