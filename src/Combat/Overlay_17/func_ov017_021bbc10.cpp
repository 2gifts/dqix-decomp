#include <globaldefs.h>

#include "Combat/Main/BattleList.h"
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Resource/GameResources.h"
#include "World/Object3D.h"

struct ListHead02046b60;
struct Obj020397cc;
struct Obj020d7aa0;
struct Base02010834;
struct Flags02033fcc;

struct Overlay021bbc10 {
    unsigned char pad00[1];
    unsigned char flag01;
    unsigned char pad02[6];
    unsigned short id08;
    unsigned short result0a;
    unsigned char pad0c[0x68];
    int task74;
    unsigned char pad78[0x24];
    unsigned char useAltPath9c;
    unsigned char pad9d[0xcc - 0x9d];
    unsigned char flagCc;
    unsigned char indexCd;
    unsigned char padCe[0xd0 - 0xce];
    unsigned char timerObj_d0[0x10];
    unsigned char padE0[0xfd - 0xe0];
    unsigned char flagFd;
    unsigned char padFe[1];
    unsigned char flagFf;
};

extern "C" void* _Z18GetFieldPtrAt0x26cPv(void* obj);
extern "C" int _Z12GetByte0x26cPc(GameObject* obj);
extern "C" int _Z12GetField0x70Pv(void* obj);
extern "C" void* _Z15GetFieldIfFlag4Pc(GameState* gs);
extern "C" int _Z18CheckField0NonZeroPi(void* p);
extern "C" void _Z13SetBitsInWordPjj(void* obj, unsigned int mask);
extern "C" int _Z15GetBitsInField0Pjj(void* obj, unsigned int mask);
extern "C" int _Z13PeekInputLogAv(void);
extern "C" void _Z13PushInputLogAi(unsigned int v);
extern "C" unsigned int* _Z27GetDataPtr02114e04_020d6c00v(void);
extern "C" void _Z16OrBitsIntoField0Pjj(unsigned int* p, unsigned int mask);
extern "C" void _Z15ClearIntAt0x23cPh(unsigned char* obj);
extern "C" void* _Z25GetGlobalResetObj020d7a50v(void);
extern "C" void _Z29TeardownAndResetState020d7aa0P11Obj020d7aa0(Obj020d7aa0* obj);
extern "C" void _Z27CancelPendingAction020397ccP11Obj020397cci(Obj020397cc* obj, int arg1);
extern "C" void _Z13SetField0x158Pvi(GameObject* obj, int v);
extern "C" void _Z29CaptureTransformState02053ed8Pv(void* obj);
extern "C" int _Z18GetField0x3acValueP9GameState(GameState* gs);
extern "C" void _Z34CopyCountedBytesToIntArray02010834P12Base02010834iPiS1_(Base02010834* base, int index, int* out, int* outCount);
extern "C" void _Z16SetFlag0x4At0xe0P13Flags02033fcc(GameObject* obj);
extern "C" void _Z30ClearBytesAndZeroBlock02039d24Ph(unsigned char* obj);
extern "C" void _Z21InitTimerObj_021bb088P11Obj021bb088(void* obj);
extern "C" int* _Z19GetFieldPtrAt0x5ca4Pv(void* obj);
extern "C" void _Z32ClearAllocSlotsAndStore_0215aa14P13SafeAllocator(void* alloc);
extern "C" void* func_02012fe4(void);
extern "C" void* func_0202ae18(void);
extern "C" ARM int func_ov017_021bb27c(Overlay021bbc10* self);

int ListContainsId(ListHead02046b60* list, int id);
int IsField0Null(void** obj);
void SetBrightness(GameResources* resources, int brightness, int duration);
char* strstr(const char* str, const char* substr);

extern const char data_ov017_021d7d6c[];
extern const char data_ov017_021d7d9e[];
extern const char data_ov017_021d7db8[];
extern const char data_ov017_021d7dbb[];
extern const char data_ov017_021d7dbf[];
extern const char data_ov017_021d7de0[];
extern const char data_ov017_021d7df9[];

