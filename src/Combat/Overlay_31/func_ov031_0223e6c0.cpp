#include <globaldefs.h>

typedef void* (*AllocateCallback)(unsigned int, unsigned int);
typedef void (*FreeCallback)(void*);
struct NetworkContext {
    int field0;
    int handle;
    void* secret;
    AllocateCallback allocate;
    void* identity;
    int active;
    void* callback;
    int error;
    FreeCallback release;
    int state;
    int field28, field2c, field30;
};
extern NetworkContext data_ov031_02290da0;
extern unsigned char data_ov031_02290de0[], data_ov031_02290e28[], data_ov031_02290dd4[], data_ov031_02290e0c[], data_ov031_02290df4[];
extern "C" void func_ov031_0223fae8(void*);
extern "C" void _Z27LogEventCategory33_0223ea60i(int);
extern "C" void* func_ov031_0223e674(const char*);
extern "C" int func_ov031_0223e454(void*, const void*, int);
extern "C" int _Z30ClearFourWordsAndFlag_0223fa34v();
extern "C" int _Z31ClearFourWords02290fa4_0223f9f0v();
extern "C" int func_ov031_0223fcd4(AllocateCallback, FreeCallback, int);
extern "C" int func_ov031_0223e8d4(void*);
extern "C" void func_ov031_0223fa08();

// USA: func_ov031_0223e6c0
extern "C" ARM int func_ov031_0223e6c0(AllocateCallback allocate, FreeCallback release, const char* identity, const char* secret, const void* identifier, const void* token, void* callback) {
    data_ov031_02290da0.allocate = allocate;
    data_ov031_02290da0.release = release;
    data_ov031_02290da0.callback = callback;
    data_ov031_02290da0.error = 0;
    data_ov031_02290da0.field28 = 0;
    data_ov031_02290da0.field2c = 0;
    data_ov031_02290da0.field30 = 0;
    data_ov031_02290da0.handle = 0;
    data_ov031_02290da0.state = -1;
    data_ov031_02290da0.secret = 0;
    data_ov031_02290da0.identity = 0;
    func_ov031_0223fae8(data_ov031_02290de0);
    _Z27LogEventCategory33_0223ea60i((int)data_ov031_02290e28);
    if ((data_ov031_02290da0.identity = func_ov031_0223e674(identity)) &&
        (data_ov031_02290da0.secret = func_ov031_0223e674(secret))) {
        int length = func_ov031_0223e454(data_ov031_02290dd4, identifier, 4);
        data_ov031_02290dd4[length] = 0;
        length = func_ov031_0223e454(data_ov031_02290e0c, token, 16);
        data_ov031_02290e0c[length] = 0;
        if (_Z30ClearFourWordsAndFlag_0223fa34v() && _Z31ClearFourWords02290fa4_0223f9f0v()) {
            if (func_ov031_0223fcd4(allocate, release, 10)) {
                data_ov031_02290da0.handle = func_ov031_0223e8d4(data_ov031_02290df4);
                data_ov031_02290da0.active = 1;
                return 1;
            }
            func_ov031_0223fa08();
        }
        data_ov031_02290da0.release(data_ov031_02290da0.secret);
        data_ov031_02290da0.release(data_ov031_02290da0.identity);
        data_ov031_02290da0.error = 8;
        return 0;
    }
    if (data_ov031_02290da0.secret) data_ov031_02290da0.release(data_ov031_02290da0.secret);
    if (data_ov031_02290da0.identity) data_ov031_02290da0.release(data_ov031_02290da0.identity);
    data_ov031_02290da0.error = 1;
    return 0;
}
