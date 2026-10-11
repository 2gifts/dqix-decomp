#include <globaldefs.h>

struct Words021e60c4 { unsigned int a, b, c; };
void InitWordsQuad_021e60e0(void* obj, unsigned int val);
void SetFourWordBlocks_021e6088(void* obj, Words021e60c4* src);
extern "C" void func_ov023_021e613c(Words021e60c4* dst, char* src);
extern "C" void func_ov023_021e6158(void* obj, int index);

struct Obj021e447c {
#if defined(jpn)
    char pad0[0x124];
#else
    char pad0[0x128];
#endif
    void* f128;
    void* f12c;
#if defined(jpn)
    char pad1[0x56c - 0x12c];
#else
    char pad1[0x634 - 0x130];
#endif
    unsigned short f634;
};

// JPN: func_ov023_021e46a0
// USA: func_ov023_021e447c
extern "C" ARM void func_ov023_021e447c(Obj021e447c* obj) {
    if (!(obj->f634 & 0x8)) return;
    if (*(unsigned char*)((char*)obj->f12c + 0xc12) != 0) return;
    if (obj->f634 & 0x40) {
        InitWordsQuad_021e60e0(obj->f128, 0x1eb);
        InitWordsQuad_021e60e0(obj->f12c, 0x1eb);
    } else {
        Words021e60c4 tmp;
        func_ov023_021e613c(&tmp, (char*)obj->f128);
        SetFourWordBlocks_021e6088(obj->f12c, &tmp);
    }
    void* t = obj->f128;
    obj->f128 = obj->f12c;
    obj->f12c = t;
    func_ov023_021e6158(obj->f12c, 0);
    func_ov023_021e6158(obj->f12c, 1);
    func_ov023_021e6158(obj->f12c, 5);
    func_ov023_021e6158(obj->f12c, 6);
    func_ov023_021e6158(obj->f12c, 2);
    func_ov023_021e6158(obj->f12c, 3);
    func_ov023_021e6158(obj->f12c, 4);
    obj->f634 &= ~0x8;
    obj->f634 &= ~0x40;
}
