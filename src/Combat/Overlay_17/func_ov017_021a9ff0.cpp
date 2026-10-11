#include <globaldefs.h>
#include "GameState/GameState.h"
#include "System/OverlayId.h"

struct S021b2ba0;
struct TailList020469b4;
struct TailNode020469b4;
struct HeadList020469f8;
struct HeadNode020469f8;
struct SafeAllocator;
struct GameResources;
struct SetFlagStruct;

int GetWord0x0(int* obj);
extern "C" void _Z21InitObjState_021b2174Ph(unsigned char* obj);
extern "C" void _Z23SetNameChecked_021b2ba0P9S021b2ba0Pc(S021b2ba0* obj, char* name);
extern "C" void _Z25SetFields30And34_021b2bd0Pvii(void* obj, int handler, int overlayId);
void PrependNodeToHead(HeadList020469f8* list, HeadNode020469f8* node);
void AppendNodeToTail(TailList020469b4* list, TailNode020469b4* node);
void SetBrightness(GameResources* resources, int brightness, int frames);
void SetFlag0x9c6(SetFlagStruct* obj, int value);
extern "C" void _Z35CopyGlobalBlockAndDispatch_02165df4P13SafeAllocatorPv(SafeAllocator* allocator, void* arg);
extern char data_ov017_021d7831;

// JPN: func_ov017_021aa860
// USA: func_ov017_021a9ff0
extern "C" ARM void func_ov017_021a9ff0(int atFront) {
#if defined(jpn)
 enum {regionalOffset0=0x392c, regionalOffset1=0x34ec};
#else
 enum {regionalOffset0=0x3b4c, regionalOffset1=0x36fc};
#endif
    GameResources* res = (GameResources*)GetWord0x0((int*)GameState::GetInstance());
    SetFlagStruct* flags;
    void* list;
    unsigned char* obj;
    obj = *(unsigned char**)((char*)res + regionalOffset0);
#if defined(jpn)
    flags = *(SetFlagStruct**)((char*)res + 0x34c0);
#else
    flags = *(SetFlagStruct**)((char*)res + 0x36d0);
#endif
    list = *(void**)((char*)res + regionalOffset1);
    _Z21InitObjState_021b2174Ph(obj);
    _Z23SetNameChecked_021b2ba0P9S021b2ba0Pc((S021b2ba0*)obj, &data_ov017_021d7831);
    _Z25SetFields30And34_021b2bd0Pvii(obj, (int)_Z35CopyGlobalBlockAndDispatch_02165df4P13SafeAllocatorPv, OVERLAY_ID(4));
    if (atFront) {
        PrependNodeToHead((HeadList020469f8*)list, (HeadNode020469f8*)obj);
    } else {
        AppendNodeToTail((TailList020469b4*)list, (TailNode020469b4*)obj);
    }
    SetBrightness(res, -16, 0x19);
    SetFlag0x9c6(flags, 1);
}
