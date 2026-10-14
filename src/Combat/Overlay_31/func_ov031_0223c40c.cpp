#include <globaldefs.h>

struct AllocatorContext0223c40c {
    char padding[0x670];
    int allocator;
    int queues[2];
};
struct Args0223bf2c;
extern AllocatorContext0223c40c* data_ov031_02290d38;
extern AllocatorContext0223c40c* data_ov031_02290d38_dup;
extern "C" void func_ov031_0223b710(int);
extern "C" void func_ov031_0223cf70(void*);
void ForwardFourArgsAsStruct_0223bf2c(Args0223bf2c);
typedef void (*FreeHandle0223c40c)(int);

// USA: func_ov031_0223c40c
extern "C" ARM void func_ov031_0223c40c() {
    int i = 0;
    do {
        func_ov031_0223b710(data_ov031_02290d38->queues[i]);
        i++;
    } while (i < 2);
    ((FreeHandle0223c40c)ForwardFourArgsAsStruct_0223bf2c)(data_ov031_02290d38->allocator);
    func_ov031_0223cf70(&data_ov031_02290d38_dup);
}
