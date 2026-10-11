#include <globaldefs.h>
#include "GameState/GameState.h"

struct Vec3_021f7784 {
    int x;
    int y;
    int z;
};

class Obj021f7784 {
public:
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06();
    virtual void MethodAt1c(Vec3_021f7784* v);
    virtual Vec3_021f7784 MethodAt20();
    virtual void v09(); virtual void v10(); virtual void v11(); virtual void v12();
    virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16();
    virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20();
    virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
    virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28();
    virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32();
    virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36();
    virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40();
    virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44();
    virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48();
    virtual void MethodAtC4(unsigned char a, unsigned char b, unsigned char c);

    char pad4[0xc - 0x4];
    unsigned char flags0xc;
    char pad0d[0x1c - 0xd];
    int field1c;
#if defined(jpn)
    char pad20[0x44 - 0x20];
#else
    char pad20[0x48 - 0x20];
#endif
    void* field48;
    unsigned char b4c;
    unsigned char b4d;
    unsigned char b4e;
};


// JPN: func_ov023_021f6c7c
// USA: func_ov023_021f7784
extern "C" ARM int func_ov023_021f7784(Obj021f7784* obj) {
    if (obj->flags0xc & 0x80) {
        int count = GameState::GetInstance()->GetTickCount();
        int t = (unsigned short)count;
        Vec3_021f7784 v = obj->MethodAt20();
        int newX = v.x - (t << 11);
        v.y += t << 11;
        v.x = newX;
        if (v.x < -0x100000) v.x += 0x100000;
        if (v.y > 0x100000) v.y -= 0x100000;
        obj->MethodAt1c(&v);
    }

    if (obj->flags0xc & 0x1) {
        return obj->field1c;
    }

    if (obj->field48 != 0) {
        obj->MethodAtC4(obj->b4c, obj->b4d, obj->b4e);
    }

    return obj->field1c;
}
