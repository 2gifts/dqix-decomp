#include <globaldefs.h>

struct TextWindow020449a4 {
    char reserved_0[0x1860];
    int characterWidth;
    int characterHeight;
    char reserved_1868[0x19b1 - 0x1868];
    unsigned char flag_19b1;
    char reserved_19b2[6];
    unsigned char flag_19b8;
    char reserved_19b9[2];
    unsigned char flag_19bb;
};
int StringStartsWithCI020d85dc(const char* string, const char* prefix);
extern "C" int func_02005a94(const char* string);
extern "C" void func_02042b98(TextWindow020449a4*, int, int, int, int);
extern char data_020f00a9[];
extern char data_020f00b0[];
extern char data_020f00b6[];
extern char data_020f00bc[];
extern char data_020f00c3[];

// USA: func_020449a4
extern "C" ARM const char* func_020449a4(TextWindow020449a4* window, const char* text) {
    int active = 1;
    while (active) {
        if (StringStartsWithCI020d85dc(text, data_020f00a9)) {
            int width;
            int finished;
            int index;
            int end;
            int x;
            int y;
            index = 6;
            end = index;
            finished = 0;
            while (text[end] != '>') {
                if (!text[end]) return text + end;
                end++;
            }
            x = func_02005a94(text + 6);
            while (text[index] != ',') {
                if (text[index] == '>') {
                    text += index + 1;
                    finished = 1;
                    break;
                }
                index++;
            }
            if (finished) return text;
            index++;
            y = func_02005a94(text + index);
            while (text[index] != ',') {
                if (text[index] == '>') {
                    text += index + 1;
                    finished = 1;
                    break;
                }
                index++;
            }
            if (finished) return text;
            index++;
            width = func_02005a94(text + index);
            while (text[index] != ',') {
                if (text[index] == '>') {
                    text += index + 1;
                    finished = 1;
                    break;
                }
                index++;
            }
            if (finished) return text;
            int height = func_02005a94(text + (index + 1));
            if (x < 0) x = 0;
            if (x > 256) x = 256;
            if (y < 0) y = 0;
            if (y > 192) y = 192;
            if (width < 0) width = 256 - x;
            if (width > 256) width = 256 - x;
            if (height < 0) height = 192 - y;
            if (height > 192) height = 192 - y;
            func_02042b98(window, x, y, width, height);
            text += end + 1;
        } else if (StringStartsWithCI020d85dc(text, data_020f00b0)) {
            window->flag_19b1 = 0;
            text += 5;
        } else if (StringStartsWithCI020d85dc(text, data_020f00b6)) {
            window->flag_19b8 = 1;
            text += 5;
        } else if (StringStartsWithCI020d85dc(text, data_020f00bc)) {
            int index = 6;
            int end = index;
            while (text[end] != '>') {
                if (!text[end]) return text + end;
                end++;
            }
            int width = func_02005a94(text + 6);
            if (width <= 0) width = 12;
            while (text[index] != ',') {
                if (text[index] == '>') {
                    text += index + 1;
                    break;
                }
                index++;
            }
            int height = func_02005a94(text + (index + 1));
            if (height <= 0) height = 16;
            window->characterWidth = width;
            window->characterHeight = height;
            text += end + 1;
        } else if (StringStartsWithCI020d85dc(text, data_020f00c3)) {
            window->flag_19bb = 0;
            text += 6;
        } else {
            active = 0;
        }
    }
    return text;
}
