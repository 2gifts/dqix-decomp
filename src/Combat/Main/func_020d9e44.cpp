#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"

#if defined(jpn)
#define data_020f2838 data_020f2a30
#define data_020ee678 data_020ee784
#endif

struct Struct020d9fc8;
void ClearHandleArrayAndFinalize020d9fc8(struct Struct020d9fc8* p);

struct Obj020397cc;
void CancelPendingAction020397cc(struct Obj020397cc* obj, int arg1);

void* GetDataPtr02114e04_020d6c00(void);
void OrBitsIntoField0_020466e4(unsigned int* word, unsigned int mask);

extern const char data_020f2838[];

struct Self020d9e44 {
    unsigned char pad0[8];
    unsigned short flags;
    unsigned char state;
    unsigned char pad1;
    int tasks[1];
};

typedef void (Self020d9e44::*Handler020d9e44)();
struct HandlerTable020d9e44 { Handler020d9e44 e[2]; };
extern HandlerTable020d9e44 data_020ee678;
extern Handler020d9e44 data_020e6d5c;

// USA: func_020d9e44
extern "C" ARM void func_020d9e44(Self020d9e44* self) {
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    if (self->state == 0) {
        if (self->flags == 0) {
            ClearHandleArrayAndFinalize020d9fc8((struct Struct020d9fc8*)self);
            return;
        }
        CancelPendingAction020397cc((struct Obj020397cc*)GameState::GetInstance()->GetUnknownGameObject(), 1);
        OrBitsIntoField0_020466e4((unsigned int*)GetDataPtr02114e04_020d6c00(), 0x1e);
        if (self->flags & 1) {
            self->tasks[0] = loader->QueueLoadFile(data_020f2838, NULL);
        }
        self->state++;
    } else if (self->state == 1) {
        int i;
        int done = 0;
        for (i = 0; i < 1; i++) {
            if (self->tasks[i] == -1) { done++; continue; }
            if (loader->GetTaskStatus(self->tasks[i]) == 0) continue;
            if (loader->GetDetailedTaskStatus(self->tasks[i]) == 2) break;
            loader->RemoveTask(self->tasks[i]);
            self->tasks[i] = -1;
        }
        if (done == 1) { self->state = 0; return; }
        if (i == 1) return;
        HandlerTable020d9e44 table;
        table = data_020ee678;
        table.e[1] = data_020e6d5c;
        (self->*table.e[i])();
    }
}
