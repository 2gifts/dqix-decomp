#include <globaldefs.h>

#include "GameState/GameState.h"
#include "Resource/Script.h"

struct Struct0200fb08;
unsigned char NormalizeField5_0200fb08(struct Struct0200fb08* obj);

struct Global021fff08 { char unknown0[0x10]; const char* text; };
extern struct Global021fff08 data_ov023_021fff08;

// USA: func_ov023_021f5788
ARM int StoreField4IfMatch_021f5788(void* obj) {
    Script::Parameter* params = (Script::Parameter*)obj;
#if defined(jpn)
    data_ov023_021fff08.text = params[0].ToString();
#else
    int a = params[0].ToInt();
    int b = NormalizeField5_0200fb08((struct Struct0200fb08*)GameState::GetInstance());
    if (a == b) {
        data_ov023_021fff08.text = params[1].ToString();
    }
#endif
    return 1;
}
