#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Grotto/Main/ActiveGrottoClass.h"
#include "Resource/GameResources.h"

struct ZoneState { unsigned short zoneId; unsigned short nextZoneId; };
struct TailList020469b4;
struct TailNode020469b4;
struct FindEntryById02096134Table;
struct FindEntryById02096134Elem { unsigned int _pad0:14, b14:1; };
struct GrottoListNode { char _pad0[8]; unsigned short h8; };

extern "C" ZoneState* func_02012fe4();
extern "C" int* func_0202ae18();
extern "C" unsigned char* func_0205ec34();
extern "C" int func_0202c508(void* obj);
extern "C" void func_ov017_021baedc(void* obj, int flag);
struct FindEntryById02096134Table* GetGlobal02109418();
extern "C" struct FindEntryById02096134Elem* _Z21FindEntryById02096134P26FindEntryById02096134Tablei(struct FindEntryById02096134Table*, int);
void AppendNodeToTail(struct TailList020469b4*, struct TailNode020469b4*);
int TestBitInByteArray(int, unsigned char*, int);
void SetOrClearBitInArray(void*, unsigned char*, int, int);
extern "C" void _Z15InitObj021beba4Pc(char*);
extern "C" int _Z17IsInRange0201b588i(int);
void* GetField0x3f8Address(GameState* battleStruct);

// USA: func_0208fc30
extern "C" ARM void func_0208fc30(ActiveGrottoClass* obj) {
    int* session;
    unsigned char* state;
    GameResources* resources;
    GrottoStruct* grotto;
    int zoneId;
    int nextZoneId;
    struct TailList020469b4* list;
    ZoneState* zone = func_02012fe4();
    zoneId = zone->zoneId;
    nextZoneId = zone->nextZoneId;
    session = func_0202ae18();
    state = func_0205ec34();
    GameState* game = GameState::GetInstance();
    GetField0x3f8Address(game);
    resources = func_ov017_0218b5b0();
    list = (struct TailList020469b4*)resources->unknown_ptr_array_36fc[0];
    grotto = game->GetGrottoStruct();

    if (_Z17IsInRange0201b588i(zoneId) && !_Z17IsInRange0201b588i(nextZoneId) &&
        (nextZoneId < 0x7530 || nextZoneId > 0x9c3f)) {
        void* node;
        bool changed = false;
        if (func_0202c508(session)) {
            node = resources->unknown_ptr_array_371c[6];
            func_ov017_021baedc(node, 1);
            struct FindEntryById02096134Table* table = GetGlobal02109418();
            if (*(unsigned short*)grotto->unk_a == 6 && TestBitInByteArray((int)state, state + 0x8c, 0x12) &&
                !TestBitInByteArray((int)state, state + 0x8c, 0x2d) &&
                !_Z21FindEntryById02096134P26FindEntryById02096134Tablei(table, 0xae)->b14) {
                ((struct GrottoListNode*)node)->h8 = 0x5105;
                AppendNodeToTail(list, (struct TailNode020469b4*)node);
                changed = true;
                SetOrClearBitInArray(state, state + 0x8c, 0x2d, 1);
            } else if (obj->GetActiveGrottoEnviron() == 2 &&
                       TestBitInByteArray((int)state, state + 0x8c, 0x13) &&
                       !TestBitInByteArray((int)state, state + 0x8c, 0x2e) &&
                       !_Z21FindEntryById02096134P26FindEntryById02096134Tablei(table, 0xc1)->b14) {
                ((struct GrottoListNode*)node)->h8 = 0x51c3;
                AppendNodeToTail(list, (struct TailNode020469b4*)node);
                changed = true;
                SetOrClearBitInArray(state, state + 0x8c, 0x2e, 1);
            }
        }
        if (!changed && ((unsigned char*)obj)[0x260] == 0) {
            void* node = resources->unknown_ptr_array_3afc[28];
            _Z15InitObj021beba4Pc((char*)node);
            AppendNodeToTail(list, (struct TailNode020469b4*)node);
        }
    } else {
        if (((unsigned char*)obj)[0x261] != 0) {
            void* node = resources->unknown_ptr_array_3afc[28];
            _Z15InitObj021beba4Pc((char*)node);
            AppendNodeToTail(list, (struct TailNode020469b4*)node);
            ((unsigned char*)obj)[0x261] = 0;
        }
    }
}
