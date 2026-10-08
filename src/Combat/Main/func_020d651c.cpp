#include <globaldefs.h>

struct WMPortRecvCallback
{
    unsigned short apiid;
    unsigned short errcode;
    unsigned short state;
    unsigned short port;
    void* recvBuf;
    void* data;
    unsigned short length;
    unsigned short aid;
    unsigned char macAddress[6];
    unsigned short seqNo;
    void* arg;
    unsigned short myAid;
    unsigned short connectedAidBitmap;
    unsigned char ssid[24];
    unsigned short reason;
    unsigned short rssi;
    unsigned short maxSendDataSize;
    unsigned short maxRecvDataSize;
};

struct WMDataSet
{
    unsigned short aidBitmap;
    unsigned short receivedBitmap;
    unsigned short data[254];
};

struct WMDataSharingInfo
{
    WMDataSet ds[4];
    unsigned short seqNum[4];
    unsigned short writeIndex;
    unsigned short sendIndex;
    unsigned short readIndex;
    unsigned short aidBitmap;
    unsigned short dataLength;
    unsigned short stationNumber;
    unsigned short dataSetLength;
    unsigned short port;
    unsigned short doubleMode;
    unsigned short currentSeqNum;
    unsigned short state;
    unsigned short reserved[1];
};

extern "C" void func_020ca3b8(const void* src, void* dst, unsigned long size);
unsigned short GetBattleContextField0x150();

// USA: func_020d651c
extern "C" ARM void func_020d651c(void* callback)
{
    WMPortRecvCallback* const cb = (WMPortRecvCallback*)callback;
    WMDataSharingInfo* const dsInfo = (WMDataSharingInfo*)cb->arg;
    if (dsInfo == NULL)
        return;
    if (cb->errcode == 0)
    {
        switch (cb->state)
        {
        case 21:
        {
            unsigned short length;
            unsigned short aidBitmap;
            unsigned short aid;
            WMDataSet* dataSet;
            dataSet = (WMDataSet*)cb->data;
            length = cb->length;
            aidBitmap = dataSet->aidBitmap;
            aid = GetBattleContextField0x150();
            if (length != dsInfo->dataSetLength)
            {
                if (length > sizeof(WMDataSet))
                    length = sizeof(WMDataSet);
            }
            if (length < 4)
                return;
            if (!(aidBitmap & (1 << aid)))
                return;
            func_020ca3b8(dataSet, &dsInfo->ds[dsInfo->writeIndex], length);
            dsInfo->seqNum[dsInfo->writeIndex] = cb->seqNo >> 1;
            dsInfo->writeIndex = (dsInfo->writeIndex + 1) & 3;
            break;
        }
        case 7:
        case 9:
        case 25:
        case 26:
            break;
        }
    }
    else
    {
        dsInfo->state = 5;
    }
}
