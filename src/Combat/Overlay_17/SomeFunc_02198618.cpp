#if defined(jpn)
enum {regionalOffset0=0x8c, regionalOffset1=0xc4, regionalOffset2=0xc6};
#else
enum {regionalOffset0=0x6c, regionalOffset1=0x84, regionalOffset2=0x86};
#endif
#include <globaldefs.h>
#include "GameState/GameState.h"

struct BitField0203402c {
    char pad[0xc4];
    unsigned short field15 : 15;
    unsigned short bit15 : 1;
};

int CheckSubstructByte0x7cPositive(signed char* obj);
int CheckField0xc4Low15BitsNonZero(struct BitField0203402c* p);
extern "C" void* func_02012fe4(void);
int GetField0x3b0Value(GameState* battleStruct);
void* GetPointerFromArray0x3c(unsigned char* obj, unsigned int index);
extern "C" int func_02094b9c(void* self, void* data);
void InitObj0219a674(unsigned char* self);
extern "C" void func_ov017_0219b33c(void* a, void* buf, int b, int tag);

struct Buf3021986 { unsigned int w0, w1, w2; };

struct LocalBuf021986 {
    unsigned char tag;
    unsigned char field1;
    unsigned short field2;
    unsigned char field4;
    unsigned char pad5[3];
    void* ptr8;
    unsigned char pad12[4];
    unsigned short field10;
    unsigned char pad18[2];
};

// JPN: func_ov017_021991c8
// USA: func_ov017_02198618  (semantic: SomeFunc_02198618)
extern "C" ARM void func_ov017_02198618(void* p0) {
    GameState* battle = GameState::GetInstance();
    GameObject* c = battle->GetUnknownGameObject();
    if (c == NULL) return;
    if (CheckSubstructByte0x7cPositive((signed char*)c) != 0) return;
    if (CheckField0xc4Low15BitsNonZero((struct BitField0203402c*)c) != 0) return;

    unsigned char* misc = (unsigned char*)func_02012fe4();
    GetField0x3b0Value(battle);
    unsigned char* arr = (unsigned char*)GetPointerFromArray0x3c(misc + regionalOffset0, 10);
    struct Buf3021986 buf3 = *(struct Buf3021986*)((char*)c + 0x44);

    while (arr != NULL) {
        if (func_02094b9c(arr, &buf3) != 0) {
            unsigned short field2c = *(unsigned short*)(arr + 0x2c);
            short field84 = *(short*)(misc + 0x2700 + regionalOffset1);
            if (field2c == field84) {
                unsigned short misc0 = *(unsigned short*)misc;
                unsigned short field86 = *(unsigned short*)(misc + 0x2700 + regionalOffset2);
                if (misc0 == field86) {
                    struct LocalBuf021986 lb;
                    InitObj0219a674((unsigned char*)&lb);
                    lb.tag = 0xb;
                    lb.ptr8 = arr;
                    lb.field4 = 1;
                    func_ov017_0219b33c(p0, &lb, 1, 0xb);
                    return;
                }
            }
        }
        arr = *(unsigned char**)(arr + 0x70);
    }
}
