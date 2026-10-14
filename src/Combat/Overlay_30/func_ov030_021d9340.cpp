#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void func_ov015_0218b5a0(void);
struct GameResources;
void InitializeBrightnessState(GameResources*);
unsigned int EnableSpecificInterrupts(unsigned int mask);
struct T02054280;
void ResetAllocators02054280(T02054280*);
extern "C" void func_0204719c(void* obj);
void InitObj0219a674(unsigned char*);
extern "C" void func_02020554(void* obj);
extern "C" void VectorizedMemset(void* dst, int value, unsigned int length);
struct List0204af64;
void ResetList0204af64(List0204af64*);
void ResetFieldGroup4444_0218b664(char* base);
struct List02046958;
void ClearListHeadTail(List02046958*);
extern "C" void func_ov017_021a124c(void* obj);
void InitAndResetHeader_0219e310(unsigned char*, int);
extern "C" void func_ov017_021b8d1c(void* obj);
extern "C" void func_ov017_021b6f18(void* obj);
extern "C" void func_ov017_021a5568(void* obj);
extern "C" void func_ov017_021bf410(void* obj);
struct Obj_021b8c70;
void InitState14Neg1_021b8c70(Obj_021b8c70*);
extern "C" void func_ov017_021bac58(void* obj);
struct Obj021ba90c;
void InitState16_021ba90c(Obj021ba90c*);
struct ByteHeader0204693c;
void ResetByteHeader(ByteHeader0204693c*);
extern "C" void func_ov017_021baedc(void* obj, int flag);
extern "C" void func_ov017_021b2c4c(void* obj);
void Init021b2f64(unsigned char*);
struct Struct021b46d8;
void InitStruct_021b46d8(Struct021b46d8*);
extern "C" void func_ov017_021b57fc(void* obj);
struct Struct021aa3f4;
void InitState25_021aa3f4(Struct021aa3f4*);
struct Obj021aa50c;
void InitState25_021aa50c(Obj021aa50c*);
struct Struct021ab250;
void InitState6_021ab250(Struct021ab250*);
struct Obj021abb68;
void InitState28_021abb68(Obj021abb68*, unsigned char);
struct Obj021ac2ec;
void InitState30_021ac2ec(Obj021ac2ec*);
struct Obj021c0124;
void InitState32_021c0124(Obj021c0124*, unsigned char);
extern "C" void func_ov017_021acd7c(void* obj);
void InitObj_021adc58(unsigned char*);
struct Obj021ae800;
void ResetHeaderAndAllocator_021ae800(Obj021ae800*);
struct Struct021aeedc;
void InitState37_021aeedc(Struct021aeedc*);
extern "C" void func_ov017_021af59c(void* obj);
struct Struct021b11b0;
void InitState39_021b11b0(Struct021b11b0*);
struct Obj021c0334;
void InitState40_021c0334(Obj021c0334*);
void InitObjWithFlag_021c0760(unsigned char*, unsigned char);
struct Obj021b14a0;
void InitState37_021b14a0(Obj021b14a0*);
extern "C" void func_ov017_021b1d44(void* obj, int size, int flag);
void InitObjState_021b2174(unsigned char*);
struct Obj021c1350;
void InitObj021c1350(Obj021c1350*, unsigned char, unsigned char);
extern "C" void func_ov017_021c17cc(void* obj);
void InitByteHeader_021c16a8(unsigned char*);
struct Struct021b61e4;
void InitBattleObj_021b61e4(Struct021b61e4*);
void InitObj021bdbf0(unsigned char*);
void InitByteHeader_021be0a0(unsigned char*);
extern "C" void func_ov017_021a9bc4(void* obj, int flag);
void InitObj021beba4(char*);
struct Obj021befe4;
void InitState53_021befe4(Obj021befe4*);
struct Obj021aa16c;
void InitState60_021aa16c(Obj021aa16c*);
struct Struct021c1e40;
void InitState66_021c1e40(Struct021c1e40*);
void InitByteHeader_021c2688(unsigned char*);
struct Obj021c2744;
void InitState69_021c2744(Obj021c2744*);
void InitObj021c2b28(void* obj, unsigned char a, unsigned char b);
struct Struct021c316c;
void InitState71WithFlag_021c316c(Struct021c316c*, int);
extern "C" void func_ov017_021a967c(void* obj, int flag);
struct Struct020d9dec;
void Init020d9dec(Struct020d9dec*, int);
struct Struct020dac68;
void Init020dac68(Struct020dac68*);
struct Struct020d9850;
void Init020d9850(Struct020d9850*);
struct Obj020d8080;
void InitObject020d8080(Obj020d8080*);
struct Struct020dbc9c;
void InitStruct020dbc9c(Struct020dbc9c*);
struct CombatState020e3c34;
void Init020e3c34(CombatState020e3c34*);
struct Obj021be40c;
void InitObj021be40c(Obj021be40c*);
void InitFieldArenaListsAndCounters_021996fc(unsigned char* base);
void InitFieldArenaLists_021a5b48(unsigned char* base);
extern "C" void* memset(void* dst, int value, unsigned int length);
void ClearBytes0And1_021941ec(unsigned char*);
void ClearFourEntries_02191b70(void* obj);

