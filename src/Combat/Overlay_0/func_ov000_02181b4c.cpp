#include <globaldefs.h>

struct TargetNode {
    char pad0[0xe];
    short targets[3];
    unsigned char kinds[3];
    unsigned char count;
    char pad18[0x20 - 0x18];
    TargetNode* next;
};

struct TargetList {
    char pad0[0x14];
    TargetNode* head;
};

extern "C" int func_ov000_0215e9fc(void* obj, short* buf, int max, int start);

static inline int IsGroupTarget(int target)
{
    return target >= 0 && target <= 3;
}

// USA: func_ov000_02181b4c
extern "C" ARM int func_ov000_02181b4c(void* obj, TargetList* list, int* outArray)
{
    int count = 0;
    TargetNode* node;
    for (node = list->head; node != NULL; node = node->next) {
        int i;
        for (i = 0; i < node->count; i++) {
            if (i > 0) {
                unsigned char kind = node->kinds[i];
                if (kind != 8 && kind != 6 && kind != 7)
                    break;
            }
            int target = node->targets[i];
            bool isNew = true;
            int* out = outArray;
            int j;
            for (j = 0; j < count; j++, out++) {
                if (*out == target) {
                    isNew = false;
                    break;
                }
            }
            if (isNew) {
                if (IsGroupTarget(target)) {
                    short buf[4];
                    count = func_ov000_0215e9fc(obj, buf, 4, 0);
                    out = outArray;
                    short* src = buf;
                    int k;
                    for (k = 0; k < count; k++) {
                        *out = *src;
                        out++;
                        src++;
                    }
                    return count;
                }
                *out = target;
                count++;
            }
        }
    }
    return count;
}
