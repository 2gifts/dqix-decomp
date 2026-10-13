#include <globaldefs.h>
#include "Filesystem/OverlayFSManagement.h"
#include "Resource/ResourceMutex.h"
#include "System/Mutex.h"

extern "C" int func_020a1bb4(unsigned int id);
extern "C" void _Z22DispatchByFlag020d9834i(int flag);
bool LoadCompressedOverlay(const OverlayMetadata& overlay);
void DecompressAndStaticInitializeOverlay(const OverlayMetadata& overlay);

extern volatile int data_01ffd348;
struct OverlayMappingRow {
    volatile signed char entries[6];
};
extern OverlayMappingRow data_01ffd364[8];
extern volatile unsigned char data_01ffd340;
extern volatile unsigned char data_01ffd344;
extern Mutex data_01ffd34c;
extern OverlayMetadata data_01ffd394[35];

struct OverlaySlotEntry {
    int column;
    int unknown4;
};
extern OverlaySlotEntry data_020e8f20[35];

// USA: func_020a1940
extern "C" ARM int func_020a1940(int id) {
    int result = 0;
    if ((unsigned int)id < 35) {
        OverlaySlotEntry* table;
        int rowIndex = data_01ffd348;
        table = data_020e8f20;
        OverlayMappingRow* const row = &data_01ffd364[rowIndex];
        int column = table[id].column;
        signed char mappedOverlay = row->entries[column];
        if (mappedOverlay != id) {
            func_020a1bb4(mappedOverlay);
            while (data_01ffd340 != 0) {
                _Z22DispatchByFlag020d9834i(0);
            }
            data_01ffd340 = 1;
            LockResourceMutex();
            OverlayMetadata* const overlays = data_01ffd394;
            LoadCompressedOverlay(overlays[id]);
            DecompressAndStaticInitializeOverlay(overlays[id]);
            UnlockResourceMutex();
            data_01ffd340 = 0;
            if (data_01ffd344 != 0) {
                LockMutex(&data_01ffd34c);
            }
            row->entries[table[id].column] = (signed char)id;
            if (data_01ffd344 != 0) {
                UnlockMutex(&data_01ffd34c);
            }
            result = 1;
        } else {
            result = 1;
        }
    }
    return result;
}
