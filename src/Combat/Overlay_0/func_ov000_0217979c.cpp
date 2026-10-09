#include <globaldefs.h>

struct UnkStruct0205c508;
extern "C" void _Z26ComputeProductSums0205c508P17UnkStruct0205c508PiS1_(struct UnkStruct0205c508* s, int* out1, int* out2);
struct Container020e0310;
extern "C" char* _Z21GetFieldByKey020e0434P17Container020e0310i(struct Container020e0310* c, int key);
int IsField0x118Equal2(void* obj);
extern "C" int _Z22AppendFrameTag02041c08Pciiiii(char* dst, int a1, int a2, int a3, int a4, int a5);
int AppendCursorTag(char* dst, int cursor);
extern "C" void* _Z33GetPointerField_02171b9c_02171b9cPvi(void* obj, int idx);
int AppendNameTag(char* dst, int n, const char* name);
extern "C" void __clear(void* buf, int n);
extern "C" int _Z20AppendString02042058PcPKc(char* dst, const char* src);
int AppendWidthTag(char* dst, int w);
extern "C" void _Z37CopyTextAndUppercaseIfFlagged0206819cPKcPci(const char* src, char* dst, int flag);

extern char data_ov000_02184069[];

struct ListItem0217979c {
    int field_0x0;
    const char* name;
    unsigned int kind : 4;
};

struct ItemList0217979c {
    char pad0[0x22];
    signed char cursor;
};

// USA: func_ov000_0217979c
extern "C" ARM void func_ov000_0217979c(char* obj, struct ItemList0217979c* list, char* dst) {
    if (list == NULL || dst == NULL) {
        return;
    }
    int first;
    int last;
    _Z26ComputeProductSums0205c508P17UnkStruct0205c508PiS1_((struct UnkStruct0205c508*)(obj + 0x1dc), &first, &last);
    signed char start = first;
    signed char end = last;
    signed char cursor = list->cursor;
    char* prefix = _Z21GetFieldByKey020e0434P17Container020e0310i((struct Container020e0310*)(obj + 0xb8), 0x13);
    char* separator = _Z21GetFieldByKey020e0434P17Container020e0310i((struct Container020e0310*)(obj + 0xb8), 0);
    if (IsField0x118Equal2(obj)) {
        _Z22AppendFrameTag02041c08Pciiiii(dst, cursor - start, 8, 5, 5, 5);
    }
    AppendCursorTag(dst, cursor - start);
    for (signed char i = start; i < end; i++) {
        struct ListItem0217979c* item = (struct ListItem0217979c*)_Z33GetPointerField_02171b9c_02171b9cPvi(list, i);
        if (item == NULL) {
            AppendNameTag(dst, i - start, data_ov000_02184069);
            continue;
        }
        char text[0x80];
        __clear(text, 0x80);
        int narrow = item->kind <= 7;
        if (narrow) {
            _Z20AppendString02042058PcPKc(text, prefix);
            AppendWidthTag(text, 3);
        } else {
            AppendWidthTag(text, 8);
        }
        char name[0x100];
        __clear(name, 0x100);
        _Z37CopyTextAndUppercaseIfFlagged0206819cPKcPci(item->name, name, 0);
        _Z20AppendString02042058PcPKc(text, name);
        AppendNameTag(dst, i - start, text);
        if (i != end - 1) {
            _Z20AppendString02042058PcPKc(dst, separator);
        }
    }
}
