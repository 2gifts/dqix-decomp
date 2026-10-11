#include <globaldefs.h>

struct Pair021d4a64 {
	int type;
	union { int i; float f; };
};

struct Instr021d4e38 {
	int op;
	int arg;
	union { int aux; float auxf; };
};

struct Interp021d4e38 {
	unsigned char pad00[0x14];
	Pair021d4a64* stack;
	unsigned char pad18[4];
	int globals;
	unsigned char pad20[4];
	int callBase;
	int callTop;
	unsigned char pad2c[4];
	int frame;
	void* typeInfo;
	Instr021d4e38* pc;
	int stopped;
	int suspended;
	unsigned char pad44[4];
	int code;
	int result;
	int steps;
};

struct S1_021d4a38;
struct S1_021d4a78;
struct S1_021d4a98;
struct S1_021d4ab8;
struct Obj021d4b9c;
struct A021d4bc8;
struct B021d4bc8;
struct Ctx021d4af8;
struct Arg021d4af8;

extern "C" extern void _Z25EnqueuePairEntry_021d4a38P11S1_021d4a3812Pair021d4a64(S1_021d4a38* obj, Pair021d4a64 v);
extern "C" extern void _Z17CopyPair_021d4a64P12Pair021d4a64S0_(Pair021d4a64* dst, Pair021d4a64* src);
extern "C" extern void _Z28SetEntryAndAdvance0_021d4a78P11S1_021d4a78i(S1_021d4a78* obj, int v);
extern "C" extern void _Z28SetEntryAndAdvance2_021d4a98P11S1_021d4a98i(S1_021d4a98* obj, int v);
extern "C" extern void _Z28SetEntryAndAdvance3_021d4ab8P11S1_021d4ab8i(S1_021d4ab8* obj, int v);
extern "C" extern int _Z22PopStackEntry_021d4b9cP11Obj021d4b9c(Obj021d4b9c* obj);
extern "C" extern void _Z32DispatchIndexedCallback_021d4bc8P9A021d4bc8P9B021d4bc8i(A021d4bc8* a, B021d4bc8* b, int c);
extern "C" int func_ov017_021d4af8(Ctx021d4af8* self, Arg021d4af8* arg, int retAddr);

// 021d4980, 021d49ac and 021d4ad8 are committed under the parameter lists their callee-side
// reconstructions used. This caller needs the real ones — an operand, an operand plus the type
// table, and a float — so bind the committed mangled names directly.
extern "C" int _Z18OrNonZero_021d49ac9S021d49ac(Pair021d4a64 v);
extern "C" int _Z23CallHelperIfF0_021d498014Struct021d4980(Pair021d4a64 v, void* typeInfo);
extern "C" void _Z28SetEntryAndAdvance1_021d4ad8P11S1_021d4ad8i(Interp021d4e38* self, float v);

extern "C" void func_0200159c(int code) __attribute__((noreturn));
extern "C" void func_02001878(void* text);
// Spelled as an explicit call because mwcc's implicit float->double conversion binds `_f2d`,
// which this ROM does not export under that name.
extern "C" double func_0200c578(float v);
extern "C" float _d2f(double v);
extern "C" double func_02009424(double v);
extern "C" double func_02008dcc(double v);
extern int data_020eec2c;

#define IsTruthy _Z18OrNonZero_021d49ac9S021d49ac
#define Resolve _Z23CallHelperIfF0_021d498014Struct021d4980
#define PushFloat _Z28SetEntryAndAdvance1_021d4ad8P11S1_021d4ad8i
#define PushInt(s, v) _Z28SetEntryAndAdvance0_021d4a78P11S1_021d4a78i((S1_021d4a78*)(s), (v))
#define PushCode(s, v) _Z28SetEntryAndAdvance2_021d4a98P11S1_021d4a98i((S1_021d4a98*)(s), (v))
#define PushRef(s, v) _Z28SetEntryAndAdvance3_021d4ab8P11S1_021d4ab8i((S1_021d4ab8*)(s), (v))
#define Push(s, v) _Z25EnqueuePairEntry_021d4a38P11S1_021d4a3812Pair021d4a64((S1_021d4a38*)(s), (v))

#define SlotPtr(base, idx) (((Pair021d4a64*)(base)) + (idx))
#define Slot(base, idx) (*SlotPtr((base), (idx)))

