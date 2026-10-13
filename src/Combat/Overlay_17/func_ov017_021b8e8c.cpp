#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Memory/AllocatorUnion.h"
#include "Resource/GameResources.h"

struct Obj020397cc;
struct Obj0205eaa0;
struct Obj020d7aa0;
struct Vec3_020406f8;
struct Node020406f8;
struct Obj02033834;
struct Owner02040a90;
struct Struct0203cedc;
struct Entry0209854c;
struct TailList020469b4;
struct TailNode020469b4;
struct ListHead02046b60;
struct Obj0208b8c4;

struct Vec3_021b8e8c {
    int x;
    int y;
    int z;
};

struct Rec021b8e8c {
    unsigned short id;
    unsigned char pad2;
    unsigned char kind;
};

struct Entry021b8e8c {
    unsigned int flags;
    char pad4[0x10];
    Struct0203cedc* combat;
};

struct Query021b8e8c {
    int id;
    char pad4[0x10];
    int value;
    char pad18[0x1c];
};

struct Self021b8e8c {
    unsigned char kind;
    unsigned char done;
    char pad2[6];
    SafeAllocator allocA;
    SafeAllocator allocB;
    unsigned char timer[0xe4];
    Rec021b8e8c* rec;
    unsigned char* sub;
    int state;
    int task;
    int f124;
    unsigned char hasSub;
    unsigned char subStep;
    char pad12a[2];
    int lastId;
    unsigned char busy;
    char pad131[6];
    unsigned char finished;
    unsigned char changed;
    unsigned char quiet;
};

extern "C" int func_ov017_021959b4(void);
extern "C" void func_ov017_021b8d80(Self021b8e8c* self);
extern "C" unsigned short* func_02012fe4(void);
extern "C" char* _Z26GetGlobalField0x1c020421a0v(void);
void* GetGlobalPtr021075f4(void);
extern "C" void* func_0205ec34(void);
int GetFieldIfFlag4(char* obj);
extern "C" void _Z24ReinitController02043204Pc(char* obj);
extern "C" void func_02043124(char* obj);
void SetField0x23cTrue(void* obj);
void ClearBitsInWord(unsigned int* obj, unsigned int mask);
extern "C" void _Z27CancelPendingAction020397ccP11Obj020397cci(Obj020397cc* obj, int arg1);
extern "C" void _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(struct Obj0205eaa0* obj, int a, int b);
extern "C" void* _Z29FindEntryPointerByKey0203df78Pvi(void* base, int key);
void SetByteField0x253(void* obj);
extern "C" Obj020d7aa0* _Z25GetGlobalResetObj020d7a50v(void);
extern "C" void _Z29TeardownAndResetState020d7aa0P11Obj020d7aa0(struct Obj020d7aa0* obj);
extern "C" int _Z19IsIdInRange020981e4ii(int a, int id);
int IsInRange1To63(int a, int x);
extern "C" Vec3_021b8e8c _Z29SelectVec3FromSources020406f8P13Vec3_020406f8P12Node020406f8(struct Node020406f8* n);
extern "C" void _Z21SetVecYByMode02033834P11Obj02033834i(struct Obj02033834* obj, int arg);
extern "C" int _Z22FindEntryByKey0203dfdcPvi(void* base, int key);
int GetFieldFromActiveChild(struct Owner02040a90* obj);
int GetField0x8(int* obj);
void SetCombatFlags0x5c(struct Struct0203cedc* obj, int b, int c);
int GetField5cb0Value(char* obj);
int GetField5cb4Value(char* obj);
extern "C" Entry0209854c* _Z25FindEntryByFieldC0209854cP13Entry0209854ci(struct Entry0209854c* list, int target);
extern "C" void func_ov017_021a967c(TailNode020469b4* node, int id);
void AppendNodeToTail(TailList020469b4* list, TailNode020469b4* node);
extern "C" int _Z28GetTableEntryOrZero_0218d2c4i(int id);
void ClearIntAt0x23c(unsigned char* obj);
extern "C" void func_ov008_02184754(void* obj);
extern "C" int _Z17GetNibble0206ec1ciiPhj(int a, int b, unsigned char* c, unsigned int d);
extern "C" void _Z23IncrementNibble0206ec64iiPhj(int a, int b, unsigned char* c, unsigned int d);
extern "C" int func_ov017_021ba810(const void* code, unsigned int length, int id, int a3, int a4, int a5, int a6);
extern "C" int _Z20AppendString02042058PcPKc(char* dst, const char* src);
extern "C" unsigned char* _Z15GetData02108d18v(void);
extern "C" void _Z12Init0206f510Pc(char* obj);
extern "C" int func_0206f550(unsigned char* s, char* in, char* out);
extern "C" int _Z23CommandDispatch0206f6ccPhi(unsigned char* obj, int arg);
int ListContainsId(ListHead02046b60* list, int id);
extern "C" void func_020a0cc4(unsigned int size);
void* AllocateAligned4(AllocatorUnion* alloc, unsigned int size);
extern "C" void _Z32InitAllocatorsAndBuffers0208b8c4P11Obj0208b8c4P13SafeAllocator(struct Obj0208b8c4* obj, SafeAllocator* allocator);
extern "C" void func_0204500c(void* obj, char* buffer, int a, int b);
extern "C" void func_0208bb78(void* timer, unsigned int ticks);
extern "C" int _Z28LookupAndForEachNode020649b0PviS_(void* a, int mode, void* c);
extern "C" void func_0206f81c(void* p);
extern "C" void _Z30SetByteB10AndClearB11_02184a3cPch(char* obj, unsigned char value);
void SetFlag0x2IfByte0xd4Not3(unsigned char* obj);
extern "C" void _Z25SetFields120_138_021bd38cPvii(void* obj, int a, int b);

