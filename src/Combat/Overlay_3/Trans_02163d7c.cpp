#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
enum { kRegionValue6FC_4EC = 0x4ec };
enum { kRegionValue734_524 = 0x524 };
enum { kRegionValue400_200 = 0x200 };
enum { kRegionValueA2_CA = 0xca };
enum { kRegionValueCD_C9 = 0xc9 };
enum { kRegionValueCE_CA = 0xca };
enum { kRegionValueCF_CB = 0xcb };
enum { kRegionValue4A3_2CB = 0x2cb };
enum { kRegionValue464_28C = 0x28c };
#else
enum { kRegionValue6FC_4EC = 0x6fc };
enum { kRegionValue734_524 = 0x734 };
enum { kRegionValue400_200 = 0x400 };
enum { kRegionValueA2_CA = 0xa2 };
enum { kRegionValueCD_C9 = 0xcd };
enum { kRegionValueCE_CA = 0xce };
enum { kRegionValueCF_CB = 0xcf };
enum { kRegionValue4A3_2CB = 0x4a3 };
enum { kRegionValue464_28C = 0x464 };
#endif

struct Field150 {
    char pad[0x14];
    unsigned char flag : 1;
};

extern "C" void _Z16AppendNodeToTailP16TailList020469b4P16TailNode020469b4(char*, char*);
extern "C" int _Z18CheckField0NonZeroPi(char*);
extern "C" void _Z19SetFlag320_02195530Ph(GameResources*);
extern "C" Field150* _Z28GetField150Ptr0x488_02052e2cP22Field150Holder02052e2c(GameObject*);
extern "C" char* func_02012fe4();
extern "C" char* func_0202ae18();
extern "C" int func_0202c508(char*);
extern "C" void func_ov003_02161480();
extern "C" void func_ov017_021bbae4(char*, unsigned int, int);

// USA: func_ov003_02163d7c  (semantic: Trans_02163d7c)
extern "C" ARM void func_ov003_02163d7c(char* self) {
    func_ov003_02161480();
    GameState* state = GameState::GetInstance();
    char* info = func_02012fe4();
    GameResources* res = func_ov017_0218b5b0();
    char* list = *(char**)((char*)res + 0x3000 + kRegionValue6FC_4EC);
    char* node = *(char**)((char*)res + 0x3000 + kRegionValue734_524);
    Field150* field = _Z28GetField150Ptr0x488_02052e2cP22Field150Holder02052e2c(
        state->GetGameObjectByIndex(*(signed char*)(self + kRegionValue400_200 + kRegionValueA2_CA)));
    char* entry = func_0202ae18();
    func_ov017_021bbae4(node, *(unsigned int*)(info + 0x8), 1);
    node[kRegionValueCD_C9] = *(signed char*)(self + kRegionValue400_200 + kRegionValueA2_CA);
    node[kRegionValueCE_CA] = field->flag;
    node[kRegionValueCF_CB] = 0;
    _Z16AppendNodeToTailP16TailList020469b4P16TailNode020469b4(list, node);
    self[kRegionValue4A3_2CB] = 0x10;
    *(unsigned int*)(self + kRegionValue464_28C) &= ~0x8000;
    if (!_Z18CheckField0NonZeroPi(entry)) {
        return;
    }
    if (!func_0202c508(entry)) {
        return;
    }
    _Z19SetFlag320_02195530Ph(res);
}
