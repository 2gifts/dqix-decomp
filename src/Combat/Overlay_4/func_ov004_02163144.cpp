#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"



struct List0202fec8;

struct ActiveEntry02046900;
int CountActiveEntries(struct ActiveEntry02046900* entry);

struct Rec020467f0;
void* FindRecordByIndex(struct Rec020467f0* rec, int index, void** out, int* out44);

struct List0204af64;
void ResetList0204af64(struct List0204af64* obj);

void DispatchByTag0204b2e0(void* obj, char* str);

struct SelfTag0204b3a0;
void DispatchByTagLookup0204b3a0(struct SelfTag0204b3a0* self, char* str);


struct LocalListStruct02163144 {
    unsigned char pad0[0x1c];
    unsigned char lo : 4;
    unsigned char hi : 4;
    unsigned char pad1d[3];
};

#if defined(jpn)
struct Struct021707e8_02163144 { char pad0[0x10]; int handle; char pad14[0xc]; int state; };
#else
struct Struct021707e8_02163144 { char pad0[0x20]; int handle; int state; };
#endif
extern Struct021707e8_02163144 data_ov004_021707e8;
extern char data_ov004_02170542;

// USA: func_ov004_02163144
// JPN: func_ov004_021637e0
extern "C" ARM int func_ov004_02163144() {
    int ret = 1;
    int data4 = (int)BackgroundLoader::GetInstance();

    if (data_ov004_021707e8.state == 0) {
        *(int*)0x4001010 = 0;
        *(int*)0x4001014 = 0;
        data_ov004_021707e8.handle = ((BackgroundLoader*)(data4))->QueueLoadFile((const char*)((int)&data_ov004_02170542), (SafeAllocator*)(0));
        data_ov004_021707e8.state = data_ov004_021707e8.state + 1;
    } else if (data_ov004_021707e8.state == 1) {
        if (((BackgroundLoader*)(data4))->GetTaskStatus((int)(data_ov004_021707e8.handle))) {
            int recListHead;
            int val2Ignored;
            int dummyOut44;
            void* dummyPtr;
            LocalListStruct02163144 s;

            ((BackgroundLoader*)((struct List0202fec8*)data4))->GetLoadedFileByID((int)(data_ov004_021707e8.handle), (void**)(&recListHead), (unsigned int*)(&val2Ignored));
            int count = CountActiveEntries((struct ActiveEntry02046900*)recListHead);
            ResetList0204af64((struct List0204af64*)&s);
            s.lo = 1;
            s.hi = 1;
            for (int i = 0; i < count; i++) {
                void* rec = FindRecordByIndex((struct Rec020467f0*)recListHead, i, &dummyPtr, &dummyOut44);
                if (rec) {
                    DispatchByTag0204b2e0(&s, (char*)rec);
                    DispatchByTagLookup0204b3a0((struct SelfTag0204b3a0*)&s, (char*)rec);
                }
            }
            ((BackgroundLoader*)(data4))->RemoveTask((int)(data_ov004_021707e8.handle));
            data_ov004_021707e8.handle = -1;
            ret = 0;
        }
    }
    return ret;
}
