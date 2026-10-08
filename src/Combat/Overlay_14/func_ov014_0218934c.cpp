#include <globaldefs.h>

struct NatEntry {
    unsigned short key_;
    unsigned short groupIndex_ : 12;
    unsigned short numGroups_ : 4;
};

struct NatGroup {
    unsigned short pointerIndex_;
    unsigned short flag_ : 1;
    unsigned short firstIndex_ : 11;
    unsigned short numIndices_ : 4;
};

struct NatTable {
    unsigned short numEntries_;
    unsigned short numGroups_;
    unsigned short numIndices_;
    unsigned short numPointers_;
    unsigned int dataSize_ : 31;
    unsigned int relocated_ : 1;
    NatEntry* entries_;
    char* data_;
};

static inline unsigned int AlignTo4(unsigned int size) {
    return (size + 3) & ~3;
}

// USA: func_ov014_0218934c
extern "C" ARM unsigned int func_ov014_0218934c(NatTable* self) {
    unsigned int entriesSize = self->numEntries_ * sizeof(NatEntry);
    unsigned int size = self->numGroups_ * sizeof(NatGroup) + self->numIndices_ * sizeof(unsigned short) + entriesSize;
    return AlignTo4(size) - entriesSize + self->numPointers_ * sizeof(char*) + entriesSize;
}
