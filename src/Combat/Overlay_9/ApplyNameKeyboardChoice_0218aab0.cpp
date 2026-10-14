#if defined(jpn)
#include <globaldefs.h>
#include "Resource/CharacterCreationUI.h"
extern "C" void* memcpy(void*, const void*, unsigned int);

int GetGlobalField0x1c020421a0();
int GetFieldByKey020e0434(Container020e0310*, int);
struct Obj0205eaa0;
extern Obj0205eaa0 data_02108760;
void DispatchWithShortB4_0205eaa0(Obj0205eaa0*, int, int);
extern "C" int func_02001aec(const void*, const void*, unsigned int);
extern "C" void func_ov009_0218b200(CharacterCreationUI*, int);
extern "C" void func_ov009_0218b2e8(CharacterCreationUI*);
extern "C" void func_ov009_0218b680(CharacterCreationUI*);
extern "C" void func_ov009_0218b850(CharacterCreationUI*);
extern const char data_ov009_0218bc73[];
extern const char data_ov009_0218bc76[];
extern const char data_ov009_0218bc79[];
extern const char data_ov009_0218bc7c[];
extern const char data_ov009_0218bc7f[];
extern const char data_ov009_0218bc82[];
extern const char data_ov009_0218bc85[];
extern const char data_ov009_0218bc88[];

extern "C" ARM int func_ov009_0218aab0(CharacterCreationUI* self, unsigned char choice)
{
    GetGlobalField0x1c020421a0();
    char character[3] = {};
    int changedIndex = -1;
    int inserted = 0;
    const char* page = (const char*)GetFieldByKey020e0434(&self->texts, (short)(self->keyboardPage + 0x4268));
    memcpy(character, page + choice * 2, 2);
    DispatchWithShortB4_0205eaa0(&data_02108760, 1, 0);
    if (func_02001aec(character, data_ov009_0218bc73, 2) == 0) {
        self->flags |= 0x200000;
    } else if (func_02001aec(character, data_ov009_0218bc76, 2) == 0) {
        func_ov009_0218b200(self, 0);
        changedIndex = self->nameFlags[self->sex];
    } else if (func_02001aec(character, data_ov009_0218bc79, 2) == 0) {
        self->keyboardPage = 0;
        self->flags |= 0x2000;
    } else if (func_02001aec(character, data_ov009_0218bc7c, 2) == 0) {
        self->keyboardPage = 1;
        self->flags |= 0x2000;
    } else if (func_02001aec(character, data_ov009_0218bc7f, 2) == 0) {
        func_ov009_0218b2e8(self);
        changedIndex = self->nameFlags[self->sex] - 1;
    } else if (func_02001aec(character, data_ov009_0218bc82, 2) == 0) {
        func_ov009_0218b680(self);
        changedIndex = self->nameFlags[self->sex] - 1;
    } else if (func_02001aec(character, data_ov009_0218bc85, 2) == 0) {
    } else if (func_02001aec(character, data_ov009_0218bc88, 2) == 0) {
        if (self->mode == 1) {
            func_ov009_0218b850(self);
            self->flags |= 0x8000;
        }
    } else {
        changedIndex = self->nameFlags[self->sex];
        if (changedIndex >= 5) --changedIndex;
        memcpy(&self->names[self->sex][changedIndex * 2], character, 2);
        self->nameFlags[self->sex] = changedIndex + 1;
        inserted = 1;
    }
    if (changedIndex >= 0) self->flags |= 0x8000;
    return inserted;
}
#endif
