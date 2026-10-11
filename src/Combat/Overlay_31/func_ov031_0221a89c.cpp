#include <globaldefs.h>

extern "C" int func_ov031_02218b8c(void* self, int flag);
extern "C" void* func_ov031_02218e2c(void* self, const char* key);
int FindAndTerminate_02218e84(void* self, int key, char* buf, int size);
extern "C" void func_ov031_0221a218(void);
extern "C" int func_02005a94(const char* s);
void SetGlobal0224e5a4IfNotNine(int a, int b);

extern char* data_ov031_0224e69c;
extern char data_ov031_0224a298[];
extern char data_ov031_0224a2a0[];
extern char data_ov031_0224a2ac[];
extern char data_ov031_0224a2b8[];
extern char data_ov031_0224a2c0[];
extern char data_ov031_0224a2d0[];
extern int data_020f3390;

// USA: func_ov031_0221a89c  (semantic: ValidateConfigAndSetFlag_0221a89c)
#pragma optimize_for_size off
extern "C" ARM int func_ov031_0221a89c(void) {
    char buf[4];
    char* obj = data_ov031_0224e69c;
    if (func_ov031_02218b8c(obj + 8, 0) == 0) {
        SetGlobal0224e5a4IfNotNine(0x10, 0xffff9df3);
        return 0;
    }
    if (func_ov031_02218e2c(obj + 8, data_ov031_0224a298) != 0) {
        func_ov031_0221a218();
    }
    void* z = func_ov031_02218e2c(obj + 8, data_ov031_0224a2a0);
    if (z == 0) {
        SetGlobal0224e5a4IfNotNine(0x10, 0xffff9df3);
        return 0;
    }
    int code = func_02005a94((const char*)z);
    if (data_020f3390 == 0x22) {
        SetGlobal0224e5a4IfNotNine(0x10, 0xffff9df3);
        return 0;
    }
    if (code != 0xc8) {
        SetGlobal0224e5a4IfNotNine(0x10, 0xffff9e58 - code);
        return 0;
    }
    if (FindAndTerminate_02218e84(obj + 8, (int)data_ov031_0224a2ac, buf, 4) <= 0) {
        SetGlobal0224e5a4IfNotNine(0x10, 0xffff9df3);
        return 0;
    }
    code = func_02005a94(buf);
    if (data_020f3390 == 0x22) {
        SetGlobal0224e5a4IfNotNine(0x10, 0xffff9df3);
        return 0;
    }
    if (code >= 0x64) {
        SetGlobal0224e5a4IfNotNine(0x10, 0xffffa240 - code);
        return 0;
    }
    char* p = *(char**)(data_ov031_0224e69c + 0x1000 + 0xc1c);
    if (FindAndTerminate_02218e84(obj + 8, (int)data_ov031_0224a2b8, p + 4, 0x40) < 0) {
        goto fail_9df3;
    }
    p = *(char**)(data_ov031_0224e69c + 0x1000 + 0xc1c);
    if (FindAndTerminate_02218e84(obj + 8, (int)data_ov031_0224a2c0, p + 0x45, 0x12c) < 0) {
        goto fail_9df3;
    }
    if (FindAndTerminate_02218e84(obj + 8, (int)data_ov031_0224a2d0, buf, 1) < 0) {
    fail_9df3:
        SetGlobal0224e5a4IfNotNine(0x10, 0xffff9df3);
        return 0;
    }
    *(int*)(*(char**)(data_ov031_0224e69c + 0x1000 + 0xc1c)) = (buf[0] == 0x59) ? 1 : 0;
    return 1;
}
