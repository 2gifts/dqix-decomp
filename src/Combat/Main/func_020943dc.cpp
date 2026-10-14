#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "std_library_functions.h"

struct NameBuf02046574 { char text[0x40]; };
struct Obj02046574 {
    char pad0[0x4ac];
    NameBuf02046574 names[16];
};
struct MessageLoadState {
    char name[0x30];
    short messageId;
    char pad32[0x340 - 0x32];
    int taskId;
    int position;
    char text[0x80];
    unsigned char phase : 7;
    unsigned char reserved : 1;
    char pad3c9;
    unsigned char counter;
    char pad3cb[2];
    unsigned char flags;
};
Obj02046574* GetGlobalField0x1c020421a0();
void SetIndexedName02046574(Obj02046574*, int, char*);
extern "C" void func_020e046c(char*, void*, unsigned int, int);
extern "C" void func_02046608(Obj02046574*, int, char*, char*, int, int, int);
extern const char data_020f13aa[];
extern const char data_020f13c5[];

// USA: func_020943dc
extern "C" ARM int func_020943dc(MessageLoadState* state) {
    if (!(state->flags & 1)) return 0;
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    if (state->phase == 0) {
        if (state->taskId >= 0) {
            loader->RemoveTask(state->taskId);
            state->taskId = -1;
        }
        state->taskId = loader->QueueLoadFileInGP2(data_020f13aa, data_020f13c5, 0);
        ++state->phase;
    } else if (state->phase == 1) {
        if (loader->GetTaskStatus(state->taskId)) {
            void* file;
            unsigned int size;
            loader->GetLoadedFileByID(state->taskId, &file, &size);
            if (file) {
                char message[0x40] = {};
                func_020e046c(message, file, size, state->messageId);
                Obj02046574* formatter = GetGlobalField0x1c020421a0();
                char* previousName = formatter->names[0].text;
                char savedName[0x40] = {};
                if (previousName) memcpy(savedName, previousName, strlen(previousName));
                SetIndexedName02046574(formatter, 0, state->name);
                memset(state->text, 0, sizeof(state->text));
                func_02046608(formatter, 10, message, state->text, 0x100, 0, 0);
                state->text[0x7f] = 0;
                state->position = 0;
                if (previousName) SetIndexedName02046574(formatter, 0, savedName);
            }
            loader->RemoveTask(state->taskId);
            state->taskId = -1;
            state->flags &= ~1;
            state->phase = 0;
            state->counter = 0;
        }
    }
    return 1;
}
