#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#if defined(jpn)
#define func_ov009_02184bbc func_ov009_02185ee8
#endif
#include "GameState/GameState.h"
#include "GameState/Field3b0.h"
#include "Graphics/NSBXX/GeometryFifo.h"
#include "Graphics/NSBXX/RenderConfig.h"
#include "System/Graphics.h"

struct Trans0218bb30
{
    char pad0[0x40];
    void* f40;
};

void ResetGxEngineState020c52e8();
extern "C" void func_020c5414();
extern "C" void func_0202e0a4(void* camera);
extern "C" void func_ov009_02184c30(void* obj);
extern "C" void func_ov009_02184bbc(void* obj);
extern "C" void* func_0203bd08();
void CleanInvalidateOamBuffers0203bd88(void* oam);
void WriteControlAndToggle020d86d0(int a, int b);

// USA: func_ov021_0218bb30  (semantic: Trans_0218bb30)
extern "C" ARM void func_ov021_0218bb30(Trans0218bb30* self)
{
    GameState* gameState = GameState::GetInstance();
    void* camera = GetField0x3b0Value_020100bc(gameState);
    ResetGxEngineState020c52e8();
    func_020c5414();
    DISP3DCNT = (DISP3DCNT & ~0x3000) | 8;
    DISP3DCNT = (DISP3DCNT & ~0x3000) | 0x10;
    DISP3DCNT = (DISP3DCNT & ~0x3000) | 0x20;
    if (camera != NULL)
        func_0202e0a4(camera);
    RenderConfig::SubmitToFifo();
    SendQueuedDataToGeometryFifo();
    func_ov009_02184c30(self->f40);
    func_ov009_02184bbc(self->f40);
    CleanInvalidateOamBuffers0203bd88(func_0203bd08());
    WriteControlAndToggle020d86d0(1, 0);
}
