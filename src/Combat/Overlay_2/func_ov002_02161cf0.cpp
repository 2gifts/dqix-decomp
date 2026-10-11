#include "GameState/GameState.h"
#include <globaldefs.h>

struct Struct_0205ba68;
struct Node0205bacc;
struct Struct_0205bcdc;
struct Struct0205cf1c;
extern "C" void _Z23SetChannelAFlag0205cef8Pv(void *p);
extern "C" void _Z23SetChannelBFlag0205cf04Pv(void *p);
extern "C" void _Z25ClearChannelAFlag0205cf10Pv(void *p);
extern "C" void _Z21ClearFlagByte0205cf1cP14Struct0205cf1c(struct Struct0205cf1c *p);
int ReadBattleField0x64f4Byte();
extern "C" int _Z22GetCountByType02157108Pvi(void *base, int id);
extern "C" void _Z25SetupPointerTable0205ba68P15Struct_0205ba68iii(struct Struct_0205ba68 *p, int a, int b, int c);
extern "C" void _Z29SetField0AndPropagate0205baccP12Node0205bacci(struct Node0205bacc *p, int v);
extern "C" void _Z23SetIndexIfValid0205bcdcP15Struct_0205bcdci(struct Struct_0205bcdc *p, int v);
extern "C" void func_0205bb04(void *p, int v);
extern "C" int func_020dc428();
extern "C" void func_ov002_02156080(void *self, short *out, short *outCount);

