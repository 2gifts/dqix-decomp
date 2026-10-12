#include <globaldefs.h>

struct Table0222cb5c { unsigned char values[1]; };
extern const Table0222cb5c data_ov031_02248e2c;
struct Struct0222cb5c { unsigned char pad[4]; char* field4; };
extern Struct0222cb5c data_ov031_02290c8c;
extern "C" int func_ov031_02234ff8(int, int, int);

// USA: func_ov031_0222cb5c
ARM void ForwardByteAndPtr8_0222cb5c(void) {
    Table0222cb5c table = data_ov031_02248e2c;
    unsigned char v = table.values[0];
    int arg0 = *(int*)(data_ov031_02290c8c.field4 + 8);
    func_ov031_02234ff8(arg0, v, v);
}
