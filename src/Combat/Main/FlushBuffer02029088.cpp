#include <globaldefs.h>

#if defined(jpn)
struct GfxBufferHolder { char pad[4]; void* buffer; };
extern GfxBufferHolder data_020fe6fc;
#define data_020fe9a4 data_020fe6fc.buffer
#define FlushBuffer02029088 func_020288d8
extern "C" ARM void func_020288d8();
int GetData02107800Word0(void);
extern "C" void* memcpy(void*, const void*, unsigned int);
#else
extern void* data_020fe9a4;
#endif
void CleanInvalidateCacheRange(const void* addr, unsigned int size);

// USA: func_02029088
ARM void FlushBuffer02029088() {
    if (data_020fe9a4 == NULL) return;
#if defined(jpn)
    char* scratch = (char*)GetData02107800Word0();
    char* buffer = (char*)data_020fe9a4;
    char* out;
    char* in;
    unsigned int offset;
    unsigned int block;
    unsigned int column;
    unsigned int row;
    unsigned int start;
    for (block = 0; block < 0x18; block++) {
        offset = block * 0x400;
        out = scratch;
        start = offset;
        for (column = 0; column < 0x20; column++) {
            in = buffer + offset;
            for (row = 0; row < 8; row++) {
                memcpy(out, in, 4);
                out += 4;
                in += 0x80;
            }
            offset += 4;
        }
        memcpy(buffer + start, scratch, 0x400);
    }
#endif
    CleanInvalidateCacheRange((const void*)((int)data_020fe9a4), 0x6000);
}
