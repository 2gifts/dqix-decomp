#include <globaldefs.h>

struct Struct020dac68;
struct TailList020469b4;
struct TailNode020469b4;

extern void Init020dac68(Struct020dac68*);
extern void AppendNodeToTail(TailList020469b4*, TailNode020469b4*);

struct Root020dac40 {
#if defined(jpn)
    unsigned char pad[0x34ec];
#else
    unsigned char pad[0x36fc];
#endif
    TailList020469b4* list;
#if defined(jpn)
    unsigned char pad2[0x9a4 - 0x4ec - 4];
#else
    unsigned char pad2[0xbc4 - 0x6fc - 4];
#endif
    void* entity;
};

// USA: func_020dac40
ARM void InitAndAppendEntity020dac40(Root020dac40* root) {
    Init020dac68((Struct020dac68*)root->entity);
    AppendNodeToTail(root->list, (TailNode020469b4*)root->entity);
}
