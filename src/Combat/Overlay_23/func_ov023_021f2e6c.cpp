#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"

struct EntryBits021f2e6c {
    unsigned int id : 9;
    unsigned int pad : 5;
    unsigned int b14 : 1;
    unsigned int b15 : 1;
    unsigned int b16 : 1;
    unsigned int rest : 15;
};
struct Entry021f2e6c {
    EntryBits021f2e6c bits;
    char pad[0xc];
};
struct Table021f2e6c {
    unsigned char count;
    char pad[3];
    Entry021f2e6c entries[1];
};
struct IdList021f2e6c {
    char pad[4];
    short ids[8];
    short count;
};
struct Mgr021f2e6c {
    char pad[0x6c];
    int key6c;
    int arr70[4];
    char pad2[0x84 - 0x80];
    int f84;
    int f88;
    int f8c;
};
struct Triple021f2e6c { int w[3]; };
struct Bufs021f2e6c { char* a; char* b; int c; };
struct Blk021f2e6c { int w[0x15]; };

extern "C" Table021f2e6c* _Z17GetGlobal02109418v(void);
extern "C" unsigned char* _Z26GetGlobalField0x1c020421a0v(void);
extern "C" void _Z24InitCombatEntry_021d8b6cPv(void* p);
extern "C" void func_ov023_021d8af8(void* p);
extern "C" void _Z21CopyShortTriple0x8e4aPvPsS0_S0_(void* obj, short* a, short* b, short* c);
extern "C" void* _Z21FindEntryById02096134P26FindEntryById02096134Tablei(Table021f2e6c* t, int id);
extern "C" void func_02046380(unsigned char* st);
extern "C" char* _Z14FindEntryByKeyP8TableA68i(void* table, int key);
extern "C" void _Z20Clear12Bytes020e46c4Pv(void* p);
extern "C" unsigned char* _Z25GetCombatantWithFlag0x400P9GameStatei(GameState* gs, int id);
extern "C" Triple021f2e6c func_ov023_021ed804(Triple021f2e6c t, void* p);
extern "C" void _Z26SetWords_021edf38_021edf38PvP13Words021edf38(Triple021f2e6c* dst, const Triple021f2e6c& src);
extern "C" void __clear(void* dst, int n);
extern "C" void _Z31DispatchIfCountPositive020dcf7ciPv(int count, void* buf);
extern "C" void _Z36ResetAndDispatchActorContext0209c6d8Pvs(void* actor, short arg);
extern "C" void func_0204500c(void* obj, char* buffer, int a, int b);
extern "C" void _Z28SetShortFields0x8e4aTo0x8e4ePviii(void* obj, int a, int b, int c);
extern "C" void* func_0202ae18(void);
extern "C" int func_0202c540(void* p);
extern "C" int _Z38AreAllListedCombatantsFlagged_021ed92cv(void);
extern "C" void _Z20ResetFields_021eefacP14Reset_021eefac(int* g);
extern "C" void _Z18InitStruct020d784cP14Buffer020d784c(IdList021f2e6c* list);
extern "C" int _Z17GetGlobal02109400v(void);
extern "C" void _Z21BlankFunction02094b40v(void);
extern "C" void _Z21BlankFunction02094b30v(int a, int b, int c);
extern "C" int func_ov023_021f4fc8(void);
extern "C" void _Z34RegisterCallbackObjectAndRunScriptPvS_P12StreamHeaderih(void* obj, void* alloc, void* data, int len, unsigned char flag);
extern "C" int _Z18AlwaysTrue02094b4cv(int p);
extern "C" short _Z22GetMaxOfHalfwords0And4P12Pair020deb08(void* p);
extern "C" void _Z16ZeroInit020de868Pv(void* p);
extern "C" void* ExtractFileFromGP2(const char* gp2Path, const char* innerFilePath, unsigned int* outSize);
extern "C" int func_020dea64(void* a, void* b, void* c, int d, void* e, int flag);
extern "C" int sprintf(char* buf, const char* fmt, ...);
extern "C" void* memcpy(void* dst, const void* src, unsigned int n);
extern "C" void _Z24InitStateManager0209e3dcPci(Mgr021f2e6c* mgr, void* p);
extern "C" void func_0209fd64(Mgr021f2e6c* mgr, SafeAllocator* alloc, void* data, unsigned int len);
extern "C" void _Z19ResetFields0209e46cPc(Mgr021f2e6c* mgr);
extern "C" void _Z21SetIntAt0x64_0209fe10P21IntField0x64_0209fe10i(Mgr021f2e6c* mgr, int v);
extern "C" void _Z21PollOv017Task0209fe18P17TaskState0209fe18(Mgr021f2e6c* mgr);
extern "C" char* _Z22FindValueByHalfwordKeyP8List794ci(IdList021f2e6c* list, int key);
extern "C" int _Z32AreFields64And68AllOnes_021f3a8cP17Fields64_021f3a8c(Mgr021f2e6c* mgr);
extern "C" void _Z17StoreInArray0x8b0P11StoreStructii(unsigned char* st, int index, int value);
extern "C" unsigned char* _Z26FindNodeByShortKey02162d88Pvs(void* self, unsigned short key);
extern "C" void _Z22ResetNameState02048614Ph(unsigned char* obj);
extern "C" void func_02049c88(unsigned char* obj, int v);
extern "C" void _Z28SetupFieldsFromParam02048850P11Obj02048850P13Param02048850(unsigned char* obj, int v);
extern "C" void _Z24CopyObjectFields02048588PhS_(unsigned char* src, unsigned char* dst);
extern "C" void _ZN8Object3D10SetField06Et(unsigned char* obj, unsigned short v);
extern "C" int _Z20SetByte0xbeShiftPrevP13Bytes02033b88i(unsigned char* obj, int v);
extern "C" void _ZN8Object3D17SetInheritedAlphaEi(unsigned char* obj, int v);
extern "C" void _ZN8Object3D11MakeVisibleEv(unsigned char* obj);
extern "C" void _Z20SetSubstructByte0x56Ph(unsigned char* obj);
extern "C" void* func_ov000_02160f14(void* self);
extern "C" void func_ov000_0216d370(void* cam, int a, int b, int c);
extern "C" void _Z22SetFlagOrState0216d530Pvi(void* cam, int v);
extern "C" int _ZNK8Object3D9GetHeightEv(unsigned char* obj);
extern "C" void _Z19SetFields0x10To0x18Phiii(void* cam, int a, int b, int c);
extern "C" void func_0202e5d8(void* cam, int a, int b, int c);
extern "C" void func_ov000_02163b90(void* self, int v);
extern "C" int _ZNK8Object3D17GetInheritedAlphaEv(unsigned char* obj);
extern "C" void _ZN8Object3D24TransitionInheritedAlphaEii(unsigned char* obj, int a, int b);
extern "C" void _ZN8Object3D10MakeHiddenEv(unsigned char* obj);
extern "C" void _Z22ClearSubstructByte0x56Ph(unsigned char* obj);
extern "C" Blk021f2e6c* _Z14GetPtrField0x4Pv(void* cam);
extern "C" void func_ov000_0216d2d0(void* cam);
extern "C" void _Z25CopyGroupedBlocks0202ed0cP11Dst0202ed0cP11Src0202ed0c(void* cam, Blk021f2e6c* src);

