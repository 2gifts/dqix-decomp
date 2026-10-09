#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" int _Z21AllBytesZero_02171df0Ph(unsigned char* arr);
extern "C" int func_02001aec(void* a, void* b, int n);

struct KeyEntry_02171e1c {
    unsigned char key[6];
    unsigned char age;
    unsigned char pad;
};

struct KeyList_02171e1c {
    unsigned char pad0[0x8];
    KeyEntry_02171e1c entries[0x32];
    unsigned char pad1[0x198 - (0x8 + 0x32 * 0x8)];
    unsigned char count;
};

// USA: func_ov003_02171e1c
extern "C" ARM void func_ov003_02171e1c(KeyList_02171e1c* list, unsigned char* key) {
    if (key == 0) return;
    if (_Z21AllBytesZero_02171df0Ph(key) != 0) return;
    {
        KeyEntry_02171e1c* found = 0;
        int foundAge = 0;
        KeyEntry_02171e1c* e = list->entries;
        for (int i = 0; i < 0x32; i++, e++) {
            int age = e->age;
            if (age != 0 && func_02001aec(e, key, 6) == 0) {
                found = e;
                foundAge = age;
                e->age = 0x32;
                break;
            }
        }
        if (foundAge == 0x32) return;
        if (foundAge > 0) {
            KeyEntry_02171e1c* other = list->entries;
            for (int i = 0; i < 0x32; i++, other++) {
                if (other->age > foundAge && other != found) {
                    other->age--;
                }
            }
            return;
        }
    }
    {
        KeyEntry_02171e1c* empty = 0;
        KeyEntry_02171e1c* e = list->entries;
        for (int i = 0; i < 0x32; i++, e++) {
            if (e->age != 0) {
                if (--e->age == 0) {
                    memset(e, 0, 6);
                    list->count--;
                }
            }
            if (e->age == 0 && empty == 0) empty = e;
        }
        if (empty == 0) return;
        empty->age = 0x32;
        memcpy(empty, key, 6);
        list->count++;
    }
}
