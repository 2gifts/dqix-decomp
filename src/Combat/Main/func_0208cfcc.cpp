#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"

struct TransitionOwner0208cfcc { char padding[0x3c]; SafeAllocator allocator; };
struct TransitionList0208cfcc { char padding[0x40]; int field_40; char padding_44[8]; unsigned short type; char padding_4e[2]; unsigned char active; char padding_51[3]; };
struct Obj0208bf28 {
    TransitionOwner0208cfcc* owner;
    char padding_4[0x5c];
    TransitionList0208cfcc list;
    int index;
    char padding_b8[8];
    int task;
    int field_c4;
    int counter;
    float blend;
    unsigned short timer;
    short value;
    unsigned char complete;
    unsigned char state;
    unsigned char field_d6;
    unsigned char field_d7;
    unsigned char field_d8;
    signed char delay;
    unsigned short flags;
};
struct ActiveEntry02046900;
struct Rec020467f0;
extern char data_020f11eb[];
extern char data_020f11fe[];
extern char data_02108760[];
void SetSubBrightness(GameResources*, int, int);
extern "C" void _Z18SetFieldD20208bf28P11Obj0208bf28ih(Obj0208bf28*, int, unsigned char);
int CountActiveEntries(ActiveEntry02046900*);
extern "C" void _Z18InitStruct0205a444Pc(char*);
void* FindRecordByIndex(Rec020467f0*, int, void**, int*);
extern "C" void func_0205a528(TransitionList0208cfcc*, void*, int, SafeAllocator*);
void WrapAddByteField0x22(int, char*, unsigned int, int);
extern "C" void _Z29SetBitfieldStoreBytes0205af38iPcii(int, char*, int, int);
typedef void (*WrapTransitionList0208cfcc)(TransitionList0208cfcc*, int, unsigned int, int);
typedef void (*SetTransitionList0208cfcc)(TransitionList0208cfcc*, int, int, int);
int IsSubBrightnessTransitionActive(GameResources*);
extern "C" void _Z26SetForwardAndStore0205eb54Pvii(void*, int, int);
extern "C" void _Z34DispatchIfField0xc4NonNeg_0205eb90Pvii(void*, int, int);
extern "C" void _Z25ForwardField0xc0_0205eb80Pv(void*);

static inline int NoShortDelay0208cfcc(Obj0208bf28* obj) { return (obj->flags & 0x100) == 0; }

// USA: func_0208cfcc
extern "C" ARM void func_0208cfcc(Obj0208bf28* obj) {
    TransitionOwner0208cfcc* owner;
    BackgroundLoader* loader;
    GameResources* resources = func_ov017_0218b5b0();
    loader = BackgroundLoader::GetInstance();
    if (obj->state == 0) {
        int shortDelay = NoShortDelay0208cfcc(obj) == 0;
        unsigned int limit = 300;
        if (shortDelay) limit = 150;
        if (obj->timer < limit) obj->timer += GameState::GetInstance()->GetTickCount();
        else if (shortDelay) {
            SetSubBrightness(resources, -4, 4);
            obj->task = loader->QueueLoadFileInGP2(data_020f11eb, data_020f11fe, 0);
            obj->state++;
        } else {
            _Z18SetFieldD20208bf28P11Obj0208bf28ih(obj, obj->value, 0);
            obj->flags |= 4;
            obj->counter = 0;
            obj->field_d7 = 0;
            obj->state = 2;
        }
    } else if (obj->state == 1) {
        if (loader->GetTaskStatus(obj->task)) {
            owner = obj->owner;
            owner->allocator.Reset();
            void* record;
            void* file;
            unsigned int length;
            loader->GetLoadedFileByID(obj->task, &file, &length);
            int count = CountActiveEntries((ActiveEntry02046900*)file);
            _Z18InitStruct0205a444Pc((char*)&obj->list);
            obj->list.active = 1;
            obj->list.field_40 = obj->index;
            obj->list.type = 3;
            for (int i = 0; i < count; i++) {
                int size;
                void* entry = FindRecordByIndex((Rec020467f0*)file, i, &record, &size);
                func_0205a528(&obj->list, entry, size, &owner->allocator);
            }
            reinterpret_cast<WrapTransitionList0208cfcc>(WrapAddByteField0x22)(&obj->list, obj->index, 3, 64);
            loader->RemoveTask(obj->task);
            obj->task = -1;
            obj->flags |= 4;
            obj->counter = 0;
            obj->field_d7 = 0;
            obj->state++;
        }
    } else if (obj->state == 2) {
        if (!IsSubBrightnessTransitionActive(func_ov017_0218b5b0())) {
            reinterpret_cast<SetTransitionList0208cfcc>(_Z29SetBitfieldStoreBytes0205af38iPcii)(&obj->list, obj->index, 1, 1);
            reinterpret_cast<SetTransitionList0208cfcc>(_Z29SetBitfieldStoreBytes0205af38iPcii)(&obj->list, obj->index + 40, 1, 1);
            obj->field_d8 = 0;
            obj->blend = 0;
            obj->flags &= ~1;
            obj->state++;
        }
    } else if (obj->state == 3) {
        obj->flags |= 8;
        if (obj->blend < 1.0f) obj->blend += 0.2f;
        else {
            obj->blend = 1.0f;
            _Z26SetForwardAndStore0205eb54Pvii(data_02108760, 110, 110);
            _Z34DispatchIfField0xc4NonNeg_0205eb90Pvii(data_02108760, 0, 0);
            obj->state++;
            obj->delay = 30;
        }
    } else if (obj->state == 4) {
        obj->flags |= 128;
        obj->state++;
    } else if (obj->state == 5) {
        if (!(obj->flags & 128)) {
            obj->blend += 0.2f;
            if (1.0f < obj->blend) {
                obj->blend = 1.0f;
                obj->state++;
            }
        }
    } else if (obj->state == 6 && obj->delay == 0) {
        _Z25ForwardField0xc0_0205eb80Pv(data_02108760);
        obj->complete = 1;
        obj->state = 0;
    }
}
