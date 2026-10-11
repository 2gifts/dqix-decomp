#include <globaldefs.h>
#if defined(jpn)
enum { kRegion13ec = 0x127c };
enum { kRegion12a8 = 0x1138 };
enum { kRegion126c = 0x10fc };
enum { kRegiondf = 0xd7 };
#else
enum { kRegion13ec = 0x13ec };
enum { kRegion12a8 = 0x12a8 };
enum { kRegion126c = 0x126c };
enum { kRegiondf = 0xdf };
#endif

#include "GameState/GameState.h"


struct Container0205a3d0;
struct Elem0205a3d0;
void SetEntryFlag2ByKey0205a370(struct Container0205a3d0* c, int key);
struct Elem0205a3d0* FindEntryByHalfword0205a3d0(struct Container0205a3d0* c, int key);
void SetEntryPosition(struct Container0205a3d0* c, int key, short a, short b);
void SetEntryByte14ByKey0205a42c(struct Container0205a3d0* c, int key, int val);

struct Container0205a330;
void IterateEntries0205a330(struct Container0205a330* c, int arg);

struct Struct0200fb08;
int NormalizeField5_0200fb08(struct Struct0200fb08*);

extern "C" void func_0205ae8c(void* obj);

// JPN: func_ov003_0216d794
// USA: func_ov003_0216ddfc  (semantic: UpdateEntryOnFlag_0216ddfc)
extern "C" ARM void func_ov003_0216ddfc(char* obj) {
    GameState* battle = GameState::GetInstance();
    if (*(unsigned char*)(obj + kRegion13ec) & 4) {
        struct Container0205a3d0* cont = *(struct Container0205a3d0**)(obj + kRegion12a8);
        if (cont != 0) {
            SetEntryFlag2ByKey0205a370(cont, 1);
            struct Elem0205a3d0* e = FindEntryByHalfword0205a3d0(cont, 1);
            if (e != 0) {
                *(unsigned char*)((char*)e + 0x15) |= 8;
            }
            IterateEntries0205a330((struct Container0205a330*)cont, battle->GetTickCount());
            SetEntryPosition(cont, 1, kRegiondf, 0x96);
            SetEntryByte14ByKey0205a42c(cont, 1, 0x10);
#if !defined(jpn)
            if (NormalizeField5_0200fb08((struct Struct0200fb08*)GameState::GetInstance()) == 3) {
                SetEntryPosition(cont, 1, 0xd7, 0x96);
            }
#endif
        }
        func_0205ae8c(obj + kRegion126c);
        return;
    }

    struct Container0205a3d0* cont = *(struct Container0205a3d0**)(obj + kRegion12a8);
    if (cont == 0) return;
    struct Elem0205a3d0* e = FindEntryByHalfword0205a3d0(cont, 1);
    if (e != 0) {
        *(unsigned char*)((char*)e + 0x15) &= ~8;
    }
}
