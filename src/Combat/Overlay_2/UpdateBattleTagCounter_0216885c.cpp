#include <globaldefs.h>

int GetGlobalField0x1c020421a0();
int TestFlag0SetAndFlag1Clear_02012444(unsigned short* obj, int mask);
int CheckByteSetAndByteClear_02012aac(unsigned char* obj);
extern unsigned short data_02114e30;
extern unsigned char data_02114e54;

// USA: func_ov002_0216885c
ARM void UpdateBattleTagCounter_0216885c(char* base) {
    char* field = (char*)GetGlobalField0x1c020421a0();
    int v998 = *(int*)(field + 0x998);
    if (v998 != 0) {
        unsigned char b454 = *(unsigned char*)(base + 0x2000 + 0x454);
        unsigned char b455 = *(unsigned char*)(base + 0x2000 + 0x455);
        if (b454 >= b455) {
            (*(int*)(base + 0x1000 + 0xbc0))++;
        }
        int v9a0 = *(int*)(field + 0x9a0);
        if (v9a0 != 3) {
            return;
        }
        if (!TestFlag0SetAndFlag1Clear_02012444(&data_02114e30, 0x603)) {
            if (!CheckByteSetAndByteClear_02012aac(&data_02114e54)) {
                return;
            }
        }
        (*(int*)(base + 0x1000 + 0xbc0))--;
    } else {
        (*(int*)(base + 0x1000 + 0xbc0))++;
    }
}
