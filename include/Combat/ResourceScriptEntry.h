#pragma once

#include "Resource/Script.h"

struct ResourceScriptPackedTriple {
    unsigned int low : 10;
    unsigned int middle : 10;
    unsigned int high : 10;
    unsigned int reserved : 2;
};

struct ResourceScriptFields {
    unsigned int value0 : 32;
    unsigned short value4Low : 7;
    unsigned short value4High : 9;
    unsigned short unknown6;
    ResourceScriptPackedTriple value8;
    ResourceScriptPackedTriple valueC;
    ResourceScriptPackedTriple value10;
};

struct ResourceScriptEntry {
    ResourceScriptFields initial;
    ResourceScriptFields final;
    ResourceScriptFields difference;
    unsigned char variants[0x16];
};

struct Data02108ee8 {
    int field0;
    int field4;
    int field8;
    void *fieldC;
    int field10;
};

extern Data02108ee8 data_02108ee8;
extern Script::OpcodeLookupEntry data_020f0ff8[];

extern "C" int func_02082490(void *output, void *resource, unsigned int size, int selection, int extra);
