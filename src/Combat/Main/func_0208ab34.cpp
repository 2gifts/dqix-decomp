#include <globaldefs.h>
#include "GameState/GameState.h"

struct Container020e34bc;
struct Entry020e3054;
struct PartyRoster {
    char pad0[0xf78];
    unsigned char ids[4];
    unsigned char count;
};
class TimedPartyEntries {
public:
    virtual int Test(int, void*);
    virtual void Activate(int);
    char pad4[2];
    unsigned char threshold;
    unsigned char timers[17];
    unsigned char counters[17];
};
extern "C" int* func_0202ae18();
Container020e34bc* GetData02153637();
extern "C" int _Z28GetEntryStatusForKey020e34bcP17Container020e34bci(Container020e34bc*, int);
int CheckField0NonZero(int*);
void StoreInFirstEmptySlot(unsigned char*, unsigned char);
extern "C" void _Z37ClearEntryIfCurrentArrMatches020e3468P13Entry020e3054i(Entry020e3054*, int);
extern "C" void _Z31InitFieldsIfHandleValid0208ad1cPv(void*);
extern "C" void _Z16Dispatch020e3428Pvi(void*, int);
extern unsigned char data_020e8cc6[];
extern unsigned char data_020e8cc5[];

// USA: func_0208ab34
extern "C" ARM void func_0208ab34(TimedPartyEntries* entries, void* context) {
    PartyRoster* roster = (PartyRoster*)GetPtrField0x2a04(GameState::GetInstance());
    int* session = func_0202ae18();
    int activated = 0;
    int dispatched = 0;
    Container020e34bc* requests = GetData02153637();
    for (int i = 0; i < roster->count; ++i) {
        int status = _Z28GetEntryStatusForKey020e34bcP17Container020e34bci(requests, 1);
        int id = roster->ids[i];
        if ((!CheckField0NonZero(session) ||
             (CheckField0NonZero(session) && status != 1)) &&
            !entries->Test(id, context)) {
            for (int j = 0; j < 3; ++j) {
                if (entries->counters[id] == data_020e8cc5[j * 2])
                    entries->timers[id] += data_020e8cc6[j * 2];
            }
            entries->counters[id] = 0;
        } else {
            if (entries->threshold <= entries->timers[id]) {
                if (status != 2 && status != 1)
                    StoreInFirstEmptySlot((unsigned char*)requests, 1);
                if (status == 1) {
                    entries->timers[id] = 0;
                    dispatched = 1;
                    if (entries->Test(id, context)) {
                        activated = 1;
                        entries->Activate(id);
                    }
                } else if ((unsigned int)(status - 3) <= 2) {
                    _Z37ClearEntryIfCurrentArrMatches020e3468P13Entry020e3054i((Entry020e3054*)requests, 1);
                }
            } else {
                ++entries->timers[id];
                if (entries->counters[id] < 0xff) ++entries->counters[id];
            }
        }
    }
    if (activated) _Z31InitFieldsIfHandleValid0208ad1cPv(entries);
    if (dispatched) _Z16Dispatch020e3428Pvi(requests, 1);
}
