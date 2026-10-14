#include <globaldefs.h>

struct PackedNibbleArray0206e120;
int GetPackedNibbleField(struct PackedNibbleArray0206e120* obj, int index);

// USA: func_02095ae0
ARM int IsNibbleFieldZeroOrOne_02095ae0(struct PackedNibbleArray0206e120* obj, int index) {
    int result = 1;
    int b = (GetPackedNibbleField(obj, index) == 0);
    if (!b) {
        b = (GetPackedNibbleField(obj, index) == 1);
        if (!b) {
            result = 0;
        }
    }
    return result;
}
