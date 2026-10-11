#include <globaldefs.h>
#include "Combat/Main/CopyRecord0200fbb4.h"
#include "GameState/GameState.h"


extern "C" void* _Z20GetField0x3f8AddressP9GameState(void* battle);
extern "C" void func_02012fe4(void);
extern "C" int func_ov017_021d60f4(void* obj);
extern "C" float func_ov017_021d6110(void* obj);
extern "C" void _ZN8Vector3iaSERKS_(int* dst, int* src);
extern "C" void _Z18InitStruct02070378Pc(void* obj);

struct S3f8_02161f80 {
    short field0;
    char field2;
    char pad1[4];
    char field7;
    char pad2[8];
    int vec10[3];
    short field1c;
    char pad3[2];
    int field20;
    char pad4[0x68 - 0x24];
    char field68;
    char field69;
};

// USA: func_ov001_02161f80
// JPN: func_ov001_02163594
extern "C" ARM int func_ov001_02161f80(void* target, int count) {
    int tmpArr[3];
    void* battle = GameState::GetInstance();
    struct S3f8_02161f80* obj = (struct S3f8_02161f80*)_Z20GetField0x3f8AddressP9GameState(battle);
    func_02012fe4();
    int flag2 = -1;
    int fixedD;
    int flag = func_ov017_021d60f4(target);
    tmpArr[0] = (int)(4096.0f * func_ov017_021d6110((char*)target + 0x8));
    tmpArr[1] = (int)(4096.0f * func_ov017_021d6110((char*)target + 0x10));
    tmpArr[2] = (int)(4096.0f * func_ov017_021d6110((char*)target + 0x18));
    fixedD = (int)(4096.0f * func_ov017_021d6110((char*)target + 0x20));
    int cnt = count;
    if (cnt > 5) {
        flag2 = func_ov017_021d60f4((char*)target + 0x28);
    }
    _Z18InitStruct02070378Pc(obj);
    obj->field2 = 1;
    obj->field7 = 1;
    obj->field0 = (short)flag;
    _ZN8Vector3iaSERKS_(obj->vec10, tmpArr);
    obj->field1c = (short)fixedD;
    obj->field20 = flag2;
    void* p = ((char*)func_ov017_0218b5b0()) + 0x3000;
#if defined(jpn)
    void* q = *(void**)((char*)p + 0x524);
#else
    void* q = *(void**)((char*)p + 0x734);
#endif
    if (q != NULL && *((unsigned char*)q + 3) != 0) {
        unsigned short v = *(unsigned short*)((char*)q + 8);
        if (v == 0x733d || v == 0x7340) {
            obj->field69 = 1;
        }
    }
    _Z28CallFunc0200fbb4AtField0x3f8Pv(battle, obj);
    return 1;
}
