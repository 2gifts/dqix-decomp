#include <globaldefs.h>

#include "GameState/GameState.h"



extern int data_02108760;

struct Outer020e28dc;
int GetInnerFlagBit0020e28dc(struct Outer020e28dc* o);

struct Ctx020e263c;
void UpdateEntryStateAndPosition(struct Ctx020e263c* obj, int value);


struct Obj0205eaa0;
void DispatchWithShortB4_0205eaa0(struct Obj0205eaa0* obj, int a, int b);

struct Clamp020e29a8;
void ClampFieldTo2At0x16(struct Clamp020e29a8* p, int v);

struct Obj020e280c;
void ResetAndReposition020e280c(struct Obj020e280c* self, void* b);

int GetField0x15UnlessInactive(signed char* param);

int IsFlag0x2Active020e2984(void);

struct Obj020e25e8;
void ResetSelectionState020e25e8(struct Obj020e25e8* obj);

// USA: func_ov003_0215bf18
// JPN: func_ov003_0215d230
extern "C" ARM int func_ov003_0215bf18(void* p, int arg1) {
    char* obj = (char*)p;
    if (*(void**)(obj + 0x570) != 0 && GetInnerFlagBit0020e28dc((struct Outer020e28dc*)*(void**)(obj + 0x570)) != 0) {
        GameState* bs = GameState::GetInstance();
        int count = bs->GetTickCount();
        UpdateEntryStateAndPosition((struct Ctx020e263c*)*(void**)(obj + 0x570), count);
    }
    unsigned char state = *(unsigned char*)(obj + 0x581);
    if (state == 0) {
        DispatchWithShortB4_0205eaa0((struct Obj0205eaa0*)&data_02108760, 5, 0);
        ClampFieldTo2At0x16((struct Clamp020e29a8*)*(void**)(obj + 0x570), (signed char)arg1);
        ResetAndReposition020e280c((struct Obj020e280c*)*(void**)(obj + 0x570), (void*)-1);
        *(unsigned char*)(obj + 0x581) = *(unsigned char*)(obj + 0x581) + 1;
    }
    if (state == 1) {
        *(unsigned char*)(obj + 0x59f) |= 1;
        int result = GetField0x15UnlessInactive((signed char*)*(void**)(obj + 0x570));
        if (result >= 0) {
            *(unsigned char*)(obj + 0x581) = 0;
            *(unsigned char*)(obj + 0x59f) &= ~1;
            ResetSelectionState020e25e8((struct Obj020e25e8*)*(void**)(obj + 0x570));
            return result;
        }
        (void)*(struct Outer020e28dc* volatile*)(obj + 0x570);
        if (IsFlag0x2Active020e2984()) {
            *(unsigned char*)(obj + 0x581) = 0;
            *(unsigned char*)(obj + 0x59f) &= ~1;
            ResetSelectionState020e25e8((struct Obj020e25e8*)*(void**)(obj + 0x570));
            return -2;
        }
    }
    return -1;
}
