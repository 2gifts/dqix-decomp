#include <globaldefs.h>

struct PackedNibbleArray0206e120;
struct PackedNibbleArray0206e260;
extern "C" int _Z29CheckFlagAndThreshold0206e31cii(int, int);
int GetPackedNibbleField(PackedNibbleArray0206e120*, int);
int GetPackedNibbleFlag0x4(PackedNibbleArray0206e260*, int);

// USA: func_0206474c
extern "C" ARM int func_0206474c(PackedNibbleArray0206e120* data, int index, int mode) {
    if (!_Z29CheckFlagAndThreshold0206e31cii((int)data, index)) return 0;
    switch (mode) {
    case -1: return GetPackedNibbleField(data, index) == 0;
    case 0: return GetPackedNibbleField(data, index) == 2;
    case 1: return GetPackedNibbleFlag0x4((PackedNibbleArray0206e260*)data, index);
    case 2: return GetPackedNibbleField(data, index) == 3;
    case 3: return GetPackedNibbleField(data, index) == 1;
    case 5: return GetPackedNibbleField(data, index) == 0;
    default: return 0;
    }
}
