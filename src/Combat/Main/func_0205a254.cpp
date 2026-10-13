#include <globaldefs.h>
struct Frame0205a254 { unsigned short duration; unsigned short field2; };
struct Elem0205a3d0 {
    int mode; int field4; unsigned short key, count;
    Frame0205a254* frames;
    unsigned short index, elapsed;
    unsigned char field14, flags; unsigned short field16;
};
struct Container0205a3d0;
Elem0205a3d0* FindEntryByHalfword0205a3d0(Container0205a3d0*, int);
void SetEntryFlag1ByKey0205a3ac(Container0205a3d0*, int);
// USA: func_0205a254
extern "C" ARM void func_0205a254(Container0205a3d0* container, int key, int delta) {
    Frame0205a254* frames;
    unsigned short elapsed;
    int frameOffset;
    unsigned short increment = delta;
    Elem0205a3d0* entry = FindEntryByHalfword0205a3d0(container, key);
    if (!entry) return;
    if (!(entry->flags & 2) || !entry->mode) return;
    entry->elapsed += increment;
    frames = entry->frames;
    frameOffset = entry->index;
    const unsigned short& duration = frames[frameOffset].duration;
    elapsed = entry->elapsed;
    if (duration <= elapsed) {
        entry->elapsed = elapsed - duration;
        switch (entry->mode) {
        case 0: break;
        case 1:
            entry->index++;
            elapsed = entry->index;
            if (entry->count > elapsed) return;
            {
                entry->index = elapsed - 1;
                entry->elapsed = frames[frameOffset].duration;
                SetEntryFlag1ByKey0205a3ac(container, entry->key);
            }
            break;
        case 2:
            entry->index++;
            if (entry->count <= entry->index) entry->index = 0;
            break;
        case 3: break;
        case 4: break;
        }
    }
}
