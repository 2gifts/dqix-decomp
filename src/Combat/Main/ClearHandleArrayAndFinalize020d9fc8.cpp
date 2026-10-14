#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"

void SetByteField0x253_020397c0(void* obj);
void* GetDataPtr02114e04_020d6c00(void);
struct FlagWord020466f4 {
    unsigned int flags;
};
void ClearFlags020466f4(struct FlagWord020466f4* word, unsigned int mask);

struct Struct020d9fc8 {
    char pad[0xc];
    int arr[1];
};

// USA: func_020d9fc8
ARM void ClearHandleArrayAndFinalize020d9fc8(struct Struct020d9fc8* p) {
    int x = (int)BackgroundLoader::GetInstance();
    int i;
    for (i = 0; i < 1; i++) {
        if (p->arr[i] != -1) {
            ((BackgroundLoader*)(x))->RemoveTask((int)(p->arr[i]));
            p->arr[i] = -1;
        }
    }
    SetByteField0x253_020397c0(GameState::GetInstance()->GetUnknownGameObject());
    ClearFlags020466f4((struct FlagWord020466f4*)GetDataPtr02114e04_020d6c00(), 0x1e);
    *((unsigned char*)p + 1) = 1;
}
