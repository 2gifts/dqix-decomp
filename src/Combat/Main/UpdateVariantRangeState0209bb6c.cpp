#include <globaldefs.h>
#include "Resource/Script.h"

struct Variant02030b0c;

struct Table0209bb6c { char pad[0xc0]; int count; };
struct Ctx0209bb6c {
    struct Table0209bb6c* field0;
    int field4;
    int field8;
    int fieldc;
    int field10;
    int field14;
};
extern struct Ctx0209bb6c* data_02109bb0;

// USA: func_0209bb6c
ARM int UpdateVariantRangeState0209bb6c(struct Variant02030b0c* obj, int count) {
    int a, b, c, d;

    data_02109bb0->field14 = 0;
    if (data_02109bb0->field10 == 0) return 1;
    {
        int val = ((Script::Parameter*)obj)->ToInt();
        if (val != data_02109bb0->field4) return 1;
    }

    a = 0;
    b = 0;
    c = 0;
    d = 0;
    if (count > 1) {
        a = ((Script::Parameter*)((struct Variant02030b0c*)((char*)obj + 8)))->ToInt();
        b = ((Script::Parameter*)((struct Variant02030b0c*)((char*)obj + 0x10)))->ToInt();
        c = ((Script::Parameter*)((struct Variant02030b0c*)((char*)obj + 0x18)))->ToInt();
        d = ((Script::Parameter*)((struct Variant02030b0c*)((char*)obj + 0x20)))->ToInt();
    }

    {
        int lowSum = a * 100 + b;
        int highSum = c * 100 + d;
        int mid = data_02109bb0->field8 * 100 + data_02109bb0->fieldc;

        if (a == 0 && b == 0 && c == 0 && d == 0) {
            data_02109bb0->field14 = 1;
            data_02109bb0->field0->count = 0;
        } else if (lowSum <= mid && mid <= highSum) {
            data_02109bb0->field14 = 1;
            data_02109bb0->field10 = 0;
            data_02109bb0->field0->count = 0;
        }
    }
    return 1;
}
