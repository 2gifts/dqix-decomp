#include <globaldefs.h>

struct SubStruct {
    char unk[0x34];
    unsigned short field34;
    char unk36[0x2];
    unsigned short field38;
};

struct Holder {
    struct SubStruct* volatile ptr;
};

// USA: func_020bc1ec
ARM void SetSubFields0x34And0x38_020bc1ec(struct Holder* holder, int value) {
    if (holder->ptr != 0) {
        holder->ptr->field34 = 1;
        holder->ptr->field38 = value;
        return;
    }
}
