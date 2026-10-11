#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "GameState/GameState.h"

int SendShortBufferOrReturnZero020aba5c(int flag);
int GetGlobalField0x1c020421a0(void);
void ReinitController02043204(char* obj);
extern "C" void func_02043124(char* obj);
void* GetNodeIfType6_0216ae9c(void* a, int id);
void SetOffset100Fields_021f8960(char* base, short a, short b);
extern "C" void func_ov011_021848a0(void* obj, int val);
void SetByte0x7f70(void* obj, unsigned char value);

// USA: func_ov004_0216e414  (semantic: SendOrReinitAndNotify_0216e414)
extern "C" ARM int func_ov004_0216e414(void* obj) {
    if (SendShortBufferOrReturnZero020aba5c(1) == 0) {
        char* g = (char*)GetGlobalField0x1c020421a0();
        ReinitController02043204(g);
        func_02043124(g);
        void* node = GetNodeIfType6_0216ae9c(obj, 0xd4);
        SetOffset100Fields_021f8960((char*)node, 0, 7);
        func_ov011_021848a0(obj, 0x1f5);
    } else {
        SetByte0x7f70((void*)GameState::GetInstance(), 1);
        func_ov011_021848a0(obj, 0x3e7);
    }
    return 0;
}
