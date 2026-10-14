#include <globaldefs.h>

extern "C" void func_020ce39c(unsigned int *arr, int count);
extern "C" int func_020ceba8(int a, int b, int c, int d);

// USA: func_020ce45c
ARM int SendEncodedMessagePair_020ce45c(int a, int b) {
    unsigned int arr[2];
    arr[0] = 0x3006000;
    func_020ce39c(arr, 1);
    while (func_020ceba8(0, 2, 0, 1) != 1) {}
    arr[0] = (a & 0xff) | 0x6200 | 0x2000000;
    arr[1] = 0x1010000 | (unsigned short)b;
    func_020ce39c(arr, 2);
    return 0;
}
