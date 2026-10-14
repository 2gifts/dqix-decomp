#include <globaldefs.h>

struct VCountAlarmNode {
    char _pad[0x14];
    struct VCountAlarmNode* prev;
    struct VCountAlarmNode* next;
};

struct VCountAlarmList {
    char _pad[0xc];
    struct VCountAlarmNode* head;
    struct VCountAlarmNode* tail;
};

extern struct VCountAlarmList data_02111654;

// USA: func_020c9384
ARM void UnlinkVCountAlarmNode_020c9384(struct VCountAlarmNode* node) {
    struct VCountAlarmNode* prev;
    struct VCountAlarmNode* next;
    if (node == NULL) {
        return;
    }
    prev = node->prev;
    next = node->next;
    if (next != NULL) {
        next->prev = prev;
    } else {
        data_02111654.tail = prev;
    }
    if (prev != NULL) {
        prev->next = next;
    } else {
        data_02111654.head = next;
    }
}
