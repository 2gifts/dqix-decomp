#include <globaldefs.h>
#pragma optimize_for_size off

extern "C" int func_020bd7c4(unsigned int index, void* buf, int size, int flag);

struct OutPair020bd88c;
void GetHolderPair020bd88c(struct OutPair020bd88c* out);

struct TwoWords020c0044 { int a; int b; };
#include "Filesystem/NitroVM.h"
bool NitroVM_PrepareReadFileByID(NitroVM* vm, NitroFileAccessor accessor);

int GetListEntryWord0020bd774(unsigned int index);

struct Obj020c0044 { char pad[0xa4]; int fieldA4; };

// USA: func_020c0044
ARM int InitStreamFromEntry020c0044(struct Obj020c0044* obj, unsigned int index) {
    if (func_020bd7c4(index, (char*)obj + 0xa8, 0x40, 0) != 0x40) {
        return 0;
    }
    struct TwoWords020c0044 local;
    GetHolderPair020bd88c((struct OutPair020bd88c*)&local);
    if (NitroVM_PrepareReadFileByID((NitroVM*)((char*)obj + 0x5c), *(NitroFileAccessor*)&local) == 0) {
        return 0;
    }
    obj->fieldA4 = GetListEntryWord0020bd774(index);
    return 1;
}
