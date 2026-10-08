#pragma once

struct BackupDeviceSpec {
    unsigned int totalSize;
    unsigned int sectorSize;
    unsigned int subsectorSize;
    unsigned int pageSize;
    unsigned int addressWidth;
    unsigned int programPageTime;
    unsigned int writePageTime;
    unsigned int writePageTimeout;
    unsigned int eraseChipTime;
    unsigned int eraseChipTimeout;
    unsigned int eraseSectorTime;
    unsigned int eraseSectorTimeout;
    unsigned int eraseSubsectorTime;
    unsigned int eraseSubsectorTimeout;
    unsigned int erasePageTime;
    unsigned char initialStatus;
    unsigned char padding55[3];
    unsigned int capabilities;
    // This final word is cleared with the specification; its purpose is unknown.
    unsigned int unknown5c;
};

extern "C" void func_020d0078(unsigned int type);
