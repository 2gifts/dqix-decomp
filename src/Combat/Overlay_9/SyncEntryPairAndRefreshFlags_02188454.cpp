#include <globaldefs.h>
#include "World/Object3D.h"

#if defined(jpn)
#define func_ov009_02188454 func_ov009_02189214
#endif

struct CharacterModel {
    char unknown0[0xc12];
    unsigned char loading;
};

struct PartyMemberAppearance {
    short models[10];
    unsigned char unknown14[4];
    short width;
    short height;
};

struct PartyMemberData {
    char unknown0[0x488];
    PartyMemberAppearance appearance;
};

struct CharacterCreation {
#if defined(jpn)
    char unknown0[0x7bc];
#else
    char unknown0[0x7f8];
#endif
    CharacterModel* character;
    CharacterModel* nextCharacter;
    char unknown800[0xd88 - 0x800];
    PartyMemberData* member;
    char unknownD8c[0xd9c - 0xd8c];
    unsigned int flags;
    signed char lastStates[2];
    unsigned char vocation;
    unsigned char sex;
    unsigned char bodyTypes[2];
};

extern "C" void _Z22InitWordsQuad_021e60e0Pvj(CharacterModel* character, unsigned int angle);
extern "C" Vector3i func_ov023_021e613c(CharacterModel* character);
extern "C" void _Z26SetFourWordBlocks_021e6088PvP13Words021e60c4(CharacterModel* character, const Vector3i* rotation);
extern "C" Object3D* func_ov023_021e6194(CharacterModel* character);
extern "C" void _Z20GetEntryPair02188bf8PhiPsS0_(CharacterCreation* editor, int bodyType, short* width, short* height);
extern "C" void func_ov023_021e5e68(CharacterModel* character, int width, int height);
int StringLength(const char* s);

// USA: func_ov009_02188454
extern "C" ARM void func_ov009_02188454(CharacterCreation* editor) {
    if (editor->flags & 4) {
        CharacterModel* next = editor->nextCharacter;
        if (next != NULL && next->loading != 0)
            return;

        if (editor->flags & 0x40000) {
            _Z22InitWordsQuad_021e60e0Pvj(editor->character, 0x1eb);
            editor->flags &= ~0x40000;
        }
        const Vector3i& rotation = func_ov023_021e613c(editor->character);
        _Z26SetFourWordBlocks_021e6088PvP13Words021e60c4(editor->nextCharacter, &rotation);

        Object3D* currentObject = func_ov023_021e6194(editor->character);
        Object3D* nextObject = func_ov023_021e6194(editor->nextCharacter);
        const BCFG::AnimationRecord* nextAnimation = nextObject->activeAnimationRecord_;
        int nextNameLength = 0;
        int currentNameLength = 0;
        const BCFG::AnimationRecord* currentAnimation = currentObject->activeAnimationRecord_;
        if (nextAnimation != NULL)
            nextNameLength = StringLength(nextAnimation->name);
        if (currentAnimation != NULL)
            currentNameLength = StringLength(currentAnimation->name);
        if (nextNameLength == currentNameLength && currentAnimation != NULL) {
            nextObject->MaybeSetRegularAnimation(currentAnimation->name, 0);
            nextObject->SetCurrentAnimationTime(currentObject->animationTime_);
        }

        CharacterModel* previous = editor->character;
        editor->character = editor->nextCharacter;
        editor->nextCharacter = previous;

        if (editor->flags & 0x20000) {
            unsigned char sex = editor->sex;
            PartyMemberAppearance* appearance = &editor->member->appearance;
            unsigned char bodyType = editor->bodyTypes[sex];
            _Z20GetEntryPair02188bf8PhiPsS0_(editor, bodyType, &appearance->width, &appearance->height);
            func_ov023_021e5e68(editor->character, appearance->width, appearance->height);
            func_ov023_021e5e68(editor->nextCharacter, appearance->width, appearance->height);
            editor->flags &= ~0x20000;
        }
        editor->flags &= ~4;
    }
}
