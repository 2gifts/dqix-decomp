#include "Filesystem/BackgroundLoader.h"
#include "System/ColorEffects.h"
#include "System/Graphics.h"
#include <globaldefs.h>
#include "Resource/FontGlyphTable.h"

struct Run0216e714;
extern "C" struct Run0216e714 *func_02012fe4(void);
struct ActiveEntry02046900;
int CountActiveEntries(ActiveEntry02046900 *pac);
struct Rec020467f0;
void *FindRecordByIndex(Rec020467f0 *pac, int index, void **outName, int *outSize);
extern "C" void func_0204c684(void *obj);
extern "C" void __clear(void *dst, int count);
extern "C" void func_02042764(void *src, void *dst, int flag);
extern "C" void func_0204f41c(void *obj, short x, short y, void *str, int d, int e, short *outA, short *outB, int zero);
struct Container020e0310;
int GetFieldByKey020e0434(Container020e0310 *c, int key);
extern "C" int func_020420e8(void *p, int flag);
extern "C" void func_0204e038(void *canvas, char *str, int a, int b, int c, int d, int e, int f);
struct List0204af64;
void ResetList0204af64(struct List0204af64 *obj);
void SetWord0x18ClearByte0x1f(unsigned char *obj, int value);
struct Obj0204b5e8;
int DispatchViaTable0204b5e8(struct Obj0204b5e8 *obj, int a, int b);
void CleanInvalidateCacheRange(const void *addr, unsigned int size);
extern "C" int LoadToMainBG3ScreenData(int arg0, int arg1, unsigned int arg2);
extern "C" void func_0204b174(void *graphics, void *file, SafeAllocator *allocator, unsigned int size);
struct List0204b0e8;
void FlushAndDispatchList0204b0e8(struct List0204b0e8 *obj, void *buf);
struct List0204afb4;
void ResetRecordList0204afb4(struct List0204afb4 *obj);

extern char data_ov003_0218028b[];
extern char data_ov003_0218029b[];
extern char data_ov003_021802a7[];
extern char data_ov003_021802b3[];
extern char data_ov003_021802b6[];
extern char data_ov003_021802b9[];
extern char data_ov003_021802bc[];
extern char data_ov003_0217f5bc[];

struct Progress0216e714 {
    unsigned char pad0[0xb38];
    int count;
};

struct Run0216e714 {
    unsigned char pad0[0x1840];
    struct Progress0216e714 progress;
};

static inline struct Progress0216e714 *GetProgress(struct Run0216e714 *run) { return &run->progress; }
static inline int GetCount(struct Progress0216e714 *progress) { return progress->count; }

struct Record0216e714 {
    int unk_0;
    int unk_4;
    unsigned char unk_8[3];
    unsigned char year : 7;
    unsigned char unk_b7 : 1;
    unsigned int kind : 4;
    unsigned int category : 4;
    unsigned int unk_c8 : 7;
    unsigned int rank : 4;
    unsigned int level : 5;
    unsigned int unk_c24 : 8;
};

struct Canvas0216e714 {
    char unk_0[8];
    char *text;
    char unk_c[0xa8 - 0xc];
    short width;
    short height;
    char unk_ac[0xb4 - 0xac];
    short fontW;
    short fontH;
    char unk_b8[0xe0 - 0xb8];
};

struct Background0216e714 {
    char unk_0[0x1c];
    unsigned char lo : 4;
    unsigned char hi : 4;
    char unk_1d[3];
};

struct File0216e714 {
    char unk_0[0xc];
    unsigned int size;
    char data[1];
};

struct Menu0216e714 {
    unsigned char page;
    unsigned char state;
    signed char step;
    unsigned char move;
    unsigned char pages;
    unsigned char count;
    signed char cursor;
    signed char selected;
    char unk_8[0x1c - 0x8];
    int task;
    unsigned short flags;
    char unk_22[0xdc - 0x22];
    char texts[0x18];
    Record0216e714 *records[(0x3b0 - 0xf4) / 4];
    int kinds[8];
};

