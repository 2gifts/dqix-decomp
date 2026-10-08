#pragma once

struct InitStruct02075cdcStruct {
    int f00;
    int f04;
    int f08;
    int f0c;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    int f28;
    int f2c;
    short f30;
    short pad32;
    int f34;
    int f38;
    int f3c;
    int f40;
    int f44;
    int f48;
    int f4c;
    int f50;
    int f54;
    int f58;
    short f5c;
    unsigned char f5e;
    unsigned char f5f;
    int f60;
    int f64;
    int f68;
    int f6c;
};

void InitStruct02075cdc(InitStruct02075cdcStruct *resource);

extern "C" int func_02076738(InitStruct02075cdcStruct *resource, const unsigned char *stream, int length);
