#include <globaldefs.h>
#include "GameState/Field3b0.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"

extern "C" int func_ov017_021d60f4(void*);
extern "C" void* func_ov017_021d612c(void*);
extern SafeAllocator* data_ov001_021658b8[8];
void* GetFieldPtrAt0x5ca4(void* obj);
void SetField0x3b0Value(GameState* battleStruct, int value);

struct Obj0204a120;
void InitState0204a120(struct Obj0204a120* obj);

struct Owner0204a3f0;
struct Holder0204a3f0;
void SetHolderAndMarkNode0204a3f0(struct Owner0204a3f0* owner, struct Holder0204a3f0* h);

void SetName0204a440(char* obj, const char* src);
void SetStringField0234(char* obj, const char* src);

struct Entry_02161650 { int type; int val; int pad2; void* child; };
struct DataTable_02161650 { char pad0[4]; Entry_02161650* table; };
extern struct DataTable_02161650 data_ov001_02165880;

// USA: func_ov001_02161650  (semantic: AllocateAndLinkStateHolder_02161650)
extern "C" ARM int func_ov001_02161650(char* self) {
    GameState* bs = GameState::GetInstance();
    SafeAllocator* allocator = data_ov001_021658b8[0];
    void* fieldPtr = GetFieldPtrAt0x5ca4(bs);

    int a = func_ov017_021d60f4(self);
    void* name = func_ov017_021d612c(self + 0x8);
    void* str1 = func_ov017_021d612c(self + 0x10);

    void* child = data_ov001_02165880.table[a].child;
    if (child == 0 || data_ov001_02165880.table[a].type != 1) {
        return 0;
    }

    void* newObj = allocator->Allocate(0x268);
    if (newObj == 0) return 0;

    *(void**)((char*)fieldPtr + 0x4) = GetField0x3b0Value(bs);

    InitState0204a120((struct Obj0204a120*)newObj);
    SetHolderAndMarkNode0204a3f0((struct Owner0204a3f0*)newObj, (struct Holder0204a3f0*)child);
    ((Object3D*)child)->UntrackAllBones();
    SetName0204a440((char*)newObj, (const char*)name);
    SetStringField0234((char*)newObj, (const char*)str1);
    ((Object3D*)((unsigned char*)child))->StopCurrentAnimation();
    ((Object3D*)((unsigned char*)child))->EnableFlag(1);
    ((Object3D*)((unsigned char*)child))->EnableFlag(0x20);

    SetField0x3b0Value(bs, (int)newObj);
    return 1;
}
