#include <globaldefs.h>

int StringLength_020d2ff0(const char* s);
extern "C" int func_02001aec(void* a, void* b, int n);

struct FindResult0215f41c {
    void* match;
    void* list;
    char pad8[0x18 - 8];
    int field_18;
    short field_1c;
    unsigned char field_1e;
    char pad1f;
    unsigned char field_20;
};

// USA: func_ov003_0215f41c  (semantic: FindEntryByName_0215f41c)
extern "C" ARM void func_ov003_0215f41c(struct FindResult0215f41c* self, char* name) {
    int len;
    char* item;
    short count;
    self->match = 0;
    self->field_18 = 0;
    self->field_1c = 0;
    self->field_1e = 1;
    self->field_20 = 0;
    len = StringLength_020d2ff0(name);
    char* list = (char*)self->list;
    count = *(short*)(list + 6);
    item = *(char**)(list + 0);
    for (short i = 0; i < count; i++, item += 0x14) {
        void* namePtr = *(void**)(item + 4);
        if (namePtr != 0) {
            if (func_02001aec(namePtr, name, len) == 0) {
                self->match = item;
                return;
            }
        }
    }
}
