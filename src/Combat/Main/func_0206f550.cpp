#include <globaldefs.h>

int StringLength(const char* s);
extern "C" int func_02001aec(void* a, void* b, int n);
extern "C" int func_02005a94(void* p);

extern char* data_020f0afc[];

struct Tags0206f550 {
    unsigned char ids[4];
    int count;
    short vals[4];
};

// USA: func_0206f550
extern "C" ARM int func_0206f550(struct Tags0206f550* s, char* in, char* out) {
    unsigned char* p = (unsigned char*)in;
    int found;
    char* tag;
    int len;
    unsigned char i;
    unsigned char c;
    char** tab;

    if (in == 0) return 0;
    if (out == 0) return 0;
    s->count = 0;
    while ((c = *p) != 0) {
        if (c == '<') {
            found = 0;
            if (s->count < 4) {
                i = 1;
                tab = data_020f0afc;
                while (i < 13) {
                    tag = tab[i];
                    len = StringLength(tag);
                    if (func_02001aec(p, tag, len) == 0) {
                        if (i == 4 || (unsigned char)(i + 0xff) <= 1) {
                            p += len;
                            s->vals[s->count] = (short)func_02005a94(p);
                        }
                        found = 1;
                        s->ids[s->count] = i;
                        s->count++;
                        break;
                    }
                    i++;
                }
            }
            if (found) {
                while ((c = *p) != '>') {
                    if (c == 0) return s->count;
                    p++;
                }
                p++;
            } else {
                while ((c = *p) != '>') {
                    *out = c;
                    c = *p;
                    if (c == 0) return s->count;
                    p++;
                    out++;
                }
                *out++ = c;
                p++;
            }
        } else {
            if ((c >= 0x81 && c <= 0x9f) || (c >= 0xe0 && c <= 0xea)) {
                *out++ = c;
                p++;
            }
            *out++ = *p++;
        }
    }
    return s->count;
}
