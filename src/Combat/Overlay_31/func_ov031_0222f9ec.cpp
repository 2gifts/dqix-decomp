#include <globaldefs.h>

struct BattleList0222f9ec { char pad_0[8]; unsigned short* entries; char pad_c[8]; void* display; };
struct BattleListState0222f9ec { char pad_0[4]; unsigned short position; char pad_6[2]; BattleList0222f9ec* list; };
extern BattleListState0222f9ec data_ov031_02290ca0;
extern unsigned short data_ov031_02248f96[];
extern "C" int FastIntDivide(int, int);
extern "C" void CallVTableField14_0223ca40(void*, int);
extern "C" void func_ov031_0222faac(int, int);
extern "C" void func_ov031_02234f4c(unsigned short*, int, int, int);
extern "C" void func_ov031_0222fc48(int, int);
void SetField604_02234f34();
void SetFlagIfMatchesElem0_0223caec(void*);
extern "C" void func_ov031_02230120();

// USA: func_ov031_0222f9ec
extern "C" ARM void func_ov031_0222f9ec() {
    int first = FastIntDivide(data_ov031_02290ca0.position, 0x1d);
    CallVTableField14_0223ca40(data_ov031_02290ca0.list->display, 0);
    int entry = first;
    int row = 0;
    do {
        func_ov031_0222faac(entry, row);
        ++row;
        ++entry;
    } while (row < 5);
    func_ov031_02234f4c(data_ov031_02290ca0.list->entries + data_ov031_02248f96[first], 0, 0x1e, 0x13);
    int nextRow = 0;
    do {
        func_ov031_0222fc48(first, nextRow);
        ++nextRow;
        ++first;
    } while (nextRow < 5);
    SetField604_02234f34();
    SetFlagIfMatchesElem0_0223caec(data_ov031_02290ca0.list->display);
    func_ov031_02230120();
}
