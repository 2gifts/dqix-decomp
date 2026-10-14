#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "World/Object3D.h"

int GetGlobalField0x1c020421a0(void);
unsigned char GetField0x397cValue_020100b0(GameState* battleStruct);
int GetSignedByte0x1c9_02039874(void* obj);
int GetIndexedEntryField0x178_02053604(signed char* obj);

extern "C" void func_020531f0(void* obj);
struct ObjectArchiveLoadInfo;
extern "C" void* func_02012fe4(void);
extern "C" void func_0205308c(void* obj, int val);
extern "C" void* func_0205ec34(void);
extern "C" void func_0206f81c(void* p);

struct Obj0205eaa0;
void DispatchWithShortB4_0205eaa0(struct Obj0205eaa0* obj, int a, int b);

void ForwardToTargetOrDefault0205eabc(void* obj, void* target, int arg);
int SetTargetFieldAndForEach02064a9c(void* param0, void* param1);
int GetFieldIfFlag4_020100f8(char* obj);
int TestFlag0SetAndFlag1Clear_02012444(unsigned short* obj, int mask);
void EnqueueEventTag6_021cc2f0(int);
void SetFlagsAt0x244_020a28a0(unsigned char* obj, unsigned char mask);
void ClearFlagBits_020a28b0(unsigned char* obj, int mask);

struct Params02036804 {
    int flag;
    void* data;
    unsigned int size;
    void* alloc;
    int one;
    int pad18;
    int pad1c;
    int pad20;
};

struct Entry02053634 { short id; short kind; };
extern struct Entry02053634 data_020e7c94[];

extern char data_020f0477;
extern char data_020f047e;
extern int data_02108760;
extern char data_020f0481;
extern unsigned short data_02114e30;
extern char data_020f0486;

#if defined(jpn)
#define OBJECT_OFFSET(offset) ((offset) - 0xc)
#define GLOBAL_ACTIVE_OFFSET 0x17e1
#else
#define OBJECT_OFFSET(offset) (offset)
#define GLOBAL_ACTIVE_OFFSET 0x19b1
#endif

