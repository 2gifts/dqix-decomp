#include <globaldefs.h>

#include "Resource/Script.h"

struct StreamHeader02072488;
extern "C" int data_02108da8;
extern Script::OpcodeLookupEntry data_020f0ca0[];

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag.
// USA: func_0207249c
extern "C" ARM int _Z24InitCommandStreamSessioniiP12StreamHeaderi(int arg0, int arg1, StreamHeader02072488* arg2, int arg3) {
    *((int*)((char*)&data_02108da8 + 4)) = arg0;
    *((int*)((char*)&data_02108da8 + 0)) = arg1;
    Script s;
    s.Initialize();
    s.SetOpcodeLookup(data_020f0ca0);
    s.Load(arg2, arg3);
    s.Execute();
}
