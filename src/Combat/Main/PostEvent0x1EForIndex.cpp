#include <globaldefs.h>

typedef void (*EventCallback020be13c)(int, int, int, int);
extern "C" int func_020be09c(unsigned int index, EventCallback020be13c callback, void* ctx, unsigned int index2, int b);

void PrepareAndPostEvent1E020be44c(int, int, int, int);
void* GetGlobalContext02110370_020bd444(void);
int GetListEntryWord8020bd8ac(unsigned int index);
void SetListEntryWord8020bd8d4(unsigned int index, int value);

// USA: func_020be13c
ARM int PostEvent0x1EForIndex_020be13c(unsigned int index, int b, int flag) {
    int result = GetListEntryWord8020bd8ac(index);
    if (result == 0) {
        void* ctx = flag ? GetGlobalContext02110370_020bd444() : 0;
        result = func_020be09c(index, PrepareAndPostEvent1E020be44c, ctx, index, b);
        if (flag && result != 0) {
            SetListEntryWord8020bd8d4(index, result);
        }
    }
    return result;
}
