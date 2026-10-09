#include <globaldefs.h>
#include "Resource/Script.h"
#include "Memory/SafeAllocator.h"

int StringLength(const char*);
struct ScriptRecord021aca2c {
    char* first;
    char* second;
    char* third;
    short* values;
    unsigned short id;
    short index;
    unsigned char field_14;
    unsigned char field_15;
    unsigned char count;
    unsigned char loaded;
};
struct ScriptStorage021aca2c {
    SafeAllocator* allocator;
    ScriptRecord021aca2c* record;
};
extern ScriptStorage021aca2c data_ov017_021d83cc;

// USA: func_ov017_021aca2c
extern "C" ARM int func_ov017_021aca2c(Script::Parameter* params, int count) {
    int id = params[0].ToInt();
    if (data_ov017_021d83cc.record->id != id) return 1;
    int index = params[1].ToInt();
    if (data_ov017_021d83cc.record->index != index) return 1;
    if (index < 0) return 1;
    data_ov017_021d83cc.record->field_14 = params[2].ToInt();
    data_ov017_021d83cc.record->field_15 = params[3].ToInt();
    const char* text = params[4].ToString();
    if (text) {
        int length = StringLength(text);
        if (length) {
            data_ov017_021d83cc.record->first = (char*)data_ov017_021d83cc.allocator->Allocate(length + 1);
            memset(data_ov017_021d83cc.record->first, 0, length + 1);
            memcpy(data_ov017_021d83cc.record->first, text, length);
            data_ov017_021d83cc.record->first[length] = 0;
        }
    }
    text = params[5].ToString();
    if (text) {
        int length = StringLength(text);
        if (length) {
            data_ov017_021d83cc.record->second = (char*)data_ov017_021d83cc.allocator->Allocate(length + 1);
            memset(data_ov017_021d83cc.record->second, 0, length + 1);
            memcpy(data_ov017_021d83cc.record->second, text, length);
            data_ov017_021d83cc.record->second[length] = 0;
        }
    }
    Script::Parameter* lastText = params + 6;
    params += 7;
    text = lastText->ToString();
    if (text) {
        int length = StringLength(text);
        if (length) {
            data_ov017_021d83cc.record->third = (char*)data_ov017_021d83cc.allocator->Allocate(length + 1);
            memset(data_ov017_021d83cc.record->third, 0, length + 1);
            memcpy(data_ov017_021d83cc.record->third, text, length);
            data_ov017_021d83cc.record->third[length] = 0;
        }
    }
    if (count - 7) {
        data_ov017_021d83cc.record->count = count - 7;
        data_ov017_021d83cc.record->values = (short*)data_ov017_021d83cc.allocator->Allocate((count - 7) * 2);
        for (int i = 0; i < count - 7; ++params, ++i) {
            data_ov017_021d83cc.record->values[i] = params->ToInt();
        }
    }
    data_ov017_021d83cc.record->loaded = 1;
    return 1;
}
