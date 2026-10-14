#include <globaldefs.h>

struct Record_1f1b0 {
    short key;
    char unk[0xa];
};

struct Table_1f1b0 {
    struct Record_1f1b0* records;
    int count;
};

// USA: func_0201f1b0
ARM int FindRecordIndexByHalfwordKey_0201f1b0(struct Table_1f1b0* table, int key) {
    int i;
    for (i = 0; i < table->count; i++) {
        if (key == table->records[i].key) {
            return i;
        }
    }
    return -1;
}
