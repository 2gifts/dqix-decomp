#include <globaldefs.h>

struct Container020e0310;
int GetFieldByKey020e0434(struct Container020e0310* c, int key);
int AppendString02042058(char* dst, const char* src);
extern "C" void func_ov002_02156080(void* self, short* arr, short* out);

struct StackTmp0215f644 {
    short pad0;
    short arr[9];
};

// USA: func_ov002_0215f644
ARM void AppendField0215f644(void* self, char* dst, int) {
    if (dst == NULL) {
        return;
    }
    struct StackTmp0215f644 tmp;
    func_ov002_02156080(self, tmp.arr, &tmp.pad0);
    int idx = *(short*)((char*)self + 0x1bfe);
    short val = tmp.arr[idx];
    int key = (short)(val + 0xfb4);
    int fmt = GetFieldByKey020e0434((struct Container020e0310*)((char*)self + 0x20), key);
    AppendString02042058(dst, (const char*)fmt);
}
