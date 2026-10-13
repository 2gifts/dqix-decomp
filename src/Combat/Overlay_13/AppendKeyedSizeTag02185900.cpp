#include <globaldefs.h>

#if defined(jpn)
#define AppendSizeTag func_02042428
#define func_ov013_02185900 func_ov013_02186aec
#endif

struct SkillPointMenu {
#if defined(jpn)
    char unknown0[0x5ac];
#else
    char unknown0[0x620];
#endif
    char texts[0x18];
    unsigned char unknownStateBytes[4];
    unsigned char state;
};

#if defined(jpn)
enum { CancelMessage = 2000, ConfirmMessage = 2001, PointLimitMessage = 2002 };
extern "C"
#else
enum { CancelMessage = 1000, ConfirmMessage = 1001, PointLimitMessage = 1002 };
#endif
int AppendSizeTag(char* dst, int size);
struct Container020e0310;
int GetFieldByKey020e0434(Container020e0310* texts, int key);
int AppendString02042058(char* dst, const char* src);

// USA: func_ov013_02185900
extern "C" ARM void func_ov013_02185900(SkillPointMenu* menu, char* dst) {
    AppendSizeTag(dst, 12);

    unsigned char state = menu->state;
    if (state == 4) {
        AppendString02042058(dst, (const char*)GetFieldByKey020e0434((Container020e0310*)menu->texts, CancelMessage));
    } else if (state == 3) {
        AppendString02042058(dst, (const char*)GetFieldByKey020e0434((Container020e0310*)menu->texts, ConfirmMessage));
    } else if (state == 2) {
        AppendString02042058(dst, (const char*)GetFieldByKey020e0434((Container020e0310*)menu->texts, PointLimitMessage));
    }
}
