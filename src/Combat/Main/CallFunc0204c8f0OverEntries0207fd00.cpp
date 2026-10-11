#include <globaldefs.h>
void SomeFunc0204c8f0(struct Struct0204c8f0*);


struct Obj0207fd00 {
    #if defined(jpn)
    char pad0[0x20];
#else
    char pad0[0x2c];
#endif
    void* field_2c;
    char* entries;
    char pad34[5];
    unsigned char count;
};

// JPN: func_0208083c
// USA: func_0207fd00
ARM void CallFunc0204c8f0OverEntries0207fd00(struct Obj0207fd00* obj) {
    unsigned char count;
    char* e;
    unsigned char i;
    if (obj->field_2c != NULL && obj->entries != NULL) {
        e = obj->entries;
        count = obj->count;
        for (i = 0; i < count; i++) {
            SomeFunc0204c8f0((struct Struct0204c8f0*)(e));
            e += 0xe0;
        }
    }
}
