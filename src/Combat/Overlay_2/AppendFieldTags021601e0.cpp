#include <globaldefs.h>

struct Container020e0310;

int AppendXTag_02041a28(char* dst, int x);
int GetFieldByKey020e0434(struct Container020e0310* c, int key);
int AppendDotLeaderLabel02042084(char* buffer, char* label, int width, int extra);
int AppendLineTag02041cc0(char* dst, int a1);
int AppendXYTag_02041a90(char* dst, int x, int y);

// USA: func_ov002_021601e0
ARM void AppendFieldTags021601e0(char* obj, char* dst, int) {
    struct Container020e0310* c;
    int field;

    if (dst == NULL) return;

    AppendXTag_02041a28(dst, 0);

    c = (struct Container020e0310*)(obj + 0x20);
    field = GetFieldByKey020e0434(c, 0x1130);
    AppendDotLeaderLabel02042084(dst, (char*)field, 0x48, 0);

    AppendLineTag02041cc0(dst, 0x10);
    AppendXYTag_02041a90(dst, 0, 0x3a);

    field = GetFieldByKey020e0434(c, (short)(*(short*)(obj + 0x1c00 + 0x6) + 0x31 + 0x1100));
    AppendDotLeaderLabel02042084(dst, (char*)field, 0x48, 0);
}
