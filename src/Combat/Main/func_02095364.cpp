#include <globaldefs.h>
#include "Resource/Script.h"

struct ScriptTableState02095364 {
    unsigned char field_0;
    unsigned char skip;
    unsigned char selected;
    unsigned char pad_3[3];
    unsigned short index;
};
struct ScriptTableEntry02095364 {
    unsigned short id : 9;
    unsigned short bit9 : 1;
    unsigned short bit10 : 1;
    unsigned short bit11 : 1;
    unsigned short bit12 : 1;
    unsigned short rest : 3;
};
struct ScriptTableOwner02095364 {
    char pad_0[0xa8];
    ScriptTableEntry02095364* entries;
};
extern ScriptTableState02095364 data_02109404 __attribute__((aligned(4)));
extern ScriptTableOwner02095364 data_02109418;
extern short data_020f13d8;

// USA: func_02095364
extern "C" ARM int func_02095364(Script::Parameter* params) {
    if (data_02109404.skip != 0) {
        data_02109404.index++;
        return 1;
    }
    unsigned short id = params[0].ToInt();
    unsigned short bit9 = params[5].ToInt();
    unsigned short bit11 = params[7].ToInt();
    unsigned short bit10 = params[8].ToInt();
    unsigned short bit12 = params[9].ToInt();
    ScriptTableEntry02095364* table = data_02109418.entries;
    if (table != 0) {
        int index = data_02109404.index;
        table[index].id = id;
        table[index].bit9 = bit9;
        table[index].bit11 = bit11;
        table[index].bit10 = bit10;
        table[index].bit12 = bit12;
    }
    int nextIndex = data_02109404.index + 1;
    int selection = data_020f13d8;
    data_02109404.index = nextIndex;
    if (selection >= 0 && id == selection)
        data_02109404.selected = bit10 != 0;
    return 1;
}
