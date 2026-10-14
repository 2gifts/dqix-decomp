#include <globaldefs.h>

extern "C" void* func_ov011_021849c8(int type);
extern "C" void* func_ov023_021f6880(void** list, int value);
void* GetFieldPtrAt_021f79e4_021f79e4(void* obj);
int CheckField0x9cSetWhenField0xd4Present_0204c7e0(unsigned char* obj);
extern "C" int func_0204fd00(void* ctx, int mask);
extern "C" void func_0204bc74(void* target, int type, short a, short b, short c, short d, int flags);

// USA: func_ov023_021f86fc  (semantic: DispatchBoundsEdges_021f86fc)
extern "C" ARM void func_ov023_021f86fc(unsigned char* obj, int key) {
    void* list = func_ov011_021849c8(key);
    void* node = func_ov023_021f6880((void**)list, obj[0x108]);
    if (!node) return;
    void* target = GetFieldPtrAt_021f79e4_021f79e4(node);
    if (!CheckField0x9cSetWhenField0xd4Present_0204c7e0(obj + 0x20)) return;
    if (obj[0xe5] & 0x20) return;
    if (obj[0xe5] & 0x80) return;
    short cc = *(short*)(obj + 0xcc);
    short ce = *(short*)(obj + 0xce);
    short c8 = *(short*)(obj + 0xc8);
    short e0 = *(short*)(obj + 0xe0);
    func_0204bc74(target, 1, cc, ce, c8, e0, 0);
    if (e0 == 0) return;
    if (!func_0204fd00(obj + 0x20, 1))
        func_0204bc74(target, 2, cc, ce, 1, 1, 0);
    if (!func_0204fd00(obj + 0x20, 2))
        func_0204bc74(target, 0x402, (short)(cc + c8 - 1), ce, 1, 1, 0);
    if (!func_0204fd00(obj + 0x20, 4))
        func_0204bc74(target, 0x802, cc, (short)(ce + e0 - 1), 1, 1, 0);
    if (!func_0204fd00(obj + 0x20, 8))
        func_0204bc74(target, 0xc02, (short)(cc + c8 - 1), (short)(ce + e0 - 1), 1, 1, 0);
}
