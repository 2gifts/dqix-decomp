#pragma once

struct Element_1f2a4 {
    char unk[0x20];
};

struct Manager_1f2a4 {
    char unk[0xc];
    struct Element_1f2a4 *elements;
    int count;
};

Element_1f2a4 *GetElementByIndexStride0x20(Manager_1f2a4 *manager, int index);
