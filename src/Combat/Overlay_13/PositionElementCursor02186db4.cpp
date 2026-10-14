#include <globaldefs.h>

struct Struct_0205d81c;

struct Elem_0205d81c* FindElementByC40205d81c(struct Struct_0205d81c*, int);
int IsField0x9cEqual3(unsigned char*);
void* GetArrayElement02184338(void*, unsigned int);
extern "C" void func_0205ac40(void* list, void* entry);

struct CursorTag_02186db4 {
    unsigned char pad00[0x14];
    int posX;
    int posY;
    unsigned char pad1c[6];
    unsigned char size;
    unsigned char pad23[3];
    unsigned char visible;
};

// USA: func_ov013_02186db4  (semantic: PositionElementCursor02186db4)
extern "C" ARM void func_ov013_02186db4(void* obj) {
    unsigned char* o = (unsigned char*)obj;

    if (*(void**)(o + 0x18) == 0) return;

    unsigned char* elem = (unsigned char*)FindElementByC40205d81c((struct Struct_0205d81c*)(o + 0x38), 4);
    if (elem == 0) return;
    if (IsField0x9cEqual3(elem) == 0) return;
    if ((elem[0xc5] & 0x20) != 0) return;

    int tagId = 0x2a;
    if (o[0x640] != 0) tagId = 0x20;

    CursorTag_02186db4* tag = (CursorTag_02186db4*)GetArrayElement02184338(*(void**)(o + 0x18), (unsigned short)tagId);
    if (tag == 0) return;

    short x = *(short*)(elem + 0xac);
    short y = *(short*)(elem + 0xae);
    short baseX = *(short*)(o + 0x1e);
    x *= 8;
    y *= 8;
    x += baseX + 3;
    y += 3;
    tag->posX = x * 0x1000;
    tag->posY = y * 0x1000;
    tag->visible = 1;
    tag->size = 0x20;
    func_0205ac40(*(void**)(o + 0x18), tag);
}
