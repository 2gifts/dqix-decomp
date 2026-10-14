#include <globaldefs.h>
#include "World/Object3D.h"

extern "C" int func_ov017_021d60f4(void*);
extern "C" float func_ov017_021d6110(void*);

struct Struct_203cec4;
struct Struct_0203fc5c;
void SetOrClearFlag0x8_0203cec4(struct Struct_203cec4* obj, int enable);
ARM int SetField40IfPositive(struct Struct_0203fc5c* obj, float value);

struct TableStruct02160070 { void* unused0; char* base; };
extern TableStruct02160070 data_ov001_02165880;
extern int data_ov001_021657db;

struct Entry02160070 { int word0; char pad[8]; void* fieldC; };
struct Member02160070 { char pad[0x14]; void* field14; };

// USA: func_ov001_02160070
extern "C" ARM int func_ov001_02160070(char* obj) {
    int idx = func_ov017_021d60f4(obj);
    float f = func_ov017_021d6110(obj + 8);
    Entry02160070* table = (Entry02160070*)data_ov001_02165880.base;
    int type = table[idx].word0;
    if (type == 2 || type == 6) {
        Member02160070* member = 0;
        if (table) member = (Member02160070*)table[idx].fieldC;
        if (member == NULL) return 0;
        if (member->field14 != NULL) SetOrClearFlag0x8_0203cec4((struct Struct_203cec4*)member->field14, 1);
        if (member->field14 != NULL) SetField40IfPositive((struct Struct_0203fc5c*)member->field14, f);
    } else if (type == 1 || type == 0 || type == 4 || type == 5) {
        void* member2 = 0;
        if (table) member2 = table[idx].fieldC;
        if (member2 == NULL) return 0;
        ((Object3D*)member2)->MaybeSetRegularAnimation((char const*)&data_ov001_021657db, 0);
    }
    return 1;
}
