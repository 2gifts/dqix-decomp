#include <globaldefs.h>

extern void* GetData02153637_020e2ff8(void);

struct Container020e34bc;
int GetEntryStatusForKey020e34bc(struct Container020e34bc* obj, int key);

struct Entry020e3054;
void ClearEntryIfCurrentArrMatches020e3468(struct Entry020e3054* list, int key);

// USA: func_ov002_0215b7d0
ARM int CheckAndClearEntryStatus_0215b7d0(char* base) {
    void* obj = GetData02153637_020e2ff8();
    int status = GetEntryStatusForKey020e34bc((struct Container020e34bc*)obj, 1);
    if (status == 1) {
        return 1;
    }
    if ((unsigned int)(status - 3) > 2) {
        return 0;
    }
    ClearEntryIfCurrentArrMatches020e3468((struct Entry020e3054*)obj, 1);
    return -1;
}
