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
void AppendPairToBoundedList_020281d8(struct AppendPairList* list, struct AppendEntry* src);

extern void* data_020fdd30;

// USA: func_02027db0
ARM int AppendMatchedPairIfFound02027db0(void* param0) {
    struct AppendEntry entry;
    int a, b;
    entry.b = 0;
    entry.a = 0;
    a = ((Script::Parameter*)((struct Variant02030b0c*)param0))->ToInt();
    b = ((Script::Parameter*)((struct Variant02030b0c*)((char*)param0 + 8)))->ToInt();
    if (a == b) return 0;
    entry.a = (int)FindListEntryById((struct List_020283c0*)data_020fdd30, a);
    entry.b = (int)FindListEntryById((struct List_020283c0*)data_020fdd30, b);
    if (entry.a == 0 || entry.b == 0) return 0;
    AppendPairToBoundedList_020281d8((struct AppendPairList*)data_020fdd30, &entry);
    return 1;
}