// USA: func_ov002_02161cf0
extern "C" ARM void func_ov002_02161cf0(char *base) {
    int cols;
    int rows;
    int total;
    int pages;
    int cursor;
    char *list = base + 0x2c8 + 0xc00;
    int flag;
    GameState::GetInstance();
    flag = 0;
    _Z23SetChannelAFlag0205cef8Pv(base + 0x2c8 + 0xc00);
    _Z23SetChannelBFlag0205cf04Pv(base + 0x2c8 + 0xc00);
    switch (*(int *) (base + 0x1000 + 0xbb8)) {
        case 1:
            cursor = *(short *) (base + 0x1b00 + 0xe0);
            cols   = 2;
            rows   = 3;
            total  = 6;
            pages  = 1;
            break;
        case 2:
            total  = *(signed char *) (base + 0x1c00 + 0x73);
            cols   = 1;
            rows   = total;
            pages  = 1;
            cursor = *(short *) (base + 0x1b00 + 0xe2);
            break;
        case 3:
            pages  = 1;
            total  = 3;
            cols   = 1;
            rows   = 3;
            cursor = *(short *) (base + 0x1b00 + 0xe4);
            GameState::GetInstance();
            if (ReadBattleField0x64f4Byte() == 0) {
                total = 2;
                rows  = 2;
            }
            break;
        case 4:
            total = *(signed char *) (base + 0x1c00 + 0x73) + 2;
            pages = 1;
            rows  = total;
            cols  = pages;
            if (*(unsigned char *) (base + 0x2000 + 0x485)) rows = total - 1;
            cursor = *(short *) (base + 0x1b00 + 0xe6);
            break;
        case 5:
        case 10:
            if (*(short *) (base + 0x1b00 + 0xe6) >= 0) {
                *(signed char *) (base + 0x1000 + 0xc20) =
                    *(signed char *) (base + *(short *) (base + 0x1b00 + 0xe6) + 0x1c00 + 0x6e);
                if (*(short *) (base + 0x1b00 + 0xe6) == *(signed char *) (base + 0x1c00 + 0x73))
                    *(signed char *) (base + 0x1000 + 0xc20) = 4;
                if (*(short *) (base + 0x1b00 + 0xe6) == *(signed char *) (base + 0x1c00 + 0x73) + 1)
                    *(signed char *) (base + 0x1000 + 0xc20) = -1;
            }
            cols  = 1;
            rows  = 8;
            total = _Z22GetCountByType02157108Pvi(base, *(signed char *) (base + 0x1c00 + 0x20));
            pages = (total + 7) / 8;
            if (total < 8) rows = total;
            if (total <= *(short *) (base + 0x1b00 + 0xe8)) *(short *) (base + 0x1b00 + 0xe8) = total - 1;
            cursor = *(short *) (base + 0x1b00 + 0xe8);
            break;
        case 6:
            pages  = 1;
            total  = 4;
            cols   = 1;
            rows   = 4;
            cursor = *(short *) (base + 0x1b00 + 0xea);
            break;
        case 7:
            pages = 1;
            cols  = 1;
            if (*(unsigned char *) (base + 0x1000 + 0xc84) == 7)
                total = *(signed char *) (base + 0x1c00 + 0x73);
            else
                total = *(unsigned char *) (base + 0x1000 + 0xc6d);
            cursor = *(short *) (base + 0x1b00 + 0xec);
            rows   = total;
            break;
        case 9:
            total  = *(unsigned char *) (base + 0x1000 + 0xc6d) + 1;
            pages  = 1;
            cols   = 1;
            rows   = total;
            cursor = *(short *) (base + 0x1b00 + 0xee);
            break;
        case 11:
            total  = *(int *) (base + 0x1000 + 0xc38) + 1;
            pages  = 1;
            cols   = 1;
            rows   = total;
            cursor = *(short *) (base + 0x1b00 + 0xf0);
            break;
        case 12:
            pages  = 1;
            total  = 2;
            cols   = 1;
            rows   = 2;
            cursor = *(short *) (base + 0x1b00 + 0xf2);
            break;
        case 13:
            cols  = 1;
            rows  = 8;
            total = _Z22GetCountByType02157108Pvi(base, *(signed char *) (base + 0x1c00 + 0x21)) + 1;
            pages = 1;
            if (total > 8) total = 8;
            if (total < 8) rows = total;
            cursor = *(short *) (base + 0x1b00 + 0xf4);
            break;
        case 14: {
            signed char n = func_020dc428();
            total         = n + 1;
            if (*(short *) (base + 0x1b00 + 0xf6) > n) *(short *) (base + 0x1b00 + 0xf6) = n;
            cols  = 1;
            rows  = total;
            pages = 1;
            if (*(short *) (base + 0x1b00 + 0xf6) < 0) *(short *) (base + 0x1b00 + 0xf6) = 0;
            cursor = *(short *) (base + 0x1b00 + 0xf6);
            break;
        }
        case 16:
            total  = *(signed char *) (base + 0x1c00 + 0x73);
            cols   = 1;
            rows   = total;
            pages  = 1;
            cursor = *(short *) (base + 0x1b00 + 0xf8);
            break;
        case 17:
            total = *(unsigned char *) (base + 0x2000 + 0x520);
            rows  = 8;
            cols  = 1;
            pages = (total + 7) / 8;
            if (total < 8) rows = total;
            cursor = *(short *) (base + 0x1b00 + 0xfa);
            break;
        case 20: {
            char *p = *(char **) (base + 0x2000 + 0x474);
            if (p != NULL) {
                total = *(unsigned short *) (p + 0xc);
                rows  = 6;
                cols  = 1;
                if (total < 6) rows = total;
                cursor = *(short *) (base + 0x1b00 + 0xfc);
                pages  = (total - 1) / 6 + 1;
            } else {
                cols   = flag;
                rows   = cols;
                total  = cols;
                cursor = cols;
                pages  = cols;
            }
            break;
        }
        case 21: {
            short count = 0;
            short items[9];
            func_ov002_02156080(base, items, &count);
            total  = count;
            cols   = 1;
            rows   = total;
            pages  = 1;
            cursor = *(short *) (base + 0x1b00 + 0xfe);
            break;
        }
        case 23: break;
        case 24:
            cursor = *(short *) (base + 0x1c00 + 0x2);
            cols   = 3;
            rows   = *(signed char *) (base + 0x1c00 + 0x73) + 1;
            total  = rows * 3;
            pages  = 1;
            break;
        case 25:
            pages  = 1;
            total  = 6;
            cols   = 1;
            rows   = 6;
            cursor = *(short *) (base + 0x1c00 + 0x4);
            break;
        case 28:
            rows   = 4;
            pages  = 1;
            cols   = 4;
            flag   = 1;
            cursor = *(short *) (base + 0x1c00 + 0x6);
            total  = 0x10;
            break;
        case 31:
            total  = *(signed char *) (base + 0x1c00 + 0x73);
            pages  = 1;
            cols   = 1;
            rows   = total;
            cursor = *(short *) (base + 0x1c00 + 0x8);
            break;
        case 33:
            pages  = 1;
            total  = 8;
            cols   = 1;
            rows   = 8;
            cursor = *(short *) (base + 0x1c00 + 0xa);
            break;
        case 34:
            cols   = 2;
            pages  = 2;
            cursor = *(short *) (base + 0x1c00 + 0xc);
            rows   = 8;
            total  = 0x20;
            flag   = 1;
            break;
        case 35:
            pages  = 1;
            total  = 3;
            cols   = 1;
            rows   = 3;
            cursor = *(short *) (base + 0x1c00 + 0xe);
            break;
        case 36:
            pages  = 1;
            total  = 2;
            cols   = 1;
            rows   = 2;
            cursor = *(short *) (base + 0x1c00 + 0x10);
            break;
        case 37:
            pages  = 1;
            total  = 2;
            cols   = 1;
            rows   = 2;
            cursor = *(short *) (base + 0x1c00 + 0x12);
            break;
        case 39:
            pages  = 1;
            total  = 2;
            cols   = 1;
            rows   = 2;
            cursor = *(short *) (base + 0x1c00 + 0x14);
            break;
        default:
            _Z25ClearChannelAFlag0205cf10Pv(base + 0x2c8 + 0xc00);
            _Z21ClearFlagByte0205cf1cP14Struct0205cf1c((struct Struct0205cf1c *) (base + 0x2c8 + 0xc00));
            return;
    }
    _Z25SetupPointerTable0205ba68P15Struct_0205ba68iii((struct Struct_0205ba68 *) (list + 4), cols, rows, flag);
    _Z25SetupPointerTable0205ba68P15Struct_0205ba68iii((struct Struct_0205ba68 *) (list + 0x54), cols, rows, flag);
    _Z29SetField0AndPropagate0205baccP12Node0205bacci((struct Node0205bacc *) (list + 4), total);
    _Z29SetField0AndPropagate0205baccP12Node0205bacci((struct Node0205bacc *) (list + 0x54), total);
    *(int *) (list + 8)    = pages;
    *(int *) (list + 0x58) = pages;
    _Z23SetIndexIfValid0205bcdcP15Struct_0205bcdci((struct Struct_0205bcdc *) (list + 4), cursor);
    func_0205bb04(list + 0x54, cursor);
    *(unsigned int *) (base + 0x2000 + 0x47c) &= ~4;
}
