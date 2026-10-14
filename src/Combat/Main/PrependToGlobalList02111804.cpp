#include <globaldefs.h>

struct ListHeadCEE54;
struct NodeCEE54;
ARM void PrependNode_020cee54(struct ListHeadCEE54*, struct NodeCEE54*);

extern int data_02111804;

// USA: func_020cef34
ARM void PrependToGlobalList02111804_020cef34(struct NodeCEE54* node) {
    PrependNode_020cee54((struct ListHeadCEE54*)&data_02111804, node);
}
