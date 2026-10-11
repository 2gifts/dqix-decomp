#include <globaldefs.h>
#include "Resource/Script.h"
#include "GameState/GameState.h"

struct DownloadDate_021f5e70
{
    unsigned int year_ : 12;
    unsigned int month_ : 4;
    unsigned int day_ : 5;
    unsigned int hour_ : 5;
    unsigned int unk_26 : 6;
};

struct DownloadedEntry_021f5e70
{
    short id_;
    char unk_2[2];
    unsigned int value_ : 7;
    unsigned int unk_4_7 : 25;
    char unk_8[0x28 - 8];
};

struct DownloadedData_021f5e70
{
    short unk_0;
    char unk_2[2];
    DownloadedEntry_021f5e70 entries_[6];
    DownloadDate_021f5e70 start_;
    short itemId_;
    char unk_fa[2];
    unsigned short price_;
    char unk_fe[2];
    DownloadDate_021f5e70 end_;
    char unk_104[8];
    unsigned short flags_ : 13;
    unsigned short unk_10c_13 : 3;
    char unk_10e[0x114 - 0x10e];
};

struct DownloadState_021f5e70
{
    unsigned char count_;
    unsigned char checked_;
    unsigned char choosing_;
    unsigned char index_;
    void* items_;
    char* quest_;
    DownloadedData_021f5e70* data_;
    const char* message_;
};

struct GameStateDownload_021f5e70
{
#if defined(jpn)
    char unk_0[0x5c0c];
#else
    char unk_0[0x5e6c];
#endif

    DownloadedData_021f5e70 downloadedData_;
};

struct RC4Context_021f5e70
{
    char unk_0[0x104];
};

extern "C" unsigned long long _Z23ComputeModHash_021f6324iPh(int size, unsigned char* data);
extern "C" void func_ov031_022118a8(RC4Context_021f5e70* context, const char* key, int length);
extern "C" void Rc4Crypt_02211938(RC4Context_021f5e70* context, const void* input, int size, void* output);

extern "C" DownloadState_021f5e70 data_ov023_021fff08;
extern "C" unsigned char data_ov023_021fff1c[];
extern "C" Script::OpcodeLookupEntry data_ov023_021fe34c[];
extern "C" unsigned char data_ov023_021fe3c8[];

// JPN: func_ov023_021f54ac
// USA: func_ov023_021f5e70
extern "C" ARM int func_ov023_021f5e70(unsigned char* data, int size, void* buffer)
{
    Script counter;
    Script script;
    if (_Z23ComputeModHash_021f6324iPh(size, data) != 0)
        return 0;
    int i;
    RC4Context_021f5e70 context;
    const char* key = (const char*)data_ov023_021fe3c8;
    func_ov031_022118a8(&context, key, strlen(key));
    Rc4Crypt_02211938(&context, data, size - 4, buffer);
    data = (unsigned char*)buffer;
    DownloadedData_021f5e70* downloaded = &((GameStateDownload_021f5e70*)GameState::GetInstance())->downloadedData_;
    data_ov023_021fff08.choosing_ = 0;
    data_ov023_021fff08.index_ = 0;
    data_ov023_021fff08.data_ = downloaded;
    counter.Initialize();
    counter.SetOpcodeLookup(data_ov023_021fe34c);
    int length = size - 4;
    counter.Load(buffer, length);
    counter.Execute();
    if (data_ov023_021fff08.index_ == 0)
        return 0;
    for (i = 0; i < 6; i++)
    {
        downloaded->entries_[i].id_ = -1;
        data_ov023_021fff1c[i] = 0xff;
    }
    data_ov023_021fff08.count_ = data_ov023_021fff08.index_;
    if (data_ov023_021fff08.count_ > 6)
        data_ov023_021fff08.count_ = 6;
    for (i = 0; i < data_ov023_021fff08.count_; i++)
    {
        short chosen = rand() % data_ov023_021fff08.index_;
        int j;
        for (j = i - 1; j >= 0; j--)
        {
            if (chosen == data_ov023_021fff1c[j])
                break;
        }
        if (j >= 0)
            i--;
        else
            data_ov023_021fff1c[i] = chosen;
    }
    data_ov023_021fff08.choosing_ = 1;
    data_ov023_021fff08.index_ = 0;
    data_ov023_021fff08.data_ = downloaded;
    script.Initialize();
    script.SetOpcodeLookup(data_ov023_021fe34c);
    script.Load(data, length);
    script.Execute();
    return 1;
}
