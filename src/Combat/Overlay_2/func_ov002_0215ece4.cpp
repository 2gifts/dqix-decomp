#include <globaldefs.h>

int AppendNameTag_02041b70(char* dst, int n, const char* name);
int AppendString02042058(char* dst, const char* src);
void SetElementStateOrCreate0215b918(unsigned char* obj, int key, int b, int c);

// USA: func_ov002_0215ece4  (semantic: AppendEntryTagsAndFinalize_0215ece4)
extern "C" ARM void func_ov002_0215ece4(void* base, char* dst, int c, int productB, int clampedSum) {
    char* obj = (char*)base;
    char* buf;
    int last;
    int tag = 0;
    int inRange = (c >= 0) && (c <= 3);

    if (inRange) {
        int i;
        last = clampedSum - 1;
        buf = obj + 0x1000;
        for (i = productB; i < clampedSum; i++) {
            void* entry = *(void**)(obj + (i << 2) + 0x2000 + 0x4a0);
            if (entry != 0) {
                const char* name = *(const char**)entry;
                AppendNameTag_02041b70(dst, tag, name);
                if (i != last) {
                    AppendString02042058(dst, *(char**)(buf + 0xbdc));
                }
                tag++;
            }
        }
    }

    unsigned char flagByte = *(unsigned char*)(obj + 0x2000 + 0x520);
    if (flagByte == 0) {
        SetElementStateOrCreate0215b918((unsigned char*)obj, 0x11, 0, 0);
        return;
    }
    SetElementStateOrCreate0215b918((unsigned char*)obj, 0x11, productB / 8, (flagByte + 7) / 8);
}
