#if defined(jpn)
#define R(j,u) (j)
#define data_ov005_0215cd48 data_ov005_0215e128
#define func_ov005_02157b74 func_ov005_0215916c
#define func_ov013_02185990 func_ov013_02186b88
#define func_ov013_02186c64 func_ov013_02187f78
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

struct Struct_0205bcdc;
void SetIndexIfValid0205bcdc(struct Struct_0205bcdc* s, int index);
extern "C" void func_0205bb04(void* s, int n);

int GetGlobalField0x1c020421a0();
int GetScaledSumIfActive0205cecc(void* s);
int CallFunc0205c570AtField0x1c(void* obj);
int TestFlag0SetAndFlag1Clear(unsigned short* obj, int mask);
void ReinitController02043204(char* obj);
void ResetGlobalObjAndInitSelfPointer0205ce94(unsigned char* p);
void InvalidateBattlerField0x18(unsigned char* obj);

struct Obj0205eaa0;
void DispatchWithShortB4_0205eaa0(struct Obj0205eaa0* obj, int a, int b);

struct Entry_0205d6a0;
void ResetEntryList0205d6a0(struct Entry_0205d6a0* a, int flag);

extern "C" void func_ov013_02185990(void* obj);
extern "C" void func_ov013_02186c64(void* obj, int a, int b);
extern "C" void func_ov013_02185cc0(void* obj);

extern unsigned short data_02114e30;
extern struct Obj0205eaa0 data_02108760;

// USA: func_ov013_02186590  (semantic: AdvanceTagState02186590)
extern "C" ARM void func_ov013_02186590(void* obj) {
    unsigned char* o = (unsigned char*)obj;
    if (o[R(0x5cb,0x63f)] != 0) {
        o[R(0x5c5,0x639)] = 1;
    }
    int g = GetGlobalField0x1c020421a0();
    unsigned char* gp = (unsigned char*)g;
    int oneFlag = 1;
    gp[0x1000 + R(0x7ee,0x9be)] = oneFlag;

    if (o[R(0x5ca,0x63e)] == 0) {
        if (*(int*)(gp + R(0x870,0x9a0)) != 0) return;
        func_ov013_02185990(obj);
        unsigned char tag = o[R(0x5c8,0x63c)];
        unsigned char* local = o + R(0x3ec,0x3f0);
        if (tag == 4) {
            SetIndexIfValid0205bcdc((struct Struct_0205bcdc*)(local + 4), oneFlag);
            func_0205bb04(local + 0x54, oneFlag);
        } else {
            SetIndexIfValid0205bcdc((struct Struct_0205bcdc*)(local + 4), 0);
            func_0205bb04(local + 0x54, 0);
        }
        o[R(0x5ca,0x63e)] = o[R(0x5ca,0x63e)] + 1;
        return;
    }

    if (o[R(0x5ca,0x63e)] != 1) return;

    int scaled = GetScaledSumIfActive0205cecc(o + R(0x3d0,0x3d4));
    if (TestFlag0SetAndFlag1Clear(&data_02114e30, 0x601) != 0) {
        scaled = CallFunc0205c570AtField0x1c(o + R(0x3d0,0x3d4));
    } else if (TestFlag0SetAndFlag1Clear(&data_02114e30, 2) != 0) {
        scaled = -2;
        oneFlag = 0;
    }

    if (scaled == -2) goto caseInvalidate;
    if (scaled == 0) goto caseReset;
    if (scaled == 1) goto caseInvalidate;
    return;

caseReset:
    {
        unsigned char tag = o[R(0x5c8,0x63c)];
        if (tag == 4) {
            o[R(0x5c8,0x63c)] = 5;
            ReinitController02043204((char*)gp);
            ResetGlobalObjAndInitSelfPointer0205ce94(o + R(0x3d0,0x3d4));
            o[R(0x5ec,0x664)] = 0;
            DispatchWithShortB4_0205eaa0(&data_02108760, 1, 0);
        } else {
            o[R(0x5c8,0x63c)] = 5;
            o[R(0x5ec,0x664)] = 1;
            ReinitController02043204((char*)gp);
            ResetGlobalObjAndInitSelfPointer0205ce94(o + R(0x3d0,0x3d4));
            ResetEntryList0205d6a0((struct Entry_0205d6a0*)(o + R(0x34,0x38)), 1);
            DispatchWithShortB4_0205eaa0(&data_02108760, 1, 0);
        }
        o[R(0x5ca,0x63e)] = 0;
        return;
    }

caseInvalidate:
    o[R(0x5c8,0x63c)] = 1;
    o[R(0x5ca,0x63e)] = 0;
    InvalidateBattlerField0x18((unsigned char*)&data_02114e30);
    if (oneFlag != 0) {
        DispatchWithShortB4_0205eaa0(&data_02108760, 1, 0);
    }
    o[R(0x5ec,0x664)] = 0;
    ReinitController02043204((char*)gp);
    ResetGlobalObjAndInitSelfPointer0205ce94(o + R(0x3d0,0x3d4));
    o[R(0x5c5,0x639)] = 0;
    func_ov013_02186c64(obj, 0, 0);
    func_ov013_02185cc0(obj);
}
