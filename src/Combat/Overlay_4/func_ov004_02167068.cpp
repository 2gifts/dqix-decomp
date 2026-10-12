#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"

struct StreamHeader;
struct StreamHeader0208d860 {
    unsigned int field_0;
    unsigned short field_4;
    unsigned short field_6;
    unsigned int field_8;
    unsigned short field_c;
    unsigned short field_e;
};
struct Obj02095e90;
struct Ctx02095ee0;
struct Obj0208becc { unsigned char field_0[0x100]; };
struct Node02167068 { unsigned char field_0[0x34]; Obj0208becc object; };
struct State02167068 {
    unsigned int field_0;
    unsigned int field_4;
    unsigned int field_8;
    StreamHeader0208d860 stream;
    SafeAllocator allocator;
    SafeAllocator secondaryAllocator;
    int task;
    short count0;
    short count1;
    short field_4c;
    short script;
    unsigned char step : 6;
    unsigned char bit6 : 1;
    unsigned char bit7 : 1;
};
extern State02167068* data_ov004_0217101c;
extern char data_ov004_021705a5[];
extern char data_ov004_021705c0[];
extern char data_ov004_021705d2[];
int* GetGlobal02109418();
extern "C" int _Z25RunBufferedScript020957f4PvP12StreamHeaderi(void*, StreamHeader*, int);
extern "C" void _Z39SetupHeaderAndRunBufferedScript0208d860P20StreamHeader0208d860PvP12StreamHeaderiist(StreamHeader0208d860*, void*, StreamHeader*, int, int, short, unsigned short);
extern "C" int _Z28InitObjWithAllocator02095e90P11Obj02095e90P13SafeAllocator(Obj02095e90*, SafeAllocator*);
extern "C" int _Z23RunOrPollScript02095ee0P11Ctx02095ee0(Ctx02095ee0*);
extern "C" void func_0209576c(void*, SafeAllocator*, void*, int, int);
extern "C" void func_ov004_02166198();
extern "C" void func_ov011_021848a0(void*, int);
extern "C" int func_ov004_02166b40(void*);
extern "C" short func_ov004_021666bc(void*, char*);
extern "C" void* _Z40CheckTypeAndReturnNode_02165e70_02165e70Pvi(void*, int);
extern "C" void _Z27SetFieldD2IfChanged0208beccP11Obj0208beccih(Obj0208becc*, int, unsigned char);

// USA: func_ov004_02167068
extern "C" ARM int func_ov004_02167068(void* self) {
    State02167068* state = data_ov004_0217101c;
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    int* global = GetGlobal02109418();
    int result = 1;
    if (state->step == 0) {
        state->task = loader->QueueLoadFileInGP2(data_ov004_021705a5, data_ov004_021705c0, 0);
        state->step = 1;
    } else if (state->step == 1) {
        if (loader->GetTaskStatus(state->task)) {
            void* buffer;
            unsigned int size;
            loader->GetLoadedFileByID(state->task, &buffer, &size);
            if (buffer) {
                state->script = _Z25RunBufferedScript020957f4PvP12StreamHeaderi(global, (StreamHeader*)buffer, size);
                _Z39SetupHeaderAndRunBufferedScript0208d860P20StreamHeader0208d860PvP12StreamHeaderiist(&state->stream, &state->allocator, (StreamHeader*)buffer, size, 0, 0, 1);
            }
            loader->RemoveTask(state->task);
            state->task = -1;
            state->step = 2;
        }
    } else if (state->step == 2) {
        _Z28InitObjWithAllocator02095e90P11Obj02095e90P13SafeAllocator((Obj02095e90*)global, &state->allocator);
        state->step = 3;
    } else if (state->step == 3) {
        if (_Z23RunOrPollScript02095ee0P11Ctx02095ee0((Ctx02095ee0*)global) != 1) return result;
        state->task = loader->QueueLoadFile(data_ov004_021705d2, 0);
        state->step = 4;
    } else if (state->step == 4) {
        if (loader->GetTaskStatus(state->task)) {
            void* buffer;
            unsigned int size;
            loader->GetLoadedFileByID(state->task, &buffer, &size);
            if (buffer) func_0209576c(global, &state->allocator, buffer, size, 0);
            loader->RemoveTask(state->task);
            state->task = -1;
            state->step = 5;
        }
    } else if (state->step == 5) {
        func_ov004_02166198();
        state->step = 6;
    } else {
        state->step = 0;
        result = 0;
        char flag = 0;
        if (state->count0 == 0 && state->count1 == 0) {
            func_ov011_021848a0(self, 0x65);
        } else if (state->count1 == 0) {
            func_ov004_02166b40(self);
            func_ov004_021666bc(self, &flag);
        } else {
            func_ov011_021848a0(self, 0x12c);
        }
        unsigned char value = flag;
        Node02167068* node = (Node02167068*)_Z40CheckTypeAndReturnNode_02165e70_02165e70Pvi(self, 7);
        if (node) _Z27SetFieldD2IfChanged0208beccP11Obj0208beccih(&node->object, 0x270f, value);
    }
    return result;
}
