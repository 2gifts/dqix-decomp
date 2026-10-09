#include <globaldefs.h>
#include <std_library_functions.h>
#include <System/Cache.h>
#include <System/LoadToVRAM.h>

struct Table020429e4;
extern "C" char* func_02042a50(Table020429e4* table, char* key);
extern unsigned char data_020fe9ac[32];

// USA: func_0202ab34
extern "C" ARM void func_0202ab34(void* data, int count, int tileIndex) {
    char key[3] = {};
    memcpy(key, data, 2);
    for (int i = 0; i < count; i++) {
        unsigned char* glyph = (unsigned char*)func_02042a50((Table020429e4*)8, key);
        if (glyph != NULL) {
            unsigned char* destination = data_020fe9ac;
            memset(destination, 0, 32);
            int bit = 0;
            short row = 0;
            while (row < 8) {
                for (short column = 0; column < 8; column++) {
                    if (*glyph & (1 << bit)) {
                        if (column & 1) {
                            destination[column >> 1] = (destination[column >> 1] & 15) | 16;
                        } else {
                            destination[column >> 1] &= 240;
                            destination[column >> 1] |= 1;
                        }
                    }
                    bit++;
                    if (bit >= 8) {
                        bit = 0;
                        glyph++;
                    }
                }
                row++;
                destination += 4;
            }
            CleanInvalidateCacheRange(data_020fe9ac, 32);
            LoadToMainBG1CharacterData(data_020fe9ac, tileIndex << 5, 32);
            CleanCacheRange(data_020fe9ac, 32);
        }
        tileIndex = (tileIndex + 1) & 255;
        key[1]++;
    }
}
