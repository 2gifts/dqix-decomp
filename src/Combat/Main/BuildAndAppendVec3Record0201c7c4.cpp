#include "World/ZoneWarpScript.h"
#include <globaldefs.h>

// USA: func_0201c7c4
ARM int WarpScript_Opcode_65_0201c7c4(Script::Parameter *arg0, int count) {
    const char* extra1;
    const char* extra2;
    int id;
    Vector3fix vec3;
    Script::Parameter *ret;
    const char* name;

    id = arg0->ToInt();
    ret = arg0[1].ToVec3fix(&vec3);
    arg0 = ret + 1;
    name = ret->ToString();
    extra1 = NULL;
    extra2 = NULL;
    if (count >= 6) {
        extra1 = arg0->ToString();
        arg0++;
    }
    if (count >= 7) {
        extra2 = arg0->ToString();
    }
    if (name == NULL) return 0;

    {
        ZoneFeatures::Opcode64Entry entry;
        entry.unk_0 = id;
        entry.vector_4.vec = vec3;
        strcpy(entry.string_10, name);
        if (extra1 == NULL) entry.string_20[0] = 0; else strcpy(entry.string_20, extra1);
        if (extra2 == NULL) entry.string_30[0] = 0; else strcpy(entry.string_30, extra2);
        data_020fdc20.warp->CreateOpcode64Entry_0201e304(entry);
    }
    return 1;
}
