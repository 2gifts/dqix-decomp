#include <globaldefs.h>

struct FindRowByIdRow { unsigned short id; char pad[0x4a]; };

struct KeyField021b8a34 { unsigned int keyLow : 12; unsigned int keyHigh : 20; };
struct WeightField021b8a34 { unsigned short value : 8; unsigned short chance : 8; };

int GetBTRandom(void);
FindRowByIdRow* FindRowById_0209b9e4(FindRowByIdRow* base, int key);
extern "C" int func_02032370(int max);

// USA: func_ov017_021b8a34
ARM int PickWeightedSubEntry_021b8a34(FindRowByIdRow* table, int id, int key12) {
    GetBTRandom();
    FindRowByIdRow* row = FindRowById_0209b9e4(table, id);
    if (row != NULL) {
        int i;
        for (i = 0; i < *(unsigned char*)((char*)row + 2); i++) {
            struct KeyField021b8a34* keyField = (struct KeyField021b8a34*)((char*)row + (i << 3) + 4);
            if (key12 == (int)keyField->keyLow) {
                struct WeightField021b8a34* weight = (struct WeightField021b8a34*)((char*)row + 8 + (i << 3));
                int roll = func_02032370(0x64);
                if (roll < weight->chance) {
                    return weight->value;
                }
                break;
            }
        }
    }
    return -1;
}
