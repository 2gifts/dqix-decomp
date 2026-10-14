#include <globaldefs.h>

struct Struct_0205bd04;
int GetScaledSumIfActive0205bd04(struct Struct_0205bd04*);

struct Struct_0205bcdc;
void SetIndexIfValid0205bcdc(struct Struct_0205bcdc*, int);

struct Struct_0205bd78 {
    int field0;
    char pad4[0x1c];
    int* field20;
    int* field24;
    int* field28;
    int* field2c;
    char pad30[0x4];
    int field34;
    short field38;
    short field3a;
    short* field3c;
    short* field40;
    short* field44;
    short* field48;
};

// USA: func_0205bd78
extern "C" ARM int func_0205bd78(struct Struct_0205bd78* s, int x, int y) {
    if (s->field34 == 0) return -1;
    if (s->field3c == 0) return -1;
    if (s->field40 == 0) return -1;
    if (s->field44 == 0) return -1;
    if (s->field48 == 0) return -1;

    x -= s->field38;
    y -= s->field3a;

    int row = 0;
    while (row < *s->field24) {
        int col = 0;
        while (col < *s->field20) {
            int idx = col * *s->field24 + row;
            if (s->field34 > idx) {
                short a = s->field3c[idx];
                short b = s->field40[idx];
                short c = s->field44[idx];
                short d = s->field48[idx];
                int right = a + c;
                int bottom = b + d;
                if (x >= a && right >= x && y >= b && bottom >= y) {
                    *s->field2c = row;
                    *s->field28 = col;
                    int result = GetScaledSumIfActive0205bd04((struct Struct_0205bd04*)s);
                    if (s->field0 <= result) result = -1;
                    SetIndexIfValid0205bcdc((struct Struct_0205bcdc*)s, result);
                    return result;
                }
            }
            col++;
        }
        row++;
    }
    return -1;
}
