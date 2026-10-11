#if defined(jpn)
#define R(j,u) (j)
#define _Z24IssueBattleCommandSlot25ii func_020d84e0
#define data_ov001_02164ca4 data_ov001_02166270
#define data_ov028_021d9aa0 data_ov028_021da400
#define func_ov014_02188330 func_ov014_02189234
#define func_ov014_0218854c func_ov014_0218942c
#define func_ov014_021885bc func_ov014_0218948c
#define func_ov015_02191f04 func_ov015_02192a48
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

#include <System/Matrix.h>

struct NodeStruct02159ef0 {
    int type;
};

struct EventList0215a134 {
    struct NodeStruct02159ef0* head;
    struct NodeStruct02159ef0* tail;
};

struct Actor0215a134 {
    void* entries;
    int count;
    struct EventList0215a134 lists[8];
    char pad48[0x28];
    int modelIndex;
    Vector3fix position;
    Vector3fix rotation;
    float alpha;
    int radius;
};

struct ModelEntry0215a134;

typedef int (*NodeHandler0215a134)(struct NodeStruct02159ef0* node, struct Actor0215a134* actor);

extern struct ModelEntry0215a134* data_ov001_02165884;
extern NodeHandler0215a134 data_ov001_02164ca4[];

extern "C" int func_ov001_02164418(struct ModelEntry0215a134* table, int index, Vector3fix* dst);
extern "C" int func_ov001_021644c8(struct ModelEntry0215a134* table, int index, Vector3fix* dst);
extern "C" int func_ov001_0216427c(struct ModelEntry0215a134* table, int index, int x, int y, int z);
extern "C" int func_ov001_02164320(struct ModelEntry0215a134* table, int index, int x, int y, int z);
extern "C" int func_ov001_02164908(struct ModelEntry0215a134* table, int index, int alpha);
extern "C" int func_ov001_021649d4(struct ModelEntry0215a134* table, int index, int radius);
extern "C" void func_ov001_02159d9c(struct Actor0215a134* actor);
extern "C" struct NodeStruct02159ef0* _Z29GetValueAfterProcess_02159ef0PvP18NodeStruct02159ef0(void* owner, struct NodeStruct02159ef0* node);

// USA: func_ov001_0215a134
extern "C" ARM void func_ov001_0215a134(struct Actor0215a134* actor) {
    struct NodeStruct02159ef0* node;
    int i;
    struct NodeStruct02159ef0** head;
    struct NodeStruct02159ef0** tail;

    if (actor->modelIndex <= -1) {
        return;
    }
    if (func_ov001_02164418(data_ov001_02165884, actor->modelIndex, &actor->position) == 0) {
        func_ov001_02159d9c(actor);
        return;
    }
    func_ov001_021644c8(data_ov001_02165884, actor->modelIndex, &actor->rotation);

    for (i = 0; i < 8; i++) {
        switch (i) {
        case 0:
            head = &actor->lists[0].head;
            tail = &actor->lists[0].tail;
            break;
        case 1:
            head = &actor->lists[1].head;
            tail = &actor->lists[1].tail;
            break;
        case 2:
            head = &actor->lists[2].head;
            tail = &actor->lists[2].tail;
            break;
        case 3:
            head = &actor->lists[3].head;
            tail = &actor->lists[3].tail;
            break;
        case 4:
            head = &actor->lists[4].head;
            tail = &actor->lists[4].tail;
            break;
        case 5:
            head = &actor->lists[5].head;
            tail = &actor->lists[5].tail;
            break;
        case 6:
            head = &actor->lists[6].head;
            tail = &actor->lists[6].tail;
            break;
        case 7:
            head = &actor->lists[7].head;
            tail = &actor->lists[7].tail;
            break;
        }

        node = *head;
        while (node != NULL) {
            if (node->type > 0 && node->type < 0x1a) {
                if (data_ov001_02164ca4[node->type](node, actor) != 0) {
                    break;
                }
            } else {
                node = NULL;
                break;
            }
            node = _Z29GetValueAfterProcess_02159ef0PvP18NodeStruct02159ef0(actor, node);
        }
        *head = node;
        if (node == NULL) {
            *tail = NULL;
        }
    }

    Vector3fix position = actor->position;
    func_ov001_0216427c(data_ov001_02165884, actor->modelIndex, position.x, position.y, position.z);
    Vector3fix rotation = actor->rotation;
    func_ov001_02164320(data_ov001_02165884, actor->modelIndex, rotation.x, rotation.y, rotation.z);
    func_ov001_02164908(data_ov001_02165884, actor->modelIndex, actor->alpha);
    func_ov001_021649d4(data_ov001_02165884, actor->modelIndex, actor->radius);
}
