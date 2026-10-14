#include <globaldefs.h>

typedef void (*EventCallback020be280)(int, int, int, int);
extern "C" int func_020be09c(unsigned int index, EventCallback020be280 callback, void* ctx, unsigned int index2, int b);

void PostRangeEvent0x20_020be4a4(int, int, int, int);
void* GetGlobalContext02110370_020bd444(void);
int GetListEntryWord8020bd8ac(unsigned int index);
void SetListEntryWord8020bd8d4(unsigned int index, int value);

// USA: func_020be280
ARM int PostEvent0x20ForIndex_020be280(unsigned int index, int b, int flag) {
    int result = GetListEntryWord8020bd8ac(index);
    if (result == 0) {
        void* ctx = flag ? GetGlobalContext02110370_020bd444() : 0;
        result = func_020be09c(index, PostRangeEvent0x20_020be4a4, ctx, index, b);
        if (flag && result != 0) {
            SetListEntryWord8020bd8d4(index, result);
        }
    }
    return result;
}
