#include <globaldefs.h>

#include "Combat/DistanceSort.h"
#include "GameState/GameState.h"

struct ListNode02057854;
int CheckListStableAndField8LtField402057854(ListNode02057854 *node);
struct S02055080;
void *GetSubField0x14(S02055080 *source);
int GetField0x3b0Value(GameState *state);

extern "C" void func_02059a54(void *node);

struct DispatchNodePrefix {
    unsigned char unknown0[0x10];
    Vector3fix position;
    unsigned char unknown1c[0x10];
    unsigned char enabled;
    unsigned char unknown2d[3];
    S02055080 *source;
    DispatchNodePrefix *head;
    unsigned char suppressed;
    unsigned char unknown39[0x128 - 0x39];
    int dispatchIndex;
    unsigned char unknown12c[0xc];
    float alpha;
    unsigned char unknown13c[0xc];
    DispatchNodePrefix *next;
};

struct DispatchSourcePrefix {
    unsigned char unknown0[5];
    unsigned char directOrder;
};

struct ViewPositionPrefix {
    int unknown0;
    Vector3fix position;
};

// USA: func_0205765c
extern "C" ARM void func_0205765c(int value) {
    DispatchNodePrefix *self = (DispatchNodePrefix *) value;
    if (CheckListStableAndField8LtField402057854((ListNode02057854 *) self) && self->suppressed) {
        return;
    }

    DispatchSourcePrefix *source = (DispatchSourcePrefix *) GetSubField0x14(self->source);
    if (!source->directOrder) {
        SortEntry_02056c3c entries[64];
        memset(entries, 0, sizeof(entries));
        Vector3fix viewPosition  = ((ViewPositionPrefix *) GetField0x3b0Value(GameState::GetInstance()))->position;
        viewPosition.y           = 0;
        int count                = 0;
        DispatchNodePrefix *node = self->head;
        while (node != NULL) {
            if (!node->enabled) {
                node = node->next;
                continue;
            }
            int alpha = (int) node->alpha;
            if (alpha <= 0) {
                node = node->next;
                continue;
            }
            if (alpha > 31) {
                alpha = 31;
            }
            alpha += 31;
            if (alpha > 47) {
                alpha -= 17;
            }
            node->dispatchIndex     = alpha;
            Vector3fix position     = node->position;
            position.y              = 0;
            entries[count].node     = node;
            entries[count].distance = (float) Vector3fix_Distance(&position, &viewPosition) / 4096.0f;
            node                    = node->next;
            count++;
        }
        if (count > 0) {
            func_02056c3c(self, entries, 0, count - 1);
            for (int index = 0; index < count; index++) {
                func_02059a54(entries[index].node);
            }
        }
    } else {
        DispatchNodePrefix *node = self->head;
        while (node != NULL) {
            if (!node->enabled) {
                node = node->next;
                continue;
            }
            func_02059a54(node);
            node = node->next;
        }
    }
}
