#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Graphics/LightingManager.h"
#include "Graphics/NSBXX/RenderConfig.h"
#include "System/Graphics.h"

struct Obj0204724C;
struct StructAt020472e4;

struct CombatRecord {
    char pad0[0x8];
    void* commandList;
    char pad1[0x1c - 0xc];
    Vector3i position;
    char pad2[0x34 - 0x28];
    Vector3i scale;
    char pad3[0x80 - 0x40];
    unsigned short diffuseColor;
    char pad4[0x88 - 0x82];
};

struct StructAt020472e4 {
    char pad0[0xc];
    void* streamTable;
    char pad1[0x1c - 0x10];
    Vector3i position;
    char pad2[0x80 - 0x28];
    unsigned short diffuseColor;
    char pad3[0x88 - 0x82];
};

struct CombatEntry {
    short unk0;
    short state;
    short timer;
    char pad0[0x8 - 6];
    CombatRecord commandRecord;
    StructAt020472e4 renderRecord;
    CombatRecord segments[4];
    Vector3i velocity[4];
};

struct CombatEntryList {
    char pad0[0x476];
    unsigned char count;
    char pad1[1];
    CombatEntry* entries;
    char pad2[0x2750 - 0x47c];
    void* field2750;
};

int GetField0x3b0Value(GameState* state);
void* GetPtrField0x144(void* obj);
extern "C" void _Z27ClearGlobalFlagBits02016d8cPv(void* arg);
int GetBoxTestResult(int* out);
extern "C" void _Z24SubmitGxCommands02047648Phii(unsigned char* obj, int idx, int something);
extern "C" void _Z27AdvanceStreamRecord0204724cP11Obj0204724C(Obj0204724C* obj);
void RenderTransformedFlaggedIndexedEntry(StructAt020472e4* obj, int param);

extern Vector3i data_020e6e20;
extern int data_020e6e64[4];

// USA: func_0201730c
extern "C" ARM void func_0201730c(CombatEntryList* list) {
    if (list->field2750 == NULL) return;

    GameState* game = GameState::GetInstance();
    void* camera = (void*)GetField0x3b0Value(game);
    if (camera == NULL) return;
    game->GetTickCount();
    unsigned short lightColor = LightingManager::GetInstance()->maybePotBarrelDiffuseColor_;
    _Z27ClearGlobalFlagBits02016d8cPv(GetPtrField0x144(camera));

    for (int i = 0; i < list->count; i++) {
        CombatEntry* entry = &list->entries[i];
        if (entry->state == -1) continue;

        RenderConfig::SetObjectPosition(&entry->commandRecord.position);

        Vector3i scale = data_020e6e20;
        RenderConfig::SetObjectScale(&scale);
        RenderConfig::SubmitToFifo();

        union {
            struct {
                short xMin;
                short yMin;
                short zMin;
                short xSize;
                short ySize;
                short zSize;
            } box;
            struct {
                unsigned int a;
                unsigned int b;
                unsigned int c;
            } u32s;
        } boxParams;
        boxParams.box.xMin = -0x800;
        boxParams.box.yMin = 0;
        boxParams.box.zMin = -0x800;
        boxParams.box.xSize = 0x1000;
        boxParams.box.ySize = 0x1000;
        boxParams.box.zSize = 0x1000;
        GXFIFO_TEST_BOX = boxParams.u32s.a;
        GXFIFO_TEST_BOX = boxParams.u32s.b;
        GXFIFO_TEST_BOX = boxParams.u32s.c;

        int visible;
        while (GetBoxTestResult(&visible) != 0) {}
        if (visible == 0) continue;

        scale = entry->commandRecord.scale;
        RenderConfig::SetObjectScale(&scale);
        RenderConfig::SubmitToFifo();

        entry->commandRecord.diffuseColor = lightColor;
        entry->renderRecord.diffuseColor = lightColor;
        for (int j = 0; j < 4; j++) entry->segments[j].diffuseColor = lightColor;

        if (entry->state != 3) {
            _Z24SubmitGxCommands02047648Phii((unsigned char*)&entry->commandRecord, 0, 1);
        } else if (entry->state == 3) {
            if (entry->timer < 12) {
                _Z27AdvanceStreamRecord0204724cP11Obj0204724C((Obj0204724C*)&entry->renderRecord);
                RenderTransformedFlaggedIndexedEntry(&entry->renderRecord, 1);
            }
            for (int j = 0; j < 4; j++) {
                CombatRecord* segment = &entry->segments[j];
                RenderConfig::SetObjectPosition(&segment->position);
                Matrix3x3* viewMatrix = (Matrix3x3*)GetPtrField0x144(camera);
                Matrix3x3 rotation;
                Matrix3x3 transformed;
                fix32_t angle = data_020e6e64[j];
                fix32_t cosine = fix32cos(angle);
                fix32_t sine = fix32sin(angle);
                Mat3x3_WriteRotationY(&rotation, sine, cosine);
                Mat3x3_Multiply(viewMatrix, &rotation, &transformed);
                _Z27ClearGlobalFlagBits02016d8cPv(&transformed);
                RenderConfig::SubmitToFifo();
                _Z24SubmitGxCommands02047648Phii((unsigned char*)segment, 0, 1);
            }
        }
    }
}
