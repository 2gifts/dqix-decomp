#include <globaldefs.h>

extern "C" ARM void* __clear(void* dst, int count);

struct List02160094;
struct ListNode02160094;
ListNode02160094* GetNodeAtIndex02160094(List02160094* list, int index);

struct List021600f8;
struct ListNode021600f8;
ListNode021600f8* GetNodeAtIndex021600f8(List021600f8* list, int index);

extern "C" void func_ov025_021d8c30(void* sl, void* sb, int kind, int category, int idx, int inner, int flag);

// USA: func_ov025_021d8ab8  (semantic: DispatchListEntries_021d8ab8)
extern "C" ARM void func_ov025_021d8ab8(void* sl, void* sb, int kind, int category, int idx) {
    int buf[6];
    __clear(buf, 0x18);
    int* p = buf;

    if (kind == 0) {
        ListNode02160094* node = GetNodeAtIndex02160094((List02160094*)sb, idx);
        if (node) {
            unsigned char* n = (unsigned char*)node;
            p[0] = n[0x26];
            p[1] = n[0x28];
            p[2] = n[0x29];
            p[3] = n[0x2b];
            p[4] = n[0x2a];
            p[5] = n[0x27];
        }
    } else if ((unsigned int)(kind - 1) <= 2) {
        ListNode021600f8* node = GetNodeAtIndex021600f8((List021600f8*)sb, idx);
        if (node) {
            unsigned char* n = (unsigned char*)node;
            p[0] = n[0x18];
            p[1] = n[0x19];
            p[2] = n[0x1a];
        }
    }

    int outer;
    if (category == 6) {
        for (outer = 0; outer < 6; outer++) {
            for (int inner = 0; inner < p[outer]; inner++) {
                func_ov025_021d8c30(sl, sb, kind, outer, idx, inner, 0);
            }
        }
    } else {
        for (int inner = 0; inner < p[category]; inner++) {
            func_ov025_021d8c30(sl, sb, kind, category, idx, inner, 0);
        }
    }
}
