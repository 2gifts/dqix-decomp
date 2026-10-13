#include <globaldefs.h>
#include "Resource/Script.h"

#if defined(jpn)
enum { kAngleOffset = 0x54, kWordAOffset = 0x58, kWordBOffset = 0x5c };
#else
enum { kAngleOffset = 0x34, kWordAOffset = 0x38, kWordBOffset = 0x3c };
#endif

#include "std_library_functions.h"

extern "C" int _Z22fix32ReduceAngle0To2Pii(int v);

extern int data_020ef2bc;
extern int data_020fdc14;

// USA: func_0201c5fc
ARM int InitFromVariantBlock0201c5fc(void* obj) {
    const Script::Parameter* parameters = static_cast<const Script::Parameter*>(obj);

    if (data_020ef2bc != parameters[0].ToInt())
        return 1;

    parameters[1].ToInt();
#if defined(jpn)
    const char* extraName = parameters[2].ToString();
    strcpy(*(char**)((char*)&data_020fdc14 + 0x4) + 0x2a, extraName);
#else
    parameters[2].ToString();
#endif
    parameters[3].ToInt();
    parameters[4].ToString();
    parameters[5].ToString();
    parameters[6].ToInt();
    parameters[7].ToString();
    parameters[8].ToInt();
    parameters[9].ToInt();
    parameters[10].ToInt();

    const char* name = parameters[11].ToString();
    if (name != NULL) {
        strcpy(*(char**)((char*)&data_020fdc14 + 0x4), name);
    }

    parameters[12].ToInt();

    *(unsigned short*)(*(char**)((char*)&data_020fdc14 + 0x4) + kAngleOffset) =
        (unsigned short)_Z22fix32ReduceAngle0To2Pii((int)(4096.0f * parameters[13].ToFloat()));

    *(int*)(*(char**)((char*)&data_020fdc14 + 0x4) + kWordAOffset) =
        (int)(4096.0f * parameters[14].ToFloat());

    *(int*)(*(char**)((char*)&data_020fdc14 + 0x4) + kWordBOffset) =
        (int)(4096.0f * parameters[15].ToFloat());

    return 1;
}
