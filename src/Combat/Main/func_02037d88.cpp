#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void func_0202ae18(void);
extern "C" void* func_02012fe4(void);
extern "C" void func_020391ac(void* obj);
extern "C" void func_02038138(void* obj);
extern "C" void func_02038598(void* obj);

extern "C" void _ZN8Vector3iaSERKS_(int* dst, int* src);

struct S02037418;
extern "C" void _ZN8Object3D17SetInheritedAlphaEi(struct S02037418* obj, int val);

struct Struct020372b8;
extern "C" void _ZN8Object3D24TransitionInheritedAlphaEii(struct Struct020372b8* obj, int a, int b);

struct Obj02039df4;
void ApplyStatusTickEffect(struct Obj02039df4* obj);

struct Obj02052ae8;
extern "C" void _Z29StepValueTowardTarget02052ae8P11Obj02052ae8(struct Obj02052ae8* obj);

int GetField0x3b0Value(GameState* battleStruct);
int CheckSubstructByte0x7cPositive(signed char* obj);
extern "C" int _Z24IsCountAtLeast4_0219a370Ph(unsigned char* base);
int IsField0Null(void** obj);
int TestFlagMask(unsigned short* obj, int mask);

struct BitField0203402c;
int CheckField0xc4Low15BitsNonZero(struct BitField0203402c* p);

extern "C" int _Z26GetGlobalField0x1c020421a0v();

unsigned char GetField0x397cValue(GameState* battleStruct);
int GetFieldIfFlag4(char* obj);

struct S020a2c70;
extern "C" int _Z23MarkStateIfFlag020a2c70P9S020a2c70(struct S020a2c70* p);

void SetBitsInField4(unsigned int* obj, unsigned int mask);
void ClearBitsInField4(unsigned int* obj, unsigned int mask);
int TestFlag0SetAndFlag1Clear(unsigned short* obj, int mask);

struct Obj02052e44;
extern "C" int _Z27InitFieldsIfInRange02052e44P11Obj02052e44aii(struct Obj02052e44* obj, signed char arg1);

struct Obj02052f44;
extern "C" int _Z26FilterBytesAndInit02052f44P11Obj02052f44Pai(struct Obj02052f44* obj, signed char* src, int len);

extern "C" int _Z23LoadBattleBlock020ac4c0Pv(void* dst);

struct S_a06b0;
void AddClamped10BitFieldMidAt0x28(struct S_a06b0* p, unsigned int amount);

struct S_a0140;
void AddClamped10BitFieldAt0x14(struct S_a0140* p, unsigned int amount);

int CopyInBattleField0x7540(void* src);

void SetByte0x2c4To2IfByte0x2c5Set(unsigned char* obj);

extern "C" int _ZNK8Object3D7GetFlagEi(void* obj, int mask);

extern unsigned short data_02114e30;

#if defined(jpn)
enum { ActorRegionOffset = 12, BattleRegionOffset = 0x2d4, StatusRegionOffset = 0x1d0,
       ContextFlagOffset = 0x444, OverlayValueBase = 0x3000, OverlayValueOffset = 0xe60,
       OverlayPointerOffset = 0x4ec };
#else
enum { ActorRegionOffset = 0, BattleRegionOffset = 0, StatusRegionOffset = 0,
       ContextFlagOffset = 0x424, OverlayValueBase = 0x4000, OverlayValueOffset = 0x80,
       OverlayPointerOffset = 0x6fc };
#endif

struct SubAt1000_020421a0 {
    char pad[0x9b1 - StatusRegionOffset];
    unsigned char flag;
};
struct GlobalOuter020421a0 {
    char pad[0x1000];
    struct SubAt1000_020421a0 sub;
};

struct Obj02037d88 {
    char pad0[4];
    short combatantId;
    char pad6[0x44 - 6];
    int vec[3];
    char pad50[0x54 - 0x50];
    int field54;
    char pad58[0xb2 - 0x58];
    short field0xb2;
    short field0xb4;
    char padb6[0xc2 - 0xb6];
    unsigned char lo0xc2 : 5;
    unsigned char flagBit0xc2 : 1;
    unsigned char hi0xc2 : 2;
    char padc3[0x130 - 0xc3];
    void* field130;
    char pad134[0x1ce - ActorRegionOffset - 0x134];
    unsigned char flags1ce;
    char pad1cf[0x260 - 0x1cf];
    int field260;
};

