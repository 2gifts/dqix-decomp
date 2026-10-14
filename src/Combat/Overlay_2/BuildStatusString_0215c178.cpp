#include <globaldefs.h>

extern "C" void* func_0205ec34(void* a0);
extern "C" int func_020420e8(int a, int b);
int TestBitInByteArray_0206dfb0(int unused, unsigned char* arr, int index);
int CallFunc020e0434With02153694_020e51cc(int value);
int AppendFrameTag02041c08(char* dst, int a1, int a2, int a3, int a4, int a5);
int AppendCursorTag_02041ea4(char* dst, int cursor);
int AppendPaletteTag_02041e70(char* dst, int palette);
int AppendNameTag_02041b70(char* dst, int n, const char* name);
int AppendString02042058(char* dst, const char* src);
int AppendXTag_02041a28(char* dst, int x);

extern short data_ov002_0216ca04[];
extern int data_ov002_0216ca58[];
extern char data_ov002_0216d26e;

// USA: func_ov002_0215c178
ARM void BuildStatusString_0215c178(void* a0, char* dst, int flag) {
    if (dst == NULL) return;
    char* sub = (char*)a0 + 0x1b00;
    short cursor = *(short*)(sub + 0xe0);
    void* p = func_0205ec34(sub);
    int hasBit = TestBitInByteArray_0206dfb0((int)(long)p, (unsigned char*)p + 0x8c, 4506) != 0;
    int maxVal = 0;
    for (int i = 0; i < 3; i++) {
        int v = func_020420e8(CallFunc020e0434With02153694_020e51cc(data_ov002_0216ca04[i]), 0);
        if (maxVal < v) maxVal = v;
    }
    if (flag != 0) {
        AppendFrameTag02041c08(dst, cursor, 8, 5, 5, 5);
    }
    AppendCursorTag_02041ea4(dst, cursor);
    for (int i = 0; i < 6; i++) {
        if (i == 3 && hasBit == 0) {
            AppendPaletteTag_02041e70(dst, 3);
        }
        int n = data_ov002_0216ca58[i];
        int name = CallFunc020e0434With02153694_020e51cc(data_ov002_0216ca04[n]);
        AppendNameTag_02041b70(dst, n, (const char*)(long)name);
        if (i == 1 || i == 3) {
            AppendString02042058(dst, &data_ov002_0216d26e);
        } else {
            AppendXTag_02041a28(dst, maxVal + 0x20);
        }
        if (i == 3 && hasBit == 0) {
            AppendPaletteTag_02041e70(dst, 15);
        }
    }
}
