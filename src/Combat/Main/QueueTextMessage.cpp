#include <globaldefs.h>

#include <std_library_functions.h>

#include "Resource/TextQueue.h"

extern "C" int func_ov017_021959b4(void);

struct QueuedTextEntry {
#if defined(jpn)
    char text[0x4f];
#else
    char text[0x6f];
#endif
    unsigned char flags;
};

struct TextQueuePrefix {
    QueuedTextEntry entries[3];
    unsigned char count : 6;
    unsigned char reserved6 : 1;
    unsigned char reserved7 : 1;
    unsigned char reserved151;
    unsigned short timer;
};

#if defined(jpn)
#define QUEUE_STYLE_MASK 0x7f
#else
#define QUEUE_STYLE_MASK 0x3f
#endif

// USA: func_020d7e10
#if defined(jpn)
extern "C" ARM void func_020d7e10(void *receiver, void *input, int style, int flag7, unsigned char ignoreDuplicates) {
#else
extern "C" ARM void func_020d7e10(void *receiver, void *input, int style, int flag7, unsigned char ignoreDuplicates,
                                  unsigned char flag6) {
#endif
    TextQueuePrefix *queue = static_cast<TextQueuePrefix *>(receiver);
    const char *text       = static_cast<const char *>(input);
    if (func_ov017_021959b4()) return;
    unsigned int count = queue->count;
    if (count != 0 && ignoreDuplicates != 0 && strcmp(queue->entries[0].text, text) == 0) return;
    if (count < 3) {
        strcpy(queue->entries[count].text, text);
        QueuedTextEntry *entry = &queue->entries[queue->count];
        entry->flags           = (entry->flags & ~QUEUE_STYLE_MASK) | (style & QUEUE_STYLE_MASK);
        entry                  = &queue->entries[queue->count];
        entry->flags           = (entry->flags & ~0x80) | ((flag7 & 1) << 7);
#if !defined(jpn)
        entry                  = &queue->entries[queue->count];
        entry->flags           = (entry->flags & ~0x40) | ((flag6 & 1) << 6);
#endif
        queue->count++;
        if (queue->timer > 1000) queue->timer %= 1000;
        return;
    }
    if (queue->timer != 0) {
        queue->timer = 0;
        if (queue->count != 0) {
            memcpy(&queue->entries[0], &queue->entries[1], sizeof(QueuedTextEntry));
            memcpy(&queue->entries[1], &queue->entries[2], sizeof(QueuedTextEntry));
            queue->count--;
        }
    }
    if (queue->count >= 3) return;
    strcpy(queue->entries[queue->count].text, text);
    QueuedTextEntry *entry = &queue->entries[queue->count];
    entry->flags           = (entry->flags & ~QUEUE_STYLE_MASK) | (style & QUEUE_STYLE_MASK);
    entry                  = &queue->entries[queue->count];
    entry->flags           = (entry->flags & ~0x80) | ((flag7 & 1) << 7);
#if !defined(jpn)
    entry                  = &queue->entries[queue->count];
    entry->flags           = (entry->flags & ~0x40) | ((flag6 & 1) << 6);
#endif
    queue->count++;
}
