#include <globaldefs.h>

struct ListNode02160094 {
    char pad0[0x20];
    short id;
};
struct List02160094;
extern "C" ListNode02160094* _Z22GetNodeAtIndex02160094P12List02160094i(List02160094* list, int index);

struct ListNode021600f8 {
    char pad0[0xe];
    short id;
};
struct List021600f8;
extern "C" ListNode021600f8* _Z22GetNodeAtIndex021600f8P12List021600f8i(List021600f8* list, int index);

extern "C" int func_ov000_0215e9fc(void* obj, short* buf, int max, int start);
extern "C" int func_ov000_0215ec1c(void* obj, short* buf, int max, int start);

static inline int IsPartyIndex(int id) {
    return id >= 0 && id <= 3;
}

static inline int IsMonsterIndex(int id) {
    return id >= 0xc0 && id <= 0xc7;
}

// USA: func_ov000_0218177c
extern "C" ARM int func_ov000_0218177c(void* obj, void* list, int useFirstList, int sameSide, int* out) {
    short buf[12];
    int id;
    if (useFirstList) {
        ListNode02160094* node = _Z22GetNodeAtIndex02160094P12List02160094i((List02160094*)list, 0);
        if (node == 0) {
            return 0;
        }
        id = node->id;
    } else {
        ListNode021600f8* node = _Z22GetNodeAtIndex021600f8P12List021600f8i((List021600f8*)list, 0);
        if (node == 0) {
            return 0;
        }
        id = node->id;
    }
    int count = 0;
    if (sameSide) {
        if (IsPartyIndex(id)) {
            count = func_ov000_0215e9fc(obj, buf, 12, 0);
        } else if (IsMonsterIndex(id)) {
            count = func_ov000_0215ec1c(obj, buf, 12, 0);
        }
    } else {
        if (IsPartyIndex(id)) {
            count = func_ov000_0215ec1c(obj, buf, 12, 0);
        } else if (IsMonsterIndex(id)) {
            count = func_ov000_0215e9fc(obj, buf, 12, 0);
        }
    }
    for (int i = 0; i < count; i++) {
        out[i] = buf[i];
    }
    return count;
}
