#include <globaldefs.h>

struct Container020e0310;
int GetFieldByKey020e0434(struct Container020e0310* c, int key);
int AppendString02042058(char* dst, const char* src);

// USA: func_ov003_02159290
ARM void AppendFieldTwice_02159290(void* self, unsigned short a, int b) {
    int v1 = GetFieldByKey020e0434((struct Container020e0310*)((char*)self + 0x64), (int)(short)a);
    AppendString02042058(*(char**)((char*)self + 0x7c), (const char*)v1);
    int v2 = GetFieldByKey020e0434((struct Container020e0310*)((char*)self + 0x64), (int)(short)b);
    AppendString02042058(*(char**)((char*)self + 0x7c), (const char*)v2);
}
