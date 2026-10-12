#include <globaldefs.h>

extern char* data_02105244;
extern "C" void func_02042764(void* entry, int arg, int zero);

#if defined(jpn)
int StringLength(const char*);
extern "C" void* memcpy(void*, const void*, unsigned int);
// USA: func_0203c248
extern "C" ARM void func_0203bdf4(char* obj, char* output) {
    char* base = data_02105244;
    if (base == NULL) return;
    char* entries;
    int used = 0;
    int slot = 0;
    entries = base + 4;
    while (slot < 10) {
        short index = ((short*)obj)[slot];
        if (index >= 0) {
            char* entry = entries + index * 0x10;
            int length = StringLength(entry + 4);
            memcpy(output + used, entry + 4, length);
            used += length;
            slot++;
        }
        slot++;
    }
}
#else
// USA: func_0203c248
ARM void InvokeGlobalEntry0203c248(char* obj, int arg1) {
    char* base = data_02105244;
    char* arr;
    short idx;
    if (base == NULL) return;
    arr = base + 4;
    idx = *(short*)(obj + 0x14);
    if (idx < 0) return;
    func_02042764(arr + idx * 0x28, arg1, 0);
}
#endif
