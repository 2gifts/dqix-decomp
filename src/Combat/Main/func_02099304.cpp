#include <globaldefs.h>

class Script {
public:
    struct OpcodeLookupEntry;
    void Initialize();
    void SetOpcodeLookup(OpcodeLookupEntry* lookup);
    void Load(const void* data, unsigned int size);
    void Execute();
};

struct ScriptRequest {
    unsigned int lo : 12;
    unsigned int mid : 4;
    unsigned int hi : 5;
    unsigned int rest : 10;
    unsigned int top : 1;
    int offset : 9;
    signed char mode;
};

struct StoreStruct;
struct Obj02046574;

struct ScriptGlobal {
    unsigned char flags;
    void* buffer;
    ScriptRequest* request;
};

extern ScriptGlobal data_021098e8;
extern char data_020f1504[];

extern "C" void* func_0202ae18(void);
extern "C" int func_0202c508(void* gs);
extern "C" void func_02046380(StoreStruct* store);
extern "C" void* memset(void* dst, int value, unsigned int length);
extern "C" void _Z21RegisterSlotA020cf0fci(int out);
extern "C" StoreStruct* _Z26GetGlobalField0x1c020421a0v(void);
extern "C" void _Z26StoreInArray0x8b0_020465c0P11StoreStructii(StoreStruct* store, int index, int value);
extern "C" int _Z21CalculateAge_02098f20iii(int a, int b, int c);
extern "C" void _Z22SetIndexedName02046574P11Obj02046574iPc(Obj02046574* obj, int index, char* name);

// USA: func_02099304
extern "C" ARM int func_02099304(ScriptRequest* request, char* name, const void* data, unsigned int size, void* buffer, int bufferSize, unsigned char flags, char* nameA, char* nameB) {
    void* gs = func_0202ae18();
    int slot[4];
    unsigned char scriptBuf[0x430];

    if (request == 0 || name == 0) {
        return 0;
    }
    if (bufferSize < 0x190) {
        return 0;
    }
    memset(buffer, 0, bufferSize);
    data_021098e8.request = request;
    data_021098e8.buffer = buffer;
    data_021098e8.flags = 0;
    if (flags == 0) {
        data_021098e8.flags |= 0x10;
    } else {
        if (flags & 2) {
            if (func_0202c508(gs)) {
                _Z21RegisterSlotA020cf0fci((int)slot);
                if (slot[1] == request->mid && slot[2] == request->hi) {
                    data_021098e8.flags |= 1;
                }
                if (slot[1] == 1 && slot[2] == 1) {
                    data_021098e8.flags |= 2;
                } else if (slot[1] == 0xc && slot[2] == 0x19) {
                    data_021098e8.flags |= 8;
                } else if (slot[1] == 2 && slot[2] == 0xe) {
                    data_021098e8.flags |= 4;
                }
            }
        }
        if ((flags & 1) && request->mode != 0) {
            data_021098e8.flags |= 0x20;
        }
    }

    StoreStruct* store = _Z26GetGlobalField0x1c020421a0v();
    func_02046380(store);
    unsigned int hi = request->hi;
    _Z26StoreInArray0x8b0_020465c0P11StoreStructii(store, 1, request->mid);
    _Z26StoreInArray0x8b0_020465c0P11StoreStructii(store, 2, hi);
    if (request->top) {
        int age;
        if (request->offset < 0) {
            age = 0;
        } else {
            age = _Z21CalculateAge_02098f20iii(request->lo, request->mid, request->hi);
            if (age < 0) {
                age = 0;
            }
        }
        _Z26StoreInArray0x8b0_020465c0P11StoreStructii(store, 0, age);
    }
    _Z22SetIndexedName02046574P11Obj02046574iPc((Obj02046574*)store, 0, name);
    _Z22SetIndexedName02046574P11Obj02046574iPc((Obj02046574*)store, 1, nameA);
    _Z22SetIndexedName02046574P11Obj02046574iPc((Obj02046574*)store, 2, nameB);

    ((Script*)scriptBuf)->Initialize();
    ((Script*)scriptBuf)->SetOpcodeLookup((Script::OpcodeLookupEntry*)data_020f1504);
    ((Script*)scriptBuf)->Load(data, size);
    ((Script*)scriptBuf)->Execute();
    return 1;
}
