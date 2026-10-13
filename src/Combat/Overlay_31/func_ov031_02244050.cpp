#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "System/Timing.h"
#include "std_library_functions.h"

struct SessionRecord02244050 {
    unsigned char padding_0[0x88];
    char name[0x24];
    int length;
};
union SessionRecordStorage02244050 {
    SessionRecord02244050 entries[12];
    unsigned char bytes[0x840];
};
struct SessionSettings02244050 {
    unsigned int field_0 : 12;
    unsigned int field_12 : 4;
    unsigned int field_16 : 5;
    unsigned int field_21 : 5;
    unsigned int field_26 : 6;
};
struct Struct_02245528 {
    unsigned char padding_0[0x34];
    unsigned char category;
    unsigned char phase;
    unsigned char field_36;
    unsigned char step;
    int count;
    int selected;
    unsigned int present;
    unsigned char flags;
    unsigned char padding_45[3];
    int offset;
    unsigned char padding_4c[4];
    SessionRecord02244050 records[4];
    unsigned char padding_310[0x378 - 0x310];
    SessionSettings02244050 settings;
    unsigned char padding_37c[0xb4];
    unsigned long long last_request;
};
struct SessionGlobals02244050 {
    unsigned char padding_0[0xc];
    int completed;
    int field_10;
    int connected;
    int field_18;
    int released;
    SessionRecordStorage02244050* records;
    int error;
    unsigned char padding_28[0x10];
};
struct SavedSession02244050 {
    unsigned char padding_0[0x104];
    SessionSettings02244050 settings;
};
struct SessionGame02244050 {
    unsigned char padding_0[0x5e6c];
    SavedSession02244050 save;
    SavedSession02244050* GetSave() { return &save; }
};
struct Struct0200fb08;
extern SessionGlobals02244050 data_ov031_02291e04;
extern char data_ov031_0224c938[];
extern char data_ov031_0224c93d[];
extern char data_ov031_022495b4[4][8];
extern char data_ov031_02249582[][3];
extern "C" void func_ov031_022433d0();
extern "C" void _Z19SetField28_02243404v();
extern "C" int func_ov031_02212ab4(void*, const char*, const char*);
extern "C" int _Z25RunIfGlobalUnset_02212c18i(int);
extern "C" void _Z31SetCallbackAndRegister_02212bccPv(void*);
extern "C" int _Z28InitAndProcessArray_02212c3cPvS_i(void*, void*, int);
extern "C" int _Z24NormalizeField5_0200fb08P14Struct0200fb08(Struct0200fb08*);
extern "C" int func_ov031_022123d4();
extern "C" int func_ov031_02212c84(void*, int, int);
extern "C" void func_ov031_022120f8();
extern "C" void _Z32SetField34AndClear35_37_02245528P15Struct_02245528i(Struct_02245528*, int);
extern "C" void func_ov023_021f6158(void*);
extern "C" int func_ov031_02212184();
extern "C" void func_ov031_02245478(Struct_02245528*);

