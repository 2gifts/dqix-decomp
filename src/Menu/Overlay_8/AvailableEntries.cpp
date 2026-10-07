struct Overlay8EntryView {
    unsigned char unknown000[0x744];
    unsigned char entries[8];
    unsigned char count;
    unsigned char unknown74d[0xb18 - 0x74d];
    unsigned int flags;
};

extern "C" {
    char* func_0205ec34();
    bool _Z18TestBitInByteArrayiPhi(void*, void*, int);

    void func_ov008_02186cec(Overlay8EntryView* menu) {
        menu->count = 0;
        for (int i = 0; i < 8; ++i)
            menu->entries[i] = 0xff;

        menu->entries[menu->count++] = 0;
        menu->entries[menu->count++] = 1;
        menu->entries[menu->count++] = 2;

        char* state = func_0205ec34();
        if (_Z18TestBitInByteArrayiPhi(state, state + 0x8c, 0x1198))
            menu->entries[menu->count++] = 3;
        if (menu->flags & 0x2000)
            menu->entries[menu->count++] = 4;
        if (_Z18TestBitInByteArrayiPhi(state, state + 0x8c, 0x119d))
            menu->entries[menu->count++] = 5;
        if (_Z18TestBitInByteArrayiPhi(state, state + 0x8c, 0x119b))
            menu->entries[menu->count++] = 6;
        if (menu->flags & 4)
            menu->entries[menu->count++] = 7;
    }
}
