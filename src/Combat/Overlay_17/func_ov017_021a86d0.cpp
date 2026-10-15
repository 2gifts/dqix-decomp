#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#include "Combat/Main/CopyRecord0200fbb4.h"
#include "GameState/GameState.h"

#if defined(jpn)
extern "C" char data_ov017_021d7c0c[];
extern "C" void func_0205dfa8(void* obj);
enum { WorkBuffer = 0x1000, MessageContainer = 0x230, ResourceTail = 0x34ec, ResourceNode = 0x34fc, ResourceAux = 0x3524, SubEnd = 0x1f4, SubByte = 0x1ef, MessageState = 0x868, MessageResult = 0x870, MessageLeft = 0x7e4, MessageWidth = 0x7e8, MessageTop = 0x7e6, MessageDone = 0x17de, GrottoResult = 0x27f4, GrottoFlag = 0x285f };
#else
enum { WorkBuffer = 0x1400, MessageContainer = 0x2e0, ResourceTail = 0x36fc, ResourceNode = 0x370c, ResourceAux = 0x3734, SubEnd = 0x264, SubByte = 0x25f, MessageState = 0x998, MessageResult = 0x9a0, MessageLeft = 0x914, MessageWidth = 0x918, MessageTop = 0x916, MessageDone = 0x19ae, GrottoResult = 0x27b4, GrottoFlag = 0x281f };
#endif

struct Sub021a86d0 {
    char pad0[0x4];
    unsigned char resetData[0x1c];
    unsigned char table4c[0x50];
    unsigned char table9c[0x40];
    unsigned char dc;
    unsigned char dd;
    char padde[2];
    short e0;
    short e2;
    short e4;
    short e6;
    char pade8[SubByte - 0xe8];
    unsigned char b25f;
    unsigned char b260;
    char pad261[3];
};

struct Self021a86d0 {
    char pad0;
    unsigned char done;
    char pad2[6];
    int state;
    int result;
    int choice;
    int mode;
    unsigned char members[5];
    char pad1d[3];
    int count;
    int planes;
    int task;
    unsigned char sub[SubEnd - 0x2c];
    unsigned char allocator[0x14];
    unsigned char container[0x10];
};

char* GetGlobalField0x1c020421a0(void);
extern "C" char* func_02012fe4(void);
void SetupAndDispatch0205c904(unsigned char* obj, int value);
void* GetGlobalResetObj020d7a50(void);
struct Obj020d7aa0;
void TeardownAndResetState020d7aa0(Obj020d7aa0*);
struct Obj020397cc;
void CancelPendingAction020397cc(Obj020397cc*, int);
void SetBitsInField4_0203b4d8(unsigned int*, unsigned int);
extern "C" void ColorEffect_ConfigureAlphaBlend(void* reg, int plane1, int plane2, int ev1, int ev2);
void* GetGlobalPtr021075f4_0203cf4c(void);
void* FindEntryPointerByKey0203df78(void* p, int key);
extern "C" Vector3fix _Z29SelectVec3FromSources020406f8P13Vec3_020406f8P12Node020406f8(void* node);
extern "C" int fix32_Atan2(int y, int x);
#include "Combat/EntryGetterTypes.h"
#include "Filesystem/BackgroundLoader.h"
struct AllocatorUnion;
void* AllocateAligned4_02012d88(AllocatorUnion*, unsigned int);
extern "C" void func_020dfec0(void* cont, void* alloc, void* data, unsigned int length);
struct Obj02046574;
void SetIndexedName02046574(Obj02046574*, int, char*);
struct Obj0205eaa0;
void DispatchWithShortB4_0205eaa0(Obj0205eaa0*, int, int);
extern "C" void func_ov017_021a933c(void* obj, int key);
void InitBigStruct0205c790(char*);
struct Struct_0205ba68;
void SetupPointerTable0205ba68(Struct_0205ba68*, int, int, int);
struct Node0205bacc;
void SetField0AndPropagate0205bacc(Node0205bacc*, int);
struct Container020e0310;
void* GetFieldByKey020e0434(Container020e0310*, int);
void ProcessCombatEntry0205cb74(char*, int);
extern "C" void func_0205cc50(void* obj, int a, int b);
struct Struct_0205bcdc;
void SetIndexIfValid0205bcdc(Struct_0205bcdc*, int);
extern "C" void func_0205bb04(void* obj, int value);
struct ResetBytesAndSetByte0x16Data;
void ResetBytesAndSetByte0x16_0205c77c(ResetBytesAndSetByte0x16Data*, int);
void SetupGlobalObjType1AndInitSelfPointer_0205cd28(unsigned char* obj);
struct Container0205a330;
void IterateEntries0205a330(Container0205a330*, int);
int GetScaledSumIfActive0205cecc(void* obj);
int TestFlag0SetAndFlag1Clear_02012444(unsigned short* flags, int mask);
int CallFunc0205c570AtField0x1c_0205cb64(void* obj);
void ReinitController02043204(char* obj);
void SetupGlobalObjType3AndInitSelfPointer_0205ce50(unsigned char* obj);
extern "C" int func_020457e0(char* obj);
extern "C" unsigned char* func_0205ec34(void);
unsigned char* GetField0x3f8Address_0200fd0c(GameState*);
extern "C" void VectorizedMemset(void* dst, int value, unsigned int size);
void InitContext020e1154(void* p);
void SetHalfFieldsAndEnqueueIfActive_021d1c2c(unsigned char, unsigned short);
void EnqueueEventTagB5_021d1dc0(unsigned short, int, int*, int, int);
void InitAndResetHeader_0219e310(unsigned char* obj, int arg);
struct TailList020469b4;
struct TailNode020469b4;
void AppendNodeToTail(TailList020469b4*, TailNode020469b4*);
void InitAndAppendState61_021a65c4(void* obj, unsigned char mode, int arg);
extern "C" void func_ov017_021baedc(unsigned char* node, int arg);
int GetField5cb0Value_0201079c(char*);
int GetField5cb4Value_020107d0(char*);
int GetField5cb8Value_02010804(char*);
int TestBitInByteArray_0206dfb0(int, unsigned char*, int);
int ReturnZero_021a01b4(char* res, int value);
void SetField11c_021bbbf8(void*, unsigned short);
void SetByteField0x253_020397c0(void* obj);
extern "C" void func_ov017_021a92a0(Self021a86d0* self);

