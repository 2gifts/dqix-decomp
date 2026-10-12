#include <globaldefs.h>

struct Entry0206f110 {
    #if defined(jpn)
    char pad[0x14];
#else
    char pad[0x1c];
#endif
};

struct EntryList0206f110 {
    unsigned int count : 12;
    unsigned int rest : 20;
    struct Entry0206f110* entries;
};

#if defined(jpn)
struct Fixup0206ef48;
typedef int (*EntryCallback0206f110)(void*, struct Fixup0206ef48*);
#else
typedef void (*EntryCallback0206f110)(struct EntryList0206f110*, struct Entry0206f110*);
#endif

#if defined(jpn)
#define InvokeCallbackForEachEntry func_02070260
extern "C" ARM int func_02070260(struct EntryList0206f110* self,
                                   EntryCallback0206f110 callback);
#endif

// USA: func_0206f110
ARM int InvokeCallbackForEachEntry(struct EntryList0206f110* self,
                                   EntryCallback0206f110 callback) {
    int count;
    struct Entry0206f110* entry = self->entries;
    int i;
    if (entry != NULL) {
        count = self->count;
        if (count != 0 && callback != NULL) {
            goto run;
        }
    }
    return 0;
run:
    i = 0;
    while (i < count) {
#if defined(jpn)
        callback(self, (struct Fixup0206ef48*)entry);
#else
        callback(self, entry);
#endif
        i++;
        entry++;
    }
    return 1;
}
