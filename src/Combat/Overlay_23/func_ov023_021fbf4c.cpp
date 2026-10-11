#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"

struct MenuHeap_021fbf4c
{
    int unk_0;
    SafeAllocator allocator_;
};

struct PartNameTable_021fbf4c
{
    char unk_0[0x18];
};

class MenuPartNames_021fbf4c
{
public:
    unsigned short type_;
    unsigned short id_;
    unsigned short heap_;
    unsigned short vramState_;
    unsigned char flags_;
    char unk_d[3];
    const char* file_;
    void* prev_;
    void* next_;
    int state_;
    SafeAllocator allocator_;
    PartNameTable_021fbf4c names_;
    int categories_;

    virtual void Update(void* script);
};

struct MenuObjectList_021fbf4c;

extern "C" double func_0200ab28(double a, double b);
extern "C" unsigned int func_0200af90(double value);
extern "C" MenuObjectList_021fbf4c* func_ov011_021849c8(void* script);
extern "C" int func_ov023_021f6bb8(MenuObjectList_021fbf4c* objects);
extern "C" void func_ov023_021f6bb0(MenuObjectList_021fbf4c* objects, int task);
extern "C" MenuHeap_021fbf4c* func_ov011_021845f8(void* script, int heap);
extern "C" void func_020de888(PartNameTable_021fbf4c* names, SafeAllocator* allocator, void* file, unsigned int size);
extern "C" void func_020dea64(PartNameTable_021fbf4c* names, SafeAllocator* allocator, void* file, unsigned int size,
                              unsigned char* categories, int count);

// JPN: func_ov023_021fb2bc
// USA: func_ov023_021fbf4c
extern "C" ARM int func_ov023_021fbf4c(MenuPartNames_021fbf4c* self, void* script)
{
#if defined(jpn)
 enum {regionalOffset0=0x19000};
#else
 enum {regionalOffset0=0x1a000};
#endif
    MenuHeap_021fbf4c* heap;
    MenuObjectList_021fbf4c* objects = func_ov011_021849c8(script);
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    int task = func_ov023_021f6bb8(objects);
    if (loader->GetTaskStatus(task))
    {
        if (loader->GetDetailedTaskStatus(task) == 2)
        {
            void* file;
            unsigned int size;
            loader->GetLoadedFileByID(task, &file, &size);
            heap = func_ov011_021845f8(script, self->heap_);
            if (heap == NULL)
            {
                loader->RemoveTask(task);
                func_ov023_021f6bb0(objects, -1);
                return 2;
            }
            if (self->categories_ == 0)
            {
                self->allocator_.CreateTypeA(heap->allocator_.Allocate(regionalOffset0), regionalOffset0);
                self->allocator_.Reset();
                func_020de888(&self->names_, &self->allocator_, file, size);
            }
            else
            {
                unsigned int bytes = 0;
                short count = 0;
                unsigned char categories[12] = {0};
                if (self->categories_ & 1)
                {
#if defined(jpn)
                    bytes += 0x12c00;
#else
                    bytes = func_0200af90(func_0200ab28(bytes, 79872.0));
#endif

                    for (short i = 0; i <= 7; i++)
                        categories[count++] = i;
                }
                if (self->categories_ & 2)
                {
#if defined(jpn)
                    bytes += 0x1c00;
#else
                    bytes = func_0200af90(func_0200ab28(bytes, 7987.2));
#endif

                    categories[count++] = 8;
                }
                if (self->categories_ & 4)
                {
#if defined(jpn)
                    bytes += 0x1400;
#else
                    bytes = func_0200af90(func_0200ab28(bytes, 4915.2));
#endif

                    categories[count++] = 9;
                }
                if (self->categories_ & 8)
                {
#if defined(jpn)
                    bytes += 0x4000;
#else
                    bytes = func_0200af90(func_0200ab28(bytes, 15872.0));
#endif

                    categories[count++] = 11;
                }
                if (bytes > regionalOffset0)
                    bytes = regionalOffset0;
                self->allocator_.CreateTypeA(heap->allocator_.Allocate(bytes), bytes);
                self->allocator_.Reset();
                func_020dea64(&self->names_, &self->allocator_, file, size, categories, count);
            }
        }
        loader->RemoveTask(task);
        func_ov023_021f6bb0(objects, -1);
        return 2;
    }
    return self->state_;
}
