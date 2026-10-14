#include <globaldefs.h>
#include "System/Memory.h"

struct Session0220940c {
    unsigned char field_0[0x32];
    unsigned short algorithm;
    unsigned char field_34[0x1a0];
    void* secret;
    unsigned char field_1d8[0x10c];
    unsigned char sequence[8];
    unsigned char counter[8];
    unsigned char field_2f4[0x54];
    unsigned int sha1[45];
    unsigned int md5[22];
    unsigned char field_454;
    unsigned char error;
};
struct Packet0220940c { unsigned char type; unsigned char field_1[2]; unsigned char lengthHigh; unsigned char lengthLow; unsigned char payload[1]; };
struct Scratch0220940c { unsigned char padding[0x30]; unsigned char digest[0x14]; };
int CryptWithOffset1e0_022093f4(void*, void*, int);
void InitMd5Ctx_0220afe0(void*);
void FinalizeMd5_0220b0e0(void*, void*);
void InitSha1State_0220b8a0(unsigned int*);
void FinalizeSha1Digest_0220b9ac(void*, void*);
void IncrementByteCounter_022093d0(unsigned char*);
extern "C" void func_ov031_0220b028(void*, const void*, unsigned int);
extern "C" void func_ov031_0220b8f4(void*, const void*, unsigned int);
extern "C" int func_02001aec(const void*, const void*, unsigned int);

// USA: func_ov031_0220940c
extern "C" ARM int func_ov031_0220940c(Session0220940c* session, Packet0220940c* packet) {
    int size = CryptWithOffset1e0_022093f4(session, packet->payload, (packet->lengthHigh << 8) + packet->lengthLow);
    Scratch0220940c scratch;
    int digestSize;
    switch (session->algorithm) {
    case 4:
        size -= 0x10;
        packet->lengthHigh = size >> 8;
        packet->lengthLow = size;
        InitMd5Ctx_0220afe0(session->md5);
        func_ov031_0220b028(session->md5, session->secret, 0x10);
        VectorizedMemset(scratch.padding, 0x36, 0x30);
        func_ov031_0220b028(session->md5, scratch.padding, 0x30);
        func_ov031_0220b028(session->md5, session->sequence, 8);
        func_ov031_0220b028(session->md5, packet, 1);
        func_ov031_0220b028(session->md5, &packet->lengthHigh, size + 2);
        FinalizeMd5_0220b0e0(session->md5, scratch.digest);
        InitMd5Ctx_0220afe0(session->md5);
        func_ov031_0220b028(session->md5, session->secret, 0x10);
        VectorizedMemset(scratch.padding, 0x5c, 0x30);
        func_ov031_0220b028(session->md5, scratch.padding, 0x30);
        func_ov031_0220b028(session->md5, scratch.digest, 0x10);
        FinalizeMd5_0220b0e0(session->md5, scratch.digest);
        digestSize = 0x10;
        break;
    case 5:
        size -= 0x14;
        packet->lengthHigh = size >> 8;
        packet->lengthLow = size;
        InitSha1State_0220b8a0(session->sha1);
        func_ov031_0220b8f4(session->sha1, session->secret, 0x14);
        VectorizedMemset(scratch.padding, 0x36, 0x28);
        func_ov031_0220b8f4(session->sha1, scratch.padding, 0x28);
        func_ov031_0220b8f4(session->sha1, session->sequence, 8);
        func_ov031_0220b8f4(session->sha1, packet, 1);
        func_ov031_0220b8f4(session->sha1, &packet->lengthHigh, size + 2);
        FinalizeSha1Digest_0220b9ac(session->sha1, scratch.digest);
        InitSha1State_0220b8a0(session->sha1);
        func_ov031_0220b8f4(session->sha1, session->secret, 0x14);
        VectorizedMemset(scratch.padding, 0x5c, 0x28);
        func_ov031_0220b8f4(session->sha1, scratch.padding, 0x28);
        func_ov031_0220b8f4(session->sha1, scratch.digest, 0x14);
        FinalizeSha1Digest_0220b9ac(session->sha1, scratch.digest);
        digestSize = 0x14;
        break;
    }
    if (func_02001aec(packet->payload + size, scratch.digest, digestSize)) session->error = 9;
    IncrementByteCounter_022093d0(session->counter);
    return size + 5;
}
