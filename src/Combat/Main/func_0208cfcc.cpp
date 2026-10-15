#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"

struct DstStruct0208baec { unsigned char field_0[0xc]; int x, y, width, height; unsigned short value; unsigned short field_1e; unsigned short style; unsigned char flags; unsigned char field_23[5]; };

struct TransitionOwner0208cfcc { char padding[0x3c]; SafeAllocator allocator; };
struct TransitionList0208cfcc { char padding[0x40]; DstStruct0208baec* entries; char padding_44[8]; unsigned short type; char padding_4e[2]; unsigned char active; char padding_51[3]; };
struct Obj0208bf28 {
    TransitionOwner0208cfcc* owner;
    char padding_4[0x5c];
    TransitionList0208cfcc list;
    DstStruct0208baec* entries;
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
#if defined(jpn)
extern char data_020f12cc[];
#endif
extern char data_020f11eb[];
extern char data_020f11fe[];
extern char data_02108760[];
void SetSubBrightness(GameResources*, int, int);
void SetFieldD20208bf28(Obj0208bf28*, int, unsigned char);
int CountActiveEntries(ActiveEntry02046900*);
void InitStruct0205a444(char*);
void* FindRecordByIndex(Rec020467f0*, int, void**, int*);
extern "C" void func_0205a528(TransitionList0208cfcc*, void*, int, SafeAllocator*);
void WrapAddByteField0x22_0205aed0(void*, char*, unsigned int, int);
void SetBitfieldStoreBytes0205af38(int, char*, int, int);
int IsSubBrightnessTransitionActive(GameResources*);
void SetForwardAndStore0205eb54(void*, int, int);
void DispatchIfField0xc4NonNeg_0205eb90(void*, int, int);
void ForwardField0xc0_0205eb80(void*);

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
#if defined(jpn)
            obj->task = loader->QueueLoadFile(data_020f12cc, 0);
#else
            obj->task = loader->QueueLoadFileInGP2(data_020f11eb, data_020f11fe, 0);
#endif
            obj->state++;
        } else {
            SetFieldD20208bf28(obj, obj->value, 0);
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
            InitStruct0205a444((char*)&obj->list);
            obj->list.active = 1;
            obj->list.entries = obj->entries;
            obj->list.type = 3;
            for (int i = 0; i < count; i++) {
                int size;
                void* entry = FindRecordByIndex((Rec020467f0*)file, i, &record, &size);
                func_0205a528(&obj->list, entry, size, &owner->allocator);
            }
            WrapAddByteField0x22_0205aed0(&obj->list, (char*)obj->entries, 3, 64);
            loader->RemoveTask(obj->task);
            obj->task = -1;
            obj->flags |= 4;
            obj->counter = 0;
            obj->field_d7 = 0;
            obj->state++;
        }
    } else if (obj->state == 2) {
        if (!IsSubBrightnessTransitionActive(func_ov017_0218b5b0())) {
            SetBitfieldStoreBytes0205af38((int)&obj->list, (char*)&obj->entries[0], 1, 1);
            SetBitfieldStoreBytes0205af38((int)&obj->list, (char*)&obj->entries[1], 1, 1);
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
            SetForwardAndStore0205eb54(data_02108760, 110, 110);
            DispatchIfField0xc4NonNeg_0205eb90(data_02108760, 0, 0);
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
        ForwardField0xc0_0205eb80(data_02108760);
        obj->complete = 1;
        obj->state = 0;
    }
}
