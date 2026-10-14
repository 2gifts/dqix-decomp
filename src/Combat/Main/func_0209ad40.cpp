#include <globaldefs.h>
#include "Resource/Script.h"

struct Variant02030b0c { int tag; int u; };

struct StoreCellWordHalfSource;
struct StoreCellWordHalfRow;
void StoreCellWordHalf_0209b988(struct StoreCellWordHalfRow *base, int i, int j,
                       struct StoreCellWordHalfSource *src);

struct GetRowByIndexRow;
struct GetRowByIndexRow* GetRowByIndex_0209b9c0(struct GetRowByIndexRow* base, int i);

struct Source0209ad40 {
    unsigned int w;
    struct {
        unsigned short lo : 8;
        unsigned short hi : 8;
    } b;
};

extern void* data_02109bac;

// USA: func_0209ad40
extern "C" ARM int func_0209ad40(struct Variant02030b0c* arg0) {
    char* p = (char*)data_02109bac;
    if (*(int*)(p + 0x8) == 0) return 1;

    char* q = *(char**)(p + 0x0);
    int i = *(int*)(q + 0x1c8);
    int j = *(int*)(q + 0x1cc);

    struct Source0209ad40 src;
    src.w = (unsigned int)((Script::Parameter*)arg0)->ToInt();
    int v = ((Script::Parameter*)&arg0[1])->ToInt();

    src.b.lo = (unsigned char)v;
    src.b.hi = (unsigned char)(v >> 8);

    q = *(char**)((char*)data_02109bac + 0x0);
    StoreCellWordHalf_0209b988((struct StoreCellWordHalfRow*)q, i, j, (struct StoreCellWordHalfSource*)&src);

    *(int*)(*(char**)((char*)data_02109bac + 0x0) + 0x1cc) = j + 1;

    q = *(char**)((char*)data_02109bac + 0x0);
    struct GetRowByIndexRow* row = GetRowByIndex_0209b9c0((struct GetRowByIndexRow*)q, i);
    if (row != 0) {
        unsigned char* cnt = (unsigned char*)row + 2;
        *cnt = *cnt + 1;
    }
    return 1;
}
