#include <globaldefs.h>

int StringLength(const char*);


struct List0207f6ac;
struct TableA68;

extern void* FindEntryByShortId0207f6ac(struct List0207f6ac* list, int id);
extern void* FindEntryByKey(struct TableA68* table, int key);
extern int IsValueEqual12(int x);
extern "C" int func_020420e8(void* value, int flag);

struct Entry020808c8 {
    void* field0;
    char pad1[0xa - 4];
    short fieldA;
    short fieldC;
    short fieldE;
    char pad2[0x12 - 0x10];
    unsigned char field12;
    unsigned char field13nibble : 4;
    unsigned char field13rest : 4;
};

#if defined(jpn)
#define GetEntryOutputs020808c8 func_020813bc
extern "C" ARM void func_020813bc(void* obj, int id, short* out1, short* out2);
#endif

// USA: func_020808c8
ARM void GetEntryOutputs020808c8(void* obj, int id, short* out1, short* out2) {
    struct Entry020808c8* e = (struct Entry020808c8*)FindEntryByShortId0207f6ac((struct List0207f6ac*)((char*)obj + 0x4), id);
    if (e == NULL) {
        return;
    }

#if !defined(jpn)
    int isTwelve = IsValueEqual12(e->field13nibble);
#endif
    int kind = e->field12;

    switch (kind) {
    case 0: {
        void* found = FindEntryByKey(*(struct TableA68**)obj, e->fieldE);
        if (found == NULL) {
            return;
        }
        #if defined(jpn)
        int length = StringLength((const char*)found);
        int characters = length >> 1;
        int fontSize = e->field13nibble;
        *out1 = (short)(characters * fontSize);
#else
        *out1 = (short)func_020420e8(found, isTwelve);
#endif
        *out2 = e->field13nibble;
        break;
    }
    case 1:
        *out1 = e->fieldA;
        *out2 = e->fieldC;
        break;
    case 4: {
        if (e->field0 == NULL) {
            return;
        }
        #if defined(jpn)
        int length = StringLength((const char*)e->field0);
        int characters = length >> 1;
        int fontSize = e->field13nibble;
        *out1 = (short)(characters * fontSize);
#else
        *out1 = (short)func_020420e8(e->field0, isTwelve);
#endif
        *out2 = e->field13nibble;
        break;
    }
    default:
        *out2 = 0;
        *out1 = 0;
        break;
    }
}
