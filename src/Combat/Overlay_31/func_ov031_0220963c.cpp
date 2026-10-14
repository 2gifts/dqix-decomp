#include <globaldefs.h>
#include "System/Memory.h"

struct RecordContext0220963c {
    unsigned char padding_0[0x32];
    unsigned short algorithm;
    unsigned char padding_34[0x88];
    unsigned char* secret;
    unsigned char padding_c0[8];
    unsigned char cipher[0x104];
    unsigned char sequence[8];
    unsigned char counter[8];
    unsigned char padding_1dc[0x16c];
    unsigned int sha1[23];
    unsigned char padding_3a4[0x58];
    unsigned int md5[22];
};

struct Record0220963c {
    unsigned char type;
    unsigned char majorVersion;
    unsigned char minorVersion;
    unsigned char lengthHigh;
    unsigned char lengthLow;
    unsigned char payload[1];
};

void InitMd5Ctx_0220afe0(void*);
void FinalizeMd5_0220b0e0(void*, void*);
void InitSha1State_0220b8a0(unsigned int*);
void FinalizeSha1Digest_0220b9ac(void*, void*);
void IncrementByteCounter_022093d0(unsigned char*);
extern "C" void func_ov031_0220b028(void*, const void*, unsigned int);
extern "C" void func_ov031_0220b8f4(void*, const void*, unsigned int);
extern "C" void func_ov031_0220bab8(void*, void*, unsigned int);

// USA: func_ov031_0220963c
extern "C" ARM int func_ov031_0220963c(RecordContext0220963c* context, Record0220963c* record) {
    unsigned char pad[0x30];
    unsigned char* payload = record->payload;
    int length = (record->lengthHigh << 8) + record->lengthLow;
    switch (context->algorithm) {
    case 4:
        InitMd5Ctx_0220afe0(context->md5);
        func_ov031_0220b028(context->md5, context->secret, 16);
        VectorizedMemset(pad, 0x36, 0x30);
        func_ov031_0220b028(context->md5, pad, 0x30);
        func_ov031_0220b028(context->md5, context->sequence, 8);
        func_ov031_0220b028(context->md5, record, 1);
        func_ov031_0220b028(context->md5, &record->lengthHigh, length + 2);
        FinalizeMd5_0220b0e0(context->md5, payload + length);
        InitMd5Ctx_0220afe0(context->md5);
        func_ov031_0220b028(context->md5, context->secret, 16);
        VectorizedMemset(pad, 0x5c, 0x30);
        func_ov031_0220b028(context->md5, pad, 0x30);
        func_ov031_0220b028(context->md5, payload + length, 16);
        FinalizeMd5_0220b0e0(context->md5, payload + length);
        length += 16;
        break;
    case 5:
        InitSha1State_0220b8a0(context->sha1);
        func_ov031_0220b8f4(context->sha1, context->secret, 20);
        VectorizedMemset(pad, 0x36, 0x28);
        func_ov031_0220b8f4(context->sha1, pad, 0x28);
        func_ov031_0220b8f4(context->sha1, context->sequence, 8);
        func_ov031_0220b8f4(context->sha1, record, 1);
        func_ov031_0220b8f4(context->sha1, &record->lengthHigh, length + 2);
        FinalizeSha1Digest_0220b9ac(context->sha1, payload + length);
        InitSha1State_0220b8a0(context->sha1);
        func_ov031_0220b8f4(context->sha1, context->secret, 20);
        VectorizedMemset(pad, 0x5c, 0x28);
        func_ov031_0220b8f4(context->sha1, pad, 0x28);
        func_ov031_0220b8f4(context->sha1, payload + length, 20);
        FinalizeSha1Digest_0220b9ac(context->sha1, payload + length);
        length += 20;
        break;
    }
    record->lengthHigh = length >> 8;
    record->lengthLow = length;
    func_ov031_0220bab8(context->cipher, record->payload, length);
    IncrementByteCounter_022093d0(context->counter);
    return length + 5;
}
