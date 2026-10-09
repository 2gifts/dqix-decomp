#include <globaldefs.h>
#include <Filesystem/BackgroundLoader.h>
#include <System/Cache.h>
#include <System/LoadToVRAM.h>
struct Obj020a629c { char pad[0xa]; unsigned char ready, state; int task; };
struct Resource020a629c { char pad[0xc]; unsigned int size; char data[1]; };
struct Palette020a629c { char pad[0xc]; char data[0x200]; };
struct ActiveEntry02046900;
struct Rec020467f0;
extern "C" void* func_ov017_0218b5b0();
extern char data_020f1b28;
int CountActiveEntries(ActiveEntry02046900*);
void* FindRecordByIndex(Rec020467f0*, int, void**, int*);
// USA: func_020a629c
extern "C" ARM void func_020a629c(Obj020a629c* self) {
    func_ov017_0218b5b0();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    if (self->state == 0) {
        self->task = loader->QueueLoadFile(&data_020f1b28, 0);
        self->state = 1;
    } else if (self->state == 1 && loader->GetTaskStatus(self->task)) {
        void* record;
        void* file;
        unsigned int size;
        void* resources[3];
        int fields[3];
        loader->GetLoadedFileByID(self->task, &file, &size);
        int count = CountActiveEntries((ActiveEntry02046900*)file);
        for (int i = 0;i < count;i++) resources[i] = FindRecordByIndex((Rec020467f0*)file, i, &record, &fields[i]);
        Resource020a629c* chars = (Resource020a629c*)resources[0];
        unsigned int charsSize = chars->size;
        CleanInvalidateCacheRange(chars->data, charsSize);
        LoadToSubBG1CharacterData(((Resource020a629c*)resources[0])->data, 0, charsSize);
        Palette020a629c* palette = (Palette020a629c*)resources[1];
        CleanInvalidateCacheRange(palette->data, 0x200);
        LoadToSubBGStandardPalette(palette->data, 0, 0x40);
        LoadToSubBGStandardPalette(palette->data+0x180, 0x180, 0x80);
        unsigned int screenSize;
        Resource020a629c* screen = (Resource020a629c*)resources[2];
        screenSize = screen->size;
        CleanInvalidateCacheRange(screen->data, screenSize);
        LoadToSubBG1ScreenData(screen->data, 0, screenSize);
        loader->RemoveTask(self->task);
        self->task = -1;
        self->ready = 1;
        self->state = 0;
    }
}
