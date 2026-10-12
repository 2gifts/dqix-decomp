#include <globaldefs.h>

struct BufferNode02241060 {
    BufferNode02241060* next;
};

struct TextBuffer02241060 {
    char padding0[0x10];
    void* firstBuffer;
    void* secondBuffer;
    char padding18[4];
    BufferNode02241060* head;
};

extern "C" void (*data_ov031_02290fc8)(void*);

// USA: func_ov031_02241060
extern "C" ARM void func_ov031_02241060(TextBuffer02241060* buffer) {
    BufferNode02241060* node = buffer->head;
    if (node != NULL) {
        do {
            BufferNode02241060* next = node->next;
            data_ov031_02290fc8(node);
            buffer->head = next;
        } while ((node = buffer->head) != NULL);
    }
    if (buffer->firstBuffer != NULL) data_ov031_02290fc8(buffer->firstBuffer);
    if (buffer->secondBuffer != NULL) data_ov031_02290fc8(buffer->secondBuffer);
    data_ov031_02290fc8(buffer);
}
