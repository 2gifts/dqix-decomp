#include <globaldefs.h>

int AppendFrameTag02041c08(char* dst, int a1, int a2, int a3, int a4, int a5);
int AppendCursorTag_02041ea4(char* dst, int cursor);

// USA: func_ov002_02160190
ARM void AppendCursorFrameTag_02160190(char* base, char* dst, int flag) {
    if (flag) {
        int cursor = *(short*)(base + 0x1c06);
        AppendFrameTag02041c08(dst, cursor, 8, 5, 5, 5);
    }
    int cursor2 = *(short*)(base + 0x1c06);
    AppendCursorTag_02041ea4(dst, cursor2);
}
