#include <globaldefs.h>
#include "GameState/GameState.h"

struct Obj374b0;
extern "C" void* _ZN8Object3D25GetCurrentAnimationConfigEv(struct Obj374b0* obj);

struct List_020347b4;
struct Entry_020347b4;
extern "C" Entry_020347b4* _ZN4BCFG18GetAnimationRecordEi(List_020347b4* list, int index);


extern "C" void func_0208e0a8(void);
extern "C" void* func_0202ae18(void);
extern "C" int func_0202c540(void* obj);
extern "C" void* func_0205ec34(void);
extern "C" void func_0208f048(unsigned char* p0);
extern "C" int rand(void);
int TestBitInByteArray(int unused, unsigned char* arr, int index);
extern "C" void _Z27EnqueueEventTag183_021d38f8hhhhPi(unsigned char a0, unsigned char a1, unsigned char a2, unsigned char a3, int* p);

struct Node0208ec78 {
    char pad[0x10];
    int val;                     // +0x10
    struct Node0208ec78* next;   // +0x14
};

struct Param0208ec78 {
    unsigned char id;            // +0x0
    float accum;                 // +0x4
    struct Obj374b0* field8;     // +0x8
    struct Node0208ec78* fieldC; // +0xc
};

struct Entry0208ec78 {
    unsigned int low9 : 9;
    unsigned int nibA : 4;
    unsigned int nibB : 4;
    unsigned int id8 : 8;
    unsigned int type4 : 4;
    unsigned int kind : 2;
    unsigned int flag : 1;
};

// USA: func_0208ec78
extern "C" ARM void func_0208ec78(struct Param0208ec78* p0) {
    GameState* bs = GameState::GetInstance();
    func_0208e0a8();
    void* g;
    char* r;
#if defined(jpn)
    struct Entry0208ec78* arr = (struct Entry0208ec78*)((char*)bs + 0x5a7c);
#else
    struct Entry0208ec78* arr = (struct Entry0208ec78*)((char*)bs + 0x5cdc);
#endif
    g = func_0202ae18();

    if (p0->field8 != 0) {
        void* field4 = _ZN8Object3D25GetCurrentAnimationConfigEv(p0->field8);
        if (field4 != 0) {
            Entry_020347b4* rate = _ZN4BCFG18GetAnimationRecordEi((List_020347b4*)field4, 0);
            if (rate != 0) {
                r = (char*)rate;
                int ifixed = (int)(4096.0f * ((float)(unsigned int)bs->GetEffectiveDeltaTime() / 16.666666f));
                int rateVal = *(int*)(r + 0x18);
                int delta = (int)(((long long)rateVal * ifixed + 0x800) >> 12);
                struct Node0208ec78* node = p0->fieldC;
                while (node != 0) {
                    node->val += delta;
                    if (*(int*)(r + 0x14) < node->val) {
                        node->val = *(int*)(r + 0x10);
                    }
                    node = node->next;
                }
            }
        }
    }

    if (func_0202c540(g) != 0) {
        return;
    }

    p0->accum = p0->accum + (float)(unsigned int)bs->GetEffectiveDeltaTime() / 1000.0f;
    if (p0->accum < 60.0f) {
        if (p0->id == 0) return;
    }
    if (p0->accum >= 60.0f) {
        p0->accum = 0.0f;
    }

    unsigned char id0 = p0->id;
    struct Entry0208ec78* e;
    int avail = 0;
    e = &arr[id0];
    if (e->flag == 0) avail = 1;
    unsigned int kind = e->kind;
    if (kind != 1) {
        void* ctx = func_0205ec34();
        if (e->kind == 2 && TestBitInByteArray((int)ctx, (unsigned char*)ctx + 0x8c, 1944) == 0) {
            avail = 1;
        } else if (e->kind == 3 && TestBitInByteArray((int)ctx, (unsigned char*)ctx + 0x8c, 1942) == 0) {
            avail = 1;
        }
    }

    if (avail != 0) {
        p0->id = (unsigned char)((p0->id + 1) % 100);
        return;
    }

    unsigned char pop = 0;
    {
        int i;
        for (i = 0; i < 8; i++) {
            if (((*(unsigned int*)e << 7) >> 24) & (1u << i)) pop++;
        }
    }

    unsigned int sel = pop;
    if (e->low9 == 0) {
        unsigned char rej = 0;
        if (pop == 0) {
            rej = rand() % (e->nibA + 1);
            if (rej < e->nibB) rej = e->nibB;
        } else if (pop < e->nibA) {
            rej = rand() % (e->nibA - pop + 1);
        }

        if (p0->id < 0x62) {
            sel = (pop + rej) & 0xff;
            unsigned int j = rand() % e->nibA;
            while (rej != 0) {
                unsigned int mask = 1u << j;
                unsigned int idbits = (*(unsigned int*)e << 7) >> 24;
                if ((idbits & mask) == 0) {
                    e->id8 = idbits | mask;
                    rej--;
                }
                j++;
                if (j >= e->nibA) j = 0;
            }
            _Z27EnqueueEventTag183_021d38f8hhhhPi(0, 0, (unsigned char)((*(unsigned int*)e << 7) >> 24), p0->id, (int*)e);
        } else {
            func_0208f048((unsigned char*)p0);
        }

        e->low9 = e->type4 * 30;
    }

    if (sel != e->nibA || p0->id >= 0x62) {
        e->low9 = e->low9 - 1;
    }
    p0->id = (unsigned char)((p0->id + 1) % 100);
}
