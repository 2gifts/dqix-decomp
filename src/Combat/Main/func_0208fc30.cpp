#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Grotto/Main/ActiveGrottoClass.h"
#include "Resource/GameResources.h"
#if defined(jpn)
#include "std_library_functions.h"
extern const char data_020f1438[];
#endif

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
struct FindEntryById02096134Table* GetGlobal02109418_02094d6c();
struct FindEntryById02096134Elem* FindEntryById02096134(struct FindEntryById02096134Table*, int);
void AppendNodeToTail(struct TailList020469b4*, struct TailNode020469b4*);
int TestBitInByteArray_0206dfb0(int, unsigned char*, int);
void SetOrClearBitInArray_0206df6c(void*, unsigned char*, int, int);
void InitObj021beba4(char*);
int IsInRange0201b588(int);
void* GetField0x3f8Address_0200fd0c(GameState* battleStruct);

// JPN: func_02090544
// USA: func_0208fc30
extern "C" ARM void func_0208fc30(ActiveGrottoClass* obj) {
#if defined(jpn)
    unsigned char* state;
    GameResources* resources;
    bool changed;
    int* session;
    const char* requiredNamePart;
    int nextZoneId;
    struct TailList020469b4* list;
    int zoneId;
    void* node;
#else
    int* session;
    unsigned char* state;
    GameResources* resources;
    GrottoStruct* grotto;
    int zoneId;
    int nextZoneId;
    struct TailList020469b4* list;
#endif
    ZoneState* zone = func_02012fe4();
    zoneId = zone->zoneId;
    nextZoneId = zone->nextZoneId;
    session = func_0202ae18();
    state = func_0205ec34();
    GameState* game = GameState::GetInstance();
    GetField0x3f8Address_0200fd0c(game);
    resources = func_ov017_0218b5b0();
    list = (struct TailList020469b4*)resources->unknown_ptr_array_36fc[0];
#if !defined(jpn)
    grotto = game->GetGrottoStruct();
#endif

    if (IsInRange0201b588(zoneId) && !IsInRange0201b588(nextZoneId) &&
        (nextZoneId < 0x7530 || nextZoneId > 0x9c3f)) {
#if defined(jpn)
        changed = false;
#else
        void* node;
        bool changed = false;
#endif
        if (func_0202c508(session)) {
            node = resources->unknown_ptr_array_371c[6];
            func_ov017_021baedc(node, 1);
            struct FindEntryById02096134Table* table = GetGlobal02109418_02094d6c();
#if defined(jpn)
            requiredNamePart = "\x96\xb2";
            const char* popupName = obj->GetPopupName();
            if (strstr(popupName, requiredNamePart) != NULL &&
#else
            if (*(unsigned short*)grotto->unk_a == 6 &&
#endif
                TestBitInByteArray_0206dfb0((int)state, state + 0x8c, 0x12) &&
                !TestBitInByteArray_0206dfb0((int)state, state + 0x8c, 0x2d) &&
                !FindEntryById02096134(table, 0xae)->b14) {
                ((struct GrottoListNode*)node)->h8 = 0x5105;
                AppendNodeToTail(list, (struct TailNode020469b4*)node);
                changed = true;
                SetOrClearBitInArray_0206df6c(state, state + 0x8c, 0x2d, 1);
            } else if (obj->GetActiveGrottoEnviron() == 2 &&
                       TestBitInByteArray_0206dfb0((int)state, state + 0x8c, 0x13) &&
                       !TestBitInByteArray_0206dfb0((int)state, state + 0x8c, 0x2e) &&
                       !FindEntryById02096134(table, 0xc1)->b14) {
                ((struct GrottoListNode*)node)->h8 = 0x51c3;
                AppendNodeToTail(list, (struct TailNode020469b4*)node);
                changed = true;
                SetOrClearBitInArray_0206df6c(state, state + 0x8c, 0x2e, 1);
            }
        }
        if (!changed && (unsigned char)obj->unknown_260_[0] == 0) {
            void* node = resources->unknown_ptr_array_3afc[28];
            InitObj021beba4((char*)node);
            AppendNodeToTail(list, (struct TailNode020469b4*)node);
        }
    } else {
        if ((unsigned char)obj->unknown_260_[1] != 0) {
            void* node = resources->unknown_ptr_array_3afc[28];
            InitObj021beba4((char*)node);
            AppendNodeToTail(list, (struct TailNode020469b4*)node);
            obj->unknown_260_[1] = 0;
        }
    }
}
