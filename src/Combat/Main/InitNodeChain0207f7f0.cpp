#include <globaldefs.h>

struct Node0207f7f0 {
    struct Node0207f7f0* prev;
    char pad[0xe0 - 4];
};

struct Manager0207f7f0 {
    #if defined(jpn)
    char pad[0x24];
#else
    char pad[0x30];
#endif
    struct Node0207f7f0* nodes;
    char pad2[0x39 - 0x34];
    unsigned char count;
};

// USA: func_0207f7f0
ARM void InitNodeChain0207f7f0(struct Manager0207f7f0* mgr, struct Node0207f7f0* nodes, int count) {
    unsigned char i;
    mgr->nodes = nodes;
    mgr->count = (unsigned char)count;
    if (mgr->nodes != NULL && mgr->count != 0) {
        for (i = 1; i < mgr->count; i++) {
            mgr->nodes[i].prev = &mgr->nodes[i - 1];
        }
    }
}

// JPN: 0x02080568
