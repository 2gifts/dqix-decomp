#include <globaldefs.h>

struct SocketAddress022073a4 {
    unsigned short family;
    unsigned short port;
    unsigned int address;
};
extern "C" int func_ov031_02206150(int, int, int, unsigned int, unsigned int, int);

// USA: func_ov031_022073a4
extern "C" ARM int func_ov031_022073a4(int socket, int buffer, int size, int flags, const SocketAddress022073a4* destination) {
    unsigned short port;
    unsigned int address;
    if (destination) {
        unsigned short encodedPort = destination->port;
        unsigned int encodedAddress = destination->address;
        port = ((encodedPort >> 8) & 0xff) | ((encodedPort << 8) & 0xff00);
        address = ((encodedAddress >> 24) & 0xff) | ((encodedAddress >> 8) & 0xff00) |
                  ((encodedAddress << 8) & 0xff0000) | ((encodedAddress << 24) & 0xff000000);
    } else {
        port = 0;
        address = 0;
    }
    return func_ov031_02206150(socket, buffer, size, port, address, flags);
}
