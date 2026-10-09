#include <globaldefs.h>
#include "std_library_functions.h"

struct PathNode021e2148 {
    unsigned char id;
    unsigned char cost;
    unsigned char score;
    unsigned char heuristic;
    unsigned char parent;
    unsigned char blocked;
    char pad6[2];
    PathNode021e2148* next;
};

struct PathList021e2148 {
    PathNode021e2148* head;
};

struct PathGraph021e2148 {
    PathNode021e2148* nodes;
    int count;
    unsigned char blockedCells[12];
    unsigned char numBlocked;
};

struct Neighbors021e2148 {
    unsigned char b[6];
};

extern "C" void _Z21PushFrontNode021e23d0P12List021e23d0P12Node021e23d0(PathList021e2148* list, PathNode021e2148* node);
extern "C" int _Z20IsFieldZero_021e2494Pv(PathList021e2148* list);
extern "C" PathNode021e2148* _Z25FindAndRemoveMin_021e23e8P12List021e23e8(PathList021e2148* list);
extern "C" void _Z18RemoveNode021e244cP12List021e244cP12Node021e244c(PathList021e2148* list, PathNode021e2148* node);
extern "C" int func_ov025_021e24a8(PathList021e2148* list, PathNode021e2148* node);
extern "C" void func_ov000_0216f82c(Neighbors021e2148* out, const int* cell);

// USA: func_ov025_021e2148
extern "C" ARM int func_ov025_021e2148(PathGraph021e2148* graph, int start, int goal, unsigned char* out, int maxLen) {
    if (graph->nodes == NULL) {
        return 0;
    }
    if (graph->count <= start) {
        return 0;
    }
    if (graph->count <= goal) {
        return 0;
    }
    memset(graph->nodes, 0, graph->count * sizeof(PathNode021e2148));

    PathList021e2148 open;
    PathList021e2148 closed;
    open.head = NULL;
    closed.head = NULL;

    unsigned char* cells = graph->blockedCells;
    for (int i = 0; i < graph->numBlocked; i++) {
        int cell = cells[i];
        if (graph->count <= cell) {
            return 0;
        }
        graph->nodes[cell].blocked = 1;
    }

    PathNode021e2148* node = &graph->nodes[start];
    node->id = start;
    node->cost = 0;
    node->score = 0;
    node->heuristic = 0;
    node->parent = 0xff;
    node->next = NULL;
    node->blocked = 0;
    _Z21PushFrontNode021e23d0P12List021e23d0P12Node021e23d0(&open, node);

    PathNode021e2148* cur;
    while (true) {
        if (_Z20IsFieldZero_021e2494Pv(&open)) {
            return 0;
        }
        cur = _Z25FindAndRemoveMin_021e23e8P12List021e23e8(&open);
        if (cur->id == goal) {
            break;
        }
        _Z21PushFrontNode021e23d0P12List021e23d0P12Node021e23d0(&closed, cur);

        Neighbors021e2148 nb;
        Neighbors021e2148 tmp;
        int cell = cur->id;
        func_ov000_0216f82c(&tmp, &cell);
        nb = tmp;

        for (int i = 0; i < 6; i++) {
            int id = nb.b[i];
            if (id == 0xff) {
                continue;
            }
            PathNode021e2148* next = &graph->nodes[id];
            next->id = id;
            if (graph->count <= id) {
                return 0;
            }
            if (next->blocked != 0) {
                continue;
            }
            cur->score = cur->cost - cur->heuristic;
            int cost = cur->score + 1;
            if (func_ov025_021e24a8(&open, next)) {
                if (cost < next->cost) {
                    next->cost = cost;
                    next->parent = cur->id;
                }
            } else if (func_ov025_021e24a8(&closed, next)) {
                if (cost < next->cost) {
                    next->cost = cost;
                    next->parent = cur->id;
                    _Z18RemoveNode021e244cP12List021e244cP12Node021e244c(&closed, next);
                    _Z21PushFrontNode021e23d0P12List021e23d0P12Node021e23d0(&open, next);
                }
            } else {
                next->cost = cost;
                next->parent = cur->id;
                _Z21PushFrontNode021e23d0P12List021e23d0P12Node021e23d0(&open, next);
            }
        }
    }

    PathNode021e2148* p = &graph->nodes[goal];
    int n = 0;
    while (true) {
        out[n] = p->id;
        n++;
        if (maxLen <= n) {
            break;
        }
        int parent = p->parent;
        if (graph->count <= parent) {
            break;
        }
        p = &graph->nodes[parent];
    }
    return n;
}
