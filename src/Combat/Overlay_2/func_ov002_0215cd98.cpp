#include <globaldefs.h>

struct Container020e0310;
extern "C" int _Z21GetFieldByKey020e0434P17Container020e0310i(struct Container020e0310 *c, int key);
extern "C" int _Z22AppendFrameTag02041c08Pciiiii(char *dst, int a1, int a2, int a3, int a4, int a5);
int AppendCursorTag(char *dst, int cursor);
int AppendNameTag(char *dst, int n, const char *name);
extern "C" int _Z20AppendString02042058PcPKc(char *dst, const char *src);
extern "C" int _Z23AppendFormatted02041facPcii(char *dst, int str, int b);
extern "C" void __clear(void *buf, int n);

struct DstHolder0215b8c8 {
    char *dst;
};
extern "C" void _Z27AppendTaggedString_0215b8c8P17DstHolder0215b8c8PKci(struct DstHolder0215b8c8 *holder, const char *str,
                                                                        int value);

// USA: func_ov002_0215cd98
extern "C" ARM void func_ov002_0215cd98(unsigned char *obj, char *dst, int flag) {
    if (dst == NULL) return;

    short id   = 0x4b0;
    int cursor = *(short *) (obj + 0x1bea);

    if (flag) {
        _Z22AppendFrameTag02041c08Pciiiii(dst, cursor, 8, 5, 5, 5);
    }
    AppendCursorTag(dst, cursor);

    const char *title =
        (const char *) _Z21GetFieldByKey020e0434P17Container020e0310i((Container020e0310 *) (obj + 0x20), id++);
    char buf[0x80];
    __clear(buf, 0x80);
    struct DstHolder0215b8c8 holder;
    holder.dst = buf;
    _Z27AppendTaggedString_0215b8c8P17DstHolder0215b8c8PKci(&holder, title, 0);
    _Z23AppendFormatted02041facPcii(dst, (int) buf, 0x10);

    for (int i = 0; i < 4; i++) {
        int field = _Z21GetFieldByKey020e0434P17Container020e0310i((Container020e0310 *) (obj + 0x20), id++);
        AppendNameTag(dst, i, (const char *) field);
        if (i != 3) {
            _Z20AppendString02042058PcPKc(dst, *(char **) (obj + 0x1bdc));
        }
    }
}
