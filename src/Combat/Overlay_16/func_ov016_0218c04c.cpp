#include <globaldefs.h>

extern "C" unsigned int _Z16GetSharedWordDa0i(int i);
extern "C" unsigned int _Z16GetSharedWordDc4i(int i);
extern "C" unsigned int _Z22GetConst25980_0218fc78v(void);
extern "C" unsigned int _Z21GetConst9600_0218fc84v(void);
extern "C" void _Z16SetData_0218fc8cPvj(unsigned int a, unsigned int n);
extern "C" void _Z20SetupHandle_0218fcacPvi(unsigned int a, unsigned int n);
extern "C" void _Z18NitroVM_InitializeP7NitroVM(void* vm);
extern "C" int _Z29NitroVM_PrepareReadFileByPathP7NitroVMPKc(void* vm, const char* path);
extern "C" void _Z18NitroVM_FinishReadP7NitroVM(void* vm);
extern "C" void* func_ov016_0218e558(void* vm, int n);
extern "C" unsigned int _Z22CallIfNonNull_0218e690Pv(void* p);
extern "C" unsigned int _Z22CallIfNonNull_0218e6a8Pv(void* p);
extern "C" unsigned int _Z22CallIfNonNull_0218e678Pv(void* p);
extern "C" void* func_ov016_0218e660(void* p);
extern "C" unsigned int func_ov016_0218e750(void* p);
extern "C" int _Z26CallIfNonNullBool_0218e6c0Pv(void* p);
extern "C" void _Z26CallIfNonNullBool_0218e6e4Pv(void* p);
extern "C" void _Z26CallIfNonNullBool_0218e72cPv(void* p);
extern "C" void _Z22ClearAndReset_0218e640Pv(void* p);
extern "C" int _Z28CheckStateEqualsOne_0218e768Pv(void* p, void* buf);
extern "C" void func_ov016_0218bce8(void* p, unsigned int n);
extern "C" void func_ov016_0218bec4(void* p, int n);
extern "C" void func_020d1f0c(int a, int b, int c, int d);
extern "C" void _Z16EnqueueEvent0x1Bii(int a, int b);
extern "C" void func_020d24c4(int a);
extern "C" void func_020c9778(int a, int b);
extern "C" void func_020bbd9c(void);
extern "C" int func_020ce89c(int a, int b, int c);
extern "C" unsigned short _Z24XorMaskKeyInput_0218ca70v(void);
extern "C" int _Z15SetData020f2284v(void);
extern "C" void* _ZN13SafeAllocator8AllocateEj(void* self, unsigned int n);
extern "C" void _ZN13SafeAllocator4FreeEPv(void* self, void* p);
extern "C" void* memset(void* p, int c, unsigned int n);
extern "C" void _Z14CleanDataCachev(void);
extern "C" void _Z15CleanCacheRangePKvj(const void* p, unsigned int n);
extern "C" void _Z19ZeroInitializeAlarmP5Alarm(void* a);
extern "C" unsigned long long _Z19GetCurrentTimestampv(void);
extern "C" void _Z11SetIntervalP5AlarmyyPFvPP16ProcessorContextES3_(void* a, unsigned long long residue,
    unsigned long long interval, void* fn, void* arg);
extern "C" void _Z11CancelAlarmP5Alarm(void* a);
extern "C" void _Z28SetKeyAndApplyRecord0203ad14PvtS_i(void* a, int id, void* b, int c);
extern "C" void _Z29TryDispatchOrFallback0203aba8P11Obj0203aba8PvS1_(void* a, int id, void* b);
extern "C" void _Z32UpdateScaleOrApplyRecord0203ae4cPviS_(void* a, int b, void* c);
extern "C" void _Z22ScaleAndNotify0203ad88PvS_i(void* a, void* b, int c);
extern "C" void _Z29SetContextAndDispatch0203ac10PvS_i(void* a, void* b, int c);
extern "C" void func_02012538(void* p);
extern "C" void _Z22SelectCoordsByFlag0x24PhPiS0_(unsigned char* p, int* x, int* y);
extern "C" void* _ZN9GameState11GetInstanceEv(void);
extern "C" int _Z24NormalizeField5_0200fb08P14Struct0200fb08(void* gs);
extern "C" void _Z33SetFlagAndMaybeIncrement_0218c024v(void);

