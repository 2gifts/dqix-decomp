#include <globaldefs.h>

struct Container020e0310;
int GetFieldByKey020e0434(struct Container020e0310 *c, int key);
int AppendFrameTag02041c08(char *dst, int a1, int a2, int a3, int a4, int a5);
int AppendCursorTag(char *dst, int cursor);
int AppendNameTag(char *dst, int n, const char *name);
int AppendString02042058(char *dst, const char *src);
int AppendFormatted02041fac(char *dst, int str, int b);
extern "C" void __clear(void *buf, int n);

struct DstHolder0215b8c8 {
    char *dst;
};
void AppendTaggedString_0215b8c8(struct DstHolder0215b8c8 *holder, const char *str,
                                                                        int value);

// USA: func_ov002_0215cd98
extern "C" ARM void func_ov002_0215cd98(unsigned char *obj, char *dst, int flag) {
    if (dst == NULL) return;

    short id   = 0x4b0;
    int cursor = *(short *) (obj + 0x1bea);

    if (flag) {
        AppendFrameTag02041c08(dst, cursor, 8, 5, 5, 5);
    }
    AppendCursorTag(dst, cursor);

    const char *title =
        (const char *) GetFieldByKey020e0434((Container020e0310 *) (obj + 0x20), id++);
    char buf[0x80];
    __clear(buf, 0x80);
    struct DstHolder0215b8c8 holder;
    holder.dst = buf;
    AppendTaggedString_0215b8c8(&holder, title, 0);
    AppendFormatted02041fac(dst, (int) buf, 0x10);

    for (int i = 0; i < 4; i++) {
        int field = GetFieldByKey020e0434((Container020e0310 *) (obj + 0x20), id++);
        AppendNameTag(dst, i, (const char *) field);
        if (i != 3) {
            AppendString02042058(dst, *(char **) (obj + 0x1bdc));
        }
    }
}
