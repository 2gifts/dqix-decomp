#include <globaldefs.h>

struct Fields020b1d48 {
    int field0;
    int width;
    int height;
    unsigned char format;
    unsigned char paddingD[3];
    int stride;
    void* vtable;
    Fields020b1d48* self;
    void* layer;
    int field20;
    int field24;
    int buffer;
    void* request;
};
struct Layer0223c560 { unsigned char data[8]; };
struct State0223c560 {
    Layer0223c560 layers[0x610 / 8];
    Fields020b1d48 backgrounds[2];
    unsigned char padding670[0xc];
    unsigned char requestArgs[2];
};
struct Dimension0223c560 { unsigned short value; unsigned short padding; };
extern State0223c560* data_ov031_02290d38;
extern Dimension0223c560 data_ov031_022493b2[];
extern Dimension0223c560 data_ov031_022493b0[];
extern const unsigned short data_ov031_022493ac[];
extern "C" int func_ov031_0223cf4c(unsigned int, int);
void InitFieldsWithData_020b1e94(Fields020b1d48*, int, int, int, int);
extern "C" void* GetSubBG0ScreenBase();
extern "C" void* GetMainBG0ScreenBase();
extern "C" void func_020b1f48(void*, int, int, int, int, int, int, int);
extern "C" void CallVTableField14_0223ca40(Fields020b1d48*, int);
extern "C" void func_ov031_0223c6d8();
void* CallWithZeroExtra_0223e218(void*, void*, void*, int);
#define REG_SUB_BG0CNT (*(volatile unsigned short*)0x04001008)
#define REG_MAIN_BG0CNT (*(volatile unsigned short*)0x04000008)

// USA: func_ov031_0223c560
extern "C" ARM Fields020b1d48* func_ov031_0223c560(int screen, int layer) {
    unsigned short height = data_ov031_022493b2[screen].value;
    unsigned short width = data_ov031_022493b0[screen].value;
    Fields020b1d48* background = &data_ov031_02290d38->backgrounds[screen];
    background->buffer = func_ov031_0223cf4c(width * height * 0x20, 0x20);
    if (screen == 1) {
        REG_SUB_BG0CNT &= ~0x40;
        REG_SUB_BG0CNT = (REG_SUB_BG0CNT & 0x43) | 0xc00;
    } else {
        REG_MAIN_BG0CNT &= ~0x40;
        REG_MAIN_BG0CNT = (REG_MAIN_BG0CNT & 0x43) | 0xc00;
    }
    InitFieldsWithData_020b1e94(background, background->buffer, width, height, 4);
    void* layerData = &data_ov031_02290d38->layers[layer];
    background->self = background;
    background->layer = layerData;
    background->field20 = 1;
    background->field24 = 1;
    void* screenBase = screen == 1 ? GetSubBG0ScreenBase() : GetMainBG0ScreenBase();
    int tile = data_ov031_022493ac[screen];
    func_020b1f48(screenBase, width, height, 0, 0, 0x20, tile, 0xf);
    CallVTableField14_0223ca40(background, 0);
    background->request = CallWithZeroExtra_0223e218((void*)1, (void*)func_ov031_0223c6d8, &data_ov031_02290d38->requestArgs[screen], 0xc8);
    return background;
}
