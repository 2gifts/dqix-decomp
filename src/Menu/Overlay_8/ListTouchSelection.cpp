#if defined(jpn)
#define R(j,u) (j)
#define data_ov008_0218b490 data_ov008_0218c0f1
#define data_ov014_021896d4 data_ov014_0218a4e4
#define data_ov014_0218981c data_ov014_0218a5fc
#define data_ov015_02193d20 data_ov015_02194850
#define data_ov015_02193fe0 data_ov015_02194b20
#define data_ov015_02194052 data_ov015_02194b92
#define data_ov015_02194078 data_ov015_02194bb8
#define data_ov015_0219415c data_ov015_02194c9c
#define data_ov015_02194160 data_ov015_02194ca0
#define data_ov015_02194167 data_ov015_02194ca7
#define func_ov008_02184968 func_ov008_02185a64
#define func_ov008_021895a8 func_ov008_0218a2b0
#define func_ov008_02189c70 func_ov008_0218a930
#define func_ov008_0218aee4 func_ov008_0218bb50
#define func_ov014_021886f8 func_ov014_021895c8
#else
#define R(j,u) (u)
#endif
#include "World/Object3D.h"

struct Overlay8ListTouchView {
    unsigned char unknown000[0x74c];
    unsigned char count;
    unsigned char unknown74d[3];
    unsigned char cursor[0x40];
    Object3D object;
    unsigned char unknown83c[0xb10 - 0x83c];
    signed char phase;
    unsigned char unknownb11[7];
    unsigned int flags;
    unsigned char unknownb1c[0xb29 - 0xb1c];
    unsigned char page;
};

extern char data_02108760[];
extern char data_ov008_0218b490[];
extern "C" {
    int _Z18GetField0_0205bafcPv(void*);
    int _Z24ComputeScaledSum0205bb84P15Struct_0205bb84(void*);
    void func_0205bb04(void*, int);
    void _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(void*, int, int);

    int func_ov008_02186b18(Overlay8ListTouchView* menu, int touchX, int touchY) {
        if (!touchX || !touchY)
            return -1;
        int count = _Z18GetField0_0205bafcPv(menu->cursor);
        if (count > 6)
            count = 6;
        for (int i = 0; i < count; ++i) {
            int y = (i << 4) + 8;
            int maxY = y + 16;
            if (touchY > y && touchY < maxY && touchX > 16 && touchX < R(136, 152))
                return i + menu->page;
        }

        if ((menu->flags & 0x10) && menu->phase != 12 && touchX >= 70 && touchX < 82) {
            int page = menu->page;
            if (page != 0 && touchY >= 0 && touchY < 8) {
                menu->page = page - 1;
                int index = menu->page + 5;
                if (_Z24ComputeScaledSum0205bb84P15Struct_0205bb84(menu->cursor) > index)
                    func_0205bb04(menu->cursor, index);
                return -1;
            }
            if ((unsigned int)page < 2 && touchY >= 104 && touchY < 112) {
                if (page + 6 < menu->count)
                    ++menu->page;
                int index = menu->page;
                if (_Z24ComputeScaledSum0205bb84P15Struct_0205bb84(menu->cursor) < index)
                    func_0205bb04(menu->cursor, index);
                return -1;
            }
        }

        if (touchY > 96 && touchY < 106 && touchX > R(207, 199) && touchX < 242)
            return -2;

        if (!(menu->flags & 0x80) && touchY > 16 && touchY < 96 && touchX > 176 && touchX < 208 && !(menu->flags & 0x4000)) {
            _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(data_02108760, 0x5e, 0);
            menu->object.MaybeSetRegularAnimation(data_ov008_0218b490, 0);
            menu->flags |= 0x4000;
        }
        return -1;
    }
}
