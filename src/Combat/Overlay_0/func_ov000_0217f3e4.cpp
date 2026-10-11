#include <globaldefs.h>

#if defined(jpn)
#define REGION_OFFSET_0 0x1f98
#define REGION_OFFSET_1 0x1fa6
#define REGION_OFFSET_2 0x1fa1
#else
#define REGION_OFFSET_0 0x1d60
#define REGION_OFFSET_1 0x1d6e
#define REGION_OFFSET_2 0x1d69
#endif


struct Obj_0205dd08;
extern "C" int func_0205dd08(struct Obj_0205dd08* obj);
struct Struct_0205c4a8;
extern "C" void _Z33AdvanceWrappedAccumulator0205c4a8P15Struct_0205c4a8i(struct Struct_0205c4a8* s, int delta);
struct Struct_0205bb84;
extern "C" int _Z24ComputeScaledSum0205bb84P15Struct_0205bb84(struct Struct_0205bb84* s);
struct Struct_0205bcdc;
extern "C" void _Z23SetIndexIfValid0205bcdcP15Struct_0205bcdci(struct Struct_0205bcdc* s, int index);

struct Channel0217f3e4 {
    char data[0x50];
};

struct ListWidget0217f3e4 {
    int header;
    Channel0217f3e4 cursor;
    Channel0217f3e4 accumulator;
};

struct Menu0217f3e4 {
    char pad0[0x188];
    ListWidget0217f3e4 list;
    char pad1[REGION_OFFSET_0 - 0x22c];
    signed char kinds[8];
    signed char kindIndex;
    char pad2[REGION_OFFSET_1 - REGION_OFFSET_2];
    unsigned char valueKind6;
    unsigned char valueKind7;
};

struct MenuChannels0217f3e4 {
    char pad0[0x18c - sizeof(Channel0217f3e4)];
    Channel0217f3e4 channels[3];
    Channel0217f3e4* GetChannel(int i) { return &channels[i]; }
};

// USA: func_ov000_0217f3e4
extern "C" ARM int func_ov000_0217f3e4(struct Menu0217f3e4* menu) {
    int delta = func_0205dd08((struct Obj_0205dd08*)&menu->list);
    if (delta == 0) {
        return 0;
    }
    Channel0217f3e4* accumulator = ((MenuChannels0217f3e4*)menu)->GetChannel(2);
    Channel0217f3e4* cursor = ((MenuChannels0217f3e4*)menu)->GetChannel(1);
    _Z33AdvanceWrappedAccumulator0205c4a8P15Struct_0205c4a8i((struct Struct_0205c4a8*)accumulator, delta);
    int value = _Z24ComputeScaledSum0205bb84P15Struct_0205bb84((struct Struct_0205bb84*)accumulator);
    _Z23SetIndexIfValid0205bcdcP15Struct_0205bcdci((struct Struct_0205bcdc*)cursor, value);
    switch (menu->kinds[menu->kindIndex]) {
    case 6:
        menu->valueKind6 = value;
        break;
    case 7:
        menu->valueKind7 = value;
        break;
    }
    return 1;
}
