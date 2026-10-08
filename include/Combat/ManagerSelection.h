#pragma once

struct SelectionRecord {
    unsigned int flags;
    unsigned char unknown4[4];
    unsigned int flags8;
    unsigned int flagsC;
    unsigned char unknown10[2];
    short value12;
    unsigned short value14;
    unsigned char unknown16[8];
    unsigned char flags1e;
    unsigned char state1f;
    unsigned char unknown20[0x10];
    short values30[8];
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
