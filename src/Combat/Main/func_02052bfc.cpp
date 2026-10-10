#include <globaldefs.h>
#include "GameState/GameState.h"
#include "System/Timing.h"
#include "std_library_functions.h"

struct ArrayContainsByteStruct;

struct Inner0201bc94 {
    unsigned char lowBits : 4;
    unsigned char flag4 : 1;
    unsigned char highBits : 3;
};

struct Struct0201bc94 {
    unsigned short field0;
    unsigned short field2;
    unsigned short field4;
    unsigned short field6;
    Inner0201bc94* field8;
};

struct Sub150_02052bfc {
    char pad0[0x480];
    uint64_t stamp;
    char pad1[0x56c - 0x488];
    unsigned char field56c;
    unsigned char field56d;
};

struct Obj02052bfc {
    char pad0[4];
    short field4;
    char pad1[0x150 - 6];
    Sub150_02052bfc* field150;
};

int ArrayContainsByte(ArrayContainsByteStruct*, int);
void* GetPtrField0x2a04(GameState*);
extern "C" void* func_02012fe4(void);
extern "C" long long _ll_udiv(long long a, long long b);
int IsField0Null(void** obj);
int IsEntryEligibleAndFlagged(Struct0201bc94* obj);
int CallFunc020e0434With02153694(int value);
void* GetGlobalResetObj020d7a50(void);
extern "C" void func_020d7e10(void* receiver, void* input, int style, int flag7,
                              unsigned char ignoreDuplicates, unsigned char flag6);
extern "C" void func_ov017_02191aac(char* obj, int mode, int idx, unsigned char mask);
void EnqueueEventTag17_021ce014(int a, unsigned short b, unsigned short c, unsigned short d);

// USA: func_02052bfc
extern "C" ARM void func_02052bfc(struct Obj02052bfc* obj) {
    if (obj->field150 == NULL) return;

    GameState* gs = GameState::GetInstance();
    GameResources* ov = func_ov017_0218b5b0();
    void* list = *(void**)((char*)ov + 0x3000 + 0x6fc);
    ArrayContainsByteStruct* arr = (ArrayContainsByteStruct*)GetPtrField0x2a04(gs);
    Struct0201bc94* entry = (Struct0201bc94*)func_02012fe4();
    unsigned char idx = obj->field4 & 0xff;

    if (!ArrayContainsByte(arr, idx)) return;
    if (obj->field150->field56c == 0) return;

    uint64_t diff = GetCurrentTimestamp() - obj->field150->stamp;
    long long elapsed = _ll_udiv(diff << 6, 0x1ff6210);

    if (!IsField0Null((void**)list)) return;
    if (elapsed < 0x12c && IsEntryEligibleAndFlagged(entry)) return;

    char buf[0x80];
    obj->field150->field56c = 0;
    if (idx == *(short*)((char*)gs->GetUnknownGameObject() + 4)) {
        if (obj->field150->field56d != 0) {
            strcpy(buf, (char*)CallFunc020e0434With02153694(0x33));
        }
        else {
            strcpy(buf, (char*)CallFunc020e0434With02153694(0x32));
        }
        func_020d7e10(GetGlobalResetObj020d7a50(), buf, 0, 0, 1, 1);
    }
    func_ov017_02191aac((char*)ov, 0, idx, 2);
    EnqueueEventTag17_021ce014(0, 1, 0, idx);
}
