#include <globaldefs.h>

struct Entry0207f6ac;
struct List0207f6ac { Entry0207f6ac* entries; short count; };
struct MenuItems020806b0 {
    void* table;
    List0207f6ac items;
};
extern void SetEntryFlagBits0207f7ac(struct List0207f6ac* list, int id, int mask);

#if defined(jpn)
#define AddSublistEntryFlag2_020806b0 func_020811d8
extern "C" ARM void func_020811d8(void* obj, int id);
#endif

// USA: func_020806b0
ARM void AddSublistEntryFlag2_020806b0(void* obj, int id) {
    MenuItems020806b0* menu = (MenuItems020806b0*)obj;
    SetEntryFlagBits0207f7ac(&menu->items, id, 2);
}
