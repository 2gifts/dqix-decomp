#include <globaldefs.h>

struct ScaledElementList0204aa28 {
    unsigned int baseOffset;
    short firstTile;
    char unknown6[4];
    unsigned char uses64ByteTiles;
};

// USA: func_0204aa28
ARM unsigned int GetScaledElementPtr(struct ScaledElementList0204aa28* layout) {
    int tileShift = 5;
    if (layout->uses64ByteTiles) {
        tileShift = 6;
    }
    return layout->baseOffset + (layout->firstTile << tileShift);
}
