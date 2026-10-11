#include <globaldefs.h>

extern "C" void* func_0202ae18(void);
struct SearchStruct0202c1a4;
signed char GetSearchStructCurrentArrEntry(struct SearchStruct0202c1a4* obj);
extern "C" void func_0202c288(void* obj);
extern "C" void* func_0205ec34(void);
int LookupAndForEachNode020649b0(void* a, int mode, void* c);
extern "C" void func_0206f81c(void* p);
struct Obj_021b994c;
void ResetFieldsToDefault_021b994c(struct Obj_021b994c* obj);

struct SearchStruct0202c1a4 {
    char pad[0x100d];
    unsigned char entryLimit;
};

struct Obj_021b994c {
    char pad[0x12c];
    unsigned int field12c;
    unsigned char field130;
    unsigned char field131;
    unsigned char field132;
    unsigned char field133;
    char pad2[0x136 - 0x134];
    unsigned char field136;
};

struct LocalBuf021b9a98 { char pad[0x34]; };

// USA: func_ov017_021b9a98
extern "C" ARM void func_ov017_021b9a98(Obj_021b994c* obj, int unused1, unsigned char matchType, unsigned char unused2, unsigned short flag) {
    SearchStruct0202c1a4* search = (SearchStruct0202c1a4*)func_0202ae18();
    signed char arrEntry = GetSearchStructCurrentArrEntry(search);
    if (matchType != arrEntry && matchType != 4) return;

    if (obj->field130 == 0) return;

    func_0202c288(search);

    int cnt = obj->field131 + 1;
    obj->field131 = (unsigned char)cnt;
    if ((cnt & 0xff) >= search->entryLimit - 1) obj->field130 = 0;

    if (obj->field136 == 0) {
        if (flag == 0) {
            obj->field133 = 0;
            *(short*)((char*)obj + 0x134) = (short)obj->field12c;
            void* list = func_0205ec34();
            LocalBuf021b9a98 c;
            if (LookupAndForEachNode020649b0(list, 0x1a, &c)) {
                func_0206f81c(&c);
            }
            ResetFieldsToDefault_021b994c(obj);
            obj->field136 = 1;
        } else {
            int cnt2 = obj->field132 + 1;
            obj->field132 = (unsigned char)cnt2;
            if ((cnt2 & 0xff) < search->entryLimit - 1) return;

            obj->field133 = 1;
            *(short*)((char*)obj + 0x134) = (short)obj->field12c;
            void* list2 = func_0205ec34();
            LocalBuf021b9a98 c2;
            if (LookupAndForEachNode020649b0(list2, 0x1a, &c2)) {
                func_0206f81c(&c2);
            }
            ResetFieldsToDefault_021b994c(obj);
            obj->field136 = 1;
        }
    }
}
