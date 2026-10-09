#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"

extern "C" unsigned long long _Z23ComputeModHash_021f6324iPh(int count, unsigned char* ptr);
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

struct Data021fff08_021f6058 { char pad[0x8]; char* quest; char* data; };
extern struct Data021fff08_021f6058 data_ov023_021fff08;

struct Downloaded_021f6058 {
    char pad[0x10c];
    unsigned short flags : 13;
    unsigned short unk_10c_13 : 3;
};

// USA: func_ov023_021f6058
extern "C" ARM int func_ov023_021f6058(unsigned char* buf, int len, unsigned char* out) {
    char local[0x430];
    if (_Z23ComputeModHash_021f6324iPh(len, buf) != 0) {
        return 0;
    }
    char ctx[0x104];
    char* key = (char*)data_ov023_021fe3c8;
    int keylen = strlen(key);
    func_ov031_022118a8(ctx, (unsigned char*)key, keylen);
    Rc4Crypt_02211938((unsigned char*)ctx, buf, len - 4, out);
    char* bs = (char*)GameState::GetInstance();
    Downloaded_021f6058* d = (Downloaded_021f6058*)(bs + 0x5e6c);
    buf = (unsigned char*)bs + 0x6380;
    data_ov023_021fff08.data = (char*)d;
    data_ov023_021fff08.quest = (char*)buf;
    d->flags &= ~0x240;
    _ZN6Script10InitializeEv((struct ResetStruct*)local);
    _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE((struct ResetStruct*)local, &data_ov023_021fe34c);
    _ZN6Script4LoadEPKvj((struct StreamState*)local, (struct StreamHeader*)out, len - 4);
    _ZN6Script7ExecuteEv((struct Struct02030774*)local);
    return 1;
}
