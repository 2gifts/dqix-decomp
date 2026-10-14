#include <globaldefs.h>
#include "GameState/GameState.h"

void* GetData02100044(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Vec3s02030fc8;
struct Vector3s;
void Vector3fix16Copy(Vector3s*, Vector3s const*);

struct Inner021d360c {
    unsigned char a;
    unsigned char b;
    unsigned short c;
    unsigned char vec[6];
    unsigned char pad2[6];
};

struct LocalEvt021d360c {
    unsigned char tag;
    unsigned char pad0[3];
    struct Inner021d360c fields;
};

// USA: func_ov017_021d360c  (semantic: EnqueueTagB6WithVec_021d360c)
extern "C" ARM void func_ov017_021d360c(int a, int b, int c, int d) {
    void* data = GetData02100044();
    struct LocalEvt021d360c buf;
    struct Inner021d360c* p = &buf.fields;

    if (a != 1) goto sendEvent;
    {
        int le3 = (unsigned int)c <= 3;
        if (le3) goto sendEvent;
    }
    {
        GameObject* combatant = GameState::GetInstance()->GetMaybeFieldMonsterByIndex(c);
        if (combatant == 0) return;
        unsigned short v = *(unsigned short*)((char*)combatant + 0x100 + 0x6a);
        c = (unsigned short)(v + 4);
    }

sendEvent:
    buf.tag = 0xb6;
    p->a = (unsigned char)a;
    p->b = (unsigned char)b;
    p->c = (unsigned short)c;
    Vector3fix16Copy((Vector3s*)p->vec, (Vector3s const*)&d);

    func_0205e330(data, &buf, 0);
}
