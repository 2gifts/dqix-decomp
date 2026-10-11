#include <globaldefs.h>

struct LookupNode_0220ee50 {
    int field0;
    int id;
    int field8;
    LookupNode_0220ee50* next;
};

struct LookupList_0220ee50 {
    int field0;
    LookupNode_0220ee50* head;
};

struct LookupContext_0220ee50 {
    char padding[0x2270];
    LookupList_0220ee50* list;
    unsigned int state;
};

int GetData0224e53c_0220d60c(void);

// USA: func_ov031_0220ee50
extern "C" ARM int func_ov031_0220ee50(int id) {
    LookupContext_0220ee50* context = (LookupContext_0220ee50*)GetData0224e53c_0220d60c();
    LookupList_0220ee50* list = context->list;
    LookupNode_0220ee50* node = NULL;
    if (list != NULL && context->state > 12) {
        node = list->head;
        if (node != NULL) {
            do {
                if (node->id == id) break;
                node = node->next;
            } while (node != NULL);
        }
    }
    return (int)node;
}
