#include <globaldefs.h>

struct SafeAllocator {
    void* Allocate(unsigned int len);
    void Reset();
};

struct BackgroundLoader {
    static BackgroundLoader* GetInstance();
    int QueueLoadFileInGP2(const char* gp2, const char* innerFile, SafeAllocator* alloc);
    int GetTaskStatus(int taskID);
    void GetLoadedFileByID(int taskID, void** outPtr, unsigned int* outLength);
    void RemoveTask(int taskID);
};

struct GrottoStruct {
    unsigned char unknown_0[5];
};

struct GameState {
    static GameState* GetInstance();
    GrottoStruct* GetGrottoStruct();
};

struct Struct0205a198;
struct ClearTarget0205a234;
struct ActiveEntry02046900;
struct Rec020467f0;

extern "C" void _Z18InitStruct0205a444Pc(char* p);
extern "C" void _Z12Init0205a198P14Struct0205a198(struct Struct0205a198* p);
extern "C" void _Z23ClearField0And40205a234P19ClearTarget0205a234(struct ClearTarget0205a234* p);
int CountActiveEntries(struct ActiveEntry02046900* entry);
void* FindRecordByIndex(struct Rec020467f0* rec, int index, void** out, int* outLength);
extern "C" void func_0205a528(void* a, void* b, int c, void* d);

extern char data_020f007f;
extern char data_020f0093;

struct LoadTable {
    char pad0[0x3c];
    struct ClearTarget0205a234* clearTarget;
    void* entries;
    char pad1[8];
    unsigned short entryCount;
    char pad2[2];
    unsigned char flag50;
};

struct LoadController {
    char pad0[0x2d0];
    int taskId;
    SafeAllocator* allocator;
    struct LoadTable* table;
    char* tableEntries;
    struct ClearTarget0205a234* clearTarget;
    unsigned short f2e4;
    char pad1[1];
    unsigned char state;
};

// USA: func_02043368
extern "C" ARM void func_02043368(struct LoadController* self) {
    if (self->allocator == 0) {
        return;
    }
    BackgroundLoader* loader = BackgroundLoader::GetInstance();

    if (self->state == 0) {
        if (self->table != 0) {
            return;
        }
        GrottoStruct* grotto = GameState::GetInstance()->GetGrottoStruct();
        if (grotto != 0 && grotto->unknown_0[0] != 0 && grotto->unknown_0[2] == 0) {
            return;
        }
        self->taskId = loader->QueueLoadFileInGP2(&data_020f007f, &data_020f0093, 0);
        self->state++;
        return;
    }

    if (self->state == 1) {
        if (loader->GetTaskStatus(self->taskId) == 0) {
            return;
        }
        self->allocator->Reset();
        self->table = (struct LoadTable*)self->allocator->Allocate(0x54);
        self->tableEntries = (char*)self->allocator->Allocate(0xf0);
        self->clearTarget = (struct ClearTarget0205a234*)self->allocator->Allocate(8);

        if (self->table != 0 && self->tableEntries != 0 && self->clearTarget != 0) {
            _Z18InitStruct0205a444Pc((char*)self->table);
            for (unsigned short i = 0; i < 6; i++) {
                _Z12Init0205a198P14Struct0205a198((struct Struct0205a198*)(self->tableEntries + i * 0x28));
            }
            _Z23ClearField0And40205a234P19ClearTarget0205a234(self->clearTarget);
            self->table->flag50 = 0;
            {
                struct LoadTable* table = self->table;
                table->entries = self->tableEntries;
                table->entryCount = 6;
            }
            self->table->clearTarget = self->clearTarget;
            self->f2e4 = 0;

            void* rec;
            void* found;
            unsigned int foundLen;
            int recLen;
            loader->GetLoadedFileByID(self->taskId, &found, &foundLen);
            int count = CountActiveEntries((struct ActiveEntry02046900*)found);
            for (int i = 0; i < count; i++) {
                void* r = FindRecordByIndex((struct Rec020467f0*)found, i, &rec, &recLen);
                func_0205a528(self->table, r, recLen, self->allocator);
            }
        }

        loader->RemoveTask(self->taskId);
        self->taskId = -1;
        self->state++;
        return;
    }

    if (self->state == 2) {
        if (self->table != 0 && self->clearTarget != 0) {
            return;
        }
        self->table = 0;
        self->tableEntries = 0;
        self->clearTarget = 0;
        self->f2e4 = 0;
        self->taskId = -1;
        self->state = 0;
    }
}
