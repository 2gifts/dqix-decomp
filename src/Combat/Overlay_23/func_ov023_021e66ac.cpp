#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"

int GetField5cb0Value(char* game);
extern "C" void* func_0202ae18(void);

struct TableA68 { struct EntryA68* entries; short count; };
void* FindEntryByKey(TableA68* table, int key);

struct ProfileTextFields {
    unsigned int unknown0 : 29;
    unsigned int accoladeChosen : 1;
    unsigned int vocationAccolade : 1;
    unsigned int showBirthday : 1;
    unsigned int unknown4 : 9;
    signed int title : 10;
    unsigned int unknown4High : 13;
};

struct SavedProfileTextView {
#if defined(jpn)
    unsigned char unknown0[0x543c];
#else
    unsigned char unknown0[0x569c];
#endif
    ProfileTextFields profile;
};

struct ProfileTextEditor {
#if defined(jpn)
    unsigned char unknown0[0x1314];
    TableA68 strings;
    unsigned char unknownAfterStrings[0x1458 - 0x131c];
#else
    unsigned char unknown0[0x133c];
    TableA68 strings;
    unsigned char unknownAfterStrings[0x1400 - 0x1344];
#endif
    char accoladeText[0x40];
    char titleText[0x40];
};

struct ProfilePartyMember {
    unsigned char unknown0[0x49c];
    unsigned char female : 1;
#if defined(jpn)
    unsigned char unknown49d[0x8b8 - 0x49d];
#else
    unsigned char unknown49d[0x950 - 0x49d];
#endif
    int vocation;
};

struct ProfileProtagonist {
#if defined(jpn)
    unsigned char unknown0[0x144];
#else
    unsigned char unknown0[0x150];
#endif
    ProfilePartyMember* partyData;
};

// JPN: func_ov023_021e6c24
// USA: func_ov023_021e66ac  (semantic: BuildOrCopyKeyStringField_021e66ac)
extern "C" ARM void func_ov023_021e66ac(void* editor) {
    ProfileTextEditor* self = (ProfileTextEditor*)editor;
    GameState* game = GameState::GetInstance();
    ProfileTextFields* profile = &((SavedProfileTextView*)game)->profile;

    if (!profile->accoladeChosen) {
        memset(self->accoladeText, 0, sizeof(self->accoladeText));
        void* entry = FindEntryByKey(&self->strings, 0x6d);
        memcpy(self->accoladeText, entry, 7);
    } else if (profile->vocationAccolade) {
        func_0202ae18();
        ProfileProtagonist* protagonist = (ProfileProtagonist*)game->GetProtagonist();
        int vocation = protagonist->partyData->vocation;
        if (GetField5cb0Value((char*)game) == 1) {
            vocation = 13;
        }
        int base = 0x50dc;
#if !defined(jpn)
        if (protagonist->partyData->female == 1) {
            base += 0x32;
        }
#endif
        short key = (short)(base + vocation);
        char* entry = (char*)FindEntryByKey(&self->strings, key);
        memset(self->accoladeText, 0, sizeof(self->accoladeText));
        unsigned int length = strlen(entry);
        memcpy(self->accoladeText, entry, length);
    }

    if (profile->title != 300) {
        return;
    }

    memset(self->titleText, 0, sizeof(self->titleText));
    char* entry = (char*)FindEntryByKey(&self->strings, 0x6d);
    unsigned int length = strlen(entry);
    memcpy(self->titleText, entry, length);
}
