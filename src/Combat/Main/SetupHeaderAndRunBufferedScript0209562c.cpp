#include <globaldefs.h>
#include "Resource/Script.h"

struct HeaderStruct0209562c {
    char pad[0xa0];
    int f0xa0;
};

struct DataStruct02109404_0209562c {
    unsigned char f0;
    unsigned char pad1[2];
    unsigned char f3;
    unsigned char f4;
    unsigned char pad5[3];
    unsigned short f8;
    unsigned char pad10[2];
    unsigned int fc;
};
extern struct DataStruct02109404_0209562c data_02109404;
extern int data_020f1444;

struct ResetStruct {
    int w0;
    int w4;
    int w8;
    int wc;
    int w10;
    int w14;
    int w18;
    int w1c;
    int w20;
    int w24;
    int w28;
    char pad[0x400];
    unsigned char b42c;
};

struct StreamState;
struct StreamHeader;

struct Struct02030774;

// USA: func_0209562c
ARM void SetupHeaderAndRunBufferedScript0209562c(struct HeaderStruct0209562c* header, int param1, struct StreamHeader* buffer, int length, unsigned short param4, int param5, int param6) {
    if (param1 != 0 && buffer != 0 && length != 0) {
        data_02109404.f8 = param4;
        data_02109404.f3 = param5;
        data_02109404.f4 = param6;
        data_02109404.fc = param1;
        header->f0xa0 = 0;
        data_02109404.f0 = 0;
        struct ResetStruct local;
        ((Script*)&local)->Initialize();
        ((Script*)&local)->SetOpcodeLookup((Script::OpcodeLookupEntry*)&data_020f1444);
        ((Script*)((struct StreamState*)&local))->Load(buffer, length);
        ((Script*)((struct Struct02030774*)&local))->Execute();
    }
}
