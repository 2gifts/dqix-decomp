#include <globaldefs.h>

#if defined(jpn)
enum { flagOffset = 0x40c2, listOffset = 0x4ec, contextOffset = 0x508, resetOffset = 0x7ee };
#else
enum { flagOffset = 0x42e2, listOffset = 0x6fc, contextOffset = 0x718, resetOffset = 0x9be };
#endif

extern "C" void* func_ov017_0218b5b0(void);
extern "C" void func_02046a8c(int a, int b);
extern "C" void* func_020704fc(void);
extern "C" void _Z28SetScaledEffectParam020708c8P19EffectParam020708c8j(void* p, unsigned int v);
extern "C" void _Z17SetMainBrightnessP13GameResourcesii(void* ov17, int a, int b);
extern "C" void* _Z26GetGlobalField0x1c020421a0v(void);
extern "C" void func_02043124(void* v);
extern "C" void _Z31ClearMultipleFieldBits_02156b20v(void* obj);
extern "C" void func_ov017_021bb27c(void* obj);

struct S021564b0 { char pad0; char flag1; char pad[8]; unsigned short fieldA; };

// USA: func_ov001_021564b0  (semantic: TriggerEffectAndResetCombatant_021564b0)
extern "C" ARM unsigned short func_ov001_021564b0(struct S021564b0* obj) {
    void* ov17 = func_ov017_0218b5b0();
    if (*(unsigned char*)((char*)ov17 + flagOffset) != 0) {
        char* p3000 = (char*)ov17 + 0x3000;
        func_02046a8c(*(int*)(p3000 + listOffset), *(int*)(p3000 + contextOffset));
        _Z28SetScaledEffectParam020708c8P19EffectParam020708c8j(func_020704fc(), 0xf);
        _Z17SetMainBrightnessP13GameResourcesii(ov17, 0, 0xf);
        void* field = _Z26GetGlobalField0x1c020421a0v();
        func_02043124(field);
        char* p1000 = (char*)field + 0x1000;
        p1000[resetOffset] = 0;
        _Z31ClearMultipleFieldBits_02156b20v(obj);
        func_ov017_021bb27c(obj);
        obj->flag1 = 1;
    }
    return obj->fieldA;
}
