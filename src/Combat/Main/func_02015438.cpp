#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Graphics/LightingManager.h"
#include "Resource/GameResources.h"
#include "World/Zone3D.h"

struct HeadNode02046b24;
struct EntryList0217208;
int GetHeadNodeIdOrMinusOne(struct HeadNode02046b24** obj);
extern "C" void _Z22ForEachElement02015518PvPc(void* a, char* list);
void SetByteField0x253(void* obj);
extern "C" void func_02013e18(Zone3D* self);
extern "C" void func_02017208(struct EntryList0217208* self);
extern "C" void func_020158cc(Zone3D* self);
extern "C" void func_020a84e0();
extern "C" void _Z28SetBitFromValueRange0201ba68Pv(void*);
void DispatchField0x744FlagsAndNotify(unsigned char*);
extern "C" void _Z29MaybeClearGrottoState0201bfd4v(Zone3D* self);

// USA: func_02015438
extern "C" ARM void func_02015438(Zone3D* self) {
    GameState* battle = GameState::GetInstance();
    if (*(int*)&self->unk_428[0] == 0)
        return;

    if (self->unknown_424_ != 0) {
        func_02013e18(self);
        return;
    }

    char* p = (char*)self->firstBMDJStruct_41c_;
    while (p != 0) {
        _Z22ForEachElement02015518PvPc(self, p);
        p = *(char**)(p + 0x54);
    }

    unsigned char n = self->unk_830[0];
    if (n != 0) {
        n--;
        self->unk_830[0] = n;
        if ((self->unk_830[0] & 0xff) == 0) {
            void* actor = battle->GetProtagonist();
            if (actor != 0) {
                if (GetHeadNodeIdOrMinusOne(
                        *(struct HeadNode02046b24***)((char*)func_ov017_0218b5b0() + 0x3000 + 0x6fc)) != 4) {
                    SetByteField0x253(actor);
                }
            }
            self->unk_830[0] = 0;
        }
    }

    func_02017208((struct EntryList0217208*)self);
    func_020158cc(self);
    LightingManager::GetInstance()->RecomputeAdvancedLighting();
    func_020a84e0();
    _Z28SetBitFromValueRange0201ba68Pv(self);
    DispatchField0x744FlagsAndNotify((unsigned char*)self);
    _Z29MaybeClearGrottoState0201bfd4v(self);
}
