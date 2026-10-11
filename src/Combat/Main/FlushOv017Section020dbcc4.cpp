#include <globaldefs.h>

#if defined(jpn)
enum { kSectionOffset = 0x860 };
#else
enum { kSectionOffset = 0x840 };
#endif

#include "GameState/GameState.h"

extern "C" void* func_02012fe4(void);
void* GetData02100044(void);
struct Struct0205e7d0;
int GetSection0x1000Count0205e7d0(struct Struct0205e7d0* s);
extern "C" int func_ov017_021d3d40(void* dst, int len, int val, unsigned char byte, int cursor);

struct Obj020dbcc4 {
    unsigned char pad0[1];
    unsigned char field1;
    unsigned char pad2[6];
    unsigned char field8;
    unsigned char pad3[3];
    int field0xc;
    int field10;
};

// USA: func_020dbcc4
ARM void FlushOv017Section020dbcc4(struct Obj020dbcc4* obj) {
    int flag;
    int i;
    GameState::GetInstance();
    char* base = (char*)func_02012fe4() + kSectionOffset;
    if (obj->field10 != 0) return;
    if (GetSection0x1000Count0205e7d0((struct Struct0205e7d0*)GetData02100044()) < 0x76) return;

    flag = 0;
    for (i = 0; i < 4; i++) {
        int cursor = obj->field0xc;
        if (cursor + 0xd > 0x1b30) {
            flag = 1;
            func_ov017_021d3d40(base + cursor, (0x1b30 - cursor) & 0xff, 1, obj->field8, cursor);
            break;
        } else {
            func_ov017_021d3d40(base + cursor, 0xd, 0, obj->field8, cursor);
            obj->field0xc = obj->field0xc + 0xd;
        }
    }

    if (flag != 0) {
        obj->field1 = 1;
    }
}
