#include <globaldefs.h>

struct ListHeadCEE68;
struct NodeCEE68;
ARM void AppendNodeToTail_020cee68(struct ListHeadCEE68*, struct NodeCEE68*);

extern int data_02111800;

// USA: func_020cef4c
ARM void AppendToGlobalList02111800_020cef4c(struct NodeCEE68* node) {
    AppendNodeToTail_020cee68((struct ListHeadCEE68*)&data_02111800, node);
}
