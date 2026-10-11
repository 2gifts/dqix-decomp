#include <globaldefs.h>

extern "C" int _s32_div_f(int a, int b);
extern char* data_ov004_021707c0; // pointer to struct with fields at 0x78 (short), 0x7a (short)

extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, int);
extern "C" void func_ov004_021536e0(void*, int, int);
extern "C" int func_ov023_021f809c(void*, void*);
#if defined(jpn)
extern "C" unsigned int func_ov023_021f6f10(void* self);
#define NODE_KIND_CALL func_ov023_021f6f10
#else
int ScaleStatsIfType12_021f6f10(void* self);
#define NODE_KIND_CALL ScaleStatsIfType12_021f6f10
#endif

struct VTable02154250 { char pad[0xe0]; void (*fn)(void*, int); };
struct Obj02154250 { struct VTable02154250* vtable; };

// USA: func_ov004_02154250
ARM int SetPercentAndFlags_02154250(void* a) {
    short cur = *(short*)(data_ov004_021707c0 + 0x7a);
    short max = *(short*)(data_ov004_021707c0 + 0x78);
    int percent = _s32_div_f(cur * 100, max);
    percent = (short)percent;
    if (percent == 0 && cur == 0) percent = 0;
    if (percent == 0 && cur != 0) percent = 1;
    if (percent > 100) percent = 100;
    if (percent < 0) percent = 0;

    void* base = func_ov011_021849c8(a);
    struct Obj02154250* node1 = (struct Obj02154250*)func_ov023_021f6880(base, 0x13);
    if (!node1) return 0;
    node1->vtable->fn(node1, percent);

    struct Obj02154250* node2 = (struct Obj02154250*)func_ov023_021f6880(base, 0x14);
    if (!node2) return 0;
    node2->vtable->fn(node2, cur);

#if !defined(jpn)
    func_ov004_021536e0(a, 0x14, 0x19);
#endif

    void* node3 = func_ov023_021f6880(base, 0x10);
    if (!node3) return 0;
    if (NODE_KIND_CALL(node3) != 6) return 0;
    func_ov023_021f809c(node3, a);
    return 0;
}
