#include <globaldefs.h>
#include "Resource/Script.h"

struct Variant02030b0c;

struct List_020283c0;
struct ListEntry_020283c0;
struct ListEntry_020283c0* FindListEntryById(struct List_020283c0* list, int id);

struct AppendEntry {
    int a;
    int b;
};
struct AppendPairList;
void AppendPairToBoundedList(struct AppendPairList* list, struct AppendEntry* src);

extern void* data_020fdd30;

// USA: func_02027e44  (semantic: AppendMatchedPairsByCount02027e44)
extern "C" ARM int func_02027e44(void* param0, int count) {
    struct AppendEntry pair;
    pair.b = 0;
    pair.a = 0;
    void* startArg = param0;
    param0 = (char*)param0 + 8;
    int start = ((Script::Parameter*)((struct Variant02030b0c*)startArg))->ToInt();
    count = count - 1;
    pair.a = (int)FindListEntryById((struct List_020283c0*)data_020fdd30, start);
    for (; count >= 0;) {
        int id = ((Script::Parameter*)((struct Variant02030b0c*)param0))->ToInt();
        param0 = (char*)param0 + 8;
        count = count - 1;
        int cur = (int)FindListEntryById((struct List_020283c0*)data_020fdd30, id);
        pair.b = cur;
        if (pair.a != 0 && cur != 0) {
            AppendPairToBoundedList((struct AppendPairList*)data_020fdd30, &pair);
        }
        if (pair.b != 0) pair.a = pair.b;
    }
    return 1;
}
