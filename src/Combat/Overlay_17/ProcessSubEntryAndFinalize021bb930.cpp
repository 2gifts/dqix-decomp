#include <globaldefs.h>
#include "GameState/GameState.h"

void BlankFunction0208be8c(void);

struct Container0205a3d0;
struct Container0205a330;

struct Elem021bb930 {
    char unk0[4];
    unsigned short unk4;
    unsigned short unk6;
    char unk8[0x15 - 0x8];
    unsigned char flags15;
};

extern struct Elem021bb930* FindEntryByHalfword0205a3d0(struct Container0205a3d0*, int);
extern void SetEntryFlag2ByKey0205a370(struct Container0205a3d0*, int);
extern void IterateEntries0205a330(struct Container0205a330*, int);
extern void SetEntryByte14ByKey0205a42c(struct Container0205a3d0*, int, int);
extern "C" void func_0205ae8c(void* p);

struct Sub021bb930 {
    char pad0[0x3c];
    struct Container0205a3d0* c;
};

struct Obj021bb930 {
#if defined(jpn)
    char pad0[0xfa];
#else
    char pad0[0xfe];
#endif
    unsigned char flag0xfe;
    char pad1[0x120 - 0xff];
    void* field120;
    char pad2[0x168 - 0x124];
    struct Sub021bb930* sub;
};

// JPN: func_ov017_021bbf28
// USA: func_ov017_021bb930  (semantic: ProcessSubEntryAndFinalize021bb930)
extern "C" ARM void func_ov017_021bb930(struct Obj021bb930* self) {
    if (self->flag0xfe != 0 && self->sub != NULL) {
        GameState* battleStruct = GameState::GetInstance();
        struct Container0205a3d0* c = self->sub->c;
        if (c != NULL) {
            struct Elem021bb930* e;
            unsigned int count;
            SetEntryFlag2ByKey0205a370(c, 1);
            e = FindEntryByHalfword0205a3d0(c, 1);
            if (e != NULL) {
                e->flags15 |= 0x8;
            }
            count = battleStruct->GetTickCount();
            IterateEntries0205a330((struct Container0205a330*)c, count);
            e = FindEntryByHalfword0205a3d0(c, 1);
            if (e != NULL) {
                e->unk4 = 0xd8;
                e->unk6 = 0x98;
            }
            SetEntryByte14ByKey0205a42c(c, 1, 6);
        }
        func_0205ae8c(self->sub);
    }
    if (self->field120 != 0) {
        BlankFunction0208be8c();
    }
}
