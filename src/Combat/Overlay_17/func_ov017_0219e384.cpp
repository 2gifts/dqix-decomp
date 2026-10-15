#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#include "World/ZoneChest.h"
#include "Combat/ActorAction.h"
#include "GameState/Overlay17DayCycle.h"
#include "Filesystem/BackgroundLoader.h"
#include "World/LootableContainer.h"
#include "GameState/GameState.h"

#if defined(jpn)
enum { Field23ec = 0x240c, Field840 = 0x860, Field44ae = 0x41fe, Field44ac = 0x41fc, Field42e9 = 0x40c9, Field3700 = 0x34f0, Field3704 = 0x34f4, Field36f8 = 0x34e8, Field3a9c = 0x388c, Field281f = 0x285f, Field3734 = 0x3524, Field23b8 = 0x23d8, Field1840 = 0x1860, Field36fc = 0x34ec, Field5cac = 0x5a4c, Field3718 = 0x3508, Field36d0 = 0x34c0, Field7f60 = 0x7c8c, Field2786 = 0x27c6, Field2784 = 0x27c4, Field2788 = 0x27c8, Field2774 = 0x27b4, Field2780 = 0x27c0, Field44b2 = 0x4202, WarpLow = 0xfe, WarpHigh = 0x4100 };
#else
enum { Field23ec = 0x23ec, Field840 = 0x840, Field44ae = 0x44ae, Field44ac = 0x44ac, Field42e9 = 0x42e9, Field3700 = 0x3700, Field3704 = 0x3704, Field36f8 = 0x36f8, Field3a9c = 0x3a9c, Field281f = 0x281f, Field3734 = 0x3734, Field23b8 = 0x23b8, Field1840 = 0x1840, Field36fc = 0x36fc, Field5cac = 0x5cac, Field3718 = 0x3718, Field36d0 = 0x36d0, Field7f60 = 0x7f60, Field2786 = 0x2786, Field2784 = 0x2784, Field2788 = 0x2788, Field2774 = 0x2774, Field2780 = 0x2780, Field44b2 = 0x44b2, WarpLow = 0xae, WarpHigh = 0x4400 };
#endif

#if defined(jpn)
enum { FieldRunValue = 0x54, MessageField = 0x228 };
#else
enum { FieldRunValue = 0x34, MessageField = 0x2d8 };
#endif

struct Vec3 { int v[3]; };

struct Seq0219e384 {
	unsigned char unk0;
	unsigned char done;
	unsigned char unk2[6];
	unsigned char state;
	unsigned char pending;
	unsigned char active;
	unsigned char expired;
	unsigned char unkc[2];
	unsigned short flagsE;
	unsigned short flags10;
	short v12;
	short v14;
	short v16;
	short v18;
	short v1a;
	short v1c;
	unsigned char v1e;
	unsigned char unk1f;
	unsigned char v20;
	unsigned char unk21;
	unsigned short timer;
	unsigned short warp;
	unsigned char unk26[2];
	int accum;
};

struct Field3f8 {
	int GetF24() const { SDK_NULL_ASSERT(this); return f24; }

	unsigned short mapId;
	unsigned char unk2[8];
	unsigned char active;
	unsigned char unkb;
	unsigned char mode;
	unsigned char flagD;
	unsigned char flagE;
	unsigned char unkf;
	int vec10[3];
	short s1c;
	short s1e;
	int f20;
	int f24;
	int f28;
	int f2c;
	unsigned char unk30[0x33];
	unsigned char f63;
	unsigned char f64;
	unsigned char unk65[2];
	unsigned char f67;
	unsigned char unk68;
	unsigned char f69;
	unsigned char unk6a[2];
	short f6c;
	unsigned char flags6e;
};

struct Combatant0219e384 {
	short GetId() const { SDK_NULL_ASSERT(this); return s4; }

	unsigned char unk0[4];
	short s4;
	unsigned char unk6[0x3e];
	int vec44[3];
	unsigned char unk50[4];
	int f54;
	unsigned char unk58[0x60];
	unsigned short b8;
	unsigned char unkba[4];
	unsigned char be;
	unsigned char unkbf[3];
	unsigned char c2;
	unsigned char unkc3[0x6d];
	unsigned int* p130;
	unsigned char unk134[0x2c];
	unsigned char unk160[6];
	unsigned short f166;
	unsigned char unk168[2];
	unsigned short f16a;
#if defined(jpn)
	unsigned char unk16c[0x3a];
#else
	unsigned char unk16c[0x46];
#endif
	unsigned short f1b2;
};

struct Npc0219e384 {
	unsigned char unk0[0xbe];
	unsigned char be;
	unsigned char unkbf[0x71];
	int mode;
	unsigned char unk134[0x32];
	unsigned short f166;
	unsigned char unk168[2];
	unsigned short f16a;
};

static inline int GetNpcMode(struct Npc0219e384* c) {
	return *(int*)((char*)c + 0x130);
}

struct HdrFlags4 {
	unsigned char noSkip : 1;
	unsigned char rest : 7;
};

struct GrottoSlot {
	unsigned char unk0[2];
	unsigned char used;
	unsigned char unk3[5];
	void* entry;
	unsigned char unkc[5];
	unsigned char kind;
	unsigned short value;
#if !defined(jpn)
	unsigned char unk14[4];
#endif
};

struct InlineEntry {
	unsigned char unk0[2];
	unsigned short slotIndex : 2;
	unsigned short unk2b : 2;
	unsigned short group : 12;
	unsigned short f4;
	unsigned char unk6[7];
	unsigned char fd;
#if defined(jpn)
	unsigned char unke[6];
#else
	unsigned char unke[0xa];
#endif
	int vec18[3];
	unsigned char unk24[0x10];
	int f34;
};

struct GrottoIds {
	unsigned char unk0[0xf78];
	unsigned char ids[4];
	unsigned char count;
	unsigned char flagF7d;
};

struct Msg021b6e70 {
	unsigned char kind;
	unsigned char actor;
	unsigned short id;
	unsigned short value;
	unsigned short f6;
	int f8;
	unsigned char fc;
	unsigned char fd;
	unsigned char fe;
	unsigned char ff;
	unsigned char f10;
	unsigned char f11;
	unsigned char f12;
	unsigned char f13;
	int f14;
};

struct NodeScratch {
	unsigned char unk0[0xc];
	int mapId;
	unsigned char unk10[0x24];
};

