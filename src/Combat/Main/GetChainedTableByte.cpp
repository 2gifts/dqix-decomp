#include <globaldefs.h>

struct ChainEntryB {
    char unk0[8];
    int index;
};

struct ChainEntryA {
    int unk0;
    struct ChainEntryB* entries;
};

struct ChainRoot {
    char unk0[8];
    unsigned char* byteTable;
    struct ChainEntryA* tableA;
    char unk10[0x60];
    int indexB;
    int indexA;
    char unk78[0xc];
    unsigned char flag : 1;
};

// USA: func_020479fc
ARM int GetChainedTableByte_020479fc(struct ChainRoot* root) {
    struct ChainEntryB* entryB;
    if (!root->flag) {
        return 0;
    }
    entryB = &root->tableA[root->indexA].entries[root->indexB];
    return root->byteTable[entryB->index * 8];
}
