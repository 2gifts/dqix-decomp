#include <globaldefs.h>

#if defined(jpn)
#define REGION_OFFSET_0 0xdc
#define REGION_OFFSET_1 0x1e4
#else
#define REGION_OFFSET_0 0x9c
#define REGION_OFFSET_1 0x1a4
#endif


void* GetData02108e10(void);
void* SearchBothTables02079e2c(char* p, int key);

struct Entry02170cf8 {
    char pad[4];
    unsigned int field4 : 12;
    unsigned int rest4 : 20;
};

// USA: func_ov000_02170cf8  (semantic: FindEntryByKey_02170cf8)
extern "C" ARM void* func_ov000_02170cf8(char* obj, int val) {
    if (val == 0) {
        return 0;
    }
    void* data = GetData02108e10();
    if (data == 0) {
        return 0;
    }
    void* result = SearchBothTables02079e2c((char*)data, (short)val);
    if (result != 0) {
        return result;
    }
    struct Entry02170cf8** arr1 = (struct Entry02170cf8**)(obj + REGION_OFFSET_0);
    for (unsigned short i = 0; i < 0x42; i++) {
        struct Entry02170cf8* e = arr1[i];
        if (e != 0 && e->field4 == val) {
            return e;
        }
    }
    struct Entry02170cf8** arr2 = (struct Entry02170cf8**)(obj + REGION_OFFSET_1);
    for (unsigned short i = 0; i < 0x93; i++) {
        struct Entry02170cf8* e = arr2[i];
        if (e != 0 && e->field4 == val) {
            return e;
        }
    }
    return 0;
}
