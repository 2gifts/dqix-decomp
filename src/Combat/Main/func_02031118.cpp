#include <globaldefs.h>

struct Point02031118 { int x; int y; int z; };
struct Bounds02031118 { int minx; int miny; int minz; int maxx; int maxy; int maxz; };

// USA: func_02031118
extern "C" ARM int func_02031118(struct Point02031118* p, struct Bounds02031118* b) {
    if (b->minx < p->x) return 0;
    if (b->miny < p->y) return 0;
    if (b->minz < p->z) return 0;
    if (p->x < b->maxx) return 0;
    if (p->y < b->maxy) return 0;
    return p->z >= b->maxz ? 1 : 0;
}