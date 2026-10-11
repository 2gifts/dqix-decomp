#include <globaldefs.h>

#if defined(jpn)
enum { kOffset54 = 0x74, kOffset6c = 0x8c, kOffsetf4 = 0x114, kOffset10c = 0x12c, kOffset498 = 0x4b8, kOffset600 = 0x620, kOffset840 = 0x860, kOffset1c8 = 0x1e8, kOffset264 = 0x2a4, kOffset324 = 0x364, kOffset730 = 0x770, kOffset354 = 0x394, kGrottoLow = 0xc, kGrottoHigh = 0x2400 };
#else
enum { kOffset54 = 0x54, kOffset6c = 0x6c, kOffsetf4 = 0xf4, kOffset10c = 0x10c, kOffset498 = 0x498, kOffset600 = 0x600, kOffset840 = 0x840, kOffset1c8 = 0x1c8, kOffset264 = 0x264, kOffset324 = 0x324, kOffset730 = 0x730, kOffset354 = 0x354, kGrottoLow = 0x3ec, kGrottoHigh = 0x2000 };
#endif

#include "Graphics/LightingInfo.h"
#include "Memory/SafeAllocator.h"
#include "Grotto/Main/FloorMap.h"
#include "Grotto/Main/ActiveGrottoClass.h"

extern "C" void _ZN12ZoneFeatures5ResetEv(void* obj);

extern "C" void func_0200ee94(void* obj, int a, int b, void* cb1, void* cb2);
extern "C" void* _ZN7Model3DC1Ev(void* obj);
extern "C" void* _ZN7Model3DD1Ev(void* obj);
void* NotifyThenResetNameTable(void* obj);
void* ResetNameTableThenNotify(void* obj);

extern "C" void func_020982b4(void* obj);

struct InitState0208f7ecStruct;
void InitState0208f7ec(struct InitState0208f7ecStruct* s);

struct ClearThreeWords02094d00Struct;
void ClearThreeWords02094d00(struct ClearThreeWords02094d00Struct* s);

void* ZeroInitReturn020de824(void* obj);

extern "C" void func_020134e0(void* obj);

// USA: func_0201c014
ARM void* InitBigStruct0201c014(void* obj) {
    ((SafeAllocator*)((char*)obj + kOffset54))->ResetAllocatorPointer();
    _ZN12ZoneFeatures5ResetEv((char*)obj + kOffset6c);
    *(int*)((char*)obj + kOffsetf4) = 0;
    ((LightingInfo*)((char*)obj + kOffset10c))->Initialize();
    func_0200ee94((char*)obj + kOffset498, 2, 0xac, (void*)_ZN7Model3DC1Ev, (void*)_ZN7Model3DD1Ev);
    func_0200ee94((char*)obj + kOffset600, 4, 0x88, (void*)ResetNameTableThenNotify, (void*)NotifyThenResetNameTable);
    func_020982b4((char*)obj + kOffset840);
    ActiveGrottoClass* grotto = (ActiveGrottoClass*)((char*)obj + kGrottoLow + kGrottoHigh);
    ((FloorMap*)((char*)grotto + kOffset1c8))->Clear();
    grotto->Clear();
    InitState0208f7ec((struct InitState0208f7ecStruct*)((char*)obj + kOffset264 + 0x2400));
    ClearThreeWords02094d00((struct ClearThreeWords02094d00Struct*)((char*)obj + kOffset324 + 0x2400));
    ((SafeAllocator*)((char*)obj + kOffset730 + 0x2000))->ResetAllocatorPointer();
    ZeroInitReturn020de824((char*)obj + kOffset354 + 0x2400);
    func_020134e0(obj);
    return obj;
}
