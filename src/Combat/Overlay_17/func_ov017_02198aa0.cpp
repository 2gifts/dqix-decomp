#include <globaldefs.h>
#include "World/ZoneLifecycle.h"
#include "GameState/GameState.h"
#include "Resource/Brightness.h"
#include "Combat/Main/CopyRecord0200fbb4.h"

struct BitField0203402c;
struct Vec3copy0202ec84;
struct TailList020469b4;
struct TailNode020469b4;
struct Controller02198aa0 { unsigned char padding0[0x9a0]; int field9a0; };
struct Position02198aa0 { int x,y,z; };
struct GrottoView02198aa0 { unsigned char padding0[8]; signed char offset; unsigned char padding9[3]; int entranceZone; Position02198aa0 position; };
struct Cursor02198aa0 { unsigned char padding0[0x38]; int x, y; unsigned int field40, mode; unsigned char padding48[12]; unsigned char active; };
struct Event02198aa0 { unsigned char kind; unsigned char padding1[19]; };
struct State02198aa0 { unsigned short zoneId; unsigned char padding2[5]; unsigned char field7; unsigned char padding8[4]; unsigned char fieldC; unsigned char paddingD[15]; unsigned short angle; };
void* GetField0x3b0Value(GameState*);
void* GetGlobalField0x1c020421a0();
extern "C" void* func_0202ae18();
extern "C" void* func_02012fe4();
int CheckSubstructByte0x7cPositive(signed char*);
int CheckField0xc4Low15BitsNonZero(BitField0203402c*);
int CheckField0NonZero(int*);
extern "C" int func_0202c540(void*);
void InitObj0219a674(unsigned char*);
extern "C" void func_ov017_0219b33c(void*, Event02198aa0*);
int TestFlag0SetAndFlag1Clear(unsigned short*, int);
int ComputeTwoFromVec3_0202ec84(void*, Vec3copy0202ec84*, int*, int*);
void* GetField0x3f8Address(GameState*);
void InitStruct02070378(char*);
void InitAndResetHeader_0219e310(unsigned char*, int);
void AppendNodeToTail(TailList020469b4*, TailNode020469b4*);
void InitByteHeader_021be0a0(unsigned char*);
extern unsigned short data_02114e30[];
extern Cursor02198aa0 data_02114e54;

// USA: func_ov017_02198aa0
extern "C" ARM void func_ov017_02198aa0(GameResources* self) {
    GameState* game = GameState::GetInstance();
    GameObject* actor = game->GetUnknownGameObject();
    void* camera = GetField0x3b0Value(game);
    GameResources* resources = func_ov017_0218b5b0();
    Controller02198aa0* controller = (Controller02198aa0*)GetGlobalField0x1c020421a0();
    void* search = func_0202ae18();
    void* zone = func_02012fe4();
    GrottoStruct* grotto = game->GetGrottoStruct();
    unsigned char discovery = grotto->activeMapData.GetDiscoveryState();
    unsigned char mapType = grotto->activeMapData.GetMapType();
    unsigned char environment = grotto->activeEnviron;
    if (CheckSubstructByte0x7cPositive((signed char*)actor) || !grotto->unknown_0[0]) return;
    if (((GrottoView02198aa0*)grotto)->entranceZone != actor->obj3D_.GetField06() || controller->field9a0) return;
    if (IsBrightnessTransitionActive(resources)) return;
    if (CheckField0xc4Low15BitsNonZero((BitField0203402c*)actor)) return;
    if (discovery != 2 && discovery != 3 && CheckField0NonZero((int*)search) && func_0202c540(search)) return;
    Position02198aa0 entrance = ((GrottoView02198aa0*)grotto)->position;
    int inside = 0;
    if (entrance.x - 0x2666 < actor->obj3D_.position_.x && actor->obj3D_.position_.x < entrance.x + 0x2666 &&
          entrance.z - 0x2666 < actor->obj3D_.position_.z && actor->obj3D_.position_.z < entrance.z + 0x2666 &&
          entrance.y - 0x1000 < actor->obj3D_.position_.y && actor->obj3D_.position_.y < entrance.y + 0x1000) inside = 1;
    if (!inside) return;
    Event02198aa0 event;
    InitObj0219a674((unsigned char*)&event);
    event.kind = 4;
    func_ov017_0219b33c(self, &event);
    int proceed = 0;
    if (TestFlag0SetAndFlag1Clear(data_02114e30, 1)) proceed = 1;
    int cursorX = -1;
    int cursorY = -1;
    if (data_02114e54.active && data_02114e54.mode < 10) { cursorX = data_02114e54.x; cursorY = data_02114e54.y; }
    {
        int screenX, screenY;
        ComputeTwoFromVec3_0202ec84(camera, (Vec3copy0202ec84*)&actor->obj3D_.position_, &screenX, &screenY);
        if (cursorX > 0x70 && cursorX < 0x90 && cursorY > 0x28 && cursorY < 0x60) proceed = 1;
        else if (screenX - 12 < cursorX && cursorX < screenX + 12 && screenY - 12 < cursorY && cursorY < screenY + 12) proceed = 0;
    }
    if (!proceed) return;
    if ((unsigned char)(discovery + 254) <= 1) {
        MaybeClearGrottoState0201bfd4(static_cast<Zone3D*>(zone));
        State02198aa0* state = (State02198aa0*)GetField0x3f8Address(game);
        InitStruct02070378((char*)state);
        state->field7 = 1;
        state->fieldC = 1;
        if (mapType == 2) {
            switch (environment) {
            case 1: state->zoneId = 0xa08d; break;
            case 2: state->zoneId = 0xa0f1; break;
            case 3: state->zoneId = 0xa155; break;
            case 4: state->zoneId = 0xa1b9; break;
            case 5: state->zoneId = 0xa21d; break;
            default: state->zoneId = 0xa08d; break;
            }
            unsigned short offset = ((GrottoView02198aa0*)grotto)->offset;
            state->zoneId += offset;
            state->angle = 0x323d;
        } else {
            state->zoneId = 0x9c41;
        }
        CallFunc0200fbb4AtField0x3f8(game, state);
        TailList020469b4* list = (TailList020469b4*)resources->unknown_ptr_array_36fc[0];
        unsigned char* node = (unsigned char*)resources->unknown_ptr_array_36fc[4];
        InitAndResetHeader_0219e310(node, 0);
        AppendNodeToTail(list, (TailNode020469b4*)node);
    } else {
        TailList020469b4* list = (TailList020469b4*)self->unknown_ptr_array_36fc[0];
        unsigned char* node = (unsigned char*)resources->unknown_ptr_array_3afc[26];
        InitByteHeader_021be0a0(node);
        AppendNodeToTail(list, (TailNode020469b4*)node);
    }
}
