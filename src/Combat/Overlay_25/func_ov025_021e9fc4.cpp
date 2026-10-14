#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

struct Struct0216fd38;
struct ShortSetStruct0216fdf8;
struct EntryTask0216fd80;
struct List02160094;
struct List021600f8;
struct ListNode0215feb4;
struct ListNode02160094;
struct ListNode0215feb4;
struct ListNode021600f8 {
    ListNode0215feb4* children[3];
    short unknown0c;
    short ids[3];
    unsigned char codes[3];
    unsigned char codeCount;
    unsigned char childCounts[3];
    unsigned char unknown1b[5];
    ListNode021600f8* next;
};
struct Self021ed634;
void* GetActiveCombatWork_ov000_02160130();
void* GetSlotPtr02160f20(void*);
int CheckOrSetFlagA0_0216fd38(Struct0216fd38*);
void AppendUniqueShort0216fdf8(ShortSetStruct0216fdf8*, int);
void BeginListEntryTask_0216fd80(EntryTask0216fd80*, int);
ListNode02160094* GetNodeAtIndex02160094(List02160094*, int);
ListNode021600f8* GetNodeAtIndex021600f8(List021600f8*, int);
ListNode0215feb4* GetNodeAtIndex0215feb4(char*, int, int);
void* GetNodeAtIndex0215fe2c(void*, int);
void* FindNodeAtDepth0215fff4(void*, int, int);
void SetName021ed324(void*, const char*);
extern "C" char* func_020e046c(char*, void*, void*, int);
extern "C" void func_ov025_021ed634(Self021ed634*);

static inline unsigned char* Codes021e9fc4(ListNode021600f8* node) { return node->codes; }

