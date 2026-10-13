#include <globaldefs.h>

struct Entry0207f6ac;
struct List0207f6ac { Entry0207f6ac* entries; short count; };
struct MenuItems020806b0 {
    void* table;
    List0207f6ac items;
};
extern void SetEntryFlagBits0207f7ac(struct List0207f6ac* list, int id, int mask);

// USA: func_020806b0
ARM void AddSublistEntryFlag2_020806b0(void* obj, int id) {
    MenuItems020806b0* menu = (MenuItems020806b0*)obj;
    SetEntryFlagBits0207f7ac(&menu->items, id, 2);
}