inline Pair021d4a64 Pop(Interp021d4e38* self) {
	self->stack--;
	return *self->stack;
}

// Case 20 walks the operands it drops with a cursor it never reads; keeping that cursor is what
// puts the cursor in a callee-saved register and the diagnostic text alongside it.
#pragma opt_dead_assignments off

// USA: func_ov017_021d4e38
extern "C" ARM void func_ov017_021d4e38(Interp021d4e38* self, Instr021d4e38* start) {
	Pair021d4a64 stmp, rhs, lhs;

	self->pc = start;
	for (;;) {
		switch (self->pc->op) {
		case 1:
			switch (self->pc->aux) {
			case 1:
				Push(self, Slot(self->frame, self->pc->arg));
				break;
			case 0x40:
				Push(self, Slot(self->globals, self->pc->arg));
				break;
			case 2: {
				int idx = Resolve(Pop(self), self->typeInfo);
				Push(self, SlotPtr(self->frame, self->pc->arg)[idx]);
				break;
			}
			case 4: {
				int idx = Resolve(Pop(self), self->typeInfo);
				Push(self, Slot(Slot(self->frame, self->pc->arg).i, idx));
				break;
			}
			case 8:
				Slot(self->frame, self->pc->arg).type = 1;
				Push(self, Slot(self->frame, self->pc->arg));
				break;
			case 0x200:
				Slot(self->globals, self->pc->arg).type = 1;
				Push(self, Slot(self->globals, self->pc->arg));
				break;
			case 0x10: {
				int idx = Resolve(Pop(self), self->typeInfo);
				SlotPtr(self->frame, self->pc->arg)[idx].type = 1;
				Push(self, SlotPtr(self->frame, self->pc->arg)[idx]);
				break;
			}
			case 0x20: {
				int idx = Resolve(Pop(self), self->typeInfo);
				Slot(Slot(self->frame, self->pc->arg).i, idx).type = 1;
				Push(self, Slot(Slot(self->frame, self->pc->arg).i, idx));
				break;
			}
			}
			break;

		case 2:
			switch (self->pc->aux) {
			case 1:
				PushRef(self, (int)SlotPtr(self->frame, self->pc->arg));
				break;
			case 0x40:
				PushRef(self, (int)SlotPtr(self->globals, self->pc->arg));
				break;
			case 2: {
				int idx = Resolve(Pop(self), self->typeInfo);
				PushRef(self, (int)(SlotPtr(self->frame, self->pc->arg) + idx));
				break;
			}
			case 4: {
				int idx = Resolve(Pop(self), self->typeInfo);
				PushRef(self, (int)SlotPtr(Slot(self->frame, self->pc->arg).i, idx));
				break;
			}
			case 8:
				PushRef(self, (int)SlotPtr(self->frame, self->pc->arg));
				break;
			case 0x200:
				PushRef(self, (int)SlotPtr(self->globals, self->pc->arg));
				break;
			case 0x10: {
				int idx = Resolve(Pop(self), self->typeInfo);
				PushRef(self, (int)(SlotPtr(self->frame, self->pc->arg) + idx));
				break;
			}
			case 0x20: {
				int idx = Resolve(Pop(self), self->typeInfo);
				PushRef(self, (int)SlotPtr(Slot(self->frame, self->pc->arg).i, idx));
				break;
			}
			}
			break;

		case 5:
			stmp = Pop(self);
			_Z17CopyPair_021d4a64P12Pair021d4a64S0_((Pair021d4a64*)Pop(self).i, &stmp);
			Push(self, stmp);
			break;

		case 3:
			if (self->pc->arg == 1) {
				PushInt(self, self->pc->aux);
			} else if (self->pc->arg == 3) {
				PushCode(self, self->code + self->pc->aux);
			} else if (self->pc->arg == 2) {
				PushFloat(self, self->pc->auxf);
			}
			break;

		case 4:
			self->stack--;
			break;

		case 16:
			if (self->suspended == 0) {
				self->pc = (Instr021d4e38*)(self->code + self->pc->arg);
				continue;
			}
			break;

		case 18:
			if (self->suspended != 0) {
				break;
			}
			if (IsTruthy(Pop(self))) {
				if (self->pc->aux != 0) {
					PushInt(self, 1);
				}
				self->pc = (Instr021d4e38*)(self->code + self->pc->arg);
				continue;
			}
			break;

		case 17:
			if (self->suspended != 0) {
				break;
			}
			if (!IsTruthy(Pop(self))) {
				if (self->pc->aux != 0) {
					PushInt(self, 0);
				}
				self->pc = (Instr021d4e38*)(self->code + self->pc->arg);
				continue;
			}
			break;

		case 14:
			rhs = Pop(self);
			lhs = Pop(self);
			if (lhs.type == 0 && rhs.type == 0) {
				switch (self->pc->arg) {
				case 0x28: PushInt(self, rhs.i == lhs.i); break;
				case 0x29: PushInt(self, rhs.i != lhs.i); break;
				case 0x2a: PushInt(self, lhs.i < rhs.i); break;
				case 0x2b: PushInt(self, lhs.i <= rhs.i); break;
				case 0x2c: PushInt(self, lhs.i > rhs.i); break;
				case 0x2d: PushInt(self, lhs.i >= rhs.i); break;
				}
			} else {
				float rf, lf;
				if (lhs.type == 1 && rhs.type == 1) {
					rf = rhs.f;
					lf = lhs.f;
				} else if (lhs.type == 0 && rhs.type == 1) {
					rf = rhs.f;
					lf = (float)lhs.i;
				} else if (lhs.type == 1 && rhs.type == 0) {
					rf = (float)rhs.i;
					lf = lhs.f;
				} else {
					func_0200159c(-1);
				}
				switch (self->pc->arg) {
				case 0x28: PushInt(self, rf == lf); break;
				case 0x29: PushInt(self, rf != lf); break;
				case 0x2a: PushInt(self, lf < rf); break;
				case 0x2b: PushInt(self, lf <= rf); break;
				case 0x2c: PushInt(self, lf > rf); break;
				case 0x2d: PushInt(self, lf >= rf); break;
				}
			}
			break;

		case 6:
			rhs = Pop(self);
			lhs = Pop(self);
			if (lhs.type == 0 && rhs.type == 0) {
				PushInt(self, lhs.i + rhs.i);
			} else if (lhs.type == 1 && rhs.type == 1) {
				PushFloat(self, lhs.f + rhs.f);
			} else if (lhs.type == 0 && rhs.type == 1) {
				PushFloat(self, (float)lhs.i + rhs.f);
			} else if (lhs.type == 1 && rhs.type == 0) {
				PushFloat(self, lhs.f + (float)rhs.i);
			} else {
				func_0200159c(-1);
			}
			break;

		case 7:
			rhs = Pop(self);
			lhs = Pop(self);
			if (lhs.type == 0 && rhs.type == 0) {
				PushInt(self, lhs.i - rhs.i);
			} else if (lhs.type == 1 && rhs.type == 1) {
				PushFloat(self, lhs.f - rhs.f);
			} else if (lhs.type == 0 && rhs.type == 1) {
				PushFloat(self, (float)lhs.i - rhs.f);
			} else if (lhs.type == 1 && rhs.type == 0) {
				PushFloat(self, lhs.f - (float)rhs.i);
			} else {
				func_0200159c(-1);
			}
			break;

		case 8:
			rhs = Pop(self);
			lhs = Pop(self);
			if (lhs.type == 0 && rhs.type == 0) {
				PushInt(self, lhs.i * rhs.i);
			} else if (lhs.type == 1 && rhs.type == 1) {
				PushFloat(self, lhs.f * rhs.f);
			} else if (lhs.type == 0 && rhs.type == 1) {
				PushFloat(self, (float)lhs.i * rhs.f);
			} else if (lhs.type == 1 && rhs.type == 0) {
				PushFloat(self, lhs.f * (float)rhs.i);
			} else {
				func_0200159c(-1);
			}
			break;

		case 9:
			rhs = Pop(self);
			lhs = Pop(self);
			if (lhs.type == 0 && rhs.type == 0) {
				PushInt(self, lhs.i / rhs.i);
			} else if (lhs.type == 1 && rhs.type == 1) {
				PushFloat(self, lhs.f / rhs.f);
			} else if (lhs.type == 0 && rhs.type == 1) {
				PushFloat(self, (float)lhs.i / rhs.f);
			} else if (lhs.type == 1 && rhs.type == 0) {
				PushFloat(self, lhs.f / (float)rhs.i);
			} else {
				func_0200159c(-1);
			}
			break;

		case 10: {
			int r = Resolve(Pop(self), self->typeInfo);
			int l = Resolve(Pop(self), self->typeInfo);
			PushInt(self, l % r);
			break;
		}

		case 24: {
			int r = Resolve(Pop(self), self->typeInfo);
			int l = Resolve(Pop(self), self->typeInfo);
			PushInt(self, r & l);
			break;
		}

		case 25: {
			int r = Resolve(Pop(self), self->typeInfo);
			int l = Resolve(Pop(self), self->typeInfo);
			PushInt(self, r | l);
			break;
		}

		case 11:
			rhs = Pop(self);
			if (rhs.type == 0) {
				PushInt(self, -rhs.i);
			} else if (rhs.type == 1) {
				PushFloat(self, -rhs.f);
			} else {
				func_0200159c(-1);
			}
			break;

		case 29:
			rhs = Pop(self);
			if (rhs.type == 0) {
				PushFloat(self, _d2f(func_02009424(func_0200c578((float)rhs.i))));
			} else if (rhs.type == 1) {
				PushFloat(self, _d2f(func_02009424(func_0200c578(rhs.f))));
			} else {
				func_0200159c(-1);
			}
			break;

		case 30:
			rhs = Pop(self);
			if (rhs.type == 0) {
				PushFloat(self, _d2f(func_02008dcc(func_0200c578((float)rhs.i))));
			} else if (rhs.type == 1) {
				PushFloat(self, _d2f(func_02008dcc(func_0200c578(rhs.f))));
			} else {
				func_0200159c(-1);
			}
			break;

		case 26:
			rhs = Pop(self);
			if (rhs.type == 0) {
				PushInt(self, rhs.i == 0);
			} else {
				func_0200159c(-1);
			}
			break;

		case 12:
			rhs = Pop(self);
			if (rhs.type == 0) {
				PushFloat(self, (float)rhs.i);
			} else if (rhs.type == 1) {
				PushFloat(self, rhs.f);
			} else {
				func_0200159c(-1);
			}
			break;

		case 13:
			rhs = Pop(self);
			if (rhs.type == 0) {
				PushInt(self, rhs.i);
			} else if (rhs.type == 1) {
				PushInt(self, (int)rhs.f);
			} else {
				func_0200159c(-1);
			}
			break;

		case 20: {
			self->stack -= self->pc->arg;
			Pair021d4a64* p = self->stack;
			int n = self->pc->arg;
			for (int i = 0; i < n; i++, p++) {
				func_02001878(&data_020eec2c);
			}
			break;
		}

		case 21:
			self->stack -= self->pc->arg;
			if (self->suspended == 0) {
				_Z32DispatchIndexedCallback_021d4bc8P9A021d4bc8P9B021d4bc8i((A021d4bc8*)self, (B021d4bc8*)self->stack,
				                                self->pc->arg);
			}
			break;

		case 27:
			self->stopped = 1;
			self->pc = NULL;
			return;

		case 19:
			self->pc = (Instr021d4e38*)(func_ov017_021d4af8((Ctx021d4af8*)self,
			                                               (Arg021d4af8*)(self->code + self->pc->aux),
			                                               (int)self->pc) - 0xc);
			break;

		case 15:
			stmp = Pop(self);
			if (self->callTop != self->callBase) {
				self->stack = (Pair021d4a64*)self->frame;
				self->pc = (Instr021d4e38*)_Z22PopStackEntry_021d4b9cP11Obj021d4b9c((Obj021d4b9c*)self);
			} else {
				self->result = stmp.i;
				Push(self, stmp);
				self->pc = NULL;
				self->stopped = 1;
				return;
			}
			Push(self, stmp);
			break;

		case 23:
			if (self->suspended != 0) {
				break;
			}
			self->pc = self->pc + 1;
			return;

		case 28:
			self->steps++;
			if (self->suspended != 0) {
				self->suspended = 0;
				self->pc = self->pc + 1;
				return;
			}
			break;
		}
		self->pc++;
	}
}

#pragma opt_dead_assignments reset
