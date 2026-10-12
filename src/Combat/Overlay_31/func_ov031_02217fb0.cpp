#include <globaldefs.h>
#include <std_library_functions.h>
#include "System/Mutex.h"

struct ResponseBuffer02217fb0 {
    char* start;
    char* end;
    unsigned char unknown[8];
    Mutex mutex;
};
struct NetworkResponse02217fb0 {
    unsigned char prefix[0xa08];
    ResponseBuffer02217fb0 buffer;
    int contentLength;
    int bodyOffset;
};
struct ResponseState02217fb0 {
    unsigned char prefix[0x1000];
    NetworkResponse02217fb0 response;
};
extern char data_ov031_02249df8[];
extern char data_ov031_02249e14[];
extern char data_ov031_02249e28[];
extern "C" int func_02005a94(signed char*);

// USA: func_ov031_02217fb0
extern "C" ARM int func_ov031_02217fb0(ResponseState02217fb0* state) {
    char* text = state->response.buffer.start;
    ResponseBuffer02217fb0* buffer = &state->response.buffer;
    if (strstr(text, data_ov031_02249df8) == 0) return 0;
    char* body = strstr(text, data_ov031_02249df8) + 4;
    LockMutex(&state->response.buffer.mutex);
    state->response.bodyOffset = buffer->end - body;
    UnlockMutex(&state->response.buffer.mutex);
    char* value = strstr(buffer->start, data_ov031_02249e14);
    if (value == 0) return 1;
    int length = strlen(data_ov031_02249e14);
    char* end = strstr(value + length, data_ov031_02249e28);
    signed char saved = *end;
    *end = 0;
    LockMutex(&state->response.buffer.mutex);
    state->response.contentLength = func_02005a94((signed char*)(value + length));
    UnlockMutex(&state->response.buffer.mutex);
    *end = saved;
    return 1;
}
