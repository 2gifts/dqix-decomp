#include <globaldefs.h>
#include <System/BGBases.h>

struct RangeEntry020e58dc { int field0; int field4; int lo; int hi; int field10; };
struct RangeList020e58dc { RangeEntry020e58dc* base; int field4; int count; };

struct DualPlaybackState {
    int pending;
    int bank;
    char context[4];
    int started;
    void* info;
    int busy;
    int elapsed;
    int displayed;
    unsigned int consecutive;
    unsigned int frames;
    int position;
    short* buffer;
    volatile int ready;
    unsigned int writtenLow;
    unsigned int writtenHigh;
    unsigned int startTimeLow;
    unsigned int startTimeHigh;
    volatile unsigned int readLow;
    volatile unsigned int readHigh;
};

extern DualPlaybackState data_ov016_0219d144;
void SleepCurrentContext(unsigned int ticks);
RangeEntry020e58dc* FindRangeEntry020e58dc(RangeList020e58dc* list, int key);
int CallIfNonNullBool_0218e708(void* object, void* destination, int stride, int mode);
int CallIfNonNullBool_0218e72c(void* object);
extern "C" void func_ov016_0218e240(unsigned short* destination, char* text, unsigned short color, int x, int y, unsigned char centered, int outline, int limit);

// USA: func_ov016_0218d0d4
extern "C" ARM void func_ov016_0218d0d4(void* first, void* second, int captionsAddress) {
    int displayed;
    while (data_ov016_0219d144.ready == 0) {
    }
    while (data_ov016_0219d144.elapsed <= (displayed = data_ov016_0219d144.displayed)) {
        SleepCurrentContext(1);
    }
    data_ov016_0219d144.pending = 0;
    if (data_ov016_0219d144.consecutive < 2 ||
        data_ov016_0219d144.elapsed - displayed <= 1) {
        RangeEntry020e58dc* caption = FindRangeEntry020e58dc((RangeList020e58dc*)captionsAddress, displayed);
        unsigned short* destination;
        if (data_ov016_0219d144.bank == 0) {
            destination = (unsigned short*)0x06820000;
        } else {
            destination = (unsigned short*)0x06800000;
        }
        CallIfNonNullBool_0218e708(first, destination, 0x100, 0);
        if (caption != 0 && caption->field4 == 0) {
            func_ov016_0218e240(destination, (char*)caption->field10, 0x7fff, 0, 0xa8, 1, 1, caption->field0);
            caption->field0 += 4;
        }
        if (data_ov016_0219d144.bank == 0) {
            destination = (unsigned short*)0x06600000;
        } else {
            destination = (unsigned short*)GetSubBG2ScreenBase();
        }
        CallIfNonNullBool_0218e708(second, destination, 0x100, 0);
        if (caption != 0 && caption->field4 == 1) {
            func_ov016_0218e240(destination, (char*)caption->field10, 0xffff, 0, 0xa8, 1, 1, caption->field0);
            caption->field0 += 4;
        }
        data_ov016_0219d144.ready = 0;
    } else {
        CallIfNonNullBool_0218e72c(first);
        CallIfNonNullBool_0218e72c(second);
        data_ov016_0219d144.consecutive = 0;
    }
    data_ov016_0219d144.displayed++;
    data_ov016_0219d144.consecutive++;
}