// USA: func_02053634
extern "C" ARM void func_02053634(void* obj) {
    char* ctx = (char*)obj;
    GameState* bs = GameState::GetInstance();

    int hasEntries0 = ctx[OBJECT_OFFSET(0x17c)] > 0 ? 1 : 0;
    if (hasEntries0 != 0) {
        short cid0 = *(short*)(ctx + 4);
        int activeCid0 = GetField0x397cValue_020100b0(bs);
        if (activeCid0 == cid0
            && ((unsigned char*)GetGlobalField0x1c020421a0())[GLOBAL_ACTIVE_OFFSET] != 0) {
            func_020531f0(ctx);
            return;
        }
    }

    GameObject* combatant = bs->GetPartyMemberByIndex(*(short*)(ctx + 4));
    int hasEntries = ctx[OBJECT_OFFSET(0x17c)] > 0 ? 1 : 0;
    if (hasEntries != 0) {
        if (GetSignedByte0x1c9_02039874(combatant) > 0) {
            func_020531f0(ctx);
            return;
        }
    }

    signed char state = ctx[OBJECT_OFFSET(0x17e)];
    if (state == 0) {
        BackgroundLoader* loader = BackgroundLoader::GetInstance();
        if (loader->GetTaskStatus(*(int*)(ctx + OBJECT_OFFSET(0x180))) == 0) {
            return;
        }
        if (*(int*)(ctx + OBJECT_OFFSET(0x194)) >= 0) {
            if (loader->GetTaskStatus(*(int*)(ctx + OBJECT_OFFSET(0x194))) == 0) {
                return;
            }
        }

        int moreAvailable = 0;
        if (loader->GetDetailedTaskStatus(*(int*)(ctx + OBJECT_OFFSET(0x180))) != 2) {
            goto detailFail;
        }
        {
        ((Object3D*)ctx)->RemoveAnimationPackageByID(2);
        void* filePtr;
        unsigned int fileLen;
        loader->GetLoadedFileByID(*(int*)(ctx + OBJECT_OFFSET(0x180)), &filePtr, &fileLen);
        if (filePtr != 0) {
            void* base = *(void**)(ctx + OBJECT_OFFSET(0x154));
            void* alloc = (char*)base + 0x554;
            ((SafeAllocator*)alloc)->Reset();

            struct Params02036804 params;
            params.data = filePtr;
            params.flag = 0;
            params.pad18 = 0;
            params.pad1c = 0;
            params.size = fileLen;
            params.alloc = alloc;
            params.pad20 = 2;
            params.one = 1;
            if (((Object3D*)ctx)->LoadFromCCHROrCMOTArchive((ObjectArchiveLoadInfo*)&params, (int (*)(BCFG::AnimationRecord*))0) == 0) {
                goto loadFail;
            }
            if (((Object3D*)ctx)->MaybeSetRegularAnimation(&data_020f0477, 1) == 0) {
                if (((Object3D*)ctx)->MaybeSetRegularAnimation(&data_020f047e, 1) == 0) {
                    func_020531f0(ctx);
                    return;
                }
                ctx[OBJECT_OFFSET(0x17f)] = 1;
            } else {
                ctx[OBJECT_OFFSET(0x17f)] = 0;
            }

            if (ctx[OBJECT_OFFSET(0x17f)] == 0) {
                if (ctx[OBJECT_OFFSET(0x17d)] + 1 < ctx[OBJECT_OFFSET(0x17c)]) {
                    moreAvailable = 1;
                }
            }

            struct Entry02053634* e = data_020e7c94;
            for (; e->id > 0; e++) {
                if (e->id != GetIndexedEntryField0x178_02053604((signed char*)ctx)) continue;
                void* arg2 = 0;
                if (e->kind == 0x4e) {
                    arg2 = ctx + OBJECT_OFFSET(0x198);
                }
                unsigned short val = *(unsigned short*)func_02012fe4();
                if (val == ((Object3D*)ctx)->GetField06()) {
                    DispatchWithShortB4_0205eaa0((struct Obj0205eaa0*)&data_02108760, e->kind, (int)arg2);
                }
                break;
            }
            ctx[OBJECT_OFFSET(0x17e)] = 1;
            goto loadOK;
        loadFail:
            func_020531f0(ctx);
            return;
        } else {
            goto loadOK;
        }
    loadOK:
        ctx[OBJECT_OFFSET(0x185)] = 1;
        goto detailOK;
    detailFail:
        func_020531f0(ctx);
        return;
        }
    detailOK:
        loader->RemoveTask(*(int*)(ctx + OBJECT_OFFSET(0x180)));
        *(int*)(ctx + OBJECT_OFFSET(0x180)) = -1;
        if (moreAvailable != 0) {
            if (*(unsigned char*)(ctx + OBJECT_OFFSET(0x185)) != 0) {
                ctx[OBJECT_OFFSET(0x186)] = 1;
            } else {
                signed char idx = ctx[OBJECT_OFFSET(0x17d)];
                char* p = ctx + (idx + 1) + 0x100;
                func_0205308c(ctx, p[OBJECT_OFFSET(0x78)]);
            }
        }
    } else {
        if (state == 1) {
            if (((Object3D*)ctx)->HasAnimationStopped() == 0) {
                return;
            }
            if (ctx[OBJECT_OFFSET(0x17f)] == 0) {
                ctx[OBJECT_OFFSET(0x17d)] = ctx[OBJECT_OFFSET(0x17d)] + 1;
                if (ctx[OBJECT_OFFSET(0x17d)] < ctx[OBJECT_OFFSET(0x17c)]) {
                    ctx[OBJECT_OFFSET(0x17e)] = 0;
                    *(int*)(ctx + OBJECT_OFFSET(0x190)) = 0;
                    return;
                }
                short cid = *(short*)(ctx + 4);
                if (cid == GetField0x397cValue_020100b0(bs)) {
                    void* p = func_0205ec34();
                    unsigned char req[0x34];
                    for (int i = 0; i < 4; i++) {
                        char* q = ctx + i + 0x100;
                        ((signed char*)(req + 0x2a))[i] = q[OBJECT_OFFSET(0x78)];
                    }
                    if (SetTargetFieldAndForEach02064a9c(p, req) != 0) {
                        func_0206f81c(req);
                    }
                }
                func_020531f0(ctx);
                return;
            } else if (ctx[OBJECT_OFFSET(0x17f)] == 1) {
                int mode = 0;
                if (ctx[OBJECT_OFFSET(0x17c)] > 1) {
                    mode = 1;
                    if (GetIndexedEntryField0x178_02053604((signed char*)ctx) == 0x19) {
                        ForwardToTargetOrDefault0205eabc((void*)&data_02108760, ctx + OBJECT_OFFSET(0x198), 0);
                    }
                }
                if (((Object3D*)ctx)->MaybeSetRegularAnimation(&data_020f0481, mode) != 0) {
                    ctx[OBJECT_OFFSET(0x17e)] = 2;
                    return;
                }
                func_020531f0(ctx);
                return;
            } else {
                func_020531f0(ctx);
                return;
            }
        } else if (state == 2) {
            bs = GameState::GetInstance();
            int target = GetFieldIfFlag4_020100f8((char*)bs);
            int flag = 0;
            if (ctx[OBJECT_OFFSET(0x17c)] > 1) {
                if (((Object3D*)ctx)->HasAnimationStopped() != 0) {
                    flag = 1;
                }
            } else {
                short cid = *(short*)(ctx + 4);
                if (cid == GetField0x397cValue_020100b0(bs)
                    && TestFlag0SetAndFlag1Clear_02012444(&data_02114e30, 0xc03) != 0) {
                    flag = 1;
                    EnqueueEventTag6_021cc2f0(*(short*)(ctx + 4));
                } else {
                    if (*(unsigned char*)(ctx + OBJECT_OFFSET(0x184)) != 0) {
                        ctx[OBJECT_OFFSET(0x184)] = *(unsigned char*)(ctx + OBJECT_OFFSET(0x184)) - 1;
                        flag = 1;
                    } else if (target != 0) {
                        SetFlagsAt0x244_020a28a0((unsigned char*)target, 1);
                    }
                }
                if (flag != 0 && target != 0) {
                    ClearFlagBits_020a28b0((unsigned char*)target, 1);
                }
            }
            if (flag == 0) {
                return;
            }
            if (((Object3D*)ctx)->MaybeSetRegularAnimation(&data_020f0486, 1) == 0) {
                func_020531f0(ctx);
                return;
            }
            {
                signed char cursor = ctx[OBJECT_OFFSET(0x17d)];
                signed char count = ctx[OBJECT_OFFSET(0x17c)];
                int next = cursor + 1;
                if (next < count) {
                    char* q = ctx + next + 0x100;
                    func_0205308c(ctx, q[OBJECT_OFFSET(0x78)]);
                }
            }
            ctx[OBJECT_OFFSET(0x17e)] = 3;
            return;
        } else if (state == 3) {
            if (((Object3D*)ctx)->HasAnimationStopped() == 0) {
                return;
            }
            if (GetIndexedEntryField0x178_02053604((signed char*)ctx) == 0x19) {
                ForwardToTargetOrDefault0205eabc((void*)&data_02108760, ctx + OBJECT_OFFSET(0x198), 0);
            }
            ctx[OBJECT_OFFSET(0x17d)] = ctx[OBJECT_OFFSET(0x17d)] + 1;
            if (ctx[OBJECT_OFFSET(0x17d)] < ctx[OBJECT_OFFSET(0x17c)]) {
                ctx[OBJECT_OFFSET(0x17e)] = 0;
                *(int*)(ctx + OBJECT_OFFSET(0x190)) = 0;
                return;
            }
            short cid = *(short*)(ctx + 4);
            if (cid == GetField0x397cValue_020100b0(bs)) {
                void* p = func_0205ec34();
                unsigned char req[0x34];
                for (int i = 0; i < 4; i++) {
                    char* q = ctx + i + 0x100;
                    ((signed char*)(req + 0x2a))[i] = q[OBJECT_OFFSET(0x78)];
                }
                if (SetTargetFieldAndForEach02064a9c(p, req) != 0) {
                    func_0206f81c(req);
                }
            }
            func_020531f0(ctx);
            return;
        }
    }
}
