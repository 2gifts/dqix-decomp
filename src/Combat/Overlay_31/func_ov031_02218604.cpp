#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" int func_ov031_0221aae4(int a, int b, char* out, int size);
extern "C" int func_ov031_0221883c(void* self, void* buf, int extra);
int VariadicForward020c7170(int a, int b, int c, ...);

extern const char data_ov031_02249edc[];
extern const char data_ov031_02249ee0[];

struct TextBuffer_02218604 {
    char* start;
    char* cur;
    char* end;
};

struct Printer_02218604 {
    char pad[0x19f4];
    int depth;
    TextBuffer_02218604 buf;
};

// USA: func_ov031_02218604  (semantic: AppendNamedValue_02218604)
extern "C" ARM int func_ov031_02218604(Printer_02218604* self, const char* name, int a, int b) {
    int len;
    TextBuffer_02218604* buf = &self->buf;
    const char* fmt = self->depth == 0 ? data_ov031_02249edc : data_ov031_02249ee0;
    int lenFmt;
    int need;
    int avail;
    int written;
    char* cur;

    self->depth = self->depth + 1;
    len = func_ov031_0221aae4(a, b, 0, 0);
    lenFmt = (int)strlen(fmt);
    need = len + (lenFmt - 2 + (int)strlen(name));
    cur = buf->cur;
    avail = buf->end - cur;
    if (need > avail) {
        if (func_ov031_0221883c(self, buf, need - avail + 1) == 0) {
            return 1;
        }
        cur = buf->cur;
        avail = buf->end - cur;
    }
    written = VariadicForward020c7170((int)cur, avail, (int)fmt, name);
    buf->cur = buf->cur + written;
    if (func_ov031_0221aae4(a, b, buf->cur, buf->end - buf->cur - 1) >= 0) {
        buf->cur = buf->cur + len;
        *buf->cur = 0;
        return 0;
    }
    return 1;
}
