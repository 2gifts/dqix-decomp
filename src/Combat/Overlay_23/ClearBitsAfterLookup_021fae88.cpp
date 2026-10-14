#include <globaldefs.h>

extern "C" void* func_ov023_021f6880(void* obj, int key);
extern "C" void* func_ov023_021fad18(void* node);
void ClearBitRange_021f6c3c(void*, unsigned int, unsigned int, unsigned int);
void* GetEntryPtr_021fa854(char* obj, unsigned int idx);

// USA: func_ov023_021fae88
ARM void ClearBitsAfterLookup_021fae88(void* a, void* b) {
    unsigned short key = *(unsigned short*)((char*)a + 0x20);
    void* node = func_ov023_021f6880(b, key);
    if (node == NULL) return;
    char* sub = (char*)func_ov023_021fad18(node);
    unsigned char idx = *(unsigned char*)(sub + 0x50);
    void* entry = GetEntryPtr_021fa854(sub, *(unsigned short*)((char*)a + 0x22));
    unsigned short startBit = *(unsigned short*)entry;
    unsigned short count = *(unsigned short*)((char*)a + 0x24);
    ClearBitRange_021f6c3c(b, idx, count, startBit);
}
