#include <globaldefs.h>

struct Obj020bda58;
void* GetOffsetEntry0x20_020bd6ac(int index);
void* AllocateAndLinkEntry020bda58(struct Obj020bda58* obj, unsigned int size, int a2, int a3, int a4);
extern "C" void func_020bf1a0(void* entry);
struct Ctx020bf484;
void DetachAndReleaseRefs020bf484(int expected, void* unused1, struct Ctx020bf484* obj);

extern int data_02110a4c;

// USA: func_020beaec  (semantic: PopulateEntryTableAndLink_020beaec)
extern "C" ARM int func_020beaec(struct Obj020bda58* obj) {
    int i = 0;
    unsigned int size;
    unsigned char* dstEntry = (unsigned char*)&data_02110a4c;
    do {
        unsigned char* srcEntry = (unsigned char*)GetOffsetEntry0x20_020bd6ac(i);
        if (srcEntry != 0) {
            dstEntry[0x124] = srcEntry[0];
            int j = 0;
            if (j < srcEntry[0]) {
                do {
                    unsigned char* s = srcEntry + j;
                    unsigned char* d = dstEntry + j;
                    d[0x126] = s[1];
                    j++;
                } while (j < srcEntry[0]);
            }
            if (obj != 0) {
                size = (unsigned int)dstEntry[0x124] << 11;
                void* handle = AllocateAndLinkEntry020bda58(obj, size, (int)&DetachAndReleaseRefs020bf484, (int)dstEntry, 0);
                if (handle == 0) return 0;
                func_020bf1a0(dstEntry);
                *(void**)(dstEntry + 0x12c) = handle;
                *(unsigned int*)(dstEntry + 0x130) = size;
            }
        }
        dstEntry += 0x174;
        i++;
    } while (i < 4);
    return 1;
}
