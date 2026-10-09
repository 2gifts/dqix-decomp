#include <globaldefs.h>
#include "Graphics/LightingManager.h"
#include "Graphics/NSBXX/GeometryFifo.h"
#include "Graphics/NSBXX/RenderConfig.h"
#include "System/Graphics.h"

struct FlagWord02046708;
struct HeadNode02046b24;

unsigned long long GetCurrentTimestamp(void);
extern "C" FlagWord02046708* _Z27GetDataPtr02114e04_020d6c00v();
extern "C" int _Z17TestFlags02046708P16FlagWord02046708j(struct FlagWord02046708* word, unsigned int mask);
extern "C" void* func_0202ae18(void);
extern "C" void _Z26ResetGxEngineState020c52e8v();
extern "C" void func_020c5414();
unsigned int GetBitsInField4(unsigned int* obj, unsigned int mask);
extern "C" void func_ov017_02195ecc(unsigned char* obj, int mode);
extern "C" void _Z35MaybeUpdateOrDispatchEntry_021959ecv(unsigned char* obj);
extern "C" void _Z27SetActiveDmaChannel020c3a0ci(int ch);
extern "C" void func_ov017_02195bbc(unsigned char* obj);
int GetHeadNodeIdOrMinusOne(struct HeadNode02046b24** obj);
extern "C" int func_0202c508(void* obj);
extern "C" int func_0202c540(void* obj);
extern "C" void _Z22DispatchByFlag020d9834i(int flag);
extern "C" void func_ov017_021960b8(unsigned char* obj);

// USA: func_ov017_02195a20
extern "C" ARM void func_ov017_02195a20(unsigned char* obj) {
    GetCurrentTimestamp();
    FlagWord02046708* flags = _Z27GetDataPtr02114e04_020d6c00v();
    void* search = func_0202ae18();
    _Z26ResetGxEngineState020c52e8v();
    func_020c5414();
    RenderConfig::Reset();
    DISP3DCNT = (DISP3DCNT & ~0x3000) | 8;
    DISP3DCNT = (DISP3DCNT & ~0x3000) | 0x10;
    if (GetBitsInField4((unsigned int*)obj, 0x2000)) {
        DISP3DCNT &= 0xcfdf;
    } else {
        DISP3DCNT = (DISP3DCNT & ~0x3000) | 0x20;
    }
    if (obj[0x448a] == 0) {
        func_ov017_02195ecc(obj, 1);
    }
    _Z35MaybeUpdateOrDispatchEntry_021959ecv(obj);
    RenderConfig::SubmitToFifo();
    SendQueuedDataToGeometryFifo();
    LightingManager::GetInstance()->SubmitToRenderConfig();

    int useDma = _Z17TestFlags02046708P16FlagWord02046708j(flags, 0x800000);
    if (useDma) {
        _Z27SetActiveDmaChannel020c3a0ci(-1);
    }
    func_ov017_02195bbc(obj);
    if (useDma) {
        _Z27SetActiveDmaChannel020c3a0ci(0);
    }
    if (GetHeadNodeIdOrMinusOne(*(HeadNode02046b24***)(obj + 0x36fc)) == 0x16) {
        func_ov017_02195ecc(obj, 2);
    }
    if (useDma) {
        while (1) {
            int line = VCOUNT;
            if (func_0202c508(search) && line < 0xd2) break;
            if (func_0202c540(search) && (line < 0xbe || line > 0xf0)) break;
            _Z22DispatchByFlag020d9834i(0);
        }
    }
    func_ov017_021960b8(obj);
    if (obj[0x448a] != 0) {
        func_ov017_02195ecc(obj, 1);
    }
}
