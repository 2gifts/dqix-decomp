#include <globaldefs.h>

struct RangeEntry020e58dc { int field0; int field4; int lo; int hi; int field10; };
struct RangeList020e58dc { RangeEntry020e58dc* base; int field4; int count; };

struct PlaybackInfo {
    char pad0[0x10];
    unsigned char isSet;
    char pad11;
    short id;
    unsigned int delay;
};

struct PlaybackState {
    int mute;
    int pending;
    void* allocator;
    char context[4];
    int started;
    volatile int ready;
    int bank;
    int displayed;
    unsigned int consecutive;
    unsigned int frames;
    int position;
    short* rightBuffer;
    short* leftBuffer;
    PlaybackInfo* info;
    int busy;
    int elapsed;
    unsigned long long startTime;
    volatile long long read;
    long long written;
};

extern PlaybackState data_ov016_0219d0c0;
void SleepCurrentContext(unsigned int ticks);
extern "C" RangeEntry020e58dc* _Z22FindRangeEntry020e58dcP17RangeList020e58dci(RangeList020e58dc* list, int key);
extern "C" int _Z27GetSomeConstByFlag_0218be5cv();
int CallIfNonNullBool_0218e708(void* object, void* destination, int stride, int mode);
extern "C" int _Z26CallIfNonNullBool_0218e72cPv(void* object);
extern "C" void* __clear(void* destination, int size);
extern "C" int _Z26GetGlobalField0x1c020421a0v();
extern "C" void func_02046608(void* context, int unused, int id, int bufferAddress, int d, int e, int f);
extern "C" void func_ov016_0218e240(unsigned short* destination, char* text, unsigned short color, int x, int y, unsigned char centered, int outline, int limit);

// USA: func_ov016_0218bec4
extern "C" ARM void func_ov016_0218bec4(void* object, int captionsAddress) {
    char buffer[0x200];
    int displayed;
    while (data_ov016_0219d0c0.ready == 0) {
    }
    while (data_ov016_0219d0c0.elapsed <= (displayed = data_ov016_0219d0c0.displayed)) {
        SleepCurrentContext(1);
    }
    data_ov016_0219d0c0.pending = 0;
    if (data_ov016_0219d0c0.consecutive < 2 ||
        data_ov016_0219d0c0.elapsed - displayed <= 1) {
        RangeEntry020e58dc* caption = _Z22FindRangeEntry020e58dcP17RangeList020e58dci((RangeList020e58dc*)captionsAddress, displayed);
        CallIfNonNullBool_0218e708(object, (void*)_Z27GetSomeConstByFlag_0218be5cv(), 0x100, 0);
        if (caption != 0 && caption->field4 == 0) {
            __clear(buffer, 0x200);
            func_02046608((void*)_Z26GetGlobalField0x1c020421a0v(), 0xc, caption->field10, (int)buffer, 0xe3, 0, 1);
            func_ov016_0218e240((unsigned short*)_Z27GetSomeConstByFlag_0218be5cv(), buffer, 0x7fff, 0, 0xa8, 1, 1, caption->field0);
            caption->field0 += 4;
        }
        data_ov016_0219d0c0.ready = 0;
    } else {
        _Z26CallIfNonNullBool_0218e72cPv(object);
        data_ov016_0219d0c0.consecutive = 0;
    }
    data_ov016_0219d0c0.displayed++;
    data_ov016_0219d0c0.consecutive++;
}
