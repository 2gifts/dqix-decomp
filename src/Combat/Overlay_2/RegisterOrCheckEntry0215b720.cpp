#include <globaldefs.h>

void* GetData02108e10(void);
void* SearchBothTables02079e2c(char* p, int key);
void* GetData02153637(void);
void StoreInFirstEmptySlot(unsigned char* base, unsigned char val);

struct Field18_0215b720 {
    unsigned int field0 : 5;
    unsigned int field1 : 7;
    unsigned int rest : 20;
};

// USA: func_ov002_0215b720  (semantic: RegisterOrCheckEntry0215b720)
extern "C" ARM int func_ov002_0215b720(unsigned char* obj, int key) {
    int result = 0;

    if (*(int*)(obj + 0x1000 + 0xbb8) == 6 || *(int*)(obj + 0x1000 + 0xbb8) == 0x11) {
        if (key == 0x198 || key == 0x22 || key == 0x310) {
            result = 1;
        }
    } else {
        void* table = GetData02108e10();
        void* entry = SearchBothTables02079e2c((char*)table, key);
        if (entry != 0) {
            struct Field18_0215b720* f = (struct Field18_0215b720*)((char*)entry + 0x18);
            if (f->field1 == 2 || f->field1 == 7 || f->field1 == 0x4f || f->field1 == 0x50 || f->field1 == 0x12 || f->field1 == 0x1a) {
                result = 1;
            }
            if (f->field0 == 5 && *(int*)(obj + 0x1000 + 0xbb8) == 7) {
                result = 1;
            }
        }
    }

    if (result != 0) {
        void* ctx = GetData02153637();
        StoreInFirstEmptySlot((unsigned char*)ctx, 1);
    }

    return result;
}
