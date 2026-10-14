#if defined(jpn)
#define func_0205cc50 func_0205dfa8
#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif
#include <globaldefs.h>

#if defined(jpn)
#define func_ov013_02185990 func_ov013_02186b88
#endif

struct Struct_0205ba68;
void SetupPointerTable0205ba68(struct Struct_0205ba68* s, int a, int b, int mode);

struct Node0205bacc;
void SetField0AndPropagate0205bacc(struct Node0205bacc* s, int val);

struct Container020e0310;
int GetFieldByKey020e0434(struct Container020e0310* c, int key);

void ProcessCombatEntry0205cb74(char* obj, int value);

#if defined(jpn)
extern "C" void func_0205cc50(void* obj);
#else
extern "C" void func_0205cc50(void* obj, int a, int b);
#endif

struct ResetBytesAndSetByte0x16Data;
void ResetBytesAndSetByte0x16_0205c77c(struct ResetBytesAndSetByte0x16Data* p, int val);

void SetupGlobalObjType1AndInitSelfPointer_0205cd28(unsigned char* obj);
void InitGlobalObjAndSelfPointer0205cd94(unsigned char* p);

struct Obj0205eaa0;
void DispatchWithShortB4_0205eaa0(struct Obj0205eaa0* obj, int a, int b);

void InitBigStruct0205c790(char* obj);

extern int data_02108760;

// USA: func_ov013_02185990  (semantic: InitCombatEntry02185990)
extern "C" ARM void func_ov013_02185990(unsigned char* obj) {
    unsigned char* tag = obj + LOW_REGION(0, 0x3d4);

    InitBigStruct0205c790((char*)(tag + LOW_REGION(0x3d0, 0)));

    *(unsigned char*)(tag + LOW_REGION(0x481, 0xb1)) = 1;
    *(unsigned char*)(tag + LOW_REGION(0x480, 0xb0)) = 1;

    SetupPointerTable0205ba68((struct Struct_0205ba68*)(tag + LOW_REGION(0x3f0, 0x20)), 1, 2, 0);
    SetupPointerTable0205ba68((struct Struct_0205ba68*)(tag + LOW_REGION(0x440, 0x70)), 1, 2, 0);
    SetField0AndPropagate0205bacc((struct Node0205bacc*)(tag + LOW_REGION(0x3f0, 0x20)), 2);
    SetField0AndPropagate0205bacc((struct Node0205bacc*)(tag + LOW_REGION(0x440, 0x70)), 2);

    int v0 = GetFieldByKey020e0434((struct Container020e0310*)(obj + LOW_REGION(0x5ac, 0x620)), 0xa);
    ProcessCombatEntry0205cb74((char*)(tag + LOW_REGION(0x3d0, 0)), v0);

    int v1 = GetFieldByKey020e0434((struct Container020e0310*)(obj + LOW_REGION(0x5ac, 0x620)), 0xb);
    ProcessCombatEntry0205cb74((char*)(tag + LOW_REGION(0x3d0, 0)), v1);

    *(unsigned short*)(tag + LOW_REGION(0x484, 0xb4)) = 0xc2;
    *(unsigned short*)(tag + LOW_REGION(0x486, 0xb6)) = 0x92;

#if defined(jpn)
    func_0205cc50(tag + 0x3d0);
#else
    func_0205cc50(tag, 0, -4);
#endif

    *(unsigned char*)(tag + LOW_REGION(0x594, 0x234)) = 1;
    ResetBytesAndSetByte0x16_0205c77c((struct ResetBytesAndSetByte0x16Data*)(tag + LOW_REGION(0x3d4, 0x4)), 1);

    *(unsigned char*)(tag + LOW_REGION(0x593, 0x233)) = 1;
    *(unsigned char*)(tag + LOW_REGION(0x594, 0x234)) = 1;
    ResetBytesAndSetByte0x16_0205c77c((struct ResetBytesAndSetByte0x16Data*)(tag + LOW_REGION(0x3d4, 0x4)), 1);

    SetupGlobalObjType1AndInitSelfPointer_0205cd28(tag + LOW_REGION(0x3d0, 0));
    InitGlobalObjAndSelfPointer0205cd94(tag + LOW_REGION(0x3d0, 0));

    DispatchWithShortB4_0205eaa0((struct Obj0205eaa0*)&data_02108760, 5, 0);

#if !defined(jpn)
    short b6 = *(short*)(tag + 0xb6);
    short b8 = *(short*)(tag + 0xb8);
    *(unsigned short*)(tag + 0xb4) = 0xfe - b8;
    *(unsigned short*)(tag + 0xb6) = b6;
    func_0205cc50(tag, 0, -4);
#endif
}
