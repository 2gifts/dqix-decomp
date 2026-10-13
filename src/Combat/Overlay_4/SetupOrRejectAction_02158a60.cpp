#include <globaldefs.h>

#if defined(jpn)
extern "C" void func_020e207c(void*, char*, int);
struct Obj02046574;
void SetIndexedName02046574(Obj02046574*, int, char*);
#endif

#include "GameState/GameState.h"

struct Struct021707d8_02158a60 { char pad[8]; char* ptr; };
extern Struct021707d8_02158a60 data_ov004_021707d8;

int GetGlobalField0x1c020421a0(void);
extern "C" void func_02046380(void* g);

struct Container020dedd0;
struct Element020de650;
extern "C" struct Container020dedd0* func_ov004_02156fd4(void* obj, int key);
struct Element020de650* FindElementByKey020dedd0(struct Container020dedd0* c, int key);
int CallFunc020e52a0(void* p, int key);

extern "C" void func_ov011_021848a0(void* obj, int val);
extern "C" void* func_0202ae18(void);
extern "C" int func_0202c540(void* p);
int CheckField0NonZero(int* obj);

struct DownloadedRecord02158a60 {
    unsigned char unknown00[0xf8];
    short itemId;
    unsigned short unknownFA;
    unsigned char unknownFC[0x10];
    unsigned short flags : 13;
    unsigned short unknownFlags : 3;
    unsigned char unknown10E[2];
};

struct GameStateDownloadView02158a60 {
#if defined(jpn)
    unsigned char unknown00[0x5c0c];
#else
    unsigned char unknown00[0x5e6c];
#endif
    DownloadedRecord02158a60 downloaded;
};

// USA: func_ov004_02158a60  (semantic: SetupOrRejectAction_02158a60)
extern "C" ARM int func_ov004_02158a60(void* obj) {
    DownloadedRecord02158a60* downloaded = &((GameStateDownloadView02158a60*)GameState::GetInstance())->downloaded;
    short a = downloaded->itemId;
    if (a > 0 || downloaded->unknownFA != 0) {
        void* g = (void*)GetGlobalField0x1c020421a0();
        func_02046380(g);
        struct Container020dedd0* node = func_ov004_02156fd4(obj, 5);
        struct Element020de650* elem = FindElementByKey020dedd0(node, downloaded->itemId);
#if defined(jpn)
        char name[80];
        func_020e207c(data_ov004_021707d8.ptr + 0x8c, name, *(short*)((char*)elem + 0x18));
        SetIndexedName02046574((Obj02046574*)g, 1, name);
#else
        int val = CallFunc020e52a0(data_ov004_021707d8.ptr + 0x8c, *(short*)((char*)elem + 0x18));
        *(int*)((char*)g + 0x18) = val;
#endif
        func_ov011_021848a0(obj, 0x3a3);
        return 0;
    }

    void* s = func_0202ae18();
    if (func_0202c540(s) != 0) {
        func_ov011_021848a0(obj, 0x3ae);
        return 0;
    }
    if (CheckField0NonZero((int*)s) != 0) {
        func_ov011_021848a0(obj, 0x24cd);
        return 0;
    }
    if (downloaded->flags & 0x10) {
        func_ov011_021848a0(obj, 0x3a6);
        return 0;
    }
    func_ov011_021848a0(obj, 0x3b0);
    return 0;
}
