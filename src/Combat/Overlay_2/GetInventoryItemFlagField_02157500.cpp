#include <globaldefs.h>

extern "C" int GetInventoryItemByID(void* obj);

struct Container020dedd0;
struct Element020de650;
struct Element020de650* FindElementByKey020dedd0(struct Container020dedd0* c, int key);

// USA: func_ov002_02157500
ARM int GetInventoryItemFlagField_02157500(char* obj, int, int) {
    int invId = GetInventoryItemByID(obj);
    if (invId < 0) {
        return 0;
    }
    struct Element020de650* elem = FindElementByKey020dedd0((struct Container020dedd0*)(obj + 0x3ec + 0x400), invId);
    if (elem != NULL) {
        unsigned int v = *(unsigned int*)((char*)elem + 8);
        return (int)((v << 16) >> 30);
    }
    return 0;
}
