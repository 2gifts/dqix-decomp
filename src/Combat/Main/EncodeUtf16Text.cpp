#include <globaldefs.h>

#include "Resource/TextEncoding.h"

extern KeyValue02032e24 data_020e74ec[];
extern KeyValue02032e24 data_020e74c8[];
extern KeyValue02032e24 data_020e74bc[];
extern KeyValue02032e24 data_020e743c[];
extern KeyValue02032e24 data_020e752c[];

// USA: func_020328bc
extern "C" ARM void func_020328bc(unsigned char *destination, unsigned short *source, unsigned short count) {
    while (*source != 0 && count-- != 0) {
        unsigned short character = *source++;
        unsigned short encoded;
        if (character == 0xa5) {
            encoded = 0x5c;
        } else if (character == 0x5c) {
            encoded = 0x815f;
        } else if (character == 0x203e) {
            encoded = 0x7e;
        } else if (character == 0xd || character == 0xa) {
            encoded = character;
        } else if (character >= 0x20 && character < 0x7e) {
            encoded = character;
        } else if (character >= 0xa2 && character <= 0xf7) {
            encoded = LookupKeyTable02032e24(character, data_020e74ec, 0xab);
        } else if (character >= 0xff61 && character <= 0xff9f) {
            encoded = character - 0xfec0;
        } else if (character == 0x4edd) {
            encoded = 0x8157;
        } else if (character >= 0xff01 && character <= 0xffe5) {
            if (character >= 0xff10 && character <= 0xff19) {
                encoded = character - 0x7cc1;
            } else if (character >= 0xff21 && character <= 0xff3a) {
                encoded = character - 0x7cc1;
            } else if (character >= 0xff41 && character <= 0xff5a) {
                encoded = character - 0x7cc0;
            } else {
                encoded = LookupKeyTable02032e24(character, data_020e74c8, 0x54);
            }
        } else if (character >= 0x3000 && character <= 0x30fe) {
            if (character >= 0x3041 && character <= 0x3093) {
                encoded = character + 0x525e;
            } else if (character >= 0x30a1 && character <= 0x30f6) {
                encoded = character + 0x529f;
                if (character >= 0x30e0) encoded++;
            } else {
                encoded = LookupKeyTable02032e24(character, data_020e74bc, 0x6c);
            }
        } else if (character >= 0x391 && character <= 0x3a9) {
            encoded = character + 0x800e;
            if (character >= 0x3a3) encoded--;
        } else if (character >= 0x3b1 && character <= 0x3c9) {
            encoded = character + 0x800e;
            if (character >= 0x3c3) encoded--;
        } else if (character == 0x401) {
            encoded = 0x8446;
        } else if (character >= 0x410 && character <= 0x42f) {
            encoded = character + 0x8030;
            if (character >= 0x416) encoded++;
        } else if (character >= 0x430 && character <= 0x44f) {
            encoded = character + 0x8040;
            if (character >= 0x436) {
                encoded++;
                if (character >= 0x43e) encoded++;
            }
        } else if (character == 0x451) {
            encoded = 0x8476;
        } else if (character >= 0x2500 && character <= 0x254b) {
            encoded = LookupKeyTable02032e24(character, data_020e743c, 0x20);
        } else if ((character >= 0x2010 && character <= 0x2312) || (character >= 0x25a0 && character <= 0x266f)) {
            encoded = LookupKeyTable02032e24(character, data_020e752c, 0xa0);
        } else {
            encoded = 0x8140;
        }
        if (encoded & 0xff00) *destination++ = encoded >> 8;
        *destination++ = encoded;
    }
}
