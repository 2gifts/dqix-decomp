#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include <globaldefs.h>

struct Container020e0310;
struct List020727d8;

extern "C" int _Z19ResetFields021847c4P14Struct021847c4(void *obj, int a);
extern "C" char *_Z26GetGlobalField0x1c020421a0v();
extern "C" int _Z29GetField110ArrayValue021574d4Pvi(void *self, int index);
extern "C" void func_ov013_02184c8c(void *menu, void *member);
extern "C" void *memset(void *dst, int value, unsigned int length);
extern "C" unsigned char func_0209a678(char *table, void *member, unsigned short *skills);
extern "C" void *func_0202ae18();
int CheckField0NonZero(int *p);
extern "C" void func_ov017_021c9e00(int id, int a, int b, int c);
extern "C" void func_ov017_021ccc34(int id);
extern "C" void func_ov017_021cd0d8(int id, unsigned short *skills, int count);
extern "C" const char *_Z21GetFieldByKey020e0434P17Container020e0310i(Container020e0310 *texts, int id);
extern "C" void _Z23ResetListHeader020727d8P12List020727d8(List020727d8 *list);
extern "C" void func_020728ac(void *list, void *alloc, void *buffer, unsigned int length, int a4, int a5, int a6);
void Zero4Bytes(void *reader);
extern "C" void func_020e5604(void *reader, void *alloc, void *buffer, unsigned int length);
void *GetFieldAt0x150(unsigned char *member);
extern "C" void func_02083e28(void *model, int arg);

extern "C" const char data_ov002_0216d300[];
extern "C" const char data_ov002_0216d315[];

// USA: func_ov002_02168354
extern "C" ARM void func_ov002_02168354(char *self) {
    unsigned int size;
    *(unsigned int *) (self + 0x247c) |= 4;
    if (_Z19ResetFields021847c4P14Struct021847c4(self + 0xd70 + 0x1000, *(int *) (self + 0x1ba0)) != 6) {
        return;
    }
    GameState *gs = GameState::GetInstance();
    _Z26GetGlobalField0x1c020421a0v();
    *(unsigned int *) (self + 0x247c) &= ~4;
    if (*(unsigned char *) (self + 0x2455) == 0) {
        char *member =
            (char *) GetCombatantWithFlag0x100(gs, _Z29GetField110ArrayValue021574d4Pvi(self, *(short *) (self + 0x1c08)));
        if (member != 0) {
            func_ov013_02184c8c(self + 0xd70 + 0x1000, member);
        }
        if (member != 0) {
            ((SafeAllocator *) (self + 0x64 + 0x800))->Reset();
            *(void **) (self + 0x2450) = ((SafeAllocator *) (self + 0x64 + 0x800))->Allocate(0x6e);
            memset(*(void **) (self + 0x2450), 0, 0x6e);
            *(unsigned char *) (self + 0x2455) =
                func_0209a678(self + 0x3c + 0x2400, member, *(unsigned short **) (self + 0x2450));
            if (CheckField0NonZero((int *) func_0202ae18())) {
                int id = _Z29GetField110ArrayValue021574d4Pvi(self, *(short *) (self + 0x1c08));
                func_ov017_021c9e00(id, 0, 0, 0);
                func_ov017_021ccc34(id);
                func_ov017_021cd0d8(id, *(unsigned short **) (self + 0x2450), *(unsigned char *) (self + 0x2455));
            }
            if (*(unsigned char *) (self + 0x2455) == 0) {
                *(int *) (self + 0x1bc0) += 1;
                return;
            }
            BackgroundLoader::AddLockGlobal();
            BackgroundLoader::FreeAllocationsGlobal();
            const char *inner = _Z21GetFieldByKey020e0434P17Container020e0310i((Container020e0310 *) (self + 0x20), 0x65);
            void *file        = ExtractFileFromGP2(
                _Z21GetFieldByKey020e0434P17Container020e0310i((Container020e0310 *) (self + 0x20), 0x64), inner, &size);
            *(void **) (self + 0x2448) = ((SafeAllocator *) (self + 0x64 + 0x800))->Allocate(8);
            _Z23ResetListHeader020727d8P12List020727d8(*(List020727d8 **) (self + 0x2448));
            if (file != 0) {
                func_020728ac(*(void **) (self + 0x2448), self + 0x64 + 0x800, file, size, 0, 0, 0);
            }
            file                       = ExtractFileFromGP2(data_ov002_0216d300, data_ov002_0216d315, &size);
            *(void **) (self + 0x244c) = ((SafeAllocator *) (self + 0x64 + 0x800))->Allocate(0xc);
            Zero4Bytes(*(void **) (self + 0x244c));
            if (file != 0) {
                func_020e5604(*(void **) (self + 0x244c), self + 0x64 + 0x800, file, size);
            }
            BackgroundLoader::RemoveLockGlobal();
            func_02083e28(GetFieldAt0x150((unsigned char *) member), 0);
        }
    }
    *(int *) (self + 0x1bc0) += 1;
}
