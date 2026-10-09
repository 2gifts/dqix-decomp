#include <globaldefs.h>
#include "std_library_functions.h"
struct Entry0209ebe4 { char data[0x40]; };
struct Source0209ebe4 { char pad0[0x5c60]; Entry0209ebe4 entries[16]; char pad6060[0x8e07-0x6060]; unsigned char count; };
struct Manager0209ebe4 { int field_0x0; Source0209ebe4* source; char pad8[0x90]; int count; Entry0209ebe4 entries[16]; int temporaryCount; Entry0209ebe4 temporary[16]; };
extern "C" int func_0209dcdc(Manager0209ebe4*, Entry0209ebe4*, int, int);
// USA: func_0209ebe4
extern "C" ARM void func_0209ebe4(Manager0209ebe4* mgr, int filterExisting, int arg) {
    int limit;
    int i;
    Entry0209ebe4* source;
    Entry0209ebe4* entry;
    i = 0;
    if (!filterExisting) {
        mgr->count = 0;
        limit = mgr->source->count;
        for (i = 0; i < limit; i++) {
            entry = &mgr->source->entries[i];
            if (entry && func_0209dcdc(mgr, entry, 1, arg)) {
                memcpy(&mgr->entries[mgr->count++], entry, 0x40);
            }
        }
    } else {
        mgr->temporaryCount = 0;
        memset(mgr->temporary, 0, 0x400);
        source = mgr->entries;
        for (i = 0; i < mgr->count; i++) {
            entry = &source[i];
            if (func_0209dcdc(mgr, entry, 1, arg)) {
                int count = mgr->temporaryCount;
                mgr->temporaryCount = mgr->temporaryCount + 1;
                memcpy(&mgr->temporary[count], entry, 0x40);
            }
        }
        mgr->count = mgr->temporaryCount;
        memcpy(mgr->entries, mgr->temporary, 0x400);
    }
}
