#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"
#include <globaldefs.h>

struct Container020dedd0;
struct Container020e0310;

struct Element021760cc {
    char pad0[0x1a];
    unsigned short value;
};
struct Loaded021760cc {
    void *a;
    void *b;
    int c;
};
struct Messages021760cc {
    char pad0[0x10];
    void *target;
    char pad14[4];
    void *loaded;
    char pad1c[0x60 - 0x1c];
    char *text;
    char *buffer;
    char pad68[0x998 - 0x68];
    int busy;
    int field99c;
    int state;
};
struct Menu021760cc {
    char pad0[0xc];
    char messages[0x74 - 0xc];
    char container[0x800];
    char pad874[0xfec - 0x874];
    int task;
    int fieldff0;
    char padff4[0x1004 - 0xff4];
    short mode;
    char pad1006[0x1036 - 0x1006];
    short cur;
    short next;
    short selected;
    unsigned char count;
    char pad103d;
    unsigned char field103e;
    unsigned char field103f;
    unsigned char step;
    char pad1041[2];
    signed char character;
    char pad1044[2];
    unsigned short flags;
    short field1048;
};

extern "C" int _Z20AppendString02042058PcPKc(char *, const char *);
extern "C" Messages021760cc *_Z26GetGlobalField0x1c020421a0v();
extern "C" void __clear(void *, int);
extern "C" void _Z20Clear12Bytes020e46c4Pv(void *);
extern "C" void func_020e5334(Loaded021760cc *, void *, unsigned int, int);
extern "C" void func_02046380(Messages021760cc *);
extern "C" void _Z30InitObjFromCombatantId020e4bf4Pvi(void *, int);
extern "C" Element021760cc *_Z24FindElementByKey020dedd0P17Container020dedd0i(Container020dedd0 *, int);
extern "C" int _Z21ComputeRatio_02175898PcPv(char *, void *);
struct StoreStruct;
void StoreInArray0x8b0(StoreStruct *, int, int);
extern "C" const char *_Z21GetFieldByKey020e0434P17Container020e0310i(Container020e0310 *, int);
extern "C" void func_0204500c(Messages021760cc *, const char *, int, int);
extern "C" void func_ov003_021749c0(char *);
extern "C" void _Z24ReinitController02043204Pc(char *);
extern "C" void func_02043124(Messages021760cc *);

extern const char data_ov003_02180b9f[];
extern const char data_ov003_02180bb5[];

// USA: func_ov003_021760cc
extern "C" ARM void func_ov003_021760cc(Menu021760cc *menu) {
    BackgroundLoader *loader = BackgroundLoader::GetInstance();
    Messages021760cc *msgs   = _Z26GetGlobalField0x1c020421a0v();
    if (menu->step == 0) {
        if (menu->task >= 0) {
            loader->RemoveTask(menu->task);
            menu->task = -1;
        }
        menu->task = loader->QueueLoadFileInGP2(data_ov003_02180b9f, data_ov003_02180bb5, 0);
        menu->step++;
    } else if (menu->step == 1) {
        if (loader->GetTaskStatus(menu->task)) {
            char first[0x48];
            char second[0x48];
            Loaded021760cc loaded;
            __clear(first, 0x48);
            __clear(second, 0x48);
            _Z20Clear12Bytes020e46c4Pv(&loaded);
            loaded.a = first;
            loaded.b = second;
            char name[12];
            void *file;
            unsigned int length;
            loader->GetLoadedFileByID(menu->task, &file, &length);
            if (file) {
                if (menu->cur == 0x1e && menu->field1048 != -1) {
                    func_020e5334(&loaded, file, length, menu->field1048);
                } else {
                    func_020e5334(&loaded, file, length, menu->selected);
                }
            }
            loader->RemoveTask(menu->task);
            menu->task = -1;
            short cur  = menu->cur;
            func_02046380(msgs);
            _Z30InitObjFromCombatantId020e4bf4Pvi(name, menu->character);
            msgs->target             = name;
            Element021760cc *element = _Z24FindElementByKey020dedd0P17Container020dedd0i(
                (Container020dedd0 *) (menu->container + 0x800), menu->selected);
            if (element) {
                int value = (menu->mode == 4 ? _Z21ComputeRatio_02175898PcPv((char *) menu, element) : element->value);
                value *= menu->count;
                StoreInArray0x8b0((StoreStruct *) msgs, 0, value);
                StoreInArray0x8b0((StoreStruct *) msgs, 1, menu->count);
            }
            msgs->loaded = &loaded;
            if (menu->flags & 0x200) {
                char *text = msgs->text;
                _Z20AppendString02042058PcPKc(
                    text, _Z21GetFieldByKey020e0434P17Container020e0310i((Container020e0310 *) (menu->messages), cur));
                char *buffer = msgs->buffer;
                memset(buffer, 0, 0x960);
                memcpy(buffer, text, 0x960);
                func_0204500c(msgs, buffer, 0, 0xe3);
                menu->flags &= ~0x200;
            } else {
                func_0204500c(msgs,
                              _Z21GetFieldByKey020e0434P17Container020e0310i((Container020e0310 *) (menu->messages), cur), 0,
                              0xe3);
            }
            msgs->field99c = menu->fieldff0;
            msgs->busy     = 1;
            menu->step++;
        }
    } else if (menu->step == 2) {
        if (!(menu->flags & 0x40)) {
            if (msgs->busy == 0) {
                menu->cur       = menu->next;
                menu->next      = -1;
                menu->field103e = 9;
                menu->field103f = 0;
                if (menu->flags & 0x2000) {
                    func_ov003_021749c0((char *) menu);
                    menu->flags &= ~0x2000;
                }
            } else if (msgs->state == 3) {
                *(unsigned char *) ((char *) _Z26GetGlobalField0x1c020421a0v() + 0x19ae) = 0;
                menu->cur                                                                = menu->next;
                menu->next                                                               = -1;
                if (menu->cur < 0) {
                    if (menu->flags & 0x20) {
                        _Z24ReinitController02043204Pc((char *) msgs);
                        func_02043124(msgs);
                        menu->flags &= ~0x20;
                    }
                    if (menu->flags & 0x2000) {
                        func_ov003_021749c0((char *) menu);
                        menu->flags &= ~0x2000;
                    }
                }
                menu->step = 0;
            }
        }
    }
}
