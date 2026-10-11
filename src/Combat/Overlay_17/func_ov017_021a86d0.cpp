// JPN: func_ov017_021a8ecc
#include <globaldefs.h>
#include "Combat/Main/CopyRecord0200fbb4.h"

#if defined(jpn)
extern "C" int _ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(void* loader, const char* file, void* alloc);
extern "C" char data_ov017_021d7c0c[];
extern "C" void func_0205dfa8(void* obj);
enum { WorkBuffer = 0x1000, MessageContainer = 0x230, ResourceTail = 0x34ec, ResourceNode = 0x34fc, ResourceAux = 0x3524, SubEnd = 0x1f4, SubByte = 0x1ef, MessageState = 0x868, MessageResult = 0x870, MessageLeft = 0x7e4, MessageWidth = 0x7e8, MessageTop = 0x7e6, MessageDone = 0x17de, GrottoResult = 0x27f4, GrottoFlag = 0x285f };
#else
enum { WorkBuffer = 0x1400, MessageContainer = 0x2e0, ResourceTail = 0x36fc, ResourceNode = 0x370c, ResourceAux = 0x3734, SubEnd = 0x264, SubByte = 0x25f, MessageState = 0x998, MessageResult = 0x9a0, MessageLeft = 0x914, MessageWidth = 0x918, MessageTop = 0x916, MessageDone = 0x19ae, GrottoResult = 0x27b4, GrottoFlag = 0x281f };
#endif

struct Vec3_021a86d0 {
    int x;
    int y;
    int z;
};

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


