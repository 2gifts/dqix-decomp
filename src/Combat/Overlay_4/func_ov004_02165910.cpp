#include <globaldefs.h>

int FindTreasureMapIndexAndDivide_021635d0(int* outQuotient, int* outRemainder);
extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, int);
#if defined(jpn)
extern "C" int func_ov023_021f6f10(void* self);
#else
int ScaleStatsIfType12_021f6f10(void* self);
#endif
extern "C" void func_ov023_021f9ba8(void* obj, unsigned short v);
extern "C" void func_ov004_02164084(void* obj);
extern "C" int func_ov023_021f98e0(void*, void*);

extern char* data_ov004_02171010;

struct Node02165910 { char pad[0x5c]; short f5c; short f5e; char pad2[0x61 - 0x5e - 2]; unsigned char f61; };

#if defined(jpn)
enum { kFieldBase = 0x1900 };
#else
enum { kFieldBase = 0x1800 };
#endif

// USA: func_ov004_02165910
extern "C" ARM int func_ov004_02165910(void* obj) {
    int remainder, quotient;
    quotient = 0;
    remainder = 0;
    if (FindTreasureMapIndexAndDivide_021635d0(&quotient, &remainder)) {
        struct Node02165910* node = (struct Node02165910*)func_ov023_021f6880(func_ov011_021849c8(obj), 0xa);
        if (node) {
#if defined(jpn)
            if (func_ov023_021f6f10(node) == 7) {
#else
            if (ScaleStatsIfType12_021f6f10(node) == 7) {
#endif
                *(short*)((char*)data_ov004_02171010 + kFieldBase + 0xf6) = (short)quotient;
                short valF8 = *(short*)((char*)data_ov004_02171010 + kFieldBase + 0xf8);
                short valF6 = *(short*)((char*)data_ov004_02171010 + kFieldBase + 0xf6);
                node->f5c = valF6;
                node->f5e = valF8;
                func_ov023_021f9ba8(node, (unsigned short)remainder);
                func_ov004_02164084(obj);
                func_ov023_021f9ba8(node, (unsigned short)remainder);
                func_ov023_021f98e0(node, obj);
            }
        }
    }

    struct Node02165910* node2 = (struct Node02165910*)func_ov023_021f6880(func_ov011_021849c8(obj), 0xa);
    if (!node2) {
        goto ret0;
    }
#if defined(jpn)
    if (func_ov023_021f6f10(node2) == 7) {
#else
    if (ScaleStatsIfType12_021f6f10(node2) == 7) {
#endif
        goto setf61;
    }
ret0:
    return 0;
setf61:
    node2->f61 = 0;
    return 0;
}
