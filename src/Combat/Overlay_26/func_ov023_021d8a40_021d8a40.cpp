#include <globaldefs.h>

void* GetData02100044_0202ae24(void);
int CheckSlotsAllFree0205e488(void* obj);
extern "C" int func_0205e4f8(void* obj, int id);

// USA: func_ov026_021d8a40  (semantic: func_ov023_021d8a40)  (semantic: IsSlotId99Absent_021d8a40)
extern "C" ARM int func_ov026_021d8a40(void) {
    void* data = GetData02100044_0202ae24();
    if (CheckSlotsAllFree0205e488(data) != 0) return 1;
    return func_0205e4f8(data, 0x63) == 0;
}
