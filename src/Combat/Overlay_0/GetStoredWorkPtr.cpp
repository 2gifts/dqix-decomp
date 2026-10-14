#include <globaldefs.h>

struct WorkPtrHolder02184288 {
    int unk0;
    void* ptr;
    int unk8;
};
extern struct WorkPtrHolder02184288 data_ov000_02184288;

// USA: func_ov000_02174504
ARM void* GetStoredWorkPtr_ov000_02174504(void) {
    return data_ov000_02184288.ptr;
}
