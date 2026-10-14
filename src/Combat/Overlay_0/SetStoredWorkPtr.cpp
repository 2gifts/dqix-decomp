#include <globaldefs.h>

struct WorkPtrHolder02184288 {
    int unk0;
    void* ptr;
    int unk8;
};
extern struct WorkPtrHolder02184288 data_ov000_02184288;

// USA: func_ov000_021744f4
ARM void SetStoredWorkPtr_ov000_021744f4(int unused, void* val) {
    data_ov000_02184288.ptr = val;
}
