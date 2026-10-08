#include <globaldefs.h>

#include "Filesystem/BackupDevice.h"
#include "Filesystem/FSInnerDefs.h"
#include "System/Memory.h"

// USA: func_020d0078
extern "C" ARM void func_020d0078(unsigned int type) {
    Arm7CardReadData *const command = data_021118e0.pSharedData;

    VectorizedMemset(&command->backup.spec, 0, sizeof(command->backup.spec));
    command->backup.type              = type;
    command->backup.spec.capabilities = 0x203f;
    if (type != 0) {
        const unsigned int size = 1 << (((int) type >> 8) & 0xff);
        const int device        = type & 0xff;
        const int vendor        = ((int) type >> 16) & 0xff;

        command->backup.spec.totalSize     = size;
        command->backup.spec.initialStatus = 0xff;
        if (device == 1) {
            switch (size) {
                default: goto invalidType;
                case 0x200:
                    command->backup.spec.pageSize        = 0x10;
                    command->backup.spec.addressWidth    = 1;
                    command->backup.spec.programPageTime = 5;
                    command->backup.spec.initialStatus   = 0xf0;
                    break;
                case 0x2000:
                    command->backup.spec.pageSize        = 0x20;
                    command->backup.spec.addressWidth    = 2;
                    command->backup.spec.programPageTime = 5;
                    command->backup.spec.initialStatus   = 0;
                    break;
                case 0x10000:
                    command->backup.spec.pageSize        = 0x80;
                    command->backup.spec.addressWidth    = 2;
                    command->backup.spec.programPageTime = 10;
                    command->backup.spec.initialStatus   = 0;
                    break;
                case 0x20000:
                    command->backup.spec.pageSize        = 0x100;
                    command->backup.spec.addressWidth    = 3;
                    command->backup.spec.programPageTime = 5;
                    command->backup.spec.initialStatus   = 0;
                    break;
            }
            command->backup.spec.sectorSize = command->backup.spec.pageSize;
            command->backup.spec.capabilities |= 0x40;
            command->backup.spec.capabilities |= 0x4300;
        } else if (device == 2) {
            switch (size) {
                default: goto invalidType;
                case 0x40000:
                case 0x80000:
                case 0x100000:
                    command->backup.spec.writePageTime    = 25;
                    command->backup.spec.writePageTimeout = 300;
                    command->backup.spec.erasePageTime    = 300;
                    command->backup.spec.eraseSectorTime  = 5000;
                    command->backup.spec.capabilities |= 0x480;
                    break;
                case 0x200000:
                    command->backup.spec.writePageTime      = 23;
                    command->backup.spec.writePageTimeout   = 300;
                    command->backup.spec.eraseSectorTime    = 500;
                    command->backup.spec.eraseSectorTimeout = 5000;
                    command->backup.spec.eraseChipTime      = 10000;
                    command->backup.spec.eraseChipTimeout   = 60000;
                    command->backup.spec.initialStatus      = 0;
                    command->backup.spec.capabilities |= 0x80;
                    command->backup.spec.capabilities |= 0x5400;
                    break;
                case 0x400000:
                    command->backup.spec.eraseSectorTime       = 600;
                    command->backup.spec.eraseSectorTimeout    = 3000;
                    command->backup.spec.eraseSubsectorTime    = 70;
                    command->backup.spec.eraseSubsectorTimeout = 150;
                    command->backup.spec.eraseChipTime         = 23000;
                    command->backup.spec.eraseChipTimeout      = 800000;
                    command->backup.spec.initialStatus         = 0;
                    command->backup.spec.subsectorSize         = 0x1000;
                    command->backup.spec.capabilities |= 0x1000;
                    command->backup.spec.capabilities |= 0xc000;
                    break;
                case 0x800000:
                    if (vendor == 0) {
                        command->backup.spec.eraseSectorTime    = 1000;
                        command->backup.spec.eraseSectorTimeout = 3000;
                        command->backup.spec.eraseChipTime      = 68000;
                        command->backup.spec.eraseChipTimeout   = 160000;
                        command->backup.spec.initialStatus      = 0;
                        command->backup.spec.capabilities |= 0x1000;
                        command->backup.spec.capabilities |= 0x4000;
                    } else if (vendor == 1) {
                        command->backup.spec.eraseSectorTime    = 1000;
                        command->backup.spec.eraseSectorTimeout = 3000;
                        command->backup.spec.eraseChipTime      = 68000;
                        command->backup.spec.eraseChipTimeout   = 160000;
                        command->backup.spec.initialStatus      = 0x84;
                        command->backup.spec.capabilities |= 0x1000;
                        command->backup.spec.capabilities |= 0x4000;
                    }
                    break;
            }
            command->backup.spec.sectorSize      = 0x10000;
            command->backup.spec.pageSize        = 0x100;
            command->backup.spec.addressWidth    = 3;
            command->backup.spec.programPageTime = 5;
            command->backup.spec.capabilities |= 0xb40;
        } else if (device == 3) {
            switch (size) {
                default: goto invalidType;
                case 0x2000:
                case 0x8000: break;
            }
            command->backup.spec.pageSize      = size;
            command->backup.spec.sectorSize    = size;
            command->backup.spec.addressWidth  = 2;
            command->backup.spec.initialStatus = 0;
            command->backup.spec.capabilities |= 0x40;
            command->backup.spec.capabilities |= 0x4300;
        } else {
        invalidType:
            command->backup.type                 = 0;
            command->backup.spec.totalSize       = 0;
            data_021118e0.pSharedData->unknown_0 = 3;
            return;
        }
    }
}
