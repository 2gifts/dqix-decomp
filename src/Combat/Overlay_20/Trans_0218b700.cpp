#include <globaldefs.h>

unsigned int InitControllerObject(char* obj);
char* GetGlobalField0x1c020421a0();

// USA: func_ov020_0218b700  (semantic: Trans_0218b700)
extern "C" ARM void func_ov020_0218b700() {
    InitControllerObject(GetGlobalField0x1c020421a0());
}
