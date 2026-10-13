#include <globaldefs.h>

struct Decimal02009dfc {
    unsigned short field_0;
    short exponent;
    unsigned char length;
    unsigned char digits[0x20];
};
struct DecimalLength02009dfc { unsigned char value; };
static inline int GetLength02009dfc(Decimal02009dfc* value) {
    return ((DecimalLength02009dfc*)&value->length)->value;
}
static inline unsigned char GetDigit02009dfc(Decimal02009dfc* value, int index) {
    Decimal02009dfc* window = (Decimal02009dfc*)((unsigned char*)value + index);
    return window->digits[0];
}

// USA: func_02009dfc
extern "C" ARM int func_02009dfc(Decimal02009dfc* first, Decimal02009dfc* second) {
    if (!first->digits[0]) return second->digits[0] != 0;
    if (!second->digits[0]) return 0;
    if (first->exponent == second->exponent) {
        int index;
        int common;
        int secondLength;
        int firstLength;
        firstLength = first->length;
        secondLength = second->length;
        index = 0;
        common = firstLength;
        if (firstLength > secondLength) common = secondLength;
        if (common > 0) {
            do {
                if (GetDigit02009dfc(first, index) < GetDigit02009dfc(second, index)) return 1;
                if (GetDigit02009dfc(second, index) < GetDigit02009dfc(first, index)) return 0;
                ++index;
            } while (index < common);
        }
        if (common == firstLength && index < secondLength) {
            do {
                if (second->digits[index]) return 1;
                ++index;
            } while (index < GetLength02009dfc(second));
        }
        return 0;
    }
    return first->exponent < second->exponent;
}