struct Info_0218c04c {
	char pad0[0x10];
	unsigned char isSet;	// 0x10
	char pad11;
	short id;				// 0x12
	unsigned int delay;		// 0x14
};

struct State_0218c04c {
	int mute;					// 0x00
	int flag4;					// 0x04
	void* alloc;				// 0x08
	char padc[4];				// 0x0c
	int started;				// 0x10
	volatile int ready;			// 0x14
	int counter18;				// 0x18
	int f1c;					// 0x1c
	int f20;					// 0x20
	unsigned int frames;		// 0x24
	int pos;					// 0x28
	short* bufR;				// 0x2c
	short* bufL;				// 0x30
	Info_0218c04c* info;		// 0x34
	int busy;					// 0x38
	int counter3c;				// 0x3c
	unsigned long long startTime;	// 0x40
	volatile long long read;	// 0x48
	long long written;			// 0x50
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
	base3 = _Z16GetSharedWordDa0i(3);
	sz3 = _Z16GetSharedWordDc4i(3) - base3;
	if (sz3 >= _Z22GetConst25980_0218fc78v()) {
		sz3 = _Z22GetConst25980_0218fc78v();
	}
	base4 = _Z16GetSharedWordDa0i(4);
	sz4 = _Z16GetSharedWordDc4i(4) - base4;
	if (sz4 >= _Z21GetConst9600_0218fc84v()) {
		sz4 = _Z21GetConst9600_0218fc84v();
	}
	_Z16SetData_0218fc8cPvj(_Z16GetSharedWordDa0i(3), sz3);
	_Z20SetupHandle_0218fcacPvi(_Z16GetSharedWordDa0i(4), sz4);
	_Z18NitroVM_InitializeP7NitroVM(vm);

