#include <globaldefs.h>

struct SearchStruct0202c1a4;
signed char GetSearchStructCurrentArrEntry(SearchStruct0202c1a4* obj);
int CheckField0NonZero(int* obj);
int UpdatePlayClocks020ac4f8(int commit);
int* GetGlobal02109030(void);
extern "C" void func_02094030(int* g, short h4, short h6, signed char b8);
extern "C" void func_ov017_021d1118(int a, int b, int c, int d);

struct Node_021d1078 {
    char pad0[4];
    unsigned char value : 7;
    unsigned char highFlag : 1;
    unsigned char field5;
};

// USA: func_ov017_021d1078  (semantic: DispatchTableEntry_021d1078)
extern "C" ARM void func_ov017_021d1078(int id, Node_021d1078* node, void* unused0, void* unused1, void* searchObj) {
    signed char cur = GetSearchStructCurrentArrEntry((SearchStruct0202c1a4*)searchObj);
    if (!node->highFlag) {
        if (cur != node->value) return;
        UpdatePlayClocks020ac4f8(CheckField0NonZero((int*)searchObj) != 0);
        func_ov017_021d1118(id, 0xff, 0, 0);
        func_02094030(GetGlobal02109030(), 0x4e20, -1, id);
        return;
    }
    unsigned char flags = 1;
    if (node->field5 == 1) flags |= 4;
    func_ov017_021d1118(id, flags, 1, node->field5);
}
