#include <globaldefs.h>

int GetField18_021f6f18(void* obj);
extern "C" unsigned int func_ov023_021f6f10(void* obj);

struct List0204afb4;
void ResetRecordList0204afb4(struct List0204afb4* obj);

struct SubStruct_021f7984 {
    char pad0[4];
    void* owner;
};

// JPN: func_ov023_021f6e7c
// USA: func_ov023_021f7984  (semantic: ClearOwnerAndResetList_021f7984)
extern "C" ARM void func_ov023_021f7984(void* obj, void** headHolder) {
#if defined(jpn)
 enum {regionalOffset0=0x24};
#else
 enum {regionalOffset0=0x28};
#endif
    void* node = *headHolder;
    while (node != 0) {
        void* next = (void*)GetField18_021f6f18(node);
        unsigned int type = func_ov023_021f6f10(node);
        if (type == 6) {
            SubStruct_021f7984* sub = (SubStruct_021f7984*)((char*)node + 0x20);
            if (sub != 0) {
                if ((void*)((char*)obj + regionalOffset0) == sub->owner) sub->owner = 0;
            }
        }
        node = next;
    }
    ResetRecordList0204afb4((struct List0204afb4*)((char*)obj + regionalOffset0));
}
