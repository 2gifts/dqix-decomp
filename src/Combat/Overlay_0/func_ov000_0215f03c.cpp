#include <globaldefs.h>

struct Name0215f03c {
    char text[0x16];
};

struct Element0215f03c {
    char pad0[0x6c];
    Name0215f03c name;
    unsigned char field82;
    unsigned char field83;
};

struct Container02070e60 {
    char pad0[4];
};

extern "C" Element0215f03c* _Z33SearchWithLow15Comparator02070fd0P17Container02070e60i(struct Container02070e60* container, int key);

struct Unit0215f03c {
    char pad0[0x3e];
    Name0215f03c name;
    unsigned char field54;
    unsigned char field55;
    char pad56[0xa4 - 0x56];
};

struct Table0215f03c {
    char pad0[0x400];
    Container02070e60 container;
};

struct BattleData0215f03c {
    char pad0[0x158];
    Unit0215f03c units[1];
    char pad1fc[0x284 - 0x1fc];
    Table0215f03c table;
};

struct Group0215f03c {
    unsigned short key;
    unsigned char members[8];
    unsigned char memberCount : 4;
    unsigned char matched : 4;
    char padb[0x18 - 0xb];
};

struct Battle0215f03c {
    char pad0[0x81b1];
    unsigned char counter : 4;
    unsigned char groupCount : 2;
    unsigned char unused : 2;
    char pad81b2[2];
    Group0215f03c groups[4];
    char pad8214[0x8e18 - 0x8214];
    BattleData0215f03c* data;
};

// USA: func_ov000_0215f03c
extern "C" ARM void func_ov000_0215f03c(Battle0215f03c* self) {
    BattleData0215f03c* data = self->data;
    Table0215f03c* table = &data->table;
    Unit0215f03c* units = data->units;
    Group0215f03c* groups = self->groups;
    int i;
    unsigned char* members;
    int j;
    Unit0215f03c* unit;
    Group0215f03c* group;
    for (i = 0; i < self->groupCount; i++) {
        group = &groups[i];
        int key = group->key;
        members = group->members;
        for (j = 0; j < group->memberCount; j++) {
            unit = &units[members[j]];
            Element0215f03c* e = _Z33SearchWithLow15Comparator02070fd0P17Container02070e60i(&table->container, key);
            if (e != NULL) {
                unit->name = e->name;
                unit->field54 = e->field82;
                unit->field55 = e->field83;
            }
        }
    }
}