extern "C" void __clear(void* buf, int n);

extern char data_02108760;
extern char data_ov017_021d7c90;
extern char data_ov017_021d7c95;
extern char data_ov017_021d7cad;
extern AllocatorUnion data_02114e20;

// USA: func_ov017_021b8e8c
extern "C" ARM void func_ov017_021b8e8c(Self021b8e8c* self, ListHead02046b60* list) {
    if (self->rec == NULL) {
        self->done = 1;
        return;
    }

    GameState* gs = GameState::GetInstance();
    GameResources* res = func_ov017_0218b5b0();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    unsigned short* area = func_02012fe4();
    char* msg = _Z26GetGlobalField0x1c020421a0v();
    void* table = GetGlobalPtr021075f4();
    GameObject* leader = gs->GetUnknownGameObject();
    void* events = func_0205ec34();
    void* hud;
    unsigned short areaId = *area;
    hud = (void*)GetFieldIfFlag4((char*)gs);
    unsigned char* nibbles = (unsigned char*)res->unknown_ptr_44c4;

    if (func_ov017_021959b4() != 0) {
        func_ov017_021b8d80(self);
        _Z24ReinitController02043204Pc(msg);
        func_02043124(msg);
        SetField0x23cTrue(hud);
        ClearBitsInWord((unsigned int*)res, 0x2000);
        self->done = 1;
        return;
    }

    _Z27CancelPendingAction020397ccP11Obj020397cci((Obj020397cc*)leader, 1);

    switch (self->state) {
    case 0: {
        if (self->quiet == 0) {
            _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii((Obj0205eaa0*)&data_02108760, 1, 0);
        }
        *(short*)((char*)leader + 0xb2) = 0;
        Vec3_021b8e8c from = *(Vec3_021b8e8c*)((char*)leader + 0x44);
        Entry021b8e8c* entry = (Entry021b8e8c*)_Z29FindEntryPointerByKey0203df78Pvi(table, self->rec->id);
        if (entry == NULL) {
            SetByteField0x253(leader);
            if (hud != NULL) {
                SetField0x23cTrue(hud);
            }
            self->done = 1;
            break;
        }
        _Z29TeardownAndResetState020d7aa0P11Obj020d7aa0(_Z25GetGlobalResetObj020d7a50v());
        self->lastId = self->rec->id;
        if (_Z19IsIdInRange020981e4ii((int)((char*)area + 0x840), areaId) &&
            IsInRange1To63((int)((char*)area + 0x840), self->rec->id)) {
            self->hasSub = 1;
        }
        Vec3_021b8e8c to = _Z29SelectVec3FromSources020406f8P13Vec3_020406f8P12Node020406f8((Node020406f8*)entry);
        _Z21SetVecYByMode02033834P11Obj02033834i((Obj02033834*)leader, fix32ReduceAngle0To2Pi(fix32_Atan2(to.x - from.x, to.z - from.z)));
        *(int*)(msg + 0x1838) = _Z22FindEntryByKey0203dfdcPvi(table, self->rec->id);
        *(int*)(msg + 0x183c) = GetFieldFromActiveChild((Owner02040a90*)entry);
        char* info = (char*)GetField0x8((int*)entry);
        if (info != NULL && strstr(info + 4, &data_ov017_021d7c90) != NULL && !(entry->flags & 0x4000) &&
            entry->combat != NULL) {
            SetCombatFlags0x5c(entry->combat, 1, 0);
        }
        int tableId = GetField5cb0Value((char*)gs);
        char prefix[0xc];
        strcpy(prefix, *(char**)((char*)area + 8) + 5);
        prefix[3] = 0;
        _Z27CancelPendingAction020397ccP11Obj020397cci((Obj020397cc*)leader, 1);
        if (self->hasSub != 0) {
            TailList020469b4* tail;
            TailNode020469b4* node = (TailNode020469b4*)res->unknown_ptr_array_3afc[0x22];
            tail = (TailList020469b4*)res->unknown_ptr_array_36fc[0];
            Entry0209854c* found = _Z25FindEntryByFieldC0209854cP13Entry0209854ci((Entry0209854c*)((char*)area + 0x840), *(unsigned short*)info);
            func_ov017_021a967c(node, -1);
            *(Entry0209854c**)((char*)node + 0x54) = found;
            AppendNodeToTail(tail, node);
            self->done = 1;
            break;
        }
        char path[0x50];
        sprintf(path, &data_ov017_021d7c95, prefix, _Z28GetTableEntryOrZero_0218d2c4i(tableId));
        if (hud != NULL) {
            ClearIntAt0x23c((unsigned char*)hud);
        }
        char name[0x10];
        __clear(name, sizeof(name));
        sprintf(name, &data_ov017_021d7cad, *(unsigned short*)info);
        self->task = loader->QueueLoadFileInGP2(path, name, NULL);
        self->state = 1;
        break;
    }
    case 1: {
        if (self->hasSub != 0) {
            func_ov008_02184754(self->sub);
        }
        if (loader->GetTaskStatus(self->task) == 0) {
            break;
        }
        if (loader->GetDetailedTaskStatus(self->task) != 2) {
            loader->RemoveTask(self->task);
            self->task = -1;
            SetByteField0x253(leader);
            if (hud != NULL) {
                SetField0x23cTrue(hud);
            }
            self->done = 1;
            _Z24ReinitController02043204Pc(msg);
            func_02043124(msg);
            break;
        }
        void* data;
        unsigned int length;
        loader->GetLoadedFileByID(self->task, &data, &length);
        int arg = GetField5cb4Value((char*)gs);
        unsigned short id = self->rec->id;
        int lo = _Z17GetNibble0206ec1ciiPhj((int)nibbles, id, nibbles, 0x80);
        int hi = _Z17GetNibble0206ec1ciiPhj((int)nibbles, id, nibbles + 0x80, 0x80);
        char* text = (char*)func_ov017_021ba810(data, length, id, arg, self->f124, lo, hi);
        if (text == NULL) {
            loader->RemoveTask(self->task);
            self->task = -1;
            SetByteField0x253(leader);
            if (hud != NULL) {
                SetField0x23cTrue(hud);
            }
            self->done = 1;
            _Z24ReinitController02043204Pc(msg);
            func_02043124(msg);
            break;
        }
        _Z23IncrementNibble0206ec64iiPhj((int)nibbles, id, nibbles, 0x80);
        _Z23IncrementNibble0206ec64iiPhj((int)nibbles, id, nibbles + 0x80, 0x80);
        *(int*)(msg + 0x99c) = self->rec->kind;
        char* out = *(char**)(msg + 0x5c);
        char* in = *(char**)(msg + 0x60);
        memset(out, 0, 0x960);
        memset(in, 0, 0x960);
        if (strlen(text) >= 0x960) {
            text[0x95f] = 0;
        }
        _Z20AppendString02042058PcPKc(in, text);
        loader->RemoveTask(self->task);
        self->task = -1;
        unsigned char* script = _Z15GetData02108d18v();
        _Z12Init0206f510Pc((char*)script);
        if (func_0206f550(script, in, out) != 0 && _Z23CommandDispatch0206f6ccPhi(script, 0) == 0) {
            self->state = 8;
            BlankFunction02094b34(GetGlobal02109400(), 0x6f, 0x1388, 1, 1);
            break;
        }
        self->state = 3;
        break;
    }
    case 8:
        if (AlwaysTrue02094b4c(GetGlobal02109400()) != 0) {
            if (hud != NULL) {
                SetField0x23cTrue(hud);
            }
            if (ListContainsId(list, 0x2b) != 0 && hud != NULL) {
                ClearIntAt0x23c((unsigned char*)hud);
            }
            self->state = -1;
            self->done = 1;
        }
        break;
    case 3: {
        if (self->hasSub != 0) {
            func_ov008_02184754(self->sub);
        }
        FontBankLoader* fade = GetGlobal02109400();
        if (self->hasSub != 0) {
            BlankFunction02094b40(fade);
            BlankFunction02094b34(fade, 0x6e, 0x1ff, 0, 0);
        } else {
            BlankFunction02094b34(fade, 0x6f, 0x1388, 1, 1);
        }
        self->state = 4;
        break;
    }
    case 4:
        if (self->hasSub != 0) {
            func_ov008_02184754(self->sub);
        }
        if (AlwaysTrue02094b4c(GetGlobal02109400()) != 0) {
            self->state = 2;
        }
        break;
    case 2: {
        func_020a0cc4(0xa000);
        self->allocA.CreateTypeA(AllocateAligned4(&data_02114e20, 0xa000), 0xa000);
        _Z32InitAllocatorsAndBuffers0208b8c4P11Obj0208b8c4P13SafeAllocator((Obj0208b8c4*)self->timer, &self->allocA);
        char* buffer = *(char**)(msg + 0x5c);
        int scroll = 1;
        switch (areaId) {
        case 1:
            if (self->rec->id == 0xc8) {
                scroll = 0;
            }
            break;
        case 0xc3b5:
        case 0xc419:
        case 0xc47d:
        case 0xc4e1: {
            unsigned short id = self->rec->id;
            if (id == 0xd0 || id == 0x63 || id == 0xd3) {
                scroll = 0;
            }
            break;
        }
        }
        func_0204500c(msg, buffer, scroll, 0xe3);
        *(int*)(msg + 0x998) = 1;
        *(unsigned char*)(msg + 0x19b2) = 1;
        *(void**)(msg + 0x8c) = self->timer;
        *(int*)(msg + 0x99c) = self->rec->kind;
        self->state = 5;
        func_0208bb78(self->timer, gs->GetTickCount());
        if (ListContainsId((ListHead02046b60*)res->unknown_ptr_array_36fc[0], 0x17) == 0) {
            break;
        }
        if (hud != NULL) {
            SetField0x23cTrue(hud);
        }
        self->done = 1;
        func_ov017_021b8d80(self);
        if (_Z29FindEntryPointerByKey0203df78Pvi(table, self->rec->id) == NULL) {
            break;
        }
        Query021b8e8c query;
        query.id = self->rec->id;
        query.value = self->f124;
        if (_Z28LookupAndForEachNode020649b0PviS_(events, 1, &query) != 0) {
            func_0206f81c(&query);
        }
        break;
    }
    case 5: {
        if (self->busy != 0) {
            break;
        }
        func_0208bb78(self->timer, gs->GetTickCount());
        if (self->hasSub != 0) {
            func_ov008_02184754(self->sub);
        }
        if (*(int*)(msg + 0x9a0) == 3) {
            _Z24ReinitController02043204Pc(msg);
            func_02043124(msg);
        }
        if (*(int*)(msg + 0x998) != 0) {
            break;
        }
        if (self->hasSub != 0) {
            if (self->subStep == 0) {
                _Z30SetByteB10AndClearB11_02184a3cPch((char*)self->sub, 0xd);
                self->subStep++;
                break;
            }
            if (self->sub[0xb10] != 0xe) {
                break;
            }
            self->subStep = 0;
        }
        Entry021b8e8c* entry = (Entry021b8e8c*)_Z29FindEntryPointerByKey0203df78Pvi(table, self->rec->id);
        if (entry == NULL) {
            break;
        }
        char* info = (char*)GetField0x8((int*)entry);
        if (info != NULL && strstr(info + 4, &data_ov017_021d7c90) != NULL && !(entry->flags & 0x4000) &&
            entry->combat != NULL) {
            SetCombatFlags0x5c(entry->combat, 1, 1);
        }
        self->state = 6;
        break;
    }
    case 6: {
        if (*(short*)(self->timer + 0xd2) < 0) {
            SetByteField0x253(leader);
            if (hud != NULL) {
                SetField0x23cTrue(hud);
            }
            self->done = 1;
            func_ov017_021b8d80(self);
        } else {
            self->state = 7;
        }
        int was;
        unsigned char* party = (unsigned char*)res->unknown_ptr_array_36fc[14];
        was = 0;
        if (party[2] != 0) {
            was = 1;
        }
        Query021b8e8c query;
        query.id = self->rec->id;
        query.value = self->f124;
        if (_Z28LookupAndForEachNode020649b0PviS_(events, 1, &query) != 0) {
            func_0206f81c(&query);
        }
        if (was == 0 && party[2] != 0) {
            self->changed = 1;
        }
        break;
    }
    case 7:
        func_0208bb78(self->timer, gs->GetTickCount());
        if (*(short*)(self->timer + 0xd2) >= 0) {
            if (self->changed == 0) {
                SetFlag0x2IfByte0xd4Not3(self->timer);
                break;
            }
            _Z25SetFields120_138_021bd38cPvii(res->unknown_ptr_array_36fc[14], (int)self->timer, (int)&self->allocA);
            self->finished = 1;
        }
        SetByteField0x253(leader);
        if (hud != NULL) {
            SetField0x23cTrue(hud);
        }
        self->done = 1;
        func_ov017_021b8d80(self);
        break;
    }
}