// USA: func_02037d88
extern "C" ARM void func_02037d88(struct Obj02037d88* obj) {
    void* bs = GameState::GetInstance();
    func_0202ae18();
    unsigned char* r6 = (unsigned char*)((int)func_ov017_0218b5b0());

    int flagBit = (obj->flags1ce & 4) != 0;
    if (flagBit) {
        if (obj->field0xb2 > 0) {
            obj->flags1ce &= ~4;
            _ZN8Object3D17SetInheritedAlphaEi((struct S02037418*)obj, 0);
            _ZN8Object3D24TransitionInheritedAlphaEii((struct Struct020372b8*)obj, 0x1f, 0x64);
        }
    }
    ApplyStatusTickEffect((struct Obj02039df4*)obj);

    if (obj->combatantId == 0xce) {
        *(int*)((char*)bs + 0x7f5c - BattleRegionOffset) = obj->field54;
        _ZN8Vector3iaSERKS_((int*)((char*)bs + 0x7f60 - BattleRegionOffset), obj->vec);
    }

    {
        char* sub100 = (char*)obj + 0x100;
        signed char byte1c9 = ((signed char*)sub100)[0xc9 - ActorRegionOffset];
        if (byte1c9 != 0) {
            _Z29StepValueTowardTarget02052ae8P11Obj02052ae8((struct Obj02052ae8*)obj);
            func_020391ac(obj);
            return;
        }
    }

    {
        void* bsOrig = GameState::GetInstance();
        int field3b0 = GetField0x3b0Value((GameState*)bsOrig);
        void* ctx = func_02012fe4();
        int* ptr130 = (int*)obj->field130;

        if ((*ptr130 & 1) != 0
            || CheckSubstructByte0x7cPositive((signed char*)obj) != 0
            || *(int*)((char*)ctx + ContextFlagOffset) != 0
            || field3b0 == 0
            || obj->flagBit0xc2) {
            _Z29StepValueTowardTarget02052ae8P11Obj02052ae8((struct Obj02052ae8*)obj);
            return;
        }

        {
            short saved0xb4 = obj->field0xb4;
            _Z29StepValueTowardTarget02052ae8P11Obj02052ae8((struct Obj02052ae8*)obj);
            obj->field0xb4 = saved0xb4;
        }

        unsigned int* p4000 = (unsigned int*)(r6 + OverlayValueBase);
        int val80 = *(int*)((char*)p4000 + OverlayValueOffset);
        unsigned int* p3000 = (unsigned int*)(r6 + 0x3000);
        void* val6fc = *(void**)((char*)p3000 + OverlayPointerOffset);

        if (val80 != 0
            && _Z24IsCountAtLeast4_0219a370Ph(r6) != 0
            && IsField0Null((void**)val6fc) != 0
            && TestFlagMask(&data_02114e30, 2) != 0
            && CheckField0xc4Low15BitsNonZero((struct BitField0203402c*)obj) == 0
            && ((struct GlobalOuter020421a0*)_Z26GetGlobalField0x1c020421a0v())->sub.flag == 0) {

            unsigned char* ptr2a04 = (unsigned char*)GetPtrField0x2a04((GameState*)bsOrig);

            void* bsOrig2 = GameState::GetInstance();
            short id3 = obj->combatantId;
            unsigned char field397c_1 = GetField0x397cValue((GameState*)bsOrig2);
            if (field397c_1 == id3) {
                int p2 = GetFieldIfFlag4((char*)bsOrig2);
                if (p2 != 0) {
                    if (_Z24IsCountAtLeast4_0219a370Ph(r6) != 0) {
                        if (_Z23MarkStateIfFlag020a2c70P9S020a2c70((struct S020a2c70*)p2) != 0) {
                            SetBitsInField4((unsigned int*)r6, 0x80);
                        }
                    }
                }
            }

            int result = 0;
            if (TestFlag0SetAndFlag1Clear(&data_02114e30, 0x40)) {
                signed char val = ptr2a04[0x2c8d];
                result = _Z27InitFieldsIfInRange02052e44P11Obj02052e44aii((struct Obj02052e44*)obj, val);
                obj->field260 = 0;
            } else if (TestFlag0SetAndFlag1Clear(&data_02114e30, 0x10)) {
                signed char val = ptr2a04[0x2c8f];
                result = _Z27InitFieldsIfInRange02052e44P11Obj02052e44aii((struct Obj02052e44*)obj, val);
                obj->field260 = 2;
            } else if (TestFlag0SetAndFlag1Clear(&data_02114e30, 0x20)) {
                signed char val = ptr2a04[0x2c8e];
                result = _Z27InitFieldsIfInRange02052e44P11Obj02052e44aii((struct Obj02052e44*)obj, val);
                obj->field260 = 1;
            } else if (TestFlag0SetAndFlag1Clear(&data_02114e30, 0x80)) {
                result = _Z26FilterBytesAndInit02052f44P11Obj02052f44Pai((struct Obj02052f44*)obj, (signed char*)(ptr2a04 + 0x2c90), 4);
                obj->field260 = 3;
            }

            if (result != 0) {
                char buf[0xb0];
                _Z23LoadBattleBlock020ac4c0Pv(buf);
                AddClamped10BitFieldMidAt0x28((struct S_a06b0*)buf, 1);
                AddClamped10BitFieldAt0x14((struct S_a0140*)(buf + 0x68), 1);
                CopyInBattleField0x7540(buf);
                return;
            }
        } else {
            void* bs3 = GameState::GetInstance();
            short id2 = obj->combatantId;
            unsigned char field397c_2 = GetField0x397cValue((GameState*)bs3);
            if (field397c_2 == id2) {
                int p = GetFieldIfFlag4((char*)bs3);
                if (p != 0) {
                    unsigned char* state = (unsigned char*)p + 0x2c4;
                    if (state != 0) {
                        unsigned char stateByte = state[0];
                        if (stateByte == 1) {
                            SetByte0x2c4To2IfByte0x2c5Set((unsigned char*)p);
                        } else if (stateByte == 2) {
                            short v = *(short*)(state + 2);
                            if (v < 0x199) {
                                ClearBitsInField4((unsigned int*)r6, 0x80);
                            }
                        }
                    }
                }
            }
        }

        obj->field260 = -1;
        if (_ZNK8Object3D7GetFlagEi(obj, 0x1000000) == 0) {
            func_02038138(obj);
        }
        func_02038598(obj);
    }
}
