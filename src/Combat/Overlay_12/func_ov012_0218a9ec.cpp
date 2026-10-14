#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
enum { kCursorOffset = 0x144c, kStringsOffset = 0x1314, kSeparatorOffset = 0x1348, kProfileOffset = 0x543c };
#else
enum { kCursorOffset = 0x13f4, kStringsOffset = 0x133c, kSeparatorOffset = 0x1378, kProfileOffset = 0x569c };
#endif

struct EntryA68 {
    short key;
    void* value;
};

struct TableA68 {
    struct EntryA68* entries;
    short count;
};

struct ProfileHeader {
    unsigned int year : 12;
    unsigned int month : 4;
    unsigned int day : 5;
    unsigned int design : 4;
    unsigned int female : 1;
    unsigned int initialized : 1;
    unsigned int designChosen : 1;
    unsigned int birthdayChosen : 1;
    unsigned int accoladeChosen : 1;
    unsigned int vocationAccolade : 1;
    unsigned int showBirthday : 1;
};

int AppendFrameTag02041c08(char* dst, int a1, int a2, int a3, int a4, int a5);
int AppendCursorTag_02041ea4(char* dst, int cursor);
void* FindEntryByKey_02072a68(struct TableA68* table, int key);
int AppendNameTag_02041b70(char* dst, int n, const char* name);
int AppendString02042058(char* dst, const char* src);

// USA: func_ov012_0218a9ec
extern "C" ARM void func_ov012_0218a9ec(unsigned char* self, char* dst, int c) {
    if (dst == 0) return;

    int cursor = *(int*)(self + kCursorOffset) & 7;
    ProfileHeader* profile =
        (ProfileHeader*)((char*)GameState::GetInstance() + kProfileOffset);

    if (c != 0) {
        AppendFrameTag02041c08(dst, cursor, 8, 5, 5, 5);
    }
    AppendCursorTag_02041ea4(dst, cursor);

    int i;
    for (i = 0; i < 8; i++) {
        if (i != 0) {
            AppendString02042058(dst, *(char**)(self + kSeparatorOffset));
        }
        void* name = FindEntryByKey_02072a68((struct TableA68*)(self + kStringsOffset),
                                    (short)(((short)profile->female) + i * 2 + 0x7530));
        AppendNameTag_02041b70(dst, i, (const char*)name);
    }
}
