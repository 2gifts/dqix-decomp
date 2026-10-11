#include <globaldefs.h>
#include "System/Mutex.h"
#include "Resource/ResourceMutex.h"
#include "Filesystem/OverlayFSManagement.h"
#include "Filesystem/FSInnerDefs.h"

extern "C" void _Z22DispatchByFlag020d9834i(int flag);
extern "C" void _Z18NitroVM_InitializeP7NitroVM(NitroVM* vm);
extern "C" unsigned int _Z21LoadCompressedOverlayRK15OverlayMetadataP7NitroVM(const OverlayMetadata* overlay, NitroVM* machine);
extern "C" void _Z18NitroVM_FinishReadP7NitroVM(NitroVM* vm);
extern "C" void _Z36DecompressAndStaticInitializeOverlayRK15OverlayMetadata(const OverlayMetadata* overlay);
extern "C" int func_020a1ccc(unsigned int id);

extern volatile int data_01ffd348;
extern volatile unsigned char data_01ffd344;
extern volatile unsigned char data_01ffd340;
extern signed char data_01ffd364;
extern Mutex data_01ffd34c;
extern struct OverlayMetadata data_01ffd394[35];

extern int data_020e8f20[][2];

// USA: func_020a1a40
extern "C" ARM int func_020a1a40(unsigned int id) {
    int result = 0;
    int (*table)[2];
    int rowIdx;
    volatile signed char* row;
    int cur;
    const OverlayMetadata* meta;
    NitroVM machine;
    unsigned int ok;
    if (id < 0x23) {
        table = data_020e8f20;
        rowIdx = data_01ffd348;
        row = &data_01ffd364 + rowIdx * 6;
        cur = row[table[id][0]];
        if (cur != (int)id) {
            func_020a1ccc(cur);
            while (data_01ffd340) {
                _Z22DispatchByFlag020d9834i(0);
            }
            data_01ffd340 = 1;
            LockResourceMutex();
            meta = &data_01ffd394[id];
            _Z18NitroVM_InitializeP7NitroVM(&machine);
            ok = _Z21LoadCompressedOverlayRK15OverlayMetadataP7NitroVM(meta, &machine);
            UnlockResourceMutex();
            if (ok) {
                result = 0;
                for (;;) {
                    if (!GET_FLAG_BIT(machine.flags, NITROVM_FLAG_IN_HANDLE_QUEUE)) {
                        break;
                    }
                    _Z22DispatchByFlag020d9834i(0);
                }
                LockResourceMutex();
                _Z18NitroVM_FinishReadP7NitroVM(&machine);
                _Z36DecompressAndStaticInitializeOverlayRK15OverlayMetadata(meta);
                UnlockResourceMutex();
                data_01ffd340 = 0;
                if (data_01ffd344) {
                    LockMutex(&data_01ffd34c);
                }
                row[table[id][0]] = id;
                if (data_01ffd344) {
                    UnlockMutex(&data_01ffd34c);
                }
                result = 1;
            } else {
                data_01ffd340 = 0;
            }
        } else {
            result = 1;
        }
    }
    return result;
}
