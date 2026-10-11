#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void __clear(void* buf, int size);
extern "C" void func_02042764(char* name, void* buf, int flag);
extern "C" void func_ov017_0219558c(unsigned char* obj, int value);

struct SearchStruct0202c1a4;
signed char GetSearchStructCurrentArrEntry(struct SearchStruct0202c1a4* obj);
extern "C" void _Z33SetSearchBitAndClearFlag_021954c4Pvi(void* obj, int bitIdx);
extern "C" void _Z28SetNameSlotAndClear_0219541cPviPc(void* obj, int idx, char* namePtr);
extern "C" void _Z29SetBitField_021afae8_021afae8Phi(unsigned char* obj, int value);
extern "C" void _Z29SetBitField_021afafc_021afafcPhi(unsigned char* obj, int value);
extern "C" void _Z22SetIntField28_021afb10Pv(void* obj);
extern "C" void _Z22SetIntField30_021afb1cPv(void* obj);
extern "C" void _Z22SetIntField34_021afb28Pv(void* obj);
extern "C" void _Z34SetStatusBitWithPeerCheck_021afb34Pvi(void* obj, int value);
extern "C" void _Z23SetByteField2c_021afb84Pvi(void* obj, int v);

struct Evt021d0bd4 {
    unsigned char tag;
    unsigned char pad1[3];
    unsigned short mode;
    unsigned short slot;
    char name[12];
};

struct NameSlot021d0bd4 {
    unsigned char slot;
    unsigned char flag;
    char name[14];
};

// JPN: func_ov017_021d1068
// USA: func_ov017_021d0bd4
extern "C" ARM void func_ov017_021d0bd4(int value, Evt021d0bd4* evt, int unused, unsigned char* obj, struct SearchStruct0202c1a4* search) {
#if defined(jpn)
 enum {regionalOffset0=0x910, regionalOffset1=0x13c, regionalOffset2=0xc};
#else
 enum {regionalOffset0=0xb30, regionalOffset1=0x35c, regionalOffset2=0x30};
#endif
    unsigned char* status = *(unsigned char**)(obj + 0x3000 + regionalOffset0);
    switch (evt->mode) {
    case 0: {
        _Z33SetSearchBitAndClearFlag_021954c4Pvi(obj, evt->slot);
        NameSlot021d0bd4 slotName;
        slotName.slot = evt->slot;
        slotName.flag = 1;
        strcpy(slotName.name, evt->name);
        _Z28SetNameSlotAndClear_0219541cPviPc(obj, evt->slot, (char*)&slotName);
        unsigned char* entry = obj + regionalOffset1 + 0x4000 + evt->slot * regionalOffset2;
        if (entry == 0) break;
#if defined(jpn)
        strcpy((char*)entry, evt->name);
#else
        char nameBuf[regionalOffset2];
        __clear(nameBuf, regionalOffset2);
        func_02042764(evt->name, nameBuf, 1);
        strcpy((char*)entry, nameBuf);
#endif

        break;
    }
    case 1:
        if (GetSearchStructCurrentArrEntry(search) == 0) {
            _Z29SetBitField_021afae8_021afae8Phi(status, (unsigned char)value);
        }
        break;
    case 2:
        if (GetSearchStructCurrentArrEntry(search) == 0) {
            _Z29SetBitField_021afafc_021afafcPhi(status, (unsigned char)value);
        }
        break;
    case 3:
        if (status[9] == 2) {
            _Z22SetIntField28_021afb10Pv(status);
        }
        break;
    case 4:
        _Z22SetIntField30_021afb1cPv(status);
        break;
    case 5:
        _Z22SetIntField34_021afb28Pv(status);
        break;
    case 6:
        _Z34SetStatusBitWithPeerCheck_021afb34Pvi(status, (unsigned char)value);
        break;
    case 7:
        _Z23SetByteField2c_021afb84Pvi(status, 2);
        break;
    case 8:
        _Z23SetByteField2c_021afb84Pvi(status, 1);
        break;
    case 9:
        func_ov017_0219558c(obj, value);
        break;
    }
}