// USA: func_ov017_021bbc10
extern "C" ARM int func_ov017_021bbc10(Overlay021bbc10* self) {
    GameState* gs = GameState::GetInstance();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    GameObject* unk = gs->GetUnknownGameObject();
    unsigned char* field4 = (unsigned char*)_Z15GetFieldIfFlag4Pc(gs);
    GameResources* res = func_ov017_0218b5b0();
    void* search = func_0202ae18();

    if (ListContainsId((ListHead02046b60*)res->unknown_ptr_array_36fc[0], 1)) {
        self->flagFf = 1;
        self->flag01 = 1;
        return self->result0a;
    }
    _Z16OrBitsIntoField0Pjj(_Z27GetDataPtr02114e04_020d6c00v(), 0x400e);
    if (res->unknown_4080 != 0) {
        return self->result0a;
    }
    unsigned char* field26c = (unsigned char*)_Z18GetFieldPtrAt0x26cPv(unk);
    if (_Z12GetByte0x26cPc(unk) != 0 && field26c[1] != 2) {
        return self->result0a;
    }
    if (self->flagFd == 0 && IsField0Null((void**)res->unknown_ptr_array_36fc[1]) == 0) {
        return self->result0a;
    }
    _Z13SetBitsInWordPjj(res, 0x10);
    if (_Z15GetBitsInField0Pjj(res, 0x1000) == 0 && _Z13PeekInputLogAv() != 1) {
        _Z13PushInputLogAi(1);
    }
    _Z32ClearAllocSlotsAndStore_0215aa14P13SafeAllocator(NULL);
    _Z27CancelPendingAction020397ccP11Obj020397cci((Obj020397cc*)unk, 1);
    _Z15ClearIntAt0x23cPh(field4);
    _Z29TeardownAndResetState020d7aa0P11Obj020d7aa0((Obj020d7aa0*)_Z25GetGlobalResetObj020d7a50v());
    *(unsigned short*)(field4 + 0x21e) = _Z12GetField0x70Pv(field4);

    if (_Z18CheckField0NonZeroPi(search)) {
        char* arr = (char*)GetPtrField0x2a04(gs);
        for (int i = 0; i < *(unsigned char*)(arr + 0xf7c); i++) {
            GameObject* combatant = GetCombatantWithFlag0x100(gs, *(unsigned char*)(arr + i + 0xf78));
            if (combatant != NULL) {
                _Z13SetField0x158Pvi(combatant, 3);
                _Z29CaptureTransformState02053ed8Pv(combatant);
            }
        }
    }

    int count;
    int ids[4];
    _Z34CopyCountedBytesToIntArray02010834P12Base02010834iPiS1_((Base02010834*)gs, _Z18GetField0x3acValueP9GameState(gs), ids, &count);
    for (int i = 0; i < count; i++) {
        GameObject* member = gs->GetPartyMemberByIndex(ids[i]);
        if (member != NULL) {
            _Z16SetFlag0x4At0xe0P13Flags02033fcc(member);
            if (_Z12GetByte0x26cPc(member) == 0 || ((unsigned char*)_Z18GetFieldPtrAt0x26cPv(member))[1] != 2) {
                ((Object3D*)member)->MaybeSetRegularAnimation(data_ov017_021d7d6c, 0x10);
            }
            _Z30ClearBytesAndZeroBlock02039d24Ph((unsigned char*)member);
        }
    }
    GameObject* extra = gs->GetPartyMemberByIndex(0xce);
    if (extra != NULL) {
        _Z30ClearBytesAndZeroBlock02039d24Ph((unsigned char*)extra);
    }
    _Z21InitTimerObj_021bb088P11Obj021bb088(self->timerObj_d0);
    int* ptr5ca4 = _Z19GetFieldPtrAt0x5ca4Pv(gs);
    ptr5ca4[0] = 0;
    ptr5ca4[1] = 0;
    loader->AddFence();

    if (self->useAltPath9c != 0) {
        self->task74 = loader->QueueLoadFile(data_ov017_021d7d9e, NULL);
    } else if (self->flagCc != 0) {
        char* name = *(char**)((char*)func_02012fe4() + 8);
        if (gs->GetGameObjectByIndex(self->indexCd) == NULL || strstr(name + 5, data_ov017_021d7db8) == NULL ||
            strstr(name + 5, data_ov017_021d7dbb) == NULL) {
            SetBrightness(res, 0, 0x28);
            func_ov017_021bb27c(self);
            self->flag01 = 1;
            return self->result0a;
        }
        return 0xc;
    } else {
        unsigned int id = self->id08;
        if (id >= 0x5208 && id < 0x9c40) {
            self->task74 = loader->QueueLoadFile(data_ov017_021d7dbf, NULL);
            loader->GetNumQueuedTasks();
        } else if (id >= 0x9c40) {
            self->task74 = loader->QueueLoadFile(data_ov017_021d7de0, NULL);
        } else {
            self->task74 = loader->QueueLoadFile(data_ov017_021d7df9, NULL);
        }
    }
    return 1;
}
