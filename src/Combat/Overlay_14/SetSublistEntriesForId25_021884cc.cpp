#include <globaldefs.h>

struct StatusOwner02081164;

void SetEntryHalfword0xe_0208103c(void* obj, int id, int value);
void DispatchEntryOp0x8_0208108c(void* obj, int id);
void SetEntryFlag0x2ByShortId(struct StatusOwner02081164* obj, int id, int value);
void SetEntryLowNibbleAndElement02080c68(void* obj, int id, int value);
extern "C" void func_020813ec(void* obj, int key);

// USA: func_ov014_021884cc  (semantic: SetSublistEntriesForId25_021884cc)
extern "C" ARM void func_ov014_021884cc(void* self) {
    short v = *(short*)((char*)self + 0x172);
    short adj = v + 0x10;
    if (v == 9) {
        short v2 = *(short*)((char*)self + 0x174);
        if (v2 >= 0) {
            adj = v2 - 4;
        }
    }
    SetEntryHalfword0xe_0208103c(*(void**)((char*)self + 0xc0), 0x19, adj);
    DispatchEntryOp0x8_0208108c(*(void**)((char*)self + 0xc0), 0x19);
    SetEntryFlag0x2ByShortId(*(struct StatusOwner02081164**)((char*)self + 0xc0), 3, 1);
    SetEntryLowNibbleAndElement02080c68(*(void**)((char*)self + 0xc0), 3, 1);
    func_020813ec(*(void**)((char*)self + 0xc0), 3);
}
