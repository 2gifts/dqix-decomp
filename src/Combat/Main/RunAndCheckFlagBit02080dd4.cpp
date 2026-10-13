#include <globaldefs.h>

struct Entry0207f6ac {
    unsigned char unknown0[0x2a];
    unsigned char flags;
    unsigned char unknown2b[5];
};
struct List0207f6ac {
    Entry0207f6ac* entries;
    short count;
};
struct MenuStateView {
    void* textTable;
    List0207f6ac items;
};

extern "C" int func_02080e40(void* menu, int groupId, int x, int y);
struct Entry0207f6ac* FindEntryByShortId0207f6ac(struct List0207f6ac* list, int id);

extern "C" void func_02080558(void* obj, int p1, int result, int flag, unsigned char extra);

// USA: func_02080dd4
ARM int RunAndCheckFlagBit02080dd4(void* menuData, int groupId, int pointX, int pointY,
                                  unsigned char* outPreviouslySelected, unsigned char refreshDisplay) {
    MenuStateView* menu = static_cast<MenuStateView*>(menuData);
    int result;
    struct Entry0207f6ac* entry;
    result = func_02080e40(menu, groupId, pointX, pointY);
    if (result == -1) {
        return -1;
    }
    *outPreviouslySelected = 0;
    entry = FindEntryByShortId0207f6ac(&menu->items, result);
    if (entry->flags & 4) {
        *outPreviouslySelected = 1;
    }
    func_02080558(menu, groupId, result, 1, refreshDisplay);
    return result;
}