// USA: func_ov031_02244050
extern "C" ARM void func_ov031_02244050(Struct_02245528* session) {
    switch (session->phase) {
    case 0:
        switch (session->step) {
        case 0:
            data_ov031_02291e04.error = 0;
            data_ov031_02291e04.completed = 0;
            if (!func_ov031_02212ab4((void*)func_ov031_022433d0, data_ov031_0224c938, data_ov031_0224c93d)) session->phase = 8;
            else session->step++;
            break;
        case 1:
            if (data_ov031_02291e04.completed) session->step++;
            break;
        case 2:
            if (data_ov031_02291e04.error) session->phase = 8;
            else session->step++;
            break;
        case 3:
            data_ov031_02291e04.error = 0;
            data_ov031_02291e04.completed = 0;
            if (!_Z25RunIfGlobalUnset_02212c18i((int)&session->count)) session->phase = 8;
            else session->step++;
            break;
        case 4:
            if (data_ov031_02291e04.completed) session->step++;
            break;
        case 5:
            if (data_ov031_02291e04.error == 1) { session->phase = 8; break; }
            if (session->count == 0) {
                session->phase = 5;
                data_ov031_02291e04.released = 0;
                _Z31SetCallbackAndRegister_02212bccPv((void*)_Z19SetField28_02243404v);
                break;
            }
            data_ov031_02291e04.records = (SessionRecordStorage02244050*)((SafeAllocator*)session)->Allocate(0x840);
            if (!data_ov031_02291e04.records) { session->phase = 7; break; }
            data_ov031_02291e04.error = 0;
            data_ov031_02291e04.completed = 0;
            if (!_Z28InitAndProcessArray_02212c3cPvS_i(data_ov031_02291e04.records, 0, session->count)) session->phase = 8;
            else session->step++;
            break;
        case 6:
            if (data_ov031_02291e04.completed) session->step++;
            break;
        case 7: {
            if (data_ov031_02291e04.error) { session->phase = 8; break; }
            int language = _Z24NormalizeField5_0200fb08P14Struct0200fb08((Struct0200fb08*)GameState::GetInstance());
            for (int record = 0; record < session->count; record++) {
                int record_offset = record * sizeof(SessionRecord02244050);
                for (int kind = 0; kind < 4; kind++) {
                    SessionRecord02244050* entry = (SessionRecord02244050*)&data_ov031_02291e04.records->bytes[record_offset];
                    if (!strstr(entry->name, data_ov031_022495b4[kind])) continue;
                    if (kind == 0 && !strstr(entry->name + 11, data_ov031_02249582[language])) continue;
                    if (session->present & (1 << kind)) continue;
                    session->present |= 1 << kind;
                    memcpy(&session->records[kind], &data_ov031_02291e04.records->entries[record], 0xb0);
                }
            }
            session->phase = 3;
            session->step++;
            break;
        }
        }
        if (func_ov031_022123d4()) session->phase = 8;
        return;
    case 3:
        if (session->selected >= 3 && session->selected % 3 == 0) {
            unsigned long long now = (GetCurrentTimestamp() << 6) / 0x82ea;
            if (session->last_request + 1000 > now) return;
        }
        while (!(session->present & (1 << session->selected)) && session->selected < 4) session->selected++;
        if (session->selected < 4) {
            data_ov031_02291e04.error = 0;
            data_ov031_02291e04.completed = 0;
            if (!func_ov031_02212c84(&session->records[session->selected], session->offset, session->records[session->selected].length)) {
                session->phase = 8;
                return;
            }
            data_ov031_02291e04.connected = 0;
        } else {
            data_ov031_02291e04.connected = 1;
            data_ov031_02291e04.completed = 1;
        }
        session->phase = 4;
        return;
    case 4:
        if (data_ov031_02291e04.connected && data_ov031_02291e04.completed) {
            if (session->selected < 3) {
                session->offset += session->records[session->selected].length;
                session->selected++;
                session->phase = 3;
                if (session->selected % 3 == 0) session->last_request = (GetCurrentTimestamp() << 6) / 0x82ea;
            } else {
                session->phase = 5;
                data_ov031_02291e04.released = 0;
                _Z31SetCallbackAndRegister_02212bccPv((void*)_Z19SetField28_02243404v);
            }
        } else if (data_ov031_02291e04.error == 1) session->phase = 8;
        return;
    case 5:
        if (data_ov031_02291e04.released != 1) return;
        session->step = 0;
        func_ov031_022120f8();
        session->phase = 6;
        return;
    case 6: {
        _Z32SetField34AndClear35_37_02245528P15Struct_02245528i(session, 0);
        SavedSession02244050* saved = ((SessionGame02244050*)GameState::GetInstance())->GetSave();
        saved->settings.field_0 = session->settings.field_0;
        saved->settings.field_12 = session->settings.field_12;
        saved->settings.field_16 = session->settings.field_16;
        saved->settings.field_21 = session->settings.field_21;
        saved->settings.field_26 = session->settings.field_26;
        func_ov023_021f6158(&saved->settings);
        session->flags |= 1;
        return;
    }
    case 7:
        if (!data_ov031_02291e04.completed) return;
        data_ov031_02291e04.error = 0;
        data_ov031_02291e04.released = 0;
        _Z31SetCallbackAndRegister_02212bccPv((void*)_Z19SetField28_02243404v);
        session->phase = 9;
        if (data_ov031_02291e04.error == 1) session->phase = 8;
        return;
    case 9:
        if (data_ov031_02291e04.released && func_ov031_02212184()) func_ov031_02245478(session);
        return;
    case 8:
        session->phase = 7;
        return;
    }
}
