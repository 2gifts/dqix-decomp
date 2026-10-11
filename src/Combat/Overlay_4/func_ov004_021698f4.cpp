#include <globaldefs.h>
#if defined(jpn)

#define func_ov023_021f6524 func_ov004_02168f08
#define func_ov004_02169658 func_ov004_02169b80
extern "C" void* func_ov004_02168fa4(void*, int);
#endif


#if defined(jpn)
extern "C" void* func_ov004_02168fd8(void*, int);
#define TYPE1_LOOKUP func_ov004_02168fd8
#else
void* GetNodeIfType1_02168aa0(void* a, int id);
#define TYPE1_LOOKUP GetNodeIfType1_02168aa0
#endif
extern "C" void* func_ov011_021849c8(void* ctx);
extern "C" void* func_ov023_021f6880(void* list, int value);
extern "C" int func_ov023_021f6f10(void* obj);
int CheckField0x9cSetWhenField0xd4Present(unsigned char* obj);
extern "C" void func_ov023_021f8120(void* obj);
extern "C" void* func_ov011_021845f8(void* ctx, int v);
extern "C" void func_ov023_021f6844(void* extra, int v);
extern "C" void _ZN13SafeAllocator5ResetEv(void* thisPtr);
struct Fields021849e0;
void SetFieldConditional_021849e0(struct Fields021849e0* obj, unsigned short val);
extern "C" void* func_ov023_021f6524(void* ctx, int value);
struct S021f9c0c;
void* ClearBuffer_021f9c0c(struct S021f9c0c* obj);
void SetByte38_021fb274(void* obj, unsigned char val);
extern "C" void func_ov004_02169658(void* a);
extern "C" void func_ov011_021848a0(void* obj, int val);

struct Obj0205eaa0;
void DispatchWithShortB4_0205eaa0(struct Obj0205eaa0* obj, int a, int b);
struct Data02171030 {
#if defined(jpn)
 char pad[0x20];
#else
 char pad[0x1a0];
#endif
 unsigned char field1a0; };
extern Data02171030* data_ov004_02171030;
extern struct Obj0205eaa0 data_02108760;

// USA: func_ov004_021698f4  (semantic: CheckAndDispatchFlags1f_021698f4)
extern "C" ARM int func_ov004_021698f4(void* a) {
    int found = 0;
    void* node1 = TYPE1_LOOKUP(a, 0x1f);
    if (!node1) return 0;

#if defined(jpn)
    void* node2 = func_ov004_02168fa4(a, 0x15);
#else
    void* node2 = func_ov023_021f6880(func_ov011_021849c8(a), 0x15);
    if (!node2 || func_ov023_021f6f10(node2) != 6) node2 = 0;
#endif

    if (node2) {
        unsigned char* f20 = (unsigned char*)node2 + 0x20;
        if (f20 && CheckField0x9cSetWhenField0xd4Present(f20)) {
            func_ov023_021f8120(node2);
            void* av = func_ov011_021845f8(a, 2);
            if (av) {
                func_ov023_021f6844(func_ov011_021849c8(a), 2);
                _ZN13SafeAllocator5ResetEv((char*)av + 4);
            }
            SetFieldConditional_021849e0((struct Fields021849e0*)a, 0);
            void* r = func_ov023_021f6524(a, 0x64);
            if (r) {
                ClearBuffer_021f9c0c((struct S021f9c0c*)r);
                found = 1;
            }
        }
    }

    SetByte38_021fb274(node1, 2);
    func_ov004_02169658(a);
    func_ov011_021848a0(a, 0x53);
    if (found) {
        SetFieldConditional_021849e0((struct Fields021849e0*)a, 0x64);
    }

    if (data_ov004_02171030->field1a0 != 0) {
        DispatchWithShortB4_0205eaa0(&data_02108760, 1, 0);
    }
    data_ov004_02171030->field1a0 = 0;
    return 0;
}