	if (_Z29NitroVM_PrepareReadFileByPathP7NitroVMPKc(vm, path)) {
	node = func_ov016_0218e558(vm, 6);
	if (node != 0) {
		unsigned int frame = 0;

		cnt = 0;
		limitCnt = _Z22CallIfNonNull_0218e690Pv(node);
		unit = _Z22CallIfNonNull_0218e6a8Pv(node);
		q = (int)(((unsigned long long)(unsigned int)func_ov016_0218e660(node) << 24) /
			((unsigned long long)unit * _Z22CallIfNonNull_0218e678Pv(node)));
		data_ov016_0219d0c0.frames = (q + 1) * 7;
		data_ov016_0219d0c0.bufL = (short*)_ZN13SafeAllocator8AllocateEj(data_ov016_0219d0c0.alloc,
			data_ov016_0219d0c0.frames * unit * 2);
		data_ov016_0219d0c0.bufR = (short*)_ZN13SafeAllocator8AllocateEj(data_ov016_0219d0c0.alloc,
			data_ov016_0219d0c0.frames * unit * 2);
		memset(data_ov016_0219d0c0.bufL, 0, data_ov016_0219d0c0.frames * unit * 2);
		memset(data_ov016_0219d0c0.bufR, 0, data_ov016_0219d0c0.frames * unit * 2);
		_Z14CleanDataCachev();
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
			unsigned long long now = _Z19GetCurrentTimestampv();
			unsigned long long per = (0xf4240ULL << 24) / _Z22CallIfNonNull_0218e678Pv(node);
			unsigned long long iv = ((per * 0x82ea) >> 6) / 1000;
			_Z11SetIntervalP5AlarmyyPFvPP16ProcessorContextES3_(&data_ov016_0219d118, now + 5, (unsigned int)iv,
				(void*)_Z33SetFlagAndMaybeIncrement_0218c024v, 0);
		}
		data_ov016_0219d0c0.startTime = (_Z19GetCurrentTimestampv() << 6) / 0x82ea;
		scale = (float)_Z22CallIfNonNull_0218e678Pv(node) / 16777216.0f;
		lastFrame = 0;

		while (_Z26CallIfNonNullBool_0218e6c0Pv(node)) {
			if (data_ov016_0219d0c0.started == 0) {
				Info_0218c04c* p = data_ov016_0219d0c0.info;
				unsigned long long t = (_Z19GetCurrentTimestampv() << 6) / 0x82ea;
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
					_Z32UpdateScaleOrApplyRecord0203ae4cPviS_(&data_02109bf4, 1, 0);
					func_020ce89c(0xc, 0, 0);
					*(unsigned int*)(&data_02109bf4 + 0xa8) =
						(unsigned int)(1000.0f * ((float)(frame - lastFrame) / scale));
					_Z32UpdateScaleOrApplyRecord0203ae4cPviS_(&data_02109bf4, 0, 0);
				} else {
					func_020ce89c(0xc, 0, 0);
				}
				data_ov016_0219d0c0.busy = 0;
			}
			_Z26CallIfNonNullBool_0218e6e4Pv(node);
			frame++;

			if ((_Z15SetData020f2284v() & 0x40000000) || (_Z15SetData020f2284v() & 0x80000000)) {
				if (func_ov016_0218e660(node) != 0) {
					unsigned long long total = func_ov016_0218e750(node);
					int j = 0;
					int pos = data_ov016_0219d0c0.pos;
					unsigned int bytes = unit * 2;
					for (; j < total; j++) {
						if (state != 0) {
							long long used; do { used = data_ov016_0219d0c0.written - data_ov016_0219d0c0.read; } while (data_ov016_0219d0c0.frames - used == 0);
						}
						_Z28CheckStateEqualsOne_0218e768Pv(node, data_ov016_0219d0c0.bufL + pos);
						_Z28CheckStateEqualsOne_0218e768Pv(node, data_ov016_0219d0c0.bufR + data_ov016_0219d0c0.pos);
						_Z15CleanCacheRangePKvj(data_ov016_0219d0c0.bufL + data_ov016_0219d0c0.pos, bytes);
						_Z15CleanCacheRangePKvj(data_ov016_0219d0c0.bufR + data_ov016_0219d0c0.pos, bytes);
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
					_Z26CallIfNonNullBool_0218e72cPv(node);
					paused = 1;
				} else {
					func_ov016_0218bec4(node, arg1);
					paused = 0;
				}
			}

			{
				unsigned short keys = _Z24XorMaskKeyInput_0218ca70v();
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
							_Z16EnqueueEvent0x1Bii(3, 0);
							func_020d24c4(1);
						}
						while (_Z24XorMaskKeyInput_0218ca70v() != 0) {
							func_020c9778(0, 1);
						}
						while ((_Z24XorMaskKeyInput_0218ca70v() & 8) == 0) {
							func_020c9778(0, 1);
						}
						if (state == 1) {
							memset(data_ov016_0219d0c0.bufL, 0, data_ov016_0219d0c0.frames * unit * 2);
							memset(data_ov016_0219d0c0.bufR, 0, data_ov016_0219d0c0.frames * unit * 2);
							_Z14CleanDataCachev();
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
				_Z22SelectCoordsByFlag0x24PhPiS0_((unsigned char*)&data_02114e54, &sx, &sy);
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
		if ((_Z15SetData020f2284v() & 0x40000000) || (_Z15SetData020f2284v() & 0x80000000)) {
			if (state == 1) {
				func_020d1f0c(3, 0, 1, 0);
				_Z16EnqueueEvent0x1Bii(3, 0);
				func_020d24c4(1);
			}
		}
		_Z11CancelAlarmP5Alarm(&data_ov016_0219d118);
		_ZN13SafeAllocator4FreeEPv(data_ov016_0219d0c0.alloc, data_ov016_0219d0c0.bufL);
		_ZN13SafeAllocator4FreeEPv(data_ov016_0219d0c0.alloc, data_ov016_0219d0c0.bufR);
		_Z22ClearAndReset_0218e640Pv(node);
		_Z18NitroVM_FinishReadP7NitroVM(vm);
		if (data_ov016_0219d0c0.info->id > -1) {
			if (data_ov016_0219d0c0.info->isSet != 0) {
				_Z22ScaleAndNotify0203ad88PvS_i(&data_02109bf4, 0, 0);
			} else {
				_Z29SetContextAndDispatch0203ac10PvS_i(&data_02109bf4, &data_ov016_0219d0cc, 0);
			}
			func_020bbd9c();
		}
	}
}
}
