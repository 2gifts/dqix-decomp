#include <globaldefs.h>
#include "World/Object3D.h"

extern "C" int func_ov017_021d60f4(int id);

struct Struct_203cec4;
void SetOrClearFlag0x8(struct Struct_203cec4* obj, int enable);
struct Struct_0203fc5c;
int SetField40IfPositive(struct Struct_0203fc5c* obj, float value);

struct Row02165880 {
    int type;
    char pad[0x8];
    void* obj;
};
struct TableHeader02165880 {
    void* unused0;
    struct Row02165880* rows;
};
extern struct TableHeader02165880 data_ov001_02165880;
extern int data_ov001_02165769;

struct EntryWithField14 {
    char pad[0x14];
    void* field14;
};

// USA: func_ov001_0216013c  (semantic: UpdateEntryFlagsByType_0216013c)
extern "C" ARM int func_ov001_0216013c(int id) {
    id = func_ov017_021d60f4(id);
    int type = data_ov001_02165880.rows[id].type;

    if (type == 2 || type == 6) {
        void* obj = 0;
        if (data_ov001_02165880.rows != 0) {
            obj = data_ov001_02165880.rows[id].obj;
        }
        if (obj == 0) {
            return 0;
        }
        if (((struct EntryWithField14*)obj)->field14 != 0) {
            SetOrClearFlag0x8((struct Struct_203cec4*)((struct EntryWithField14*)obj)->field14, 0);
        }
        if (((struct EntryWithField14*)obj)->field14 != 0) {
            SetField40IfPositive((struct Struct_0203fc5c*)((struct EntryWithField14*)obj)->field14, 1.0f);
        }
    } else if (type == 1 || type == 0 || (unsigned int)(type - 4) <= 1) {
        void* obj2 = 0;
        if (data_ov001_02165880.rows != 0) {
            obj2 = data_ov001_02165880.rows[id].obj;
        }
        if (obj2 == 0) {
            return 0;
        }
        ((Object3D*)obj2)->MaybeSetRegularAnimation((char const*)&data_ov001_02165769, 0);
    }

    return 1;
}
