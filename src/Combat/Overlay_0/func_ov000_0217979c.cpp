#include <globaldefs.h>

struct UnkStruct0205c508;
void ComputeProductSums0205c508(struct UnkStruct0205c508* s, int* out1, int* out2);
struct Container020e0310;
char* GetFieldByKey020e0434(struct Container020e0310* c, int key);
int IsField0x118Equal2_ov000_0217542c(void* obj);
int AppendFrameTag02041c08(char* dst, int a1, int a2, int a3, int a4, int a5);
int AppendCursorTag_02041ea4(char* dst, int cursor);
void* GetPointerField_02171b9c_02171b9c(void* obj, int idx);
int AppendNameTag_02041b70(char* dst, int n, const char* name);
extern "C" void __clear(void* buf, int n);
int AppendString02042058(char* dst, const char* src);
#if defined(jpn)
extern "C" int func_02042158(char* dst, int w);
#define AppendWidthTag_02041acc func_02042158
#else
int AppendWidthTag_02041acc(char* dst, int w);
#endif
void CopyTextAndUppercaseIfFlagged0206819c(const char* src, char* dst, int flag);

#if defined(jpn)
#define data_ov000_02184069 data_ov000_021851a9
#endif
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
    ComputeProductSums0205c508((struct UnkStruct0205c508*)(obj + 0x1dc), &first, &last);
    signed char start = first;
    signed char end = last;
    signed char cursor = list->cursor;
#if !defined(jpn)
    char* prefix = GetFieldByKey020e0434((struct Container020e0310*)(obj + 0xb8), 0x13);
    char* separator = GetFieldByKey020e0434((struct Container020e0310*)(obj + 0xb8), 0);
#endif
    if (IsField0x118Equal2_ov000_0217542c(obj)) {
        AppendFrameTag02041c08(dst, cursor - start, 8, 5, 5, 5);
    }
    AppendCursorTag_02041ea4(dst, cursor - start);
    for (signed char i = start; i < end; i++) {
        struct ListItem0217979c* item = (struct ListItem0217979c*)GetPointerField_02171b9c_02171b9c(list, i);
        if (item == NULL) {
            AppendNameTag_02041b70(dst, i - start, data_ov000_02184069);
            continue;
        }
        char text[0x80];
        __clear(text, 0x80);
        int narrow = item->kind <= 7;
        if (narrow) {
#if defined(jpn)
            AppendString02042058(text, GetFieldByKey020e0434((struct Container020e0310*)(obj + 0xb8), 0x13));
#else
            AppendString02042058(text, prefix);
            AppendWidthTag_02041acc(text, 3);
#endif
        } else {
            AppendWidthTag_02041acc(text, 8);
        }
#if defined(jpn)
        AppendString02042058(text, item->name);
#else
        char name[0x100];
        __clear(name, 0x100);
        CopyTextAndUppercaseIfFlagged0206819c(item->name, name, 0);
        AppendString02042058(text, name);
#endif
        AppendNameTag_02041b70(dst, i - start, text);
        if (i != end - 1) {
#if defined(jpn)
            AppendString02042058(dst, GetFieldByKey020e0434((struct Container020e0310*)(obj + 0xb8), 0));
#else
            AppendString02042058(dst, separator);
#endif
        }
    }
}
