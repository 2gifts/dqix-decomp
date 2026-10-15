#include <globaldefs.h>

struct List02160094;
struct ListNode02160094;

extern "C" void* func_ov017_0218b5b0(void);
struct ListNode02160094* GetNodeAtIndex02160094(struct List02160094* list, int index);
int GetByteAtPtrOrZero_02191b58(void*, int);
typedef int (*GetByteAtPtrOrZeroFn2)(void*, int);
extern "C" void func_ov017_0219230c(void* a, int b, int c);
extern "C" void func_ov017_02192400(void* a, int b);

// USA: func_ov025_021e8670  (semantic: DispatchNodeFlagOrClear_021e8670)
extern "C" ARM int func_ov025_021e8670(void* unused0, struct List02160094* list) {
    void* w = func_ov017_0218b5b0();
    struct ListNode02160094* node = GetNodeAtIndex02160094(list, 0);
    int lvl = *(unsigned short*)((char*)node + 0x20);
    int inRange = (lvl >= 0 && lvl <= 3);
    if (inRange && (((GetByteAtPtrOrZeroFn2)&GetByteAtPtrOrZero_02191b58)(w, lvl) & 2)) {
        func_ov017_0219230c(w, lvl, 8);
        return 1;
    }
    func_ov017_02192400(w, lvl);
    return 1;
}
