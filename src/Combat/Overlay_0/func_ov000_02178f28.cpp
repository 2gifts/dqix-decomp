#include <globaldefs.h>

struct UnkStruct0205c508;
void ComputeProductSums0205c508(struct UnkStruct0205c508* s, int* out1, int* out2);

int IsField0x118Equal2_ov000_0217542c(void* obj);
int AppendFrameTag02041c08(char* dst, int a1, int a2, int a3, int a4, int a5);
int AppendCursorTag_02041ea4(char* dst, int cursor);
int GetBoundedField156_02171674(void* obj, int index);
int AppendNameTag_02041b70(char* dst, int n, const char* name);
struct Container020e0310;
int GetFieldByKey020e0434(struct Container020e0310* c, int key);
int AppendString02042058(char* dst, const char* src);

struct Entry02178f28 {
    char pad[0x20];
    signed char cursor;
};

// USA: func_ov000_02178f28
extern "C" ARM void func_ov000_02178f28(char* obj, struct Entry02178f28* entry, char* dst) {
    if (entry != NULL && dst != NULL) {
        int a, b;
        ComputeProductSums0205c508((struct UnkStruct0205c508*)(obj + 0x1dc), &a, &b);
        signed char first = a;
        signed char last = b;
        signed char cursor = entry->cursor;
        if (IsField0x118Equal2_ov000_0217542c(obj)) {
            AppendFrameTag02041c08(dst, cursor - first, 8, 5, 5, 5);
        }
        AppendCursorTag_02041ea4(dst, cursor - first);
        for (signed char i = first; i < last; i++) {
            const char** name = (const char**)GetBoundedField156_02171674(entry, i);
            if (name == NULL) continue;
            AppendNameTag_02041b70(dst, i - first, *name);
            if (i == last - 1) continue;
            AppendString02042058(dst, (const char*)GetFieldByKey020e0434((struct Container020e0310*)(obj + 0xb8), 0));
        }
    }
}
