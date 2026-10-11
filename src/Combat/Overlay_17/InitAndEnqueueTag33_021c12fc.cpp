#include <globaldefs.h>

struct TailList020469b4;
struct TailNode020469b4;
struct ByteHeader0204693c { signed char byte0, byte1, byte2, byte3; };
struct Obj021c1350;

void InitObj021c1350(struct Obj021c1350* obj, unsigned char a, unsigned char b);
void AppendNodeToTail(TailList020469b4* list, TailNode020469b4* node);
void EnqueueTag33ForListedCombatant_021c12b0(unsigned char param);

#if defined(jpn)
#define NODE_OFFSET 0x3930
#define LIST_OFFSET 0x34ec
#else
#define NODE_OFFSET 0x3b50
#define LIST_OFFSET 0x36fc
#endif

// JPN: func_ov017_021c18a4
// USA: func_ov017_021c12fc  (semantic: InitAndEnqueueTag33_021c12fc)
extern "C" ARM void func_ov017_021c12fc(char* self, unsigned char param2, unsigned char param3) {
    struct Obj021c1350* node = *(struct Obj021c1350**)(self + NODE_OFFSET);
    if (*((unsigned char*)node + 2) != 0) {
        return;
    }
    InitObj021c1350(node, param2, param3);
    AppendNodeToTail(*(TailList020469b4**)(self + LIST_OFFSET), *(TailNode020469b4**)(self + NODE_OFFSET));
    if (param2 == 0) return;
    if (param3 != 0) return;
    EnqueueTag33ForListedCombatant_021c12b0(1);
}