extern "C" void* _ZN9GameState11GetInstanceEv(void);
extern "C" char* _Z26GetGlobalField0x1c020421a0v(void);
extern "C" char* func_02012fe4(void);
extern "C" unsigned int _ZNK9GameState12GetTickCountEv(void* gs);
extern "C" void _Z24SetupAndDispatch0205c904Phi(unsigned char* obj, int value);
extern "C" void* _Z25GetGlobalResetObj020d7a50v(void);
extern "C" void _Z29TeardownAndResetState020d7aa0P11Obj020d7aa0(void* obj);
extern "C" void* _ZN9GameState14GetProtagonistEv(void* gs);
extern "C" void _Z27CancelPendingAction020397ccP11Obj020397cci(void* obj, int arg);
extern "C" char* func_ov017_0218b5b0(void);
extern "C" void _Z15SetBitsInField4Pjj(void* obj, unsigned int mask);
extern "C" void ColorEffect_ConfigureAlphaBlend(void* reg, int plane1, int plane2, int ev1, int ev2);
extern "C" void* _Z20GetGlobalPtr021075f4v(void);
extern "C" void* _Z29FindEntryPointerByKey0203df78Pvi(void* p, int key);
extern "C" char* _ZN9GameState20GetUnknownGameObjectEv(void* gs);
extern "C" Vec3_021a86d0 _Z29SelectVec3FromSources020406f8P13Vec3_020406f8P12Node020406f8(void* node);
extern "C" void Vector3fix_Subtract(const Vec3_021a86d0* a, const Vec3_021a86d0* b, Vec3_021a86d0* out);
extern "C" void Vector3fix_Normalize(const Vec3_021a86d0* a, Vec3_021a86d0* out);
extern "C" int fix32_Atan2(int y, int x);
extern "C" void _Z29SetValueOnActiveChild02040af0P13Child02040af0i(void* obj, int value);
extern "C" void* _Z17GetGlobal02109400v(void);
extern "C" void _Z21BlankFunction02094b30v(void* obj, int a, int b);
extern "C" int _Z18AlwaysTrue02094b4cv(void* obj);
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv(void);
extern "C" int _ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(void* loader, const char* gp2, const char* inner, void* alloc);
extern "C" void* _Z16AllocateAligned4P14AllocatorUnionj(void* alloc, unsigned int size);
extern "C" void _ZN13SafeAllocator11CreateTypeAEPvj(void* alloc, void* buf, unsigned int size);
extern "C" int _ZN16BackgroundLoader13GetTaskStatusEi(void* loader, int task);
extern "C" void _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(void* loader, int task, void** data, unsigned int* length);
extern "C" void _ZN13SafeAllocator5ResetEv(void* alloc);
extern "C" void func_020dfec0(void* cont, void* alloc, void* data, unsigned int length);
extern "C" void _ZN16BackgroundLoader10RemoveTaskEi(void* loader, int task);
extern "C" void _Z22SetIndexedName02046574P11Obj02046574iPc(void* obj, int index, char* name);
extern "C" void _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(void* obj, int a, int b);
extern "C" void func_ov017_021a933c(void* obj, int key);
extern "C" void _Z21InitBigStruct0205c790Pc(unsigned char* obj);
extern "C" void _Z25SetupPointerTable0205ba68P15Struct_0205ba68iii(void* obj, int a, int b, int c);
extern "C" void _Z29SetField0AndPropagate0205baccP12Node0205bacci(void* obj, int value);
extern "C" void* _Z21GetFieldByKey020e0434P17Container020e0310i(void* cont, int key);
extern "C" void _Z26ProcessCombatEntry0205cb74Pci(unsigned char* obj, void* entry);
extern "C" void func_0205cc50(void* obj, int a, int b);
extern "C" void _Z23SetIndexIfValid0205bcdcP15Struct_0205bcdci(void* obj, int index);
extern "C" void func_0205bb04(void* obj, int value);
extern "C" void _Z24ResetBytesAndSetByte0x16P28ResetBytesAndSetByte0x16Datai(void* obj, int value);
extern "C" void _Z37SetupGlobalObjType1AndInitSelfPointerPh(unsigned char* obj);
extern "C" void _Z22IterateEntries0205a330P17Container0205a330i(void* cont, int value);
extern "C" int _Z28GetScaledSumIfActive0205ceccPv(void* obj);
extern "C" int _Z25TestFlag0SetAndFlag1ClearPti(unsigned short* flags, int mask);
extern "C" int _Z27CallFunc0205c570AtField0x1cPv(void* obj);
extern "C" void _Z24ReinitController02043204Pc(char* obj);
extern "C" void _Z37SetupGlobalObjType3AndInitSelfPointerPh(unsigned char* obj);
extern "C" int func_020457e0(char* obj);
extern "C" unsigned char* func_0205ec34(void);
extern "C" unsigned char* _Z20GetField0x3f8AddressP9GameState(void* gs);
extern "C" void VectorizedMemset(void* dst, int value, unsigned int size);
extern "C" void _Z19InitContext020e1154Pv(void* p);
extern "C" void _Z40SetHalfFieldsAndEnqueueIfActive_021d1c2ctt(unsigned char a, unsigned short b);
extern "C" void _Z26EnqueueEventTagB5_021d1dc0ssPisi(unsigned short id, int a, int* buf, int b, int c);
extern "C" void _Z27InitAndResetHeader_0219e310Phi(unsigned char* obj, int arg);
extern "C" void _Z16AppendNodeToTailP16TailList020469b4P16TailNode020469b4(void* list, void* node);
extern "C" void _Z29InitAndAppendState61_021a65c4Pvhi(void* obj, unsigned char mode, int arg);
extern "C" void func_ov017_021baedc(unsigned char* node, int arg);
extern "C" int _Z17GetField5cb0ValuePc(void* gs);
extern "C" int _Z17GetField5cb4ValuePc(void* gs);
extern "C" int _Z17GetField5cb8ValuePc(void* gs);
extern "C" int _Z18TestBitInByteArrayiPhi(unsigned char* obj, unsigned char* array, int bit);
extern "C" int _Z19ReturnZero_021a01b4v(char* res, int value);
extern "C" void _Z20SetField11c_021bbbf8Pvt(unsigned char* obj, unsigned short value);
extern "C" void _Z17SetByteField0x253Pv(void* obj);
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
    void* gs = _ZN9GameState11GetInstanceEv();
    char* g = _Z26GetGlobalField0x1c020421a0v();
    char* flags = func_02012fe4();
    Sub021a86d0* sub = (Sub021a86d0*)self->sub;
    _Z24SetupAndDispatch0205c904Phi(self->sub, _ZNK9GameState12GetTickCountEv(gs));

    if (self->state == 0) {
        _Z29TeardownAndResetState020d7aa0P11Obj020d7aa0(_Z25GetGlobalResetObj020d7a50v());
        self->planes = GX_GetVisiblePlane();
        GX_SetVisiblePlane(0x11);
        _Z27CancelPendingAction020397ccP11Obj020397cci(_ZN9GameState14GetProtagonistEv(gs), 1);
        _Z15SetBitsInField4Pjj(func_ov017_0218b5b0(), 0x40);
        ColorEffect_ConfigureAlphaBlend((void*)0x4000050, 0x10, 1, 0x1f, 0);
        void* tbl = _Z20GetGlobalPtr021075f4v();
        void* node = NULL;
        if (self->mode == 0) {
            node = _Z29FindEntryPointerByKey0203df78Pvi(tbl, 2);
        } else if (self->mode == 1) {
            node = _Z29FindEntryPointerByKey0203df78Pvi(tbl, 0xcb);
        }
        if (node != NULL) {
            char* unk = _ZN9GameState20GetUnknownGameObjectEv(gs);
            Vec3_021a86d0 target = _Z29SelectVec3FromSources020406f8P13Vec3_020406f8P12Node020406f8(node);
            Vec3_021a86d0 diff;
            Vector3fix_Subtract((Vec3_021a86d0*)(unk + 0x44), &target, &diff);
            Vector3fix_Normalize(&diff, &diff);
            int angle = fix32_Atan2(diff.x, diff.z);
            if (angle < 0) {
                angle += 0x6488;
            }
            _Z29SetValueOnActiveChild02040af0P13Child02040af0i(node, angle);
        }
        void* snd = _Z17GetGlobal02109400v();
        _Z21BlankFunction02094b30v(snd, 0x205, 0);
        if (_Z18AlwaysTrue02094b4cv(snd)) {
#if defined(jpn)
            self->task = _ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(
                _ZN16BackgroundLoader11GetInstanceEv(), data_ov017_021d7c0c, NULL);
#else
            self->task = _ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(
                _ZN16BackgroundLoader11GetInstanceEv(), data_ov017_021d77f0, data_ov017_021d780a, NULL);
#endif
            _ZN13SafeAllocator11CreateTypeAEPvj(self->allocator, _Z16AllocateAligned4P14AllocatorUnionj(data_02114e20, WorkBuffer), WorkBuffer);
            self->state = 1;
        }
    } else if (self->state == 1) {
        void* loader = _ZN16BackgroundLoader11GetInstanceEv();
        if (_ZN16BackgroundLoader13GetTaskStatusEi(loader, self->task)) {
            void* data;
            unsigned int length;
            _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(loader, self->task, &data, &length);
            _ZN13SafeAllocator5ResetEv(self->allocator);
            func_020dfec0(self->container, self->allocator, data, length);
            _ZN16BackgroundLoader10RemoveTaskEi(loader, self->task);
            self->task = -1;
            _Z22SetIndexedName02046574P11Obj02046574iPc(g, 0, *(char**)((char*)_ZN9GameState14GetProtagonistEv(gs) + 0x134));
            _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(data_02108760, 1, 0);
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
            _Z21InitBigStruct0205c790Pc(self->sub);
            sub->dd = 1;
            sub->dc = 1;
            int count = self->count;
            _Z25SetupPointerTable0205ba68P15Struct_0205ba68iii(sub->table4c, 1, count + 1, 0);
            _Z25SetupPointerTable0205ba68P15Struct_0205ba68iii(sub->table9c, 1, count + 1, 0);
            _Z29SetField0AndPropagate0205baccP12Node0205bacci(sub->table4c, count + 1);
            _Z29SetField0AndPropagate0205baccP12Node0205bacci(sub->table9c, count + 1);
            int offset = 0;
            for (int j = 0; j < self->count; j++) {
                if (self->members[j] == 4) {
                    offset = 0xc;
                }
                _Z26ProcessCombatEntry0205cb74Pci(self->sub, _Z21GetFieldByKey020e0434P17Container020e0310i(self->container, self->members[j]));
            }
            _Z26ProcessCombatEntry0205cb74Pci(self->sub, _Z21GetFieldByKey020e0434P17Container020e0310i(self->container, 6));
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
            _Z23SetIndexIfValid0205bcdcP15Struct_0205bcdci(sub->table4c, 0);
            func_0205bb04(sub->table9c, 0);
            sub->b260 = 1;
            _Z24ResetBytesAndSetByte0x16P28ResetBytesAndSetByte0x16Datai(sub->resetData, 1);
            sub->b25f = 1;
            sub->b260 = 1;
            _Z24ResetBytesAndSetByte0x16P28ResetBytesAndSetByte0x16Datai(sub->resetData, 1);
            _Z37SetupGlobalObjType1AndInitSelfPointerPh(self->sub);
            self->state = 3;
        }
    } else if (self->state == 3) {
        void* cont = *(void**)(g + MessageContainer);
        _Z22IterateEntries0205a330P17Container0205a330i(cont, _ZNK9GameState12GetTickCountEv(gs));
        g[MessageDone] = 0;
        int sel = _Z28GetScaledSumIfActive0205ceccPv(self->sub);
        if (_Z25TestFlag0SetAndFlag1ClearPti(&data_02114e30, 1)) {
            _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(data_02108760, 1, 0);
            sel = _Z27CallFunc0205c570AtField0x1cPv(self->sub);
        } else if (_Z25TestFlag0SetAndFlag1ClearPti(&data_02114e30, 2)) {
            sel = -2;
        }
        if (self->count > sel && sel >= 0) {
            self->choice = self->members[sel];
            self->state = 5;
        } else if (sel != -1) {
            self->state = 4;
        }
    } else if (self->state == 4) {
        _Z24ReinitController02043204Pc(g);
        self->state = 100;
    } else if (self->state == 5) {
        self->result = *(unsigned short*)(flags + GrottoResult);
        if (self->choice == self->result) {
            *(int*)(g + MessageState) = 1;
            func_ov017_021a933c(self, 0x65);
            _Z37SetupGlobalObjType3AndInitSelfPointerPh(self->sub);
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
        char* res = func_ov017_0218b5b0();
        void* tail = *(void**)(res + ResourceTail);
        unsigned char* ctx = _Z20GetField0x3f8AddressP9GameState(gs);
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
        _Z19InitContext020e1154Pv((void*)0x1f4);
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
            _Z40SetHalfFieldsAndEnqueueIfActive_021d1c2ctt(self->choice, 0);
            _Z26EnqueueEventTagB5_021d1dc0ssPisi(self->choice, 0, buf, 0, 0);
            _Z28CallFunc0200fbb4AtField0x3f8Pv(gs, ctx);
            unsigned char* header = *(unsigned char**)(res + ResourceNode);
            _Z27InitAndResetHeader_0219e310Phi(header, 0);
            _Z16AppendNodeToTailP16TailList020469b4P16TailNode020469b4(tail, header);
            if (intro) {
                _Z29InitAndAppendState61_021a65c4Pvhi(res, 1, 0);
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
            chapter = _Z17GetField5cb0ValuePc(gs);
            part = _Z17GetField5cb4ValuePc(gs);
            int step = _Z17GetField5cb8ValuePc(gs);
            if (chapter == 10 && part == 8 && step == 1) {
                if (self->mode == 0 && self->choice == 1 &&
                    _Z18TestBitInByteArrayiPhi(bits, bits + 0x8c, 4) &&
                    _Z18TestBitInByteArrayiPhi(bits, bits + 0x8c, 5) &&
                    _Z18TestBitInByteArrayiPhi(bits, bits + 0x8c, 6) &&
                    _Z18TestBitInByteArrayiPhi(bits, bits + 0x8c, 7) &&
                    _Z18TestBitInByteArrayiPhi(bits, bits + 0x8c, 8) &&
                    _Z18TestBitInByteArrayiPhi(bits, bits + 0x8c, 9) &&
                    _Z18TestBitInByteArrayiPhi(bits, bits + 0x8c, 10)) {
                    msgB = 0x7080;
                }
            } else if (chapter == 0x11 && part == 1 && step == 1 && self->mode == 1 && self->choice == 3) {
                if (_Z18TestBitInByteArrayiPhi(bits, bits + 0x8c, 0x15)) {
                    msgB = 0x721a;
                }
            }
            if (msgA == 0) {
                msgA = msgB;
                msgB = 0;
            }
            if (_Z19ReturnZero_021a01b4v(res, msgA)) {
                flags[GrottoFlag] = 1;
            }
            *(unsigned short*)(node + 8) = msgA;
            _Z20SetField11c_021bbbf8Pvt(node, msgB);
            _Z16AppendNodeToTailP16TailList020469b4P16TailNode020469b4(tail, node);
            int buf[3];
            _Z40SetHalfFieldsAndEnqueueIfActive_021d1c2ctt(self->choice, 0);
            _Z26EnqueueEventTagB5_021d1dc0ssPisi(self->choice, 0, buf, msgA, msgB);
        }
        self->state = 100;
        _Z24ReinitController02043204Pc(g);
    } else if (self->state == 100 && *(int*)(g + MessageResult) == 0) {
        _Z24ReinitController02043204Pc(g);
        _Z37SetupGlobalObjType3AndInitSelfPointerPh(self->sub);
        _Z17SetByteField0x253Pv(_ZN9GameState14GetProtagonistEv(gs));
        func_ov017_021a92a0(self);
        self->done = 1;
    }
}
