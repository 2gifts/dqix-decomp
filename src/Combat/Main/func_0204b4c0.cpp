#include <globaldefs.h>
#include "std_library_functions.h"
struct Record0204acb0 { short h0; short h2; char b4; char b5; char pad[2]; int w8; int wc; };
struct Object0204b4c0 { char unknown0[0xc]; int fieldc[4]; unsigned char kindLow : 4; unsigned char kindHigh : 4; };
extern "C" void __clear(void*, unsigned int);
extern "C" int func_02001aec(const void*, const void*, unsigned int);
extern "C" void func_0204a9c4(Object0204b4c0*, unsigned int, unsigned int, const void*);
extern "C" void func_0204ac60(void*, unsigned int, const void*);
void ClearRecordFields(Record0204acb0*);
extern "C" void func_0204ade8(Record0204acb0*, unsigned int, unsigned int, const void*);
extern char data_020f0238[];
extern char data_020f023d[];
extern char data_020f0242[];

// USA: func_0204b4c0
extern "C" ARM void func_0204b4c0(Object0204b4c0* object, const void* data) {
    if (!data) return;
    char header[5];
    Record0204acb0 record;
    __clear(header, 5);
    memcpy(header, data, 5);
    if (func_02001aec(header, data_020f0238, 4) == 0) {
        func_0204a9c4(object, object->kindLow, object->kindHigh, data);
    } else if (func_02001aec(header, data_020f023d, 4) == 0) {
        func_0204ac60(object->fieldc, object->kindLow, data);
    } else if (func_02001aec(header, data_020f0242, 4) == 0) {
        ClearRecordFields(&record);
        func_0204ade8(&record, object->kindLow, object->kindHigh, data);
    }
}
