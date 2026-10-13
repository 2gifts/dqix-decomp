#include <globaldefs.h>

extern int data_ov031_0224f4e0;
extern "C" int func_ov031_0221f158();
extern "C" int func_020c7ea0(void* queue, int* message, int blocking);

// USA: func_ov031_0221e92c
extern "C" THUMB int func_ov031_0221e92c() {
    int result = -1;
    if (func_ov031_0221f158() != 0) {
        int message;
        int running = 1;
        do {
        func_020c7ea0(&data_ov031_0224f4e0, &message, 1);
        switch (message) {
        case 0xe:
            running = 0;
            result = 0;
            break;
        default:
            running = 0;
            break;
        }
    } while (running != 0);
    }
    return result;
}
