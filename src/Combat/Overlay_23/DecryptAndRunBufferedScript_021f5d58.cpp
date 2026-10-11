#include <globaldefs.h>
#if defined(jpn)
#include "Filesystem/FileIO.h"
extern const char data_ov023_021fd69d[];
extern const char data_ov023_021fd6a5[];
#endif
#include "std_library_functions.h"
#include "GameState/GameState.h"

unsigned long long ComputeModHash_021f6324(int count, unsigned char* ptr);
extern "C" void func_ov031_022118a8(void* ctx, unsigned char* key, int keylen);
extern "C" void Rc4Crypt_02211938(unsigned char* ctx, const unsigned char* in, int len, unsigned char* out);
extern unsigned char data_ov023_021fe3c8[];

struct ResetStruct;
extern "C" int _ZN6Script10InitializeEv(struct ResetStruct* s);
struct StreamState;
struct StreamHeader;
extern "C" int _ZN6Script4LoadEPKvj(struct StreamState* s, struct StreamHeader* buffer, int length);
struct Struct02030774;
extern "C" int _ZN6Script7ExecuteEv(struct Struct02030774* p);
extern "C" void _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(struct ResetStruct*, int*);
extern int data_ov023_021fe34c;

struct Data021fff08_021f5d58 { char pad[0xc]; void* fieldC; void* field10; };
extern struct Data021fff08_021f5d58 data_ov023_021fff08;

// JPN: func_ov023_021f5344
// USA: func_ov023_021f5d58  (semantic: DecryptAndRunBufferedScript_021f5d58)
extern "C" ARM int func_ov023_021f5d58(unsigned char* buf, int len, unsigned char* out) {
    if (ComputeModHash_021f6324(len, buf) != 0) {
        return 0;
    }
    char local[0x430];
    char ctx[0x104];
    char* key = (char*)data_ov023_021fe3c8;
    int keylen = strlen(key);
    func_ov031_022118a8(ctx, (unsigned char*)key, keylen);
    Rc4Crypt_02211938((unsigned char*)ctx, buf, len - 4, out);
    char* bs = (char*)GameState::GetInstance();
#if defined(jpn)
    data_ov023_021fff08.fieldC = bs + 0x5c0c;
#else
    data_ov023_021fff08.fieldC = bs + 0x5e6c;
#endif

    data_ov023_021fff08.field10 = 0;
#if defined(jpn)
    const void* file;
    unsigned int size;
    if (!GetFileInNarc(out, data_ov023_021fd69d, &file, &size, 0)) return 0;
#endif
    _ZN6Script10InitializeEv((struct ResetStruct*)local);
    _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE((struct ResetStruct*)local, &data_ov023_021fe34c);
#if defined(jpn)
    _ZN6Script4LoadEPKvj((struct StreamState*)local, (struct StreamHeader*)file, size);
#else
    _ZN6Script4LoadEPKvj((struct StreamState*)local, (struct StreamHeader*)out, len - 4);
#endif

    _ZN6Script7ExecuteEv((struct Struct02030774*)local);
#if defined(jpn)
    char* str = (char*)data_ov023_021fff08.field10;
    if (str == 0) return 0;
    memcpy(bs + 0x5d20, str, strlen(str));
    if (!GetFileInNarc(out, data_ov023_021fd6a5, &file, &size, 0)) return 0;
    memcpy(bs + 0x5f20, file, size);
    *(unsigned int*)(bs + 0x5d1c) = size;

#else
    if (data_ov023_021fff08.field10 == 0) {
        return 0;
    }
    memset(bs + 0x5f80, 0, 0x200);
    char* str = (char*)data_ov023_021fff08.field10;
    memcpy(bs + 0x5f80, str, strlen(str));

#endif
    return 1;
}
