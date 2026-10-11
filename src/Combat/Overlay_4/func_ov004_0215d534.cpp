#include <globaldefs.h>
#include "GameState/GameState.h"

struct Stat0215d534 { char pad[0x5c]; short cur; short max; };
struct Entry0215d534 { short id; short pad2; unsigned int limit : 7; };
struct Battle021707d8 { char pad[0x11]; unsigned char count; };
struct Data021707d8 { char pad[8]; Battle021707d8* battle; };
extern Data021707d8 data_ov004_021707d8;

struct SearchStruct;
extern "C" int _Z28DispatchNodeIfType7_02156e2cPvi(void* obj, int key);
extern "C" SearchStruct* func_0202ae18(void);
int CheckField0NonZero(int* obj);
extern "C" int func_ov004_0215c0c0(void* obj);
extern "C" Stat0215d534* func_ov004_02156ed0(void* obj, int key);
extern "C" void* _Z20GetEntryFor_021570a4Pvi(void* obj, int index);
extern "C" int func_0202c508(SearchStruct* obj);
extern "C" void _Z27EnqueueEventTag184_021d3bbciiii(int a, int b, int c, int d);
extern "C" void func_ov011_021848a0(void* obj, int val);
int TestFlagBitAt0xe(SearchStruct* obj, int value);
extern "C" void func_ov011_02184a40(void* obj, int val);

// USA: func_ov004_0215d534
extern "C" ARM int func_ov004_0215d534(void* obj) {
#if defined(jpn)
 enum { stateOffset = 0xc };
#else
 enum { stateOffset = 0x26c };
#endif
    int key = _Z28DispatchNodeIfType7_02156e2cPvi(obj, 0x5b);
    if (key < 0) return 0;

    SearchStruct* search = func_0202ae18();
    if (!CheckField0NonZero((int*)search)) {
        func_ov004_0215c0c0(obj);
    } else {
        int slot = func_ov004_02156ed0(obj, 0x5b)->cur * 6 + key;
        Entry0215d534* entry = (Entry0215d534*)_Z20GetEntryFor_021570a4Pvi(obj, (unsigned char)key);

        if (func_0202c508(search)) {
            if (entry->limit >= data_ov004_021707d8.battle->count) {
                func_ov004_0215c0c0(obj);
                _Z27EnqueueEventTag184_021d3bbciiii(slot, data_ov004_021707d8.battle->count, 1, 0);
            } else {
                func_ov011_021848a0(obj, 0x2367);
            }
        } else if (!TestFlagBitAt0xe(search, 0)) {
            char* p = (char*)GameState::GetInstance() + stateOffset;
            *(unsigned short*)(p + 0x5d00 + 0xc) &= ~0xe000;
            _Z27EnqueueEventTag184_021d3bbciiii(slot, data_ov004_021707d8.battle->count, 3, 0);
            func_ov011_02184a40(obj, 0x5c);
        } else {
            func_ov011_021848a0(obj, 0x2369);
        }
    }
    return 0;
}
