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

// USA: func_02027eec  (semantic: AppendMatchedPairsInRange02027eec)
extern "C" ARM int func_02027eec(void* param0) {
    struct AppendEntry pair;
    int start, end, id;
    start = ((Script::Parameter*)((struct Variant02030b0c*)param0))->ToInt();
    end = ((Script::Parameter*)((struct Variant02030b0c*)((char*)param0 + 8)))->ToInt();
    pair.a = 0;
    pair.b = 0;
    id = start + 1;
    pair.a = (int)FindListEntryById((struct List_020283c0*)data_020fdd30, start);
    for (; id <= end;) {
        int cur = (int)FindListEntryById((struct List_020283c0*)data_020fdd30, id);
        pair.b = cur;
        id++;
        if (pair.a != 0 && cur != 0) {
            AppendPairToBoundedList((struct AppendPairList*)data_020fdd30, &pair);
        }
        if (pair.b != 0) pair.a = pair.b;
    }
    return 1;
}
