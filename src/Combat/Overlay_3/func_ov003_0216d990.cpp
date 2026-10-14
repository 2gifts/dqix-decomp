#include <globaldefs.h>

struct Elem_0205d81c {
    char pad0[0xac];
    short posX;
    short posY;
};

struct Struct_0205d81c;
struct Elem_0205d81c* FindElementByC40205d81c(struct Struct_0205d81c* s, int key);
int CheckField0NonZero(int* obj);
void GetFourSubstructPointers(unsigned char* elem, unsigned char** a, unsigned char** b, unsigned char** c,
                              unsigned char** d);

extern "C" void* func_0202ae18(void);
extern "C" void func_0205ac40(void* list, void* entry);

struct CursorTag_0216d990 {
    unsigned char pad00[0x14];
    int posX;
    int posY;
};

// USA: func_ov003_0216d990
extern "C" ARM void func_ov003_0216d990(char* obj) {
    void* g = func_0202ae18();
    if (*(short*)(obj + 4) != 2 || *(short*)(obj + 6) != 2) return;
    if (CheckField0NonZero((int*)g) != 0) return;

    struct CursorTag_0216d990* tag = 0;
#if defined(jpn)
    enum { baseOffset = 0x113c, countOffset = 0x114a, listOffset = 0x10fc };
#else
    enum { baseOffset = 0x12ac, countOffset = 0x12ba, listOffset = 0x126c };
#endif
    char* base = *(char**)(obj + baseOffset);
    if (base != 0 && *(unsigned short*)(obj + countOffset) > 6) {
        tag = (struct CursorTag_0216d990*)(base + 0xf0);
    }
    if (tag == 0) return;

#if defined(jpn)
    tag->posX = 0xde000;
    tag->posY = 0x14000;
#else
    struct Elem_0205d81c* elem = FindElementByC40205d81c(*(struct Struct_0205d81c**)(obj + 0x1000 + 0x2c0), 0);
    if (elem == 0) return;

    short ex = elem->posX << 3;
    short ey = elem->posY << 3;
    short* xMin;
    short* yMin;
    short* xWidth;
    short* yWidth;
    GetFourSubstructPointers((unsigned char*)elem, (unsigned char**)&xMin, (unsigned char**)&yMin, (unsigned char**)&xWidth,
                             (unsigned char**)&yWidth);
    int x = xMin[1] + xWidth[1] + ex;
    int y = yMin[1] + ey;
    x = (short)x;
    y = (short)y;
    tag->posX = (x + 2) << 12;
    tag->posY = (y - 2) << 12;
#endif
    func_0205ac40(obj + listOffset, tag);
}
