#include <globaldefs.h>
#include "GameState/GameState.h"

struct PackedField017 {
    unsigned int low : 12;
    unsigned int f12 : 4;
    unsigned int f16 : 5;
    unsigned int f21 : 5;
    unsigned int top : 6;
};

struct DownloadedEntry {
    short id;
    unsigned short unknown02;
    unsigned int value : 7;
    unsigned int unknown04 : 25;
    unsigned char unknown08[0x20];
};

struct DownloadedData {
    short unknown00;
    unsigned short unknown02;
    DownloadedEntry entries[6];
    PackedField017 start;
    short itemId;
    unsigned short unknownFA;
    unsigned short price;
    unsigned short unknownFE;
    PackedField017 end;
    PackedField017 timestamp;
    unsigned int unknown108;
    unsigned short flags : 13;
    unsigned short unknownFlags : 3;
    unsigned short unknown10E;
};

extern "C" void func_ov011_021848a0(void* obj, int val);

// KEEP-NAME
// USA: func_ov004_0215c900
// JPN: func_ov004_0215d900
ARM int CheckBitAndNotify_0215c900(void* obj) {
#if defined(jpn)
    const DownloadedData* data = (const DownloadedData*)((const char*)GameState::GetInstance() + 0x5c0c);
#else
    const DownloadedData* data = (const DownloadedData*)((const char*)GameState::GetInstance() + 0x5e6c);
#endif
    if (data->flags & 0x20) {
        func_ov011_021848a0(obj, 2);
    } else {
        func_ov011_021848a0(obj, 1);
    }
    return 0;
}
