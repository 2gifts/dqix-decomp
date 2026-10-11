#include <globaldefs.h>
#if defined(jpn)
#define data_020e93fc data_020e9508
#define func_020c0cd0 func_020c279c
#endif

#if defined(jpn)
#define func_020c0c3c func_020c2708
#endif

struct HashDesc020c0c3c {
    unsigned int words[7];
};
extern HashDesc020c0c3c data_020e93fc;

struct Sha1Ctx020c089c;
void InitSha1Context020c089c(struct Sha1Ctx020c089c* ctx);
struct HashCtx020c08ec;
void HashUpdate020c08ec(struct HashCtx020c08ec* ctx, const unsigned char* src, unsigned int len);
extern "C" void func_020c0a40(void);
extern "C" void func_020c0cd0(void* a, void* b, void* c, void* d, void* e, HashDesc020c0c3c* desc);

// USA: func_020c0c3c  (semantic: SomeHashWrapper_020c0c3c)
extern "C" ARM void func_020c0c3c(void* a, void* b, void* c, void* d, void* e) {
    unsigned char digestBuffer[0x14];
    HashDesc020c0c3c desc = data_020e93fc;
    unsigned char ctxBuffer[0x68];
    desc.words[2] = (unsigned int)ctxBuffer;
    desc.words[3] = (unsigned int)digestBuffer;
    desc.words[4] = (unsigned int)InitSha1Context020c089c;
    desc.words[5] = (unsigned int)HashUpdate020c08ec;
    desc.words[6] = (unsigned int)func_020c0a40;
    func_020c0cd0(a, b, c, d, e, &desc);
}
