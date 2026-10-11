#include <globaldefs.h>
#include "GameState/GameState.h"

int GetGlobalField0x1c020421a0(void);
extern "C" void* func_ov011_021849c8(void* a);
extern "C" void* func_ov023_021f6880(void** list, int value);
extern "C" void* func_ov023_021fad18(void* obj);

struct Entry021faed0;
ARM void* GetEntryPtr_021fa854(char* obj, unsigned int idx);

extern "C" void func_0205ac40(void* obj, void* entry);
void SelectCoordsByFlag0x24(unsigned char* obj, int* out1, int* out2);

struct Obj0205eaa0;
void DispatchWithShortB4_0205eaa0(struct Obj0205eaa0* obj, int a, int b);
extern struct Obj0205eaa0 data_02108760;

extern "C" void func_ov011_02184a40(void* a, int b);

extern char data_02114e54;
#if defined(jpn)
extern "C" void* func_0203bd08(void);
extern "C" void* func_0203be40(void);
#endif

struct Entry021faed0 {
    unsigned short us0;
    char pad1[0x14 - 0x2];
    int f14;
    int f18;
    char pad2[0x22 - 0x1c];
    unsigned char b22;
    char pad3[0x25 - 0x23];
    signed char b25;
    signed char b26;
};

struct Obj021faed0 {
    char pad0[0xc];
    unsigned char flags0xc;
    char pad1[0x20 - 0xd];
    unsigned short f20;
    unsigned short f22;
    unsigned short f24;
    char pad2[0x28 - 0x26];
    int f28;
    int f2c;
    signed short f30;
    signed short f32;
    signed short f34;
    signed short f36;
    signed char f38;
    signed char f39;
#if defined(jpn)
    unsigned short f3c;
    unsigned short f3e;
    unsigned short f40;
    unsigned short f42;
    char regionalPad42[2];
    int f44;
    int f46;
    signed short f48;
    unsigned char f4a;

#else
    unsigned char f3a;
    char pad3[0x3c - 0x3b];
    unsigned short f3c;
    unsigned short f3e;
    unsigned short f40;
    unsigned short f42;
    unsigned short f44;
    unsigned short f46;
    signed short f48;
    unsigned char f4a;
    unsigned char f4b;

#endif
};

