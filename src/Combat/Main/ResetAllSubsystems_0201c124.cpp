#include <globaldefs.h>

#if defined(jpn)
enum { threeWordsOffset = 0x2764, stateOffset = 0x26a4, grottoOffset = 0x240c, floorMapOffset = 0x25f4, blankTargetOffset = 0x860, nameTablesOffset = 0x620, modelsOffset = 0x4b8, lightingOffset = 0x12c, featuresOffset = 0x8c };
#else
enum { threeWordsOffset = 0x2724, stateOffset = 0x2664, grottoOffset = 0x23ec, floorMapOffset = 0x25b4, blankTargetOffset = 0x840, nameTablesOffset = 0x600, modelsOffset = 0x498, lightingOffset = 0x10c, featuresOffset = 0x6c };
#endif
#include "Graphics/LightingInfo.h"

struct ClearThreeWords02094d00Struct;
struct InitState0208f7ecStruct;
class ActiveGrottoClass {
public:
    void BlankFunction2() const;
};
class FloorMap {
public:
    void Clear2();
};

void ResetBigStruct02013750(void* p, int n);
void ClearThreeWords02094d00(ClearThreeWords02094d00Struct* p);
void InitState0208f7ec(InitState0208f7ecStruct* p);
extern "C" void _Z21BlankFunction020984acv(void* p);
void NotifyThenResetNameTable(void* p);
extern "C" void _ZN7Model3DD1Ev(void* p);
extern "C" void _ZN12ZoneFeatures5ResetEv(void* p);

extern "C" void func_0200ef44(void* p, int count, int size, void* fn);

// USA: func_0201c124  (semantic: ResetAllSubsystems_0201c124)
extern "C" ARM void* func_0201c124(void* self) {
    ResetBigStruct02013750(self, 1);
    ClearThreeWords02094d00((ClearThreeWords02094d00Struct*)((char*)self + threeWordsOffset));
    InitState0208f7ec((InitState0208f7ecStruct*)((char*)self + stateOffset));
    ((ActiveGrottoClass*)((char*)self + grottoOffset))->BlankFunction2();
    ((FloorMap*)((char*)self + floorMapOffset))->Clear2();
    _Z21BlankFunction020984acv((char*)self + blankTargetOffset);
    func_0200ef44((char*)self + nameTablesOffset, 4, 0x88, (void*)NotifyThenResetNameTable);
    func_0200ef44((char*)self + modelsOffset, 2, 0xac, (void*)_ZN7Model3DD1Ev);
    ((LightingInfo*)((char*)self + lightingOffset))->Initialize();
    _ZN12ZoneFeatures5ResetEv((char*)self + featuresOffset);
    return self;
}
