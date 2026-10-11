#include <globaldefs.h>
#include "Grotto/Main/ActiveGrottoClass.h"

extern "C" char* func_ov017_0218b5b0(void);
extern "C" void* func_ov017_021b8478(void* table);
extern "C" void* func_02012fe4(void);
extern "C" void func_ov017_021d6134(void* obj, int flag);

struct ListHead02046b38;
struct ListNode02046b38;
int ListContainsNode(struct ListHead02046b38* list, struct ListNode02046b38* target);
bool IsInRange0201b588(int id);
int LoadBattleBlock020ac4c0(void* dst);

struct BlockWord021eaf50 {
    unsigned int fieldA : 7;
    unsigned int fieldB : 7;
};

// JPN: func_ov023_021eaeb4
// USA: func_ov023_021eaf50  (semantic: ApplyBattleBlockFieldBIfEligible_021eaf50)
extern "C" ARM int func_ov023_021eaf50(void* obj) {
#if defined(jpn)
 enum {regionalOffset0=0x4ec, regionalOffset1=0x508, regionalOffset2=0x240c};
#else
 enum {regionalOffset0=0x6fc, regionalOffset1=0x718, regionalOffset2=0x23ec};
#endif
    int result = 0;

    char* base = func_ov017_0218b5b0() + 0x3000;
    struct ListHead02046b38* list = *(struct ListHead02046b38**)(base + regionalOffset0);
    struct ListNode02046b38* node = *(struct ListNode02046b38**)(base + regionalOffset1);
    void* headerObj = func_ov017_021b8478(node);

    if (ListContainsNode(list, node) != 0) {
        void* zone = func_02012fe4();
        ActiveGrottoClass* grotto = (ActiveGrottoClass*)((char*)zone + regionalOffset2);
        DetailedTreasureMapData* detail = grotto->GetDetailedData();

        if (*((unsigned char*)headerObj + 0x25) != 0) {
            if (IsInRange0201b588(*(unsigned short*)zone) != 0 && detail != NULL) {
                if (*((unsigned char*)detail + 1) == 2) {
                    char buf[0xb0];
                    LoadBattleBlock020ac4c0(buf);
                    result = ((struct BlockWord021eaf50*)(buf + 0xc))->fieldB;
                }
            }
        }
    }

    func_ov017_021d6134(obj, result);
    return 1;
}
