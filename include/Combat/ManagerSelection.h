#pragma once

struct SelectionRecord {
    unsigned int flags;
    unsigned char unknown4[0x10];
    unsigned short value14;
    unsigned char unknown16[8];
    unsigned char flags1e;
    unsigned char state1f;
    unsigned char unknown20[0x20];
};

struct SelectionList {
    int count;
    SelectionRecord records[16];
};

struct ManagerSelectionPrefix {
    unsigned char unknown0[4];
    unsigned char *source;
    unsigned char unknown8[0x90];
    SelectionList kept;
    SelectionList scratch;
};
