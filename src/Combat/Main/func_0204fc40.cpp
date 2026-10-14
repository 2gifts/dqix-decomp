#include <globaldefs.h>

int StringLength_020d2ff0(const char* s);
extern "C" int func_02001aec(unsigned char* a, unsigned char* b, int n);
extern "C" int func_02005a94(void* p);

// USA: func_0204fc40
extern "C" ARM int func_0204fc40(void* unused0, char** cursor, char* tag, short* out, int max) {
    int len = StringLength_020d2ff0(tag);
    char* p = *cursor;
    if (func_02001aec((unsigned char*)p, (unsigned char*)tag, len) == 0) {
        p += len;
        short i;
        for (i = 0; i < max; i++) {
            int val = func_02005a94(p);
            out[i] = (short)val;
            if (i == max - 1) break;
            while (*p != ',') p++;
            p++;
        }
        while (*p != '>' && *p != 0) p++;
        *cursor = p + 1;
        return 1;
    }
    return 0;
}
