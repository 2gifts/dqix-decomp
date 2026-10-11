#include <globaldefs.h>

struct InitStruct;
struct ResetObject0209af34Struct;
struct ZeroWordAndByte0206ee70Struct;

ARM void InitializeStruct(struct InitStruct* s);
ARM void ClearBuffer0209bc84(void* obj);
ARM void ResetObject0209af34(struct ResetObject0209af34Struct* obj);
ARM void ZeroWordAndByte0206ee70(struct ZeroWordAndByte0206ee70Struct* s);

// USA: func_02028cfc
ARM void* FinalizeSubObjects02028cfc(void* obj) {
#if defined(jpn)
    ZeroWordAndByte0206ee70((struct ZeroWordAndByte0206ee70Struct*)((char*)obj + 0x300));
#else
    ZeroWordAndByte0206ee70((struct ZeroWordAndByte0206ee70Struct*)((char*)obj + 0x304));
#endif
#if defined(jpn)
    ResetObject0209af34((struct ResetObject0209af34Struct*)((char*)obj + 0x120));
#else
    ResetObject0209af34((struct ResetObject0209af34Struct*)((char*)obj + 0x124));
#endif
#if defined(jpn)
    ClearBuffer0209bc84((char*)obj + 0x5c);
#else
    ClearBuffer0209bc84((char*)obj + 0x60);
#endif
#if defined(jpn)
    InitializeStruct((struct InitStruct*)((char*)obj + 0x14));
#else
    InitializeStruct((struct InitStruct*)((char*)obj + 0x18));
#endif
    return obj;
}