struct WorkLo {
	unsigned int size;
	unsigned int fileSize;
	void* buf;
	struct Msg021b6e70 msgF63;
	struct Msg021b6e70 msgF64;
	WrappedVector3fix warpVec;
	WrappedVector3fix memberVec;
	WrappedVector3fix fieldVec;
	WrappedVector3fix deltaVec;
};

struct WorkHi {
	WrappedVector3fix actorVec;
	signed char slot;
	unsigned char unk79[0x2b];
	struct NodeScratch node;
	struct Msg021b6e70 msg;
	WrappedVector3fix entryVec;
	WrappedVector3fix baseVec;
	char name[0x10];
	struct NodeScratch turnNode;
};

struct ListNode021bba08 {
	unsigned char unk0[2];
	unsigned char flag2;
	unsigned char unk3[5];
	unsigned short f8;
#if defined(jpn)
	unsigned char unka[0x8d];
#else
	unsigned char unka[0x91];
#endif
	unsigned char f9b;
	unsigned char f9c;
};

struct SafeAllocatorObj { unsigned char unk0[0x28]; };
struct Struct44C8;
struct SearchStruct;
struct BackgroundLoader;
struct SeqSlot { unsigned short a; unsigned short b; };

struct Field3f8* GetField0x3f8Address_0200fd0c(GameState*);
extern "C" void* func_02012fe4(void);
void* GetPtrField0x468_02011584(void* battle);
struct InlineEntry* GetEntryTableBase_02027ca4(void);
extern "C" void* func_0205ec34(void);
extern "C" struct SearchStruct* func_0202ae18(void);
void* GetDataPtr02114e04_020d6c00(void);
int GetByte0x26c_02039d7c(char* obj);
struct Vector3i;
extern "C" void func_02097cac(void* obj);
struct Obj0208f944;
void HandleGrottoTurnTransition0208f944(Obj0208f944*);
void ConfigureFieldVec3ForDateWindow_020a696c(void* obj, int a, int b);
struct SearchTable;
void* FindEntryByHalfwordKey_02099950(SearchTable*, int);
extern "C" int func_0209cd50(int id);
struct ShortField0xb8_0209cae8;
int GetShortAt0xb8(ShortField0xb8_0209cae8*);
struct Actor0209c678;
void DispatchContextByState0209c678(Actor0209c678*, int);
int IsScaledFieldPositive0203adfc(void* a, void* b);
void ScaleAndNotify0203ad88(void* a, void* b, int c);
struct AxisFloats0203b5f8;
int IsAxisIntZero(AxisFloats0203b5f8*, int);
struct GameResources;
int GetBrightnessTransitionStates(GameResources*);
struct AxisFloats0203b57c;
int GetAxisIntValue(AxisFloats0203b57c*, int);
void SetMainBrightness(GameResources*, int, int);
void SetBrightness(GameResources*, int, int);
struct Obj0205eaa0;
void DispatchWithShortB4_0205eaa0(Obj0205eaa0*, int, int);
struct Obj020397cc;
void CancelPendingAction020397cc(Obj020397cc*, int);
extern "C" void func_ov017_021c4664(int mapId, struct Vec3 v, int w);
extern "C" int func_0202c540(void* search);
int GetField0x397cValue_020100b0(GameState*);
void EnqueueEventTag150_021d035c(unsigned char a, unsigned char b, unsigned char c);
void EnqueueEventTag31_021d257c(unsigned char id, int a);
int LookupAndForEachNode020649b0(void* obj, int kind, void* out);
extern "C" void func_0206f81c(void* node);
int IsBrightnessTransitionActive(GameResources*);
int CheckSubstructByte0x7cPositive_020535c8(signed char* obj);
extern "C" void func_020531f0(void* obj);
int IsField0Null_02046b08(void** obj);
void* GetGlobalContext020daf90(void);
struct ListHead02046b60;
int ListContainsId(ListHead02046b60*, int);
int GetField0x50_020db2d4(void* obj);
void DispatchWithGlobalContext020daf9c(int a, int b, int c, int d);
int CheckField0NonZero_0202b7d8(int* obj);
struct SearchStruct0202c1a4;
void* GetSearchStructCurrentArrEntry(SearchStruct0202c1a4*);
int GetBitsInField0_0203b4c4(unsigned int*, unsigned int);
void SetFlagBitAt0xe_0202c5bc(struct SearchStruct* search, int v);
void SetBitsInField4_0203b4d8(unsigned int*, unsigned int);
void OrBitsIntoField0_020466e4(unsigned int*, unsigned int);
void SetBitsInWord_0203b4a0(unsigned int*, unsigned int);
extern "C" void func_ov017_0219d250(void* obj, unsigned char v);
int CountEntriesType2WithIds_020bc0f8(int a, int b);
extern "C" void func_ov017_0219c598(int a, int b, int c);
extern "C" int func_02028a54(struct InlineEntry* base, int id);
struct Entry_02028bd0;
struct InlineEntry* FindInlineEntryById(Entry_02028bd0*, int);
int IsInRange0201b588(int v);
struct Struct021b46d8;
void InitStruct_021b46d8(Struct021b46d8*);
int IsValueInRange0201b5d8(int v);
struct TailList020469b4;
struct TailNode020469b4;
void AppendNodeToTail(TailList020469b4*, TailNode020469b4*);
extern "C" int func_0202c508(void* search);
extern "C" void func_ov017_021c4854(Zone3D* run, int a, int b, int* vec, int c, int d);
int GetByteFieldMasked0x1ce_02039790(void* obj, int mask);
extern "C" void func_ov017_021bd4d0(void* obj, unsigned char index, int a, int b);
extern "C" void func_ov017_021ce400(unsigned char v, int mapId);
extern "C" void* func_0208e0a8(void);
extern "C" void func_0208e520(void* a, void* b);
extern "C" int sprintf(char* dst, const char* fmt, ...);
extern "C" char* strcpy(char* dst, const char* src);
int IsIdInRange020981e4(int, int);
int IsIdInSet02098210(int, int);
void* GetData02109020_0208e9e8(void);
signed char* GetFieldIfFlag4_020100f8(char*);
struct Actor0209c3b4;
void SetStateAndDispatch0209c3b4(Actor0209c3b4*, int);
struct Obj02086b98;
int AreListedCombatantsBit0Set(Obj02086b98*);
struct Obj0209caa0;
void SetFlag0x2AndNotify0209caa0(Obj0209caa0*, int);
void ClassifyPriceCategoryAndNotifyBattle_02064b98(unsigned char*, int);
struct FlagWord020466f4;
void ClearFlags020466f4(FlagWord020466f4*, unsigned int);
struct Obj0208f3a8;
void ClearFieldAt0xc0208f3a8(Obj0208f3a8*);
extern "C" void func_0206461c(void* a, void* b);
void* GetGlobal02109418_02094d6c(void);
extern "C" void func_02095b30(void* obj, int v);
extern "C" void func_02097ec8(void* obj);
extern "C" void func_ov017_021a2fa0(void* ov);
extern "C" void func_ov017_0219e180(void* ov, int mapId);
extern "C" void func_0208f168(void* obj, void* alloc);
extern "C" void _ZN8Object3D10SetField06Et(void* obj, int v);
extern "C" void func_0208fc30(void* obj);
struct Obj020733c8;
void ClearField0x8020733c8(Obj020733c8*);
extern "C" int func_02028460(int* vec, int* other);
void ClearBitsInField4_0203b4e8(unsigned int*, unsigned int);
void ClearBitsInWord_0203b4b0(unsigned int*, unsigned int);
extern "C" void _Z34SetupCombatantAllocations_021901acv(void* ov);
extern "C" void func_020a6aac(void* ov, int a, int b);
extern "C" void func_020acecc(void* ov, int a, int b);
int FindAndApplyEntryVec3_021a01f4(void* ov, int mapId, int index, void* combatant, int* out);
extern "C" void func_ov017_0219fc88(void* self, int v);
extern "C" void func_ov017_021b6f18(void* node);
void InitStruct_02196c08(unsigned char*);
int GetField0x3acValue_020100a8(GameState*);
extern "C" void func_ov017_021b6e70(struct Msg021b6e70* fnMsg, int v);
extern "C" void func_ov017_021b7104(void* node, struct Msg021b6e70* fnMsg);
int Dispatch020649f4(void* obj, void* out);
int LoadFileIntoMemory(const char* name, void* dst, unsigned int* size);
struct StreamHeader;
int InitStreamAndRun0208dc00(StreamHeader*, int, int);
int TestBitInByteArray_0206dfb0(int a, unsigned char* arr, int bit);
extern "C" void func_ov017_021bba08(struct ListNode021bba08* node, void* header);
void SetOrClearBitInArray_0206df6c(void* a, unsigned char* arr, int bit, int set);
void EnqueueEventTag158_021d23bc(unsigned short v);
void SetField0x246_020a2788(void* obj, short v);
struct Struct020a27cc;
void SetVec3ComponentsAndApply020a27cc(Struct020a27cc*);
struct Struct020A2800;
void ConfigureVec3AndApply020a2800(Struct020A2800*);
void InitVec3ParamsVariant8b33_020a2830(void* obj);
struct Struct020a2868;
void SetVec3ComponentsAndApply020a2868(Struct020a2868*);
struct S020a3570;
int GetField0x218(S020a3570*);
void CopyVec3ToField0x10AndCall0202e5d8_0202ec5c(char*, int*);
extern "C" void func_ov017_021982ac(void* ov);
void ApplyVecFromField0x246_020a2718(char*);
void SetCombatModeFromCase020dc2d0(int v);
struct ByteField0x2c5_020a2cbc;
void SetByteAt0x2c5(ByteField0x2c5_020a2cbc*, int);
extern "C" void func_020ae53c(int v);
void NotifyOv017OnFlag0x1130_020a8740(void);
void MarkActiveCombatantSlots02026b7c(unsigned char*);
void SyncVec3ForFlaggedCombatants_021a3338(void* ov);
void InitAndAppendState61_021a65c4(void* ov, unsigned char a, int b);
void EnqueueEventTag147_021cdaa0(void);
void SetByteField0x253_020397c0(void* obj);
void EnqueueEventTag35_021d2ad0(short, int, int, int, unsigned char);
void* GetGlobalField0x1c020421a0(void);
extern "C" void func_ov017_021a7a74(void* ov, struct Msg021b6e70* fnMsg);
int TrySetMode02076ccc(void* obj, int mode);
extern "C" void func_020a72ac(void* obj, unsigned char v);
void* GetGlobal02109030_020936f8(void);
extern "C" void func_02094030(void* obj, int a, int b, int c);

