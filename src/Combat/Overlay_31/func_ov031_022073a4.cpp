#include <globaldefs.h>

struct SocketAddress022073a4;
extern "C" ARM int func_ov031_022073a4(int socket, int buffer, int size, int flags, const SocketAddress022073a4* destination);

// USA: func_ov031_0221e5a0  (semantic: StoreByteAndForward_0221e5a0)
extern "C" THUMB int func_ov031_0221e5a0(int socket, const void* buffer, int size, int flags, void* destination, int addressSize) {
    *(unsigned char*)destination = (unsigned char)addressSize;
    return func_ov031_022073a4(socket, (int)buffer, size, flags, (const SocketAddress022073a4*)destination);
}
