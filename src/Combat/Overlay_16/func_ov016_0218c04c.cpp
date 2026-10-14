#include <globaldefs.h>

unsigned int GetSharedWordDa0(int i);
unsigned int GetSharedWordDc4(int i);
unsigned int GetConst25980_0218fc78(void);
unsigned int GetConst9600_0218fc84(void);
extern "C" void _Z16SetData_0218fc8cPvj(unsigned int a, unsigned int n);
extern "C" void _Z20SetupHandle_0218fcacPvi(unsigned int a, unsigned int n);
extern "C" void _Z18NitroVM_InitializeP7NitroVM(void* vm);
extern "C" int _Z29NitroVM_PrepareReadFileByPathP7NitroVMPKc(void* vm, const char* path);
extern "C" void _Z18NitroVM_FinishReadP7NitroVM(void* vm);
extern "C" void* func_ov016_0218e558(void* vm, int n);
unsigned int CallIfNonNull_0218e690(void* p);
unsigned int CallIfNonNull_0218e6a8(void* p);
unsigned int CallIfNonNull_0218e678(void* p);
extern "C" void* func_ov016_0218e660(void* p);
extern "C" unsigned int func_ov016_0218e750(void* p);
int CallIfNonNullBool_0218e6c0(void* p);
void CallIfNonNullBool_0218e6e4(void* p);
void CallIfNonNullBool_0218e72c(void* p);
void ClearAndReset_0218e640(void* p);
int CheckStateEqualsOne_0218e768(void* p, void* buf);
extern "C" void func_ov016_0218bce8(void* p, unsigned int n);
extern "C" void func_ov016_0218bec4(void* p, int n);
extern "C" void func_020d1f0c(int a, int b, int c, int d);
void EnqueueEvent0x1B(int a, int b);
extern "C" void func_020d24c4(int a);
extern "C" void func_020c9778(int a, int b);
extern "C" void func_020bbd9c(void);
extern "C" int func_020ce89c(int a, int b, int c);
unsigned short XorMaskKeyInput_0218ca70(void);
int SetData020f2284(void);
extern "C" void* _ZN13SafeAllocator8AllocateEj(void* self, unsigned int n);
extern "C" void _ZN13SafeAllocator4FreeEPv(void* self, void* p);
extern "C" void* memset(void* p, int c, unsigned int n);
void CleanDataCache(void);
void CleanCacheRange(const void* p, unsigned int n);
extern "C" void _Z19ZeroInitializeAlarmP5Alarm(void* a);
unsigned long long GetCurrentTimestamp(void);
extern "C" void _Z11SetIntervalP5AlarmyyPFvPP16ProcessorContextES3_(void* a, unsigned long long residue,
    unsigned long long interval, void* fn, void* arg);
extern "C" void _Z11CancelAlarmP5Alarm(void* a);
extern "C" void _Z28SetKeyAndApplyRecord0203ad14PvtS_i(void* a, int id, void* b, int c);
extern "C" void _Z29TryDispatchOrFallback0203aba8P11Obj0203aba8PvS1_(void* a, int id, void* b);
void UpdateScaleOrApplyRecord0203ae4c(void* a, int b, void* c);
void ScaleAndNotify0203ad88(void* a, void* b, int c);
void SetContextAndDispatch0203ac10(void* a, void* b, int c);
extern "C" void func_02012538(void* p);
void SelectCoordsByFlag0x24(unsigned char* p, int* x, int* y);
extern "C" void* _ZN9GameState11GetInstanceEv(void);
extern "C" int _Z24NormalizeField5_0200fb08P14Struct0200fb08(void* gs);
void SetFlagAndMaybeIncrement_0218c024(void);

struct Info_0218c04c {
	char pad0[0x10];
	unsigned char isSet;
	char pad11;
	short id;
	unsigned int delay;
};

struct State_0218c04c {
	int mute;
	int flag4;
	void* alloc;
	char padc[4];
	int started;
	volatile int ready;
	int counter18;
	int f1c;
	int f20;
	unsigned int frames;
	int pos;
	short* bufR;
	short* bufL;
	Info_0218c04c* info;
	int busy;
	int counter3c;
	unsigned long long startTime;
	volatile long long read;
	long long written;
};

