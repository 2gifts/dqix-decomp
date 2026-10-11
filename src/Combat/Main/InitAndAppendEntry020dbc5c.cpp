#include <globaldefs.h>

#if defined(jpn)
enum { entryArrayOffset = 0x39a8, tailListOffset = 0x34f4 };
#else
enum { entryArrayOffset = 0x3bc8, tailListOffset = 0x3704 };
#endif

struct Struct020dbc9c;
void InitStruct020dbc9c(struct Struct020dbc9c* p);
struct TailList020469b4;
struct TailNode020469b4;
void AppendNodeToTail(struct TailList020469b4* list, struct TailNode020469b4* node);

struct Entry020dbc5c {
    char pad[8];
    signed char byte8;
    char pad2[11];
};

// USA: func_020dbc5c
ARM void InitAndAppendEntry020dbc5c(char* obj, int id) {
    struct Entry020dbc5c* e = (struct Entry020dbc5c*)(obj + entryArrayOffset + (id - 1) * 0x14);
    InitStruct020dbc9c((struct Struct020dbc9c*)e);
    e->byte8 = (signed char)id;
    AppendNodeToTail(*(struct TailList020469b4**)(obj + tailListOffset), (struct TailNode020469b4*)e);
}
