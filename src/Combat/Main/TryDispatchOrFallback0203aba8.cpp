#include <globaldefs.h>

void* SetGlobalContext02110370(void* value);
int LookupRecordAndDispatch020be760(void* a, void* key);

struct Obj0203aba8 {
    void* field0;
};

// USA: func_0203aba8
ARM int TryDispatchOrFallback0203aba8(struct Obj0203aba8* obj, void* key, void* target) {
    int found;
    if (obj->field0 == 0) {
        return 0;
    }
    SetGlobalContext02110370((char*)obj + 4);
    found = 1;
    if (target != 0) {
        if (LookupRecordAndDispatch020be760(target, key) == 0) {
            found = 0;
        }
    } else {
        if (LookupRecordAndDispatch020be760((char*)obj + 0x98, key) == 0) {
            found = 0;
        }
    }
    return found != 0;
}

// JPN: 0x0203a600