// JPN: func_ov023_021fa2b0
// USA: func_ov023_021faed0  (semantic: SyncEntryPositionAndDispatch_021faed0)
extern "C" ARM void func_ov023_021faed0(struct Obj021faed0* obj, void* arg1) {
    if ((obj->flags0xc & 8) == 0) {
        void** listHead = (void**)func_ov011_021849c8(arg1);
        void* node = func_ov023_021f6880(listHead, obj->f20);
        void* z = func_ov023_021fad18(node);
        struct Entry021faed0* entryPtr = (struct Entry021faed0*)GetEntryPtr_021fa854((char*)z, obj->f22);
        int* state = (int*)GetGlobalField0x1c020421a0();

        if (entryPtr != 0) {
#if defined(jpn)
            int delta = 0;
            signed char saved25 = entryPtr->b25;
            signed char saved26 = entryPtr->b26;
            if (obj->f4a != 0) delta = 0x1000;
            entryPtr->b22 = (unsigned char)obj->f24;
            entryPtr->f14 = obj->f28 + delta;
            entryPtr->f18 = obj->f2c + delta;
            signed char v38 = obj->f38;
            if (v38 >= 0) entryPtr->b25 = v38 & 0xf;
            signed char v39 = obj->f39;
            if (v39 >= 0) entryPtr->b26 = v39 & 3;
            func_0205ac40(z, entryPtr);
            entryPtr->f14 = obj->f28;
            entryPtr->f18 = obj->f2c;
            obj->f4a = 0;
            entryPtr->b25 = saved25;
            entryPtr->b26 = saved26;
            int selected = obj->f44;
            if (obj->f46 != -1) {
                int cond = *(int*)((char*)state + 0x10c) >= 2;
                if (cond) selected = obj->f46;
            }
            if (selected >= 0) {
                func_0203bd08();
                struct Slot { unsigned int word; unsigned int next; };
                Slot* table = (Slot*)func_0203be40();
                unsigned int word = table[obj->f24].word & 0x3fff3fff;
                word |= selected;
                table[obj->f24].word = word;
            }

#else
            int dx = 0, dy = 0;
            if (obj->f4a != 0) {
                dx = 0x1000;
                dy = 0x1000;
            } else if (obj->f4b != 0) {
                dx = -0x1000;
                dy = 0x1000;
            }

            signed char saved25 = entryPtr->b25;
            signed char saved26 = entryPtr->b26;
            entryPtr->b22 = (unsigned char)obj->f24;
            entryPtr->f14 = obj->f28 + dx;
            entryPtr->f18 = obj->f2c + dy;
            signed char v38 = obj->f38;
            if (v38 >= 0) entryPtr->b25 = v38 & 0xf;
            signed char v39 = obj->f39;
            if (v39 >= 0) entryPtr->b26 = v39 & 3;

            unsigned short v44 = obj->f44;
            if (obj->f46 != 0) {
                int cond = *(int*)((char*)state + 0x14c) >= 2;
                if (cond) v44 = obj->f46;
            }
            if (v44 != 0) entryPtr->us0 = v44;

            int cond2 = *(int*)((char*)state + 0x14c) >= 2;
            if (cond2 && obj->f3a != 0) {
                unsigned short v0 = entryPtr->us0;
                if (v0 > 2) {
                    entryPtr->us0 = v0 - 2;
                    func_0205ac40(z, entryPtr);
                    entryPtr->us0 = v0;
                }
            } else {
                func_0205ac40(z, entryPtr);
            }

            entryPtr->f14 = obj->f28;
            entryPtr->f18 = obj->f2c;
            obj->f4a = 0;
            obj->f4b = 0;
            entryPtr->b25 = saved25;
            entryPtr->b26 = saved26;
#endif

        }
    }

    if ((obj->flags0xc & 0x10) == 0) {
        unsigned char b55 = *((unsigned char*)&data_02114e54 + 0x55);
        int flagX = 0;
        if (*((unsigned char*)&data_02114e54 + 0x5f) != 0 &&
            *(unsigned short*)((char*)&data_02114e54 + 0x24) != 0) {
            flagX = 1;
        }
        unsigned char b54 = *((unsigned char*)&data_02114e54 + 0x54);
        GameState* battleStruct = GameState::GetInstance();
        int field3b4 = battleStruct->GetEffectiveDeltaTime();
        int result = 0;

        if (b55 != 0 && (obj->flags0xc & 0x20) == 0) {
            result = obj->f3c;
            obj->flags0xc |= 0x20;
            obj->f48 = 0x1f4;
            goto DONE;
        }
        if (flagX != 0 && (obj->flags0xc & 0x20) != 0) {
            signed short v48 = obj->f48;
            result = obj->f3e;
            if (v48 > 0) {
                obj->f48 = v48 - field3b4;
                goto DONE;
            }
            unsigned short v42 = obj->f42;
            if (v42 != 0) result = v42;
            goto DONE;
        }
        if (b54 != 0 && (obj->flags0xc & 0x20) != 0) {
            result = obj->f40;
            goto DONE;
        }
        obj->flags0xc &= ~0x20;

DONE:
        if (result == 0) return;

        int px, py;
        SelectCoordsByFlag0x24((unsigned char*)&data_02114e54, &px, &py);
        int ax1 = (obj->f28 >> 12) + obj->f30;
        int ay1 = (obj->f2c >> 12) + obj->f32;
        int ax2 = ax1 + obj->f34;
        int ay2 = ay1 + obj->f36;
        int pySave = py;
        int overlap = 0;
        if (ax1 <= px && px < ax2 && ay1 <= pySave && pySave < ay2) overlap = 1;

        if (overlap != 0) {
            if (result == 0) return;
            if (obj->flags0xc & 0x40) {
                DispatchWithShortB4_0205eaa0(&data_02108760, 1, 0);
            }
            func_ov011_02184a40(arg1, result);
        } else {
            obj->flags0xc &= ~0x20;
        }
    }
}
