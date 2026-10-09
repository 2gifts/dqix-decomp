#pragma once

#include <globaldefs.h>

struct NameTable02048080
{
    int count;
    void* entries;
};

struct Foo02048004
{
    unsigned int word0;
    unsigned short f4;
    unsigned short f6;
    unsigned int w8;
    unsigned int wc;
    unsigned int w10;
    NameTable02048080 nameTable;
    unsigned int words1c[25];
    unsigned short field80;
    unsigned short field82;
    unsigned char bit0 : 1;
    unsigned char bit1 : 1;
    unsigned char bit2 : 1;
    unsigned char rest : 5;
};

struct ZoneLootableRecord
{
    unsigned short id;
    short field2;
    short field4;
    unsigned char reserved6[2];
    Foo02048004 blocks[6];
    unsigned char tail338[0x30];
};

void CopyFieldsWithFlags02048004(Foo02048004* src, Foo02048004* dst);
void MaybeInvoke0204719c(Foo02048004* obj);
void ClearNameTable(NameTable02048080* table);
extern "C" void func_0204719c(void* obj);

typedef char Foo02048004SizeMustBe88[(sizeof(Foo02048004) == 0x88) ? 1 : -1];
typedef char ZoneLootableRecordSizeMustBe368[(sizeof(ZoneLootableRecord) == 0x368) ? 1 : -1];
