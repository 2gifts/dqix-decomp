#include <globaldefs.h>

struct SearchStruct0202c1a4;
int GetSearchStructCurrentArrEntry(struct SearchStruct0202c1a4*);
extern "C" void* func_0205ec34(void);
void SetField5cb0AndRecordByte0_02010774(char* obj, int v);
void SetField5cb4AndRecordByte1_020107a8(char* obj, int v);
void SetSlotByte020107dc(char* base, int val);
void ClearRegions0206e080(char* base, int index);
void ClearIndexedEntryFields0206e0d0(char* base, int index);
void SetOrClearBitInArray_0206df6c(void* unused, unsigned char* array, int bit, int value);

struct Obj021ce174 {
    char pad0[4];
    unsigned char caseSel : 7;
    unsigned char flag7 : 1;
    short val6;
    unsigned short bit8;
};

// USA: func_ov017_021ce174  (semantic: DispatchSlotAction_021ce174)
extern "C" ARM void func_ov017_021ce174(void* unused, struct Obj021ce174* obj, char* target, int unused2, struct SearchStruct0202c1a4* search) {
    if (!obj->flag7) {
        if (GetSearchStructCurrentArrEntry(search) == 0) {
            return;
        }
    }

    unsigned char* base = (unsigned char*)func_0205ec34();

    switch (obj->caseSel) {
    case 0:
        SetField5cb0AndRecordByte0_02010774(target, obj->val6);
        SetField5cb4AndRecordByte1_020107a8(target, 1);
        SetSlotByte020107dc(target, 1);
        ClearRegions0206e080((char*)base, base[0x332]);
        break;
    case 1:
        SetField5cb4AndRecordByte1_020107a8(target, obj->val6);
        SetSlotByte020107dc(target, 1);
        ClearIndexedEntryFields0206e0d0((char*)base, base[0x332]);
        break;
    case 2:
        SetSlotByte020107dc(target, obj->val6);
        break;
    case 3:
        SetOrClearBitInArray_0206df6c(base, base + 0x8c, obj->bit8, obj->val6);
        break;
    case 4:
        SetOrClearBitInArray_0206df6c(base, base + base[0x332] * 0x1c + 0x3, obj->bit8, obj->val6);
        break;
    case 5:
        SetOrClearBitInArray_0206df6c(base, base + base[0x332] * 0x1c + 0x10, obj->bit8, obj->val6);
        break;
    default:
        break;
    }
}
