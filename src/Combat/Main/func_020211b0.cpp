#include "Filesystem/BackgroundLoader.h"
#include "System/Memory.h"
#include <globaldefs.h>

struct Stream0200fd14 {
    char *ptr;
};
extern "C" void _Z23ReadStreamBlock0200fd14P14Stream0200fd14Pvj(Stream0200fd14 *stream, void *dst, unsigned int length);
extern "C" void *__clear(void *dst, int count);

struct Node020211b0 {
    unsigned char type;
    unsigned char id;
    unsigned char count;
    unsigned char pad3;
    short *data;
    int x;
    int y;
    Node020211b0 *next;
};

struct Entry020211b0 {
    unsigned short key1;
    unsigned char key2;
    unsigned char pad3;
    short val1;
    short val2;
};

struct Table020211b0 {
    char pad0[0xaa0];
    unsigned short count;
    Entry020211b0 entries[32];
};

// USA: func_020211b0
extern "C" ARM void func_020211b0(char *receiver, int *taskID) {
    BackgroundLoader *loader = BackgroundLoader::GetInstance();
    Stream0200fd14 stream;
    stream.ptr              = 0;
    unsigned int fileLength = 0;
    loader->GetLoadedFileByID(*taskID, (void **) &stream.ptr, &fileLength);

    unsigned short keys[16];
    unsigned char keyCount = 0;
    __clear(keys, sizeof(keys));
    for (Node020211b0 *node = *(Node020211b0 **) (receiver + 0x754); node; node = node->next) {
        for (int i = 0; i < node->count; i++) {
            unsigned short key = node->data[i];
            if (key >= 20000 && key <= 29999) {
                keys[keyCount++] = key;
            }
        }
    }

    if (stream.ptr) {
        ((Table020211b0 *) receiver)->count = 0;
        VectorizedMemset(((Table020211b0 *) receiver)->entries, 0, 0x100);
        unsigned short recordCount = 0;
        _Z23ReadStreamBlock0200fd14P14Stream0200fd14Pvj(&stream, &recordCount, 2);
        for (int i = 0; i < recordCount; i++) {
            unsigned short key1;
            unsigned char key2;
            short val1;
            short val2;
            _Z23ReadStreamBlock0200fd14P14Stream0200fd14Pvj(&stream, &key1, 2);
            _Z23ReadStreamBlock0200fd14P14Stream0200fd14Pvj(&stream, &key2, 1);
            _Z23ReadStreamBlock0200fd14P14Stream0200fd14Pvj(&stream, &val1, 2);
            _Z23ReadStreamBlock0200fd14P14Stream0200fd14Pvj(&stream, &val2, 2);
            int found = 0;
            for (int j = 0; j < keyCount && !found; j++) {
                if (key1 == keys[j]) found = 1;
            }
            if (found) {
                Entry020211b0 *entry = &((Table020211b0 *) receiver)->entries[((Table020211b0 *) receiver)->count++];
                entry->key1          = key1;
                entry->key2          = key2;
                entry->val1          = val1;
                entry->val2          = val2;
            }
        }
    }

    BackgroundLoader::GetInstance()->RemoveTask(*taskID);
    *taskID = -1;
}
