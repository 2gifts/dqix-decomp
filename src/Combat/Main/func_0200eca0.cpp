#include <globaldefs.h>
struct Object0200eca0 {
    unsigned int field0;
    unsigned int field4;
    unsigned char* cursor;
    void* current;
    unsigned int field10;
    unsigned int field14;
    unsigned char* records;
};
struct Input0200eca0 { unsigned int field0; unsigned int field4; unsigned char* cursor; unsigned int fieldc; unsigned int field10; unsigned int field14; };
struct Output0200eca0 { int extra; unsigned int value; int offset; int entry; };
extern "C" void func_0200dad4(unsigned int, Input0200eca0*);
extern "C" void func_0200efb8();
extern "C" void func_0200f1fc(Object0200eca0*, Input0200eca0*);
extern "C" void* func_0200e830(Object0200eca0*, Input0200eca0*);
extern "C" unsigned char* func_0200ea68(Object0200eca0*, Input0200eca0*, Output0200eca0*);
extern "C" const unsigned char* func_0200d9e4(const unsigned char*, int*);
extern "C" const unsigned char* func_0200d958(const unsigned char*, int*);
extern "C" void func_0200df80(Object0200eca0*, Input0200eca0*, unsigned char*);
extern "C" void func_0200ec44(Object0200eca0*, int, int);
extern "C" void func_0200f2ec(Object0200eca0*, Input0200eca0*, unsigned int);

// USA: func_0200eca0
extern "C" ARM void func_0200eca0(Object0200eca0* object) {
    Input0200eca0 input;
    Output0200eca0 output;
    func_0200dad4(object->field10, &input);
    if (!input.field4) func_0200efb8();
    func_0200f1fc(object, &input);
    if (object->field0) object->current = 0;
    else {
        object->current = func_0200e830(object, &input);
        if (!object->current) func_0200efb8();
    }
    unsigned char* record = func_0200ea68(object, &input, &output);
    output.value = record[1] | record[2] << 8 | record[3] << 16 | record[4] << 24;
    const unsigned char* cursor = func_0200d9e4(record + 5, &output.offset);
    func_0200d958(cursor, &output.entry);
    func_0200df80(object, &input, record);
    func_0200ec44(object, output.entry, output.extra);
    func_0200f2ec(object, &input, input.field0 + output.offset);
}
