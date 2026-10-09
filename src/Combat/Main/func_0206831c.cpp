#include <globaldefs.h>
char* FindUnescapedAngleBracket(char*);
extern "C" int _Z21IsPrefixMatch020d857cPaS_(signed char*, signed char*);
int StringLength(const char*);
extern "C" int func_02005a94(const char*);
struct Tag0206831c {
    signed char* name;
    void (*expand)(signed char*, signed char**, void*, int);
};
extern Tag0206831c data_020e7e5c[];
// USA: func_0206831c
extern "C" ARM void func_0206831c(void* context, signed char* input, signed char* destination) {
    signed char* output;
    if (!input || !destination) return;
    output = destination;
    while (1) {
        if (!*input) break;
        if (*input == '<') {
            signed char* end = (signed char*)FindUnescapedAngleBracket((char*)input);
            if (end) {
                int found = 0;
                Tag0206831c* tag = data_020e7e5c;
                signed char* name = input + 1;
                while (tag->name) {
                    if (_Z21IsPrefixMatch020d857cPaS_(name, tag->name)) {
                        if (tag->expand) {
                            int index = 0;
                            int length = StringLength((char*)tag->name);
                            signed char digit = name[length];
                            if (digit >= '1' && digit <= '9') index = func_02005a94((char*)name + length) - 1;
                            tag->expand(name, &output, context, index);
                        }
                        input = end + 1;
                        found = 1;
                        break;
                    }
                    tag++;
                }
                if (found) continue;
            }
        }
        *output = *input++;
        output++;
    }
    *output = *input;
}
