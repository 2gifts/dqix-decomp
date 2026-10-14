#include <globaldefs.h>

struct FindEntryById02096134Elem;
struct FindEntryById02096134Table;
struct FindEntryById02096134Elem* FindEntryById02096134(struct FindEntryById02096134Table* t, int id);
int* GetGlobal02109418_02094d6c(void);

// USA: func_02064904
ARM void* GetStatFieldPointer02064904(void* unusedA, int id, unsigned int statIndex) {
    struct FindEntryById02096134Elem* elem = FindEntryById02096134((struct FindEntryById02096134Table*)GetGlobal02109418_02094d6c(), id);
    void* result = NULL;
    if (elem != NULL && statIndex <= 9) {
        switch (statIndex) {
            case 0: result = (char*)elem + 0xa; break;
            case 1: result = (char*)elem + 0xa; break;
            case 2: result = (char*)elem + 0xc; break;
            case 3: result = (char*)elem + 0xe; break;
            case 4: result = (char*)elem + 0x4; break;
            case 5: result = (char*)elem + 0x6; break;
            case 6: result = (char*)elem + 0x8; break;
            case 7: result = (char*)elem + 0xa; break;
            case 8: result = (char*)elem + 0xc; break;
            case 9: result = (char*)elem + 0xe; break;
        }
    }
    return result;
}
