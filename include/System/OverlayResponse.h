#ifndef SYSTEM_OVERLAY_RESPONSE_H
#define SYSTEM_OVERLAY_RESPONSE_H

#include <globaldefs.h>

struct ResponseIdentifier {
    unsigned char prefix[6];
    unsigned short sequence;
};

struct ResponseHeader {
    unsigned short version;
    unsigned short unknown02[2];
    unsigned short type;
    unsigned short unknown08;
    unsigned short protocol;
    unsigned short flags;
    unsigned char unknown0e;
    unsigned char transport;
    ResponseIdentifier identifier;
    ResponseIdentifier* GetIdentifier() { return &identifier; }
};

struct ResponseBody {
    unsigned char type;
    unsigned char unknown01;
    unsigned short identifier;
    unsigned int status;
};

struct ResponsePacket {
    unsigned char unknown00[12];
    ResponseHeader header;
    ResponseBody body;
    ResponseHeader* GetHeader() { return &header; }
};

struct ResponseIdentifiers {
    ResponseIdentifier entries[3];
    ResponseIdentifier* GetFinalIdentifier() { return &entries[2]; }
};

#if defined(jpn)
#define func_ov031_0221d52c func_ov031_0221dd0c
#define func_ov031_0221d6a8 func_ov031_0221de88
#define func_ov031_0221d82c func_ov031_0221e00c
#define func_ov031_0221db48 func_ov031_0221e328
#define data_ov031_0224e720 data_ov031_0224f320
#define data_ov031_0224eda0 data_ov031_0224f9a0
#endif

extern "C" {
unsigned short func_ov031_0221e638(unsigned short);
int func_ov031_0221d7e0(ResponseIdentifier*, ResponseIdentifier*);
int func_ov031_0221d450(int, ResponsePacket*, int*, ResponseIdentifiers*);
int func_ov031_0221d52c(int, ResponsePacket*, int*, ResponseIdentifiers*);
int func_ov031_0221d604(int, ResponsePacket*, int*, ResponseIdentifiers*);
}

#endif
