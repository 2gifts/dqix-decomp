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
char* GetGlobalField0x1c020421a0(void);
void* GetGlobalPtr021075f4_0203cf4c(void);
extern "C" void* func_0205ec34(void);
int GetFieldIfFlag4_020100f8(char* obj);
void ReinitController02043204(char* obj);
extern "C" void func_02043124(char* obj);
void SetField0x23cTrue_020a27ac(void* obj);
void ClearBitsInWord_0203b4b0(unsigned int* obj, unsigned int mask);
void CancelPendingAction020397cc(Obj020397cc* obj, int arg1);
void DispatchWithShortB4_0205eaa0(struct Obj0205eaa0* obj, int a, int b);
void* FindEntryPointerByKey0203df78(void* base, int key);
void SetByteField0x253_020397c0(void* obj);
Obj020d7aa0* GetGlobalResetObj020d7a50(void);
void TeardownAndResetState020d7aa0(struct Obj020d7aa0* obj);
int IsIdInRange020981e4(int a, int id);
int IsInRange1To63_02098268(int a, int x);
extern "C" Vec3_021b8e8c _Z29SelectVec3FromSources020406f8P13Vec3_020406f8P12Node020406f8(struct Node020406f8* n);
void SetVecYByMode02033834(struct Obj02033834* obj, int arg);
int FindEntryByKey0203dfdc(void* base, int key);
int GetFieldFromActiveChild(struct Owner02040a90* obj);
int GetField0x8_02040528(int* obj);
void SetCombatFlags0x5c(struct Struct0203cedc* obj, int b, int c);
int GetField5cb0Value_0201079c(char* obj);
int GetField5cb4Value_020107d0(char* obj);
Entry0209854c* FindEntryByFieldC0209854c(struct Entry0209854c* list, int target);
extern "C" void func_ov017_021a967c(TailNode020469b4* node, int id);
void AppendNodeToTail(TailList020469b4* list, TailNode020469b4* node);
int GetTableEntryOrZero_0218d2c4(int id);
void ClearIntAt0x23c_020a27b8(unsigned char* obj);
extern "C" void func_ov008_02184754(void* obj);
int GetNibble0206ec1c(int a, int b, unsigned char* c, unsigned int d);
void IncrementNibble0206ec64(int a, int b, unsigned char* c, unsigned int d);
extern "C" int func_ov017_021ba810(const void* code, unsigned int length, int id, int a3, int a4, int a5, int a6);
int AppendString02042058(char* dst, const char* src);
unsigned char* GetData02108d18_0206f504(void);
void Init0206f510(char* obj);
extern "C" int func_0206f550(unsigned char* s, char* in, char* out);
int CommandDispatch0206f6cc(unsigned char* obj, int arg);
int ListContainsId(ListHead02046b60* list, int id);
extern "C" void func_020a0cc4(unsigned int size);
void* AllocateAligned4_02012d88(AllocatorUnion* alloc, unsigned int size);
void InitAllocatorsAndBuffers0208b8c4(struct Obj0208b8c4* obj, SafeAllocator* allocator);
extern "C" void func_0204500c(void* obj, char* buffer, int a, int b);
extern "C" void func_0208bb78(void* timer, unsigned int ticks);
int LookupAndForEachNode020649b0(void* a, int mode, void* c);
extern "C" void func_0206f81c(void* p);
void SetByteB10AndClearB11_02184a3c(char* obj, unsigned char value);
void SetFlag0x2IfByte0xd4Not3_0208beb4(unsigned char* obj);
void SetFields120_138_021bd38c(void* obj, int a, int b);

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
    char* msg = GetGlobalField0x1c020421a0();
    void* table = GetGlobalPtr021075f4_0203cf4c();
    GameObject* leader = gs->GetUnknownGameObject();
    void* events = func_0205ec34();
    void* hud;
    unsigned short areaId = *area;
    hud = (void*)GetFieldIfFlag4_020100f8((char*)gs);
    unsigned char* nibbles = (unsigned char*)res->unknown_ptr_44c4;

    if (func_ov017_021959b4() != 0) {
        func_ov017_021b8d80(self);
        ReinitController02043204(msg);
        func_02043124(msg);
        SetField0x23cTrue_020a27ac(hud);
        ClearBitsInWord_0203b4b0((unsigned int*)res, 0x2000);
        self->done = 1;
        return;
    }

    CancelPendingAction020397cc((Obj020397cc*)leader, 1);

    switch (self->state) {
    case 0: {
        if (self->quiet == 0) {
            DispatchWithShortB4_0205eaa0((Obj0205eaa0*)&data_02108760, 1, 0);
        }
        *(short*)((char*)leader + 0xb2) = 0;
        Vec3_021b8e8c from = *(Vec3_021b8e8c*)((char*)leader + 0x44);
        Entry021b8e8c* entry = (Entry021b8e8c*)FindEntryPointerByKey0203df78(table, self->rec->id);
        if (entry == NULL) {
            SetByteField0x253_020397c0(leader);
            if (hud != NULL) {
                SetField0x23cTrue_020a27ac(hud);
            }
            self->done = 1;
            break;
        }
        TeardownAndResetState020d7aa0(GetGlobalResetObj020d7a50());
        self->lastId = self->rec->id;
        if (IsIdInRange020981e4((int)((char*)area + 0x840), areaId) &&
            IsInRange1To63_02098268((int)((char*)area + 0x840), self->rec->id)) {
            self->hasSub = 1;
        }
        Vec3_021b8e8c to = _Z29SelectVec3FromSources020406f8P13Vec3_020406f8P12Node020406f8((Node020406f8*)entry);
        SetVecYByMode02033834((Obj02033834*)leader, fix32ReduceAngle0To2Pi(fix32_Atan2(to.x - from.x, to.z - from.z)));
        *(int*)(msg + 0x1838) = FindEntryByKey0203dfdc(table, self->rec->id);
        *(int*)(msg + 0x183c) = GetFieldFromActiveChild((Owner02040a90*)entry);
        char* info = (char*)GetField0x8_02040528((int*)entry);
        if (info != NULL && strstr(info + 4, &data_ov017_021d7c90) != NULL && !(entry->flags & 0x4000) &&
            entry->combat != NULL) {
            SetCombatFlags0x5c(entry->combat, 1, 0);
        }
        int tableId = GetField5cb0Value_0201079c((char*)gs);
        char prefix[0xc];
        strcpy(prefix, *(char**)((char*)area + 8) + 5);
        prefix[3] = 0;
        CancelPendingAction020397cc((Obj020397cc*)leader, 1);
        if (self->hasSub != 0) {
            TailList020469b4* tail;
            TailNode020469b4* node = (TailNode020469b4*)res->unknown_ptr_array_3afc[0x22];
            tail = (TailList020469b4*)res->unknown_ptr_array_36fc[0];
            Entry0209854c* found = FindEntryByFieldC0209854c((Entry0209854c*)((char*)area + 0x840), *(unsigned short*)info);
            func_ov017_021a967c(node, -1);
            *(Entry0209854c**)((char*)node + 0x54) = found;
            AppendNodeToTail(tail, node);
            self->done = 1;
            break;
        }
        char path[0x50];
        sprintf(path, &data_ov017_021d7c95, prefix, GetTableEntryOrZero_0218d2c4(tableId));
        if (hud != NULL) {
            ClearIntAt0x23c_020a27b8((unsigned char*)hud);
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
            SetByteField0x253_020397c0(leader);
            if (hud != NULL) {
                SetField0x23cTrue_020a27ac(hud);
            }
            self->done = 1;
            ReinitController02043204(msg);
            func_02043124(msg);
            break;
        }
        void* data;
        unsigned int length;
        loader->GetLoadedFileByID(self->task, &data, &length);
        int arg = GetField5cb4Value_020107d0((char*)gs);
        unsigned short id = self->rec->id;
        int lo = GetNibble0206ec1c((int)nibbles, id, nibbles, 0x80);
        int hi = GetNibble0206ec1c((int)nibbles, id, nibbles + 0x80, 0x80);
        char* text = (char*)func_ov017_021ba810(data, length, id, arg, self->f124, lo, hi);
        if (text == NULL) {
            loader->RemoveTask(self->task);
            self->task = -1;
            SetByteField0x253_020397c0(leader);
            if (hud != NULL) {
                SetField0x23cTrue_020a27ac(hud);
            }
            self->done = 1;
            ReinitController02043204(msg);
            func_02043124(msg);
            break;
        }
        IncrementNibble0206ec64((int)nibbles, id, nibbles, 0x80);
        IncrementNibble0206ec64((int)nibbles, id, nibbles + 0x80, 0x80);
        *(int*)(msg + 0x99c) = self->rec->kind;
        char* out = *(char**)(msg + 0x5c);
        char* in = *(char**)(msg + 0x60);
        memset(out, 0, 0x960);
        memset(in, 0, 0x960);
        if (strlen(text) >= 0x960) {
            text[0x95f] = 0;
        }
        AppendString02042058(in, text);
        loader->RemoveTask(self->task);
        self->task = -1;
        unsigned char* script = GetData02108d18_0206f504();
        Init0206f510((char*)script);
        if (func_0206f550(script, in, out) != 0 && CommandDispatch0206f6cc(script, 0) == 0) {
            self->state = 8;
            BlankFunction02094b34(GetGlobal02109400_02094a00(), 0x6f, 0x1388, 1, 1);
            break;
        }
        self->state = 3;
        break;
    }
    case 8:
        if (AlwaysTrue02094b4c(GetGlobal02109400_02094a00()) != 0) {
            if (hud != NULL) {
                SetField0x23cTrue_020a27ac(hud);
            }
            if (ListContainsId(list, 0x2b) != 0 && hud != NULL) {
                ClearIntAt0x23c_020a27b8((unsigned char*)hud);
            }
            self->state = -1;
            self->done = 1;
        }
        break;
    case 3: {
        if (self->hasSub != 0) {
            func_ov008_02184754(self->sub);
        }
        FontBankLoader* fade = GetGlobal02109400_02094a00();
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
        if (AlwaysTrue02094b4c(GetGlobal02109400_02094a00()) != 0) {
            self->state = 2;
        }
        break;
    case 2: {
        func_020a0cc4(0xa000);
        self->allocA.CreateTypeA(AllocateAligned4_02012d88(&data_02114e20, 0xa000), 0xa000);
        InitAllocatorsAndBuffers0208b8c4((Obj0208b8c4*)self->timer, &self->allocA);
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
            SetField0x23cTrue_020a27ac(hud);
        }
        self->done = 1;
        func_ov017_021b8d80(self);
        if (FindEntryPointerByKey0203df78(table, self->rec->id) == NULL) {
            break;
        }
        Query021b8e8c query;
        query.id = self->rec->id;
        query.value = self->f124;
        if (LookupAndForEachNode020649b0(events, 1, &query) != 0) {
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
            ReinitController02043204(msg);
            func_02043124(msg);
        }
        if (*(int*)(msg + 0x998) != 0) {
            break;
        }
        if (self->hasSub != 0) {
            if (self->subStep == 0) {
                SetByteB10AndClearB11_02184a3c((char*)self->sub, 0xd);
                self->subStep++;
                break;
            }
            if (self->sub[0xb10] != 0xe) {
                break;
            }
            self->subStep = 0;
        }
        Entry021b8e8c* entry = (Entry021b8e8c*)FindEntryPointerByKey0203df78(table, self->rec->id);
        if (entry == NULL) {
            break;
        }
        char* info = (char*)GetField0x8_02040528((int*)entry);
        if (info != NULL && strstr(info + 4, &data_ov017_021d7c90) != NULL && !(entry->flags & 0x4000) &&
            entry->combat != NULL) {
            SetCombatFlags0x5c(entry->combat, 1, 1);
        }
        self->state = 6;
        break;
    }
    case 6: {
        if (*(short*)(self->timer + 0xd2) < 0) {
            SetByteField0x253_020397c0(leader);
            if (hud != NULL) {
                SetField0x23cTrue_020a27ac(hud);
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
        if (LookupAndForEachNode020649b0(events, 1, &query) != 0) {
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
                SetFlag0x2IfByte0xd4Not3_0208beb4(self->timer);
                break;
            }
            SetFields120_138_021bd38c(res->unknown_ptr_array_36fc[14], (int)self->timer, (int)&self->allocA);
            self->finished = 1;
        }
        SetByteField0x253_020397c0(leader);
        if (hud != NULL) {
            SetField0x23cTrue_020a27ac(hud);
        }
        self->done = 1;
        func_ov017_021b8d80(self);
        break;
    }
}
