#include <globaldefs.h>

int AppendString02042058(char* dst, const char* src);

struct Container021e8cc0 { char pad1[0x5d8]; char* field5d8; char pad2[0x5fc - 0x5dc]; char* field5fc; };

#if defined(jpn)
#include "std_library_functions.h"
extern "C" void func_020420e8(char*, int);
struct TableA68;
char* FindEntryByKey_02072a68(TableA68*, int);
int AppendXYTag_02041a90(char*, int, int);
#endif

// USA: func_ov023_021e8cc0
ARM void CallAppendStringIfSet_021e8cc0(struct Container021e8cc0* obj) {
#if defined(jpn)
    char* dst;
    char* src = obj->field5fc;
    if (src == 0) return;
    dst = obj->field5d8;
    func_020420e8(dst, 8);
    dst += strlen(dst);
    for (int row = 1; row <= 2; ++row) {
        char* found = strstr(src, FindEntryByKey_02072a68(*(TableA68**)((char*)obj + 0x5f4), 0));
        if (!found) continue;
        int length = found - src;
        memcpy(dst, src, length);
        dst += length;
        src += length + 2;
        AppendXYTag_02041a90(dst, 1, row * 0x13 + 8);
        dst += strlen(dst);
    }
    memcpy(dst, src, strlen(src));
#else
	if (obj->field5fc == 0) return;
	AppendString02042058(obj->field5d8, obj->field5fc);
#endif
}
