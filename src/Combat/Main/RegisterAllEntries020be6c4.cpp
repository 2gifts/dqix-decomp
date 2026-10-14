#include <globaldefs.h>

struct Obj020bda58;
void* GetGlobalContext02110370_020bd444(void);
void* GetOffsetEntry0x18_020bd648(int index);
void SetEntryHalfword_020bbf4c(int index, int value);
void SetTableEntryPointer_020bbf6c(int index, void* value);
int AllocateAndRegisterEntry020bbf84(int index, struct Obj020bda58* obj, unsigned int size);

struct TableEntry020be6c4 {
    unsigned char count;
    unsigned char pad1;
    unsigned short field2;
    unsigned int field4;
};

// USA: func_020be6c4  (semantic: RegisterAllEntries020be6c4)
extern "C" ARM int func_020be6c4(struct Obj020bda58* obj) {
    GetGlobalContext02110370_020bd444();
    int j0 = 0;
    int i = 0;
    do {
        struct TableEntry020be6c4* e = (struct TableEntry020be6c4*)GetOffsetEntry0x18_020bd648(i);
        if (e) {
            SetEntryHalfword_020bbf4c(i, e->count);
            SetTableEntryPointer_020bbf6c(i, (void*)(unsigned int)e->field2);
            if (e->field4 != 0 && obj != 0) {
                int j = j0;
                if (j < e->count) {
                    do {
                        if (AllocateAndRegisterEntry020bbf84(i, obj, e->field4) == 0) return 0;
                        j++;
                    } while (j < e->count);
                }
            }
        }
        i++;
    } while (i < 0x20);
    return 1;
}
