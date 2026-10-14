#include <globaldefs.h>

int GetFieldAt0x150_02053c6c(unsigned char* member);
int TestBitInArray0x8ec_02083b00(unsigned char* arr, int bit);
void SetBitInArray0x8ec_02083acc(unsigned char* arr, int bit);

struct SkillEntry {
#if defined(jpn)
    unsigned short id : 12;
    unsigned short pad1 : 4;
#else
    unsigned short id : 11;
    unsigned short pad1 : 5;
#endif
    union {
        unsigned int slot : 5;
        unsigned int raw;
    } u;
    unsigned int pad2;
};

struct Field150 {
    unsigned char pad[0x464];
    unsigned char key[0x20];
};

// USA: func_0209a678
extern "C" ARM int func_0209a678(char* table, void* member, unsigned short* skills) {
    unsigned char* field = (unsigned char*)GetFieldAt0x150_02053c6c((unsigned char*)member);
    int index = 0;
    int count = 0;
    int slot;
    int i;
    for (slot = 0; slot < 0x1a; slot++) {
        unsigned char want = ((Field150*)field)->key[(*(SkillEntry**)table)[index].u.slot];
        int j = 0;
        for (;;) {
            unsigned int ord = ((*(SkillEntry**)table)[index + j].u.raw << 20) >> 25;
            if (ord >= want) {
                if (want == ord) {
                    j++;
                }
                break;
            }
            j++;
        }
        int end = index + j;
        for (i = index; i < end; i++) {
#if defined(jpn)
            SkillEntry* entry = &(*(SkillEntry**)table)[i];
            unsigned int raw = entry->u.raw;
            unsigned int prerequisite = (raw << 15) >> 27;
            if (prerequisite != 0 &&
                ((Field150*)field)->key[prerequisite] < ((raw << 8) >> 25)) {
                continue;
            }
            unsigned short id = entry->id;
#else
            unsigned short id = (*(SkillEntry**)table)[i].id;
#endif
            if (TestBitInArray0x8ec_02083b00(field, id) == 0) {
                SetBitInArray0x8ec_02083acc(field, id);
                skills[count] = id;
                count++;
            }
        }
        index += 0xb;
    }
    return count;
}
