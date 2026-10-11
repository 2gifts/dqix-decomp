#include <globaldefs.h>
#include "GameState/GameState.h"


extern "C" int func_020aaf84(void* ptr, int a, int b, int c);
struct StateBits5ccc_1155c;
void ClearFlag0x5cccBit0(struct StateBits5ccc_1155c* state);
unsigned char GetField0xcc0209ca98(char* obj);
unsigned char GetByteFieldAt0xcc(unsigned char* obj);
void SetModeClamped0209ca70(void* obj, int val);
struct Obj0205e9f4;
void SetStateAndDispatch0205e9f4(struct Obj0205e9f4* obj, int state);
int VerifyAndApplySaveBuffer(int flag);
extern "C" void func_ov011_021848a0(void* obj, int val);
int SendShortBufferOrReturnZero020aba5c(int flag);
int GetGlobalField0x1c020421a0(void);
void ReinitController02043204(char* obj);
extern "C" void func_02043124(char* obj);
void* GetNodeIfType6_0216ae9c(void* a, int id);
void SetOffset100Fields_021f8960(char* base, short a, short b);
void SetByte0x4(char* obj, unsigned char value);

extern unsigned char data_ov004_02171034[];
extern int data_02109bf4;
extern int data_02108760;

// USA: func_ov004_0216e490
// JPN: func_ov004_0216eb30
extern "C" ARM int func_ov004_0216e490(void* obj) {
    GameState* bs = GameState::GetInstance();
#if defined(jpn)
    data_ov004_02171034[3] = 0;
    int res = func_020aaf84(*(void**)&data_ov004_02171034[0xc], 0, 1, 0);
#else
    data_ov004_02171034[5] = 0;
    int res = func_020aaf84(*(void**)&data_ov004_02171034[0x10], 0, 1, 0);
#endif
    if (res == 0) {
        ClearFlag0x5cccBit0((struct StateBits5ccc_1155c*)bs);
#if defined(jpn)
        data_ov004_02171034[3] = 1;
#else
        data_ov004_02171034[5] = 1;
#endif
    } else {
        unsigned char v1 = GetField0xcc0209ca98((char*)&data_02109bf4);
#if defined(jpn)
        data_ov004_02171034[7] = v1;
#else
        data_ov004_02171034[4] = v1;
#endif
        unsigned char v2 = GetByteFieldAt0xcc((unsigned char*)&data_02108760);
#if defined(jpn)
        data_ov004_02171034[6] = v2;
#else
        data_ov004_02171034[1] = v2;
#endif
        SetModeClamped0209ca70(&data_02109bf4, 3);
        SetStateAndDispatch0205e9f4((struct Obj0205e9f4*)&data_02108760, 3);
        if (VerifyAndApplySaveBuffer(1) == 0) {
#if defined(jpn)
            data_ov004_02171034[3] = 1;
#else
            data_ov004_02171034[5] = 1;
#endif
        }
    }

#if defined(jpn)
    if (data_ov004_02171034[3] != 0) {
#else
    if (data_ov004_02171034[5] != 0) {
#endif
        func_ov011_021848a0(obj, 0x3e7);
        return 0;
    }
#if defined(jpn)
    if (data_ov004_02171034[1] == 1) {
#else
    if (data_ov004_02171034[0] == 1) {
#endif
        if (SendShortBufferOrReturnZero020aba5c(1) == 0) {
            char* g = (char*)GetGlobalField0x1c020421a0();
            ReinitController02043204(g);
            func_02043124(g);
            void* node = GetNodeIfType6_0216ae9c(obj, 0xd4);
            SetOffset100Fields_021f8960((char*)node, 0, 7);
            func_ov011_021848a0(obj, 0x1f5);
            return 0;
        } else {
            SetByte0x4((char*)bs, 5);
#if defined(jpn)
            data_ov004_02171034[0] = 0;
#else
            data_ov004_02171034[2] = 0;
#endif
            func_ov011_021848a0(obj, 0x3e7);
            return 0;
        }
    }
    return 0;
}
