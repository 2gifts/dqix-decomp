#ifndef COMBAT_NAME_ENTRY_QUEUE_H
#define COMBAT_NAME_ENTRY_QUEUE_H

struct Mid12_02195214 {
    unsigned char v[12];
};

struct Entry15_02195214 {
    unsigned char a;
    unsigned char b;
    Mid12_02195214 mid;
    unsigned char e;
};

extern "C" void func_ov017_02195214(Entry15_02195214 *dst, Entry15_02195214 *src);

struct ActiveEntry02195250 {
    unsigned char state;
    unsigned char mode;
    Entry15_02195214 entry;
};

struct EntryQueueReceiver02195250 {
    unsigned char unknown0[0x42f0];
    unsigned char count;
    Entry15_02195214 entries[3];
    unsigned char unknown431e[0x441c - 0x431e];
    ActiveEntry02195250 *active;
};

#endif
