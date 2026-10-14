#include <globaldefs.h>
#include "Resource/Script.h"

struct ResetStruct;

struct StreamState;
struct StreamHeader;

struct Struct02030774;

extern int data_020fdd30;
extern int data_020ef6f4;

// USA: func_02028048
ARM void RunBufferedScript_02028048(int handler0, int handler1, struct StreamHeader* buffer, int length) {
    char local[0x430];
    *(int*)&data_020fdd30 = handler0;
    *(int*)((char*)&data_020fdd30 + 4) = handler1;
    ((Script*)((struct ResetStruct*)local))->Initialize();
    ((Script*)((struct ResetStruct*)local))->SetOpcodeLookup((Script::OpcodeLookupEntry*)&data_020ef6f4);
    ((Script*)((struct StreamState*)local))->Load(buffer, length);
    ((Script*)((struct Struct02030774*)local))->Execute();
    *(int*)((char*)&data_020fdd30 + 4) = 0;
    *(int*)&data_020fdd30 = 0;
}
