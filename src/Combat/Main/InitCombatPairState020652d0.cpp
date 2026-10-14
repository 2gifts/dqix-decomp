#include <globaldefs.h>

void InitBigStruct0205c790(char* obj);

struct Struct_0205ba68;
void SetupPointerTable0205ba68(struct Struct_0205ba68* s, int a, int b, int mode);

struct Node0205bacc;
void SetField0AndPropagate0205bacc(struct Node0205bacc* s, int val);

void ProcessCombatEntry0205cb74(char* obj, int value);

extern "C" void func_0205cc50(void* obj, int a, int b);

int GetGlobalField0x1c020421a0(void);
void StoreClampedDeltas_0206b7b0(char* base);

struct Struct_0205bcdc;
void SetIndexIfValid0205bcdc(struct Struct_0205bcdc* s, int index);

extern "C" void func_0205bb04(void* s, int n);

struct ResetBytesAndSetByte0x16Data;
void ResetBytesAndSetByte0x16_0205c77c(struct ResetBytesAndSetByte0x16Data* p, int val);

void SetupGlobalObjType1AndInitSelfPointer_0205cd28(unsigned char* obj);

// USA: func_020652d0
ARM void InitCombatPairState020652d0(char* obj, int a, int b, int c) {
    InitBigStruct0205c790(obj);

    obj[0xb1] = 1;
    obj[0xb0] = 1;
    SetupPointerTable0205ba68((struct Struct_0205ba68*)(obj + 0x20), 1, 2, 0);
    SetupPointerTable0205ba68((struct Struct_0205ba68*)(obj + 0x70), 1, 2, 0);

    SetField0AndPropagate0205bacc((struct Node0205bacc*)(obj + 0x20), 2);
    SetField0AndPropagate0205bacc((struct Node0205bacc*)(obj + 0x70), 2);

    ProcessCombatEntry0205cb74(obj, b);
    ProcessCombatEntry0205cb74(obj, c);

    *(short*)(obj + 0xb4) = 0;
    *(short*)(obj + 0xb6) = 0;

    func_0205cc50(obj, 1, -4);
    StoreClampedDeltas_0206b7b0((char*)GetGlobalField0x1c020421a0());
    func_0205cc50(obj, 1, -4);

    SetIndexIfValid0205bcdc((struct Struct_0205bcdc*)(obj + 0x20), a);
    func_0205bb04(obj + 0x70, a);

    obj[0x234] = 1;
    ResetBytesAndSetByte0x16_0205c77c((struct ResetBytesAndSetByte0x16Data*)(obj + 0x4), 1);

    obj[0x233] = 1;
    obj[0x234] = 1;
    ResetBytesAndSetByte0x16_0205c77c((struct ResetBytesAndSetByte0x16Data*)(obj + 0x4), 1);

    SetupGlobalObjType1AndInitSelfPointer_0205cd28((unsigned char*)obj);

    int bit = (*(volatile unsigned short*)0x4000304 & 0x8000) >> 15;
    if (bit == 1) {
        obj[0xb0] = 0;
    }
}
