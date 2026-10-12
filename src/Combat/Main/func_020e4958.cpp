#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct0200fb08;
extern "C" int _Z24NormalizeField5_0200fb08P14Struct0200fb08(Struct0200fb08*);
int StringLength(const char*);
extern "C" int func_02001aec(const char*, const char*, unsigned int);
extern "C" int sprintf(char*, const char*, ...);
extern "C" void* memset(void*, int, unsigned int);
extern "C" void* memcpy(void*, const void*, unsigned int);
extern "C" void __clear(void*, unsigned int);
extern "C" void func_020e4864(char*, char*, int, int, int, int);
extern void (*data_020ee9f0[])(char*, int);
struct TextToken020e4958 {
    signed char choices[4];
    const char* name;
    signed char length;
    char pad9[3];
};
extern TextToken020e4958 data_020eea50[];
struct TextChoice020e4958 { char text[6]; };
extern TextChoice020e4958 data_020eea08[];
extern char data_020f2dcf[];

// USA: func_020e4958
extern "C" ARM void func_020e4958(char** destination, int value, int inputMode, int kind, int group, int choice) {
    int mode;
    char source[0x100] = {0};
    mode = 1 - inputMode;
    if (inputMode == -1) mode = 0;
    int selection = group;
    if (selection == -1) selection = 0;
    selection = selection * 3;
    data_020ee9f0[selection + (mode + kind)](source, value);
    char expanded[0x100];
    mode = 1 - mode;
    __clear(expanded, 0x100);
    if (choice == -1 && _Z24NormalizeField5_0200fb08P14Struct0200fb08((Struct0200fb08*)GameState::GetInstance()) == 3) choice = 0;
    char* input;
    char* output = expanded;
    input = source;
    for (;;) {
        if (*input == 0) break;
        if (*input == '[') {
            int replaced = 0;
            TextToken020e4958* token = data_020eea50;
            int length;
            while ((length = token->length) != 0) {
                if (func_02001aec(input + 1, token->name, length) == 0) {
                    if (choice != -1) {
                        output += sprintf(output, data_020eea08[token->choices[choice]].text);
                        input += token->length + 1;
                        if (*input != ' ') output += sprintf(output, data_020f2dcf);
                    } else {
                        if (*(input += length + 1) == ' ') input++;
                    }
                    replaced = 1;
                    break;
                }
                token++;
            }
            if (replaced) continue;
        }
        *output = *input;
        input++;
        output++;
    }
    *output = *input;
    memset(source, 0, 0x100);
    func_020e4864(expanded, source, mode, kind, selection, choice);
    int length = StringLength(source);
    memcpy(*destination, source, length);
    *destination += length;
}
