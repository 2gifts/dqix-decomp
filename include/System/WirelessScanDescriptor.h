#ifndef SYSTEM_WIRELESS_SCAN_DESCRIPTOR_H
#define SYSTEM_WIRELESS_SCAN_DESCRIPTOR_H

struct WirelessScanDescriptor {
    unsigned short length;
    unsigned short rssi;
    unsigned char bssid[6];
    unsigned short ssidLength;
    unsigned char ssid[32];
    unsigned short capability;
    unsigned short basicRates;
    unsigned short supportedRates;
    unsigned short beaconPeriod;
    unsigned short dtimPeriod;
    unsigned short channel;
    unsigned short cfpPeriod;
    unsigned short cfpMaxDuration;
    unsigned short gameInfoLength;
    unsigned short reserved;
    unsigned char gameInfo[0x80];
};

struct WirelessScanNode {
    unsigned char used;
    unsigned char unknown01;
    unsigned short unknown02;
    int index;
    WirelessScanNode* previous;
    WirelessScanNode* next;
    WirelessScanDescriptor descriptor;
};

WirelessScanDescriptor* GetOffset10FromResult_0220ec04(int index);
extern "C" WirelessScanNode* func_ov031_0220ee50(int index);

#endif
