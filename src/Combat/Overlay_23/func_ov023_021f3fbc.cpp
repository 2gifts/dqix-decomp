#if defined(jpn)
enum {regionalOffset0=0xe28, regionalOffset1=0x5778};
#else
enum {regionalOffset0=0xeac, regionalOffset1=0x5588};
#endif
#include <globaldefs.h>
#include "GameState/GameState.h"

int IsAnimationActive0209ca2c(void* obj);
extern "C" void func_ov023_021d8af8(void* obj);
extern "C" void* func_0202ae18(void);
int CheckField0NonZero(int* obj);
void* GetPtrField0x2a04(GameState*);
extern "C" void func_ov017_021cc730(int id, unsigned char arg1, unsigned char arg2, unsigned char arg3);
int GetGlobalField0x1c020421a0(void);
void ReinitController02043204(char* obj);
extern "C" void func_02043124(char* obj);
void* GetDataPtr02114e04_020d6c00(void);
struct FlagWord020466f4;
void ClearFlags020466f4(struct FlagWord020466f4*, unsigned int);
void SetFieldsAndSignalData02184220(void* p, int val);
struct Actor0209c678;
void DispatchContextByState0209c678(struct Actor0209c678*, int);
void PopStack1AndTrigger(int);

extern char data_02109bf4;

// JPN: func_ov023_021f3648
// USA: func_ov023_021f3fbc  (semantic: ResetAndDispatchIfIdle_021f3fbc)
extern "C" ARM int func_ov023_021f3fbc(char* obj) {
    if (IsAnimationActive0209ca2c(&data_02109bf4)) {
        return *(int*)(obj + regionalOffset0);
    }

    if (*(void**)(obj + regionalOffset1) != 0) {
        func_ov023_021d8af8(*(void**)(obj + regionalOffset1));
        *(void**)(obj + regionalOffset1) = 0;
    }

    if (CheckField0NonZero((int*)func_0202ae18())) {
        GameState* battleStruct = GameState::GetInstance();
        unsigned char* list = (unsigned char*)GetPtrField0x2a04(battleStruct);
        for (int i = 0; i < list[0xf7c]; i++) {
            unsigned char* p = list + i;
            func_ov017_021cc730(p[0xf78], 0, 0, 1);
        }
    }

    int g = GetGlobalField0x1c020421a0();
    ReinitController02043204((char*)g);
    func_02043124((char*)g);
    ClearFlags020466f4((struct FlagWord020466f4*)GetDataPtr02114e04_020d6c00(), 0x20000);
    SetFieldsAndSignalData02184220(obj, 4);
    DispatchContextByState0209c678((struct Actor0209c678*)&data_02109bf4, 0);
    PopStack1AndTrigger(1);
    return *(int*)(obj + regionalOffset0);
}
