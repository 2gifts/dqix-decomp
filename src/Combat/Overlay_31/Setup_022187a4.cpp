#include <globaldefs.h>

struct Buffer_022187a4 {
    char* begin;
    char* current;
    char* end;
    int size;
};

typedef char* (*Allocate_022187a4)(const char*, int);
extern char data_ov031_02249eec[];

// USA: func_ov031_022187a4
ARM int Setup_022187a4(char* obj, void* out, int length) {
    Allocate_022187a4 allocate = *(Allocate_022187a4*)(obj + 0x1010);
    Buffer_022187a4* buffer = (Buffer_022187a4*)out;
    if (length == 0) return 0;
    buffer->begin = allocate(data_ov031_02249eec, length);
    if (buffer->begin == NULL) return 0;
    buffer->current = buffer->begin;
    buffer->size = length;
    buffer->end = buffer->begin + buffer->size;
    return 1;
}
