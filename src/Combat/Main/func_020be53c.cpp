#include <globaldefs.h>

struct S020d2eb0;
int GetField0x38(struct S020d2eb0* p);
void* ResolveOffsetOrPointerEntry_020d2eec(void* base, int index);
struct Obj020bda58;
void* AllocateAndLinkEntry020bda58(struct Obj020bda58* obj, unsigned int size, int a2, int a3, int a4);
extern "C" int func_020bd7c4(int index, void* buffer, int size, int offset);
void CleanCacheRange(const void* addr, unsigned int size);
struct SlotArray020d2eb8;
void StoreField0x3cArrayEntryAndFlush(struct SlotArray020d2eb8* obj, int index, int value);
void DetachEntryAndPostRangeEvent0x20_020be4f4(int start, int length, void* base, int index);

// USA: func_020be53c
extern "C" ARM int func_020be53c(void* obj, int index, int fatIndex, struct Obj020bda58* allocatorObj) {
    int size;
    if ((int)ResolveOffsetOrPointerEntry_020d2eec(obj, index) != 0) return 1;
    int capacity = GetField0x38((struct S020d2eb0*)obj);
    int idx = *(int*)((char*)obj + 0x38) + index;
    int* entry = (int*)obj + idx;
    int end;
    int start = entry[15];
    if ((unsigned int)index < (unsigned int)(capacity - 1)) end = entry[16];
    else end = ((int*)obj)[2];
    size = end - start;
    if (allocatorObj == 0) return 0;
    void* allocated = AllocateAndLinkEntry020bda58(allocatorObj, size + 0x20, (int)&DetachEntryAndPostRangeEvent0x20_020be4f4, (int)obj, index);
    if (allocated == 0) return 0;
    int bytesRead = func_020bd7c4(fatIndex, allocated, size, start);
    if (size != bytesRead) return 0;
    CleanCacheRange(allocated, size);
    StoreField0x3cArrayEntryAndFlush((struct SlotArray020d2eb8*)obj, index, (int)allocated);
    return 1;
}
