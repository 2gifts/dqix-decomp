#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_0202ae18(void);
extern "C" int func_0202c508(void* obj);
void* GetData02153637(void);
struct Container020e34bc;
int GetEntryStatusForKey020e34bc(struct Container020e34bc* obj, int key);
extern "C" void func_ov017_021bd5d0(void);
struct Obj020397cc;
void CancelPendingAction020397cc(struct Obj020397cc* obj, int arg1);
void Dispatch020e3428(void* a, int b);
struct Entry020e3054;
void ClearEntryIfCurrentArrMatches020e3468(struct Entry020e3054* list, int key);
void StoreInFirstEmptySlot(unsigned char* base, unsigned char val);
struct Self02154de4;
int ProcessAndDispatchState_02154de4(struct Self02154de4* self);

struct Self02155ca8 {
    char pad0[0xa];
    unsigned short field_a;
    #if defined(jpn)
    char pad1[0xf4 - 0xc];
#else
    char pad1[0xf8 - 0xc];
#endif
    unsigned int flag_f8 : 27;
    unsigned int rsv_f8 : 5;
};

// USA: func_ov001_02155ca8  (semantic: HandleEntryStatusOrProcessState_02155ca8)
extern "C" ARM int func_ov001_02155ca8(struct Self02155ca8* obj) {
    GameState* bs = GameState::GetInstance();
    void* search = func_0202ae18();
    if (obj->flag_f8 & 0x10) {
        if (func_0202c508(search) != 0) {
            void* key = GetData02153637();
            int status = GetEntryStatusForKey020e34bc((struct Container020e34bc*)key, 1);
            if (status == 1) {
                func_ov017_021bd5d0();
                CancelPendingAction020397cc((struct Obj020397cc*)bs->GetUnknownGameObject(), 1);
                Dispatch020e3428(key, 1);
            } else {
                if ((unsigned int)(status - 3) > 2) {
                    return obj->field_a;
                }
                ClearEntryIfCurrentArrMatches020e3468((struct Entry020e3054*)key, 1);
                StoreInFirstEmptySlot((unsigned char*)key, 1);
                return obj->field_a;
            }
        }
    }
    return ProcessAndDispatchState_02154de4((struct Self02154de4*)obj);
}