extern "C" int* _ZZ17GetGlobal021ffefcvE1s;
extern char data_02109bf4;
extern char data_ov023_021fe2ca;
extern char data_ov023_021fe2e5;
extern const char* data_020f2a38;
extern const char* data_020f2a30;
extern char data_ov023_021fd862;
extern char data_ov023_021fe2f7;

#if defined(jpn)
extern char data_ov023_021fd54e[];
extern char data_ov023_021fd578[];
extern char data_ov023_021fd5a2[];
extern "C" void* _Z28SearchWithComparator0206f4f0P30BinarySearchByComparatorStructi(void*,int);
extern "C" void _Z22SetIndexedName02046574P11Obj02046574iPc(void*,int,char*);
extern "C" void func_020de968(int,char*);
extern "C" void func_02045d88(void*,char*,int);
extern "C" int func_020e052c(void*,void*,const char*,void*,short,unsigned char);
#endif
// JPN: func_ov023_021f2590
// USA: func_ov023_021f2e6c
extern "C" ARM int func_ov023_021f2e6c(char* self) {
#if defined(jpn)
 enum {regionalOffset0=0x5778, regionalOffset1=0x5780, regionalOffset2=0x5784, regionalOffset3=0x57ac, regionalOffset4=0x577c, regionalOffset5=0x218, regionalOffset6=0x17e2, regionalOffset7=0x868, regionalOffset8=0xe28, regionalOffset9=0x57b0, regionalOffset10=0x2e4, regionalOffset11=0xe44, regionalOffset12=0x57aa, regionalOffset13=0x57ae, regionalOffset14=0x5788, regionalOffset15=0x57a8};
#else
 enum {regionalOffset0=0x5588, regionalOffset1=0x5590, regionalOffset2=0x5594, regionalOffset3=0x55bc, regionalOffset4=0x558c, regionalOffset5=0x29c, regionalOffset6=0x19b2, regionalOffset7=0x998, regionalOffset8=0xeac, regionalOffset9=0x55c0, regionalOffset10=0x228, regionalOffset11=0xec8, regionalOffset12=0x55ba, regionalOffset13=0x55be, regionalOffset14=0x5598, regionalOffset15=0x55b8};
#endif
    unsigned char* st;
    int* g = _ZZ17GetGlobal021ffefcvE1s;
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    Table021f2e6c* tbl = _Z17GetGlobal02109418v();
    st = _Z26GetGlobalField0x1c020421a0v();
    Entry021f2e6c* found_entries;
    int state = g[0];
    if (state == 0) {
        if (*(void**)(self + regionalOffset0) != 0) {
            _Z24InitCombatEntry_021d8b6cPv(*(void**)(self + regionalOffset0));
            func_ov023_021d8af8(*(void**)(self + regionalOffset0));
            *(void**)(self + regionalOffset0) = 0;
        }
        *(void**)(self + regionalOffset1) = 0;
        *(void**)(self + regionalOffset2) = 0;
        *(short*)(self + regionalOffset3) = 0;
        *(short*)(self + regionalOffset4) = -1;
        ((SafeAllocator*)(self + 0x30))->Reset();
        if (*(short*)(*(char**)(self + regionalOffset5) + 0x8e4a) > 0) {
            short kind = 0;
            short count = 0;
            short target = 0;
            _Z21CopyShortTriple0x8e4aPvPsS0_S0_(*(void**)(self + regionalOffset5), &kind, &target, &count);
            void* entry = _Z21FindEntryById02096134P26FindEntryById02096134Tablei(tbl, *(short*)(*(char**)(self + regionalOffset5) + 0x8e4a));
            if (count != 0 && entry != 0) {
                func_02046380(st);
#if defined(jpn)
                char* msg = data_ov023_021fd54e;
                if (kind == 0x12) msg = data_ov023_021fd578;
                void* name = _Z28SearchWithComparator0206f4f0P30BinarySearchByComparatorStructi(*(char**)(self + 0x21c) + 0x678, target);
                if (name != 0) _Z22SetIndexedName02046574P11Obj02046574iPc(st,0,*(char**)name);
                char rawName[0x40];
                __clear(rawName,0x40);
                func_020de968(count,rawName);
                _Z22SetIndexedName02046574P11Obj02046574iPc(st,1,rawName);
#else
                int key = 0x29;
                if (kind == 0x12) {
                    key = 0x2a;
                }
                char* msg = _Z14FindEntryByKeyP8TableA68i(self + 0x5904, key);
                Triple021f2e6c words;
                _Z20Clear12Bytes020e46c4Pv(&words);
                GameState* gs = GameState::GetInstance();
                for (int i = 0xc0; i <= 0xc7; i++) {
                    unsigned char* c = _Z25GetCombatantWithFlag0x400P9GameStatei(gs, i);
                    if (c != 0) {
                        void* p = *(void**)(c + 0x144);
                        if (target == *(short*)((char*)p + 8)) {
                            _Z26SetWords_021edf38_021edf38PvP13Words021edf38(&words, func_ov023_021ed804(words, p));
                            *(Triple021f2e6c**)(st + 0x20) = &words;
                            break;
                        }
                    }
                }
                char bufA[0x80];
                char bufB[0x80];
                Bufs021f2e6c bufs;
                __clear(bufA, 0x80);
                __clear(bufB, 0x80);
                _Z20Clear12Bytes020e46c4Pv(&bufs);
                bufs.a = bufA;
                bufs.b = bufB;
                _Z31DispatchIfCountPositive020dcf7ciPv(count, &bufs);
                *(Bufs021f2e6c**)(st + 0x18) = &bufs;

#endif
                _Z36ResetAndDispatchActorContext0209c6d8Pvs(&data_02109bf4, 0x3e);
#if defined(jpn)
                func_02045d88(st, msg, 1);
#else
                func_0204500c(st, msg, 1, 0xe3);
#endif

                st[regionalOffset6] = 0;
                *(int*)(st + regionalOffset7) = 1;
                _Z28SetShortFields0x8e4aTo0x8e4ePviii(*(void**)(self + regionalOffset5), kind, 0, 0);
                g[0] = 10;
                return *(int*)(self + regionalOffset8);
            }
        }
        if (func_0202c540(func_0202ae18()) != 0) {
            return 0xf;
        }
        if (_Z38AreAllListedCombatantsFlagged_021ed92cv() != 0 && *(short*)(*(char**)(self + regionalOffset5) + 0x8e4a) == 0) {
            return 0xf;
        }
        int count = tbl->count;
        Entry021f2e6c* entries = tbl->entries;
        int found = 0;
        for (int i = 0; i < count; i++) {
            if (entries[i].bits.b16 && !entries[i].bits.b15) {
                found = 1;
                break;
            }
        }
        if (found == 0) {
            _Z20ResetFields_021eefacP14Reset_021eefac(g);
            return 0xf;
        }
        *(IdList021f2e6c**)(self + regionalOffset2) = (IdList021f2e6c*)((SafeAllocator*)(self + 0x30))->Allocate(0x18);
        *(Mgr021f2e6c**)(self + regionalOffset1) = (Mgr021f2e6c*)((SafeAllocator*)(self + 0x30))->Allocate(0x8a0);
        _Z18InitStruct020d784cP14Buffer020d784c(*(IdList021f2e6c**)(self + regionalOffset2));
        *(SafeAllocator**)(self + regionalOffset9) = (SafeAllocator*)((SafeAllocator*)(self + 0x30))->Allocate(0x14);
        (*(SafeAllocator**)(self + regionalOffset9))->CreateTypeA(((SafeAllocator*)(self + 0x30))->Allocate(0xf000), 0xf000);
        int h = _Z17GetGlobal02109400v();
        _Z21BlankFunction02094b40v();
        _Z21BlankFunction02094b30v(h, 0x210, 1);
        g[0] = 1;
    } else if (state == 10) {
        if (func_ov023_021f4fc8() != 0) {
            g[0] = 0;
        }
    } else if (state == 11) {
#if defined(jpn)
        g[2] = loader->QueueLoadFile(data_ov023_021fd5a2, 0);
#else
        g[2] = loader->QueueLoadFileInGP2(&data_ov023_021fe2ca, &data_ov023_021fe2e5, 0);
#endif

        g[0]++;
        return *(int*)(self + regionalOffset8);
    } else if (state == 12) {
        if (loader->GetTaskStatus(g[2]) != 0) {
            unsigned int length;
            void* data;
            loader->GetLoadedFileByID(g[2], &data, &length);
            _Z18InitStruct020d784cP14Buffer020d784c(*(IdList021f2e6c**)(self + regionalOffset2));
            int count;
            Entry021f2e6c* entries = tbl->entries;
            count = tbl->count;
            for (int i = 0; i < count; i++) {
                if (entries[i].bits.b16 && !entries[i].bits.b15) {
                    int id = entries[i].bits.id;
                    IdList021f2e6c* list = *(IdList021f2e6c**)(self + regionalOffset2);
                    list->ids[list->count++] = id;
                }
            }
            _Z34RegisterCallbackObjectAndRunScriptPvS_P12StreamHeaderih(*(void**)(self + regionalOffset2), self + 0x30, data, length, 0);
            loader->RemoveTask(g[2]);
            g[2] = -1;
            g[0] = 4;
            *(short*)(self + regionalOffset3) = 1;
        }
    } else if (state == 1) {
        if (_Z18AlwaysTrue02094b4cv(_Z17GetGlobal02109400v()) != 0) {
            char* heap;
#if defined(jpn)
            char* sub = self + 0x3ec;
#else
            char* sub = self + 0x830;
#endif

#if defined(jpn)
            if (_Z22GetMaxOfHalfwords0And4P12Pair020deb08(sub + 0x3400) <= 0) {
#else
            if (_Z22GetMaxOfHalfwords0And4P12Pair020deb08(sub + 0x3000) <= 0) {
#endif

#if defined(jpn)
                _Z16ZeroInit020de868Pv(sub + 0x3400);
#else
                _Z16ZeroInit020de868Pv(sub + 0x3000);
#endif

                heap = self + regionalOffset10;
                ((SafeAllocator*)(heap + 0x5000))->Reset();
#if defined(jpn)
                func_020e052c(sub + 0x3400, heap + 0x5000, data_020f2a38, &data_ov023_021fd862, 3, 1);
#else
                BackgroundLoader::AddLockGlobal();
                unsigned int size;
                void* file = ExtractFileFromGP2(data_020f2a38, data_020f2a30, &size);
                if (file != 0) {
                    func_020dea64(sub + 0x3000, heap + 0x5000, file, size, &data_ov023_021fd862, 3);

                }
                BackgroundLoader::RemoveLockGlobal();
#endif

            }
            g[0] = 2;
        }
    } else if (state == 2) {
        found_entries = tbl->entries;
        int count = tbl->count;
        int found = 0;
        for (short i = *(short*)(self + regionalOffset4) + 1; i < count; i++) {
            if (func_0202c540(func_0202ae18()) != 0 || _Z38AreAllListedCombatantsFlagged_021ed92cv() != 0) {
                if (*(short*)(*(char**)(self + regionalOffset5) + 0x8e4a) != found_entries[i].bits.id) {
                    continue;
                }
            }
            if (found_entries[i].bits.b16 && !found_entries[i].bits.b15) {
                *(short*)(self + regionalOffset4) = i;
                found = 1;
                break;
            }
        }
        if (found == 0) {
            _Z20ResetFields_021eefacP14Reset_021eefac(g);
            return 0xf;
        }
        char name[0x40];
        sprintf(name, &data_ov023_021fe2f7, found_entries[*(short*)(self + regionalOffset4)].bits.id / 50 + 1);
        g[1] = loader->QueueLoadFile(name, 0);
        g[0] = 3;
    } else if (state == 3) {
        if (loader->GetTaskStatus(g[1]) != 0) {
            unsigned int length;
            void* data = 0;
            loader->GetLoadedFileByID(g[1], &data, &length);
            if (data == 0) {
                _Z20ResetFields_021eefacP14Reset_021eefac(g);
                return 0xf;
            }
            void* copy;
            found_entries = tbl->entries;
            (*(SafeAllocator**)(self + regionalOffset9))->Reset();
            copy = (*(SafeAllocator**)(self + regionalOffset9))->Allocate(length);
            memcpy(copy, data, length);
            loader->RemoveTask(g[1]);
            g[1] = -1;
            _Z24InitStateManager0209e3dcPci(*(Mgr021f2e6c**)(self + regionalOffset1), *(void**)(self + regionalOffset5));
            func_0209fd64(*(Mgr021f2e6c**)(self + regionalOffset1), *(SafeAllocator**)(self + regionalOffset9), copy, length);
            _Z19ResetFields0209e46cPc(*(Mgr021f2e6c**)(self + regionalOffset1));
            _Z21SetIntAt0x64_0209fe10P21IntField0x64_0209fe10i(*(Mgr021f2e6c**)(self + regionalOffset1), found_entries[*(short*)(self + regionalOffset4)].bits.id);
            g[0] = 4;
        }
    } else if (state == 4) {
        if (*(short*)(self + regionalOffset3) == 1) {
            *(short*)(self + regionalOffset3) = 2;
        } else {
            _Z21PollOv017Task0209fe18P17TaskState0209fe18(*(Mgr021f2e6c**)(self + regionalOffset1));
        }
        char* msg = 0;
        int key = (*(Mgr021f2e6c**)(self + regionalOffset1))->key6c;
        if (key > 0) {
            if (*(short*)(self + regionalOffset3) == 2) {
                msg = _Z22FindValueByHalfwordKeyP8List794ci(*(IdList021f2e6c**)(self + regionalOffset2), (short)key);
            } else {
                g[0] = 11;
                return *(int*)(self + regionalOffset8);
            }
        }
        if (_Z32AreFields64And68AllOnes_021f3a8cP17Fields64_021f3a8c(*(Mgr021f2e6c**)(self + regionalOffset1)) != 0 || msg != 0) {
            Entry021f2e6c* entries = tbl->entries;
            if (_Z32AreFields64And68AllOnes_021f3a8cP17Fields64_021f3a8c(*(Mgr021f2e6c**)(self + regionalOffset1)) != 0) {
                if (entries[*(short*)(self + regionalOffset4)].bits.b14) {
                    entries[*(short*)(self + regionalOffset4)].bits.b15 = 1;
                }
            }
            if (msg != 0) {
                func_02046380(st);
                for (int i = 0; i < 4; i++) {
                    _Z17StoreInArray0x8b0P11StoreStructii(st, i, (*(Mgr021f2e6c**)(self + regionalOffset1))->arr70[i]);
                }
#if defined(jpn)
                func_02045d88(st, _Z22FindValueByHalfwordKeyP8List794ci(*(IdList021f2e6c**)(self + regionalOffset2), (short)(*(Mgr021f2e6c**)(self + regionalOffset1))->key6c), 1);
#else
                func_0204500c(st, _Z22FindValueByHalfwordKeyP8List794ci(*(IdList021f2e6c**)(self + regionalOffset2), (short)(*(Mgr021f2e6c**)(self + regionalOffset1))->key6c), 1, 0xe3);
#endif

                st[regionalOffset6] = 0;
                *(int*)(st + regionalOffset7) = 1;
                int f84 = (*(Mgr021f2e6c**)(self + regionalOffset1))->f84;
                if (f84 > 0) {
                    unsigned char* node = _Z26FindNodeByShortKey02162d88Pvs(self, f84);
                    if (node != 0) {
                        GameState* gs = GameState::GetInstance();
                        int idx = 0xc0;
                        for (int i = 0xc0; i <= 0xc7; i++) {
                            unsigned char* c = _Z25GetCombatantWithFlag0x400P9GameStatei(gs, i);
                            if (c != 0 && *(int*)(c + 0x138) != 0) {
                                idx = i;
                                break;
                            }
                        }
                        unsigned char* obj = _Z25GetCombatantWithFlag0x400P9GameStatei(gs, idx);
                        int saved = *(int*)(obj + 0x138);
                        if (obj != 0 && saved != 0) {
                            int p13c = *(int*)(obj + 0x13c);
                            int p144 = *(int*)(obj + 0x144);
                            _Z22ResetNameState02048614Ph(obj);
                            *(short*)(obj + 4) = idx;
                            func_02049c88(obj, p13c);
                            _Z28SetupFieldsFromParam02048850P11Obj02048850P13Param02048850(obj, p144);
                            _Z24CopyObjectFields02048588PhS_(node, obj);
                            *(int*)(obj + 0x138) = saved;
                            _ZN8Object3D10SetField06Et(obj, *(unsigned short*)(self + regionalOffset11));
                            _Z20SetByte0xbeShiftPrevP13Bytes02033b88i(obj, 0);
                            obj[0xc2] |= 0x20;
                            _ZN8Object3D17SetInheritedAlphaEi(obj, 0x1f);
                            _ZN8Object3D11MakeVisibleEv(obj);
                            _Z20SetSubstructByte0x56Ph(obj);
                            void* cam = func_ov000_02160f14(self);
                            func_ov000_0216d370(cam, 1, 1, 1);
                            _Z22SetFlagOrState0216d530Pvi(cam, idx);
                            int height = _ZNK8Object3D9GetHeightEv(obj);
                            int y = (int)(((long long)height * 0x4cc + 0x800) >> 12);
                            if (y < 0) {
                                y = 0;
                            }
                            _Z19SetFields0x10To0x18Phiii(cam, 0, y, 0);
                            int z = (int)(((long long)height * 0x2333 + 0x800) >> 12);
                            int y2 = y + 0x800;
                            if (y2 < 0) {
                                y2 = 0;
                            }
                            func_0202e5d8(cam, 0, y2, z + 0x4000);
                            func_ov000_02163b90(self, 0);
                            *(short*)(self + regionalOffset12) = idx;
                        }
                    }
                }
                g[0]++;
            } else {
                g[0] = 6;
            }
        }
    } else if (state == 5) {
        int done = 0;
        if (func_ov023_021f4fc8() != 0 || *(unsigned char*)(self + regionalOffset13) != 0) {
            Mgr021f2e6c* mgr = *(Mgr021f2e6c**)(self + regionalOffset1);
            if (mgr->f84 > 0 && *(short*)(self + regionalOffset12) > 0) {
                if (mgr->f88 != 0) {
                    GameState* gs = GameState::GetInstance();
                    unsigned char* obj = (unsigned char*)gs->GetGameObjectByIndex(*(short*)(self + regionalOffset12));
                    if (obj != 0) {
                        int alpha = _ZNK8Object3D17GetInheritedAlphaEv(obj);
                        if (*(unsigned char*)(self + regionalOffset13) == 0 && alpha == 0x1f) {
                            _ZN8Object3D24TransitionInheritedAlphaEii(obj, 0, 500);
                            *(unsigned char*)(self + regionalOffset13) = 1;
                        }
                        if (alpha <= 0) {
                            _ZN8Object3D10MakeHiddenEv(obj);
                            _Z22ClearSubstructByte0x56Ph(obj);
                            *(unsigned char*)(self + regionalOffset13) = 0;
                            void* cam = func_ov000_02160f14(self);
                            Blk021f2e6c blk = *_Z14GetPtrField0x4Pv(cam);
                            func_ov000_0216d2d0(cam);
                            _Z25CopyGroupedBlocks0202ed0cP11Dst0202ed0cP11Src0202ed0c(cam, &blk);
                            _Z22ResetNameState02048614Ph(obj);
                            *(short*)(self + regionalOffset12) = 0;
                            done = 1;
                        }
                    }
                }
            } else {
                done = 1;
            }
        }
        if (done != 0) {
            if (_Z32AreFields64And68AllOnes_021f3a8cP17Fields64_021f3a8c(*(Mgr021f2e6c**)(self + regionalOffset1)) != 0) {
                g[0]++;
            } else {
                (*(Mgr021f2e6c**)(self + regionalOffset1))->key6c = -1;
                (*(Mgr021f2e6c**)(self + regionalOffset1))->f84 = 0;
                g[0] = 4;
            }
        }
    } else if (state == 6) {
        int v = (*(Mgr021f2e6c**)(self + regionalOffset1))->f8c;
        if (v != 0) {
            *(int*)(self + regionalOffset14 + *(short*)(self + regionalOffset15) * 4) = v;
            (*(short*)(self + regionalOffset15))++;
        }
        g[0] = 2;
    }
    return *(int*)(self + regionalOffset8);
}
