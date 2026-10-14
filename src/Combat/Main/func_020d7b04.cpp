#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#include "std_library_functions.h"
#include "GameState/GameState.h"

struct FontBankLoader;
void* GetGlobalField0x1c020421a0();
struct ListHead02046b60;
int ListContainsId(ListHead02046b60*, int);
extern "C" void func_ov016_0218b5c0(int, int);
extern "C" void func_ov017_0218b5f8(int);
extern "C" void func_02046380(void*);
#if defined(jpn)
extern "C" void func_0204500c(void*, void*, int);
#else
extern "C" void func_0204500c(void*, void*, int, int);
#endif
void InitFields02042b3c(void*);
void ReinitController02043204(char*);
extern char data_020f2348[];

struct QueuedTextEntry {
#if defined(jpn)
    char text[0x4f];
    unsigned char style : 7;
#else
    char text[0x6f];
    unsigned char style : 6;
    unsigned char compactWindow : 1;
#endif
    unsigned char waitForRequestC : 1;
};

struct TextMessageQueue {
    QueuedTextEntry entries[3];
    unsigned char count : 6;
    unsigned char windowActive : 1;
    unsigned char fontRequested : 1;
    unsigned char unknown151;
    unsigned short remainingMilliseconds;
};

struct MessageWindowState {
#if defined(jpn)
    char unknown0[0x868];
#else
    char unknown0[0x998];
#endif
    int active;
#if defined(jpn)
    char unknownAfterActive[0x17e2 - 0x86c];
#else
    char unknownAfterActive[0x19b2 - 0x99c];
#endif
    unsigned char state;
#if defined(jpn)
    char unknownAfterState[0x17ff - 0x17e3];
    unsigned char unknownLow : 2;
    unsigned char blocked : 1;
    unsigned char unknownHigh : 5;
#else
    char unknownAfterState[0x19d0 - 0x19b3];
    unsigned char blocked;
#endif
};

extern "C" ARM void func_020d7b04(TextMessageQueue* queue) {
    char formattedText[0xc8];
    GameState* game = GameState::GetInstance();
    FontBankLoader* fonts = GetGlobal02109400_02094a00();
    MessageWindowState* window = static_cast<MessageWindowState*>(GetGlobalField0x1c020421a0());
    if (queue->fontRequested && !AlwaysTrue02094b4c(fonts)) return;

    void* requests = func_ov017_0218b5b0()->unknown_ptr_array_36fc[0];
    if (ListContainsId((ListHead02046b60*)requests, 0x25)) return;
    if (ListContainsId((ListHead02046b60*)requests, 0x26)) return;

    unsigned short elapsed = game->GetEffectiveDeltaTime();
    if (queue->remainingMilliseconds != 0) {
        if (elapsed < queue->remainingMilliseconds) {
            queue->remainingMilliseconds -= elapsed;
            return;
        }
        if (window->blocked) return;
        queue->remainingMilliseconds = 0;
        if (queue->count == 0) return;
        memcpy(&queue->entries[0], &queue->entries[1], sizeof(QueuedTextEntry));
        memcpy(&queue->entries[1], &queue->entries[2], sizeof(QueuedTextEntry));
        queue->count--;
        if (queue->count == 0) {
            func_ov016_0218b5c0(1, -1);
            func_ov017_0218b5f8(-1);
        }
        return;
    }

    if (window->blocked) return;
    if (queue->count != 0) {
        if (queue->entries[0].style != 0) {
            int canLoadFont = 1;
            if (queue->entries[0].waitForRequestC) {
                canLoadFont = !ListContainsId((ListHead02046b60*)requests, 0xc);
            }
            if (canLoadFont) {
                BlankFunction02094b3c(fonts, 10);
                BlankFunction02094b30(fonts, 505, 0);
                queue->entries[0].style = 0;
                queue->fontRequested = 1;
                return;
            }
        }
        sprintf(formattedText, data_020f2348, queue->entries[0].text);
        if (queue->count > 1) {
            queue->remainingMilliseconds = 1000;
        } else {
            queue->remainingMilliseconds = 3000;
        }
        if (queue->entries[0].text[0] != 0) {
#if defined(jpn)
            func_0204500c(window, formattedText, 0);
#else
            func_02046380(window);
            if (queue->entries[0].compactWindow) {
                func_0204500c(window, formattedText, 0, 0xe3);
            } else {
                func_0204500c(window, formattedText, 0, 0x100);
            }
#endif
            InitFields02042b3c(window);
            window->active = 1;
            window->state = 1;
            queue->windowActive = 1;
            return;
        }
        queue->windowActive = 0;
        queue->remainingMilliseconds = 0;
        queue->count = 0;
        return;
    } else {
        if (queue->fontRequested) {
            func_02094ab0(fonts);
            queue->fontRequested = 0;
        }
        if (queue->windowActive) {
            ReinitController02043204(static_cast<char*>(GetGlobalField0x1c020421a0()));
            queue->windowActive = 0;
        }
    }
    queue->remainingMilliseconds = 0;
    queue->count = 0;
}
