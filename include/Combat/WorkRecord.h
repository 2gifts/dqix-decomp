#ifndef COMBAT_WORK_RECORD_H
#define COMBAT_WORK_RECORD_H

struct Rec0206bf2c {
    unsigned char field0;
    unsigned char pad1;
    unsigned short field2;
    unsigned char field4;
    unsigned char field5;
    unsigned char field6;
    unsigned char field7;
    unsigned char field8;
    unsigned char pad9;
    unsigned char flagsA_b0 : 2;
    unsigned char flagsA_b1 : 1;
    unsigned char flagsA_b2 : 3;
    unsigned char flagsA_b3 : 1;
    unsigned char flagsA_b4 : 1;
    unsigned char fieldB;
    unsigned int fieldC;
    union {
        unsigned char pad10[0xc];
        int vec[3];
    };
    unsigned short field1c;
    unsigned char field1e;
    unsigned char field1f;
    unsigned short field20;
    unsigned char pad22[2];
    unsigned char pad24[0x10];
    unsigned int field34;
    unsigned int field38;
    unsigned int field3c;
    unsigned int field40;
    unsigned short field44;
    short field46;
    unsigned char pad48[0xc];
    unsigned int field54;
    unsigned int field58;
    unsigned int field5c;
    unsigned int field60;
    Rec0206bf2c *field64;
    Rec0206bf2c *field68;
    Rec0206bf2c *field6c;
    Rec0206bf2c *field70;
};

void ClearWorkRecord0206bf2c(Rec0206bf2c *obj);
extern "C" void func_0206db48(void *receiver, Rec0206bf2c *record);

#endif