// USA: func_ov003_0216e714
extern "C" ARM void func_ov003_0216e714(Menu0216e714 *self) {
    int end;
    Run0216e714 *run         = func_02012fe4();
    BackgroundLoader *loader = BackgroundLoader::GetInstance();
    if (self->step == 0) {
        self->task = loader->QueueLoadFileInGP2(data_ov003_0218028b, data_ov003_0218029b, 0);
        if (!(self->flags & 0x20)) {
            ColorEffect_ConfigureAlphaBlend(0x04000050, 0x18, 1, 0, 0x10);
        }
        self->step = 1;
    } else if (self->step == 1) {
        if (loader->GetTaskStatus(self->task) != 0) {
            Canvas0216e714 canvas;
            char text[0x80];
            File0216e714 *files[7];
            int sizes[7];
            char name[0x30];
            Background0216e714 bg;
            void *entry;
            void *file;
            unsigned int size;
            short outA;
            short outB;
            int row;
            int start;
            int index;
            Record0216e714 *rec;
            int y;
            int slot;
            loader->GetLoadedFileByID(self->task, &file, &size);
            int numFiles = CountActiveEntries((ActiveEntry02046900 *) file);
            for (int i = 0; i < numFiles; i++) {
                files[i] = (File0216e714 *) FindRecordByIndex((Rec020467f0 *) file, i, &entry, &sizes[i]);
            }
            func_0204c684(&canvas);
            canvas.text   = (char *) files[0] + 0x10;
            canvas.width  = 0x20;
            canvas.height = 0x18;
            canvas.fontW  = 10;
            canvas.fontH  = 10;
            row           = 0;
            start         = (self->page - 1) * 8;
            __clear(text, sizeof(text));
            slot = 0;
            memset(self->kinds, -1, sizeof(self->kinds));
            end = start + 8;
            for (index = start; index < end; row++, index++) {
                if (index >= GetCount(GetProgress(run))) break;
                rec          = self->records[index];
                y            = row * 16 + 0x2f;
                canvas.fontW = 10;
                canvas.fontH = 10;
                __clear(name, sizeof(name));
                func_02042764(rec, name, 1);
                if (index == self->selected + (self->page - 1) * 8) {
                    sprintf(text, data_ov003_021802a7, name);
                } else {
                    sprintf(text, data_ov003_021802b3, name);
                }
                func_0204f41c(&canvas, 0x14, y, text, 10, 15, &outA, &outB, 0);
                self->kinds[slot] = rec->kind;
                slot++;
                int key = 4;
                switch (rec->category) {
                    case 2: key = 0; break;
                    case 3:
                    case 4: key = 1; break;
                    case 5:
                    case 6: key = 2; break;
                    case 9:
                    case 10: key = 3; break;
                }
                sprintf(text, (char *) GetFieldByKey020e0434((Container020e0310 *) self->texts, key));
                func_0204f41c(&canvas, 0xb0 - func_020420e8(text, 0), y, text, 10, 15, &outA, &outB, 0);
                canvas.fontW = 8;
                canvas.fontH = 8;
                sprintf(text, data_ov003_021802b6, rec->level);
                func_0204f41c(&canvas, 0xc8 - func_020420e8(text, 0), y, text, 10, 15, &outA, &outB, 0);
                sprintf(text, data_ov003_021802b3,
                        (char *) GetFieldByKey020e0434((Container020e0310 *) self->texts,
                                                                                (short) (rec->rank + 0xe)));
                func_0204f41c(&canvas, 0xce, y, text, 10, 15, &outA, &outB, 0);
                sprintf(text, data_ov003_021802b6, rec->year + 2000);
                func_0204f41c(&canvas, 0xf4 - func_020420e8(text, 0), y, text, 10, 15, &outA, &outB, 0);
            }
            if (GetCount(GetProgress(run)) > 8) {
                char *str = func_02042a50(8, data_ov003_021802b9);
                if (str != 0) {
                    func_0204e038(&canvas, str, 0xc, 0xb2, 8, 8, 0xf0, 0xf);
                }
                str = func_02042a50(8, data_ov003_021802bc);
                if (str != 0) {
                    func_0204e038(&canvas, str, 0xee, 0xb2, 8, 8, 0xf0, 0xf);
                }
                func_0204f41c(&canvas, 0x7e, 0xaf, data_ov003_0217f5bc, 8, 15, &outA, &outB, 0);
                sprintf(text, data_ov003_021802b6, self->page);
                func_0204f41c(&canvas, 0x7d - func_020420e8(text, 0), 0xaf, text, 8, 15, &outA, &outB, 0);
                sprintf(text, data_ov003_021802b6, self->pages);
                func_0204f41c(&canvas, 0x82, 0xaf, text, 8, 15, &outA, &outB, 0);
            }
            switch (self->move) {
                case 1: self->cursor = self->count - 1; break;
                case 2: self->cursor = 0; break;
            }
            self->move = 0;
            if (self->cursor >= self->count) {
                self->cursor = self->count - 1;
            }
            ResetList0204af64((struct List0204af64 *) &bg);
            bg.lo = 0;
            bg.hi = 3;
            SetWord0x18ClearByte0x1f((unsigned char *) &bg, 0);
            DispatchViaTable0204b5e8((struct Obj0204b5e8 *) &bg, 0, 0);
            BG3CNT = (BG3CNT & 0x43) | 0xf00;
            for (int i = 0; i < numFiles; i++) {
                if (i == 2) {
                    File0216e714 *f  = files[i];
                    unsigned int len = f->size;
                    CleanInvalidateCacheRange((char *) f + 0x10, len);
                    LoadToMainBG3ScreenData((int) ((char *) f + 0x10), 0, len);
                } else {
                    func_0204b174(&bg, files[i], 0, sizes[i]);
                }
            }
            FlushAndDispatchList0204b0e8((struct List0204b0e8 *) &bg, 0);
            ResetRecordList0204afb4((struct List0204afb4 *) &bg);
            loader->RemoveTask(self->task);
            self->task = -1;
            if (!(self->flags & 0x20)) {
                DISPCNT     = (DISPCNT & ~0x1f00) | 0xf00;
                BG0CNT      = (BG0CNT & ~3) | 3;
                BG1CNT      = BG1CNT & ~3;
                BG2CNT      = (BG2CNT & ~3) | 1;
                BG3CNT      = (BG3CNT & ~3) | 2;
                self->state = 3;
                self->step  = 0;
            } else {
                DISPCNT     = (DISPCNT & ~0x1f00) | 0x1f00;
                BG0CNT      = BG0CNT & ~3;
                BG1CNT      = (BG1CNT & ~3) | 1;
                BG2CNT      = (BG2CNT & ~3) | 2;
                BG3CNT      = (BG3CNT & ~3) | 3;
                self->state = 4;
                self->step  = 0;
            }
        }
    }
}
