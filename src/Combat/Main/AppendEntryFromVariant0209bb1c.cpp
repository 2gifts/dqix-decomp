#include <globaldefs.h>
#include "Resource/Script.h"

struct Variant02030b0c { int tag; int val; };
void AppendZeroedEntry0209bd40(char* obj, int value);

struct Recorder0209bb0b {
    char* buffer;
    unsigned char pad[0x10];
    int active;
    int lastValue;
};
extern struct Recorder0209bb0b* data_02109bb0;

// USA: func_0209bb1c
ARM int AppendEntryFromVariant0209bb1c(struct Variant02030b0c* variant) {
    if (data_02109bb0->active == 0) return 1;
    int value = ((Script::Parameter*)variant)->ToInt();
    AppendZeroedEntry0209bd40(data_02109bb0->buffer, value);
    data_02109bb0->lastValue = value;
    return 1;
}
