#include <globaldefs.h>

extern "C" void* func_ov017_0218b5b0(void);
void Init021a6be4(unsigned char* self);
struct TailList020469b4;
struct TailNode020469b4;
void AppendNodeToTail(struct TailList020469b4* list, struct TailNode020469b4* node);

#if defined(jpn)
static const int kList=0x4ec, kNode=0x970, kFirst=0x41fe, kSecond=0x4200;
#else
static const int kList=0x6fc, kNode=0xb90, kFirst=0x44ae, kSecond=0x44b0;
#endif

// USA: func_ov017_021a6b9c
ARM void Something_021a6b9c(int unused0, unsigned char byteVal) {
    unsigned char* base = (unsigned char*)func_ov017_0218b5b0();
    unsigned char* p2 = *(unsigned char**)(base + 0x3000 + kList);
    unsigned char* p1 = *(unsigned char**)(base + 0x3000 + kNode);
    Init021a6be4(p1);
    p1[0x10] = byteVal;
    AppendNodeToTail((struct TailList020469b4*)p2, (struct TailNode020469b4*)p1);
    *(unsigned short*)(base + kFirst) = 0;
    *(unsigned short*)(base + kSecond) = 0;
}