struct Touch_02114e54 {
	char pad0[0x24];
	unsigned short h24;
	char pad26[0x5f - 0x26];
	unsigned char b5f;
};

extern State_0218c04c data_ov016_0219d0c0;
extern char data_ov016_0219d0cc;
extern char data_ov016_0219d118;
extern char data_02109bf4;
extern Touch_02114e54 data_02114e54;

// USA: func_ov016_0218c04c
extern "C" ARM void func_ov016_0218c04c(const char* path, int arg1) {
	unsigned char vm[0x48];
	int sx;
	int sy;
	unsigned short prevKeys;
	bool quit;
	int cnt;
	int limitCnt;
	int q;
	unsigned char paused;
	float scale;
	int lastFrame;
	void* node;
	int state;
	unsigned int unit;
	unsigned int sz3;
	unsigned int sz4;
	unsigned int base3;
	unsigned int base4;

	state = 0;
	prevKeys = 0;
	quit = false;
	base3 = GetSharedWordDa0(3);
	sz3 = GetSharedWordDc4(3) - base3;
	if (sz3 >= GetConst25980_0218fc78()) {
		sz3 = GetConst25980_0218fc78();
	}
	base4 = GetSharedWordDa0(4);
	sz4 = GetSharedWordDc4(4) - base4;
	if (sz4 >= GetConst9600_0218fc84()) {
		sz4 = GetConst9600_0218fc84();
	}
	_Z16SetData_0218fc8cPvj(GetSharedWordDa0(3), sz3);
	_Z20SetupHandle_0218fcacPvi(GetSharedWordDa0(4), sz4);
	_Z18NitroVM_InitializeP7NitroVM(vm);

	if (_Z29NitroVM_PrepareReadFileByPathP7NitroVMPKc(vm, path)) {
	node = func_ov016_0218e558(vm, 6);
	if (node != 0) {
		unsigned int frame = 0;

		cnt = 0;
		limitCnt = CallIfNonNull_0218e690(node);
		unit = CallIfNonNull_0218e6a8(node);
		q = (int)(((unsigned long long)(unsigned int)func_ov016_0218e660(node) << 24) /
			((unsigned long long)unit * CallIfNonNull_0218e678(node)));
		data_ov016_0219d0c0.frames = (q + 1) * 7;
		data_ov016_0219d0c0.bufL = (short*)_ZN13SafeAllocator8AllocateEj(data_ov016_0219d0c0.alloc,
			data_ov016_0219d0c0.frames * unit * 2);
		data_ov016_0219d0c0.bufR = (short*)_ZN13SafeAllocator8AllocateEj(data_ov016_0219d0c0.alloc,
			data_ov016_0219d0c0.frames * unit * 2);
		memset(data_ov016_0219d0c0.bufL, 0, data_ov016_0219d0c0.frames * unit * 2);
		memset(data_ov016_0219d0c0.bufR, 0, data_ov016_0219d0c0.frames * unit * 2);
		CleanDataCache();
		paused = 0;
		data_ov016_0219d0c0.read = paused;
		data_ov016_0219d0c0.pos = paused;
		data_ov016_0219d0c0.written = paused;
		data_ov016_0219d0c0.counter18 = paused;
		data_ov016_0219d0c0.ready = 1;
		data_ov016_0219d0c0.f1c = paused;
		data_ov016_0219d0c0.counter3c = paused;
		data_ov016_0219d0c0.f20 = paused;
		_Z19ZeroInitializeAlarmP5Alarm(&data_ov016_0219d118);
		{
			unsigned long long now = GetCurrentTimestamp();
			unsigned long long per = (0xf4240ULL << 24) / CallIfNonNull_0218e678(node);
			unsigned long long iv = ((per * 0x82ea) >> 6) / 1000;
			_Z11SetIntervalP5AlarmyyPFvPP16ProcessorContextES3_(&data_ov016_0219d118, now + 5, (unsigned int)iv,
				(void*)SetFlagAndMaybeIncrement_0218c024, 0);
		}
		data_ov016_0219d0c0.startTime = (GetCurrentTimestamp() << 6) / 0x82ea;
		scale = (float)CallIfNonNull_0218e678(node) / 16777216.0f;
		lastFrame = 0;

		while (CallIfNonNullBool_0218e6c0(node)) {
			if (data_ov016_0219d0c0.started == 0) {
				Info_0218c04c* p = data_ov016_0219d0c0.info;
				unsigned long long t = (GetCurrentTimestamp() << 6) / 0x82ea;
				if (data_ov016_0219d0c0.startTime + p->delay <= t) {
					if (p->isSet != 0) {
						_Z28SetKeyAndApplyRecord0203ad14PvtS_i(&data_02109bf4, p->id, 0, 0);
					} else {
						_Z29TryDispatchOrFallback0203aba8P11Obj0203aba8PvS1_(&data_02109bf4, p->id, &data_ov016_0219d0cc);
					}
					func_020bbd9c();
					data_ov016_0219d0c0.started = 1;
					lastFrame = frame;
				}
			}
			if ((*(unsigned short*)0x27fffa8 & 0x8000) >> 15) {
				data_ov016_0219d0c0.busy = 1;
				if (data_ov016_0219d0c0.info->isSet != 0) {
					UpdateScaleOrApplyRecord0203ae4c(&data_02109bf4, 1, 0);
					func_020ce89c(0xc, 0, 0);
					*(unsigned int*)(&data_02109bf4 + 0xa8) =
						(unsigned int)(1000.0f * ((float)(frame - lastFrame) / scale));
					UpdateScaleOrApplyRecord0203ae4c(&data_02109bf4, 0, 0);
				} else {
					func_020ce89c(0xc, 0, 0);
				}
				data_ov016_0219d0c0.busy = 0;
			}
			CallIfNonNullBool_0218e6e4(node);
			frame++;

			if ((SetData020f2284() & 0x40000000) || (SetData020f2284() & 0x80000000)) {
				if (func_ov016_0218e660(node) != 0) {
					unsigned long long total = func_ov016_0218e750(node);
					int j = 0;
					int pos = data_ov016_0219d0c0.pos;
					unsigned int bytes = unit * 2;
					for (; j < total; j++) {
						if (state != 0) {
							long long used; do { used = data_ov016_0219d0c0.written - data_ov016_0219d0c0.read; } while (data_ov016_0219d0c0.frames - used == 0);
						}
						CheckStateEqualsOne_0218e768(node, data_ov016_0219d0c0.bufL + pos);
						CheckStateEqualsOne_0218e768(node, data_ov016_0219d0c0.bufR + data_ov016_0219d0c0.pos);
						CleanCacheRange(data_ov016_0219d0c0.bufL + data_ov016_0219d0c0.pos, bytes);
						CleanCacheRange(data_ov016_0219d0c0.bufR + data_ov016_0219d0c0.pos, bytes);
						pos = data_ov016_0219d0c0.pos + unit;
						data_ov016_0219d0c0.pos = pos;
						if (pos == data_ov016_0219d0c0.frames * unit) {
							data_ov016_0219d0c0.pos = pos = 0;
						}
						data_ov016_0219d0c0.written = data_ov016_0219d0c0.written + 1;
					}
					if (state == 0 && frame >= 6) {
						func_ov016_0218bce8(func_ov016_0218e660(node), unit);
						state = 1;
					}
				}
			}
			if (frame >= 6 || func_ov016_0218e660(node) == 0) {
				int diff = (int)(data_ov016_0219d0c0.written - data_ov016_0219d0c0.read);
				if (data_ov016_0219d0c0.busy != 0 ||
					(diff <= (q + 1) * 3 && paused == 0 && func_ov016_0218e660(node) != 0)) {
					CallIfNonNullBool_0218e72c(node);
					paused = 1;
				} else {
					func_ov016_0218bec4(node, arg1);
					paused = 0;
				}
			}

			{
				unsigned short keys = XorMaskKeyInput_0218ca70();
				if (data_ov016_0219d0c0.mute == 0) {
					keys &= ~0xa;
				}
				if (keys != prevKeys) {
					prevKeys = keys;
					if (data_ov016_0219d0c0.mute == 1) {
						if ((keys & 1) || (keys & 2) || (keys & 0x400) || (keys & 0x800) || (keys & 8)) {
							quit = true;
							break;
						}
					} else if (keys & 8) {
						if (state == 1) {
							func_020d1f0c(3, 0, 1, 0);
							EnqueueEvent0x1B(3, 0);
							func_020d24c4(1);
						}
						while (XorMaskKeyInput_0218ca70() != 0) {
							func_020c9778(0, 1);
						}
						while ((XorMaskKeyInput_0218ca70() & 8) == 0) {
							func_020c9778(0, 1);
						}
						if (state == 1) {
							memset(data_ov016_0219d0c0.bufL, 0, data_ov016_0219d0c0.frames * unit * 2);
							memset(data_ov016_0219d0c0.bufR, 0, data_ov016_0219d0c0.frames * unit * 2);
							CleanDataCache();
							data_ov016_0219d0c0.written = data_ov016_0219d0c0.written - data_ov016_0219d0c0.read;
							data_ov016_0219d0c0.read = 0;
							data_ov016_0219d0c0.pos = (int)data_ov016_0219d0c0.written * unit;
							if (data_ov016_0219d0c0.pos == data_ov016_0219d0c0.frames * unit) {
								data_ov016_0219d0c0.pos = 0;
							}
							func_ov016_0218bce8(func_ov016_0218e660(node), unit);
						}
					} else if (keys & 2) {
						quit = true;
						break;
					}
				}
			}

			if (data_ov016_0219d0c0.mute == 1) {
				int lo0, hi0, lo1, hi1;
				int touched;
				func_02012538(&data_02114e54);
				SelectCoordsByFlag0x24((unsigned char*)&data_02114e54, &sx, &sy);
				touched = (data_02114e54.b5f != 0 && data_02114e54.h24 != 0) ? 1 : 0;
				switch (_Z24NormalizeField5_0200fb08P14Struct0200fb08(_ZN9GameState11GetInstanceEv())) {
				case 1:
					lo0 = 0x4c; hi0 = 0xbd; lo1 = 0x67; hi1 = 0x98;
					break;
				case 2:
					lo0 = 0x4c; hi0 = 0xbd; lo1 = 0x5d; hi1 = 0xa2;
					break;
				case 3:
					lo0 = 0x42; hi0 = 0xc7; lo1 = 0x57; hi1 = 0xa7;
					break;
				case 4:
					lo0 = 0x56; hi0 = 0xb3; lo1 = 0x67; hi1 = 0x98;
					break;
				case 5:
					lo0 = 0x46; hi0 = 0xc3; lo1 = 0x5d; hi1 = 0xa2;
					break;
				default:
					lo0 = 0x4c; hi0 = 0xbd; lo1 = 0x67; hi1 = 0x98;
					break;
				}
				if (touched) {
					if (lo0 <= sx && sx <= hi0 && sy >= 0x88 && sy <= 0x97) {
						quit = true;
						break;
					}
					if (lo1 <= sx && sx <= hi1 && sy >= 0x98 && sy <= 0xa9) {
						quit = true;
						break;
					}
				}
			}
			cnt = cnt + 1;
			if (cnt == limitCnt) {
				break;
			}
		}

		if (!quit) {
			unsigned int k;
			for (k = 0; k < 5; k++) {
				func_ov016_0218bec4(node, arg1);
			}
		}
		while (data_ov016_0219d0c0.ready == 0) {
		}
		if ((SetData020f2284() & 0x40000000) || (SetData020f2284() & 0x80000000)) {
			if (state == 1) {
				func_020d1f0c(3, 0, 1, 0);
				EnqueueEvent0x1B(3, 0);
				func_020d24c4(1);
			}
		}
		_Z11CancelAlarmP5Alarm(&data_ov016_0219d118);
		_ZN13SafeAllocator4FreeEPv(data_ov016_0219d0c0.alloc, data_ov016_0219d0c0.bufL);
		_ZN13SafeAllocator4FreeEPv(data_ov016_0219d0c0.alloc, data_ov016_0219d0c0.bufR);
		ClearAndReset_0218e640(node);
		_Z18NitroVM_FinishReadP7NitroVM(vm);
		if (data_ov016_0219d0c0.info->id > -1) {
			if (data_ov016_0219d0c0.info->isSet != 0) {
				ScaleAndNotify0203ad88(&data_02109bf4, 0, 0);
			} else {
				SetContextAndDispatch0203ac10(&data_02109bf4, &data_ov016_0219d0cc, 0);
			}
			func_020bbd9c();
		}
	}
}
}
