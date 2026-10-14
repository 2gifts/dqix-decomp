#include <globaldefs.h>

struct TaggedNumber02184c30 { unsigned int a, b; };
int GetTaggedValueAsInt_02184c30(struct TaggedNumber02184c30*);
struct FnRows02186440 { unsigned int w[8]; };
extern FnRows02186440 data_ov011_02188934;
#define CALL(x) GetTaggedValueAsInt_02184c30(x)

// USA: func_ov011_02186440
ARM int InvokeTaggedHandlers_02186440(struct TaggedNumber02184c30* obj, int count) {
    FnRows02186440 rows;
    int idx = CALL(obj++);
    rows = data_ov011_02188934;
    unsigned int* fn = &rows.w[idx * 4];
    count--;
    while (count != 0) {
        int v = CALL(obj++);
        unsigned int f = *fn++;
        ((void (*)(int))f)(v);
        count--;
    }
    return 1;
}
