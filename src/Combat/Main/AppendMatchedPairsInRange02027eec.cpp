#include <globaldefs.h>
#include "Resource/Script.h"
#include "World/GrottoTileGraph.h"

struct Variant02030b0c;

struct List_020283c0;
Elem02028170* FindListEntryById(struct List_020283c0* list, int id);

struct AppendPairList;
void AppendPairToBoundedList_020281d8(struct AppendPairList* list, AppendEntry* src);

extern void* data_020fdd30;

// USA: func_02027eec  (semantic: AppendMatchedPairsInRange02027eec)
extern "C" ARM int func_02027eec(void* param0) {
    AppendEntry pair;
    int start, end, id;
    start = ((Script::Parameter*)((struct Variant02030b0c*)param0))->ToInt();
    end = ((Script::Parameter*)((struct Variant02030b0c*)((char*)param0 + 8)))->ToInt();
    pair.first = 0;
    pair.second = 0;
    id = start + 1;
    pair.first = FindListEntryById((struct List_020283c0*)data_020fdd30, start);
    for (; id <= end;) {
        Elem02028170* cur = FindListEntryById((struct List_020283c0*)data_020fdd30, id);
        pair.second = cur;
        id++;
        if (pair.first != 0 && cur != 0) {
            AppendPairToBoundedList_020281d8((struct AppendPairList*)data_020fdd30, &pair);
        }
        if (pair.second != 0) pair.first = pair.second;
    }
    return 1;
}