// USA: func_ov030_021d9340
extern "C" ARM void func_ov030_021d9340(unsigned char* self) {
    func_ov015_0218b5a0();
    InitializeBrightnessState((GameResources*)self);

    volatile unsigned short* ime = (volatile unsigned short*)0x4000208;
    unsigned short old = *ime;
    (void)old;
    *ime = 1;
    EnableSpecificInterrupts(8);
    GameState::GetInstance();

    *(int*)(self + 0x2c) = 0;
    *(int*)(self + 0x30) = 0;
    *(int*)(self + 0x34) = 0;
    for (int i = 0; i < R(0x1d, 0x21); i++) {
        ((SafeAllocator*)(self + 0x38 + i * 0x14))->ResetAllocatorPointer();
    }
    ((SafeAllocator*)(self + R(0xf2c, (0x1000 + 0x13c))))->ResetAllocatorPointer();
    ((SafeAllocator*)(self + R(0xfb0, 0x11c0)))->ResetAllocatorPointer();
    ((SafeAllocator*)(self + R(0x1034, (0x1000 + 0x244))))->ResetAllocatorPointer();
    for (int i = 0; i < 4; i++) {
        ResetAllocators02054280((T02054280*)(self + R(0x10b8, (0x1000 + 0x2c8)) + i * 0x5ec));
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 0xb; j++) {
            signed char* row = (signed char*)self + i * 0xb;
            *(row + j + R(0x41ac, (0x4000 + 0x45c))) = -1;
        }
    }

    *(int*)(self + R(0x4188, (0x4000 + 0x438))) = 0;
    *(int*)(self + R(0x418c, (0x4000 + 0x43c))) = 0;
    *(int*)(self + R(0x4190, (0x4000 + 0x440))) = 0;
    *(int*)(self + R(0x28f8, (0x2000 + 0xb08))) = -1;
    ((SafeAllocator*)(self + R(0x28fc, (0x2000 + 0xb0c))))->ResetAllocatorPointer();

    for (int i = 0; i < 0x12; i++) {
        func_0204719c(self + R(0x2980, (0x2000 + 0xb90)) + i * 0x88);
    }
    func_0204719c(self + R(0x3310, (0x3000 + 0x520)));
    func_0204719c(self + R(0x3398, (0x3400 + 0x1a8)));

    *(int*)(self + R(0x3420, (0x3000 + 0x630))) = 0;
    for (int i = 0; i < 0x12; i++) {
        unsigned char* slot = self + i;
        slot[R(0x3424, (0x3000 + 0x634))] = 0;
        slot[R(0x3436, (0x3000 + 0x646))] = 0;
        slot[R(0x3448, (0x3000 + 0x658))] = 0;
        *(int*)(self + R(0x345c, (0x3000 + 0x66c)) + i * 4) = 0;
    }

    InitObj0219a674((unsigned char*)(self + R(0x34a4, (0x3400 + 0x2b4))));
    ((Model3D*)(*(void**)(self + R(0x34b8, (0x3000 + 0x6c8)))))->Clear();
    ((Object3D*)(*(void**)(self + R(0x34bc, (0x3000 + 0x6cc)))))->Initialize();
    self[R(0x4111, (0x4000 + 0x331))] = 0;
    func_02020554(*(void**)(self + R(0x34c0, (0x3000 + 0x6d0))));

    *(int*)(self + R(0x34c4, (0x3000 + 0x6d4))) = 0;
    for (int i = 0; i < 4; i++) {
        unsigned char* entry = self + i * R(0xc, 0x30);
        entry[R(0x413c, (0x4000 + 0x35c))] = 0;
    }

    VectorizedMemset(self + R(0x34cc, (0x3400 + 0x2dc)), 0, 5);
    VectorizedMemset(self + R(0x34d1, (0x3600 + 0xe1)), 0, 9);
    ResetList0204af64((List0204af64*)(*(void**)(self + R(0x34c8, (0x3000 + 0x6d8)))));

    *(int*)(self + R(0x34dc, (0x3000 + 0x6ec))) = -1;
    *(int*)(self + R(0x34e0, (0x3000 + 0x6f0))) = 0;
    *(int*)(self + R(0x34e4, (0x3000 + 0x6f4))) = 0;
    *(int*)(self + R(0x34e8, (0x3000 + 0x6f8))) = 0;
    *(int*)(self + R(0x41dc, (0x4000 + 0x48c))) = 0;
    self[R(0x41e0, (0x4000 + 0x490))] = 0;
    ResetFieldGroup4444_0218b664((char*)self);

    *(signed char*)(self + R(0x4196, (0x4000 + 0x446))) = -1;
    for (int i = 0; i < 4; i++) {
        *(short*)(self + R(0x419a, (0x4400 + 0x4a)) + i * 2) = 0;
    }

    *(int*)(self + R(0x41a4, (0x4000 + 0x454))) = 0x24;
    *(int*)(self + R(0x41a8, (0x4000 + 0x458))) = 1;
    self[R(0x41d8, (0x4000 + 0x488))] = 0;
    self[R(0x41d9, (0x4000 + 0x489))] = 1;
    self[R(0x41da, (0x4000 + 0x48a))] = 0;

    ClearListHeadTail((List02046958*)(*(void**)(self + R(0x34ec, (0x3000 + 0x6fc)))));
    ClearListHeadTail((List02046958*)(*(void**)(self + R(0x34f0, (0x3000 + 0x700)))));
    ClearListHeadTail((List02046958*)(*(void**)(self + R(0x34f4, (0x3000 + 0x704)))));
    func_ov017_021a124c(*(void**)(self + R(0x34f8, (0x3000 + 0x708))));
    InitAndResetHeader_0219e310((unsigned char*)(*(void**)(self + R(0x34fc, (0x3000 + 0x70c)))), 1);
    func_ov017_021b8d1c(*(void**)(self + R(0x3500, (0x3000 + 0x710))));
    func_ov017_021b6f18(*(void**)(self + R(0x3508, (0x3000 + 0x718))));
    func_ov017_021a5568(*(void**)(self + R(0x350c, (0x3000 + 0x71c))));
    func_ov017_021bf410(*(void**)(self + R(0x3510, (0x3000 + 0x720))));
    InitState14Neg1_021b8c70((Obj_021b8c70*)(*(void**)(self + R(0x3514, (0x3000 + 0x724)))));
    func_ov017_021bac58(*(void**)(self + R(0x3518, (0x3000 + 0x728))));
    InitState16_021ba90c((Obj021ba90c*)(*(void**)(self + R(0x351c, (0x3000 + 0x72c)))));

    ResetByteHeader((ByteHeader0204693c*)(*(void**)(self + R(0x3520, (0x3000 + 0x730)))));
    **(unsigned char**)(self + R(0x3520, (0x3000 + 0x730))) = 0x11;
    *(int*)(*(unsigned char**)(self + R(0x3520, (0x3000 + 0x730))) + 8) = 0;
    ((SafeAllocator*)(*(unsigned char**)(self + R(0x3520, (0x3000 + 0x730))) + 0xc))->ResetAllocatorPointer();
    *(int*)(*(unsigned char**)(self + R(0x3520, (0x3000 + 0x730))) + 0x20) = 0;
    *(*(unsigned char**)(self + R(0x3520, (0x3000 + 0x730))) + 0x24) = 0xff;

    func_ov017_021baedc(*(void**)(self + R(0x3524, (0x3000 + 0x734))), 0);
    func_ov017_021b2c4c(*(void**)(self + R(0x3528, (0x3000 + 0x738))));

    for (int i = 0; i < 0xc; i++) {
        Init021b2f64((unsigned char*)(self + R(0x352c, (0x3400 + 0x33c)) + i * 0x48));
    }
    for (int i = 0; i < 4; i++) {
        InitStruct_021b46d8((Struct021b46d8*)(self + R(0x388c, (0x3800 + 0x29c)) + i * R(0x14, 0x18)));
    }

    func_ov017_021b57fc(*(void**)(self + R(0x38dc, (0x3000 + 0xafc))));

    ResetByteHeader((ByteHeader0204693c*)(*(void**)(self + R(0x38e0, (0x3000 + 0xb00)))));
    **(unsigned char**)(self + R(0x38e0, (0x3000 + 0xb00))) = 0x17;
    *(int*)(*(unsigned char**)(self + R(0x38e0, (0x3000 + 0xb00))) + 0x24) = 0;
    *(*(unsigned char**)(self + R(0x38e0, (0x3000 + 0xb00))) + 0x1f) = 0;
    *(*(unsigned char**)(self + R(0x38e0, (0x3000 + 0xb00))) + 0x1c) = 0;
    ((SafeAllocator*)(*(unsigned char**)(self + R(0x38e0, (0x3000 + 0xb00))) + 8))->ResetAllocatorPointer();
    *(*(unsigned char**)(self + R(0x38e0, (0x3000 + 0xb00))) + 0x1d) = 0;
    *(*(unsigned char**)(self + R(0x38e0, (0x3000 + 0xb00))) + 0x1e) = 0xff;
    *(signed char*)(*(unsigned char**)(self + R(0x38e0, (0x3000 + 0xb00))) + 0x20) = -1;

    ResetByteHeader((ByteHeader0204693c*)(*(void**)(self + R(0x38e4, (0x3000 + 0xb04)))));
    **(unsigned char**)(self + R(0x38e4, (0x3000 + 0xb04))) = 0x18;
    *(int*)(*(unsigned char**)(self + R(0x38e4, (0x3000 + 0xb04))) + 0x20) = 0;
    *(int*)(*(unsigned char**)(self + R(0x38e4, (0x3000 + 0xb04))) + 0x1c) = 0;
    *(*(unsigned char**)(self + R(0x38e4, (0x3000 + 0xb04))) + 0xb4) = 0;
    ((SafeAllocator*)(*(unsigned char**)(self + R(0x38e4, (0x3000 + 0xb04))) + 8))->ResetAllocatorPointer();
    *(unsigned short*)(*(unsigned char**)(self + R(0x38e4, (0x3000 + 0xb04))) + 0xa0) = 0;
    *(int*)(*(unsigned char**)(self + R(0x38e4, (0x3000 + 0xb04))) + 0xa4) = 0;
    *(int*)(*(unsigned char**)(self + R(0x38e4, (0x3000 + 0xb04))) + 0xa8) = 0;
    *(int*)(*(unsigned char**)(self + R(0x38e4, (0x3000 + 0xb04))) + 0xac) = 0;
    *(int*)(*(unsigned char**)(self + R(0x38e4, (0x3000 + 0xb04))) + 0xb0) = 0;

    InitState25_021aa3f4((Struct021aa3f4*)(*(void**)(self + R(0x38e8, (0x3000 + 0xb08)))));
    InitState25_021aa50c((Obj021aa50c*)(*(void**)(self + R(0x38ec, (0x3000 + 0xb0c)))));
    InitState6_021ab250((Struct021ab250*)(*(void**)(self + R(0x38f0, (0x3000 + 0xb10)))));
    InitState28_021abb68((Obj021abb68*)(*(void**)(self + R(0x38f4, (0x3000 + 0xb14)))), 0);
    InitState30_021ac2ec((Obj021ac2ec*)(*(void**)(self + R(0x38f8, (0x3000 + 0xb18)))));
    InitState32_021c0124((Obj021c0124*)(*(void**)(self + R(0x38fc, (0x3000 + 0xb1c)))), 0);
    func_ov017_021acd7c(*(void**)(self + R(0x3900, (0x3000 + 0xb20))));
    InitObj_021adc58((unsigned char*)(*(void**)(self + R(0x3904, (0x3000 + 0xb24)))));
    ResetHeaderAndAllocator_021ae800((Obj021ae800*)(*(void**)(self + R(0x3908, (0x3000 + 0xb28)))));
    InitState37_021aeedc((Struct021aeedc*)(*(void**)(self + R(0x390c, (0x3000 + 0xb2c)))));
    func_ov017_021af59c(*(void**)(self + R(0x3910, (0x3000 + 0xb30))));
    InitState39_021b11b0((Struct021b11b0*)(*(void**)(self + R(0x3914, (0x3000 + 0xb34)))));
    InitState40_021c0334((Obj021c0334*)(*(void**)(self + R(0x3918, (0x3000 + 0xb38)))));
    InitObjWithFlag_021c0760((unsigned char*)(*(void**)(self + R(0x391c, (0x3000 + 0xb3c)))), 1);

    ResetByteHeader((ByteHeader0204693c*)(*(void**)(self + R(0x3920, (0x3000 + 0xb40)))));
    **(unsigned char**)(self + R(0x3920, (0x3000 + 0xb40))) = 0x2a;
    *(int*)(*(unsigned char**)(self + R(0x3920, (0x3000 + 0xb40))) + 0xc) = 0;
    *(int*)(*(unsigned char**)(self + R(0x3920, (0x3000 + 0xb40))) + 0x10) = 0;
    unsigned char* state42 = *(unsigned char**)(self + R(0x3920, (0x3000 + 0xb40)));
    state42[0x3a] = 0;
    state42[0x3b] = 0;
    *(*(unsigned char**)(self + R(0x3920, (0x3000 + 0xb40))) + 0x28) = 0xff;

    InitState37_021b14a0((Obj021b14a0*)(*(void**)(self + R(0x3924, (0x3000 + 0xb44)))));
    func_ov017_021b1d44(*(void**)(self + R(0x3928, (0x3000 + 0xb48))), 0x40, 1);
    *(*(unsigned char**)(self + R(0x3928, (0x3000 + 0xb48))) + 0x33) = R(5, 8);
    InitObjState_021b2174((unsigned char*)(*(void**)(self + R(0x392c, (0x3000 + 0xb4c)))));
    InitObj021c1350((Obj021c1350*)(*(void**)(self + R(0x3930, (0x3000 + 0xb50)))), 0, 0);
    func_ov017_021c17cc(*(void**)(self + R(0x3934, (0x3000 + 0xb54))));
    InitByteHeader_021c16a8((unsigned char*)(*(void**)(self + R(0x3938, (0x3000 + 0xb58)))));
    InitBattleObj_021b61e4((Struct021b61e4*)(*(void**)(self + R(0x393c, (0x3000 + 0xb5c)))));
    InitObj021bdbf0((unsigned char*)(*(void**)(self + R(0x3940, (0x3000 + 0xb60)))));
    InitByteHeader_021be0a0((unsigned char*)(*(void**)(self + R(0x3944, (0x3000 + 0xb64)))));
    func_ov017_021a9bc4(*(void**)(self + R(0x3948, (0x3000 + 0xb68))), 0);
    InitObj021beba4((char*)(*(void**)(self + R(0x394c, (0x3000 + 0xb6c)))));
    InitState53_021befe4((Obj021befe4*)(*(void**)(self + R(0x3950, (0x3000 + 0xb70)))));

    ResetByteHeader((ByteHeader0204693c*)(*(void**)(self + R(0x3954, (0x3000 + 0xb74)))));
    **(unsigned char**)(self + R(0x3954, (0x3000 + 0xb74))) = 0x36;
    *(unsigned short*)(*(unsigned char**)(self + R(0x3954, (0x3000 + 0xb74))) + 8) = 0;
    *(*(unsigned char**)(self + R(0x3954, (0x3000 + 0xb74))) + 0xa) = 0;
    *(short*)(*(unsigned char**)(self + R(0x3954, (0x3000 + 0xb74))) + 0xc) = -1;
    *(*(unsigned char**)(self + R(0x3954, (0x3000 + 0xb74))) + 0xe) = 0;
    *(*(unsigned char**)(self + R(0x3954, (0x3000 + 0xb74))) + 0xf) = 0;

    InitState60_021aa16c((Obj021aa16c*)(*(void**)(self + R(0x3968, (0x3000 + 0xb88)))));
    InitState66_021c1e40((Struct021c1e40*)(*(void**)(self + R(0x3980, (0x3000 + 0xba0)))));
    InitByteHeader_021c2688((unsigned char*)(*(void**)(self + R(0x3988, (0x3000 + 0xba8)))));
    InitState69_021c2744((Obj021c2744*)(*(void**)(self + R(0x398c, (0x3000 + 0xbac)))));
    InitObj021c2b28(*(void**)(self + R(0x3990, (0x3000 + 0xbb0))), 0, 0);
    InitState71WithFlag_021c316c((Struct021c316c*)(*(void**)(self + R(0x3994, (0x3000 + 0xbb4)))), 0);
    func_ov017_021a967c(*(void**)(self + R(0x3964, (0x3000 + 0xb84))), 0);
    Init020d9dec((Struct020d9dec*)(*(void**)(self + R(0x399c, (0x3000 + 0xbbc)))), 1);
    Init020dac68((Struct020dac68*)(*(void**)(self + R(0x39a4, (0x3000 + 0xbc4)))));
    Init020d9850((Struct020d9850*)(*(void**)(self + R(0x3998, (0x3000 + 0xbb8)))));
    InitObject020d8080((Obj020d8080*)(*(void**)(self + R(0x3984, (0x3000 + 0xba4)))));

    for (int i = 0; i < 3; i++) {
        InitStruct020dbc9c((Struct020dbc9c*)(self + R(0x39a8, (0x3800 + 0x3c8)) + i * 0x14));
    }
    for (int i = 0; i < 4; i++) {
        Init020e3c34((CombatState020e3c34*)(self + R(0x39e4, (0x3c00 + 4)) + i * 0x28));
    }

    InitObj021be40c((Obj021be40c*)(*(void**)(self + R(0x3a84, (0x3000 + 0xca4)))));
    InitFieldArenaListsAndCounters_021996fc(self);
    InitFieldArenaLists_021a5b48(self);

    self[R(0x40c0, (0x4000 + 0x2e0))] = 2;
    self[R(0x40c1, (0x4000 + 0x2e1))] = 0;
    self[R(0x40c4, (0x4000 + 0x2e4))] = 0;
    self[R(0x40ca, (0x4000 + 0x2ea))] = 0;
    *(unsigned short*)(self + R(0x40cc, (0x4200 + 0xec))) = 0;
    *(unsigned short*)(self + R(0x40ce, (0x4200 + 0xee))) = 0;
    self[R(0x40d0, (0x4000 + 0x2f0))] = 0;
    memset(self + R(0x40d1, (0x4200 + 0xf1)), 0, 0x2d);

    self[R(0x40fe, (0x4000 + 0x31e))] = 0;
    *(int*)(self + R(0x4100, (0x4000 + 0x320))) = 1;
    *(int*)(self + R(0x4104, (0x4000 + 0x324))) = 0;
    *(signed char*)(self + R(0x410c, (0x4000 + 0x32c))) = -1;
    for (int i = 0; i < 3; i++) {
        signed char* extra = (signed char*)self + i;
        extra[R(0x410d, (0x4000 + 0x32d))] = -1;
    }

    self[R(0x4110, (0x4000 + 0x330))] = 0;
    *(int*)(self + R(0x4114, (0x4000 + 0x334))) = 0;
    *(int*)(self + R(0x4118, (0x4000 + 0x338))) = 0;
    *(int*)(self + R(0x411c, (0x4000 + 0x33c))) = 0;
    *(int*)(self + R(0x4120, (0x4000 + 0x340))) = 0;
    self[R(0x41e1, (0x4000 + 0x491))] = 0;
    self[R(0x40c7, (0x4000 + 0x2e7))] = 0;
    self[R(0x40c8, (0x4000 + 0x2e8))] = 0;
    *(int*)(self + R(0x41e4, (0x4000 + 0x494))) = 0;
    *(int*)(self + R(0x4128, (0x4000 + 0x348))) = 0;
    *(int*)(self + R(0x412c, (0x4000 + 0x34c))) = 0;
    *(int*)(self + R(0x4130, (0x4000 + 0x350))) = 0;
    self[R(0x40c9, (0x4000 + 0x2e9))] = 0;
    self[R(0x4134, (0x4000 + 0x354))] = 0;
    self[R(0x40c2, (0x4000 + 0x2e2))] = 0;
    self[R(0x40c3, (0x4000 + 0x2e3))] = 0;
    *(int*)(self + R(0x4124, (0x4000 + 0x344))) = 0;
    *(int*)(self + R(0x41e8, (0x4000 + 0x498))) = 0;
    ClearBytes0And1_021941ec((unsigned char*)(*(void**)(self + R(0x416c, (0x4000 + 0x41c)))));

    self[R(0x4170, (0x4000 + 0x420))] = 1;
    self[R(0x4171, (0x4000 + 0x421))] = 0;
    *(unsigned short*)(self + R(0x4172, (0x4400 + 0x22))) = 0;
    *(unsigned short*)(self + R(0x4174, (0x4400 + 0x24))) = 0;
    *(int*)(self + R(0x4178, (0x4000 + 0x428))) = -1;
    self[R(0x417c, (0x4000 + 0x42c))] = 0;
    self[R(0x417d, (0x4000 + 0x42d))] = 0;
    self[R(0x417e, (0x4000 + 0x42e))] = 0;
    *(short*)(self + R(0x4180, (0x4400 + 0x30))) = -1;
    self[R(0x417f, (0x4000 + 0x42f))] = 0;
    *(int*)(self + R(0x4184, (0x4000 + 0x434))) = 0;
    self[R(0x4182, (0x4000 + 0x432))] = 2;
    self[R(0x40c5, (0x4000 + 0x2e5))] = 0;
    self[R(0x4135, (0x4000 + 0x355))] = 0;
    ClearFourEntries_02191b70(self);
    *(unsigned short*)(self + R(0x41fc, (0x4400 + 0xac))) = 0;
}
