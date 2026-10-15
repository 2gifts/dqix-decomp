#include <globaldefs.h>
#include "Resource/Script.h"
#include "World/GrottoTileGraph.h"

struct Variant02030b0c;

struct List_020283c0;
Elem02028170* FindListEntryById(struct List_020283c0* list, int id);

struct AppendPairList;
void AppendPairToBoundedList_020281d8(struct AppendPairList* list, struct AppendEntry* src);

extern void* data_020fdd30;

// USA: func_02027e44  (semantic: AppendMatchedPairsByCount02027e44)
extern "C" ARM int func_02027e44(void* param0, int count) {
    struct AppendEntry pair;
    pair.second = 0;
    pair.first = 0;
    void* startArg = param0;
    param0 = (char*)param0 + 8;
    int start = ((Script::Parameter*)((struct Variant02030b0c*)startArg))->ToInt();
    count = count - 1;
    pair.first = FindListEntryById((struct List_020283c0*)data_020fdd30, start);
    for (; count >= 0;) {
        int id = ((Script::Parameter*)((struct Variant02030b0c*)param0))->ToInt();
        param0 = (char*)param0 + 8;
        count = count - 1;
        Elem02028170* cur = FindListEntryById((struct List_020283c0*)data_020fdd30, id);
        pair.second = cur;
        if (pair.first != 0 && cur != 0) {
            AppendPairToBoundedList_020281d8((struct AppendPairList*)data_020fdd30, &pair);
        }
        if (pair.second != 0) pair.first = pair.second;
    }
    return 1;
}