// USA: func_ov025_021e9fc4
// KEEP-NAME: func_ov025_021e9fc4
extern "C" ARM void func_ov025_021e9fc4(char* self) {
    if ((*(unsigned char*)(self + 0x87c)) == 0) {
        BackgroundLoader* loader = BackgroundLoader::GetInstance();
        if ((*(int*)(self + 0x880)) >= 0) {
            if (loader->GetTaskStatus((*(int*)(self + 0x880))) != 0) {
                void* file = 0;
                unsigned int size = 0;
                loader->GetLoadedFileByID((*(int*)(self + 0x880)), &file, &size);
                if (file != 0) {
                    func_020e046c((self + 0x83c), file, (void*)size, (short)(*(int*)(self + 0x884)));
                }
                SetName021ed324((self + 0x5e8), (self + 0x83c));
#if !defined(jpn)
                *(short*)(self + 0x794) = (*(int*)(self + 0x884));
#endif
                loader->RemoveTask((*(int*)(self + 0x880)));
                (*(int*)(self + 0x880)) = -1;
                (*(unsigned char*)(self + 0x87c)) = 1;
            }
        } else (*(unsigned char*)(self + 0x87c)) = 1;
    }
    if (*(unsigned char*)(self + 0x839) != 0) {
        if ((*(unsigned char*)(self + 0x87c)) != 0) func_ov025_021ed634((Self021ed634*)(self + 0x5e8));
    } else if (((int*)(self + 0x10))[(unsigned char)self[0x30]] != 0 &&
               CheckOrSetFlagA0_0216fd38((Struct0216fd38*)(self + 0x798)) != 0) {
        unsigned char* slot = (unsigned char*)GetSlotPtr02160f20(GetActiveCombatWork_ov000_02160130());
        AppendUniqueShort0216fdf8((ShortSetStruct0216fdf8*)(self + 0x798), ((short*)(slot + 0x18))[0]);
        AppendUniqueShort0216fdf8((ShortSetStruct0216fdf8*)(self + 0x798), ((short*)(slot + 0x18))[1]);
        AppendUniqueShort0216fdf8((ShortSetStruct0216fdf8*)(self + 0x798), ((short*)(slot + 0x18))[2]);
        AppendUniqueShort0216fdf8((ShortSetStruct0216fdf8*)(self + 0x798), ((short*)(slot + 0x18))[3]);
        AppendUniqueShort0216fdf8((ShortSetStruct0216fdf8*)(self + 0x798), ((short*)(slot + 0x18))[4]);
        AppendUniqueShort0216fdf8((ShortSetStruct0216fdf8*)(self + 0x798), ((short*)(slot + 0x18))[5]);
        AppendUniqueShort0216fdf8((ShortSetStruct0216fdf8*)(self + 0x798), ((short*)(slot + 0x18))[6]);
        AppendUniqueShort0216fdf8((ShortSetStruct0216fdf8*)(self + 0x798), 0x7e);
        AppendUniqueShort0216fdf8((ShortSetStruct0216fdf8*)(self + 0x798), 0x7f);
        if ((unsigned short)((short*)(slot + 0x18))[0] == 0xfa) AppendUniqueShort0216fdf8((ShortSetStruct0216fdf8*)(self + 0x798), 0x1e0);
        for (int index = 0; index < slot[8]; index++) {
            ListNode02160094* node = GetNodeAtIndex02160094((List02160094*)slot, index);
            if (node == 0) continue;
            for (int group = 0; group < 6; group++) {
                for (int item = 0; item < *((unsigned char*)node + 0x26 + group); item++) {
                    ListNode0215feb4* link = GetNodeAtIndex0215feb4((char*)node, item, (unsigned char)group);
                    if (link == 0) continue;
                    for (int child = 0; child < *((unsigned char*)link + 0x1f); child++) {
                        short* value = (short*)GetNodeAtIndex0215fe2c(link, child);
                        if (value != 0) AppendUniqueShort0216fdf8((ShortSetStruct0216fdf8*)(self + 0x798), *value);
                    }
                }
            }
        }
        for (int index = 0; index < slot[9]; index++) {
            ListNode021600f8* node = GetNodeAtIndex021600f8((List021600f8*)slot, index);
            if (node == 0) continue;
            unsigned char* codes;
            for (int code = 1; code < node->codeCount; code++) {
                codes = Codes021e9fc4(node);
                int type = codes[code];
                if (type == 3) AppendUniqueShort0216fdf8((ShortSetStruct0216fdf8*)(self + 0x798), 0x1b8);
                else if (type == 1) {
                    int value = 0xaa;
                    int id = node->ids[code - 1];
                    int valid = 0;
                    if (id >= 0) valid = id <= 3;
                    if (valid) value = 0xa9;
                    AppendUniqueShort0216fdf8((ShortSetStruct0216fdf8*)(self + 0x798), (short)value);
                } else if (!(type != 8 && type != 7 && type != 6)) AppendUniqueShort0216fdf8((ShortSetStruct0216fdf8*)(self + 0x798), 0x7e);
                else if (!(type != 4 && type != 5)) AppendUniqueShort0216fdf8((ShortSetStruct0216fdf8*)(self + 0x798), 0x142);
                else if (type == 10) AppendUniqueShort0216fdf8((ShortSetStruct0216fdf8*)(self + 0x798), 0x143);
                else if (type == 2) {
                    int value = 0x29;
                    int id = node->ids[code - 1];
                    int valid = 0;
                    if (id >= 0) valid = id <= 3;
                    if (valid) value = 0x28;
                    AppendUniqueShort0216fdf8((ShortSetStruct0216fdf8*)(self + 0x798), (short)value);
                }
            }
            for (int group = 0; group < 3; group++) {
                for (int item = 0; item < node->childCounts[group]; item++) {
                    ListNode0215feb4* link = (ListNode0215feb4*)FindNodeAtDepth0215fff4(node, item, (unsigned char)group);
                    if (link == 0) continue;
                    for (int child = 0; child < *((unsigned char*)link + 0x1f); child++) {
                        short* value = (short*)GetNodeAtIndex0215fe2c(link, child);
                        if (value != 0) AppendUniqueShort0216fdf8((ShortSetStruct0216fdf8*)(self + 0x798), *value);
                    }
                }
            }
        }
        BeginListEntryTask_0216fd80((EntryTask0216fd80*)(self + 0x798), ((int*)(self + 0x10))[(unsigned char)self[0x30]]);
    }
}
