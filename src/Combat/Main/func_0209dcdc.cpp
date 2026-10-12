#include <globaldefs.h>
#include "std_library_functions.h"

struct ConditionRatings0209dcdc {
    signed int category0:3;
    signed int category1:3;
    signed int category2:3;
    signed int category3:3;
    signed int category4:3;
    signed int category5:3;
    signed int category6:3;
    signed int category7:3;
    signed int category8:3;
    signed int category9:3;
    unsigned int padding:2;
};
struct ConditionStyle0209dcdc {
    unsigned short style:2;
    unsigned short padding:14;
};
struct ConditionCategory0209dcdc {
    unsigned char padding:4;
    unsigned char category:4;
};
struct ConditionRecord0209dcdc {
    unsigned long long capabilities[2];
    unsigned char padding10[8];
    ConditionStyle0209dcdc styles[2];
    ConditionCategory0209dcdc categories[2];
    unsigned char padding1e[0xa];
    ConditionRatings0209dcdc ratings[2];
};

// USA: func_0209dcdc
extern "C" ARM int func_0209dcdc(void* manager, ConditionRecord0209dcdc* record, int alternate, unsigned int requested) {
    unsigned int category;
    unsigned int capabilities;
    unsigned int upperCapabilities;
    unsigned int style;
    ConditionRatings0209dcdc ratings;
    if (alternate == 0) {
        style = record->styles[0].style;
        category = record->categories[0].category;
        unsigned long long flags = record->capabilities[0];
        capabilities = flags;
        upperCapabilities = flags >> 32;
        memcpy(&ratings, &record->ratings[0], sizeof(ratings));
    } else {
        style = record->styles[1].style;
        category = record->categories[1].category;
        unsigned long long flags = record->capabilities[1];
        capabilities = flags;
        upperCapabilities = flags >> 32;
        memcpy(&ratings, &record->ratings[1], sizeof(ratings));
    }
    if ((requested & 0x1) && (capabilities & 2) && style == 1) return 1;
    if ((requested & 0x2) && (capabilities & 2) && style == 2) return 1;
    if ((requested & 0x4) && (capabilities & 0x400) && ratings.category0 == 2) return 1;
    if ((requested & 0x8) && (capabilities & 0x400) && ratings.category0 == 1) return 1;
    if ((requested & 0x10) && (capabilities & 0x400) && ratings.category0 == -1) return 1;
    if ((requested & 0x20) && (capabilities & 0x400) && ratings.category0 == -2) return 1;
    if ((requested & 0x40) && (capabilities & 0x800) && ratings.category1 == 2) return 1;
    if ((requested & 0x80) && (capabilities & 0x800) && ratings.category1 == 1) return 1;
    if ((requested & 0x100) && (capabilities & 0x800) && ratings.category1 == -1) return 1;
    if ((requested & 0x200) && (capabilities & 0x800) && ratings.category1 == -2) return 1;
    if ((requested & 0x400) && (capabilities & 0x1000) && ratings.category2 == 2) return 1;
    if ((requested & 0x800) && (capabilities & 0x1000) && ratings.category2 == 1) return 1;
    if ((requested & 0x1000) && (capabilities & 0x1000) && ratings.category2 == -1) return 1;
    if ((requested & 0x2000) && (capabilities & 0x1000) && ratings.category2 == -2) return 1;
    if ((requested & 0x4000) && (capabilities & 0x2000) && ratings.category3 == 1) return 1;
    if ((requested & 0x8000) && (capabilities & 0x4000) && ratings.category4 == 2) return 1;
    if ((requested & 0x10000) && (capabilities & 0x4000) && ratings.category4 == 1) return 1;
    if ((requested & 0x20000) && (capabilities & 0x8000) && ratings.category5 == 2) return 1;
    if ((requested & 0x40000) && (capabilities & 0x8000) && ratings.category5 == 1) return 1;
    if ((requested & 0x80000) && (capabilities & 0x10000) && ratings.category6 == 2) return 1;
    if ((requested & 0x100000) && (capabilities & 0x10000) && ratings.category6 == 1) return 1;
    if ((requested & 0x200000) && (capabilities & 0x10000) && ratings.category6 == -1) return 1;
    if ((requested & 0x400000) && (capabilities & 0x10000) && ratings.category6 == -2) return 1;
    if ((requested & 0x800000) && (capabilities & 0x20000) && ratings.category7 == 2) return 1;
    if ((requested & 0x1000000) && (capabilities & 0x20000) && ratings.category7 == 1) return 1;
    if ((requested & 0x2000000) && (upperCapabilities & 1) && ratings.category8 == 2) return 1;
    if ((requested & 0x4000000) && (capabilities & 0x2000000) && ratings.category9 == 2) return 1;
    if ((requested & 0x8000000) && (capabilities & 0x800000) && category == 1) return 1;
    if ((requested & 0x10000000) && (capabilities & 0x800000) && category == 2) return 1;
    if ((requested & 0x20000000) && (capabilities & 0x800000) && category == 3) return 1;
    return 0;
}
