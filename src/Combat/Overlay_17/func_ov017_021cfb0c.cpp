// JPN: func_ov017_021cffbc
#if defined(jpn)
enum { RegionOffset36fc = 0x34ec, RegionOffset3b0c = 0x3afc };
#else
enum { RegionOffset36fc = 0x36fc, RegionOffset3b0c = 0x3b0c };
#endif

#include <globaldefs.h>
#include "GameState/GameState.h"
#include "System/Matrix.h"

struct HeadNode02046b24;
struct ListHead02046b60;
struct TailList020469b4;
struct TailNode020469b4;
struct SearchStruct0202c1a4;

struct Obj021be40c {
    unsigned char pad0[0x10];
    Vector3i pos;
    int zoneId;
};

struct Counter021cfb0c {
    unsigned char pad0[0x14];
    int count;
};

struct Ov021cfb0c {
    unsigned char pad0[RegionOffset36fc];
    HeadNode02046b24** list;
    unsigned char pad3700[RegionOffset3b0c - 0x3700];
    struct Counter021cfb0c* counter;
    unsigned char pad3b10[0x3ca4 - 0x3b10];
    struct Obj021be40c* node;
};

struct GrottoEntrance021cfb0c {
    unsigned char pad0[0xc];
    int zoneId;
    Vector3i pos;
};

extern "C" int func_0202c508(struct SearchStruct0202c1a4* search);
extern "C" unsigned short* func_02012fe4(void);
void* GetField0x3f8Address(GameState* battleStruct);
int GetHeadNodeIdOrMinusOne(HeadNode02046b24** list);
extern "C" int _Z17IsInRange0201b588i(int v);
int ListContainsId(ListHead02046b60* list, int id);
extern "C" void _Z15InitObj021be40cP11Obj021be40c(struct Obj021be40c* obj);
void AppendNodeToTail(TailList020469b4* list, TailNode020469b4* node);

// USA: func_ov017_021cfb0c
extern "C" ARM void func_ov017_021cfb0c(int unused0, void* unused1, GameState* battleStruct, struct Ov021cfb0c* ov, struct SearchStruct0202c1a4* search) {
    int flag;
    unsigned short* zone;
    struct GrottoEntrance021cfb0c* grotto;
    unsigned short zoneId;
    HeadNode02046b24** list;
    unsigned short* cur;
    struct Obj021be40c* node;

    if (func_0202c508(search) != 0) {
        return;
    }

    zone = func_02012fe4();
    battleStruct->GetUnknownGameObject();
    zoneId = *zone;
    grotto = (struct GrottoEntrance021cfb0c*)battleStruct->GetGrottoStruct();
    list = ov->list;
    flag = 0;
    cur = (unsigned short*)GetField0x3f8Address(battleStruct);
    if (GetHeadNodeIdOrMinusOne(list) == 3) {
        if (_Z17IsInRange0201b588i(*cur)) {
            flag = 1;
        }
    }
    if (!_Z17IsInRange0201b588i(zoneId) && !flag) {
        return;
    }

    Vector3i pos = grotto->pos;
    pos.z += 0x2000;
    if (ListContainsId((ListHead02046b60*)list, 3) || ListContainsId((ListHead02046b60*)list, 1)) {
        unsigned short id = *(unsigned short*)GetField0x3f8Address(battleStruct);
        if (id == 0xc3b5) {
            return;
        }
        if (!_Z17IsInRange0201b588i(id)) {
            return;
        }
    }

    if (GetHeadNodeIdOrMinusOne(list) == 0x1a) {
        if (ov->counter->count >= 6) {
            return;
        }
    }
    if (ListContainsId((ListHead02046b60*)list, 0x4e)) {
        return;
    }

    node = ov->node;
    _Z15InitObj021be40cP11Obj021be40c(node);
    node->pos = pos;
    node->zoneId = grotto->zoneId;
    AppendNodeToTail((TailList020469b4*)list, (TailNode020469b4*)node);
}
