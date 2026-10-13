#include <globaldefs.h>

extern "C" int func_02032370(int upperBound);

struct WeightedEntry_02073fdc {
    unsigned short id : 12;
    unsigned short weight : 3;
    unsigned short flag : 1;
    unsigned short field2;
};
struct WeightedTable_02073fdc {
    unsigned short field0;
    unsigned short count;
    unsigned int field4;
    WeightedEntry_02073fdc entries[];
};
// KEEP-NAME
// USA: func_02073fdc
ARM int SelectWeightedEntry02073fdc(void* data) {
    WeightedTable_02073fdc* table = (WeightedTable_02073fdc*)data;
    int total = 0;
    for (int i = 0; i < table->count; ++i) {
        total += table->entries[i].weight;
    }
    int selected = func_02032370(total);
    int result = -1;
    int cumulative = 0;
    for (int j = 0; j < table->count; ++j) {
        cumulative += table->entries[j].weight;
        if (selected < cumulative) {
            result = table->entries[j].id;
            break;
        }
    }
    return result;
}
