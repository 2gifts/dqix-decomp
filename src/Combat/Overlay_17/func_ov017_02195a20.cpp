#include <globaldefs.h>
#include "Graphics/LightingManager.h"
#include "Graphics/NSBXX/GeometryFifo.h"
#include "Graphics/NSBXX/RenderConfig.h"
#include "System/Graphics.h"

struct FlagWord02046708;
struct HeadNode02046b24;

unsigned long long GetCurrentTimestamp(void);
FlagWord02046708* GetDataPtr02114e04_020d6c00();
int TestFlags02046708(struct FlagWord02046708* word, unsigned int mask);
extern "C" void* func_0202ae18(void);
void ResetGxEngineState020c52e8();
extern "C" void func_020c5414();
unsigned int GetBitsInField4_0203b4fc(unsigned int* obj, unsigned int mask);
extern "C" void func_ov017_02195ecc(unsigned char* obj, int mode);
void MaybeUpdateOrDispatchEntry_021959ec(void* obj);
void SetActiveDmaChannel020c3a0c(int ch);
extern "C" void func_ov017_02195bbc(unsigned char* obj);
int GetHeadNodeIdOrMinusOne(struct HeadNode02046b24** obj);
extern "C" int func_0202c508(void* obj);
extern "C" int func_0202c540(void* obj);
void DispatchByFlag020d9834(int flag);
extern "C" void func_ov017_021960b8(unsigned char* obj);

// USA: func_ov017_02195a20
extern "C" ARM void func_ov017_02195a20(unsigned char* obj) {
#if defined(jpn)
 enum {regionalFlag=0x41da,regionalList=0x34ec};
#else
 enum {regionalFlag=0x448a,regionalList=0x36fc};
#endif
    GetCurrentTimestamp();
    FlagWord02046708* flags = GetDataPtr02114e04_020d6c00();
    void* search = func_0202ae18();
    ResetGxEngineState020c52e8();
    func_020c5414();
    RenderConfig::Reset();
    DISP3DCNT = (DISP3DCNT & ~0x3000) | 8;
    DISP3DCNT = (DISP3DCNT & ~0x3000) | 0x10;
    if (GetBitsInField4_0203b4fc((unsigned int*)obj, 0x2000)) {
        DISP3DCNT &= 0xcfdf;
    } else {
        DISP3DCNT = (DISP3DCNT & ~0x3000) | 0x20;
    }
    if (obj[regionalFlag] == 0) {
        func_ov017_02195ecc(obj, 1);
    }
    MaybeUpdateOrDispatchEntry_021959ec(obj);
    RenderConfig::SubmitToFifo();
    SendQueuedDataToGeometryFifo();
    LightingManager::GetInstance()->SubmitToRenderConfig();

    int useDma = TestFlags02046708(flags, 0x800000);
    if (useDma) {
        SetActiveDmaChannel020c3a0c(-1);
    }
    func_ov017_02195bbc(obj);
    if (useDma) {
        SetActiveDmaChannel020c3a0c(0);
    }
    if (GetHeadNodeIdOrMinusOne(*(HeadNode02046b24***)(obj + regionalList)) == 0x16) {
        func_ov017_02195ecc(obj, 2);
    }
    if (useDma) {
        while (1) {
            int line = VCOUNT;
            if (func_0202c508(search) && line < 0xd2) break;
            if (func_0202c540(search) && (line < 0xbe || line > 0xf0)) break;
            DispatchByFlag020d9834(0);
        }
    }
    func_ov017_021960b8(obj);
    if (obj[regionalFlag] != 0) {
        func_ov017_02195ecc(obj, 1);
    }
}
