#include <globaldefs.h>
#include "Resource/Script.h"

struct List020999f0;
struct Elem020999f0;

struct Elem020995f8 {
    unsigned short id;
    unsigned short wide : 15;
    unsigned short : 1;
    unsigned char flag4 : 1;
    unsigned char : 7;
    unsigned char text[7];
    unsigned char kindA : 4;
    unsigned char flagC4 : 1;
    unsigned char kindC5 : 2;
    unsigned char flagC7 : 1;
    unsigned char valD : 7;
    unsigned char flagD7 : 1;
    unsigned char kindE : 2;
    unsigned char mid : 4;
    unsigned char flagE6 : 1;
    unsigned char flagE7 : 1;
};

extern "C" void _Z21AppendElement020999f0P12List020999f0P12Elem020999f0(struct List020999f0* list, struct Elem020999f0* src);
extern struct List020999f0* data_02109924;

// USA: func_020995f8
extern "C" ARM int func_020995f8(Script::Parameter* params, int numParams) {
    struct Elem020995f8 e;
    const char* text;

    e.id = 0;
    e.wide = 0;
    e.text[0] = 0;
    e.kindA = 0;
    e.flagC4 = 0;
    e.kindC5 = 0;
    e.flagC7 = 0;
    e.flagD7 = 0;
    e.kindE = 0;
    e.mid = 8;
    e.flagE7 = 0;
    e.flag4 = 0;

    e.id = (params++)->ToInt();
    e.wide = (params++)->ToInt();
    (params++)->ToString();
    e.kindA = (params++)->ToInt();
    text = (params++)->ToString();
    (params++)->ToString();
    e.valD = (params++)->ToInt();
    (params++)->ToInt();
    (params++)->ToInt();
    e.flagC4 = (params++)->ToInt();
    e.kindC5 = (params++)->ToInt();
    (params++)->ToString();
    e.flagC7 = (params++)->ToInt();
    params += 3;
    e.flagD7 = (params++)->ToInt();
    e.kindE = (params++)->ToInt();
    e.mid = (params++)->ToInt();
    e.flagE6 = (params++)->ToInt();
    e.flagE7 = (params++)->ToInt();
    e.flag4 = (params++)->ToInt();

    if (text == 0) {
        return 0;
    }
    memcpy(e.text, text, 7);
    e.text[6] = 0;
    _Z21AppendElement020999f0P12List020999f0P12Elem020999f0(data_02109924, (struct Elem020999f0*)&e);
    return 1;
}
