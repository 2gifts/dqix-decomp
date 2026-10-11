#include <globaldefs.h>

struct Struct0205de24;
extern "C" void _Z32FindAndLinkMatchingEntry0205de24P14Struct0205de24hh(struct Struct0205de24 *obj, unsigned char a,
                                                                        unsigned char b);
extern "C" void _Z24AppendEntryList_0215f224PcS_i(char *self, char *list, int n);
extern "C" void func_ov002_0215be00(char *self, int a, int b, int c);
extern "C" void *memset(void *dst, int c, unsigned int n);
extern "C" int func_0205d304(char *obj, char *list, int a, int b, int c, int d, int e, int f);

struct F0215f170 {
    char pad[0x58];
    int n;
};

// USA: func_ov002_0215f170
extern "C" ARM int func_ov002_0215f170(char *self) {
    struct F0215f170 *p = (struct F0215f170 *) (self + 0x2c8 + 0xc00) + 1;
    p--;
    int many = 0;
    if (p->n > 1) {
        many = 1;
    }
    _Z32FindAndLinkMatchingEntry0205de24P14Struct0205de24hh((struct Struct0205de24 *) (self + 0xec8), 0, 3);
    func_ov002_0215be00(self, *(int *) (self + 0x1bb8) & 0xff, 0x11, 1);
    memset(*(char **) (self + 0x1bd0), 0, 0x960);
    _Z24AppendEntryList_0215f224PcS_i(self, *(char **) (self + 0x1bd0), 0);
    return func_0205d304(self + 0x2c8 + 0xc00, *(char **) (self + 0x1bd0), 0, 0, many, 1, 0, 0);
}
