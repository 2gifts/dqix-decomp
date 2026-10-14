#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Graphics/Vector.h"

struct Flags0202ecfc;
void ClearFlag0x1At0x168(struct Flags0202ecfc* p);

struct Block0202ecc8 { unsigned int v[12]; };
struct Dst0202ecc8;
void CopyBlockToField0xf0(struct Dst0202ecc8* dst, struct Block0202ecc8* src);

extern "C" void func_ov000_0216d234(void* a, void* b, void* c);

struct Field44_0216d560 { unsigned int v[3]; };
struct Field50_0216d560 { int x, y, z; };
struct Table_0216d560 { int x, y, z; };

struct Obj0216d560 {
    char pad[0x224];
    int field224;
};

// USA: func_ov000_0216d560  (semantic: SomeFunc_0216d560)
extern "C" ARM void func_ov000_0216d560(struct Obj0216d560* obj, int id) {
    GameObject* c = GameState::GetInstance()->GetGameObjectByIndex(id);
    if (!c) {
        obj->field224 = -1;
        ClearFlag0x1At0x168((struct Flags0202ecfc*)obj);
    } else {
        struct Field44_0216d560 fieldA = *(struct Field44_0216d560*)((char*)c + 0x44);
        struct Field50_0216d560 fieldB = *(struct Field50_0216d560*)((char*)c + 0x50);
        struct Table_0216d560 tbl;
        struct Block0202ecc8 block;
        tbl.x = fix32sin(fieldB.y);
        tbl.y = 0;
        tbl.z = fix32cos(fieldB.y);
        func_ov000_0216d234(&tbl, &fieldA, &block);
        CopyBlockToField0xf0((struct Dst0202ecc8*)obj, &block);
    }
}
