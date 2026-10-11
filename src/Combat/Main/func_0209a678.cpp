#include <globaldefs.h>

int GetFieldAt0x150(unsigned char* member);
int TestBitInArray0x8ec(unsigned char* arr, int bit);
void SetBitInArray0x8ec(unsigned char* arr, int bit);

struct SkillEntry {
    unsigned short id : 11;
    unsigned short pad1 : 5;
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
    unsigned char* field = (unsigned char*)GetFieldAt0x150((unsigned char*)member);
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
            unsigned short id = (*(SkillEntry**)table)[i].id;
            if (TestBitInArray0x8ec(field, id) == 0) {
                SetBitInArray0x8ec(field, id);
                skills[count] = id;
                count++;
            }
        }
        index += 0xb;
    }
    return count;
}