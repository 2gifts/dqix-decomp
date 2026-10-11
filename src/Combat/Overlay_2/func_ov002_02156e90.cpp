#include <globaldefs.h>

struct Struct0205d888;
struct Entry_0205d6a0;
struct Struct_0205d81c;
struct Elem0205d888 {
    char pad[0xc4];
    unsigned char key;
};
extern "C" struct Elem0205d888 *_Z20GetLastEntry0205d888P14Struct0205d888(struct Struct0205d888 *s);
extern "C" void *_Z23FindElementByC40205d81cP15Struct_0205d81ci(struct Struct_0205d81c *s, int key);
extern "C" void _Z22ResetEntryList0205d6a0P14Entry_0205d6a0i(struct Entry_0205d6a0 *e, int a);
void SetElementFieldC2(struct Struct_0205d81c *s, int a, int b);
extern "C" void func_ov002_02161cf0(void *base);
extern "C" void func_ov002_0215b9a4(void *base, int a, int b);
extern "C" const unsigned char data_ov002_0216c99d[];
extern "C" const unsigned char data_ov002_0216c99e[];

// USA: func_ov002_02156e90
extern "C" ARM void func_ov002_02156e90(char *base) {
    int count              = 1;
    struct Elem0205d888 *e = _Z20GetLastEntry0205d888P14Struct0205d888((struct Struct0205d888 *) (base + 0xec8));
    if (e != NULL) {
        for (int i = 0; i < 8; i++) {
            unsigned char k = e->key;
            unsigned char t = data_ov002_0216c99d[i * 2];
            if (t == k) {
                count = 2;
                break;
            }
            if (k >= 0x2c && k <= 0x2f) {
                count = 0;
                for (unsigned char j = 0x2c; j <= 0x2f; j++) {
                    if (_Z23FindElementByC40205d81cP15Struct_0205d81ci((struct Struct_0205d81c *) (base + 0xec8), j) != NULL) {
                        count++;
                    }
                }
                break;
            }
        }
    }
    for (int i = 0; i < count; i++) {
        _Z22ResetEntryList0205d6a0P14Entry_0205d6a0i((struct Entry_0205d6a0 *) (base + 0xec8), 0);
    }
    e = _Z20GetLastEntry0205d888P14Struct0205d888((struct Struct0205d888 *) (base + 0xec8));
    if (e == NULL) return;
    *(int *) (base + 0x1000 + 0xbb8) = e->key;
    func_ov002_02161cf0(base);
    for (int i = 0; i < 8; i++) {
        unsigned char t = data_ov002_0216c99d[i * 2];
        if (t == e->key) {
            unsigned char k = data_ov002_0216c99e[i * 2];
            _Z23FindElementByC40205d81cP15Struct_0205d81ci((struct Struct_0205d81c *) (base + 0xec8), k);
            SetElementFieldC2((struct Struct_0205d81c *) (base + 0xec8), k, 0);
            break;
        }
    }
    func_ov002_0215b9a4(base, *(int *) (base + 0x1000 + 0xbb8) & 0xff, 0);
}
