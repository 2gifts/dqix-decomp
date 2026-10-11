#include <globaldefs.h>

struct FrameDecoder_0218f340 {
    unsigned char* input;
    void* output;
    unsigned char state[0x14f0];
};
struct Stream_0218f340 {
    unsigned char field_0x00[0x1c];
    unsigned short format;
    unsigned short frameCount;
    unsigned char field_0x20[0x14];
    unsigned char** input;
    unsigned char field_0x38[0x20];
    FrameDecoder_0218f340* decoders;
    unsigned char field_0x5c[0x48];
#if !defined(jpn)
    int reset;
#endif
    unsigned char field_0xa8[0x20];
    int available;
    int consumed;
    int frame;
};
extern "C" int func_ov016_0219000c(FrameDecoder_0218f340*);
extern "C" void func_ov016_021909cc_unk(FrameDecoder_0218f340*);
extern "C" void func_ov016_0218fea0(FrameDecoder_0218f340*, unsigned char*);
extern "C" void func_ov016_0218feb4(FrameDecoder_0218f340*, unsigned char*, int, void*);
extern "C" void func_020ca3b8(void*, void*, int);

// USA: func_ov016_0218f340
extern "C" ARM int func_ov016_0218f340(Stream_0218f340* stream, void* output) {
    if (stream->consumed == stream->available) return 0;
    if (stream->format == 0) return 0;
    if (stream->format == 1) {
        stream->decoders[stream->frame].input = *stream->input;
        stream->decoders[stream->frame].output = output;
        *stream->input += func_ov016_0219000c(&stream->decoders[stream->frame]);
    } else
#if !defined(jpn)
    if (stream->format == 2)
#endif
    {
        stream->decoders[stream->frame].input = *stream->input;
        stream->decoders[stream->frame].output = output;
        func_ov016_021909cc_unk(&stream->decoders[stream->frame]);
        *stream->input += 0x28;
    }
#if !defined(jpn)
    else if (stream->format == 3) {
        if (stream->reset == 1) {
            func_ov016_0218fea0(&stream->decoders[stream->frame], *stream->input);
            *stream->input += 4;
        }
        func_ov016_0218feb4(&stream->decoders[stream->frame], *stream->input, 0x80, output);
        *stream->input += 0x80;
    } else {
        func_020ca3b8(*stream->input, output, 0x200);
        *stream->input += 0x200;
    }
#endif
    if (++stream->frame == stream->frameCount) {
        stream->frame = 0;
#if !defined(jpn)
        stream->reset = 0;
#endif
    }
    ++stream->consumed;
    return 1;
}
