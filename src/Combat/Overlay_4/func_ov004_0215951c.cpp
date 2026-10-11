#include <globaldefs.h>
#if defined(jpn)
enum { combatantArrayPointerOffset = 0x144 };
#else
enum { combatantArrayPointerOffset = 0x150 };
#endif
#include "GameState/GameState.h"

extern "C" signed char func_ov004_02157128(void* obj);
extern "C" void* func_ov004_02156f04(void* a, int key);
extern "C" void* func_ov004_02156f6c(void*, int);
extern "C" void func_ov023_021f809c(void*, void*);

struct Struct021707d8_0215951c { char pad[8]; unsigned char* ptr; };
extern Struct021707d8_0215951c data_ov004_021707d8;
extern unsigned char data_ov004_0216fb10[8];

struct Elem0215951c {
    int f0;
    void* f4;
    unsigned int type : 4;
    unsigned int f8rest : 28;
    char pad[0xc];
    short f18;
    char pad2[6];
};

class VObj0215951c {
public:
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
    virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
    virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51();
    virtual void v52(); virtual void v53();
    virtual void Dispatch54(int n);
    int pad4[7];
    void* field0x20;
};

// USA: func_ov004_0215951c  (semantic: DispatchCombatantBufferEntries_0215951c)
extern "C" ARM int func_ov004_0215951c(void* obj) {
    signed char flag = func_ov004_02157128(obj);
    GameState* battle = GameState::GetInstance();
    GameObject* c = GetCombatantWithFlag0x100(battle, flag);
    if (!c) return 0;

    unsigned char* fieldPtr = data_ov004_021707d8.ptr;
    fieldPtr[0x12] = (unsigned char)flag;

    unsigned char buf[8];
    int n = 8;
    unsigned char* dst = buf;
    unsigned char* src = data_ov004_0216fb10;
    do {
        unsigned char v = *src;
        src++;
        *dst = v;
        dst++;
    } while (--n);

    int key = 0x384;
    for (short i = 0; i < 8; key++, i++) {
        int dispatchArg = 3;
        void* ptr9 = 0;
        int idx = buf[i];
        if (idx != 0xff) {
            Elem0215951c* arr = (Elem0215951c*)(*(char**)((char*)c + combatantArrayPointerOffset) + 0x194);
            Elem0215951c* e = &arr[idx];
            if (e) {
                if (e->f18 > 0) {
                    unsigned int type = e->type;
                    if (type == 0xb) goto skip;
                    ptr9 = e->f4;
                    if (!ptr9) goto skip;
                    if (*(signed char*)ptr9 != 0) dispatchArg = 0xf;
                    else ptr9 = 0;
                }
            }
        }
    skip:
        VObj0215951c* node = (VObj0215951c*)func_ov004_02156f04(obj, key);
        if (node) {
            node->field0x20 = ptr9;
            node->Dispatch54(dispatchArg);
        }
    }

    void* node2 = func_ov004_02156f6c(obj, 0x16);
    if (node2) {
        func_ov023_021f809c(node2, obj);
    }
    return 0;
}
