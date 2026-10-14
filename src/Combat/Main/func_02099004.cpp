#include <globaldefs.h>
#include "Resource/Script.h"

struct Profile02099004 {
    unsigned int year : 12;
    unsigned int month : 4;
    unsigned int day : 5;
    unsigned int selector : 4;
    unsigned int field_25 : 6;
    unsigned int ageEnabled : 1;
    signed int ageState : 9;
    unsigned int field_41 : 23;
    char text[1];
};
struct ProfileGlobals02099004 { unsigned char flags; unsigned char field_1[3]; char* output; Profile02099004* profile; };
extern ProfileGlobals02099004 data_021098e8;
extern unsigned char data_020e8dac[2];
struct PagePrefix02099004 { char text[7]; };
extern const PagePrefix02099004 data_020e8dae;
int GetGlobalField0x1c020421a0();
int StringLength_020d2ff0(const char*);
char* CallFunc020e0434With02153694_020e51cc(int);
void AppendFormattedData02098f70(int*, void*, int, int);
extern "C" void func_02046608(int, int, const char*, char*, int, int, int);
extern "C" void __clear(void*, int);
extern "C" int func_02042764(const char*, char*, int);

// USA: func_02099004
extern "C" ARM int func_02099004(Script::Parameter* params, int count) {
    (params++)->ToInt();
    if (data_021098e8.profile->selector != (params++)->ToInt()) return 0;
    int base = GetGlobalField0x1c020421a0();
    (params++)->ToInt();
    const char* text = (params++)->ToString();
    if (!data_021098e8.profile->ageEnabled) {
        text = (params++)->ToString();
    } else params++;
    if (data_021098e8.flags & 0x10) text += 17;
    func_02046608(base, 12, text, data_021098e8.output, 0xe3, 0, 1);
    char* output = data_021098e8.output;
    char* cursor = output + strlen(output);
    PagePrefix02099004 prefix = data_020e8dae;
    int prefixLength = StringLength_020d2ff0(prefix.text);
    char message[0x20];
    char formatted[0x400];
    char body[0x20];
    const char* messageText = CallFunc020e0434With02153694_020e51cc(0x3ea);
    func_02046608(base, 12, messageText, message, 0xe3, 0, 1);
    char separator[2];
    separator[0] = data_020e8dac[0];
    separator[1] = data_020e8dac[1];
    const char* profileText;
    if ((data_021098e8.flags & 0x20) && (profileText = data_021098e8.profile->text)[0]) {
        memcpy(cursor, prefix.text, prefixLength);
        cursor += prefixLength;
        int messageLength = strlen(message);
        memcpy(cursor, message, messageLength);
        cursor += messageLength;
        int textLength = StringLength_020d2ff0(profileText);
        int position = 0;
        do {
            int length = textLength - position;
            if (length > 19) length = 19;
            __clear(body, sizeof(body));
            memcpy(body, profileText + position, length);
            __clear(formatted, sizeof(formatted));
            func_02042764(body, formatted, 1);
            cursor += sprintf(cursor, formatted);
            position += 19;
            if (position >= textLength) break;
            cursor += sprintf(cursor, separator);
        } while (1);
    }
    const char* first = params[0].ToString();
    const char* second = params[1].ToString();
    const char* third = params[2].ToString();
    const char* fourth = params[3].ToString();
    const char* selected = 0;
    if (data_021098e8.flags & 2) selected = first;
    else if (data_021098e8.flags & 4) selected = second;
    else if (data_021098e8.flags & 8) selected = third;
    if (selected) AppendFormattedData02098f70((int*)&cursor, (void*)selected, (int)prefix.text, prefixLength);
    selected = 0;
    if (data_021098e8.flags & 1) selected = fourth;
    if (selected) AppendFormattedData02098f70((int*)&cursor, (void*)selected, (int)prefix.text, prefixLength);
    return 1;
}