extern char data_ov017_021d77f0[];
extern char data_ov017_021d780a[];
extern char data_02114e20[];
extern char data_02108760[];
extern unsigned short data_02114e30;

static inline unsigned int GX_GetVisiblePlane(void) {
    return (*(volatile unsigned int*)0x4000000 & 0x1f00) >> 8;
}

static inline void GX_SetVisiblePlane(unsigned int plane) {
    *(volatile unsigned int*)0x4000000 = (*(volatile unsigned int*)0x4000000 & ~0x1f00) | (plane << 8);
}

// USA: func_ov017_021a86d0
extern "C" ARM void func_ov017_021a86d0(Self021a86d0* self, void* list) {
    GameState* gs = GameState::GetInstance();
    char* g = GetGlobalField0x1c020421a0();
    char* flags = func_02012fe4();
    Sub021a86d0* sub = (Sub021a86d0*)self->sub;
    SetupAndDispatch0205c904(self->sub, gs->GetTickCount());

    if (self->state == 0) {
        TeardownAndResetState020d7aa0((Obj020d7aa0*)GetGlobalResetObj020d7a50());
        self->planes = GX_GetVisiblePlane();
        GX_SetVisiblePlane(0x11);
        CancelPendingAction020397cc((Obj020397cc*)gs->GetProtagonist(), 1);
        SetBitsInField4_0203b4d8((unsigned int*)func_ov017_0218b5b0(), 0x40);
        ColorEffect_ConfigureAlphaBlend((void*)0x4000050, 0x10, 1, 0x1f, 0);
        void* tbl = GetGlobalPtr021075f4_0203cf4c();
        void* node = NULL;
        if (self->mode == 0) {
            node = FindEntryPointerByKey0203df78(tbl, 2);
        } else if (self->mode == 1) {
            node = FindEntryPointerByKey0203df78(tbl, 0xcb);
        }
        if (node != NULL) {
            GameObject* unk = gs->GetUnknownGameObject();
            Vector3fix target = _Z29SelectVec3FromSources020406f8P13Vec3_020406f8P12Node020406f8(node);
            Vector3fix diff;
            Vector3fix_Subtract(&unk->obj3D_.position_, &target, &diff);
            Vector3fix_Normalize(&diff, &diff);
            int angle = fix32_Atan2(diff.x, diff.z);
            if (angle < 0) {
                angle += 0x6488;
            }
            SetValueOnActiveChild02040af0((Entry_203dce4*)node, angle);
        }
        FontBankLoader* snd = GetGlobal02109400_02094a00();
        BlankFunction02094b30(snd, 0x205, 0);
        if (AlwaysTrue02094b4c(snd)) {
#if defined(jpn)
            self->task = ((BackgroundLoader*)BackgroundLoader::GetInstance())->QueueLoadFile(data_ov017_021d7c0c, (SafeAllocator*)NULL);
#else
            self->task = BackgroundLoader::GetInstance()->QueueLoadFileInGP2(data_ov017_021d77f0, data_ov017_021d780a, NULL);
#endif
            ((SafeAllocator*)self->allocator)->CreateTypeA(AllocateAligned4_02012d88((AllocatorUnion*)data_02114e20, WorkBuffer), WorkBuffer);
            self->state = 1;
        }
    } else if (self->state == 1) {
        void* loader = BackgroundLoader::GetInstance();
        if (((BackgroundLoader*)loader)->GetTaskStatus(self->task)) {
            void* data;
            unsigned int length;
            ((BackgroundLoader*)loader)->GetLoadedFileByID(self->task, &data, &length);
            ((SafeAllocator*)self->allocator)->Reset();
            func_020dfec0(self->container, self->allocator, data, length);
            ((BackgroundLoader*)loader)->RemoveTask(self->task);
            self->task = -1;
            SetIndexedName02046574((Obj02046574*)g, 0, *(char**)((char*)gs->GetProtagonist() + 0x134));
            DispatchWithShortB4_0205eaa0((Obj0205eaa0*)data_02108760, 1, 0);
            func_ov017_021a933c(self, 0x64);
            *(int*)(g + MessageState) = 1;
            self->state = 2;
        }
    } else if (self->state == 2) {
        if (*(int*)(g + MessageResult) == 3) {
            self->count = 0;
            for (int i = 0; i < 5; i++) {
                if (self->members[i]) {
                    self->count++;
                }
            }
            InitBigStruct0205c790((char*)self->sub);
            sub->dd = 1;
            sub->dc = 1;
            int count = self->count;
            SetupPointerTable0205ba68((Struct_0205ba68*)sub->table4c, 1, count + 1, 0);
            SetupPointerTable0205ba68((Struct_0205ba68*)sub->table9c, 1, count + 1, 0);
            SetField0AndPropagate0205bacc((Node0205bacc*)sub->table4c, count + 1);
            SetField0AndPropagate0205bacc((Node0205bacc*)sub->table9c, count + 1);
            int offset = 0;
            for (int j = 0; j < self->count; j++) {
                if (self->members[j] == 4) {
                    offset = 0xc;
                }
                ProcessCombatEntry0205cb74((char*)self->sub, (int)(GetFieldByKey020e0434((Container020e0310*)self->container, self->members[j])));
            }
            ProcessCombatEntry0205cb74((char*)self->sub, (int)(GetFieldByKey020e0434((Container020e0310*)self->container, 6)));
            int n = self->count;
            int y = 0x60 - (n + 1) * 0xe;
            if (n == 2) {
                y = 0x38;
            }
            if (n == 4) {
                y = 0x18;
            }
            sub->e0 = 0x9e - offset;
            sub->e2 = y;
#if defined(jpn)
            func_0205dfa8(self->sub);
#else
            func_0205cc50(self->sub, 0, -4);
#endif
            short left = *(short*)(g + MessageLeft);
            short width = *(short*)(g + MessageWidth);
            short top = *(short*)(g + MessageTop);
            short ox = sub->e4;
            short oy = sub->e6;
            sub->e0 = left + width - ox;
            sub->e2 = top - oy;
#if defined(jpn)
            func_0205dfa8(self->sub);
#else
            func_0205cc50(self->sub, 0, -4);
#endif
            SetIndexIfValid0205bcdc((Struct_0205bcdc*)sub->table4c, 0);
            func_0205bb04(sub->table9c, 0);
            sub->b260 = 1;
            ResetBytesAndSetByte0x16_0205c77c((ResetBytesAndSetByte0x16Data*)sub->resetData, 1);
            sub->b25f = 1;
            sub->b260 = 1;
            ResetBytesAndSetByte0x16_0205c77c((ResetBytesAndSetByte0x16Data*)sub->resetData, 1);
            SetupGlobalObjType1AndInitSelfPointer_0205cd28(self->sub);
            self->state = 3;
        }
    } else if (self->state == 3) {
        void* cont = *(void**)(g + MessageContainer);
        IterateEntries0205a330((Container0205a330*)cont, gs->GetTickCount());
        g[MessageDone] = 0;
        int sel = GetScaledSumIfActive0205cecc(self->sub);
        if (TestFlag0SetAndFlag1Clear_02012444(&data_02114e30, 1)) {
            DispatchWithShortB4_0205eaa0((Obj0205eaa0*)data_02108760, 1, 0);
            sel = CallFunc0205c570AtField0x1c_0205cb64(self->sub);
        } else if (TestFlag0SetAndFlag1Clear_02012444(&data_02114e30, 2)) {
            sel = -2;
        }
        if (self->count > sel && sel >= 0) {
            self->choice = self->members[sel];
            self->state = 5;
        } else if (sel != -1) {
            self->state = 4;
        }
    } else if (self->state == 4) {
        ReinitController02043204(g);
        self->state = 100;
    } else if (self->state == 5) {
        self->result = *(unsigned short*)(flags + GrottoResult);
        if (self->choice == self->result) {
            *(int*)(g + MessageState) = 1;
            func_ov017_021a933c(self, 0x65);
            SetupGlobalObjType3AndInitSelfPointer_0205ce50(self->sub);
            self->state = 6;
        } else {
            self->state = 99;
            func_ov017_021a86d0(self, list);
        }
    } else if (self->state == 6) {
        if (*(int*)(g + MessageResult) == 0) {
            *(int*)(g + MessageState) = 1;
            if (func_020457e0(g) == 0) {
                func_ov017_021a933c(self, 0x66);
                self->state = 7;
            } else if (func_020457e0(g) == 1) {
                func_ov017_021a933c(self, 0x67);
                self->state = 2;
            }
        }
    } else if (self->state == 7) {
        g[MessageDone] = 0;
        if (*(int*)(g + MessageResult) == 0) {
            self->state = 99;
            func_ov017_021a86d0(self, list);
        }
    } else if (self->state == 99) {
        int chapter;
        int part;
        unsigned char* bits = func_0205ec34();
        char* res = (char*)func_ov017_0218b5b0();
        void* tail = *(void**)(res + ResourceTail);
        unsigned char* ctx = GetField0x3f8Address_0200fd0c(gs);
        VectorizedMemset(ctx, 0, 0x70);
        ctx[4] = 1;
        ctx[8] = 1;
        ctx[9] = 1;
        ((signed char*)ctx)[0xb] = -1;
        *(int*)(ctx + 0x20) = -1;
        *(int*)(ctx + 0x24) = -1;
        *(int*)(ctx + 0x28) = -1;
        *(int*)(ctx + 0x2c) = -1;
        *(short*)(ctx + 0x1e) = -1;
        ctx[0xc] = 0;
        *(short*)(ctx + 0x6c) = -1;
        ctx[7] = 1;
        InitContext020e1154((void*)0x1f4);
        if (self->result == self->choice) {
            int intro = 1;
            switch (self->choice) {
            case 0:
                break;
            case 1:
                intro = 0;
                *(unsigned short*)ctx = 0x1198;
                *(short*)(ctx + 0x1c) = 0;
                *(int*)(ctx + 0x10) = -0xd000;
                *(int*)(ctx + 0x14) = 0x4333;
                *(int*)(ctx + 0x18) = -0xd000;
                break;
            case 2:
                *(unsigned short*)ctx = 0x4e27;
                *(short*)(ctx + 0x1c) = 0;
                *(int*)(ctx + 0x10) = -0x2b000;
                *(int*)(ctx + 0x14) = 0x14cc;
                *(int*)(ctx + 0x18) = -0x22000;
                break;
            case 4:
                *(unsigned short*)ctx = 0x4e42;
                *(short*)(ctx + 0x1c) = 0;
                *(int*)(ctx + 0x10) = 0x4000;
                *(int*)(ctx + 0x14) = 0x14cc;
                *(int*)(ctx + 0x18) = 0x41000;
                break;
            case 3:
                *(unsigned short*)ctx = 0x10cd;
                *(short*)(ctx + 0x1c) = 0x3244;
                intro = 0;
                *(int*)(ctx + 0x10) = 0;
                *(int*)(ctx + 0x14) = -0x6ccc;
                *(int*)(ctx + 0x18) = 0;
                break;
            case 5:
                *(unsigned short*)ctx = 0x1130;
                *(short*)(ctx + 0x1c) = 0x3244;
                intro = 0;
                *(int*)(ctx + 0x10) = 0;
                *(int*)(ctx + 0x14) = -0x5ccc;
                *(int*)(ctx + 0x18) = 0x1000;
                break;
            }
            int buf[3];
            SetHalfFieldsAndEnqueueIfActive_021d1c2c(self->choice, 0);
            EnqueueEventTagB5_021d1dc0(self->choice, 0, buf, 0, 0);
            CallFunc0200fbb4AtField0x3f8_0200fcfc(gs, ctx);
            unsigned char* header = *(unsigned char**)(res + ResourceNode);
            InitAndResetHeader_0219e310(header, 0);
            AppendNodeToTail((TailList020469b4*)tail, (TailNode020469b4*)header);
            if (intro) {
                InitAndAppendState61_021a65c4(res, 1, 0);
            }
        } else {
            unsigned char* node = *(unsigned char**)(res + ResourceAux);
            func_ov017_021baedc(node, 1);
            int msgA = 0;
            int msgB = 0;
            switch (self->result) {
            case 0:
                break;
            case 2:
                if (self->choice == 4) {
                    msgA = 0x733c;
                } else {
                    msgA = 0x734b;
                }
                break;
            case 4:
                if (self->choice == 2) {
                    msgA = 0x733f;
                } else {
                    msgA = 0x734c;
                }
                break;
            case 1:
                flags[GrottoFlag] = 1;
                msgA = 0x7342;
                break;
            case 3:
                flags[GrottoFlag] = 1;
                msgA = 0x7345;
                break;
            case 5:
                flags[GrottoFlag] = 1;
                msgA = 0x7348;
                break;
            }
            switch (self->choice) {
            case 0:
                break;
            case 2:
                msgB = 0x733d;
                break;
            case 4:
                msgB = 0x7340;
                break;
            case 1:
                msgB = 0x7343;
                break;
            case 3:
                msgB = 0x7346;
                break;
            case 5:
                msgB = 0x7349;
                break;
            }
            chapter = GetField5cb0Value_0201079c((char*)gs);
            part = GetField5cb4Value_020107d0((char*)gs);
            int step = GetField5cb8Value_02010804((char*)gs);
            if (chapter == 10 && part == 8 && step == 1) {
                if (self->mode == 0 && self->choice == 1 &&
                    TestBitInByteArray_0206dfb0((int)bits, bits + 0x8c, 4) &&
                    TestBitInByteArray_0206dfb0((int)bits, bits + 0x8c, 5) &&
                    TestBitInByteArray_0206dfb0((int)bits, bits + 0x8c, 6) &&
                    TestBitInByteArray_0206dfb0((int)bits, bits + 0x8c, 7) &&
                    TestBitInByteArray_0206dfb0((int)bits, bits + 0x8c, 8) &&
                    TestBitInByteArray_0206dfb0((int)bits, bits + 0x8c, 9) &&
                    TestBitInByteArray_0206dfb0((int)bits, bits + 0x8c, 10)) {
                    msgB = 0x7080;
                }
            } else if (chapter == 0x11 && part == 1 && step == 1 && self->mode == 1 && self->choice == 3) {
                if (TestBitInByteArray_0206dfb0((int)bits, bits + 0x8c, 0x15)) {
                    msgB = 0x721a;
                }
            }
            if (msgA == 0) {
                msgA = msgB;
                msgB = 0;
            }
            if (ReturnZero_021a01b4(res, msgA)) {
                flags[GrottoFlag] = 1;
            }
            *(unsigned short*)(node + 8) = msgA;
            SetField11c_021bbbf8(node, msgB);
            AppendNodeToTail((TailList020469b4*)tail, (TailNode020469b4*)node);
            int buf[3];
            SetHalfFieldsAndEnqueueIfActive_021d1c2c(self->choice, 0);
            EnqueueEventTagB5_021d1dc0(self->choice, 0, buf, msgA, msgB);
        }
        self->state = 100;
        ReinitController02043204(g);
    } else if (self->state == 100 && *(int*)(g + MessageResult) == 0) {
        ReinitController02043204(g);
        SetupGlobalObjType3AndInitSelfPointer_0205ce50(self->sub);
        SetByteField0x253_020397c0(gs->GetProtagonist());
        func_ov017_021a92a0(self);
        self->done = 1;
    }
}