extern int data_02109bf4;
extern int data_02108760;
extern const char data_ov017_021d75fc[];
extern const char data_ov017_021d7619[];
extern const char data_ov017_021d761e[];
extern char data_0211e33c[];

// USA: func_ov017_0219e384
extern "C" ARM void func_ov017_0219e384(struct Seq0219e384* self, void* list) {
	GameState* battle = GameState::GetInstance();
	char* ov = (char*)func_ov017_0218b5b0();
	void* c3ac = battle->GetProtagonist();
	struct Combatant0219e384* actor = (struct Combatant0219e384*)battle->GetUnknownGameObject();
	struct Field3f8* fld = GetField0x3f8Address_0200fd0c(battle);
	struct BackgroundLoader* loader = BackgroundLoader::GetInstance();
	Zone3D* run = (Zone3D*)func_02012fe4();
	char* runSub = (char*)run + Field23ec;
	int runContext = (int)run + Field840;
	void* table468 = GetPtrField0x468_02011584(battle);
	struct InlineEntry* entryTable = GetEntryTableBase_02027ca4();
	void* obj5ec34 = func_0205ec34();
	struct GrottoIds* ids = (struct GrottoIds*)GetPtrField0x2a04_02010828(battle);
	struct SearchStruct* search = func_0202ae18();
	char* region = (char*)LootableContainerManager::GetMainInstance();
	void* flags14e04 = GetDataPtr02114e04_020d6c00();
	int* data7930 = (int*)LightingManager::GetInstance();
	struct WorkHi workHi;
	struct WorkLo workLo;

	if (self->state == 0) {
		SubBlock02038508* byte26c = GetFieldPtrAt0x26c_020399a8(actor);
		if (GetByte0x26c_02039d7c((char*)actor) != 0 && byte26c->command != 2 && fld->f6c != 9999) {
			if (fld->f67 != 0) {
				*(Vector3i*)fld->vec10 = *(Vector3i const*)actor->vec44;
			}
			return;
		}
		{
			int delta;
			int axis;
			int limit;
			void* obj;
			int runMapId;
			int cnt;
			unsigned short* warpSlot;
			void* found;
			unsigned char* hdr;

			func_02097cac((void*)runContext);
			HandleGrottoTurnTransition0208f944((Obj0208f944*)runSub);
			runMapId = run->currentZoneID_;
			ConfigureFieldVec3ForDateWindow_020a696c(ov, fld->mapId, runMapId);
			found = FindEntryByHalfwordKey_02099950((SearchTable*)table468, fld->mapId);
			hdr = (unsigned char*)run->pUnknownStruct_8_;
			self->active = 1;
			if (found != 0 && hdr != 0) {
				if (func_0209cd50(fld->mapId) == GetShortAt0xb8((ShortField0xb8_0209cae8*)&data_02109bf4)) {
					self->active = 0;
				}
			}
			if (fld->f20 > 0) {
				self->active = 0;
			}
			if (self->active != 0) {
				DispatchContextByState0209c678((Actor0209c678*)&data_02109bf4, 0);
			}
			if (IsScaledFieldPositive0203adfc(&data_02108760, 0) != 0) {
				ScaleAndNotify0203ad88(&data_02109bf4, 0, 0);
				self->active = 1;
			}
			cnt = *(unsigned short*)((char*)actor->p130 + 4);
			limit = 15;
			if (cnt <= 0) {
				limit = 60;
			}
			delta = -16;
			axis = 1;
			if (IsAxisIntZero((AxisFloats0203b5f8*)ov, 0) == 0 &&
			    IsAxisIntZero((AxisFloats0203b5f8*)ov, 1) == 0 &&
			    GetBrightnessTransitionStates((GameResources*)ov) != 0x101) {
				axis = 0;
				if (GetAxisIntValue((AxisFloats0203b57c*)ov, axis) > 0) {
					delta = 16;
				}
				limit = 0;
			}
			if ((fld->flags6e & 0x10) == 0) {
				if ((fld->flags6e & 1) != 0) {
					SetMainBrightness((GameResources*)ov, delta, limit);
				} else {
					SetBrightness((GameResources*)ov, delta, limit);
				}
			}
			if (fld->mode == 1) {
				DispatchWithShortB4_0205eaa0((Obj0205eaa0*)&data_02108760, 15, 0);
			}
			CancelPendingAction020397cc((Obj020397cc*)actor, 1);
			actor->c2 &= ~0x40;
			warpSlot = (unsigned short*)(ov + WarpLow);
			warpSlot = (unsigned short*)((char*)warpSlot + WarpHigh);
			*(unsigned short*)(ov + Field44ae) = 0;
			warpSlot[1] = 0;
			func_ov017_021c4664(fld->mapId, *(struct Vec3*)fld->vec10, fld->s1c);
			if (func_0202c540(search) != 0 && fld->f67 != 0 && *(unsigned short*)(ov + Field44ac) != 0) {
				*(unsigned short*)(ov + Field44ac) = 0;
			}
			if (fld->flagE != 0) {
				EnqueueEventTag150_021d035c(0, GetField0x397cValue_020100b0(battle), 1);
			}
			runMapId = run->currentZoneID_;
			if (fld->mapId != runMapId) {
				struct GrottoIds* list2a04 = (struct GrottoIds*)GetPtrField0x2a04_02010828(battle);
				int i;
				for (i = 0; i < list2a04->count; i++) {
					EnqueueEventTag31_021d257c(list2a04->ids[i], 0);
				}
			}
			if (*(unsigned char*)(ov + Field42e9) != 0) {
				fld->active = 0;
			}
			obj = func_0205ec34();
			workHi.turnNode.mapId = run->currentZoneID_;
			if (fld->active == 0 && LookupAndForEachNode020649b0(obj, 0x1e, &workHi.turnNode) != 0) {
				func_0206f81c(&workHi.turnNode);
			}
			if (axis == 0) {
				self->state = 2;
				return;
			}
			self->state = 1;
		}
		return;
	}
	if (self->state == 1) {
		if (IsBrightnessTransitionActive((GameResources*)ov) == 0) {
			self->state = 2;
		}
		return;
	}
	if (self->state == 2) {
		void* context;
		void** tail;
		if (actor != 0 && CheckSubstructByte0x7cPositive_020535c8((signed char*)actor) != 0) {
			func_020531f0(actor);
		}
		if (loader->GetNumQueuedTasks() > 0) {
			return;
		}
		if (IsField0Null_02046b08(*(void***)(ov + Field3700)) == 0) {
			return;
		}
		context = GetGlobalContext020daf90();
		tail = *(void***)(ov + Field3704);
		if (IsField0Null_02046b08(tail) == 0) {
			if (ListContainsId((ListHead02046b60*)tail, 0x4c) == 0) {
				return;
			}
			if (GetField0x50_020db2d4(context) != 0) {
				return;
			}
			DispatchWithGlobalContext020daf9c(1, 0, 1, 0);
			SetBrightness((GameResources*)ov, -16, 0);
			return;
		}
		if (CheckField0NonZero_0202b7d8((int*)search) != 0 &&
		    GetSearchStructCurrentArrEntry((SearchStruct0202c1a4*)search) != 0 &&
		    GetBitsInField0_0203b4c4((unsigned int*)ov, 2) == 0) {
#if !defined(jpn)
			self->accum = self->accum + battle->GetEffectiveDeltaTime();
			if (self->accum > 15000) {
				self->expired = 1;
				SetFlagBitAt0xe_0202c5bc(search, 0);
			}
#endif
			if (self->expired == 0) {
				return;
			}
#if !defined(jpn)
			self->accum = 0;
#endif
		}
		if (fld->flags6e != 1) {
			SetBitsInField4_0203b4d8((unsigned int*)ov, 1);
			OrBitsIntoField0_020466e4((unsigned int*)flags14e04, 1);
		}
		SetBitsInWord_0203b4a0((unsigned int*)ov, 0x10);
		func_ov017_0219d250(ov, self->pending);
		self->pending = 0;
		self->state = 3;
		return;
	}
	if (self->state == 3) {
		struct InlineEntry* table;
		int found;
		struct InlineEntry* entry;
		signed char* grotto;
		unsigned char kind;
		unsigned short value;
		char* runSub2;
		int hasFlag;

		if (CountEntriesType2WithIds_020bc0f8(0x64, 15) > 0) {
			return;
		}
		if (run->unknown_424_ != 0) {
			return;
		}
		if (loader->GetNumQueuedTasks() > 0) {
			return;
		}
		func_ov017_0219c598(0, 0, 0);
		table = GetEntryTableBase_02027ca4();
		found = func_02028a54(table, run->currentZoneID_);
		entry = FindInlineEntryById((Entry_02028bd0*)table, run->currentZoneID_);
		*(struct InlineEntry**)(ov + Field36f8) = entry;
		grotto = (signed char*)battle->GetGrottoStruct();
		if (IsInRange0201b588(run->currentZoneID_) != 0) {
			entry->fd = grotto[8];
		}
		kind = 0;
		value = 0;
		runSub2 = &((char*)run)[Field23ec];
		if (found != 0 && entry != 0) {
			void* tail = *(void**)(ov + Field3704);
			int off = entry->slotIndex;
			off *= sizeof(struct GrottoSlot);
			struct GrottoSlot* slot = (struct GrottoSlot*)(ov + Field3a9c + off);
			if (slot->used == 0) {
				InitStruct_021b46d8((Struct021b46d8*)slot);
				slot->entry = entry;
				if (IsValueInRange0201b5d8(run->currentZoneID_) != 0 && ((unsigned char*)grotto)[3] == 0) {
					unsigned char* detail = (unsigned char*)((ActiveGrottoClass*)runSub2)->GetDetailedData();
					if (detail != 0) {
						unsigned char tag = detail[1];
						if (tag == 1) {
							slot->kind = tag;
							slot->value = *(unsigned short*)(detail + 0x54);
						} else if (tag == 2) {
							slot->kind = tag;
							slot->value = ((DetailedTreasureMapData::LegacyBossMapData*)(detail + 0x4c))->MaybeGetCurrentAlternateID();
						}
						kind = slot->kind;
						value = slot->value;
					}
				}
				AppendNodeToTail((TailList020469b4*)tail, (TailNode020469b4*)slot);
			}
			self->state = 4;
		} else {
			if (IsValueInRange0201b5d8(run->currentZoneID_) != 0 && ((unsigned char*)grotto)[3] == 0) {
				unsigned char* detail = (unsigned char*)((ActiveGrottoClass*)runSub2)->GetDetailedData();
				if (detail != 0) {
					unsigned char tag = detail[1];
					if (tag == 1) {
						kind = tag;
						value = *(unsigned short*)(detail + 0x54);
					} else if (tag == 2) {
						kind = tag;
						value = ((DetailedTreasureMapData::LegacyBossMapData*)(detail + 0x4c))->MaybeGetCurrentAlternateID();
					}
				}
			}
			self->state = 5;
		}
		hasFlag = 0;
		if (func_0202c508(search) != 0 && *(unsigned char*)((char*)run + Field281f) != 0) {
			hasFlag = 1;
		}
		*(unsigned char*)((char*)run + Field281f) = 0;
		if (fld->f20 > 0 || fld->f24 > 0) {
			EnqueueEventTag150_021d035c(1, actor->s4, 1);
		}
		func_ov017_021c4854(run, kind, value, actor->vec44, (short)actor->f54, hasFlag);
		{
			void* target = *(void**)(ov + Field3734);
			if (CheckField0NonZero_0202b7d8((int*)search) != 0) {
				int i;
				for (i = 0; i < 4; i++) {
					void* c = battle->GetPartyMemberByIndex(i);
					if (c != 0 && GetByteFieldMasked0x1ce_02039790(c, 0x20) != 0) {
						func_ov017_021bd4d0(target, i, 0, 1);
					}
				}
			}
		}
		if (func_0202c508(search) != 0 && ids->flagF7d != 0) {
			func_ov017_021ce400(ids->flagF7d, run->currentZoneID_);
		}
		return;
	}
	if (self->state == 4) {
		if (IsField0Null_02046b08(*(void***)(ov + Field3704)) != 0) {
			self->state = 5;
		}
		return;
	}
	if (self->state == 5) {
		func_0208e520(func_0208e0a8(), run->pUnknownStruct_8_->mapShortName_);
		((SafeAllocator*)(ov + 0x18c))->Reset();
		((LootableContainerManager*)region)->Reset();
		data_ov017_021d75b8.lootableLoadTask = loader->QueueLoadFile(data_ov017_021d75fc, 0);
		self->state = 6;
		return;
	}
	if (self->state == 6) {
		if (loader->GetTaskStatus(data_ov017_021d75b8.lootableLoadTask) == 0) {
			return;
		}
		if (loader->GetDetailedTaskStatus(data_ov017_021d75b8.lootableLoadTask) == 2) {
			loader->GetLoadedFileByID(data_ov017_021d75b8.lootableLoadTask, &workLo.buf, &workLo.fileSize);
			if (workLo.buf != 0) {
				unsigned char* header = (unsigned char*)run->pUnknownStruct_8_;
				if (*(unsigned char*)((char*)run + Field23b8) != 0) {
					func_0201afd0(run, workLo.buf, workLo.fileSize, 0);
				} else {
					unsigned short id = *(unsigned short*)header;
					if (id >= 0xc546 && id <= 0xc546 + 0x15) {
						sprintf(workHi.name, data_ov017_021d7619, (char*)header + 5, id + (0x61 - 0xc546));
					} else {
						strcpy(workHi.name, (char*)header + 5);
					}
					((LootableContainerManager*)region)->LoadZoneContainers(workLo.buf, workLo.fileSize, workHi.name, (SafeAllocator*)0);
					func_0201647c(run);
				}
			}
		}
		loader->RemoveTask(data_ov017_021d75b8.lootableLoadTask);
		{
			unsigned short id = run->currentZoneID_;
			data_ov017_021d75b8.lootableLoadTask = -1;
			if (IsIdInRange020981e4((int)runContext, id) != 0 &&
			    IsIdInSet02098210((int)runContext, id) == 0 &&
			    func_0202c540(search) != 0) {
				unsigned char* sub = (unsigned char*)runContext;
				if (sub[0x1b62] == 0) {
					DispatchWithGlobalContext020daf9c(1, 0, 1, 0);
					SetBrightness((GameResources*)ov, -16, 0);
					self->state = 7;
					return;
				}
			}
		}
		self->state = 8;
		return;
	}
	if (self->state == 7) {
		unsigned char* sub = (unsigned char*)runContext;
		if (sub[0x1b62] != 0) {
			self->state = 8;
		}
		return;
	}
	if (self->state == 8) {
		void* tailList;
		void* obj09020;
		int mapId;
		int subId;
		unsigned char* header;
		char* runVars;
		struct InlineEntry* entry;
		signed char* flag4;
		int moving;
		struct ListNode021bba08* node;

		if (loader->GetNumQueuedTasks() > 0) {
			return;
		}
		if (func_0202c540(search) != 0 && fld->f67 != 0 && self->v20 == 0 && fld->f24 <= 0) {
			if (self->warp != 0xffff) {
				if (self->warp != 0) {
					fld->f24 = self->warp;
					fld->flagD = 1;
				} else if (*(unsigned short*)(ov + Field44ac) != 0) {
					fld->f24 = *(unsigned short*)(ov + Field44ac);
					*(unsigned short*)(ov + Field44ac) = 0;
				} else {
					self->timer = self->timer + battle->GetEffectiveDeltaTime();
					if (self->timer < 1000) {
						return;
					}
				}
			}
		}
		tailList = *(void**)(ov + Field36fc);
		obj09020 = GetData02109020_0208e9e8();
		mapId = run->currentZoneID_;
		subId = run->previousZoneID_;
		header = (unsigned char*)run->pUnknownStruct_8_;
		runVars = (char*)run + 0xc;
		entry = FindInlineEntryById((Entry_02028bd0*)entryTable, mapId);
		flag4 = GetFieldIfFlag4_020100f8((char*)battle);
		workHi.baseVec = *(WrappedVector3fix*)actor->vec44;
		moving = (fld->f20 > 0) ? 1 : 0;
		if (moving != 0) {
			self->active = 0;
		}
		node = *(struct ListNode021bba08**)(ov + Field3734);
		if (node->flag2 != 0 && node->f9b != 0) {
			self->active = 0;
			node->f9b = 0;
		} else if (fld->GetF24() >= 0) {
			int hasBit = ((*actor->p130 & 1) != 0);
			if (hasBit != 0) {
				if (fld->f24 < 21000 || fld->f24 >= 40000) {
					self->active = 1;
				}
			}
		}
		if (self->active != 0) {
			SetStateAndDispatch0209c3b4((Actor0209c3b4*)&data_02109bf4, func_0209cd50(mapId));
			if (CheckField0NonZero_0202b7d8((int*)search) != 0 && AreListedCombatantsBit0Set((Obj02086b98*)ids) != 0) {
				DispatchContextByState0209c678((Actor0209c678*)&data_02109bf4, 0);
			}
		}
		SetFlag0x2AndNotify0209caa0((Obj0209caa0*)&data_02109bf4, ((unsigned int)header[0xd] << 24) >> 31);
		ClassifyPriceCategoryAndNotifyBattle_02064b98((unsigned char*)obj5ec34, *(unsigned short*)header);
		ClearFlags020466f4((FlagWord020466f4*)flags14e04, 0x200000);
		if (fld->active == 0) {
			ClearFieldAt0xc0208f3a8((Obj0208f3a8*)obj09020);
			func_0206461c(obj5ec34, (unsigned char*)run->pUnknownStruct_8_);
			func_02095b30(GetGlobal02109418_02094d6c(), 0);
		}
		if (func_0202c508(search) != 0) {
			struct InlineEntry* e2 = FindInlineEntryById((Entry_02028bd0*)entryTable, run->currentZoneID_);
			if (e2 != 0) {
				SetElementFlagsFromMask02013cb0(run, e2->group);
				UpdateFlaggedType2Entries02018c74(run, e2->f4);
			}
		} else if (moving == 0 && *(unsigned char*)((char*)battle + Field5cac) == 0) {
			SetElementFlagsFromMask02013cb0(run, self->flagsE);
			UpdateFlaggedType2Entries02018c74(run, self->flags10);
		}
		func_02097ec8((char*)run + Field840);
		if ((fld->flags6e & 2) == 0) {
			func_ov017_021a2fa0(ov);
		}
		func_ov017_0219e180(ov, mapId);
		if (fld->active == 0) {
			struct SafeAllocatorObj* alloc = (struct SafeAllocatorObj*)(ov + 0x18c) + 1;
			((SafeAllocator*)alloc)->Reset();
			func_0208f168(obj09020, alloc);
		}
		_ZN8Object3D10SetField06Et(c3ac, mapId);
		func_0208fc30(runSub);
		if (entry != 0) {
			ClearField0x8020733c8((Obj020733c8*)entry);
			if (entry->f34 != 0) {
				actor->b8 = func_02028460(entry->vec18, actor->vec44);
				actor->c2 |= 0x40;
			}
		}
		ClearBitsInField4_0203b4e8((unsigned int*)ov, 1);
		ClearBitsInWord_0203b4b0((unsigned int*)ov, 0x10);
		_Z34SetupCombatantAllocations_021901acv(ov);
		func_020a6aac(ov, mapId, subId);
		func_020acecc(ov, mapId, subId);
		if ((fld->flags6e & 2) == 0 && func_0202c540(search) != 0 && actor != 0) {
			if (FindAndApplyEntryVec3_021a01f4(ov, mapId, battle->GetTimeOfDay(), actor, (int*)&workHi.entryVec) != 0 && actor != 0) {
				*(Vector3i*)actor->vec44 = *(Vector3i const*)((int*)&workHi.entryVec);
			}
		}
		if (moving != 0) {
			func_ov017_0219fc88(self, fld->f20);
		} else if (fld->f28 >= 0 && fld->f2c == run->currentZoneID_ && fld->s1e != fld->f28) {
			if (IsValueInRange0201b5d8(run->currentZoneID_) == 0) {
			void* n = *(void**)(ov + Field3718);
			func_ov017_021b6f18(n);
			InitStruct_02196c08((unsigned char*)&workHi.msg);
			workHi.msg.kind = 1;
			workHi.msg.actor = GetField0x3acValue_020100a8(battle);
			workHi.msg.value = fld->f28 + 5 + 0x8000;
			workHi.msg.id = 0xffff;
			workHi.msg.f8 = fld->f28;
			workHi.msg.f12 = data7930[0x26];
			func_ov017_021b6e70(&workHi.msg, workHi.msg.id);
			func_ov017_021b7104(n, &workHi.msg);
			AppendNodeToTail((TailList020469b4*)tailList, (TailNode020469b4*)n);
			fld->f28 = -1;
			fld->flags6e |= 1;
			ClearBitsInWord_0203b4b0((unsigned int*)ov, 0x800);
			}
		} else if (fld->f24 >= 0) {
			func_ov017_0219fc88(self, fld->f24);
		} else {
			void* obj2 = func_0205ec34();
			int listed;
			workHi.node.mapId = mapId;
			if (fld->active == 0 && Dispatch020649f4(obj2, &workHi.node) != 0) {
				func_0206f81c(&workHi.node);
			}
			listed = ListContainsId((ListHead02046b60*)tailList, 4);
			if (CheckField0NonZero_0202b7d8((int*)search) == 0 || func_0202c508(search) != 0) {
				BackgroundLoader::AddLockGlobal();
				if (LoadFileIntoMemory(data_ov017_021d761e, data_0211e33c, &workLo.size) != 0 &&
				    InitStreamAndRun0208dc00((StreamHeader*)data_0211e33c, workLo.size, (int)&workHi.slot) != 0 &&
				    TestBitInByteArray_0206dfb0((int)obj2, (unsigned char*)obj2 + 0x8c, workHi.slot + 0xea + 0xb00) == 0) {
					if (listed == 0) {
						struct ListNode021bba08* n2 = *(struct ListNode021bba08**)(ov + Field3734);
						func_ov017_021bba08(n2, (unsigned char*)run->pUnknownStruct_8_);
						n2->f8 = fld->f20;
						AppendNodeToTail((TailList020469b4*)tailList, (TailNode020469b4*)n2);
						fld->f20 = -1;
					} else {
						SetOrClearBitInArray_0206df6c(obj2, (unsigned char*)obj2 + 0x8c, workHi.slot + 0xea + 0xb00, 1);
					}
				}
				BackgroundLoader::RemoveLockGlobal();
			}
		}
		fld->s1e = -1;
		node = *(struct ListNode021bba08**)(ov + Field3734);
		if (node->flag2 == 0 || node->f9c != 0 || node->f8 == 0) {
			EnqueueEventTag158_021d23bc(0xffff);
		}
		if (fld->active == 0) {
			if (runVars != 0) {
				SetField0x246_020a2788(flag4, *(short*)(runVars + FieldRunValue));
			}
			switch (((unsigned int)header[0xc] << 25) >> 30) {
			case 0:
				SetVec3ComponentsAndApply020a27cc((Struct020a27cc*)flag4);
				break;
			case 1:
				ConfigureVec3AndApply020a2800((Struct020A2800*)flag4);
				break;
			case 2:
				InitVec3ParamsVariant8b33_020a2830(flag4);
				break;
			case 3:
				SetVec3ComponentsAndApply020a2868((Struct020a2868*)flag4);
				break;
			default:
				ConfigureVec3AndApply020a2800((Struct020A2800*)flag4);
				break;
			}
			if (GetField0x218((S020a3570*)flag4) != 0) {
				workHi.actorVec = *(WrappedVector3fix*)actor->vec44;
				workLo.fieldVec = *(WrappedVector3fix*)(flag4 + 0x10);
				Vector3fix_Subtract(&workHi.actorVec.vec, &workHi.baseVec.vec, &workLo.deltaVec.vec);
				Vector3fix_Add(&workLo.fieldVec.vec, &workLo.deltaVec.vec, &workLo.fieldVec.vec);
				CopyVec3ToField0x10AndCall0202e5d8_0202ec5c((char*)flag4, (int*)&workLo.fieldVec);
			}
			func_ov017_021982ac(ov);
			ApplyVecFromField0x246_020a2718((char*)flag4);
		}
		if ((fld->flags6e & 0x40) != 0) {
			ApplyVecFromField0x246_020a2718((char*)flag4);
		}
		if ((fld->flags6e & 1) == 0) {
			ClearFlags020466f4((FlagWord020466f4*)flags14e04, 1);
			SetCombatModeFromCase020dc2d0(0);
		}
		SetByteAt0x2c5((ByteField0x2c5_020a2cbc*)flag4, ((struct HdrFlags4*)(header + 4))->noSkip == 0 ? 1 : 0);
		func_020ae53c(1);
		NotifyOv017OnFlag0x1130_020a8740();
		MarkActiveCombatantSlots02026b7c((unsigned char*)(*(void**)(ov + Field36d0)));
		SyncVec3ForFlaggedCombatants_021a3338(ov);
		if ((fld->flags6e & 8) != 0) {
			self->state = 9;
			return;
		}
		{
			FontBankLoader* g400 = GetGlobal02109400_02094a00();
			func_02094ab0(g400);
			BlankFunction02094b34(g400, 0x6f, 5000, 1, 1);
		}
		self->state = 10;
		return;
	}
	if (self->state == 10) {
		if (AlwaysTrue02094b4c(GetGlobal02109400_02094a00()) != 0) {
			self->state = 9;
		}
		return;
	}
	if (self->state == 9) {
		int wantCounter;
		int wantByte;
		int i;

		if (fld->f69 != 0 && ListContainsId((ListHead02046b60*)list, 0x3d) == 0) {
			InitAndAppendState61_021a65c4(ov, 1, 0);
		}
		wantCounter = 1;
		wantByte = 1;
		if (ListContainsId((ListHead02046b60*)list, 4) != 0 ||
		    ListContainsId((ListHead02046b60*)list, 0xa) != 0 ||
		    ListContainsId((ListHead02046b60*)list, 0x3d) != 0) {
			wantCounter = 0;
			wantByte = 0;
		}
		if (ListContainsId((ListHead02046b60*)list, 0x2a) != 0 ||
		    ListContainsId((ListHead02046b60*)list, 0xf) != 0) {
			wantByte = 0;
		}
		if (ListContainsId((ListHead02046b60*)list, 0x2d) != 0) {
			wantCounter = 0;
		}
		if (func_0202c508(search) != 0) {
			EnqueueEventTag147_021cdaa0();
		}
		if (wantCounter != 0) {
			SetMainBrightness((GameResources*)ov, 0, 15);
		}
		if (wantByte != 0) {
			SetByteField0x253_020397c0(actor);
		}
		for (i = 0; i < ids->count; i++) {
			struct Combatant0219e384* c = (struct Combatant0219e384*)battle->GetPartyMemberByIndex(ids->ids[i]);
			if (c != 0 && GetByte0x26c_02039d7c((char*)c) != 0) {
				continue;
			}
			if (c != 0) {
				((Object3D*)c)->EnableFlag(0x4000000);
			}
			if (i > 0 && fld != 0 && fld->active == 0) {
				workLo.memberVec = *(WrappedVector3fix*)actor->vec44;
				*(Vector3i*)c->vec44 = *(Vector3i const*)((int*)&workLo.memberVec);
				if (fld->mapId == 10000) {
					workLo.memberVec.entries[0] = 0xff000;
					workLo.memberVec.entries[1] = 0;
					workLo.memberVec.entries[2] = 0xff000;
				}
				EnqueueEventTag35_021d2ad0(c->GetId(), workLo.memberVec.entries[0], workLo.memberVec.entries[1], workLo.memberVec.entries[2], 0);
			}
		}
		if (func_0202c508(search) != 0 && fld != 0 && fld->active == 0) {
			void* c;
			*(Vector3i*)((int*)((char*)battle + Field7f60)) = *(Vector3i const*)actor->vec44;
			c = battle->GetPartyMemberByIndex(0xce);
			if (c != 0) {
				int* src = (int*)((char*)battle + Field7f60);
				int z = src[2];
				int y = src[1];
				int x = *(int*)((char*)battle + Field7f60);
				((struct Combatant0219e384*)c)->vec44[0] = x;
				((struct Combatant0219e384*)c)->vec44[1] = y;
				((struct Combatant0219e384*)c)->vec44[2] = z;
			}
		}
		if (func_0202c508(search) != 0) {
			int* src = (int*)((char*)battle + Field7f60);
			EnqueueEventTag35_021d2ad0(0xce, *(int*)((char*)battle + Field7f60), src[1], src[2], 0);
		}
		if (fld != 0 && (fld->flags6e & 0x20) != 0) {
			func_ov017_0219c598(0, 0, 1);
		}
		*(int*)((char*)GetGlobalField0x1c020421a0() + MessageField) = 0;
		if (fld->f64 != 0) {
			GameState* battle2 = GameState::GetInstance();
			int* data2 = (int*)LightingManager::GetInstance();
			char* ov2 = (char*)func_ov017_0218b5b0();
			struct Combatant0219e384* c;
			func_ov017_021b6f18(*(void**)(ov2 + Field3718));
			c = (struct Combatant0219e384*)battle2->GetPartyMemberByIndex(0);
			InitStruct_02196c08((unsigned char*)&workLo.msgF64);
			workLo.msgF64.kind = 1;
			workLo.msgF64.actor = 0;
			workLo.msgF64.value = c->f1b2;
			workLo.msgF64.id = -1;
			workLo.msgF64.fe = 1;
			workLo.msgF64.f14 = 1;
			workLo.msgF64.f12 = data2[0x26];
			func_ov017_021b6e70(&workLo.msgF64, -1);
			func_ov017_021a7a74(ov2, &workLo.msgF64);
		} else if (fld->f63 != 0) {
			int j;
			int found2;
			unsigned short want;
			struct InlineEntry* slot;
			unsigned short id;
			int mapId2;
			int* data2;
			GameState* battle2;
			char* ov2;
			struct Combatant0219e384* lead;
			battle2 = GameState::GetInstance();
			data2 = (int*)LightingManager::GetInstance();
			ov2 = (char*)func_ov017_0218b5b0();
			lead = (struct Combatant0219e384*)GetCombatantWithFlag0x100_0200ff1c(battle2, 0);
			if (lead != 0 && lead->be == 2) {
				want = lead->f1b2;
				if (want != 0 && want >= 1 && want <= 0x7fff) {
					slot = *(struct InlineEntry**)(ov2 + Field36f8);
					if (slot != 0) {
						mapId2 = *(unsigned short*)slot;
						found2 = 0x7fff - 0x8000;
						for (j = 0; j < 12; j++) {
							struct Npc0219e384* c;
							found2 = j + (slot->slotIndex * 12 + 0x70);
							c = (struct Npc0219e384*)battle2->GetMaybeFieldMonsterByIndex(found2);
							if (c == 0) {
								continue;
							}
							id = c->f16a;
							if (id != want || c->be != 2) {
								continue;
							}
							if (c->be == 6) {
								continue;
							}
							if (((Object3D*)c)->IsVisible() == 0) {
								continue;
							}
							if (mapId2 != ((Object3D*)c)->GetField06()) {
								continue;
							}
							if (GetNpcMode(c) != 8 && GetNpcMode(c) != 9 && GetNpcMode(c) != 0) {
								c->f166 = GetField0x3acValue_020100a8(battle2);
								TrySetMode02076ccc(c, 8);
							}
							want = id;
							break;
						}
						if (found2 >= 0) {
							func_ov017_021b6f18(*(void**)(ov2 + Field3718));
							InitStruct_02196c08((unsigned char*)&workLo.msgF63);
							workLo.msgF63.kind = 1;
							workLo.msgF63.actor = GetField0x3acValue_020100a8(battle2);
							workLo.msgF63.value = want;
							workLo.msgF63.id = found2;
							func_ov017_021b6e70(&workLo.msgF63, found2);
							workLo.msgF63.f12 = data2[0x26];
							func_ov017_021a7a74(ov2, &workLo.msgF63);
						}
					}
				}
			}
		}
		if (self->v12 != 0) {
			Zone3D* run2 = (Zone3D*)func_02012fe4();
			*(unsigned short*)((char*)run2 + Field2786) = self->v12;
			if (((self->v14 << 18) >> 18) != -1) {
				*(unsigned short*)((char*)run2 + Field2784) = (self->v14 << 18) >> 18;
			}
			*(unsigned char*)((char*)run2 + Field2788) = (self->v14 << 16) >> 30;
			workLo.warpVec.entries[0] = self->v16 << 7;
			workLo.warpVec.entries[1] = self->v18 << 7;
			workLo.warpVec.entries[2] = self->v1a << 7;
			*(Vector3i*)((int*)((char*)run2 + Field2774)) = *(Vector3i const*)((int*)&workLo.warpVec);
			*(int*)((char*)run2 + Field2780) = self->v1c;
			func_020a72ac(run2, self->v1e);
			VectorizedMemset(&self->v12, 0, 0xe);
		}
		if (*(short*)(ov + Field44b2) >= 0) {
			void* g030 = GetGlobal02109030_020936f8();
			func_02094030(g030, *(short*)(ov + Field44b2), -1, 0);
			*(short*)(ov + Field44b2) = -1;
		}
		self->done = 1;
	}
}
