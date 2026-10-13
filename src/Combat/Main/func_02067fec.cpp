#include <globaldefs.h>

struct Entry0204254c
{
    char pad_0x0[5];
    signed char offset_ : 6;
    signed char terminal_ : 1;
    signed char unused_ : 1;
};
struct Flags02067fec
{
    unsigned int low_ : 28;
    unsigned int fallback_ : 1;
    unsigned int bit29_ : 1;
    unsigned int active_ : 1;
    unsigned int bit31_ : 1;
};
struct State02067fec
{
    char pad_0x0[8];
    Flags02067fec flags_;
};
Entry0204254c* FindEntryByKey0204254c(int, int);
extern "C" int func_02067f9c(State02067fec*, int, int);

// USA: func_02067fec
extern "C" ARM int func_02067fec(State02067fec* state, signed char* address, int table)
{
    if (state && !state->flags_.active_)
        return state->flags_.fallback_;
    signed char* key = address;
    Entry0204254c* entry = FindEntryByKey0204254c((int)key, table);
    if (entry)
    {
        if (entry->terminal_)
            return 1;
        int type = *key;
        key += entry->offset_;
        if (type == 'h')
        {
            entry = FindEntryByKey0204254c((int)key, table);
            if (entry && entry->terminal_)
                return !func_02067f9c(state, (int)(key + entry->offset_), table);
        }
        else if (type == 'y')
            return !func_02067f9c(state, (int)key, table);
    }
    return 0;
}
