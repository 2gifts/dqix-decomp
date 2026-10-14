#include <globaldefs.h>

struct Args0223d884 { int a, b, c, d; };
struct Args0223bf2c { int a, b, c, d; };
void ForwardFourArgsAsStruct_0223d884(Args0223d884);
void ForwardFourArgsAsStruct_0223bf2c(Args0223bf2c);
extern "C" unsigned int func_ov031_0223cf70(void**);
struct ResourcePair0223b870 {
    char pad_0[0x220];
    void* first;
    void* second;
};
extern ResourcePair0223b870* data_ov031_02290d28;
extern ResourcePair0223b870* data_ov031_02290d28_arg;

static inline void ReleaseFirstResource(void* resource) {
    typedef void (*ResourceRelease)(void*);
    ResourceRelease release = (ResourceRelease)ForwardFourArgsAsStruct_0223d884;
    release(resource);
}
static inline void ReleaseSecondResource(void* resource) {
    typedef void (*ResourceRelease)(void*);
    ResourceRelease release = (ResourceRelease)ForwardFourArgsAsStruct_0223bf2c;
    release(resource);
}

// USA: func_ov031_0223b870
extern "C" ARM void func_ov031_0223b870() {
    int i = 0;
    unsigned int offset = 0;
    do {
        ReleaseFirstResource(((ResourcePair0223b870*)((char*)data_ov031_02290d28 + offset))->first);
        ReleaseSecondResource(((ResourcePair0223b870*)((char*)data_ov031_02290d28 + offset))->second);
        i++;
        offset += sizeof(ResourcePair0223b870);
    } while (i < 2);
    func_ov031_0223cf70((void**)&data_ov031_02290d28_arg);
}
