#include <globaldefs.h>
#include <GameState/GameState.h>
#include <System/Memory.h>
struct Flags020abb64 { unsigned int value:12, mode:4, index:5, field_0x0_21:4, bit25:1, bit26:1, bit27:1, bit28:1, bit29:1, bit30:1, bit31:1; };
struct Fields020abb64 { unsigned int low:9, middle:10, high:11, bit30:1, bit31:1; };
struct Config020abb64 { Flags020abb64 flags; Fields020abb64 fields; unsigned char statusByte; };
struct State020abb64 { char pad[0x569c]; Config020abb64 config; char pad2[0xcd8]; char buffer[0x54]; };
extern "C" char* _Z20GetSlotEntry020108d8Pci(char*, int);
extern "C" void func_02082828(char*);
extern "C" int _Z35SendShortBufferOrReturnZero020aba5ci(int);
int SendBufferOrReturnZero(int);
extern "C" void _Z28InitBigManagerStruct0208660cPc(char*);
// USA: func_020abb64
extern "C" ARM int func_020abb64() {
    GameState* state = GameState::GetInstance();
    for (int i = 0;i < 4;i++) { char* entry = _Z20GetSlotEntry020108d8Pci((char*)state, i); if (entry) func_02082828(entry); }
    if (!_Z35SendShortBufferOrReturnZero020aba5ci(0)) return 0;
    if (!_Z35SendShortBufferOrReturnZero020aba5ci(1)) return 0;
    if (!SendBufferOrReturnZero(0)) return 0;
    if (!SendBufferOrReturnZero(1)) return 0;
    State020abb64* storage = (State020abb64*)state;
    storage->config.flags.value = 2000;
    storage->config.flags.mode = 1;
    storage->config.flags.index = 1;
    storage->config.flags.bit28 = 0;
    storage->config.flags.field_0x0_21 = 0;
    storage->config.flags.bit27 = 0;
    storage->config.flags.bit25 = 0;
    storage->config.flags.bit26 = 0;
    storage->config.flags.bit29 = 0;
    storage->config.flags.bit30 = 1;
    storage->config.flags.bit31 = 0;
    Config020abb64* config = &storage->config;
    config->fields.low = 511;
    config->fields.bit30 = 0;
    config->fields.middle = 300;
    config->fields.high = 706;
    config->statusByte = 0;
    _Z28InitBigManagerStruct0208660cPc((char*)GetPtrField0x2a04(state));
    VectorizedMemset(storage->buffer, 0, 0x54);
    return 1;
}
