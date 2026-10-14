#include <globaldefs.h>

struct CallbackData020ca364 {
    int flag;
    char pad[0xc];
    void (*callback)(void*);
    void* arg;
};
extern struct CallbackData020ca364 data_02111684;

// USA: func_020ca364
ARM void RunAndClearCallback_020ca364(void) {
    void (*cb)(void*);
    void* arg;
    data_02111684.flag = 0;
    cb = data_02111684.callback;
    arg = data_02111684.arg;
    if (cb != NULL) {
        cb(arg);
    }
}
