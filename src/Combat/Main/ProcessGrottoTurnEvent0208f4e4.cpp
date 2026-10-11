#include <globaldefs.h>

#if defined(jpn)
enum { kHeadOffset = 0x4ec, kMetadataOffset = 0x4c };
#else
enum { kHeadOffset = 0x6fc, kMetadataOffset = 0x6c };
#endif

#include "GameState/GameState.h"
#include "Grotto/Main/GrottoStruct.h"

struct HeadNode02046b24;
int GetHeadNodeIdOrMinusOne(struct HeadNode02046b24** obj);
extern "C" void _ZN8Object3D10MakeHiddenEv(unsigned char* obj);

extern "C" void* func_02012fe4(void* unused);
extern "C" void func_0208f68c(void* obj);
extern "C" void _ZN8Object3D14AdvanceEffectsEv(void* obj);

// USA: func_0208f4e4
ARM void ProcessGrottoTurnEvent0208f4e4(unsigned char* obj) {
    GameState* battle = GameState::GetInstance();
    void* miscPtr;
    void* headList;
    void* p = (char*)((void* (*)(GameState*))func_ov017_0218b5b0)(battle) + 0x3000;
    headList = *(void**)((char*)p + kHeadOffset);
    miscPtr = func_02012fe4(p);
    if (obj[0xb5]) {
        func_0208f68c(obj);
    }
    if (GetHeadNodeIdOrMinusOne((struct HeadNode02046b24**)headList) == 10) return;
    GrottoStruct* grotto = battle->GetGrottoStruct();
    TreasureMapMetadata* meta = (TreasureMapMetadata*)((char*)grotto + kMetadataOffset);
    unsigned short zoneId = *(unsigned short*)miscPtr;
    unsigned char state = meta->GetDiscoveryState();
    if (zoneId == *(int*)((char*)battle->GetGrottoStruct() + 0xc)) {
        _ZN8Object3D14AdvanceEffectsEv(obj + 8);
    }
    if (*(unsigned char*)grotto != 0) {
        switch (state) {
            case 2:
            case 3:
                return;
        }
    }
    _ZN8Object3D10MakeHiddenEv(obj + 8);
}
