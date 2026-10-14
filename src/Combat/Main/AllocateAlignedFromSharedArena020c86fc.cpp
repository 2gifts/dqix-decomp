#include <globaldefs.h>

int GetSharedWordDa0_020c8534(int index);
int GetSharedWordDc4_020c8520(int index);
void SetSharedWordDa0_020c86e8(int index, int value);

// USA: func_020c86fc  (semantic: AllocateAlignedFromSharedArena020c86fc)
extern "C" ARM int func_020c86fc(int handle, int size, int align) {
    int cur = GetSharedWordDa0_020c8534(handle);
    if (cur == 0) return 0;
    int start = (cur + align - 1) & ~(align - 1);
    int sum = start + size;
    int next = (sum + align - 1) & ~(align - 1);
    int limit = GetSharedWordDc4_020c8520(handle);
    if ((unsigned int)next > (unsigned int)limit) return 0;
    SetSharedWordDa0_020c86e8(handle, next);
    return start;
}
