#if defined(jpn)
enum {regionalOffset0=0x860};
#else
enum {regionalOffset0=0x840};
#endif
#include <globaldefs.h>
#include "Resource/Script.h"

struct DownloadDate_021f5ad8
{
    unsigned int year_ : 12;
    unsigned int month_ : 4;
    unsigned int day_ : 5;
    unsigned int hour_ : 5;
    unsigned int unk_26 : 6;
};

struct DownloadedEntry_021f5ad8
{
    short id_;
    char unk_2[2];
    unsigned int value_ : 7;
    unsigned int unk_4_7 : 25;
    char unk_8[0x28 - 8];
};

struct DownloadedData_021f5ad8
{
    short unk_0;
    char unk_2[2];
    DownloadedEntry_021f5ad8 entries_[6];
    DownloadDate_021f5ad8 start_;
    short itemId_;
    char unk_fa[2];
    unsigned short price_;
    char unk_fe[2];
    DownloadDate_021f5ad8 end_;
    char unk_104[8];
    unsigned short flags_ : 13;
    unsigned short unk_10c_13 : 3;
    char unk_10e[0x114 - 0x10e];
};

struct DownloadState_021f5ad8
{
    unsigned char count_;
    unsigned char checked_;
    unsigned char choosing_;
    unsigned char index_;
    void* items_;
    char* quest_;
    DownloadedData_021f5ad8* data_;
    const char* message_;
};

struct ZoneData_021f5ad8
{
    char unk_0[regionalOffset0];
    struct Unknown_840
    {
        char unk_0[0x1b48];
        unsigned int unk_1b48;
        unsigned int unk_1b4c;
        char unk_1b50[0x11];
        unsigned char unk_1b61;
    } unk_840;
};

extern "C" ZoneData_021f5ad8* func_02012fe4();

extern "C" DownloadState_021f5ad8 data_ov023_021fff08;

// JPN: func_ov023_021f5090
// USA: func_ov023_021f5ad8
extern "C" ARM int func_ov023_021f5ad8(Script::Parameter* params, int count)
{
    ZoneData_021f5ad8::Unknown_840* zones = &func_02012fe4()->unk_840;
    for (int i = 0; i < count; i++)
    {
        int zone = params->ToInt();
        params++;
        if (!(zones->unk_1b48 & (1 << zone)))
        {
            zones->unk_1b48 |= 1 << zone;
            zones->unk_1b4c |= 1 << zone;
            zones->unk_1b61 = 1;
            data_ov023_021fff08.data_->flags_ |= 0x200;
        }
    }
    return 1;
}
