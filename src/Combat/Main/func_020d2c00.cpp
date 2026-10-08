#include <globaldefs.h>

struct SoundWaveArchive020d2c00;

struct SoundWaveArchiveLink020d2c00 {
    SoundWaveArchive020d2c00* waveArc;
    SoundWaveArchiveLink020d2c00* next;
};

struct SoundWaveArchive020d2c00 {
    unsigned char header[0x18];
    SoundWaveArchiveLink020d2c00* topLink;
    unsigned char rest[0x20];
};

struct SoundBank020d2c00 {
    unsigned char header[0x18];
    SoundWaveArchiveLink020d2c00 waveArcLink[4];
};

void CleanCacheRange(const void* addr, unsigned int size);

extern "C" {
    void func_020d21f8();
    void func_020d220c();
}

// USA: func_020d2c00
extern "C" ARM void func_020d2c00(SoundBank020d2c00* bank) {
    SoundWaveArchiveLink020d2c00* bankLink;
    int i;
    func_020d21f8();
    bankLink = &bank->waveArcLink[0];
    i = 0;
    do {
        SoundWaveArchive020d2c00* const waveArc = bank->waveArcLink[i].waveArc;
        if (waveArc != NULL) {
            if (bankLink == waveArc->topLink) {
                waveArc->topLink = bank->waveArcLink[i].next;
                CleanCacheRange(waveArc, sizeof(SoundWaveArchive020d2c00));
            } else {
                SoundWaveArchiveLink020d2c00* link = waveArc->topLink;
                if (link != NULL) {
                    do {
                        if (bankLink == link->next)
                            break;
                        link = link->next;
                    } while (link != NULL);
                }
                link->next = bank->waveArcLink[i].next;
                CleanCacheRange(link, sizeof(SoundWaveArchiveLink020d2c00));
            }
        }
        i++;
        bankLink++;
    } while (i < 4);
    func_020d220c();
}
