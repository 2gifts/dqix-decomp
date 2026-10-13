#include <globaldefs.h>
#include "Resource/Script.h"

struct KeyPacket02243018 {
    unsigned char type;
    unsigned char index;
    unsigned char keys[4][20];
};
#if defined(jpn)
#define data_ov031_02291eae data_ov031_02292aae
#endif
extern KeyPacket02243018 data_ov031_02291eae;
extern unsigned char data_ov031_02291e04[];

// USA: func_ov031_02243018
extern "C" ARM int func_ov031_02243018(Script::Parameter* parameters) {
    parameters[0].ToString();
    KeyPacket02243018 packet;
    memset(&packet, 0, 0x52);
    packet.type = parameters[1].ToInt();
    packet.index = parameters[2].ToInt() - 1;
    unsigned char* output = packet.keys[packet.index];
    const char* input = parameters[3].ToString();
    int length = strlen(input);
    for (int position = 0; position < length; ++position) {
        char digit = *input;
        unsigned char value;
        if (digit >= '0' && digit <= '9') value = digit - '0';
        else if (digit >= 'A' && digit <= 'E') value = digit - '7';
        else if (digit >= 'a' && digit <= 'e') value = digit - 'W';
        else value = 0;
        ++input;
        if (position % 2 == 0) *output |= value << 4;
        else { *output |= value; ++output; }
    }
    memcpy(&data_ov031_02291eae, &packet, 0x52);
#if defined(jpn)
    *(const char**)(data_ov031_02291e04 + 0x10) = parameters[4].ToString();
#else
    *(const char**)(data_ov031_02291e04 + 0x34) = parameters[4].ToString();
#endif
    *(unsigned short*)(data_ov031_02291e04 + 8) = parameters[5].ToInt();
    return 1;
}
