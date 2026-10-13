#include <globaldefs.h>
#include "System/WirelessScanDescriptor.h"

struct LookupList_0220ee50 {
    int field0;
    WirelessScanNode* head;
};

struct LookupContext_0220ee50 {
    char padding[0x2270];
    LookupList_0220ee50* list;
    unsigned int state;
};

int GetData0224e53c_0220d60c(void);

// USA: func_ov031_0220ee50
extern "C" ARM WirelessScanNode* func_ov031_0220ee50(int id) {
    LookupContext_0220ee50* context = (LookupContext_0220ee50*)GetData0224e53c_0220d60c();
    LookupList_0220ee50* list = context->list;
    WirelessScanNode* node = NULL;
    if (list != NULL && context->state > 12) {
        node = list->head;
        if (node != NULL) {
            do {
                if (node->index == id) break;
                node = node->next;
            } while (node != NULL);
        }
    }
    return node;
}
