#if defined(jpn)
#define R(j,u) (j)
#define data_ov015_02193d14 data_ov015_02194844
#define data_ov015_02193d2c data_ov015_0219485c
#define data_ov015_02193d38 data_ov015_02194868
#define data_ov027_021dd8e0 data_ov027_021de1a0
#define func_ov003_021594c4 func_ov003_0215a990
#define func_ov003_0215a740 func_ov003_0215bbc0
#define func_ov014_0218854c func_ov014_0218942c
#define func_ov014_021885bc func_ov014_0218948c
#define func_ov015_0219050c func_ov015_021910b0
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Graphics/NSBXX/GeometryFifo.h"
#include "Graphics/NSBXX/RenderConfig.h"
#include "Resource/Brightness.h"
#include "System/Graphics.h"
#include "System/Matrix.h"

struct EdgeColors
{
    unsigned short colors_[8];
};

extern "C" void _Z26ResetGxEngineState020c52e8v();
extern "C" void func_020c5414();
int CallWithAddr4000330(int a);
void* GetField0x3b0Value(GameState* state);
extern "C" void func_0202e0a4(void* camera);
void SubmitGeometryJob(int a, int b, int c, int d, void* e);
extern "C" void _Z28ComputeAndLoadMatrix020c5770iiiiiiiiPv(int a, int b, int c, int d, int e, int f, int g, int h, void* i);
extern "C" void _Z29WriteControlAndToggle020d86d0ii(int a, int b);
extern "C" void func_ov015_02190348(void* self);
extern "C" void func_ov015_02190428(void* self);
extern "C" void func_ov015_0219050c(void* self);

extern const EdgeColors data_ov015_02193d38;
extern const Vector3fix data_ov015_02193d14;
extern const Vector3fix data_ov015_02193d2c;

// USA: func_ov015_021901c8
extern "C" ARM void func_ov015_021901c8(void* self)
{
    GameState* gameState = GameState::GetInstance();
    if (gameState == NULL)
        return;
    _Z26ResetGxEngineState020c52e8v();
    func_020c5414();
    RenderConfig::Reset();
    DISP3DCNT = (DISP3DCNT & ~0x3000) | 8;
    DISP3DCNT = (DISP3DCNT & ~0x3000) | 0x10;
    DISP3DCNT = (DISP3DCNT & ~0x3000) | 0x20;
    {
        EdgeColors colors = data_ov015_02193d38;
        CallWithAddr4000330((int)colors.colors_);
    }
    void* camera = GetField0x3b0Value(gameState);
    if (camera != NULL)
        func_0202e0a4(camera);
    RenderConfig::SubmitToFifo();
    SendQueuedDataToGeometryFifo();
    func_ov015_02190348(self);
    _Z26ResetGxEngineState020c52e8v();
    func_020c5414();
    GXFIFO_MATRIX_MODE = 0;
    {
        Vector3fix target = data_ov015_02193d14;
        Vector3fix eye = {0};
        Vector3fix up = data_ov015_02193d2c;
        SubmitGeometryJob((int)&eye, (int)&up, (int)&target, 1, NULL);
    }
    _Z28ComputeAndLoadMatrix020c5770iiiiiiiiPv(0, 0xc0000, 0, 0x100000, -0x400000, 0x400000, 0x400000, 1, NULL);
    GXFIFO_MATRIX_MODE = 2;
    func_ov015_02190428(self);
    func_ov015_0219050c(self);
    _Z29WriteControlAndToggle020d86d0ii(1, 0);
    UpdateAndApplyBrightness((GameResources*)self);
}
