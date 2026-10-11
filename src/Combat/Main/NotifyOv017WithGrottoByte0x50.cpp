#include <globaldefs.h>

#if defined(jpn)
enum { activeGrottoOffset = 0x240c };
#else
enum { activeGrottoOffset = 0x23EC };
#endif

extern "C" void* func_02012fe4(void);
extern "C" int func_ov017_021d6134(void*, int);

struct ActiveGrottoClass {
    ActiveGrottoClass* GetDetailedData();
};

// USA: func_0209dbac
ARM int NotifyOv017WithGrottoByte0x50(void* arg) {
    ActiveGrottoClass* g = (ActiveGrottoClass*)((char*)func_02012fe4() + activeGrottoOffset);
    if (g == NULL) return 0;
    ActiveGrottoClass* r = g->GetDetailedData();
    if (r == NULL) return 0;
    if (*((unsigned char*)r + 0x1) != 1) return 0;
    func_ov017_021d6134(arg, *((unsigned char*)r + 0x50));
    return 1;
}
