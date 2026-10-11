#include <globaldefs.h>

struct TileFillCtx020b1938 {
    char* dest;
    int width;
    int height;
    unsigned char depth;
    int pitch;
};

extern "C" void func_020ca458(unsigned int value, void* dest, int count);

// USA: func_020b1938
extern "C" ARM void func_020b1938(struct TileFillCtx020b1938* ctx, unsigned int val) {
    int depth = ctx->depth;
    if (depth == 4) {
        val = val | (val << 4);
        val = val | (val << 8);
        val = val | (val << 16);
    } else {
        val = val | (val << 8);
        val = val | (val << 16);
    }
    {
        int i;
        char* pos = ctx->dest;
        int rowlen = (depth << 6) / 8;
        int step = rowlen * ctx->pitch;
        rowlen = rowlen * ctx->width;
        i = 0;
        if (ctx->height <= 0) {
            return;
        }
        do {
            func_020ca458(val, pos, rowlen);
            pos += step;
            i++;
        } while (i < ctx->height);
    }
}
