#include <globaldefs.h>

struct NodeList0218e00c {
    void* head;
    int count;
    int owner;
};

// USA: func_ov016_0218e00c  (semantic: Trans_0218e00c)
extern "C" ARM void func_ov016_0218e00c(NodeList0218e00c* list) {
    list->head = NULL;
    list->count = 0;
    list->owner = 0;
}
