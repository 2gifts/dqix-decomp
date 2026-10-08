#include <globaldefs.h>
#include <std_library_functions.h>

extern "C" void* __clear(void* dst, int count);
extern "C" int func_ov005_02158b3c(void* object, void* buffer);
extern "C" void func_0205d304(void* renderer, void* buffer, int a, int b, bool c, bool d, void* styles, bool e);

struct RenderView_021589f4 {
    unsigned char pad0[0xa0];
    short fielda0, fielda2, fielda4, fielda6;
    short fielda8, fieldaa, fieldac, fieldae;
    unsigned char fieldb0, fieldb1, fieldb2, fieldb3, fieldb4, fieldb5, fieldb6, fieldb7;
};

// USA: func_ov005_021589f4
extern "C" ARM void func_ov005_021589f4(void* object) {
    unsigned char* base = (unsigned char*)object;
    unsigned int selector = base[0x3dd1];
    int mode = 1;
    RenderView_021589f4* view = (RenderView_021589f4*)(base + 0xee4);
    if (selector >= 8 && selector <= 14) {
        view->fielda0 = 32;
        view->fielda2 = 9;
        mode = 0;
        view->fielda4 = 0;
        view->fielda6 = 15;
        view->fieldac = 12;
        view->fieldae = 20;
        view->fieldb7 = 12;
        view->fielda8 = 12;
        view->fieldaa = 11;
    } else {
        view->fielda0 = 24;
        view->fielda2 = 5;
        view->fielda4 = 4;
        view->fielda6 = 10;
        view->fieldac = 10;
        view->fieldae = 14;
        view->fieldb7 = 10;
        view->fielda8 = 6;
        view->fieldaa = 9;
    }
    view->fieldb1 = 0;
    view->fieldb5 = 0;
    view->fieldb6 = 0;
    memset(*(void**)(base + 0xe10), 0, 0x960);
    int result = func_ov005_02158b3c(object, *(void**)(base + 0xe10));
    unsigned char styles[4];
    bool special = false;
    __clear(styles, 4);
    if (result != 0) {
        special = true;
        for (int i = 1; i < 4; i++) styles[i] = 2;
    }
    func_0205d304(view, *(void**)(base + 0xe10), 0, mode, false, special, styles, false);
}
