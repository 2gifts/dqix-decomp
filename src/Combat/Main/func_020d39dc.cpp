#include <globaldefs.h>
#include "std_library_functions.h"
#include "Resource/Script.h"

struct Entry020d3cf0Flags {
    unsigned char f0 : 3;
    unsigned char f1 : 1;
    unsigned char f2 : 3;
    unsigned char f3 : 1;
};

struct Entry020d3cf0Triple {
    unsigned int f0 : 10;
    unsigned int f1 : 10;
    unsigned int f2 : 10;
    unsigned int reserved : 2;
};

struct Entry020d3cf0 {
    char name[16];
    struct Entry020d3cf0Flags flags;
    unsigned char b11;
    unsigned char b12;
    unsigned char b13;
    struct Entry020d3cf0Triple w14;
    struct Entry020d3cf0Triple w18;
    struct Entry020d3cf0Triple w1c;
    unsigned short h20;
    unsigned short h22;
};

struct Container020d3cf0;
extern "C" void _Z24AppendNamedEntry020d3cf0P17Container020d3cf0P13Entry020d3cf0(struct Container020d3cf0* container, struct Entry020d3cf0* src);
extern struct Container020d3cf0* data_021142c4;

// USA: func_020d39dc  (semantic: BuildAndAppendVariantEntry_020d39dc)
extern "C" ARM int func_020d39dc(Script::Parameter* params, int count) {
    struct Entry020d3cf0 entry;

    entry.flags.f0 = (params++)->ToInt();
    entry.b11 = (params++)->ToInt();
    strcpy(entry.name, (params++)->ToString());
    entry.flags.f1 = (params++)->ToInt();
    entry.flags.f2 = (params++)->ToInt();
    entry.b12 = (params++)->ToInt();
    entry.flags.f3 = (params++)->ToInt();

    entry.w14.f0 = (params++)->ToInt();
    entry.w14.f2 = (params++)->ToInt();
    entry.w14.f1 = (params++)->ToInt();

    entry.w18.f0 = (params++)->ToInt();
    entry.w18.f1 = (params++)->ToInt();
    entry.w18.f2 = (params++)->ToInt();

    entry.w1c.f0 = (params++)->ToInt();
    entry.w1c.f1 = (params++)->ToInt();
    entry.w1c.f2 = (params++)->ToInt();

    entry.b13 = (params++)->ToInt();
    entry.h20 = (params++)->ToInt();
    entry.h22 = (params++)->ToInt();

    _Z24AppendNamedEntry020d3cf0P17Container020d3cf0P13Entry020d3cf0(data_021142c4, &entry);
    return 1;
}
