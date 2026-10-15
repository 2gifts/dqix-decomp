#include <globaldefs.h>

struct Vec3Int0203a48c {
    int x;
    int y;
    int z;
};

struct PopupEntry0203a48c {
    unsigned short id;
    unsigned short field2;
    unsigned char field4;
    unsigned char field5;
    unsigned char digitCount;
    unsigned char field7;
    unsigned short field8;
    unsigned short fieldA;
    int x;
    int y;
    int z;
};

struct Obj0203a48c {
    char pad0[0x550];
    struct PopupEntry0203a48c entries[16];
    char pad6d0[4];
    int count;
};

// USA: func_0203a48c
ARM void QueuePopupEntry0203a48c(Obj0203a48c* obj, int id, Vec3Int0203a48c* pos, int field7, int field4, int field2) {
    int value;
    int digitCount;
    struct PopupEntry0203a48c* entry;

    value = id;
    digitCount = 0;
    while (value > 0) {
        value = value / 10;
        digitCount++;
    }
    if (digitCount == 0) {
        return;
    }

    entry = &obj->entries[obj->count];
    entry->field5 = 0x25;
    entry->id = id;
    entry->x = pos->x;
    entry->y = pos->y;
    entry->z = pos->z;
    entry->field4 = field4;
    entry->field2 = field2;
    entry->digitCount = digitCount;
    entry->field8 = 0x358 - 0x25;
    entry->fieldA = 0x1333;
    entry->field7 = field7;

    obj->count = obj->count + 1;
    if (obj->count >= 0x10) {
        obj->count = 0;
    }
}
