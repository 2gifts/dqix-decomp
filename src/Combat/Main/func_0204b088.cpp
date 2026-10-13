#include <globaldefs.h>

typedef void (*Transfer0204b088)(void*, int, unsigned int);
extern unsigned int data_020e7b98[][4];
extern Transfer0204b088 data_020f0218[][4];
struct TransferBuffer0204b088 {
    char pad[0x14];
    void* buffer;
    unsigned int sizeIndex;
    unsigned char source : 4;
    unsigned char destination : 4;
    char pad1d[2];
    unsigned char mode;
};

// USA: func_0204b088
extern "C" ARM void func_0204b088(TransferBuffer0204b088* transfer, void* buffer) {
    if (!buffer) buffer = transfer->buffer;
    if (!buffer) return;
    unsigned int source = transfer->source;
    unsigned int destination = transfer->destination;
    unsigned int mode = transfer->mode;
    unsigned int sizeIndex = transfer->sizeIndex;
    unsigned int size = data_020e7b98[mode][sizeIndex];
    Transfer0204b088 handler = data_020f0218[source][destination];
    transfer = (TransferBuffer0204b088*)buffer;
    handler(transfer, 0, size);
}
