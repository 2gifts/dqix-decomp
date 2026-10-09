#pragma once

struct KeyValue02032e24 {
    unsigned short value;
    unsigned short key;
};

unsigned short LookupKeyTable02032e24(unsigned short key, KeyValue02032e24 *entries, int count);
extern "C" void func_020328bc(unsigned char *destination, unsigned short *source, unsigned short count);
