#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"
#include <globaldefs.h>

struct S_a0b8c;
struct Obj021e1318;
struct ObjStruct_021e1474;
struct Container020dedd0;
extern "C" short _Z26CountNonZeroValues020a0b8cP7S_a0b8c(struct S_a0b8c *s);
unsigned char *GetFieldAt0x150(unsigned char *p);
extern "C" void _Z17ClearObj_021e1318P11Obj021e1318(struct Obj021e1318 *obj);
extern "C" void _Z25InitScriptAndRun_021e133cPvS_iiis(void *a, void *b, int c, int d, int e, short f);
extern "C" void _Z22ClearElements_021e1518Pv(void *p);
extern "C" void _Z32RefreshEntryStatusFlags_021e1474P18ObjStruct_021e1474P17Container020dedd0(struct ObjStruct_021e1474 *obj,
                                                                                              struct Container020dedd0 *c);
extern "C" void *ExtractFileFromGP2(const char *gp2Path, const char *innerFilePath, unsigned int *outSize);
extern "C" char data_ov002_0216cf83[];
extern "C" char data_ov002_0216cf99[];

// USA: func_ov002_0215b2c8
extern "C" ARM void func_ov002_0215b2c8(char *base) {
    unsigned int size;
    short buf[0x100];
    GameState *gs;
    char *party;
    void *src;
    int i;
    int j;
    char *sub;
    GameObject *m;
    unsigned char *data;
    short v;
    short count;
    gs    = GameState::GetInstance();
    party = (char *) GetPtrField0x2a04(gs);
    src   = *(void **) party;
    count = _Z26CountNonZeroValues020a0b8cP7S_a0b8c((struct S_a0b8c *) party);
    memset(buf, -1, sizeof(buf));
    memcpy(buf, src, count * 2);
    for (i = 0; i < *(unsigned char *) (party + 0xf7c); i++) {
        m = gs->GetPartyMemberByIndex(*(signed char *) (party + 0xf78 + i));
        if (m == NULL) continue;
        data = GetFieldAt0x150((unsigned char *) m);
        for (j = 0; j < 8; j++) {
            v = ((short *) (data + 0x454))[j];
            if (v > 0) {
                buf[count] = v;
                count++;
            }
        }
    }
    ((SafeAllocator *) (base + 0x850))->Reset();
    sub = base + 4;
    _Z17ClearObj_021e1318P11Obj021e1318((struct Obj021e1318 *) (sub + 0x800));
    BackgroundLoader::AddLockGlobal();
    BackgroundLoader::FreeAllocationsGlobal();
    void *file = ExtractFileFromGP2(data_ov002_0216cf83, data_ov002_0216cf99, &size);
    if (file != NULL) {
        _Z25InitScriptAndRun_021e133cPvS_iiis(sub + 0x800, base + 0x850, (int) file, size, (int) buf, count);
    }
    BackgroundLoader::RemoveLockGlobal();
    _Z22ClearElements_021e1518Pv(sub + 0x800);
    _Z32RefreshEntryStatusFlags_021e1474P18ObjStruct_021e1474P17Container020dedd0(
        (struct ObjStruct_021e1474 *) (sub + 0x800), (struct Container020dedd0 *) (base + 0x3ec + 0x400));
    *(void **) (base + 0x2534) = ((SafeAllocator *) (base + 0x850))->Allocate(0x140);
    *(void **) (base + 0x2538) = ((SafeAllocator *) (base + 0x850))->Allocate(0xa0);
}
