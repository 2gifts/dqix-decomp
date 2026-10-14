#include <globaldefs.h>

int AppendFrameTag02041c08(char* dst, int a1, int a2, int a3, int a4, int a5);
int AppendCursorTag_02041ea4(char* dst, int cursor);

struct UnkStruct0205c508;
void ComputeProductSums0205c508(struct UnkStruct0205c508* s, int* out1, int* out2);

extern "C" void func_ov002_0215ece4(void* base, char* dst, int c, int productB, int clampedSum);

// USA: func_ov002_0215ec4c  (semantic: AppendCursorAndProductTag_0215ec4c)
extern "C" ARM void func_ov002_0215ec4c(void* base, char* dst, int flag) {
    int productB;
    int clampedSum;
    if (dst == 0) {
        return;
    }
    int cursor = *(short*)((char*)base + 0x1bfa) % 8;
    if (flag) {
        AppendFrameTag02041c08(dst, cursor, 8, 5, 5, 5);
    }
    AppendCursorTag_02041ea4(dst, cursor);
    void* mid = (void*)((char*)base + 0x2c8 + 0xc00);
    ComputeProductSums0205c508((struct UnkStruct0205c508*)((unsigned char*)mid + 0x54), &productB, &clampedSum);
    int c = *(signed char*)((char*)base + 0x1c20);
    func_ov002_0215ece4(base, dst, c, productB, clampedSum);
}
