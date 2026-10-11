#include <globaldefs.h>

class GameState;
struct UnkStruct0205c508;
struct StoreStruct;
struct Container020dedd0;
struct KeyMap020a0b3c;

extern "C" GameState *_ZN9GameState11GetInstanceEv();
char *GetPtrField0x2a04(GameState *gs);
extern "C" void *_Z26GetGlobalField0x1c020421a0v();
extern "C" int _Z22AppendFrameTag02041c08Pciiiii(char *dst, int a1, int a2, int a3, int a4, int a5);
int AppendCursorTag(char *dst, int cursor);
int AppendNameTag(char *dst, int n, const char *name);
extern "C" int _Z20AppendString02042058PcPKc(char *dst, const char *src);
extern "C" void _Z26ComputeProductSums0205c508P17UnkStruct0205c508PiS1_(struct UnkStruct0205c508 *s, int *out1, int *out2);
extern "C" void func_02046380(void *messages);
void StoreInArray0x8b0(StoreStruct *messages, int index, int value);
extern "C" char *_Z24FindElementByKey020dedd0P17Container020dedd0i(Container020dedd0 *c, int key);
extern "C" void _Z37CopyTextAndUppercaseIfFlagged0206819cPKcPci(const char *src, char *dst, int flag);
extern "C" int _Z24LookupValueByKey020a0b3cP14KeyMap020a0b3ci(KeyMap020a0b3c *map, int key);
extern "C" void _Z31SetElementStateOrCreate0215b918Phiii(unsigned char *self, int a, int b, int c);
extern "C" void __clear(void *buf, int n);
extern "C" int sprintf(char *dst, const char *fmt, ...);
extern char data_ov002_0216d270[];

// USA: func_ov002_0215d950
extern "C" ARM void func_ov002_0215d950(char *p, char *dst, int flag2) {
    char name[0x100];
    char line[0x40];
    int out1, out2;
    char *tbl;
    int n;
    int i;
    int count;
    if (dst == 0) return;
    int cursor = *(short *) (p + 0x1be8) & 7;
    if (flag2) _Z22AppendFrameTag02041c08Pciiiii(dst, cursor, 8, 5, 5, 5);
    AppendCursorTag(dst, cursor);
    tbl       = GetPtrField0x2a04(_ZN9GameState11GetInstanceEv()) + 0xe04;
    void *msg = _Z26GetGlobalField0x1c020421a0v();
    char *fld = p + 0x2c8 + 0xc00;
    int sel   = *(int *) (fld + 0x68);
    count     = *(int *) (fld + 0x58);
    _Z26ComputeProductSums0205c508P17UnkStruct0205c508PiS1_((struct UnkStruct0205c508 *) (fld + 0x54), &out1, &out2);
    n = 0;
    for (i = out1; i < out2; i++) {
        func_02046380(msg);
        StoreInArray0x8b0((StoreStruct *) msg, 0, n);
        char *e = _Z24FindElementByKey020dedd0P17Container020dedd0i((Container020dedd0 *) (p + 0x3ec + 0x400),
                                                                    *(short *) (tbl + i * 2 + 0xc));
        if (e != 0) {
            __clear(name, sizeof(name));
            _Z37CopyTextAndUppercaseIfFlagged0206819cPKcPci(*(const char **) (e + 4), name, 0);
            AppendNameTag(dst, n, name);
            __clear(line, sizeof(line));
            sprintf(line, data_ov002_0216d270,
                    _Z24LookupValueByKey020a0b3cP14KeyMap020a0b3ci((KeyMap020a0b3c *) tbl, *(short *) (e + 0x18)));
            _Z20AppendString02042058PcPKc(dst, line);
            if (i != out2 - 1) _Z20AppendString02042058PcPKc(dst, *(char **) (p + 0x1000 + 0xbdc));
        }
        n++;
    }
    if (count > 1) _Z31SetElementStateOrCreate0215b918Phiii((unsigned char *) p, 10, sel, count);
}
