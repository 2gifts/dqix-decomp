#include <globaldefs.h>

#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Resource/GameResources.h"
#include "std_library_functions.h"

struct GameObject;
struct CombatState020e3c34;
extern "C" void _Z12Init020e3c34P19CombatState020e3c34(CombatState020e3c34* p);
GameObject* GetCombatantWithFlag0x100(GameState* gameState, int combatantId);
int GetFieldAt0x150(unsigned char* obj);
int GetField0x3acValue(GameState* gameState);
extern "C" int func_020897b4(int a, int b, int c, int d, int e, int f, int g, int h, int i);
extern "C" int func_ov017_0218f5a4(char* self, int combatantId, int flag2, int flag3, int flag4);
extern char* data_020ee9cc[];
extern char data_020f2cbc;

struct CombatState020e3c34 {
    unsigned char header;
    unsigned char byte1;
    unsigned char pad2[6];
    unsigned char byte8;
    signed char byte9;
    short half_a;
    int word_c;
    int word_10;
    int words_14[2];
    int word_1c;
    int word_20;
    unsigned char byte_24;
};

// USA: func_020e3c94
extern "C" ARM void func_020e3c94(CombatState020e3c34* obj) {
    GameState* gs = GameState::GetInstance();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    GameObject* combatant = GetCombatantWithFlag0x100(gs, obj->byte9);
    unsigned char* base = 0;

    if (combatant) {
        base = (unsigned char*)GetFieldAt0x150((unsigned char*)combatant);
    }

    if (obj->word_1c == 0) {
        if (combatant == 0) {
            _Z12Init020e3c34P19CombatState020e3c34(obj);
            obj->byte1 = 1;
            return;
        }
        char buf[80];
        sprintf(buf, &data_020f2cbc, obj->word_c);
        const char* names[2];
        names[0] = buf;
        names[1] = data_020ee9cc[1];
        for (int i = 0; i < 2; i++) {
            obj->words_14[i] = loader->QueueLoadFile(names[i], 0);
        }
        obj->word_1c = 1;
    }

    if (obj->word_1c != 1) {
        return;
    }

    for (int i = 0; i < 2; i++) {
        if (loader->GetTaskStatus(obj->words_14[i]) == 0) {
            return;
        }
    }

    void* ptr0;
    void* ptr1;
    unsigned int len0;
    unsigned int len1;
    loader->GetLoadedFileByID(obj->words_14[0], &ptr0, &len0);
    loader->GetLoadedFileByID(obj->words_14[1], &ptr1, &len1);

    unsigned short v = 0;
    if (base) {
        if (obj->word_20 & 1) {
            v = *(unsigned short*)(base + 0x564);
        }
    }

    func_020897b4(obj->byte9, obj->half_a, obj->word_c, obj->byte8,
                 obj->byte_24, (int)ptr0, (int)len0, (int)ptr1, (int)len1);

    if (base) {
        if ((obj->word_20 & 1) && (obj->byte9 == GetField0x3acValue(gs))) {
            *(unsigned short*)(base + 0x564) = v;
        }
        if (obj->word_20 & 2) {
            *(int*)((base + obj->word_c * 4) + 0x138) = obj->word_10;
        }
        if (obj->word_20 & 4) {
            func_ov017_0218f5a4((char*)func_ov017_0218b5b0(), obj->byte9, 0, 0, 1);
        }
    }

    for (int i = 0; i < 2; i++) {
        loader->RemoveTask(obj->words_14[i]);
    }

    _Z12Init020e3c34P19CombatState020e3c34(obj);
    obj->byte1 = 1;
}