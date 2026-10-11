#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

struct TaggedNumber02184c30 {
    int type;
    union { int i; float f; } value;
};

struct TaggedInput_02187a14 {
    TaggedNumber02184c30 a;
    TaggedNumber02184c30 b;
    TaggedNumber02184c30 c;
};

int GetTaggedValueAsInt_02184c30(struct TaggedNumber02184c30* v);
extern "C" ARM void* func_ov017_021b2164(void);
extern "C" ARM void* func_ov011_021849c8(void* ctx);
extern "C" ARM void* func_ov023_021f6880(void* obj, int v);
extern "C" ARM int func_ov023_021f6f10(void* obj);
extern "C" ARM void* func_ov011_021845f8(void* ctx, int v);

struct Obj_02185110;
#if defined(jpn)
#define InitObj02185110 _Z15InitObj02185110P12Obj_02185110
extern "C" ARM Obj_02185110* InitObj02185110(Obj_02185110* obj);
#else
ARM Obj_02185110* InitObj02185110(Obj_02185110* obj);
#endif
#if defined(jpn)
#define InitField20And34_0218513c _Z25InitField20And34_0218513cPv
extern "C" ARM void* InitField20And34_0218513c(void* obj);
#else
ARM void* InitField20And34_0218513c(void* obj);
#endif
ARM int InitObjWithMisc_021f6f20(void* obj, int p1, int p3, int p4, int arg5, unsigned int arg6);
ARM void* AddOffset20_021f7318(void* p);

struct Foo02048004;
ARM void CopyFieldsWithFlags02048004(struct Foo02048004* src, struct Foo02048004* dst);
ARM void SetField1cTo2_021f7320(void* p);

struct ListHead_021f67ac;
struct ListNode_021f67ac;
void AppendNodeToList_021f67ac(struct ListHead_021f67ac* head, struct ListNode_021f67ac* node);

struct LocalNodeBuf_02187a14 {
    int words[0xac / 4];
};

// USA: func_ov011_02187a14  (semantic: AllocateAndInitNode_02187a14)
extern "C" ARM int func_ov011_02187a14(struct TaggedInput_02187a14* obj) {
    int tag0 = GetTaggedValueAsInt_02184c30(&obj->a);
    int tag8 = GetTaggedValueAsInt_02184c30(&obj->b);
    int tag10 = GetTaggedValueAsInt_02184c30(&obj->c);

    void* ctx = func_ov017_021b2164();
    void* list = func_ov011_021849c8(ctx);
    void* e2 = func_ov023_021f6880(list, tag10);
    func_ov023_021f6f10(e2);

    void* node = func_ov011_021845f8(ctx, tag8);
    if (node == 0) return 0;

    ((SafeAllocator*)((char*)node + 4))->GetSizeWithLargestBlockRemoved();
    void* block = ((SafeAllocator*)((char*)node + 4))->Allocate(0xac);
    if (block == 0) return 0;

    LocalNodeBuf_02187a14 local;
    InitObj02185110((Obj_02185110*)&local);
    memcpy(block, &local, sizeof(local));

    if (InitObjWithMisc_021f6f20(block, (int)ctx, tag0, tag8, 0, 0) == 0) {
        InitField20And34_0218513c(&local);
        return 0;
    }

    void* p1 = AddOffset20_021f7318(e2);
    void* p2 = AddOffset20_021f7318(block);
    CopyFieldsWithFlags02048004((struct Foo02048004*)p1, (struct Foo02048004*)p2);
    SetField1cTo2_021f7320(block);
    AppendNodeToList_021f67ac((struct ListHead_021f67ac*)list, (struct ListNode_021f67ac*)block);
    InitField20And34_0218513c(&local);
    return 1;
}
