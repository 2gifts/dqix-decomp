#include <globaldefs.h>

int StringLength_020d2ff0(const char* s);
extern "C" int sprintf(void* dest, const void* fmt);

extern char data_020eff4d;
extern char data_020eff57;
extern char data_020eff61;
extern char data_020eff6b;

// USA: func_02041dd0
ARM int FormatCombatLogSuffix02041dd0(char* buf, int index) {
    char* p = buf + StringLength_020d2ff0(buf);
    switch (index) {
        case 0:
            p += sprintf(p, &data_020eff4d);
            break;
        case 5:
            p += sprintf(p, &data_020eff57);
            break;
        case 4:
            p += sprintf(p, &data_020eff61);
            break;
        case 6:
            p += sprintf(p, &data_020eff6b);
            break;
        default:
            break;
    }
    return p - buf;
}
