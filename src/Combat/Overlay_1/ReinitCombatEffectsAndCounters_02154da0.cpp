#include <globaldefs.h>

struct EffectParam020708c8;

int GetGlobalField0x1c020421a0();
void ReinitController02043204(char* obj);
extern "C" void func_02043124(char* obj);
extern "C" void* func_020704fc(void);
void SetScaledEffectParam020708c8(struct EffectParam020708c8* obj, unsigned int value);
extern "C" void* func_ov017_0218b5b0(void);
struct GameResources;
void SetBrightness(GameResources*, int, int);

#if defined(jpn)
enum { effectCounterOffset = 0x17ee };
#else
enum { effectCounterOffset = 0x19be };
#endif

// USA: func_ov001_02154da0  (semantic: ReinitCombatEffectsAndCounters_02154da0)
extern "C" ARM void func_ov001_02154da0() {
    char* obj = (char*)GetGlobalField0x1c020421a0();
    ReinitController02043204(obj);
    func_02043124(obj);
    *(unsigned char*)(obj + effectCounterOffset) = 0;
    SetScaledEffectParam020708c8((struct EffectParam020708c8*)func_020704fc(), 0);
    SetBrightness((GameResources*)func_ov017_0218b5b0(), -16, 0);
}
