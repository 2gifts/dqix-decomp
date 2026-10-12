#include <globaldefs.h>
#include "std_library_functions.h"

struct EntryList0206f110;
struct Entry0206f110;
struct Header0206f0f8;

#if defined(jpn)
struct Fixup0206ef48;
typedef int (*EntryCallback0206f170)(void*, struct Fixup0206ef48*);
extern "C" int func_02070248(struct Header0206f0f8* obj);
extern "C" int func_02070260(struct EntryList0206f110* self, EntryCallback0206f170 callback);
#define GetEntryArrayByteSize func_02070248
#define InvokeCallbackForEachEntry func_02070260
#else
typedef void (*EntryCallback0206f170)(struct EntryList0206f110*, struct Entry0206f110*);
int GetEntryArrayByteSize(struct Header0206f0f8* obj);
int InvokeCallbackForEachEntry(struct EntryList0206f110* self,
                                void (*callback)(struct EntryList0206f110*, struct Entry0206f110*));
#endif

struct List0206f170 {
    int field0;
    void* field4;
    void* field8;
};

struct Src0206f170 {
    int field0;
};

#if defined(jpn)
#define InitEntryListFromSource0206f170 func_020702c0
extern "C" ARM int func_020702c0(struct List0206f170*, struct Src0206f170*, unsigned char*, EntryCallback0206f170);
#endif

// USA: func_0206f170
ARM int InitEntryListFromSource0206f170(struct List0206f170* arg0, struct Src0206f170* arg1, unsigned char* outFlag,
                                         EntryCallback0206f170 callback) {
    int size;
    *outFlag = 0;
    if (arg1 == 0) {
        return 0;
    }
    memcpy(arg0, arg1, 4);
    arg0->field4 = (char*)arg1 + 4;
    size = GetEntryArrayByteSize((struct Header0206f0f8*)arg0);
    arg0->field8 = (char*)arg1 + (size + 4);
    if ((unsigned int)arg0->field0 >> 31) {
        *outFlag = 1;
        return 1;
    }
    InvokeCallbackForEachEntry((struct EntryList0206f110*)arg0, callback);
    arg0->field0 = (arg0->field0 & ~0x80000000) | 0x80000000;
    arg1->field0 = (arg1->field0 & ~0x80000000) | 0x80000000;
    return 1;
}
