#include <globaldefs.h>

struct BytePair { unsigned char values[2]; };
extern BytePair data_ov031_02248d8c;
struct IndexedBuffer {
    unsigned char index;
    char pad[3];
    int buffer;
};
extern IndexedBuffer data_ov031_02290c50;
extern "C" void func_ov031_02234ff8(int, int, int);

// USA: func_ov031_0222855c
extern "C" ARM void func_ov031_0222855c(void) {
    BytePair values = data_ov031_02248d8c;
    unsigned int index = data_ov031_02290c50.index;
    unsigned char* table = values.values;
    int value = table[index];
    func_ov031_02234ff8(data_ov031_02290c50.buffer, value, value);
}
