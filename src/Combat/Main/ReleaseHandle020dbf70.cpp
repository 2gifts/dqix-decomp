#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"


struct Obj020dbf70 {
    char pad[0xc];
    int word_c;
    int word_10;
};

static inline void RemoveLoaderTask(int& taskId) {
    BackgroundLoader::GetInstance()->RemoveTask(taskId);
    taskId = -1;
}

// USA: func_020dbf70
ARM void ReleaseHandle020dbf70(struct Obj020dbf70* o) {
    if (o->word_c < 0) return;
    RemoveLoaderTask(o->word_c);
    o->word_10 = 0;
}
