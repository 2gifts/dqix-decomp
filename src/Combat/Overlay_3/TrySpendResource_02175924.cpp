#include <globaldefs.h>
#if defined(jpn)
enum { kRegion103a = 0xfb6 };
enum { kRegion104f = 0xfcb };
enum { kRegion874 = 0x7f0 };
enum { kRegion103c = 0xfb8 };
#else
enum { kRegion103a = 0x103a };
enum { kRegion104f = 0x104f };
enum { kRegion874 = 0x874 };
enum { kRegion103c = 0x103c };
#endif

#include "GameState/GameState.h"

void* GetPtrField0x2a04(GameState* battleStruct);
struct Container020dedd0;
struct Element020de650;
struct Element020de650* FindElementByKey020dedd0(struct Container020dedd0* c, int key);
unsigned int ComputeRatio_02175898(char* obj, void* s);
extern "C" void func_ov003_02176798(void* obj);

// JPN: func_ov003_02174968
// USA: func_ov003_02175924
ARM int TrySpendResource_02175924(char* obj) {
    void* ptrField = GetPtrField0x2a04(GameState::GetInstance());
    short key = *(short*)(obj + kRegion103a);
    struct Element020de650* elem = FindElementByKey020dedd0((struct Container020dedd0*)(obj + kRegion874), key);
    if (elem == 0) {
        return 0;
    }
    unsigned int ratio = ComputeRatio_02175898(obj, elem);
    unsigned int cost = *(unsigned char*)(obj + kRegion103c) * ratio;
    unsigned int available = *(unsigned int*)((char*)ptrField + 0xf6c);
    if (available < cost) {
        return 0;
    }
    available = available - cost;
    *(unsigned int*)((char*)ptrField + 0xf6c) = available;
    func_ov003_02176798(obj);
    *(unsigned char*)(obj + kRegion104f) = 1;
    return 1;
}
